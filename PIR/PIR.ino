
#define buzzer 9
#define PIR 8




void setup() {
pinMode(PIR,INPUT);


}

void loop() {
  bool readPir=digitalRead(PIR);
  int i=10;
  if(readPir==1){
    tone(buzzer,800,100);
    delay(1000);
  }
 
  
}
