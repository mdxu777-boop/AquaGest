#include <Wire.h>

#define MPU 0x68

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);

  int16_t ax = Wire.read() << 8 | Wire.read();
  int16_t ay = Wire.read() << 8 | Wire.read();
  int16_t az = Wire.read() << 8 | Wire.read();
  int16_t tmp = Wire.read() << 8 | Wire.read();
  int16_t gx = Wire.read() << 8 | Wire.read();
  int16_t gy = Wire.read() << 8 | Wire.read();
  int16_t gz = Wire.read() << 8 | Wire.read();

  float Ax = ax / 16384.0;
  float Ay = ay / 16384.0;
  float Az = az / 16384.0;
  float Temp = tmp / 340.0 + 36.53;  // MPU6050官方公式
  float AngleX = atan2(Ay, Az) * 180 / PI;
  float AngleY = atan2(-Ax, Az) * 180 / PI;
  float Gx = gx / 131.0;
  float Gy = gy / 131.0;
  float Gz = gz / 131.0;

  // Serial.print("加速度(g)   X:"); Serial.print(Ax);
  // Serial.print(" Y:"); Serial.print(Ay);
  // Serial.print(" Z:"); Serial.println(Az);

  // Serial.print("温度(°C)    "); Serial.println(Temp);

  // Serial.print("角度(°)     X:"); Serial.print(AngleX);
  // Serial.print(" Y:"); Serial.println(AngleY);

  // Serial.print("角速度(°/s) X:"); Serial.print(Gx);
  // Serial.print(" Y:"); Serial.print(Gy);
  // Serial.print(" Z:"); Serial.println(Gz);

  // Serial.println("---");
  // delay(5);

  // 绘图仪格式：变量名:数值 空格分隔
  Serial.print("AccX:"); Serial.print(Ax);
  Serial.print(" AccY:"); Serial.print(Ay);
  Serial.print(" AccZ:"); Serial.print(Az);
  Serial.print(" Temp:"); Serial.print(Temp);
  Serial.print(" AngleX:"); Serial.print(AngleX);
  Serial.print(" AngleY:"); Serial.print(AngleY);
  Serial.print(" GyroZ:"); Serial.println(Gz);

  delay(0); 

}