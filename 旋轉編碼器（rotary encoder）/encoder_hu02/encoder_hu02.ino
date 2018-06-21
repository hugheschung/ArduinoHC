/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  時間：2018/06/20
 *  作者：黑修斯 (陳建仲)
 *  檔名：encoder_hu02
 *  版本：v01
 *  說明：旋轉編碼器模組加入中斷來計算，減少丟步(遺失訊號)。
 */
 
 #define outputA 2           //定義 outputA = 2
 #define outputB 7           //定義 outputB = 7
 int counter = 0;            //定義 counter 為 int 類型變數，且初始值為0
 int aState;                 //定義 aState 為 int 類型變數
 int aLastState;             //定義 aLastState 為 int 類型變數

 //初始化設定↓↓↓
 void setup() { 
   pinMode (outputA,INPUT);               //埠口模式設定：outputA 設為 輸入
   pinMode (outputB,INPUT);               //埠口模式設定：outputB 設為 輸入
   attachInterrupt (0, test, CHANGE);     //啟用中斷函式(中斷0,test函式,CHANGE模式)
   Serial.begin  (9600);                  //Serial通訊鮑率設為9600
   aLastState = digitalRead  (outputA);  //將初始outputA的讀取值 設給 aLastState
} 

//主程式運作區↓↓↓
 void loop() { 
    Serial.print("Position: ");  //透過serial印出字串 Position: 
    Serial.println(counter);     //透過serial印出 counter 值
 }

//test函式
void test(){
   aState = digitalRead(outputA);   //將outputA的讀取值 設給 aState

   if (aState != aLastState){  //條件判斷，當aState 不等於 aLastState時發生   
    
      if (digitalRead(outputB) != aState) {  //條件判斷，當outputB讀取值 不等於 aState時發生
        counter ++;       //計數器+1
      } else {
        counter --;      //計數器-1
      }
} 
   aLastState = aState;        //將aState 最後的值 設給 aLastState
}

