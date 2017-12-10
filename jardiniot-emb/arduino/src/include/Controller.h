#ifndef Controller_H
#define Controller_H

#include <Arduino.h>
#include <string.h>
#include <StandardCplusplus.h>
#include <vector>
#include "ControllerType.h"

class Controller {
private:
    int idController;
    ControllerType type;
protected:
    std::vector<int> outputPin;
    std::vector<String> inputPin;
public:
    Controller();
    Controller(int idController, ControllerType type, std::vector<String> inputPin, std::vector<int> outputPin);
    ~Controller();
    String getName();

    virtual int getIdController();
    virtual ControllerType getControllerType();
};

#endif
