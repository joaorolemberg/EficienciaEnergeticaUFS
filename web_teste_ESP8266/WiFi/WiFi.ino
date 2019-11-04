/*
   Copyright (c) 2015, Majenko Technologies
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

 * * Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

 * * Redistributions in binary form must reproduce the above copyright notice, this
     list of conditions and the following disclaimer in the documentation and/or
     other materials provided with the distribution.

 * * Neither the name of Majenko Technologies nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
   ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "ESP32TESTE"
#define APPSK  "BERGBERG"
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/


String teste="<html> <head> <meta http-equiv=”refresh” content=”1″> </head> <body> <H1> <center> TESTE ESP32 HTML </center> </H1> <H2> <center> TEMPO SEM DETECTAR </center> </H2> </body> </html>";
String html="<html> <head> </head> <body> <H1> <center> TESTE ESP32 HTML </center> </H1> <H2> <center> TEMPO SEM DETECTAR </center> </H2> </body> </html>";

int segundos=0;
int minutos=0;
boolean detected=false;
boolean desligar=false; 
String pagina;



String html1="<html> <head> </head> <body> <H1> <center> TESTE ESP32 HTML </center> </H1> <H2> <center> TEMPO SEM DETECTAR: ";
String html2="</center> </H2> </body> </html>";

String htmlFuncional(){
  if(digitalRead(0)==HIGH){
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
 
  if(minutos>=15 && minutos<=16){
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
  
  return tempoHtml;
}

void handleRoot() {
  server.send(200, "text/html", pagina);
  digitalWrite(2,HIGH);
  delay(500);
  digitalWrite(2,LOW);
  delay(500);


}
void setup() {
  delay(1000);
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  pinMode(0,INPUT);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  
  if(digitalRead(0)==HIGH){
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
 
  if(minutos>=15 && minutos<=16){
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
  pagina=tempoHtml;
  server.handleClient();
}
