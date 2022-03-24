#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(7, 8);//=>RX|TX
Servo myservo;
int State=0;
void setup() {
pinMode(4,OUTPUT);
myservo.attach(6);
BTSerial.begin(9600);

}

void loop() {
if (BTSerial.available()) {
State = (BTSerial.read());
}
if(State == '1'){
digitalWrite(4,HIGH); 
}
else{
digitalWrite(4,LOW);   
}
if(State >= 0&& State <= 1023){
int pos = map (State, 0, 1023, 0, 180);
myservo.write(pos);   
}
}
