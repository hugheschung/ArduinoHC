/*
  時間：2018/05/29
  作者：黑修斯(陳建仲)
  版本v1.0
  程式名稱： serial_ex_02序列練習(1)：兩個Arduino通訊---使用TX0、RX0---發送端程式
  說明：序列練習(1)：兩個Arduino通訊---使用TX0、RX0---發送端程式
*/



int LED=13;
int val ;
void setup() {
   pinMode(LED,OUTPUT);
  Serial.begin(9600);
 
  }

void loop() {
 Serial.println("0");    //送出字元 0
 reback_blink();       //執行副程式 reback_blink(); 
 delay(1000);          
 Serial.println("1");    //送出字元 0
  reback_blink();        //執行副程式 reback_blink();
 delay(1000); 
}  
  
  

void reback_blink() {        //此副程式中的註解拿掉，可以用在單獨對電腦的測試
  while(!Serial.available()){/*Serial.println("wait");*/}
  if(Serial.available()){
 val = Serial.read();
 if(val == '1'){
  digitalWrite(LED, HIGH);
  //Serial.println("one");
 }
  if(val == '0'){
  digitalWrite(LED, LOW);
 //Serial.println("zero");
 }
 }
  }

