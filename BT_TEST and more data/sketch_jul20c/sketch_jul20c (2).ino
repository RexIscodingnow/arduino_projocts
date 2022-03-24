int val=0;
int val1=0;
void setup() {
  pinMode(7,INPUT);// put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() { // put your main code here, to run repeatedly:
 val1=digitalRead(7);
 if(Serial.available() > 0){
  val=Serial.read();
  }
 if(val1==HIGH){
  Serial.write('1');
 }
 else{
  Serial.write('0');
 }
}
