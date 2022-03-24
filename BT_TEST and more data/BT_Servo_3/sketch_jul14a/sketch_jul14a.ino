#include <IRremote.h> 
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
irrecv.enableIRIn();// put your setup code here, to run once:
pinMode(3,OUTPUT); 
}
void loop() { 
if (irrecv.decode(&results)) {
if (results.value == 16750695){
digitalWrite(3,!digitalRead(3));  
}
irrecv.resume(); // put your main code here, to run repeatedly:
}
delay(100);
}
