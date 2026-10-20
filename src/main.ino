// main.ino
#include "config.h"

void setup() {
  Serial.begin(SERIAL_BAUD);
}

void loop() {
  int raw = analogRead(SENSOR_PIN);
  Serial.println(raw);
  delay(SAMPLE_PERIOD_MS);
}
