/* [2026/05/25]-19:08-v1.0.1 */
// #阿杰Newt //
/*
.test (TEST a class)
#include "magiccar_mode.h"

#---[主程式定義pin腳]---#
int motor_pin[] = {p1, p2, p3, p4};
*/
// ------------------------- //
int M_Speed_A, M_Speed_B = 0;
class motor_mode_2p{
  public:
  // test--LED
  void test(int tpp){digitalWrite(tpp, HIGH);}
  // test--

  void Run(int ru1, int ru2, int ru3, int ru4){
    digitalWrite(motor_pin[0], ru1);
    digitalWrite(motor_pin[1], ru2);
    digitalWrite(motor_pin[2], ru3);
    digitalWrite(motor_pin[3], ru4);}
  void LED(int LED_pin, char LED_CurrentStatus){
    digitalWrite(LED_pin, LED_CurrentStatus);}
  void Speed(int M_Speed_M){// 前_調速 設定 <value:1~150>
    if (M_Speed_M==150){M_Speed_A=100000;M_Speed_B=0;}
    if (M_Speed_M<=100){
      M_Speed_A = map(M_Speed_M, 1, 100, 100, 100000);
      M_Speed_B = map(M_Speed_A, 100, 100000, 50, 50000);
    }
    else{
      M_Speed_A = 100000;
      M_Speed_B = 50000;
      M_Speed_B -= (M_Speed_M-100)*1000;
    }}
  void Speed_Front(){// 前_調速
    Front();delayMicroseconds(M_Speed_A);
    Stop();delayMicroseconds(M_Speed_B);}
  void Front() {Run(1 ,0, 1, 0);}// 前
  void Back()  {Run(0, 1, 0, 1);}// 後
  void Left()  {Run(0, 1, 1, 0);}// 左(原地)
  void Right() {Run(1, 0, 0, 1);}// 右(原地)
  void Left_() {Run(0, 0, 1, 0);}// 左(輪差)
  void Right_(){Run(1, 0, 0, 0);}// 右(輪差)
  void Stop()  {Run(0, 0, 0, 0);}// 停

  void Front_() {
    Run(1 ,0, 1, 0);
    delay(17);
    Run(1, 0, 0, 0);
    delay(2);
                                }// 前_(輪差矯正，測試寫法)
};
class motor_mode_4p{
  public:
  // test--LED
  void test(int tpp){digitalWrite(tpp, HIGH);}
  // test--
};
// ------------------------- //

// 宣告class名定義
// 可在 ".h" 檔案中直接宣告，如沒有宣告則可以在主程式單獨替提取並宣告
// motor_mode_2p tt7728_MotorMode;
motor_mode_2p MotorMode_2p;
motor_mode_4p MotorMode_4p;

// #阿杰Newt //