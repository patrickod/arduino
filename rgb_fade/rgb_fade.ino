#include <stdio.h>

const int MAX_BRIGHTNESS = 64;

enum colors {
  RED   = 1,
  GREEN = 2,
  BLUE  = 4
};

int bluePin = 11;
int redPin = 10;
int greenPin = 9;

int buttonPin = 2;
int buttonState = 0;

int currentColor = RED;

void setColorRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT);
  setColorRgb(0,0,0);
}

void changeColor() {
  currentColor = currentColor == BLUE ? RED : currentColor << 1;
}

void setColor() {
  switch(currentColor) {
    case RED:
      setColorRgb(MAX_BRIGHTNESS, 0, 0);
      break;
    case GREEN:
      setColorRgb(0, MAX_BRIGHTNESS, 0);
      break;
    case BLUE:
      setColorRgb(0, 0, MAX_BRIGHTNESS);
      break;
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    changeColor();
  }

  setColor();
}

