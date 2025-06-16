#include <Arduino.h>

//アナログ入力ピンの設定
const int PowerPin = A1;
const int ThermistorPin = A0; //A0を使用

//定数の定義
const float B = 3435.0; //サーミスタのB定数
const float R0 = 9850.0; //サーミスタの25度での抵抗値（カタログ値）
const float Rv = 4610.0; //分圧抵抗の抵抗値
const float Tk = 273.15; //0度=273.15ケルビン
const float T0 = 25;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  float powValue = analogRead(PowerPin);
  int therValue = analogRead(ThermistorPin);
  //Serial.println(powValue);
  //Serial.println(therValue);
  //サーミスタ分圧からサーミスタ抵抗を読み取る
  float Rth = Rv * (powValue - therValue) / therValue;
  //温度Kを計算
  float T = 1/(1/(T0+Tk)+1/B*log(Rth/R0));
  //温度degree celciusを計算
  float deg = T - Tk;
  Serial.print(deg);
  Serial.println(" degC");
  //1秒待機
  delay(1000);
}
