
  #include <Wire.h>
  
  #define ENABLE 9 ;  // on L298
  #define P1 7 ;      // on L298
  #define P2 6 ;      // on L298
  //DC Motor connect to the motor interface
  
  const int switchPin = ENABLE; 
  const int motorPin1 =  P1; 
  const int motorPin2 =  P2;
  
  uint8_t motorSpeed = 10;

  void setup() {
    // put your setup code here, to run once:
    // initialize the motor pin as an output:
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    // initialize the switch pin as an input:
    pinMode(switchPin, INPUT);
    }
 
  void loop() {
    // put your main code here, to run repeatedly:
     motorClockwise( forward, motorSpeed);
     delay(3000); //3 sec
     motorStop();
    delay(3000);
    motorCounterClock( backward, motorSpeed);
    delay(3000);
    motorStop();
    delay(3000);
    }
