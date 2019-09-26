#include <Arduino.h>
#include <Streaming.h>

#if defined(__AVR__) || defined(ARDUINO_ARCH_STM32)
  #include <ArduinoSTL.h>
#endif

#include <etl/unordered_map.h>

#include "Router.hpp"

Router router;

void setup() {
  delay(500);

  Serial.begin(115200);
  Serial.println();

  delay(1000);
}

void testRouter() {
  Message1 m1(1);
  Message2 m2(1.2);
  Message3 m3("Hello");

  etl::send_message(router, m1);
  etl::send_message(router, Message1(2));
  etl::send_message(router, m2);
  etl::send_message(router, Message2(3.4));
  etl::send_message(router, m3);
  etl::send_message(router, Message3("World"));
  etl::send_message(router, Message4());

  Serial << endl;

  router.process_queue();
}

void loop() {
  testRouter();
  delay(1000);
}
