#include <Servo.h>
Servo servo1;
#define PinServo 6


void setup() {
  // put your setup code here, to run once:
  servo1.attach(PinServo);
  Serial.begin(9600);
  Serial.print("Digite um angulo: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
   if (Serial.available()) {
    int angulo = Serial.parseInt();
    servo1.write(angulo);
    
  }*/
  delay(2000);
  servo1.write(11);
  delay(2000);
  servo1.write(150);
  delay(2000);
}
