const int redLed = 2; // ขาเชื่อมต่อของ LED สีแดง
const int yellowLed = 3; // ขาเชื่อมต่อของ LED สีเหลือง
const int greenLed = 4; // ขาเชื่อมต่อของ LED สีเขียว
const int whiteLed = 5; // ขาเชื่อมต่อของ LED สีขาว

const int redButton = 8; // ขาเชื่อมต่อของปุ่มสีแดง
const int yellowButton = 9; // ขาเชื่อมต่อของปุ่มสีเหลือง
const int greenButton = 10; // ขาเชื่อมต่อของปุ่มสีเขียว
const int whiteButton = 11; // ขาเชื่อมต่อของปุ่มสีขาว

int activeLed; // ตัวแปรเก็บ LED ที่กำลังเปิดอยู่
int score = 0; // ตัวแปรเก็บคะแนน
unsigned long lastChangeTime = 3; // เวลาที่เปลี่ยน LED ล่าสุด
const unsigned long changeInterval = 3000; // ระยะเวลาในการเปลี่ยน LED (2 วินาที)

void setup() {
  pinMode(redLed, OUTPUT); // กำหนดให้ขาของ LED สีแดงเป็น OUTPUT
  pinMode(yellowLed, OUTPUT); // กำหนดให้ขาของ LED สีเหลืองเป็น OUTPUT
  pinMode(greenLed, OUTPUT); // กำหนดให้ขาของ LED สีเขียวเป็น OUTPUT
  pinMode(whiteLed, OUTPUT); // กำหนดให้ขาของ LED สีขาวเป็น OUTPUT

  pinMode(redButton, INPUT); // กำหนดให้ขาของปุ่มสีแดงเป็น INPUT
  pinMode(yellowButton, INPUT); // กำหนดให้ขาของปุ่มสีเหลืองเป็น INPUT
  pinMode(greenButton, INPUT); // กำหนดให้ขาของปุ่มสีเขียวเป็น INPUT
  pinMode(whiteButton, INPUT); // กำหนดให้ขาของปุ่มสีขาวเป็น INPUT

  Serial.begin(9600); // เริ่มต้นการสื่อสารผ่าน Serial Monitor
  randomSeed(analogRead(A0)); // ใช้ค่า random จาก input analog เพื่อสุ่ม
  activateRandomLed(); // เรียกใช้งานฟังก์ชันสุ่มเปิด LED
}

void loop() {
  checkButtonPress(); // ตรวจสอบการกดปุ่ม

  // เช็คเวลาหากผ่านไปเกิน 3 วินาที ให้เปลี่ยน LED
  if (millis() - lastChangeTime > changeInterval) {
    activateRandomLed(); // สุ่มเปิด LED ใหม่
    lastChangeTime = millis(); // บันทึกเวลาที่เปลี่ยน LED ล่าสุด
  }
}

// ฟังก์ชันสุ่มเปิด LED หนึ่งตัวและปิดตัวอื่น ๆ
void activateRandomLed() {
  digitalWrite(redLed, LOW); // ปิด LED สีแดง
  digitalWrite(yellowLed, LOW); // ปิด LED สีเหลือง
  digitalWrite(greenLed, LOW); // ปิด LED สีเขียว
  digitalWrite(whiteLed, LOW); // ปิด LED สีขาว

  activeLed = random(2, 6); // สุ่ม LED ที่จะเปิด (2 ถึง 5)
  digitalWrite(activeLed, HIGH); // เปิด LED ที่ถูกสุ่ม
}

// ฟังก์ชันตรวจสอบการกดปุ่ม
void checkButtonPress() {
  // ถ้ากดปุ่มสีแดงและ LED สีแดงกำลังเปิดอยู่
  if (digitalRead(redButton) == HIGH && activeLed == redLed) {
    score++; // เพิ่มคะแนน
    Serial.println("Hit Red! Score: " + String(score)); // แสดงข้อความใน Serial Monitor
    activateRandomLed(); // สุ่มเปิด LED ใหม่
  } 
  // ถ้ากดปุ่มสีเหลืองและ LED สีเหลืองกำลังเปิดอยู่
  else if (digitalRead(yellowButton) == HIGH && activeLed == yellowLed) {
    score++; // เพิ่มคะแนน
    Serial.println("Hit Yellow! Score: " + String(score)); // แสดงข้อความใน Serial Monitor
    activateRandomLed(); // สุ่มเปิด LED ใหม่
  } 
  // ถ้ากดปุ่มสีเขียวและ LED สีเขียวกำลังเปิดอยู่
  else if (digitalRead(greenButton) == HIGH && activeLed == greenLed) {
    score++; // เพิ่มคะแนน
    Serial.println("Hit Green! Score: " + String(score)); // แสดงข้อความใน Serial Monitor
    activateRandomLed(); // สุ่มเปิด LED ใหม่
  } 
  // ถ้ากดปุ่มสีขาวและ LED สีขาวกำลังเปิดอยู่
  else if (digitalRead(whiteButton) == HIGH && activeLed == whiteLed) {
    score++; // เพิ่มคะแนน
    Serial.println("Hit White! Score: " + String(score)); // แสดงข้อความใน Serial Monitor
    activateRandomLed(); // สุ่มเปิด LED ใหม่
  }
}