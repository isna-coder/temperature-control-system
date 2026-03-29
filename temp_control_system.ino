char input;
char mode = 'A';   

int sensorPin = A0;
int led = 7;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {

 
  if (Serial.available()) {
    input = Serial.read();

    if (input == 'M') {
      mode = 'M';
      Serial.println("Manual Mode");
    }
    else if (input == 'A') {
      mode = 'A';
      Serial.println("Auto Mode");
    }
    else if (mode == 'M') {
      if (input == '1') {
        digitalWrite(led, HIGH);
        Serial.println("LED ON");
      }
      else if (input == '0') {
        digitalWrite(led, LOW);
        Serial.println("LED OFF");
      }
    }
  }

  
  if (mode == 'A') {

    int reading = analogRead(sensorPin);

    float voltage = reading * (5.0 / 1023.0);
    float temperature = (voltage - 0.5) * 100;

    Serial.print("Temp: ");
    Serial.println(temperature);

    if (temperature > 40) {
      digitalWrite(led, HIGH);
    } 
    else {
      digitalWrite(led, LOW);
    }
  }

  delay(500);
}
