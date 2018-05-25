/*
  時間：2018/05/24
  作者：黑修斯(陳建仲)
  版本v101
  程式名稱：I2C測試程式---用於兩個arduino溝通part2
  說明：I2C測試程式---用於兩個arduino溝通
*/

#include <Wire.h>


void setup(){
   Wire.begin(3); //I2C位址與連線設定，主端不用設
   Wire.onReceive(receiveEvent);

   Serial.begin(9600);
}


void loop(){
  delay(100);
}

void receiveEvent(int numBytes){
  while(Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }
}

