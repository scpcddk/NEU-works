#include <LiquidCrystal.h>

// 定义引脚
const int ldrPin = A0;      // 光敏电阻连接到 A0
const int buttonPin = 2;    // 模拟雨天传感器的按键连接到 2
const int motorPin1 = 8;    // 电机驱动引脚1
const int motorPin2 = 9;    // 电机驱动引脚2
const int ledPin = 13;      // 状态指示灯

// 初始化 LCD (引脚参考 Proteus 标准连接: RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // 使用内置上拉电阻
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(ledPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("System Ready");
  delay(1000);
}

void loop() {
  int lightVal = analogRead(ldrPin); // 读取光强度
  int rainState = digitalRead(buttonPin); // 读取按键状态 (LOW为按下)

  lcd.clear();
  lcd.setCursor(0, 0);

  // 逻辑判断：如果光线弱 (阈值设为300) 或者 检测到雨水 (按键按下)
  if (lightVal < 300 || rainState == LOW) {
    lcd.print("Status: RETRACT"); // 显示：收回
    digitalWrite(ledPin, HIGH);   // 报警灯亮
    // 模拟电机收回动作
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  } else {
    lcd.print("Status: EXTEND");  // 显示：伸出
    digitalWrite(ledPin, LOW);    // 报警灯灭
    // 模拟电机伸出动作
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }

  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.print(lightVal);
  
  delay(500); // 刷新频率
}