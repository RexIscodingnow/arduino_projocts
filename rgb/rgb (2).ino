#define LEDR 11
#define LEDG 10
#define LEDB 9 
int value1=0;
int value2=0;
int value3=0;
void setup() {
 pinMode(LEDR,OUTPUT);
 pinMode(LEDG,OUTPUT);
 pinMode(LEDB,OUTPUT);
 pinMode(14,INPUT);
 pinMode(15,INPUT);
 pinMode(16,INPUT);   
}
 
void loop() {
 value1=analogRead(14)/4;
 analogWrite(LEDR,value1); 
 value2=analogRead(15)/4;
 analogWrite(LEDG,value2); 
 value3=analogRead(16)/4;
 analogWrite(LEDB,value3);
 delay(50);
}
