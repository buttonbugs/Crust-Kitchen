#include <Arduino.h>
// #include <FastLED.h>

void setup() {
    Serial.begin(115200);
    pinMode(10, OUTPUT);
}

void loop() {
    Serial.println("Ha");
    digitalWrite(10, HIGH);
    delay(1000);
    digitalWrite(10, LOW);
    delay(1000);
}