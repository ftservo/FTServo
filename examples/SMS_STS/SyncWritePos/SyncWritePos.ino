#include <SCServo.h>
SMS_STS sms_sts;

byte ID[2];
s16 Position[2];
u16 Speed[2];
byte ACC[2];

void setup()
{
  //Serial1.begin(115200);//sms_stss舵机波特率115200
  Serial1.begin(1000000);//sts舵机波特率1000000
  sms_sts.pSerial = &Serial1;
  delay(1000);
  ID[0] = 1;//舵机ID1
  ID[1] = 2;//舵机ID2
  Speed[0] = 60;//最高速度V=60*0.732=43.92rpm
  Speed[1] = 60;//最高速度V=60*0.732=43.92rpm
  ACC[0] = 50;//加速度A=50*8.7deg/s^2
  ACC[1] = 50;//加速度A=50*8.7deg/s^2
}

void loop()
{
  //舵机(ID1/ID2)以最高速度V=60*0.732=43.92rpm，加速度A=50*8.7deg/s^2，运行至P1=4095位置
  Position[0] = 4095;
  Position[1] = 4095;
  sms_sts.SyncWritePosEx(ID, 2, Position, Speed, ACC);
  delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(误差)

  //舵机(ID1/ID2)以最高速度V=60*0.732=43.92rpm，加速度A=50*8.7deg/s^2，运行至P0=0位置
  Position[0] = 0;
  Position[1] = 0;
  sms_sts.SyncWritePosEx(ID, 2, Position, Speed, ACC);
  delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(误差)
}
