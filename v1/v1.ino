#include "dht.h" //INCLUSÃO DE BIBLIOTECA
 
const int pinoDHT11 = A2; //PINO ANALÓGICO UTILIZADO PELO DHT11
int frequencia;

dht DHT;

char* musica[] = {"La","Re","Mi","Re","Sol","Re","Sol","Sol#", "Fim"}; 
int duracao[] = {300, 300, 200, 500, 200, 300, 200, 200};

void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  delay(2000);
}

void loop() {
  //Lê as informações do sensor
  DHT.read11(pinoDHT11);

  int x = DHT.temperature;
  int y = DHT.humidity;

  //Se possível criar lógica para acender luz e 
  //fazer barulho pelo component buzzer
  
  if(x > 40){
  tocar(musica,duracao);
  }else if(y > 70){
  tocar(musica,duracao); 
  }else{
  noTone(9);
  }
  
  Serial.print(x);
  Serial.print(';');
  Serial.print(y);
  Serial.println('-');
  delay(2000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR
}

void tocar(char* mus[], int tempo[]){
  int tom = 0;
  for(int i = 0; mus[i]!="Fim";i++){
    if(mus[i] == "Do") tom = 262;
    if(mus[i] == "Re") tom = 294;
    if(mus[i] == "Mi") tom = 330;
    if(mus[i] == "Fa") tom = 349;
    if(mus[i] == "Sol") tom = 392;
    if(mus[i] == "La") tom = 440;
    if(mus[i] == "Si") tom = 494;
    if(mus[i] == "Do#") tom = 528;
    if(mus[i] == "Re#") tom = 622;
    if(mus[i] == "Fa#") tom = 370;
    if(mus[i] == "Sol#") tom = 415;
    if(mus[i] == "La#") tom = 466;
    if(mus[i] == "Pausa") tom = 0;
    tone(9, tom, tempo[i]);
    delay(tempo[i]);
  }
}
