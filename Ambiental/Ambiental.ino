#include <LiquidCrystal_I2C.h>

int temperatura = 0;
int VLDR = 0;
int PINO_SENSOR = A2;

#define ledVermelho 9
#define ledVerde 10
#define BTN_1 2
#define BTN_2 3
#define BTN_3 4
#define PINO_Temperatura A0
#define LDR A1


LiquidCrystal_I2C lcd(32, 16, 2);

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2,INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(3, 0);
  lcd.print("Monitor ");
  lcd.setCursor(0, 1);
  lcd.print("    Ambiental !");
  delay(4000);
}

void loop()
{
 if (digitalRead(BTN_1) == LOW)
  {
    int leitura = analogRead(PINO_Temperatura);

    float tensao = leitura * (5.0 / 1023.0);
    float temperatura = (tensao - 0.5) * 100.0;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura:");

    lcd.setCursor(0, 1);
    lcd.print(temperatura);
    lcd.print(" C");

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" C");

    if (temperatura >= 30)
    {
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, LOW);
    }
    else
    {
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledVermelho, LOW);
    }

    delay(1000);

    while (digitalRead(BTN_1) == LOW)
    {
    }
  }
  
 if (digitalRead(BTN_2) == LOW)
{
  VLDR = analogRead(LDR);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Luminosidade:");
  lcd.setCursor(0, 1);
  lcd.print(VLDR);

  Serial.print("Luminosidade: ");
  Serial.println(VLDR);

  if (VLDR < 700)
  {
    digitalWrite(ledVermelho, HIGH);
     digitalWrite(ledVerde, LOW);
  }
  else
  {
    digitalWrite(ledVerde, HIGH);
     digitalWrite(ledVermelho, LOW);
  }

  delay(100);

  while (digitalRead(BTN_2) == LOW)
  {
  }
}
  
if (digitalRead(BTN_3) == LOW) {
  int sensorValue = analogRead(PINO_SENSOR);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nivel: ");
  lcd.print(sensorValue);

  if (sensorValue <= 180) {
    lcd.setCursor(0, 1);
    lcd.print("Muito molhado");
  }
  else if (sensorValue <= 360) {
    lcd.setCursor(0, 1);
    lcd.print("Solo umido");
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("Solo seco");
  }

  Serial.print("Umidade: ");
  Serial.println(sensorValue);

  delay(500);
}
}