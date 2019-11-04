/*
 * Communication between 4 ESPs with ESP central without Router
 * This project was done on July 7, 2018, by Engineer Jemerson Marques 
 * the code was edited and adapted for this project. 
 * You can find more information on our website:
 * http://www.fvml.com.br/2018/12/comunicacao-entre-4-esps-com-central.html?showComment=1562335021956#c5759332917663913896 
 */

//-- Libraries Included --------------------------------------------------------------
  #include <ESP8266WiFi.h>
//------------------------------------------------------------------------------------
  // Define I/O Pins
  #define     LED0      2           // WIFI Module LED
  #define     LED1      D0          // Connectivity With Client
  #define     LED2      D2          // Connectivity With Client #1
  #define     LED3      D3          // Connectivity With Client #2
  #define     LED4      D5          // Connectivity With Client #3
  #define     BUTTON    D1          // Connectivity ReInitiate Button
//------------------------------------------------------------------------------------
  // Authentication Variables
  char*       ESPssid;              // SERVER WIFI NAME
  char*       ESPpassword;          // SERVER PASSWORD
  String      Message;              // VARIABLE RECEIVE DATA FROM OTHER CLIENTS
//------------------------------------------------------------------------------------
  #define     MAXSC     6           // MAXIMUM NUMBER OF CLIENTS
  
  WiFiServer  ESPServer(9001);      // THE SERVER AND THE PORT NUMBER
  WiFiClient  ESPClient[MAXSC];     // THE SERVER CLIENTS (Devices)
//====================================================================================

  void setup()
  {
    // Setting The Serial Port
    Serial.begin(115200);           // Computer Communication
    
    // Setting The Mode Of Pins
    pinMode(LED0, OUTPUT);          // WIFI OnBoard LED Light
    pinMode(LED1, OUTPUT);          // Indicator For Client  Connectivity
    pinMode(LED2, OUTPUT);          // Indicator For Client  Connectivity
    pinMode(LED3, OUTPUT);          // Indicator For Client  Connectivity
    pinMode(LED4, OUTPUT);          // Indicator For Client  Connectivity
    pinMode(BUTTON, INPUT_PULLUP);  // Initiate Connectivity
    
    // Print Message Of I/O Setting Progress
    Serial.println();
    Serial.println("I/O Pins Modes Set .... Done");

    // Setting Up A Wifi Access Point
    SetWifi("FVMLearning", "");
  }

//====================================================================================
  
  void loop()
  {    
    AvailableClients();     // Checking For Available Clients
    AvailableMessage();     // Checking For Available Client Messages
  }

//====================================================================================
  
  void SetWifi(char* Name, char* Password)
  {
    // Stop Any Previous WIFI
    WiFi.disconnect();

    // Setting The Wifi Mode
    WiFi.mode(WIFI_AP_STA);
    Serial.println("WIFI Mode : AccessPoint Station");
    
    // Setting The AccessPoint Name & Password
    ESPssid      = Name;
    ESPpassword  = Password;
    
    // Starting The Access Point
    WiFi.softAP(ESPssid, ESPpassword);
    Serial.println("WIFI < " + String(ESPssid) + " > ... Started");
    
    // Wait For Few Seconds
    delay(500);
    
    // Getting Server IP
    IPAddress IP = WiFi.softAPIP();
    
    // Printing The Server IP Address
    Serial.print("AccessPoint IP : ");
    Serial.println(IP);

    // Printing MAC Address
    Serial.print("AccessPoint MC : ");
    Serial.println(String(WiFi.softAPmacAddress()));

    // Starting Server
    ESPServer.begin();
    ESPServer.setNoDelay(true);
    Serial.println("Server Started");
  }

//====================================================================================

  void AvailableClients()
  {   
    if (ESPServer.hasClient())
    {
      // Read LED0 Switch To Low If High.
      if(digitalRead(LED0) == HIGH) digitalWrite(LED0, LOW);
      
      // Light Up LED1
      digitalWrite(LED1, HIGH);
      
      for(uint8_t i = 0; i < MAXSC; i++)
      {
        //find free/disconnected spot
        if (!ESPClient[i] || !ESPClient[i].connected())
        {
          // Checks If Previously The Client Is Taken
          if(ESPClient[i])
          {
            ESPClient[i].stop();
          }

          // Checks If Clients Connected To The Server
          if(ESPClient[i] = ESPServer.available())
          {
            Serial.println("New Client: " + String(i+1));
          }

          // Continue Scanning
          continue;
        }
      }
      
      //no free/disconnected spot so reject
      WiFiClient ESPClient = ESPServer.available();
      ESPClient.stop();
    }
    else
    {
      // This LED Blinks If No Clients Where Available
      digitalWrite(LED0, HIGH);
      delay(250);
      digitalWrite(LED0, LOW);
      delay(250);
    }
  }

//====================================================================================

  void AvailableMessage()
  {
    //check clients for data
    for(uint8_t i = 0; i < MAXSC; i++)
    {
      if (ESPClient[i] && ESPClient[i].connected() && ESPClient[i].available())
      {
          while(ESPClient[i].available())
          {
            Message = ESPClient[i].readStringUntil('\r');
            ESPClient[i].flush();         
            ClientNumber();
            Serial.println("Client No " + String(i+1) + " - " + Message); 
          }
        }
      }
    }
    
 // =================================================================================
   
    void  ClientNumber(){
     
      if (Message == "<Cliente 01-1>"){             // Check clent number, 01 = client 1, and after trace, status 1 = on, 0 = off
             digitalWrite(LED2, HIGH);
      }
       if(Message == "<Cliente 01-0>"){
              digitalWrite(LED2, LOW);
            }
       if (Message == "<Cliente 02-1>"){
              digitalWrite(LED3, HIGH);
      }
       if(Message == "<Cliente 02-0>"){
              digitalWrite(LED3, LOW);
            }
        if (Message == "<Cliente 03-1>"){
             digitalWrite(LED4, HIGH);
      }
       if(Message == "<Cliente 03-0>"){
              digitalWrite(LED4, LOW);
            }  
      }
  

//====================================================================================
