//程式開始
// 引用 Servo Library
#include <Servo.h> // 建立一個 Servo 物件
Servo myservo; // 旋轉角度
int value = 0;
void setup()
{ 
myservo.attach(9); // Servo 接在 pin 9
}

void loop()
{ 
if (value == 0) 
value = 180; 
else 
value = 0; 
myservo.write(90); //馬達到90度位置
// myservo.write(0) 是叫 Servo 旋轉到 0 度的位置 
// myservo.write(180) 是叫 Servo 旋轉到 180 度的位置 
delay(1500);
}
//程式結束