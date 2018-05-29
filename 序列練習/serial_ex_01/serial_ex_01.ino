/*
  時間：2018/05/29
  作者：黑修斯(陳建仲)
  版本v1.0
  程式名稱： 序列練習(1)：兩個Arduino通訊---使用TX0、RX0---被動端程式
  說明：序列練習(1)：兩個Arduino通訊---使用TX0、RX0中的範例程式
*/


int LED=13;  //LED設為pin13
int val ;   
void setup() {
  pinMode(LED,OUTPUT);  //設定LED為輸出模式
  Serial.begin(9600);    //設定通訊鮑率
 
  }

void loop() {
 serial_blink();      
 
}  
  
  

void serial_blink() {
  while(!Serial.available()){}  //等待serial指令進入，如果Serial.available()沒有資料，就會一直等待
  if(Serial.available()){       //如果指令進入，會將Serial.read()的值設給val變數
 val = Serial.read();           
 if(val == '1'){               //val 收到1，LED燈亮，延遲1秒，並輸出字元1
  digitalWrite(LED, HIGH);
  delay(1000);
  Serial.print("1");
 }
  if(val == '0'){             //val 收到0，LED熄滅，延遲1秒，並輸出字元0
  digitalWrite(LED, LOW);
  delay(1000);
  Serial.print("0");
 }
 }
  }


