/*
 * ======= Slave Code =======
 * ======= 控制Servo ======= 
 */
#define ledPin 9
#include <Servo.h>
Servo myServo; 
int state = 20;
void setup() {
 myServo.attach(5);
 Serial.begin(9600); 
 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW); 
}

void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 } 
 myServo.write(state);
 delay(10);
 // Controlling the LED
 if (state == '1') {
  digitalWrite(ledPin, HIGH); // LED ON
  state = 0;
 }
 else if (state == '0') {
  digitalWrite(ledPin, LOW); // LED ON
  state = 0;
 }
}
