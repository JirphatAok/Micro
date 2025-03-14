int pushButton = 2; 
int greenLed = 7; 
int orangeLed = 8; 
int redLed = 9; 
int stat = 7;

void setup() 
{ 
    pinMode(greenLed, OUTPUT); 
    pinMode(orangeLed, OUTPUT); 
    pinMode(redLed, OUTPUT); 
    pinMode(pushButton, INPUT); 
    Serial.begin(115200);
} 

void loop() 
{ 

    while (digitalRead(pushButton) == 0) {
        digitalWrite(greenLed, HIGH);
    }

    delay(500); 

    digitalWrite(greenLed, LOW);

    for (int i = 0; i < 3; i++) {
        digitalWrite(stat, HIGH);
        delay(1000);
        digitalWrite(stat, LOW);
        stat--;
        if (stat < greenLed) {
            stat = redLed;
        }
    }
}
