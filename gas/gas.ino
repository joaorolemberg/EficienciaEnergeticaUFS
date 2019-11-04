int sensor = A0;
int nivel_sensor = 560;
int total=0;
int contador=0;
void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);

}

void loop()
{
  int valor_analogico = analogRead(sensor);
  //contador++;
  //total=total+valor_analogico;
  
  Serial.print(" Pino A0 : ");
  Serial.println(valor_analogico);
  //Serial.print(" Media: ");
  //Serial.println(total/contador);
  delay(2000);
}
