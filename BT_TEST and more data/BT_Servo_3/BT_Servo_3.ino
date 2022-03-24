/*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == MASTER CODE ==
 */
#define button 8 
int state = 0;
int buttonState = 0;
int potValue = 0;
void setup() {
  pinMode(button, INPUT);// Default communication rate of the Bluetooth module
  Serial.begin(9600); // Default communication rate of the Bluetooth module
  }
void loop() {
  pinMode(button, INPUT);  
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read();
// Reads the data from the serial portfault communication rate of the Bluetooth module
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
}
