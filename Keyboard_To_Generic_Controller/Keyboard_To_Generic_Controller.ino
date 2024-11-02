#include <XInput.h>
#include <USBHost_t36.h>

USBHost myusb;
KeyboardController keyboard1(myusb);
USBHIDParser hid1(myusb);
const uint8_t escape_key = 27;
const uint8_t enter_key = 10;

void OnPress(int key){
  Serial.println(key);
  switch (key){
    case 'W':
    case 'w': XInput.press(DPAD_UP); break;
    case 'A':
    case 'a': XInput.press(DPAD_LEFT); break;
    case 'S':
    case 's': XInput.press(DPAD_DOWN); break;
    case 'D':
    case 'd': XInput.press(DPAD_RIGHT); break;
    case 0:
    case ' ': XInput.press(JOY_LEFT); break;
    case 'J':
    case 'j': XInput.press(BUTTON_A); break;
    case 'K':
    case 'k': XInput.press(BUTTON_B); break;
    case 'L':
    case 'l': XInput.press(BUTTON_X); break;
    case ';': XInput.press(BUTTON_Y); break;
    case 'U':
    case 'u': XInput.press(TRIGGER_LEFT); break;
    case 'I':
    case 'i': XInput.press(TRIGGER_RIGHT); break;
    case escape_key: XInput.press(BUTTON_START); break;
    case 'E':
    case 'e': XInput.press(BUTTON_BACK); break;
    case 'O':
    case 'o': XInput.press(JOY_RIGHT); break;
    case 'N':
    case 'n': XInput.press(BUTTON_LB); break;
    case 'M':
    case 'm': XInput.press(BUTTON_RB); break;
    case enter_key: XInput.press(BUTTON_LOGO); break;
  }
}

void OnRelease(int key){
  switch (key){
    case 'W':
    case 'w': XInput.release(DPAD_UP); break;
    case 'A':
    case 'a': XInput.release(DPAD_LEFT); break;
    case 'S':
    case 's': XInput.release(DPAD_DOWN); break;
    case 'D':
    case 'd': XInput.release(DPAD_RIGHT); break;
    case 0:
    case ' ': XInput.release(JOY_LEFT); break;
    case 'J':
    case 'j': XInput.release(BUTTON_A); break;
    case 'K':
    case 'k': XInput.release(BUTTON_B); break;
    case 'L':
    case 'l': XInput.release(BUTTON_X); break;
    case ';': XInput.release(BUTTON_Y); break;
    case 'U':
    case 'u': XInput.release(TRIGGER_LEFT); break;
    case 'I':
    case 'i': XInput.release(TRIGGER_RIGHT); break;
    case escape_key: XInput.release(BUTTON_START); break;
    case 'E':
    case 'e': XInput.release(BUTTON_BACK); break;
    case 'O':
    case 'o': XInput.release(JOY_RIGHT); break;
    case 'N':
    case 'n': XInput.release(BUTTON_LB); break;
    case 'M':
    case 'm': XInput.release(BUTTON_RB); break;
    case enter_key: XInput.release(BUTTON_LOGO); break;
  }
}

void setup() {
  myusb.begin();
  keyboard1.attachPress(OnPress);
  keyboard1.attachRelease(OnRelease);
  Serial.begin(9600);
}

void loop() {
  myusb.Task();
}
