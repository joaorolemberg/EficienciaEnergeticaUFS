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

unsigned int teclaA[] = {};
unsigned int teclaB[] = {};
unsigned int teclaC[] = {};
unsigned int teclaD[] = {/*COPIE_OS_DADOS_DENTRO_DAS_CHAVES_DO_MONITOR_SERIAL_E_COLE_AQUI*/};

void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);

  // INICIANDO RECEPTOR IR
  receptorIR.enableIRIn();
  Serial.print("Setup Concluído");

}

void loop() {
  

  while (1) {

    decode_results  results;

    if (receptorIR.decode(&results)) {
      ircode   (&results);
      encoding (&results);
      dumpInfo (&results);
      dumpRaw  (&results);
      dumpCode (&results);
      receptorIR.resume();
    }
  }
  /*
  // BLOCO PARA RECEBER DADOS DA SERIAL E INICIAR EMISSOR IR
  if (Serial.available()) {
    char tecla = Serial.read();

    switch (tecla) {
      case 'a':
        emissorIR.sendRaw(teclaA, sizeof(teclaA) / sizeof(teclaA[0]), frequencia);
        Serial.println("Enviando Tecla A clonada");
        delay(tempoTecla);
        break;

      case 'b':
        emissorIR.sendRaw(teclaB, sizeof(teclaB) / sizeof(teclaB[0]), frequencia);
        Serial.println("Enviando Tecla B clonada");
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
  }*/
}
