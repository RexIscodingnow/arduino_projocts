/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;

int value1 = 0;
int value2 = 0; 
int value3 = 0; 
int value4 = 0; 

void setup() {  
  myservo1.attach(6);
  myservo2.attach(9);
  myservo3.attach(10); 
  myservo4.attach(11); // attaches the servo on pin 9 to the servo object
}

void loop() {
  value1 = analogRead(A0);            // reads the value of the potentiometer (value between 0 and 1023)
  value1 = map(value1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo1.write(value1);                  // sets the servo position according to the scaled value
  value2 = analogRead(A1);            // reads the value of the potentiometer (value between 0 and 1023)
  value2 = map(value2, 0, 1023, 0, 130);     // scale it to use it with the servo (value between 0 and 180)
  myservo2.write(value2);
  value3 = analogRead(A2);            // reads the value of the potentiometer (value between 0 and 1023)
  value3 = map(value3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo3.write(value3);
  value4 = analogRead(A3);            // reads the value of the potentiometer (value between 0 and 1023)
  value4 = map(value4, 0, 1023, 0, 90);     // scale it to use it with the servo (value between 0 and 180)
  myservo4.write(value4);     
  delay(15);                           // waits for the servo to get there
}

