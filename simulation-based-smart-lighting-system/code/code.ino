int ldrPin = A0;
int ledPin = 13;
int threshold = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  int ldrValue = analogRead(ldrPin);

  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
