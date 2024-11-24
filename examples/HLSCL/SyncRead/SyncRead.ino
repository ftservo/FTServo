/*
同步读指令，回读ID1与ID2两个舵机的位置与速度信息
*/

#include <SCServo.h>

HLSCL hlscl;

uint8_t ID[] = {1, 2};
uint8_t rxPacket[4];
int16_t Position;
int16_t Speed;

void setup()
{
  Serial.begin(115200);
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  hlscl.syncReadBegin(sizeof(ID), sizeof(rxPacket), 5);//10*10*2=200us<5ms
  delay(1000);
}

void loop()
{  
  hlscl.syncReadPacketTx(ID, sizeof(ID), HLSCL_PRESENT_POSITION_L, sizeof(rxPacket));//同步读指令包发送
  for(uint8_t i=0; i<sizeof(ID); i++){
    //接收ID[i]同步读返回包
    if(!hlscl.syncReadPacketRx(ID[i], rxPacket)){
     Serial.print("ID:");
     Serial.println(ID[i]);
     Serial.println("sync read error!");
     continue;//接收解码失败
    }
    Position = hlscl.syncReadRxPacketToWrod(15);//解码两个字节 bit15为方向位,参数=0表示无方向位
    Speed = hlscl.syncReadRxPacketToWrod(15);//解码两个字节 bit15为方向位,参数=0表示无方向位
    Serial.print("ID:");
    Serial.println(ID[i]);
    Serial.print("Position:");
    Serial.println(Position);
    Serial.print("Speed:");
    Serial.println(Speed);
  }
  delay(10);
}
