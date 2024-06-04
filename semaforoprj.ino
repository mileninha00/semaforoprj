const int pinLed1 = 2; 
const int pinLed2 = 4; 
const int pinLed3 = 5; 
const int pinLed4 = 18; 
const int pinLed5 = 19; 
const int pinLed6 = 21; 

int tempoAmarelo = 5000;
int tempoVerde = 30000;
int tempoVermelho = 35000;


void setup() {
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


