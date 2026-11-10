#include <Arduino.h>

#define LED_PIN 2
#define BUTTON_PIN 4 

RTC_DATA_ATTR int soLanThuc = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  digitalWrite(LED_PIN, HIGH); 
  delay(1000);
  digitalWrite(LED_PIN, LOW);

  soLanThuc++;
  Serial.print("So lan thuc day tu deep sleep: ");
  Serial.println(soLanThuc);

  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_TIMER: 
      Serial.println("Thuc day do Timer dinh thoi!"); 
      break;
    case ESP_SLEEP_WAKEUP_EXT0 : 
      Serial.println("Thuc day do Nut nhan (GPIO4)!"); 
      break;
    default: 
      Serial.println("Khoi dong lai tu dau (Power-on reset)."); 
      break;
  }

  esp_sleep_enable_timer_wakeup(10ULL * 1000000ULL); 
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_4, 0);

  Serial.println("Chuan bi vao Deep Sleep trong 3 giay...");
  delay(3000);

  esp_deep_sleep_start();
}

void loop() {
}