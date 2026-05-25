/* [2026/05/25]-02:35-v1.0 */
// #sketch_22-2
/*
3,5,6,9,10,11
magiccar_mode-v1.0/
*/
// 引入目錄
int motor_pin[] = {3, 4, 5, 6};// 馬達pin
#include "magiccar_mode-v1.0/magiccar_mode.h"

// 定義pin腳
int pin_in[]    = {};
int pin_ou[]    = {3, 4, 5, 6};

int time1 = 0;
int time2 = 100;

void setup() {
  // 定義pin腳
  for (int p: pin_in){pinMode(p, INPUT);}
  for (int p: pin_ou){pinMode(p, OUTPUT);digitalWrite(p, LOW);}
  // Serial.begin(9600);
  MotorMode_2p.Speed(30);
}
/////--------------------------------------------------/////
// 7右 8左 9前
void loop() {
  while (digitalRead(7)&&digitalRead(8)){
  MotorMode_2p.Speed_Front();}
  if (digitalRead(7)==0){
    time1 = millis()/1000;
    MotorMode_2p.Left();}
  if (digitalRead(8)==0){
    time2 = millis()/1000;
    MotorMode_2p.Right();}
  if (digitalRead(9)==0&&abs(time2-time1)<=0.5){
    MotorMode_2p.Stop();
    delay(100);
    MotorMode_2p.Back();
    delay(250);
    MotorMode_2p.Right();// 迴轉
    delay(275);
    MotorMode_2p.Stop();
    time1 = 0;
    time2 = 100;
    delay(300);}

}
/////--------------------------------------------------/////
/*
MotorMode_2p.Front();
delayMicroseconds(100);
MotorMode_2p.Stop();
delayMicroseconds(50);

Front();
delayMicroseconds(M_Speed_A);
Stop();
delayMicroseconds(M_Speed_B);

map(aa, 0, 100, 100, 100000);
map(bb, 100, 100000, 50, 50000);

*/