
void setup() { //程式初始化的地方

  // initialize digital pin LED_BUILTIN as an output.

  //初始化腳位設，將LED_BUILTIN(pin13)設為輸出。

  pinMode(LED_BUILTIN, OUTPUT);

}



// the loop function runs over and over again forever

//主程式運行的地方

void loop() {

  //使pin13的LED燈---亮

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  //延遲時間1秒

  delay(1000);                       // wait for a second

  //使pin13的LED燈---滅

  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

  //延遲時間1秒

  delay(1000);                       // wait for a second

}

