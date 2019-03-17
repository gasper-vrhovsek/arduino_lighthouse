/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by
int flashAmount = 20;
int minValue = 1;
int maxValue = 255;
int flashCount = 1;
int flashes = 3;
int flashLimit = 35;

// stages
int stage = 0;

void setup() {
//  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);
  stage = 0;
}

void loop() {
  // change the brightness for next time through the loop:

  // set stage
  if (stage == 0) {
    // ramp up
    brightness = min(brightness + fadeAmount, flashLimit);
    delay(50);  
  }

  if (stage == 1) {
    // first flash up
    brightness = min(brightness + flashAmount, maxValue);
    delay(20);
  } 

  if (stage == 2) {
    // last flash down
    brightness = max(brightness - flashAmount, flashLimit);
    delay(20);
  }

  if (stage == 22) {
    // middle flash down
    brightness = max(brightness - flashAmount, minValue);
    delay(20);
  }
  
  if (stage == 3) {
    // ramp down
    brightness = max(brightness - fadeAmount, minValue); 
    delay(50);
  }

  // write led
  analogWrite(led, brightness);
  
  // check state
  if (stage == 0 && brightness == flashLimit) {
    // set stage to first flash
    stage = 1;        
  }
  if (stage == 1 && brightness == maxValue) {
    if (flashCount < flashes) {
      stage = 22;  
    } else {
      stage = 2;    
    }
  }

  if(stage == 22 && brightness == minValue) {
    stage = 1;
    flashCount = flashCount + 1;
    delay(1500);
  }
  
  if(stage == 2 && brightness == flashLimit) {
    if (flashCount < flashes) {
      stage = 1;
      flashCount = flashCount + 1;
      delay(1500);
    } else {
      stage = 3;  
      flashCount = 1;
    }
  }
  if(stage == 3 && brightness == minValue) {
    stage = 0;
    delay(6000);
  }
}
