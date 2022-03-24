/*
*  =======   Master  Code  =======
*  =======   控制Servo   =======
 */
#define button 8
int state = 0;
int buttonState = 0;
int potValue = 0; 
void setup() {
 Serial.begin(9600); 
 pinMode(A0, INPUT); 
 pinMode(button, INPUT); 
}

void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 } 
 // Reading the button
 buttonState = digitalRead(button);
 if (buttonState == HIGH) {
   Serial.write('1'); // Sends '1' to the master to turn on LED
 }
 else {
   Serial.write('0');
 } 
 // Reading the potentiometer
 potValue = analogRead(A0);
 int potValueMapped = map(potValue, 0, 1023, 0, 180);
 Serial.write(potValueMapped); // Sends potValue to servo motor
 delay(10);
}
