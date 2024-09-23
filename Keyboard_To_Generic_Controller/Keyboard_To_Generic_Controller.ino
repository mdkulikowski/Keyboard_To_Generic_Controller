#include <XInput.h>
#include <USBHost_t36.h>

USBHost myusb;
KeyboardController keyboard1(myusb);
USBHIDParser hid1(myusb);

const int JOYSTICK_MIN = 0;
const int JOYSTICK_MID = 512;  // Center position
const int JOYSTICK_MAX = 1023;  // Full forward/right

/*
BUTTON_LOGO = 0,
	BUTTON_A = 1,
	BUTTON_B = 2,
	BUTTON_X = 3,
	BUTTON_Y = 4,
	BUTTON_LB = 5,
	BUTTON_RB = 6,
	BUTTON_BACK = 7,
	BUTTON_START = 8,
	BUTTON_L3 = 9,
	BUTTON_R3 = 10,
	DPAD_UP = 11,
	DPAD_DOWN = 12,
	DPAD_LEFT = 13,
	DPAD_RIGHT = 14,
	TRIGGER_LEFT = 15,
	TRIGGER_RIGHT = 16,
	JOY_LEFT,
	JOY_RIGHT,
*/


void OnPress(int key){
  digitalWrite(LED_BUILTIN, HIGH);
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
    case KEY_ESC: XInput.press(BUTTON_START); break;
    case KEY_RETURN: XInput.press(BUTTON_BACK); break;
    case 'o': XInput.press(TRIGGER_RIGHT); break;
    case 'n': XInput.press(BUTTON_LB); break;
    case 'm': XInput.press(BUTTON_RB); break;
    case ',': XInput.press(BUTTON_LOGO); break;
  }
}

void OnRelease(int key){
  digitalWrite(LED_BUILTIN, LOW);
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
    case KEY_ESC: XInput.release(BUTTON_START); break;
    case KEY_RETURN: XInput.release(BUTTON_BACK); break;
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
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  myusb.Task();
}