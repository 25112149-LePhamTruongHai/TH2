const int LED1 = 2;
const int ADC_PIN = 34;

unsigned long lanTruocLed = 0;
unsigned long lanTruocAdc = 0;
unsigned long lanTruocHeart = 0;

bool ledState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
}

void loop() {
  unsigned long now = millis();

  if (now - lanTruocLed >= 500) {
    lanTruocLed = now;
    ledState = !ledState;
    digitalWrite(LED1, ledState);
  }

  if (now - lanTruocAdc >= 2000) {
    lanTruocAdc = now;
    int val = analogRead(ADC_PIN);
    Serial.print("Bien tro: ");
    Serial.println(val);
  }

  if (now - lanTruocHeart >= 5000) {
    lanTruocHeart = now;
    Serial.println("heartbeat");
  }
}