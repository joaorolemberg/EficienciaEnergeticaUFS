/*
int seg =0, seg2 =0, mini= 0;
void setup(){
Serial.begin(9600);
}

void loop(){
  static unsigned long ult_tempo = 0;
  int tempo = millis();
  if((tempo - ult_tempo) >= 1000){
    ult_tempo = tempo;
    seg++; seg2++;
   }
  if(seg >= 60){
    seg =0;
    seg2 =0;
    mini++;
  };
  
  Serial.print("Tempo: ");
  Serial.print(mini);
  Serial.print(" : ");
  Serial.println(seg2);
 

}
*/
int segundos=0;
int minutos=0;

void setup(){
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);

  
  }
void loop(){

  
  
  if(digitalRead(4)==HIGH){
    digitalWrite(2,HIGH);
   }else{
      digitalWrite(2,LOW);
   }
  delay(1000);
  segundos+=1;
  if (segundos==60){
    minutos+=1;
    segundos =0;  
  }
  String tempo="Tempo= ";
  tempo+=minutos;
  tempo+=":";
  tempo+=segundos;
  Serial.println(tempo);
  
  }
