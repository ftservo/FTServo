#include <SCServo.h>
SMS_STS sms_sts;

byte ID[2];
s16 Speed[2];
byte ACC[2];

void setup()
{
  //Serial1.begin(115200);//sms_stss舵机波特率115200
  Serial1.begin(1000000);//sts舵机波特率1000000
  sms_sts.pSerial = &Serial1;
  delay(1000);
  sms_sts.WheelMode(1);//舵机ID1切换至恒速模式
  sms_sts.WheelMode(2);//舵机ID2切换至恒速模式
  ID[0] = 1;//舵机ID1
  ID[1] = 2;//舵机ID2
  ACC[0] = 50;//加速度A=50*8.7deg/s^2
  ACC[1] = 50;//加速度A=50*8.7deg/s^2
}

void loop()
{
  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，加速至最高速度V=60*0.732=43.92rpm，并保持恒速正向旋转
  Speed[0] = 60;
  Speed[1] = 60;
  sms_sts.SyncWriteSpe(ID, 2, Speed, ACC);
  delay(5000);

  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，减速至速度0停止旋转
  Speed[0] = 0;
  Speed[1] = 0;
  sms_sts.SyncWriteSpe(ID, 2, Speed, ACC);
  delay(2000);
  
  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，加速至最高速度V=-60*0.732=-43.92rpm，并保持恒速反向旋转
  Speed[0] = -60;
  Speed[1] = -60;
  sms_sts.SyncWriteSpe(ID, 2, Speed, ACC);
  delay(5000);

  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，减速至速度0停止运行
  Speed[0] = 0;
  Speed[1] = 0;
  sms_sts.SyncWriteSpe(ID, 2, Speed, ACC);
  delay(2000);
}
