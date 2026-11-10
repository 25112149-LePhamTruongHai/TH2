#define LED1 2
#define ADC_PIN 34

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);

  int val = analogRead(ADC_PIN);
  Serial.print("Bien tro: ");
  Serial.println(val);
  delay(2000);

  Serial.println("heartbeat");
  delay(5000);
}