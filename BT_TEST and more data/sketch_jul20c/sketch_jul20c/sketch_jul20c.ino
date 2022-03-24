int val=0;
void setup() {
 pinMode(7,OUTPUT);
 digitalWrite(7,LOW);// put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
  val=Serial.read(); // Reads the data from the serial port
 }
 if(val=='1'){
  digitalWrite(7,HIGH);
  val=0;
 }
  if(val=='0'){
  digitalWrite(7,LOW);
  val=0;
 }
 delay(10);
}
