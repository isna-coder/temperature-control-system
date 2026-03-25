int sensorPin = A0;
int led = 7;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int value = analogRead(sensorPin);

  float voltage = value * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.println(temperature);

  if (temperature > 40) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  delay(1000);
}