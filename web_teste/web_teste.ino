/*
  WiFiAccessPoint.ino creates a WiFi access point and provides a web server on it.

  Steps:
  1. Connect to the access point "yourAp"
  2. Point your web browser to http://192.168.4.1/H to turn the LED on or http://192.168.4.1/L to turn it off
     OR
     Run raw TCP "GET /H" and "GET /L" on PuTTY terminal with 192.168.4.1 as IP address and 80 as port

  Created for arduino-esp32 on 04 July, 2018
  by Elochukwu Ifediora (fedy0)
*/

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

// Set these to your desired credentials.
const char *ssid = "ESP32TESTE";
const char *password = "bergberg";

WiFiServer server(80);

String teste="<html> <head> <meta http-equiv=”refresh” content=”1″> </head> <body> <H1> <center> TESTE ESP32 HTML </center> </H1> <H2> <center> TEMPO SEM DETECTAR </center> </H2> </body> </html>";

String html="<html> <head> </head> <body> <H1> <center> TESTE ESP32 HTML </center> </H1> <H2> <center> TEMPO SEM DETECTAR </center> </H2> </body> </html>";
String html1="<html> <head> </head> <body> <H1> <center> TESTE ESP32 HTML </center> </H1> <H2> <center> TEMPO SEM DETECTAR: ";
String html2="</center> </H2> </body> </html>";

int segundos=0;
int minutos=0;
boolean detected=false;
boolean desligar=false;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);
  
  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
  
}

void loop() {
  WiFiClient client = server.available();
  
  if(digitalRead(4)==HIGH){
    digitalWrite(2,HIGH);
    detected=true;
    segundos=0;
    minutos=0;
   }else{
      digitalWrite(2,LOW);
      detected=false;
   }
  delay(1000);
  segundos+=1;
  if (segundos==60){
    minutos+=1;
    segundos =0;   
  }
  
  if(minutos==15){
    desligar=true;
   }else{
    desligar=false;
    }
  String tempo;
  tempo+=minutos;
  tempo+=":";
  tempo+=segundos;
  String tempoHtml=html1;
  tempoHtml+=tempo;
  tempoHtml+=html2;
  
  Serial.println(tempo);
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            
            
            Serial.println(tempo);

            // the content of the HTTP response follows the header:
            //client.print(teste);
            client.print(tempoHtml);
           
            if(detected){
              client.print("DETECTADO");
             }
    
             if (desligar){
              client.print("TEMPO ESGOTADO, LUZES DESLIGADAS");
              }
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(2, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(2, LOW);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
