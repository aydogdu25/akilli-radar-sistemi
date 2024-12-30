#include <ESP8266WiFi.h>
#include "arduino_secrets.h"
#include "thingProperties.h"

void setup() {
  Serial.begin(9600);
  delay(2000);  

  
  initProperties();
  Serial.print("WiFi'ya bağlanıyor");
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi bağlandı");
  Serial.print("IP Adresi: ");
  Serial.println(WiFi.localIP());


  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  if (Serial.available() > 0) 
  {
    String gelenVeri = Serial.readStringUntil('\n');  
    int virgulIndex = gelenVeri.indexOf(',');        

    if (virgulIndex != -1) {                                     
      String distanceStr = gelenVeri.substring(0, virgulIndex);  
      String angleStr = gelenVeri.substring(virgulIndex + 1);    

      mesafe = distanceStr.toInt();  
      aci = angleStr.toInt();       
    } 
    else 
    {
      Serial.println("Hatalı veri formatı!");
    }
    if (mesafe <= 15) {
      durum = false;
    } else {
      durum = true;
    }
  }
  Serial.println(durum);
}
