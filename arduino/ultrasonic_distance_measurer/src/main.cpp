#include <Arduino.h>

const int trigPin = 9;
const int echoPin = 10;

const int redLED = 3;
const int yellowLED = 5;
const int greenLED = 7;

const int buzzerPIN = 2;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzerPIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10 && distance > 0) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

    digitalWrite(buzzerPIN, HIGH);
    delay(100);
    digitalWrite(buzzerPIN, LOW);
    delay(100);
  }

  else if (distance >= 10 && distance <= 20) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);

    digitalWrite(buzzerPIN, HIGH);
    delay(300);
    digitalWrite(buzzerPIN, LOW);
    delay(300);
  }

  else {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);

    digitalWrite(buzzerPIN, LOW);
  }

  delay(200);
}