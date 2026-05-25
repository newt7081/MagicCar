### 初始設定
> 在主程式內定義馬達的GPIO引腳
> ```
> int motor_pin[] = {p1, p2, p3, p4};
> ```
### 呼叫
> `Front()`前
> `Back()`後
> `Left()`左(原地)
> `Right()`右(原地)
> `Left_()`左(輪差)
> `Right_()`右(輪差)
> `Stop()`停

### 馬達調速
>  設定馬達轉速`<value:1~150>`
> 最低值 (1) 大約為曹老師教室內使用的黑色馬達的最低可移動速度作為參考。
> ```
> MotorMode_2p.Speed(<int:value>);
> ```
> 例 :
> ```
> MotorMode_2p.Speed(<int:value>);
> while(True){
>   MotorMode_2p.Speed_Front();
> }
> ```
