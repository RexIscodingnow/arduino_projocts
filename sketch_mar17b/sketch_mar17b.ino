#include <AFMotor.h>
AF_Stepper motor(48, 2);  //48步馬達接第2組接口

void setup() {
  Serial.begin(9600);
  Serial.println("Stepper test!");
  motor.setSpeed(400);  //轉速
}

void loop() {
  Serial.println("Interleave FORWARD");
  motor.step(12288, FORWARD, INTERLEAVE);  //正轉4096為360度一圈
  delay(500);

  Serial.println("Interleave BACKWARD");
  motor.step(4096, BACKWARD, INTERLEAVE);  //反轉4096為360度一圈
  delay(500);
}
