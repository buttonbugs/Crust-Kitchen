#include <Arduino.h>
// #include <FastLED.h>
#include <Bluepad32.h>

ControllerPtr myControllers[BP32_MAX_GAMEPADS];

void onConnectedController(ControllerPtr ctl) {
    bool foundEmptySlot = false;
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == nullptr) {
            myControllers[i] = ctl;
            Serial.printf("Controller connected at index %d\n", i);
            foundEmptySlot = true;
            break;
        }
    }
}

void onDisconnectedController(ControllerPtr ctl) {
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == ctl) {
            myControllers[i] = nullptr;
            Serial.printf("Controller disconnected from index %d\n", i);
            break;
        }
    }
}

void setup() {
    delay(1000);
    Serial.begin(115200);
    Serial.println("Bluepad32 Starting...");
    pinMode(10, OUTPUT);
    for (int i = 0; i < 5; i++) {
        Serial.println("Ha");
        digitalWrite(10, HIGH);
        delay(500);
        digitalWrite(10, LOW);
        delay(500);
    }
    
    
    BP32.setup(&onConnectedController, &onDisconnectedController);
}

void loop() {
    BP32.update();

    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        ControllerPtr myController = myControllers[i];

        if (myController && myController->isConnected()) {
            // Check specific data directly instead of using .hasData()
            int xAxis = myController->axisX();
            int yAxis = myController->axisY();
            
            // Your logic here
            Serial.print(xAxis);
            Serial.print(",\t");
            Serial.println(yAxis);
        }
    }
    delay(1000);
}