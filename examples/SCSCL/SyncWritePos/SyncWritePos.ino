/*
同步写例子在SCS15中测试通过，如果测试其它型号SCS系列舵机请更改合适的位置、速度与延时参数。
*/

#include <SCServo.h>

SCSCL sc;

byte ID[2];
u16 Position[2];
u16 Speed[2];

void setup()
{
  Serial1.begin(1000000);
  sc.pSerial = &Serial1;
  delay(1000);
  ID[0] = 1;//舵机ID1
  ID[1] = 2;//舵机ID2
  Speed[0] = 1500;//最高速度V=1500*0.059=88.5rpm
  Speed[1] = 1500;//最高速度V=1500*0.059=88.5rpm
}

void loop()
{
  //舵机(ID1/ID2)以最高速度V=1500*0.059=88.5rpm，运行至P1=1000位置
  Position[0] = 1000;
  Position[1] = 1000;
  sc.SyncWritePos(ID, 2, Position, 0, Speed);
  delay((1000-20)*1000/(1500) + 100);//[(P1-P0)/(V)]*1000 + 100(误差)

  //舵机(ID1/ID2)以最高速度V=1500*0.059=88.5rpm，运行至P0=20位置
  Position[0] = 20;
  Position[1] = 20;
  sc.SyncWritePos(ID, 2, Position, 0, Speed);
  delay((1000-20)*1000/(1500) + 100);//[(P1-P0)/(V)]*1000 + 100(误差)
}
