#include <SoftwareSerial.h>   // 引用程式庫

// 定義連接藍牙模組的序列埠
SoftwareSerial BT(8, 9); // 接收腳, 傳送腳
char val;  // 儲存接收資料的變數
void setup() {
  pinMode(7,INPUT);
  // 藍牙透傳模式的預設連線速率。
  BT.begin(9600);
}

void loop() {
  // 若收到「序列埠監控視窗」的資料，則送到藍牙模組
  val=digitalRead(7);
 // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    val = BT.read();
    BT.print(val);   
  }
}
