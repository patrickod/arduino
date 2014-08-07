const int MAX_BRIGHTNESS = 64;
int bluePin = 11;
int redPin = 10;
int greenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  setColorRgb(0,0,0);
}

void loop() {
  unsigned int rgbColor[3];
  rgbColor[0] = MAX_BRIGHTNESS;
  rgbColor[1] = 0;
  rgbColor[2] = 0;
  
  for(int decColor = 0; decColor < 3; decColor += 1) {
    int intColor = decColor == 2 ? 0 : decColor + 1;
    for(int i = 0; i < MAX_BRIGHTNESS; i += 1) {
      rgbColor[decColor] -= 1;
      rgbColor[intColor] += 1;
      setColorRgb(rgbColor[0], rgbColor[1], rgbColor[2]);
      delay(10);
    }
  }
}

void setColorRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

