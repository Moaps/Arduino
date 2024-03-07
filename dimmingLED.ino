#include <Arduino.h>

const int pins[] = {11, 10, 9}; // Green, Yellow, Blue
const int lenPins = sizeof(pins) / sizeof(pins[0]);
const int fadeDuration = 3000; // 3 seconds fade duration
const int stayLitBG = 5000; // 5 seconds stay lit duration

void setup() {
  for (int i = 0; i < lenPins; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void fadeIn(int pin) {
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(pin, brightness);
    delay(fadeDuration / 255);
  }
}

void fadeOut(int pin) {
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(pin, brightness);
    delay(fadeDuration / 255);
  }
}

void loop() {
  for (int i = 0; i < lenPins; i++) {
    // Fade in
    fadeIn(pins[i]);

    // Stay fully lit
    if (i != 1){
     delay(stayLitRG);
    }

    // Fade out
    fadeOut(pins[i]);
  }
}
