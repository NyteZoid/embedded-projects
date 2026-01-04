#include <Arduino.h>
#include <LiquidCrystal.h>

const int trigPin = 9;
const int echoPin = 10;

const int redLED = A5;
const int yellowLED = A3;
const int greenLED = A1;

const int buzzerPIN = 2;

LiquidCrystal lcd(12, 11, 8, 13, 4, 6);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzerPIN, OUTPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();
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
  Serial.println(" cm   ");

  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance, 1);
  lcd.print(" cm   ");

  lcd.setCursor(0, 1);

  if (distance < 10 && distance > 0) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

    lcd.print("CLOSE ");

    digitalWrite(buzzerPIN, HIGH);
    delay(100);
    digitalWrite(buzzerPIN, LOW);
    delay(100);
  }

  else if (distance >= 10 && distance <= 20) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);

    lcd.print("MEDIUM");

    digitalWrite(buzzerPIN, HIGH);
    delay(300);
    digitalWrite(buzzerPIN, LOW);
    delay(300);
  }

  else {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);

    lcd.print("SAFE  ");

    digitalWrite(buzzerPIN, LOW);
  }

  delay(200);
}