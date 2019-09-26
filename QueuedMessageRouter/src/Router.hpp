#include <Arduino.h>
// #include <Streaming.h>

#if defined(__AVR__) || defined(ARDUINO_ARCH_STM32)
  #include <ArduinoSTL.h>
#endif

#include <etl/queue.h>
#include <etl/message_router.h>

//*****************************************************************************
// The messages.
//*****************************************************************************
struct Message1 : public etl::message<1>
{
  Message1(int i_)
    : i(i_)
  {
  }

  int i;
};

struct Message2 : public etl::message<2>
{
  Message2(double d_)
    : d(d_)
  {
  }

  double d;
};

struct Message3 : public etl::message<3>
{
  Message3(const std::string& s_)
    : s(s_)
  {
  }

  std::string s;
};

struct Message4 : public etl::message<4>
{
};

//*****************************************************************************
// The message router.
// Handles message types Message1, Message2, Message3.
//*****************************************************************************
class Router : public etl::message_router<Router, Message1, Message2, Message3>
{
public:

  typedef etl::message_router<Router, Message1, Message2, Message3> Base_t;

  using Base_t::receive;

  //***************************************************************************
  Router()
    : message_router(1)
  {
  }

  //***************************************************************************
  // Override the base class's receive function.
  void receive(etl::imessage_router& sender_, const etl::imessage& msg_)
  {
    if (accepts(msg_))
    {
      // Place in queue.
      queue.emplace(&sender_, msg_);

      Serial << "Queueing message " << int(msg_.message_id) << endl;
    }
    else
    {
      Serial << "Ignoring message " << int(msg_.message_id) << endl;
    }
  }

  //***************************************************************************
  void process_queue()
  {
    while (!queue.empty())
    {
      Item& item = queue.front();
      etl::imessage& msg = item.packet.get();
      etl::imessage_router& sender = *item.sender;
      Serial << "Processing message " << int(msg.message_id) << endl;

      // Call the base class's receive function.
      // This will route it to the correct on_receive handler.
      Base_t::receive(sender, msg);

      queue.pop();
    }
  }

  //***************************************************************************
  void on_receive(etl::imessage_router& sender, const Message1& msg)
  {
    Serial << "  Received message " << int(msg.message_id) << " : '" << msg.i << "'" << endl;
  }

  //***************************************************************************
  void on_receive(etl::imessage_router& sender, const Message2& msg)
  {
    Serial << "  Received message " << int(msg.message_id) << " : '" << msg.d << "'" << endl;
  }

  //***************************************************************************
  void on_receive(etl::imessage_router& sender, const Message3& msg)
  {
    Serial << "  Received message " << int(msg.message_id) << " : '" << msg.s.c_str() << "'" << endl;
  }

  //***************************************************************************
  void on_receive_unknown(etl::imessage_router& sender, const etl::imessage& msg)
  {
    Serial << "  Received unknown message " << int(msg.message_id) << endl;
  }

private:

  struct Item
  {
    Item(etl::imessage_router* sender_, const etl::imessage& msg_)
      : sender(sender_),
        packet(msg_)
    {
    }

    etl::imessage_router* sender;
    message_packet        packet;
  };

  etl::queue<Item, 5> queue;
};
