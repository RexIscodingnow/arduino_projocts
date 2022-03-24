#include <Stepper.h>
#include <Wire.h>
#define STEPS 200
Stepper stepperx(STEPS,2,3,4,5);
const int xpin = A0;
int xbob = 6;
unsigned int xvalue;
int xbutton = 0;
void control(){
  xvalue = analogRead(xpin);
  xbutton = digitalRead(xbob);
} 
void controlvalue() {  
  for(;;){  
   Serial.println(xbutton); 
   control();
   if(xvalue<512){
     stepperx.step(STEPS);    
   }
   else if(xvalue>512){
     stepperx.step(-STEPS);
  }
 }
} 
void controlval(){
  for(;;){
   control();
    if(xbutton == HIGH){
     stepperx.step(0);
  }   
 }
} 
void setup() {
 Serial.begin(9600); 
 stepperx.setSpeed(150);
 pinMode(xbob,INPUT);
} 
void loop() { 
  controlvalue();
  controlval;
} 
