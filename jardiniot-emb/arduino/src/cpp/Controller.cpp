#include "include/Controller.h"

//<<constructor>>
Controller::Controller(){
}

Controller::Controller(int idController, ControllerType type, std::vector<String> inputPin, std::vector<int> outputPin){
    this->idController = idController;
    this->inputPin = inputPin;
    this->outputPin = outputPin;
    this->type = type;
}

//<<destructor>>
Controller::~Controller(){
    this->inputPin.clear();
    this->outputPin.clear();
}

String Controller::getName(){
    String ctrlName;
    switch(this->type)
    {
        case DHT   : ctrlName = "DHT";    break;
        case LED: ctrlName = "LED"; break;
        case SoilMoisture: ctrlName = "SoilMoisture"; break;
        case FAN: ctrlName = "FAN"; break;
        case VALVE: ctrlName = "VALVE"; break;
    }
    return ctrlName;
}

int Controller::getIdController(){
    return this->idController;
}

ControllerType Controller::getControllerType(){
    return this->type;
}
