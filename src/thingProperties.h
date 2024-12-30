#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "";

const char SSID[]               = SECRET_SSID;
const char PASS[]               = SECRET_OPTIONAL_PASS;
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    

 
CloudSwitch durum;  
CloudAngle aci;
CloudCounter mesafe;

void initProperties()
{
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(durum, READ, ON_CHANGE);
  ArduinoCloud.addProperty(aci, READ, ON_CHANGE);
  ArduinoCloud.addProperty(mesafe, READ, ON_CHANGE);
}
WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
