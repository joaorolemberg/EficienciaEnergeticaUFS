/*
 * Communication between 4 ESPs with ESP central without Router
 * This project was done on July 7, 2018, by Engineer Jemerson Marques 
 * the code was edited and adapted for this project. 
 * You can find more information on our website:
 * http://www.fvml.com.br/2018/12/comunicacao-entre-4-esps-com-central.html?showComment=1562335021956#c5759332917663913896 
 */

//------------------------------------------------------------------------------------
// Libraries Needed For This Project
//------------------------------------------------------------------------------------
  #include <EEPROM.h>         // To Be Able To Store & Read Data Between Power Off
  #include <ESP8266WiFi.h>    // The Basic Function Of The ESP NOD MCU
//------------------------------------------------------------------------------------
// Defining I/O Pins
//------------------------------------------------------------------------------------
  #define       LED0      2         // WIFI Module LED
  #define       LED1      D0        // Indicate Connectivity With Client #1
  #define       BUTTON    D1        // Connectivity ReInitiate Button
//------------------------------------------------------------------------------------
// BUTTON Variables
//------------------------------------------------------------------------------------
  int           ButtonState;
  int           LastButtonState   = LOW;
  int           LastDebounceTime  = 0;
  int           DebounceDelay     = 50;
  const String  ClientType       = "Cliente 01";
//------------------------------------------------------------------------------------
// LED Delay Variables
//------------------------------------------------------------------------------------
  int           LEDState          = LOW;
  unsigned long CurrMillis        = 0;
  unsigned long PrevMillis        = 0;
  unsigned long Interval          = 1000;
//------------------------------------------------------------------------------------
// WIFI Authentication Variables
//------------------------------------------------------------------------------------
/* This Client Is Going To Connect To A WIFI Server Access Point
 * So You Have To Specify Server WIFI SSID & Password In The Code Not Here
 * Please See The Function Below Name (WiFi.Begin)
 * If WIFI dont need Any password Then WiFi.begin("SSIDNAME")
 * If WIFI needs a Password Then WiFi.begin("SSIDNAME", "PASSWORD")
 */
  char*         ESPssid;            // Wifi Name
  char*         ESPpassword;        // Wifi Password
//------------------------------------------------------------------------------------
// WIFI Module Role & Port
//------------------------------------------------------------------------------------
/* This WIFI Module Code Works As A Client
 * That Will Connect To A Server WIFI Modul With (IP ADDress 192.168.4.1)
 */
  int             ESPServerPort  = 9001;
  IPAddress       ESPServer(192,168,4,1);
  WiFiClient      ESPClient;
//====================================================================================

  void setup() 
  {
    // Setting The Serial Port ----------------------------------------------
    Serial.begin(115200);           // Computer Communication
    
    // Setting The Mode Of Pins ---------------------------------------------
    pinMode(LED0, OUTPUT);          // WIFI OnBoard LED Light
    pinMode(LED1, OUTPUT);          // Indicator For Client #1 Connectivity
    pinMode(BUTTON, INPUT_PULLUP);  // Initiate Connectivity
    digitalWrite(LED0, !LOW);       // Turn WiFi LED Off
    
    // Print Message Of I/O Setting Progress --------------------------------
    Serial.println("\nI/O Pins Modes Set .... Done");

    // Starting To Connect --------------------------------------------------
    if(WiFi.status() == WL_CONNECTED)
    {
      WiFi.disconnect();
      WiFi.mode(WIFI_OFF);
      delay(50);
    }

    /* in this part it should load the ssid and password 
     * from eeprom they try to connect using them */
    
    WiFi.mode(WIFI_STA);                // To Avoid Broadcasting An SSID
    WiFi.begin("FVMLearning", "");      // The SSID That We Want To Connect To

    // Printing Message For User That Connetion Is On Process ---------------
    Serial.println("!--- Connecting To " + WiFi.SSID() + " ---!");

    // WiFi Connectivity ----------------------------------------------------
    CheckWiFiConnectivity();        // Checking For Connection

    // Stop Blinking To Indicate Connected ----------------------------------
    digitalWrite(LED0, !HIGH);
    Serial.println("!-- Client Device Connected --!");

    // Printing IP Address --------------------------------------------------
    Serial.println("Connected To      : " + String(WiFi.SSID()));
    Serial.println("Signal Strenght   : " + String(WiFi.RSSI()) + " dBm");
    Serial.print  ("Server IP Address : ");
    Serial.println(ESPServer);
    Serial.print  ("Server Port Num   : ");
    Serial.println(ESPServerPort);
    // Printing MAC Address
    Serial.print  ("Device MC Address : ");
    Serial.println(String(WiFi.macAddress()));
    // Printing IP Address
    Serial.print  ("Device IP Address : ");
    Serial.println(WiFi.localIP());
    
    // Conecting The Device As A Client -------------------------------------
    ESPRequest();
  }

//====================================================================================
  
  void loop()
  {

    ReadButton();
  
  }

//====================================================================================

  void ReadButton()
  {
    // Reading The Button
    int reading = digitalRead(BUTTON);

    // If It Doest Match The Previous State
    if(reading != LastButtonState)
    {
      LastDebounceTime = millis();
    }

    // To Iliminate Debounce
    if((millis() - LastDebounceTime) > DebounceDelay)
    {
      if(reading != ButtonState)
      {
        ButtonState = reading;
        
        if(ButtonState == LOW)
        {
          LEDState    = !digitalRead(LED1);
          digitalWrite(LED1, LEDState);
          Serial.println   ("<" + ClientType + "-" + LEDState + ">");
          ESPClient.println("<" + ClientType + "-" + LEDState + ">");
          ESPClient.flush();
        }
      }
    }

    // Last Button State Concidered
    LastButtonState = reading;
  }

//====================================================================================

  void CheckWiFiConnectivity()
  {
    while(WiFi.status() != WL_CONNECTED)
    {
      for(int i=0; i < 10; i++)
      {
        digitalWrite(LED0, !HIGH);
        delay(250);
        digitalWrite(LED0, !LOW);
        delay(250);
        Serial.print(".");
      }
      Serial.println("");
    }
  }

  void ESPRequest()
  {
    // First Make Sure You Got Disconnected
    ESPClient.stop();

    // If Sucessfully Connected Send Connection Message
    if(ESPClient.connect(ESPServer, ESPServerPort))
    {
      Serial.println    ("<" + ClientType + "- CONNECTED>");
      ESPClient.println ("<" + ClientType + "- CONNECTED>");
    }
  }

//====================================================================================
