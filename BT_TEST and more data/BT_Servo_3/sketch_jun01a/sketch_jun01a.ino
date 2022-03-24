/*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == SLAVE CODE ==
 */
 
#include <Servo.h>
Servo myServo;
#define ledPin 9
int state = 20;
void setup() {
  myServo.attach(5); 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);       
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 // Controlling the servo motor
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
