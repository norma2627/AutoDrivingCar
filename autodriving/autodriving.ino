#include <Servo.h>   //サーボモーターのライブラリ
#include <AFMotor.h>  //AFMotorライブラリ

#define trigPin 50   // 超音波センサーのtrig pin
#define echoPin 52   // 超音波センサーのecho pin
#define servoPin 53   // サーボモーターのpin

Servo myservo;   //servoオブジェクトの宣言

AF_DCMotor motor1(1);  // 左のモーターをM1に接続
AF_DCMotor motor2(2);  // 右のモーターをM2に接続


void setup(){
  
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myservo.attach(servoPin);   //サーボの割り当て

  //モーターを一旦停止させる
  motor1.run(RELEASE);  
  motor2.run(RELEASE);
  delay(2000);

  ///正面を向く
  myservo.write(50);

}

void loop(){

  checkForward();
  moveForward(3000);

}


float measure(){
  
  //超音波の停止
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);

  //超音波の出力
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(11);

  //超音波の出力終了
  digitalWrite(trigPin, LOW);

  //出力した超音波が返って来る時間を計測
  int t = pulseIn(echoPin, HIGH);

  //計測した時間と音速から反射物までの距離を計算
  float sonic = 331.5 + 0.6 * 26;   //26℃を想定
  float distance = (float)t * ((sonic*0.0001)/2);
  //float distance = t*0.017;

  //計算結果をシリアル通信で出力
  Serial.print(distance);
  Serial.println(" cm");

  //delay(500);

  if(distance < 0){
    distance = 20;
  }
  return distance;

}


//停止
void moveStop(int n){
  // モータースピードを設定(0~255の範囲)
  motor1.setSpeed(255);  
  motor2.setSpeed(255); 
  //左右のモーターを停止させる
  motor1.run(RELEASE);   
  motor2.run(RELEASE);
  delay(n);
}

//前進
void moveForward(int n) {
  // モータースピードを設定(0~255の範囲)
  motor1.setSpeed(255);  
  motor2.setSpeed(255); 
  //左右のモーターを前に回転させる
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(n);
}

//後退
void moveBackward(int n){
  // モータースピードを設定(0~255の範囲)
  motor1.setSpeed(255);  
  motor2.setSpeed(255); 
  //左右のモーターを後ろに回転させる
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(n);
}

/*
//右回転
void turnRight(int n){
  // モータースピードを設定(0~255の範囲)
  motor1.setSpeed(255);  
  motor2.setSpeed(255); 
  //左モーター:前、右モーター:後ろに回転させる
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(n);
}

//左回転
void turnLeft(int n){
  // モータースピードを設定(0~255の範囲)
  motor1.setSpeed(255);  
  motor2.setSpeed(255); 
  //左モーター:前、右モーター:後ろに回転させる
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(n);
}
*/


//前方の障害物確認
void checkForward(){

  //正面を向く
  myservo.write(50);
  delay(300);
  Serial.print("Forward:");
  float distance = measure();

  //距離が近づいたら避ける
  if(distance < 10){
    avoid();
  }

}


//障害物を避ける
void avoid(){
  
  //停止後、後方へ移動
  Serial.print("Avoid:");
  moveStop(3000);
  moveBackward(5000);

}






