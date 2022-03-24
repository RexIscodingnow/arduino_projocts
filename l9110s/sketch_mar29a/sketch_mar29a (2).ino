#include <IRremote.h> //引入函數庫
IRrecv irrecv(8);  //將紅外線腳位設定為6
decode_results results;  //接收到的紅外線訊號值
void setup() {
  irrecv.enableIRIn();   //啟用紅外線接收
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);  
}

void loop() {
  if (irrecv.decode(&results)) {// put your main code here, to run repeatedly:
   if(results.value == 16726215)
    {
    digitalWrite(2,!digitalRead(2));
    } 
    
    irrecv.resume(); 
  }
  delay(100);
}
