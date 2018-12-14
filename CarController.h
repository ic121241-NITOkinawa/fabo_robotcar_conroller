#ifndef CarController_h
#define CarController_h

class CarController{
    public:
        CarController(byte add_r, byte add_l);
        int  SetMotor(byte side, byte mode, byte sp);
        void InitialCar();
        void Forward();
        void Reverse();
        void TurnRight();
        void TurnLeft();
        void Stop();

    private:
        byte ADD_R;
        byte ADD_L;
};

#endif
