#define ledPin 13 
#define buttonPin 2 
boolean buttonState; 
int timeDelay; 
void setup (){ 
     pinMode(ledPin,OUTPUT); 
       pinMode(buttonPin, INPUT); 
}   
void loop(){ 
buttonState = digitalRead(buttonPin); 
       if(buttonState == LOW){ 
       timeDelay =200; 
       } 
       else { 
       timeDelay = 1000; 
  } 
       Blinkly(timeDelay); 
} 
void Blinkly (int timeDelay){ 
     digitalWrite(ledPin,HIGH); 
       delay(timeDelay); 
   digitalWrite(ledPin,LOW); 
       delay(timeDelay); 
}