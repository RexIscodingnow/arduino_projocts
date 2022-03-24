
#include <IRremote.h> //引入函數庫

IRrecv irrecv(6);  //將紅外線腳位設定為6
decode_results results;  //接收到的紅外線訊號值

void setup()
{
  Serial.begin(9600);         //啟用序列埠
  irrecv.enableIRIn();   //啟用紅外線接收
  Serial.println("Enabled IRin"); //印出啟動紅外線完成
  pinMode(7,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(9,OUTPUT); 
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);       
}

void loop() {
  if (irrecv.decode(&results)) {       //如果接收到紅外線
    if(results.value == 16736925)
    { 
      digitalWrite(7,!digitalRead(7));
    }
    else if(results.value == 16712445)
    {
      digitalWrite(3,!digitalRead(3));
    }
    else if(results.value == 16754775)
    {
      digitalWrite(9,!digitalRead(9)); 
    }
    else if(results.value == 16726215)
    {
      digitalWrite(5,!digitalRead(5)); 
    }    
    else if(results.value == 16750695)
    {
      digitalWrite(4,!digitalRead(4)); 
    } 
    else if(results.value == 16718055)
    {
      digitalWrite(2,!digitalRead(2)); 
    }         
    irrecv.resume();                   //讓接收器可以再接收
  }
  delay(100);
}
