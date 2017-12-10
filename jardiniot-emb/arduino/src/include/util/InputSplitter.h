#ifndef InputSplitter_h
#define InputSplitter_h

#include "Arduino.h"

class InputSplitter {
    private:
        static const char charSplit = '*';
    public:
        static int getPin(String input){
            byte pos = input.indexOf(charSplit);
            return input.substring(0, pos).toInt();
        }
        static int getValue(String input){
            byte length = input.length();
            byte pos = input.indexOf(charSplit);
            return input.substring(pos, length).toInt();
        }
};

#endif
