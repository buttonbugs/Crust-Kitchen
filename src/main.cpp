#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 144         // The number of LEDs on one LED strip
#define LED_STRIP_DATA 10
#define LED_STRIP_SCK 8

#define COLOR_ORDER BGR     // Check physical channel order. BGR is common for SK9822; APA102 may vary

CRGB leds[NUM_LEDS];
int color_index = 0;
CRGB color[] = {CRGB::White, CRGB::Red, CRGB::Green, CRGB::Blue};

void setup() {
    pinMode(10, OUTPUT);
    Serial.begin(9600);
    FastLED.addLeds<SK9822, LED_STRIP_DATA, LED_STRIP_SCK, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(50);  // Set initial brightness (0-255)
    delay(5000);
}

void loop() {
    for (int i = 0; i < NUM_LEDS; i++) {
        for (int j = 0; j < NUM_LEDS; j++) {
            leds[j] = i==j ? color[color_index] : CRGB:: Black;
        }
        Serial.println(i);
        FastLED.show();
        delay(10);
    }
    digitalWrite(10, color_index % 2);
    color_index = (color_index + 1) % 4;
}