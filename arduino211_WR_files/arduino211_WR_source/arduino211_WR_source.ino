/* ========================================================================================================
 
   Curso de Arduino e AVR 211
   
   WR Kits Channel


   Controle de Servos via Serial Monitor

    
   Autor: Eng. Wagner Rambo  Data: Fevereiro de 2019
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits
           
======================================================================================================== */

 
// ========================================================================================================
// --- Bibliotecas Auxiliares ---
#include <Servo.h>   //inclui biblioteca para controle de servo


// ========================================================================================================
// --- Objetos ---
Servo myservo;       //cria objeto para 1 servo motor


// ========================================================================================================
// --- Configurações Iniciais ---
void setup()
{

  Serial.begin(9600);   //inicializa serial em 9600 bps
  
  while (!Serial);      //aguarda iniciliazação da serial
  
  delay(1000);          //aguarda 1 segundo
   
  myservo.attach(9);    //associa servo ao pino 9

  Serial.println("Digite o grau de movimento e tecle enter...");

 
} //end setup


// ========================================================================================================
// --- Loop Infinito ---
void loop() 
{
  
  if(Serial.available())
  {
    int state = Serial.parseInt();
  
  
    if (state > 10 && state < 170)
    {
      Serial.print(" | ");
      Serial.println(state);
      Serial.print("Servo posicionado em ");
      Serial.print(state);
      Serial.println(" graus");
      myservo.write(state);
      
    }
  
  } //end if serial available

} //end loop














