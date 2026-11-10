#include <Arduino.h>

hw_timer_t *hwTimer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

volatile uint32_t interruptCounter = 0;

void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
}

void setup() {
  Serial.begin(115200);

  hwTimer = timerBegin(1000000);
  
  timerAttachInterrupt(hwTimer, &onTimer);
  
  timerAlarm(hwTimer, 1000000, true, 0);
}

void loop() {
  if (interruptCounter > 0) {
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);

    Serial.println("Ngắt từ Timer phần cứng mỗi 1s!");
  }
}