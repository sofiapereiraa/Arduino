int ledRed = 2;
int ledGreen = 3;
int ledBlue = 4;
#define btn 5
int estado = 0;
int leitura = 0;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {

  leitura = digitalRead(btn);

  if (leitura == 0) {
    estado++;

    if (estado > 3) {
      estado = 0;
    }

    while (digitalRead(btn) == 0) {
      
    }
  }

  if (estado == 1) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledBlue, LOW);
  }

  if (estado == 2) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledBlue, LOW);
  }

  if (estado == 3) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledBlue, HIGH);
  }

  if (estado == 0) {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledBlue, LOW);
  }

}