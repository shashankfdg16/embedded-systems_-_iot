#include<DHT.h>

#define DHTPIN 2        // DHT data pin
#define DHTTYPE DHT22   // Change to DHT11 if needed

#define LEDPIN 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Threshold logic
  if (temperature > 30.0) {
    digitalWrite(LEDPIN, HIGH);   // Alert
  } else {
    digitalWrite(LEDPIN, LOW);
  }

  delay(2000);
}
