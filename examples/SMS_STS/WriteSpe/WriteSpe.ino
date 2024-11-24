#include <SCServo.h>

SMS_STS sms_sts;

void setup()
{
  //Serial1.begin(115200);//sms舵机波特率115200
  Serial1.begin(1000000);//sts舵机波特率1000000
  sms_sts.pSerial = &Serial1;
  delay(1000);
  sms_sts.WheelMode(1);//舵机ID1切换至电机恒速模式
}

void loop()
{
  //舵机(ID1)以加速度A=50*8.7deg/s^2，加速至最高速度V=60*0.732=43.92rpm，并保持恒速正向旋转
  sms_sts.WriteSpe(1, 60, 50);
  delay(5000);
  
  //舵机(ID1)以加速度A=50*8.7deg/s^2，减速至速度0停止旋转
  sms_sts.WriteSpe(1, 0, 50);
  delay(2000);
  
  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，加速至最高速度V=-60*0.732=-43.92rpm，并保持恒速反向旋转
  sms_sts.WriteSpe(1, -60, 50);
  delay(5000);
  
  //舵机(ID1/ID2)以加速度A=50*8.7deg/s^2，减速至速度0停止旋转
  sms_sts.WriteSpe(1, 0, 50);
  delay(2000);
}
