#include <SoftwareSerial.h>
SoftwareSerial BTSerial(7, 8);//=>RX|TX
int botton = 8;
int bottonState = 0;
int State =0;
void setup() {
BTSerial.begin(9600);
pinMode(botton,INPUT);  
}

void loop() {
if(BTSerial.available()){
State = (BTSerial.read());  
}
bottonState = digitalRead(botton); 
if(bottonState == HIGH){
BTSerial.write('1');
}
else{
BTSerial.write('0'); 
}
int x = analogRead(A0);
int pos = map (x, 0, 1023, 550, 655); 
BTSerial.write(pos);
}
