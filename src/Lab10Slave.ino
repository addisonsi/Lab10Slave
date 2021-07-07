#include <Wire.h>
SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);
char x;
void requestEvent(){
  if(digitalRead(D6))
    Wire.write(1);
  else
    Wire.write(0);
}
void receiveEvent(int num) {
  char input = Wire.read();
  if(input == '0'){
    digitalWrite(D7, LOW);      
  }   
  if(input == '1'){
      digitalWrite(D7, HIGH);
  }  
  if(input == '?'){
    requestEvent();
  }   
}
// setup() runs once, when the device is first turned on.
void setup() {
  //Serial.begin(9600);
  pinMode(D7, OUTPUT); 
  pinMode(D6, INPUT);
  //while (!Serial.isConnected()); 
  Wire.begin(0x2A);  
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  
}
