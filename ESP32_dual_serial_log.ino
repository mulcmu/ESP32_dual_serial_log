 #define RXD2 16 
 #define TXD2 17

 #define RXD3 18 
 #define TXD3 19

char buffer[40];
 
 void setup() {
   Serial.begin(230400);
   Serial1.begin(115200, SERIAL_8N1, RXD2, TXD2);
   Serial2.begin(115200, SERIAL_8N1, RXD3, TXD3);
   Serial.println("Serial Monitor Started");
 }

 
 void loop() {
   if(Serial1.available()){
     Serial.print(millis());
     Serial.print(" >>>");
     while(Serial1.available()) {
        sprintf(buffer, " %02X", Serial1.read());
        Serial.print(buffer);
        delayMicroseconds(120);
     }
     Serial.println();  
   }
   
   if(Serial2.available()){
      Serial.print(millis());
      Serial.print(" <<<");
      while(Serial2.available()) {
        sprintf(buffer, " %02X", Serial2.read());
        Serial.print(buffer);
        delayMicroseconds(120);
      }
     Serial.println();  
   }
   
}
