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
int fadeAmountHigh = 20;
int minValue = 1;
int maxValue = 255;





void setup() {
//  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  // change the brightness for next time through the loop:
  
  if (brightness < 35) {
    brightness = brightness + fadeAmount;
    delay(50);
  } else {
    brightness = brightness + fadeAmountHigh;  
    delay(20);
  }

  // check limits
  if (brightness >= maxValue) {
    brightness = maxValue;  
  }
  if (brightness <= minValue) {
    brightness = minValue;
    analogWrite(led, brightness);
    delay(10000);
  }
  analogWrite(led, brightness);

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= minValue || brightness >= maxValue) {
    fadeAmount = -fadeAmount;
    fadeAmountHigh = -fadeAmountHigh;
  }
}
