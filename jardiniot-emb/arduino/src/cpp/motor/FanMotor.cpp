#include "include/motor/FanMotor.h"
#include "include/ControllerType.h"//include the declaration for this class
#include "include/util/InputSplitter.h"

//<<constructor>>
FanMotor::FanMotor(int idController, std::vector<String> input):MotorStrategy(){
    fanPin = InputSplitter::getPin(input[0]);
    fanSpeed = InputSplitter::getValue(input[0]);
}

//<<destructor>>
FanMotor::~FanMotor(){/*nothing to destruct*/}

int FanMotor::activate(){
        analogWrite(fanPin, fanSpeed);
        return fanPin;
}


void FanMotor::reset(){

}

int FanMotor::stop(){
    return 0;
}
