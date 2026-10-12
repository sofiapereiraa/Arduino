#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#define BTN_RED 2
#define BTN_YELLOW 3
#define BTN_GREEN 4
#define LED_RED 8
#define LED_YELLOW 9
#define LED_GREEN 10

Adafruit_SSD1306 OLED(128, 64, &Wire, -1);

void setup() {
  Serial.begin(9600);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  pinMode(BTN_RED, INPUT_PULLUP);
  pinMode(BTN_YELLOW, INPUT_PULLUP);
  pinMode(BTN_GREEN, INPUT_PULLUP);

  if (OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    OLED.clearDisplay();
    OLED.setTextColor(1);
    OLED.setTextSize(2);
    OLED.setCursor(30, 4);
    OLED.println("APERTE");
    OLED.setCursor(40, 24);
    OLED.println("PARA");
    OLED.setCursor(34, 44);
    OLED.print("JOGAR !");
    OLED.display();
  }
}

void loop() {
  if (digitalRead(BTN_RED) == LOW) {
    InicarJogo();

    while (digitalRead(BTN_RED) == LOW) {
    }

    delay(200);
  }
}

bool RODADA1() {
  OLED.clearDisplay();
  OLED.setTextColor(SSD1306_WHITE);
  OLED.setTextSize(2);
  OLED.setCursor(28, 8);
  OLED.println("RODADA");
  OLED.setCursor(52, 26);
  OLED.println("1");
  OLED.setCursor(40, 44);
  OLED.println("!!!");
  OLED.display();
  delay(1000);
  int sequencia[] = {
    LED_GREEN, LED_GREEN, LED_RED, LED_YELLOW
  };

  int posicao = 0;
  int botao = -1;

  for (int i = 0; i < 4; i++) {
    digitalWrite(sequencia[i], HIGH);
    delay(1000);
    digitalWrite(sequencia[i], LOW);
    delay(300);
  }

  while (posicao < 4) {
    botao = -1;

    if (digitalRead(BTN_RED) == LOW)
      botao = LED_RED;
    else if (digitalRead(BTN_YELLOW) == LOW)
      botao = LED_YELLOW;
    else if (digitalRead(BTN_GREEN) == LOW)
      botao = LED_GREEN;

    if (botao != -1) {
      if (botao == sequencia[posicao])
        posicao++;
      else {
        OLED.clearDisplay();
        OLED.setCursor(0, 25);
        OLED.setTextSize(2);
        OLED.setTextColor(1);
        OLED.println("GAME OVER");
        OLED.display();
        return false;
      }

      while (digitalRead(BTN_RED) == LOW || digitalRead(BTN_YELLOW) == LOW || digitalRead(BTN_GREEN) == LOW) {
      }

      delay(200);
    }
  }

  OLED.clearDisplay();
  OLED.setCursor(0, 25);
  OLED.setTextSize(2);
  OLED.setTextColor(1);
  OLED.println("ACERTOU!");
  OLED.display();
  delay(1500);
  return true;
}

