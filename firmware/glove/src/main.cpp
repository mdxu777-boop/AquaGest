#include <Arduino.h>

// ===== 串口通信测试 =====
// 功能：每秒通过串口发送一条消息，并监听接收到的数据
// 用途：验证VSCode + PlatformIO串口是否正常工作

void setup() {
  Serial.begin(115200);       // 开启串口，波特率115200
  delay(1000);  // 等待串口稳定
  Serial.println("AquaGest serial OK");  // 启动确认消息
}

void loop() {
  // 每1秒发送一次心跳
  Serial.println("hello from AquaGest");
  delay(1000);

  // 如果收到数据，原样回传（回显测试）
  if (Serial.available() > 0) {
    String received = Serial.readStringUntil('\n');
    Serial.print("received: ");
    Serial.println(received);
  }
}
