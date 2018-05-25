/*
  時間：2018/05/24
  作者：黑修斯(陳建仲)
  版本v1.01
  程式名稱：I2C測試程式---用於兩個arduino溝通---單方面回傳hello
  說明：說明：I2C從端的程式設定
*/

#include <Wire.h>


void setup(){
   Wire.begin(3);   //I2C位址與連線設定，這裡設定為3號
   Wire.onReceive(receiveEvent);   //當收到I2C訊號時，啟動的動作

   Serial.begin(9600); //Serial輸出鮑率為9600
}


void loop(){
  delay(100);  //延遲0.1秒
}

//自定義的接收後的啟動副程式
void receiveEvent(int numBytes){
  while(Wire.available()){    //判斷Wire.available()有沒有訊號
    char c = Wire.read();     //將傳入的訊號Wire.read()指定給字串C
    Serial.print(c);          //透過Serial印出字串C的內容
  }
}

