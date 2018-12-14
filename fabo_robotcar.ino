#include <Wire.h>
#include "CarController.h"

#define ADR_DRV_L      0x64
#define ADR_DRV_R      0x63

//if you define setup() or loop(), you don't access each other.
CarController Car = CarController(ADR_DRV_R, ADR_DRV_L);

void setup() {
    Wire.begin();
    Serial.begin(9600);

    Car.InitialCar();
}

void loop() {
    Car.Forward();
    delay(2000);

    Car.Reverse();
    delay(2000);

    Car.TurnRight();
    delay(2000);

    Car.TurnLeft();
    delay(2000);

    Car.Stop();
    delay(2000);
}
