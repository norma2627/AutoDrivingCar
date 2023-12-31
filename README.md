# Arduinoで自動運転
Arduinoを使用し自動運転のロボットカーを作成しました 

## 完成形
ロボットカー
![正面](./images/front.jpg)
![右](./images/side.jpg) 
![左](./images/lside.jpg)
![後ろ](./images/back.jpg)
<br/>

## 材料
使用したもの<br/>
※今回は作成期間が限られていたので、手に入りやすい材料で作成しました <br/>
もっと良い材料があるかもしれません <br/>

### Arduino mega
Arduino UnoだとモータードライバがGpioピンを全て使用してしまうので、Arduino megaを使用<br/>
[Arduino Mega](https://amzn.asia/d/7uSjvky) <br/>

### モータードライバ
Arduinoの機能拡張シールド <br/>
Arduinoボードに接続するだけで機能を追加することができる <br/>
[KKHMF L293d](https://amzn.asia/d/cqGxtsh) <br/>

### モーター
今回は、ダブルギアボックスが手に入らなかったので、シングルギアボックスを2個繋げて使用しました<br/>
※2個繋げての使用だと、プレートに入らないのでギアボックスの角を削る必要がありました<br/>
ダブルギアボックスを使用した方が楽に組み立てが可能で見栄えもよくなると思います<br/>
[シングルギアボックス](https://amzn.asia/d/fMhvGMw) <br/>
[ダブルギアボックス](https://amzn.asia/d/jbmKmqR) <br/>

### プレート 
車体の土台となるプレート <br/>
2枚入っているので、上下に組み立てて使用する <br/>
[ユニバーサルプレート](https://amzn.asia/d/gD9fNzH) <br/>

### 車輪 
タイヤとホイールがセットとなっており、車体の大きさに合わせて車輪を作ることができる <br/>
[トラック&ホイールセット](https://amzn.asia/d/3UqQYvc) <br/>

### 電池 
モータードライバへの電力供給用 <br/>
[電池ボックス](https://amzn.asia/d/dlBoPju) <br/>

### サーボモーター 
超音波センサーと連結させて、超音波センサーが首を振れるようにするために使用する <br/>
[サーボモーター](https://amzn.asia/d/c1w4U9Z) <br/>

### 超音波センサー 
障害物との距離を測るために使用 <br/>
Arduinoの入門セットにも入ってる <br/>
[超音波センサー](https://amzn.asia/d/cwVZWaR) <br/>

### モバイルバッテリー 
モバイルバッテリーを使用することで、パソコンと連結させる必要がなくなる <br/>
独立して動けるようになる <br/>

### その他 
組み立てに必要な道具類 
- プラスドライバー 
- ハサミ 
<br/>

部品連結に使用したもの 
- 輪ゴム 
- 結束バンド 
<br/>
※部品同士を連結させるための部品が手に入らなかったので、輪ゴムや結束バンドで代用しました 


### [コード](https://github.com/norma2627/AutoDrivingCar/blob/main/autodriving/autodriving.ino)<br/>

### 使用したライブラリ
インストール方法
- スケッチ
    - ライブラリをインクルード
        - ライブラリを管理
<br/>
インストールしたライブラリ<br/>
モータードライバのライブラリ
- Adafruit Moter Sheild library 

### 障害物を検知する仕組み
超音波センサーを使用し障害物との距離を測ることで、車体をコントロールする<br/>

距離の測り方<br/>

距離 = 音速 * 往復時間 / 2<br/>
<br/>

音速の定義<br/>
音速 = 331.5 + 0.61 * t
<br/>
tは摂氏温度<br/>
<br/>

距離の計算方法<br/>
距離 = 331.5 + 0.61 * t * 往復時間 / 2<br/>
<br/>

往復時間<br/>
pulselnを使用することで、出力した超音波が帰ってくる時間を取得することができる<br/>


![説明](images/explain.jpg)






