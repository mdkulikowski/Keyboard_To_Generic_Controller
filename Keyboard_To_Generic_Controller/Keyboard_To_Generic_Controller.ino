#include <USBHost_t36.h>
#include <TeensyJoystick.h>



USBHost myusb;
KeyboardController keyboard1(myusb);
USBHIDParser hid1(myusb);
TeensyJoystick Joystick;

const int JOYSTICK_MIN = 0;
const int JOYSTICK_MID = 512;  // Center position
const int JOYSTICK_MAX = 1023;  // Full forward/right


void OnPress(int key){
  digitalWrite(LED_BUILTIN, HIGH);
  switch (key){
    case 'w': Joystick.Y(JOYSTICK_MAX); break;
    case 'a': Joystick.X(JOYSTICK_MIN); break;
    case 's': Joystick.Y(JOYSTICK_MIN); break;
    case 'd': Joystick.X(JOYSTICK_MAX); break;
    case ' ': Joystick.button(4,1); break;
    case 'j': Joystick.button(1,1); break;
    case 'k': Joystick.button(2,1); break;
    case 'l': Joystick.button(3,1); break;
    case ';': Joystick.button(11,1); break;
    case 'u': Joystick.button(5,1); break;
    case 'i': Joystick.button(6,1); break;
    case KEY_ESC: Joystick.button(10,1); break;
    case KEY_RETURN: Joystick.button(9,1); break;
    case 'o': Joystick.button(12,1); break;
    case 'n': Joystick.button(13,1); break;
    case 'm': Joystick.button(14,1); break;
    case ',': Joystick.button(15,1); break;
  }
}

void OnRelease(int key){
  digitalWrite(LED_BUILTIN, LOW);
  switch (key){
    case 'w': Joystick.Y(JOYSTICK_MID); break;
    case 'a': Joystick.X(JOYSTICK_MID); break;
    case 's': Joystick.Y(JOYSTICK_MID); break;
    case 'd': Joystick.X(JOYSTICK_MID); break;
    case ' ': Joystick.button(4,0); break;
    case 'j': Joystick.button(1,0); break;
    case 'k': Joystick.button(2,0); break;
    case 'l': Joystick.button(3,0); break;
    case ';': Joystick.button(11,0); break;
    case 'u': Joystick.button(5,0); break;
    case 'i': Joystick.button(6,0); break;
    case KEY_ESC: Joystick.button(10,0); break;
    case KEY_RETURN: Joystick.button(9,0); break;
    case 'o': Joystick.button(12,0); break;
    case 'n': Joystick.button(13,0); break;
    case 'm': Joystick.button(14,0); break;
    case ',': Joystick.button(15,0); break;
  }
}

void setup() {
  myusb.begin();
  Joystick.begin();
  keyboard1.attachPress(OnPress);
  keyboard1.attachRelease(OnRelease);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  myusb.Task();
}