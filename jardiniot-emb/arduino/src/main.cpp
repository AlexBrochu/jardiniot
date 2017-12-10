#include <include/CommandManager.h>
#include <SoftwareSerial.h>

CommandManager* cm;
std::vector<SensorStrategy*> sensorList;
int k = 0;
String test = "";

int freeRam ()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void setup(){/*nothing to setup*/
    Serial.begin(9600);
    cm = new CommandManager();
    // servoTest = new ServoMotor(5,9);
}

void loop(){

    Serial.println(freeRam ());


    // if(k == 0){
    //     cm->executeCommand("id 1 a 2 100 i 9 200 10 100 11 150");
    // }
    // // //
    // // //
    // sensorList = cm->getSensorList();
    // // //
    // // // Serial.print(F("Size = "));
    // // // Serial.println(sensorList.size());
    // for(unsigned int i = 0; i < sensorList.size(); i++){
    //     sensorList[i]->write();
    // }
    // //
    // if(k %3 ==1){
    //     // Serial.println("TEST DELETE ");
    //     // String test = cm->executeCommand("id 1 d");
    //     // test = cm->executeCommand("id 3 d");
    //     // test = cm->executeCommand("id 3 d");
    //     // Serial.println(test);
    // }
    // else if(k % 3 == 0 && k != 0){
    //     // Serial.println("TEST AJOUT");
    //     // test = cm->executeCommand("id 1 a 2 300 i 9 200 10 100 11 150");
    //     // String test = cm->executeCommand("id 2 a 1 500 i 10");
    //     // test = cm->executeCommand("id 3 a 1 500 i 3");
    //     // Serial.println(test);
    // }
    // else{
    //     // Serial.println("TEST Config");
    //     // String red = String(random(55,156));
    //     // String blue = String(random(127,256));
    //     // String green = String(random(0,256));
    //     //
        // cm->executeCommand("id 1 c 2 300 i 9 0 10 255 11 0");
        JardinCommand* jCommand = new JardinCommand("id 1 c 2 300 i 9*0 10*255 11*0 o 5 6 7");
        Serial.println(jCommand->toString());
        // delete jCommand;
    //     // cm->executeCommand("id 1 c 2 300 i 9 " + green + " 10 " +blue +" 11 " + red);
    //
    // }
    //
    // Serial.println(freeRam ());
    delay(1000);

    k++;

}
