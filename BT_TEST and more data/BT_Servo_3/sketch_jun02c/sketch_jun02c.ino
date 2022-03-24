#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1);

Servo myservo;
int vel;
void setup() {
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  myservo.attach(9);
  BTSerial.begin(9600);
}
void loop() {
 if (BTSerial.available()) {
    int rec = (BTSerial.read());

    if (rec > 0 && rec < 255) {
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
      vel = map (rec, 0, 255, 255, 0);
      analogWrite(2, vel);
      analogWrite(4, vel);
      }
    if (rec > 255 && rec < 510) {
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      vel = map (rec, 255, 510, 255, 0);
      analogWrite(2, vel);
      analogWrite(4, vel);
      }
    if (rec > 0&& rec < 1023) {
      int pos = map (rec, 0, 1023, 0, 180);
      myservo.write(pos);
    }
    }
}

