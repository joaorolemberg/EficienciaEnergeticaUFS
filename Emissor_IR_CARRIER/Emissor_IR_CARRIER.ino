// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!
 
int IRledPin =  13;    // LED connected to digital pin 13
int parada=0; 
// The setup() method runs once, when the sketch starts



void setup()   {
// initialize the IR digital pin as an output:
pinMode(IRledPin, OUTPUT);
 
Serial.begin(9600);
Serial.println("Os comandos são");
Serial.println("l - Ligar");
Serial.println("d - Desligar");
Serial.println("b - Baixar temperatura");
Serial.println("a - Aumentar temperatura");
}
 
void loop()
{

  // BLOCO PARA RECEBER DADOS DA SERIAL E INICIAR EMISSOR IR
  if (Serial.available()) {
    char tecla = Serial.read();

    switch (tecla) {
      case 'l':
        
        Serial.println("Enviando Ligar");
        Ligar();
        delay(500);
        break;

      case 'd':
        Serial.println("Enviando Desligar");
        Desligar();
        delay(500);
        break;

      case 'a':
        Serial.println("Enviando Aumentar_temp");
        Aumentar_temp();
        delay(500);
        break;

      case 'b':
        Serial.println("Enviando Baixar_temp");
        Baixar_temp();
        delay(500);
        break;
    }
  }


 
}
 
// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
// we'll count down from the number of microseconds we are told to wait
 
cli();  // this turns off any background interrupts
 
while (microsecs > 0) {
// 38 kHz is about 13 microseconds high and 13 microseconds low
digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
delayMicroseconds(10);         // hang out for 10 microseconds
digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
delayMicroseconds(10);         // hang out for 10 microseconds
 
// so 26 microseconds altogether
microsecs -= 26;
}
 
sei();  // this turns them back on
}
 
void Desligar() {
   delayMicroseconds(57404);
pulseIR(9240);
delayMicroseconds(4680);
pulseIR(520);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(1760);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(1760);
pulseIR(540);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(1740);
pulseIR(540);
delayMicroseconds(1760);
pulseIR(540);
delayMicroseconds(1760);
pulseIR(540);
delayMicroseconds(640);
pulseIR(520);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(520);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(520);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(620);
pulseIR(520);
delayMicroseconds(660);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(520);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(1760);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(1760);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(1780);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(520);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(640);
pulseIR(520);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(620);
pulseIR(540);
delayMicroseconds(640);
pulseIR(520);
delayMicroseconds(640);
pulseIR(540);
delayMicroseconds(1760);
pulseIR(540);
delayMicroseconds(1740);
pulseIR(560);
delayMicroseconds(1740);
pulseIR(540);
delayMicroseconds(1780);
pulseIR(520);
}

void Ligar(){

delayMicroseconds(40400);
pulseIR(9240);
delayMicroseconds(4640);
pulseIR(580);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(580);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(600);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(600);
delayMicroseconds(580);
pulseIR(600);
delayMicroseconds(560);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(600);
delayMicroseconds(580);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(580);
pulseIR(560);
delayMicroseconds(600);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(580);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(560);
delayMicroseconds(620);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(1700);
pulseIR(600);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(1720);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(560);
delayMicroseconds(600);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(600);
delayMicroseconds(560);
pulseIR(600);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(600);
delayMicroseconds(1700);
pulseIR(560);
delayMicroseconds(1740);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(560);

  
}

void Aumentar_temp(){
  
delayMicroseconds(11640);
pulseIR(9260);
delayMicroseconds(4640);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(1740);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(1740);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(620);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(1700);
pulseIR(600);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(1740);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(1700);
pulseIR(600);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(1700);
pulseIR(580);
delayMicroseconds(1740);
pulseIR(560);

}

void Baixar_temp(){
  
delayMicroseconds(64676);
pulseIR(9240);
delayMicroseconds(4660);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(1740);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(1740);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(620);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(1760);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(620);
pulseIR(580);
delayMicroseconds(580);
pulseIR(560);
delayMicroseconds(600);
pulseIR(580);
delayMicroseconds(580);
pulseIR(580);
delayMicroseconds(600);
pulseIR(560);
delayMicroseconds(1740);
pulseIR(560);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
delayMicroseconds(1720);
pulseIR(580);
  
}
