#include <XInput.h>
#include <USBHost_t36.h>

USBHost myusb;
KeyboardController keyboard1(myusb);
USBHIDParser hid1(myusb);
const uint8_t escape_key = 27;
const uint8_t enter_key = 10;

void OnPress(int key){
  switch (key){
    case 'w': XInput.press(DPAD_UP); break;
    case 'a': XInput.press(DPAD_LEFT); break;
    case 's': XInput.press(DPAD_DOWN); break;
    case 'd': XInput.press(DPAD_RIGHT); break;
    case ' ': XInput.press(JOY_LEFT); break;
    case 'j': XInput.press(BUTTON_A); break;
    case 'k': XInput.press(BUTTON_B); break;
    case 'l': XInput.press(BUTTON_X); break;
    case ';': XInput.press(BUTTON_Y); break;
    case 'u': XInput.press(TRIGGER_LEFT); break;
    case 'i': XInput.press(TRIGGER_RIGHT); break;
    case escape_key: XInput.press(BUTTON_START); break;
    case enter_key: XInput.press(BUTTON_BACK); break;
    case 'o': XInput.press(TRIGGER_RIGHT); break;
    case 'n': XInput.press(BUTTON_LB); break;
    case 'm': XInput.press(BUTTON_RB); break;
    case ',': XInput.press(BUTTON_LOGO); break;
  }
}

void OnRelease(int key){
  switch (key){
    case 'w': XInput.release(DPAD_UP); break;
    case 'a': XInput.release(DPAD_LEFT); break;
    case 's': XInput.release(DPAD_DOWN); break;
    case 'd': XInput.release(DPAD_RIGHT); break;
    case ' ': XInput.release(JOY_LEFT); break;
    case 'j': XInput.release(BUTTON_A); break;
    case 'k': XInput.release(BUTTON_B); break;
    case 'l': XInput.release(BUTTON_X); break;
    case ';': XInput.release(BUTTON_Y); break;
    case 'u': XInput.release(TRIGGER_LEFT); break;
    case 'i': XInput.release(TRIGGER_RIGHT); break;
    case escape_key: XInput.release(BUTTON_START); break;
    case enter_key: XInput.release(BUTTON_BACK); break;
    case 'o': XInput.release(TRIGGER_RIGHT); break;
    case 'n': XInput.release(BUTTON_LB); break;
    case 'm': XInput.release(BUTTON_RB); break;
    case ',': XInput.release(BUTTON_LOGO); break;
  }
}

void setup() {
  myusb.begin();
  keyboard1.attachPress(OnPress);
  keyboard1.attachRelease(OnRelease);
}

void loop() {
  myusb.Task();
}
