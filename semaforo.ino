#include <TFT_eSPI.h>
#define RED 12
#define YELLOW 13
#define GREEN 15

TFT_eSPI tft = TFT_eSPI();

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  tft.init();
  tft.setRotation(2);
  tft.setTextSize(10);
}

void loop() {
  lightManager("ROJO");
  lightManager("VERDE");
  lightManager("AMARILLO");
}

void lightManager(String color) {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  if (color == "ROJO") {
    digitalWrite(RED, HIGH);
    tft.setTextColor(TFT_RED, TFT_BLACK);
    countdown(10);
  }
  if (color == "VERDE") {
    digitalWrite(GREEN, HIGH);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    countdown(10);
  }
  if (color == "AMARILLO") {
    digitalWrite(YELLOW, HIGH);
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    countdown(3);
  }
 }

 void countdown(int duration) {
  int count = duration;
  for (int i = duration; i >= 1; i--) {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(50, 100);
    tft.print(i);
    delay(1000);
  }
 }
