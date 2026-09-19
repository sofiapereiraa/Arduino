#include <LiquidCrystal_I2C.h>
#define pin_1 2
#define pin_2 3
#define pin_3 4
#define pin_4 5
#define enter 6
int senha = 0;
int quantidade = 0;

LiquidCrystal_I2C lcd(32, 16, 2);

void setup() {
  pinMode(pin_1, INPUT_PULLUP);
  pinMode(pin_2, INPUT_PULLUP);
  pinMode(pin_3, INPUT_PULLUP);
  pinMode(pin_4, INPUT_PULLUP);
  pinMode(enter, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
}

void loop() {

  if (digitalRead(pin_1) == LOW && quantidade < 4) {

    senha = senha * 10 + 1;
    quantidade++;

    lcd.setCursor(quantidade, 0);
    lcd.print("1");

    while (digitalRead(pin_1) == LOW) {
    }
  }
  if (digitalRead(pin_2) == LOW && quantidade < 4) {
    senha = senha * 10 + 2;
    quantidade++;

    lcd.setCursor(quantidade, 0);
    lcd.print("2");

    while (digitalRead(pin_2) == LOW) {
    }
  }
  if (digitalRead(pin_3) == LOW && quantidade < 4) {
    senha = senha * 10 + 3;
    quantidade++;

    lcd.setCursor(quantidade, 0);
    lcd.print("3");

    while (digitalRead(pin_3) == LOW) {
    }
  }
  if (digitalRead(pin_4) == LOW && quantidade < 4) {
    senha = senha * 10 + 4;
    quantidade++;

    lcd.setCursor(quantidade, 0);
    lcd.print("4");

    while (digitalRead(pin_4) == LOW) {
    }
  }

  if (digitalRead(enter) == LOW) {
    if (senha == 1234) {
      lcd.setCursor(1, 1);
      lcd.print("Acesso Liberado");
    } else {
      lcd.setCursor(1, 1);
      lcd.print("Acesso Negado");
    }
  }
}