#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Bai 3: Quan sat nguon");
  display.display();
  delay(2000);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Trang thai: ACTIVE");
  display.println("CPU chay 100% freq");
  display.display();
  delay(3000);

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Trang thai: SLEEP");
  display.println("Giam tan so / Tat ngoai vi");
  display.display();
  delay(3000);
}
