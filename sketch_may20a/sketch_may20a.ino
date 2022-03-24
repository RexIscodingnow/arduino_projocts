
int line[8]={2,3,4,5,6,7,8,9}; // line[1]=3;line[0]=2
int col[8]={10,11,12,13,14,15,16,17};
        // C  L
int appear[8][8]={{0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0}, 
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0}, 
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0}}; 

void setup() {
  for( int i=0;i<8;i++){
      pinMode(line[i],OUTPUT);
      pinMode(col[i],OUTPUT);
      digitalWrite(line[i],LOW);
      digitalWrite(col[i],HIGH);      
  }
}

void loop() {
  for( int i=0;i<8;i++){ 
    for( int j=0;j<8;j++){
        if(appear[j][i]==1){ 
           digitalWrite(line[i],HIGH); 
           digitalWrite(col[j],LOW); 
           delay(1);
           digitalWrite(line[i],LOW);
           digitalWrite(col[j],HIGH);
        }                                       
      }
   }
}
