/*
 * arduino hc-05 master code for remote control car
 * hc-05������
 */

void setup() {
  Serial.begin(9600); //hc-05�ǿ��(����AT command�]�w)
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(A0, INPUT);
}

void loop() {
  if(digitalRead(2) == LOW){    // �e�ᱱ��
    Serial.write(182);
  }
  if(digitalRead(3) == LOW){    // �e�ᱱ��
    Serial.write(183);
  }  
  if(digitalRead(2) == HIGH && digitalRead(3) == HIGH){
    Serial.write(181);
  }
  Serial.write(analogRead(A0)/11); // ��V����
  delay(20);
}