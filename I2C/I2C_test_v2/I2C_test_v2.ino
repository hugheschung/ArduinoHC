/*
  時間：2018/05/24
  作者：黑修斯(陳建仲)
  版本v2
  程式名稱：I2C測試程式---用於兩個arduino溝通---LED開關
  說明：I2C測試程式---用於兩個arduino溝通---LED開關
*/

#include <Wire.h>
int val;

void setup(){

   Serial.begin(9600);
   Wire.begin(); //I2C位址與連線設定，主端不用設
}


void loop(){
  if(Serial.available()){
   val = Serial.read();
   if(val == '1'){
  Wire.beginTransmission(3);
  Wire.write("1");
  Wire.endTransmission();
  Serial.println("指令1已經發送");
  }
  if(val == '0'){
  Wire.beginTransmission(3);
  Wire.write("0");
  Wire.endTransmission();
   Serial.println("指令0已經發送");
  }
}
}
