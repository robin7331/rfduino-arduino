

#include <Arduino.h>
#include <RFduinoBLE.h>

int ledPIN = 3;
int inputPin = 2;

void setup() {

  pinMode(ledPIN, OUTPUT);
  pinMode(inputPin, INPUT);

  digitalWrite(ledPIN, LOW);

  RFduinoBLE.deviceName = "Doorbell";
  RFduinoBLE.begin();
}

void loop() {

  RFduino_pinWake(inputPin, HIGH);
  RFduino_ULPDelay(INFINITE);

  while (!digitalRead(inputPin));

  // button was pressed
  RFduinoBLE.send(1);
  digitalWrite(ledPIN, HIGH);

  while(RFduinoBLE.radioActive);

  delay(5000);

  digitalWrite(ledPIN, LOW);

  RFduino_resetPinWake(inputPin);

}
