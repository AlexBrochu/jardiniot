#ifndef SensorStrategy_H
#define SensorStrategy_H

#include "include/Controller.h"
#include "include/command/JardinCommand.h"
#include "include/util/InputSplitter.h"

class SensorStrategy: public Controller {
protected:
    int delayTime;
public:
    virtual int read();
    virtual int write();
    virtual String toString();
    virtual void setInput(std::vector<String> inputPin);

    // constructor
    SensorStrategy();
    SensorStrategy(int idController, ControllerType type, std::vector<String> inputPin, std::vector<int> outputPin);
    ~SensorStrategy();

    void setDelayTime(int delayTime);
    void modify(JardinCommand &jCommand);
};

#endif
