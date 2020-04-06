//
//
//  ObjectDistance.ino
//
//  Created by Sameed Ahmed on 21/03/2020.
//  Copyright © 2020 Sameed Ahmed. All rights reserved.
//


//LidarSensor distance measurement method sends out a light pulse to calculate distance
int Distance_Object() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  float Fdistance = pulseIn(Echo, HIGH);
  Fdistance= Fdistance / 58;
  return (int)Fdistance;
}

//Object Must be within 70CM
if((rightDistance > 70)&&(leftDistance > 70)){
  stop();
}else if((rightDistance >= 20) && (leftDistance >= 20)) {
  forward();
}else if((rightDistance <= 10) && (leftDistance <= 10)) {
    back();  // 10CM distance Maintained from the object
    delay(100);
}else if(rightDistance - 3 > leftDistance) {
    left();  //If Right side is 3CM away it move towards left
    delay(100);
}else if(rightDistance + 3 < leftDistance) {
    right(); // //If left side is 3CM away it move towards Right
    delay(100);
}else{
  stop();
}
