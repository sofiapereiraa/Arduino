int SOM = 11;
int LED = 13;

int BOTAO_DO = 9;
int BOTAO_RE = 8;
int BOTAO_MI = 6;
int BOTAO_FA = 5;
int BOTAO_SOL = 4;
int BOTAO_LA = 3;
int BOTAO_SI = 2;

#define NOTA_DO 523
#define NOTA_RE 587
#define NOTA_MI 659
#define NOTA_FA 698
#define NOTA_SOL 784
#define NOTA_LA 880
#define NOTA_SI 988

int MUSICAL = 10;

void setup() {

  for (int i = 2; i <= 10; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(SOM, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {

  if (digitalRead(MUSICAL) == LOW) {

    tone(SOM, NOTA_MI, 300);
    delay(350);

    tone(SOM, NOTA_MI, 300);
    delay(350);

    tone(SOM, NOTA_FA, 300);
    delay(350);

    tone(SOM, NOTA_SOL, 300);
    delay(350);

    tone(SOM, NOTA_SOL, 300);
    delay(350);

    tone(SOM, NOTA_FA, 300);
    delay(350);

    tone(SOM, NOTA_MI, 300);
    delay(350);

    tone(SOM, NOTA_RE, 300);
    delay(350);

    tone(SOM, NOTA_DO, 300);
    delay(350);

    tone(SOM, NOTA_DO, 300);
    delay(350);

    tone(SOM, NOTA_RE, 300);
    delay(350);

    tone(SOM, NOTA_MI, 300);
    delay(350);

    tone(SOM, NOTA_MI, 500);
    delay(550);

    tone(SOM, NOTA_RE, 150);
    delay(200);

    tone(SOM, NOTA_RE, 600);
    delay(650);

    tone(SOM, NOTA_DO, 300);
    delay(350);

    tone(SOM, NOTA_DO, 300);
    delay(350);

    tone(SOM, NOTA_RE, 300);
    delay(350);

    tone(SOM, NOTA_MI, 300);
    delay(350);

    tone(SOM, NOTA_MI, 500);
    delay(550);

    tone(SOM, NOTA_RE, 150);
    delay(200);

    tone(SOM, NOTA_RE, 600);
    delay(650);

  } else {
    noTone(SOM);
  }

  while (digitalRead(BOTAO_DO) == LOW) {
    tone(SOM, NOTA_DO, 300);
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);

  while (digitalRead(BOTAO_RE) == LOW) {
    tone(SOM, NOTA_RE, 300);
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);

  while (digitalRead(BOTAO_MI) == LOW) {
    tone(SOM, NOTA_MI, 300);
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);

  while (digitalRead(BOTAO_FA) == LOW) {
    tone(SOM, NOTA_FA, 300);
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);

  while (digitalRead(BOTAO_SOL) == LOW) {
    tone(SOM, NOTA_SOL, 300);
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);

  while (digitalRead(BOTAO_LA) == LOW) {
    tone(SOM, NOTA_LA, 300);
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);

  while (digitalRead(BOTAO_SI) == LOW) {
    tone(SOM, NOTA_SI, 300);
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);
}
