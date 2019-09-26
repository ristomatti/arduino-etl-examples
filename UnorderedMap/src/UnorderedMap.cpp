#include <Arduino.h>
#include <Streaming.h>

#if defined(__AVR__) || defined(ARDUINO_ARCH_STM32)
  #include <ArduinoSTL.h>
#endif

#include <etl/unordered_map.h>

#include "map_keys.h"

constexpr size_t MAP_SIZE = 32;  // 32, 100 or 1000 (see map_keys.h)

using hashmap_t = etl::unordered_map<const char*, unsigned long, MAP_SIZE>;

hashmap_t hashmap{};

void setup() {
  delay(500);

  Serial.begin(115200);
  Serial.println();

  delay(1000);
}

void testMap() {
  for (const auto& key : keys) {
    auto value = random(millis());
    Serial << "Adding - " << key << ": " << value << "..." << endl;
    hashmap[key] = value;
  }

  delay(500);

  for (const auto& v : hashmap) {
    Serial << v.first << ": " << v.second << endl;
  }
}

void loop() {
  testMap();
  delay(1000);
}
