#include <SCServo.h>
HLSCL hlscl;

byte ID[2];
s16 Speed[2];
byte ACC[2];
u16 Torque[2];

void setup()
{
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  delay(1000);
  hlscl.WheelMode(1);//舵机ID1切换至恒速模式
  hlscl.WheelMode(2);//舵机ID2切换至恒速模式
  ID[0] = 1;//舵机ID1
  ID[1] = 2;//舵机ID2
  ACC[0] = 50;//加速度A=50*8.7deg/s^2
  ACC[1] = 50;//加速度A=50*8.7deg/s^2
  Torque[0] = 500;//最大扭矩电流T=500*6.5=3250mA
  Torque[1] = 500;//最大扭矩电流T=500*6.5=3250mA
}

void loop()
{
  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，加速至最高速度V=60*0.732=43.92rpm，并保持恒速运行，最大扭矩电流T=500*6.5=3250mA
  Speed[0] = 60;
  Speed[1] = 60;
  hlscl.SyncWriteSpe(ID, 2, Speed, ACC, Torque);
  delay(5000);

  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，减速至速度0停止运行
  Speed[0] = 0;
  Speed[1] = 0;
  hlscl.SyncWriteSpe(ID, 2, Speed, ACC, Torque);
  delay(2000);
  
  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，加速至最高速度V=-60*0.732=-43.92rpm，并保持恒速运行，最大扭矩电流T=500*6.5=3250mA
  Speed[0] = -60;
  Speed[1] = -60;
  hlscl.SyncWriteSpe(ID, 2, Speed, ACC, Torque);
  delay(5000);

  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，减速至速度0停止运行
  Speed[0] = 0;
  Speed[1] = 0;
  hlscl.SyncWriteSpe(ID, 2, Speed, ACC, Torque);
  delay(2000);
}
