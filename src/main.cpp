#include <Arduino.h>
// #include <FastLED.h>
#include <Bluepad32.h>

void setup() {
    Serial.begin(115200);
    pinMode(10, OUTPUT);
}

void loop() {
    Serial.println("Ha");
    digitalWrite(10, HIGH);
    delay(500);
    digitalWrite(10, LOW);
    delay(500);
}