#include "dht.h" //INCLUSÃO DE BIBLIOTECA
 
const int pinoDHT11 = A2; //PINO ANALÓGICO UTILIZADO PELO DHT11

dht DHT;

void setup() {
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  //Lê as informações do sensor
  DHT.read11(pinoDHT11);

  int x = DHT.temperature;
  int y = DHT.humidity;

  //Se possível criar lógica para acender luz e 
  //fazer barulho pelo component buzzer
  /*
  
  
  */
  Serial.print(x);
  Serial.print(';');
  Serial.print(y);
  Serial.println('-');
  delay(2000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR
}
