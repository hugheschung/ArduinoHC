/*
  時間：2018/05/24
  作者：黑修斯(陳建仲)
  版本v2
  程式名稱：I2C測試程式---用於兩個arduino溝通---透過指令回傳
  說明：I2C主端程式
*/

#include <Wire.h>  //插入I2C函式庫
int val;          //定義val為整數

void setup(){

   Serial.begin(9600);    //設定serial 鮑率為9600
   Wire.begin(); //I2C位址與連線設定，主端不用設
}


void loop(){
  if(Serial.available()){   //判斷Serial.available())有沒有訊號
   val = Serial.read();     //將傳入的訊號Serial.read()指定給val
   if(val == '1'){         //如果val == 字串1 執行內容
  Wire.beginTransmission(3);  //開始傳送，指定給從端3號
  Wire.write("1");            //寫入訊息 "1"
  Wire.endTransmission();      //結束通訊
  Serial.println("指令1已經發送");   //透過Serial印出  "指令1已經發送"
  }
  if(val == '0'){        //如果val == 字串0 執行內容
  Wire.beginTransmission(3);  //開始傳送，指定給從端3號
  Wire.write("0");           //寫入訊息 "0"
  Wire.endTransmission();    //結束通訊
   Serial.println("指令0已經發送");   //透過Serial印出  "指令0已經發送"
  }
}
}
