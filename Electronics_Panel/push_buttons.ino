#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>


#define SSD1306_LCDHEIGHT 64
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// Pins for Push Button signal
int ledPushButtonSignalPin = 12;
int tubePushButtonSignalPin = 11;

// Pins for relay signal
int ledRelayPin = 9;
int tubeRelayPin = 8;

// Pins for Button Light
int ledPushButtonLightPin = 6;
int tubePushButtonLightPin = 5;

// LED Button state variables
int ledButtonNew;
int ledButtonOld = 1;
int ledRelayState = 0;

// Tube light Button State variables
int tubeButtonNew;
int tubeButtonOld = 1;
int tubeRelayState = 0;


// Delay between inputs
int delayTime = 100;

void setup() {

  Serial.begin(9600);

  // Input mode for push button signal
  pinMode(ledPushButtonSignalPin, INPUT);
  pinMode(tubePushButtonSignalPin, INPUT);

  // Output for relay and Switch LED Pins
  pinMode(ledRelayPin, OUTPUT);
  pinMode(tubeRelayPin, OUTPUT);
  pinMode(ledPushButtonLightPin, OUTPUT);
  pinMode(tubePushButtonLightPin, OUTPUT);

  digitalWrite(ledRelayPin, LOW);
  digitalWrite(ledPushButtonLightPin, HIGH);

  digitalWrite(tubeRelayPin, HIGH);
  digitalWrite(tubePushButtonLightPin, LOW);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize I2C addr to 0x3C ( for 128x64 Display )

  display.clearDisplay();

}

void ReadLedSignal() {

  if (ledButtonOld == 0 && ledButtonNew == 1) {
    if (ledRelayState == 0) {
      digitalWrite(ledRelayPin, LOW);
      digitalWrite(ledPushButtonLightPin, HIGH);
      ledRelayState = 1;
    } else {
      digitalWrite(ledRelayPin, HIGH);
      digitalWrite(ledPushButtonLightPin, LOW);
      ledRelayState = 0;
    }
  }
  ledButtonOld = ledButtonNew;

}

void ReadTubeSignal() {

  if (tubeButtonOld == 0 && tubeButtonNew == 1) {
    if (tubeRelayState == 0) {
      digitalWrite(tubeRelayPin, LOW);
      digitalWrite(tubePushButtonLightPin, HIGH);
      tubeRelayState = 1;
    } else {
      digitalWrite(tubeRelayPin, HIGH);
      digitalWrite(tubePushButtonLightPin, LOW);
      tubeRelayState = 0;
    }
  }
  tubeButtonOld = tubeButtonNew;
}

void loop() {

  ledButtonNew = digitalRead(ledPushButtonSignalPin);
  tubeButtonNew = digitalRead(tubePushButtonSignalPin); \

  delay(delayTime);

  ReadLedSignal();

  ReadTubeSignal();
}
