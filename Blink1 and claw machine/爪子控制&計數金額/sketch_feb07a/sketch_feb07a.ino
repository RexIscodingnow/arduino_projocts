/*
 * 爪子&計金額＋顯示器ｌｃｄ&電眼
*/
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
Servo servo;
long c;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2); 
  servo.attach(9);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(6,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);  
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("hello");
  lcd.setCursor(0,1);
  lcd.print("claw machine");
  delay(1000);
  lcd.clear();  
}

void loop() {
 int i=analogRead(A0); 
  if(digitalRead(2)==HIGH){
    analogWrite(5,i);
  }
  if(digitalRead(3)==HIGH){
    analogWrite(5,i);
  }  
  if(digitalRead(7)==HIGH){//計數金額
    c++;
    servo.write(89);
    delay(900);
   }
  if(digitalRead(4)==HIGH){//天車原點
    servo.write(30);
    analogWrite(5,0);
  }
  else if(digitalRead(8)==HIGH){//電眼
    c=0;
  }
  if(digitalRead(6)==HIGH){
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    digitalWrite(A1,LOW);
    digitalWrite(A2,HIGH);     
  }
  if(digitalRead(10)==LOW){
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    //digitalWrite(A1,LOW);
    //digitalWrite(A2,LOW);    
  }
  if(digitalRead(11)==LOW){
    //digitalWrite(12,LOW);
    //digitalWrite(13,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A2,LOW);    
  }
 if(c==19){//已達保證取物金額
   if(digitalRead(2)==HIGH){
     analogWrite(5,1023);
   }
   if(digitalRead(3)==HIGH){
     analogWrite(5,1023);
  }
   servo.write(91);
   lcd.setCursor(10,1);
   lcd.print("Don't put money");
 }
  else if(c==0){ 
  servo.write(35);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("coin");
  lcd.setCursor(0,1);
  lcd.print(c);
  lcd.setCursor(2,1);
  lcd.print("/19 coins");    
  }
  delay(50);
  lcd.setCursor(0,0);
  lcd.print("coin");
  lcd.setCursor(0,1);
  lcd.print(c);
  lcd.setCursor(2,1);
  lcd.print("/19 coins");
}
