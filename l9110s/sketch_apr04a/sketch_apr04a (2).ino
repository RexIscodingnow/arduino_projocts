int seg7[]={11,10,9,8,7,6,5};
char TAB[]={0x3F,0x06,0x4B,0x66,0x7D,0x27,0x7F,0x67};
int i,j;
void setup() {
  for(i=0;i<7;i++){
  pinMode(seg7[i],OUTPUT);   // put your setup code here, to run once:
 }
}

void loop() {
  for(i=0;i<10;i++){
   OutPort(TAB[i]); 
   delay(500);// put your main code here, to run repeatedly:
 }
}
void OutPort(byte dat){
   for(j=0;j<7;j++){
    if(dat % 2==1){
      digitalWrite(seg7[j],HIGH);
    }
   else{
     digitalWrite(seg7[j],LOW);
     dat=dat/2;
    }
  }
}
