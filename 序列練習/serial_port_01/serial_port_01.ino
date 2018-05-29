
/*  
  時間：2018/05/15
  作者：黑修斯 (陳建仲)
  版本：v01
  程式名稱：serial_port_01
  說明：用於serial port教學說明，輸入1亮起LDE，輸入0關閉LED。
*/
int LED = 13;   //定義LED的腳位
// the setup function runs once when you press reset or power the board
void setup() {
  // 初始化設定
  pinMode(LED, OUTPUT);
  Serial.begin(9600);   //設定的鮑率
  Serial.println("start up!!");  //初起化完成透過Serial送出(start up!!)字串。
}


void loop() {
 if(Serial.available()){  //接受是否有訊號傳入
  int val;
  val = Serial.read();    //將val設為傳入的數值
  if(val == '0'){        //如果收到字元0 ，關閉LED燈
    digitalWrite(LED, LOW);
    Serial.println("LED LOW");
  }
  if(val == '1'){       //如果收到字元1 ，開啟LED燈
    digitalWrite(LED, HIGH);
    Serial.println("LED HIGH");  
  }
 }
}
