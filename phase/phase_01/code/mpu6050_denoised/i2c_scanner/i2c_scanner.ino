#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin();
  delay(1000);
  Serial.println("I2C 扫描中...");

  int found = 0;
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("找到设备: 0x");
      if (addr < 16) Serial.print("0");
      Serial.println(addr, HEX);
      found++;
    }
  }
  if (found == 0) Serial.println("未找到任何 I2C 设备，检查接线");
  else Serial.println("扫描完成");
}

void loop() {}