bool RODADA2() {
  OLED.clearDisplay();
  OLED.setTextColor(1);
  OLED.setTextSize(2);
  OLED.setCursor(28, 8);
  OLED.println("RODADA");
  OLED.setCursor(52, 26);
  OLED.println("2");
  OLED.setCursor(40, 44);
  OLED.println("!!!");
  OLED.display();
  delay(1000);

  int sequencia[] = {
    LED_YELLOW, LED_GREEN, LED_RED,
    LED_RED, LED_GREEN, LED_YELLOW
  };

  int posicao = 0;
  int botao = -1;

  for (int i = 0; i < 6; i++) {
    digitalWrite(sequencia[i], HIGH);
    delay(1000);
    digitalWrite(sequencia[i], LOW);
    delay(300);
  }

  while (posicao < 6) {
    botao = -1;

    if (digitalRead(BTN_RED) == LOW)
      botao = LED_RED;
    else if (digitalRead(BTN_YELLOW) == LOW)
      botao = LED_YELLOW;
    else if (digitalRead(BTN_GREEN) == LOW)
      botao = LED_GREEN;

    if (botao != -1) {
      if (botao == sequencia[posicao])
        posicao++;
      else {
        OLED.clearDisplay();
        OLED.setCursor(0, 25);
        OLED.setTextSize(2);
        OLED.setTextColor(1);
        OLED.println("GAME OVER");
        OLED.display();
        return false;
      }

      while (digitalRead(BTN_RED) == LOW || digitalRead(BTN_YELLOW) == LOW || digitalRead(BTN_GREEN) == LOW) {
      }

      delay(200);
    }
  }

  OLED.clearDisplay();
  OLED.setCursor(0, 25);
  OLED.setTextSize(2);
  OLED.setTextColor(1);
  OLED.println("ACERTOU!");
  OLED.display();
  delay(1500);
  return true;
}
bool RODADA3() {

  OLED.clearDisplay();
  OLED.setTextColor(1);
  OLED.setTextSize(2);

  OLED.setCursor(28, 8);
  OLED.println("RODADA");

  OLED.setCursor(52, 26);
  OLED.println("3");

  OLED.setCursor(40, 44);
  OLED.println("!!!");

  OLED.display();
  delay(1000);

  int sequencia[] = {
    LED_RED, LED_GREEN, LED_RED, LED_YELLOW,
    LED_RED, LED_GREEN, LED_YELLOW, LED_GREEN
  };

  int posicao = 0;
  int botao = -1;

  for (int i = 0; i < 8; i++) {
    digitalWrite(sequencia[i], HIGH);
    delay(1000);
    digitalWrite(sequencia[i], LOW);
    delay(300);
  }

  while (posicao < 8) {
    botao = -1;

    if (digitalRead(BTN_RED) == LOW)
      botao = LED_RED;
    else if (digitalRead(BTN_YELLOW) == LOW)
      botao = LED_YELLOW;
    else if (digitalRead(BTN_GREEN) == LOW)
      botao = LED_GREEN;

    if (botao != -1) {
      if (botao == sequencia[posicao])
        posicao++;
      else {
        OLED.clearDisplay();
        OLED.setCursor(0, 25);
        OLED.setTextSize(2);
        OLED.setTextColor(1);
        OLED.println("GAME OVER");
        OLED.display();
        return false;
      }

      while (digitalRead(BTN_RED) == LOW || digitalRead(BTN_YELLOW) == LOW || digitalRead(BTN_GREEN) == LOW) {
      }

      delay(200);
    }
  }
  OLED.clearDisplay();
  OLED.setTextSize(2);
  OLED.setTextColor(1);
  OLED.setCursor(36, 8);
  OLED.println("VOCE");
  OLED.setCursor(16, 26);
  OLED.println("VENCEU");
  OLED.setCursor(40, 44);
  OLED.println("!!!");
  OLED.display();
  delay(2000);
  return true;
}

void InicarJogo() {
  OLED.clearDisplay();
  OLED.setTextColor(1);
  OLED.setTextSize(2);

  OLED.setCursor(30, 4);
  OLED.println("3 ! ");
  OLED.display();
  digitalWrite(LED_RED, HIGH);
  delay(1000);
  digitalWrite(LED_RED, LOW);

  OLED.clearDisplay();
  OLED.setCursor(40, 24);
  OLED.println("2 !");
  OLED.display();
  digitalWrite(LED_YELLOW, HIGH);
  delay(1000);
  digitalWrite(LED_YELLOW, LOW);

  OLED.clearDisplay();
  OLED.setCursor(50, 34);
  OLED.println("1 !");
  OLED.display();
  digitalWrite(LED_GREEN, HIGH);
  delay(1000);
  digitalWrite(LED_GREEN, LOW);

  OLED.clearDisplay();
  OLED.setCursor(20, 24);
  OLED.println("VAIIIII !");
  OLED.display();
  delay(1000);

  if (RODADA1()) {
    if (RODADA2()) {
      RODADA3();
    }
  }
}