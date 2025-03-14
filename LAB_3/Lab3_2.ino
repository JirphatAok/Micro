#define swOn 1  
#define swOff 2  
int count = 12;  
void setup(){ 
       for(int i = 5 ; i<=12; i++){ 
    pinMode(i,OUTPUT); 
  } 
  pinMode(swOn,INPUT); 
  pinMode(swOff,INPUT); 
  } 
  void loop (){ 
        if(digitalRead(swOn)==HIGH){ 
    for(int i =12; i>=5;i--){ 
           digitalWrite(i,HIGH); 
           delay(350); 
     } 
     } 
            if(digitalRead(swOff)==HIGH){ 
             for(int i = 5; i<=12; i++){ 
            digitalWrite(i,LOW); 
           delay(350); 
               } 
            }}