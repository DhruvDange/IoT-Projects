#include <FastLED.h>

// ---------------------------------
#define NUM_LEDS 8
#define DATA_PIN 20
CRGB leds[NUM_LEDS];

// Key definitions
#define BUTTON_KEY1 KEY_F13
#define BUTTON_KEY2 KEY_F14
#define BUTTON_KEY3 KEY_F15
#define BUTTON_KEY4 KEY_F16
#define BUTTON_KEY5 KEY_F17
#define BUTTON_KEY6 KEY_F18
#define BUTTON_KEY7 KEY_F19
#define BUTTON_KEY8 KEY_F20

// Pin definitions
#define BUTTON_PIN1 2
#define BUTTON_PIN2 3
#define BUTTON_PIN3 4
#define BUTTON_PIN4 5
#define BUTTON_PIN5 6
#define BUTTON_PIN6 7
#define BUTTON_PIN7 8
#define BUTTON_PIN8 9

// LED definitions
#define LED_1 7
#define LED_2 0
#define LED_3 1
#define LED_4 6
#define LED_5 2
#define LED_6 5
#define LED_7 3
#define LED_8 4

// LED States
boolean LED_STATE1 = false;
boolean LED_STATE2 = false;
boolean LED_STATE3 = false;
boolean LED_STATE4 = false;
boolean LED_STATE5 = false;
boolean LED_STATE6 = false;
boolean LED_STATE7 = false;
boolean LED_STATE8 = false;


// ---------------------------------

#include "Keyboard.h"

// Button helper class for handling press/release and debouncing
class button {
  public:
  const char key;
  uint8_t pin;
  uint8_t ledPos;
  boolean Ledstate;
  boolean returnState;

  button(uint8_t k, uint8_t p, uint8_t l, boolean s) : key(k), pin(p), ledPos(l), Ledstate(s){}

  void press(boolean state){
    if(state == pressed || (millis() - lastPressed  <= debounceTime)){
      return; // Nothing to see here, folks
    }
    returnState = Ledstate;
    lastPressed = millis();

    state ? Keyboard.press(key) : Keyboard.release(key);    
    pressed = state;
    if(state){
      checkLED();
    }
  }

  void checkLED()
  {
    if(Ledstate == false){
      Serial.println(ledPos);
      leds[ledPos] = CRGB::Blue;
      returnState = true;
    }else{
      Serial.println(ledPos);
      leds[ledPos] = CRGB::Black;
      returnState = false;
    }
     FastLED.show();
  }

  boolean update(){
    press(!digitalRead(pin));
    return returnState;
  }

  private:
  const unsigned long debounceTime = 30;
  unsigned long lastPressed = 0;
  boolean pressed = 0;
} ;

// Button objects, organized in array
button buttons[] = {
  {BUTTON_KEY1, BUTTON_PIN1, LED_1, LED_STATE1},
  {BUTTON_KEY2, BUTTON_PIN2, LED_2, LED_STATE2},
  {BUTTON_KEY3, BUTTON_PIN3, LED_3, LED_STATE3},
  {BUTTON_KEY4, BUTTON_PIN4, LED_4, LED_STATE4},
  {BUTTON_KEY5, BUTTON_PIN5, LED_5, LED_STATE5},
  {BUTTON_KEY6, BUTTON_PIN6, LED_6, LED_STATE6},
  {BUTTON_KEY7, BUTTON_PIN7, LED_7, LED_STATE7},
  {BUTTON_KEY8, BUTTON_PIN8, LED_8, LED_STATE8},
};

const uint8_t NumButtons = 8;

void setup() { 

   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  
  // Safety check. Ground pin #1 (RX) to cancel keyboard inputs.
  pinMode(1, INPUT_PULLUP);
  if(!digitalRead(1)){
    failsafe();
  }

  for(int i = 0; i < NumButtons; i++){
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }

  for(int i = 0; i < 9; i++){
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}

void loop() {
  for(int i = 0; i < NumButtons; i++){
    buttons[i].Ledstate = buttons[i].update();

  }
}

void failsafe(){
  for(;;){} // Just going to hang out here for awhile :D
}
