#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define CLK 2
#define DT 3
#define SW 4

#define ledVermelho 10

Adafruit_SSD1306 OLED(128, 64, &Wire, -1);

int estadoAnteriorCLK;
int ultimoEstadoBotao = HIGH;
unsigned long ultimoTempoBotao = 0;

int menuitem = 1;
int page = 1;
int opcaoControle = 0;

const char* ambientes[] = {
  "Quarto",
  "Sala",
  "Cozinha",
  "Banheiro"
};

const int totalAmbientes = 4;

bool luzLigada[totalAmbientes] = {
  false, false, false, false
};

void desenharMenu();
void desenharControle();
void lerEncoder();
void lerBotao();
void confirmarOpcao();

void setup() {
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  pinMode(ledVermelho, OUTPUT);
  digitalWrite(ledVermelho, LOW);

  Serial.begin(9600);

  if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Erro ao iniciar o OLED!");
    while (true);
  }

  estadoAnteriorCLK = digitalRead(CLK);

  desenharMenu();
}

void loop() {
  lerEncoder();
  lerBotao();
}

void lerEncoder() {
  int estadoCLK = digitalRead(CLK);
  unsigned long ultimoTempoEncoder = 0;

  if (estadoCLK != estadoAnteriorCLK && estadoCLK == LOW) {
    int direcao = digitalRead(DT);

    if (page == 1) {
      if (direcao != estadoCLK) {
        menuitem++;
      } else {
        menuitem--;
      }

      if (menuitem > totalAmbientes) {
        menuitem = 1;
      }

      if (menuitem < 1) {
        menuitem = totalAmbientes;
      }

      desenharMenu();
    } else {
      if (direcao != estadoCLK) {
        opcaoControle++;
      } else {
        opcaoControle--;
      }

      if (opcaoControle > 2) {
        opcaoControle = 0;
      }

      if (opcaoControle < 0) {
        opcaoControle = 2;
      }

      desenharControle();
    }
  }

  estadoAnteriorCLK = estadoCLK;
}

void lerBotao() {
  int estadoBotao = digitalRead(SW);

  if (estadoBotao == LOW &&
      ultimoEstadoBotao == HIGH &&
      millis() - ultimoTempoBotao > 200) {

    ultimoTempoBotao = millis();
    confirmarOpcao();
  }

  ultimoEstadoBotao = estadoBotao;
}

void confirmarOpcao() {
  if (page == 1) {
    page = 2;
    opcaoControle = 0;
    desenharControle();
    return;
  }

  if (opcaoControle == 0) {
    luzLigada[menuitem - 1] = true;
  } else if (opcaoControle == 1) {
    luzLigada[menuitem - 1] = false;
  } else {
    page = 1;
    desenharMenu();
    return;
  }

  digitalWrite(
    ledVermelho,
    luzLigada[menuitem - 1] ? HIGH : LOW
  );

  desenharControle();
}

void desenharMenu() {
  OLED.clearDisplay();
  OLED.setTextColor(SSD1306_WHITE);
  OLED.setTextSize(1);

  OLED.setCursor(0, 0);
  OLED.println("Sistema de Luzes");
  OLED.println("----------------");

  for (int i = 0; i < totalAmbientes; i++) {
    OLED.setCursor(0, 18 + i * 11);

    if (i == menuitem - 1) {
      OLED.print("> ");
    } else {
      OLED.print("  ");
    }

    OLED.println(ambientes[i]);
  }

  OLED.display();
}

void desenharControle() {
  OLED.clearDisplay();
  OLED.setTextColor(SSD1306_WHITE);
  OLED.setTextSize(1);

  OLED.setCursor(0, 0);
  OLED.println(ambientes[menuitem - 1]);
  OLED.println("----------------");

  const char* opcoes[] = {
    "Ligar",
    "Desligar",
    "Voltar"
  };

  for (int i = 0; i < 3; i++) {
    OLED.setCursor(0, 20 + i * 11);

    if (i == opcaoControle) {
      OLED.print("> ");
    } else {
      OLED.print("  ");
    }

    OLED.println(opcoes[i]);
  }

  OLED.setCursor(0, 56);
  OLED.print("Estado: ");
  OLED.print(
    luzLigada[menuitem - 1] ? "LIGADA" : "DESLIGADA"
  );

  OLED.display();
}