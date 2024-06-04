#include <WiFi.h>
#include <WiFiClient.h>
//biblioteca para executar um serviço de HTTP, para publicar os arquivos html
#include <WebServer.h>
#include <string.h>

//instancia
WebServer server(80);

//asteristico é um ponteiro da memória
const char *ssid = "Wifi-MAMR";
const char *password = "87654321";

IPAddress local_IP(192,168,0,80);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

const int pinLed1 = 2; 
const int pinLed2 = 4; 
const int pinLed3 = 5; 
const int pinLed4 = 18; 
const int pinLed5 = 19; 
const int pinLed6 = 21; 

int tempoAmarelo = 5000;
int tempoVerde = 20000;
int tempoVermelho = 25000;


void setup() {
  Serial.begin(115200);
  //configuração do Acess Point que irá ser fornecido pelo esp32
  Serial.print("Configurando AP...");
  Serial.println(WiFi.softAPConfig(local_IP,gateway,subnet)?"OK":"Erro");
  Serial.print("Iniciando o WiFi....");
  Serial.println(WiFi.softAP(ssid,password));
  Serial.print("Endereço IP");
  Serial.println(WiFi.softAPIP());

  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);
  pinMode(pinLed6, OUTPUT);
  Serial.begin(115200);
}


void loop() {
  acendeLuz();
}
 void acendeLuz(){
  //led1
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed4, LOW);
  digitalWrite(pinLed6, HIGH);
  delay(tempoVerde);
  digitalWrite(pinLed6, LOW);
  digitalWrite(pinLed5, HIGH);
  delay(tempoAmarelo);
  digitalWrite(pinLed5, LOW);
  digitalWrite(pinLed1, LOW);
 
  //led2
  digitalWrite(pinLed4, HIGH);
  digitalWrite(pinLed3, HIGH);
  delay(tempoVerde);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed2, HIGH);
  delay(tempoAmarelo);
  digitalWrite(pinLed2, LOW);
 }


