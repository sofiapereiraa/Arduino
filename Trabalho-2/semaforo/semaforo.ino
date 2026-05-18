#define led_vermelho 8
#define led_amarelo  9
#define led_verde 10



void setup() {
  pinMode (8, OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (10, OUTPUT);

}

void fechado (int temp) {    
  digitalWrite(8,HIGH);
  digitalWrite (9,LOW);
  digitalWrite (10,LOW);
  delay(temp);
}

void aberto (int temp) {
  digitalWrite(8,LOW);
  digitalWrite (9,LOW);
  digitalWrite (10,HIGH);
  delay(temp);
}

void cuidado (int temp) {
  digitalWrite(8,LOW);
  digitalWrite (9,HIGH);
  digitalWrite (10,LOW);
  delay(temp);
}


void loop() {
 fechado (6000);
 aberto (8000);
 cuidado (4000);

}
