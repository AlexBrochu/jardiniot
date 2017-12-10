#ifndef JardinCommand_H
#define JardinCommand_H

#include <Arduino.h>
#include <string.h>
#include "include/ControllerType.h"
#include "include/command/InputPin.h"
#include <StandardCplusplus.h>
#include <vector>

enum CommandType { ADD, CONFIG, DELETE};

class JardinCommand {
private:
    CommandType commandType;
    int idController;
    int delay;
    int speed;
    ControllerType type;
    std::vector<int> outputPin;
    std::vector<InputPin*> inputPin;

    // Erreur flag
    bool errorInCommand;
    String errorMsg;

    int split(const String &command, std::vector<String> &strs, char ch);

    bool validCommand(std::vector<String> &vecCommand);
    bool validIdController(std::vector<String> &vecCommand);
    bool validConversionStrToInt(String &str, int i);
    int validCommandType(std::vector<String> &vecCommand);
    int extractPin(int index, std::vector<String> &vecCommand, String condition, bool isInput);
    int extractControllerTypeDelay(std::vector<String> &vecCommand);
public:
    JardinCommand();
    JardinCommand(String command);
    ~JardinCommand();

    CommandType getCommandType();
    int getIdController();
    int getDelay();
    int getSpeed();
    ControllerType getControllerType();
    std::vector<int> getOutputPin();
    std::vector<InputPin*> getInputPin();
    String getError();

    String toString();
};

#endif