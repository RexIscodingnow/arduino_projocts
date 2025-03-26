/*
 * arduino hc-05 master code for remote control car
 * hc-05遙控器
 */

void setup() {
  Serial.begin(9600); //hc-05傳輸用(對應AT command設定)
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(A0, INPUT);
}

void loop() {
  if(digitalRead(2) == LOW){    // 前後控制
    Serial.write(182);
  }
  if(digitalRead(3) == LOW){    // 前後控制
    Serial.write(183);
  }  
  if(digitalRead(2) == HIGH && digitalRead(3) == HIGH){
    Serial.write(181);
  }
  Serial.write(analogRead(A0)/11); // 轉向控制
  delay(20);
}