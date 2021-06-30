// Buzzer code:
#include <OzIDManager.h>
#include <OzBuzzerController.h>
 
// global pointers
OzIDManager *manager;
OzBuzzerController *buzzer;
 
int buzzerPin = 10;
 
void setup()
{
  Serial.begin(115200);
 
  manager = new OzIDManager;
  manager->_sendACK = true;
  manager->_checksum = true;
   
  OzCommunication::setIDManager(manager);
   
  buzzer = new OzBuzzerController(buzzerPin);
 
  int x = 1;
  manager->sendLinkSetup();
  manager->PrintWelcomeLine(buzzer, x++, "MyBuzzer");
}
 
void loop()
{
    buzzer->ownLoop();
    OzCommunication::communicate();
}
