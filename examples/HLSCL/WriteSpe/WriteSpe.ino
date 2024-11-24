#include <SCServo.h>

HLSCL hlscl;

void setup()
{
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  delay(1000);
  hlscl.WheelMode(1);//舵机ID1切换至电机恒速模式
}

void loop()
{
  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，加速至最高速度V=60*0.732=43.92rpm，并保持恒速正向旋转，最大扭矩电流T=500*6.5=3250mA
  hlscl.WriteSpe(1, 60, 50, 500);
  delay(5000);
  
  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，减速至速度0停止旋转
  hlscl.WriteSpe(1, 0, 50, 500);
  delay(2000);
  
  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，加速至最高速度V=-60*0.732=-43.92rpm，并保持恒速反向旋转，最大扭矩电流T=500*6.5=3250mA
  hlscl.WriteSpe(1, -60, 50, 500);
  delay(5000);
  
  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，减速至速度0停止旋转
  hlscl.WriteSpe(1, 0, 50, 500);
  delay(2000);
}
