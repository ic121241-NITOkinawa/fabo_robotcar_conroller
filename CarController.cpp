#include "arduino.h"
#include "CarController.h"
#include "Wire.h"

#define ADD_CTR 0x00

#define MODE_STANBY  B00
#define MODE_REVERSE B01
#define MODE_FORWARD B10
#define MODE_BRAKE  B11

#define SPEED_MAX 0x3F
#define SPEED_MIN 0x09

CarController::CarController(byte add_r, byte add_l){
    ADD_R = add_r;
    ADD_L = add_l;

}

int CarController::SetMotor(byte side, byte mode, byte sp){
    Wire.beginTransmission(side);
    Wire.write(ADD_CTR);
    Wire.write(mode + (sp << 2));

    return Wire.endTransmission();
}

void CarController::InitialCar(void){
    SetMotor(ADD_L, MODE_STANBY, SPEED_MIN);
    SetMotor(ADD_R, MODE_STANBY, SPEED_MIN);
}

void CarController::Forward(void){
    Serial.println("Forward");
    SetMotor(ADD_L, MODE_FORWARD, SPEED_MAX);
    SetMotor(ADD_R, MODE_FORWARD, SPEED_MAX);
}

void CarController::Reverse(void){
    Serial.println("Reverse");
    SetMotor(ADD_L, MODE_REVERSE, SPEED_MAX);
    SetMotor(ADD_R, MODE_REVERSE, SPEED_MAX);
}

void CarController::TurnRight(void){
    SetMotor(ADD_L, MODE_BRAKE, SPEED_MIN);
    SetMotor(ADD_R, MODE_FORWARD, SPEED_MAX);
}

void CarController::TurnLeft(void){
    SetMotor(ADD_L, MODE_FORWARD, SPEED_MAX);
    SetMotor(ADD_R, MODE_BRAKE, SPEED_MIN);
}

void CarController::Stop(void){
    Serial.println("Brake");
    SetMotor(ADD_L, MODE_BRAKE, SPEED_MIN);
    SetMotor(ADD_R, MODE_BRAKE, SPEED_MIN);
}
