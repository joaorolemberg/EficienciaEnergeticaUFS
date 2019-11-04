#include <IRremote.h>
#include <IRremoteInt.h>

// INCLUSÃO DE BIBLIOTECA
#include <IRremote.h>

// DIRETIVAS DE COMPILAÇÃO
#define tempoTecla 350
#define frequencia 38 // kHz

// DEFINIÇÃO DOS PINOS
#define pinReceptor 11
#define pinBot1 8
#define pinLed 12

// INSTANCIANDO OBJETOS
IRrecv receptorIR(pinReceptor);
IRsend emissorIR;

// DECLARAÇÃO VARIÁVEIS GLOBAIS
bool lerComando = false;

// DECLARAÇÃO DAS FUNÇÕES DE LEITURA

void ircode   (decode_results *results);
void encoding (decode_results *results);
void dumpInfo (decode_results *results);
void dumpRaw  (decode_results *results);
void dumpCode (decode_results *results);

//  DECLARAÇÃO DAS TECLAS CLONADAS

unsigned int teclaDesligar[] = {8900,4500, 500,600, 550,550, 550,1650, 550,600, 550,550, 550,600, 550,550, 550,600, 550,600, 500,1700, 550,550, 550,600, 550,1650, 550,600, 500,600, 550,1700, 550,550, 550,600, 550,550, 550,600, 500,600, 550,550, 550,600, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,600, 500,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,1700, 550,550};
unsigned int teclaLigar[] = {8900,4450, 550,550, 550,600, 550,1650, 550,600, 550,1650, 550,550, 550,600, 550,550, 600,550, 550,1650, 600,550, 550,550, 550,1650, 600,550, 550,600, 550,1650, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,600, 550,550, 550,600, 500,600, 550,550, 550,600, 550,550, 550,600, 550,600, 550,1650, 550,550, 550,600, 550,550, 550,600, 550,550, 550,600, 550,1650, 550,600};
unsigned int teclaC[] = {};
unsigned int teclaD[] = {/*COPIE_OS_DADOS_DENTRO_DAS_CHAVES_DO_MONITOR_SERIAL_E_COLE_AQUI*/};

void setup() {
  Serial.begin(9600);

}

void loop() {
  
  
  // BLOCO PARA RECEBER DADOS DA SERIAL E INICIAR EMISSOR IR
  if (Serial.available()) {
    char tecla = Serial.read();

    switch (tecla) {
      case 'a':
        emissorIR.sendRaw(teclaDesligar, sizeof(teclaDesligar) / sizeof(teclaDesligar[0]), frequencia);
        Serial.println("Enviando Desligar clonada");
        delay(tempoTecla);
        break;

      case 'b':
        emissorIR.sendRaw(teclaLigar, sizeof(teclaLigar) / sizeof(teclaLigar[0]), frequencia);
        Serial.println("Enviando Ligar clonada");
        delay(tempoTecla);
        break;

      case 'c':
        emissorIR.sendRaw(teclaC, sizeof(teclaC) / sizeof(teclaC[0]), frequencia);
        Serial.println("Enviando Tecla C clonada");
        delay(tempoTecla);
        break;

      case 'd':
        emissorIR.sendRaw(teclaD, sizeof(teclaD) / sizeof(teclaD[0]), frequencia);
        Serial.println("Enviando Tecla D clonada");
        delay(tempoTecla);
        break;
    }
  }
}
