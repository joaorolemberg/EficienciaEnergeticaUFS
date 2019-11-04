#include <ESP8266WiFi.h> 
#include <PubSubClient.h>

#define GPIO2 2       //GP2 ESP-01
#define GPIO0 0       //GP0 ESP-01

//WiFi
const char* SSID = "Rolemberg";                // SSID / nome da rede WiFi que deseja se conectar
const char* PASSWORD = "SouzaRolemberg";       // Senha da rede WiFi que deseja se conectar
WiFiClient wifiClient;                        
 
//MQTT Server
const char* BROKER_MQTT = "192.168.0.109";    //URL ou IP do broker MQTT que se deseja utilizar
int BROKER_PORT = 1883;                       // Porta do Broker MQTT

#define ID_MQTT  "ESP"                        //Informe um ID unico e seu. Caso sejam usados IDs repetidos a ultima conexão irá sobrepor a anterior. 
#define TOPIC_SUBSCRIBE "testeReceber"        //Informe um Tópico único. Caso sejam usados tópicos em duplicidade, o último irá eliminar o anterior.
PubSubClient MQTT(wifiClient);                // Instancia o Cliente MQTT passando o objeto espClient

//Declaração das Funções
void mantemConexoes();  //Garante que as conexoes com WiFi e MQTT Broker se mantenham ativas
void conectaWiFi();     //Faz conexão com WiFi
void conectaMQTT();     //Faz conexão com Broker MQTT
void recebePacote(char* topic, byte* payload, unsigned int length);


void setup() {
  pinMode(GPIO2, OUTPUT);
  //pinMode(GPIO0, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);
  Serial.begin(115200);

  conectaWiFi();
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);  
  MQTT.setCallback(recebePacote); 
}

void loop() {
  mantemConexoes();
  MQTT.loop();
}

void mantemConexoes() {
    if (!MQTT.connected()) {
       conectaMQTT(); 
    }
    
    conectaWiFi(); //se não há conexão com o WiFI, a conexão é refeita
}

void conectaWiFi() {
  if (WiFi.status() == WL_CONNECTED) {
     return;
  }

  WiFi.begin(SSID, PASSWORD); // Conecta na rede WI-FI 
   
  while (WiFi.status() != WL_CONNECTED) {
      delay(100); // Aguardando conexão
  }
  
  //Conectado com sucesso 
  digitalWrite(GPIO2,HIGH);
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
}

void conectaMQTT() { 
    while (!MQTT.connected()) {
        //Conectando ao Broker MQTT
        if (MQTT.connect(ID_MQTT)) {
            // Conectado ao Broker com sucesso!
            
            // TOPICOS
            MQTT.subscribe(TOPIC_SUBSCRIBE);

            // Pisca led para visualização de conexão
            digitalWrite(GPIO2, LOW);
            digitalWrite(LED_BUILTIN, LOW);
            delay(500);
            digitalWrite(GPIO2, HIGH);
            digitalWrite(LED_BUILTIN, HIGH);
            delay(500);
            digitalWrite(GPIO2, LOW);
            digitalWrite(LED_BUILTIN, LOW);
        }else {
            // Não foi possivel se conectar ao broker.
            // Nova tentativa de conexao em 10 segundos
            delay(10000);
        }
    }
}

void recebePacote(char* topic, byte* payload, unsigned int length){
    String msg;
    
    //obtem a string do payload recebido
    for(int i = 0; i < length; i++) 
    {
       char c = (char)payload[i];
       msg += c;
    }
    // Logica de mensagem recebida
    
    if (msg == "0") {
       digitalWrite(GPIO2, LOW);
    }

    if (msg == "1") {
       digitalWrite(GPIO2, HIGH);
    }
}
