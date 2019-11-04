int porta_pir = 8;

 
void setup()
{
  Serial.begin(9600);
  pinMode(porta_pir, INPUT); 
}

void loop()
{
    Serial.println(digitalRead(porta_pir)); 
    delay(500);  
}
