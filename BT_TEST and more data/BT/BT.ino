#define button 8
int buttonState = 0;
int potValue = 0;
void setup() {
  pinMode(button, INPUT);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
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
