/*
同步读指令，回读ID1与ID2两个舵机的位置与速度信息
*/

#include <SCServo.h>

SMS_STS sms_sts;

uint8_t ID[] = {1, 2};
uint8_t rxPacket[4];
int16_t Position;
int16_t Speed;

void setup()
{
  Serial.begin(115200);
  //Serial1.begin(115200);//sms舵机波特率115200
  Serial1.begin(1000000);//sts舵机波特率1000000
  sms_sts.pSerial = &Serial1;
  sms_sts.syncReadBegin(sizeof(ID), sizeof(rxPacket), 5);//10*10*2=200us<5ms
  delay(1000);
}

void loop()
{  
  sms_sts.syncReadPacketTx(ID, sizeof(ID), SMS_STS_PRESENT_POSITION_L, sizeof(rxPacket));//同步读指令包发送
  for(uint8_t i=0; i<sizeof(ID); i++){
    //接收ID[i]同步读返回包
    if(!sms_sts.syncReadPacketRx(ID[i], rxPacket)){
     Serial.print("ID:");
     Serial.println(ID[i]);
     Serial.println("sync read error!");
     continue;//接收解码失败
    }
    Position = sms_sts.syncReadRxPacketToWrod(15);//解码两个字节 bit15为方向位,参数=0表示无方向位
    Speed = sms_sts.syncReadRxPacketToWrod(15);//解码两个字节 bit15为方向位,参数=0表示无方向位
    Serial.print("ID:");
    Serial.println(ID[i]);
    Serial.print("Position:");
    Serial.println(Position);
    Serial.print("Speed:");
    Serial.println(Speed);
  }
  delay(10);
}
