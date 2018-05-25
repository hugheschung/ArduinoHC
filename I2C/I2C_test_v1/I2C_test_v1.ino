/*
  時間：2018/05/24
  作者：黑修斯(陳建仲)
  版本v1
  程式名稱：I2C測試程式---用於兩個arduino溝通---單方面回傳hello
  說明：I2C主端的程式設定
*/

#include <Wire.h>   //插入I2C函式庫<Wire>


void setup(){
   Wire.begin(); //I2C位址與連線設定，主端不用設
}


void loop(){
  Wire.beginTransmission(3);    //開始傳送，指定給從端3號
  Wire.write("hello \n");       //寫入訊息 hello \n
  Wire.endTransmission();       //結束通訊
}

