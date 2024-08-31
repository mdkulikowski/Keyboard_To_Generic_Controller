#include <USBHost_t36.h>

USBHost myusb;
KeyboardController keyboard1(myusb);
USBHIDParser hid1(myusb);


void OnPress(int key){
  switch (key){
    case 'w': Joystick.Y(1023); break;
    case 'a': Joystick.X(0); break;
    case 's': Joystick.Y(0); break;
    case 'd': Joystick.x(1023); break;
    case ' ': Joystick.button(4,1); break;
    case 'j': Joystick.button(1,1); break;
    case 'k': Joystick.button(2,1); break;
    case 'l': Joystick.button(3,1); break;
    case ';': Joystick.button(11,1); break;
    case 'u': Joystick.button(5,1); break;
    case 'i': Joystick.button(6,1); break;
    case 'ESC': Joystick.button(10,1); break;
    case 'CR': Joystick.button(9,1); break;
    case 'o': Joystick.button(12,1); break;
    case 'n': Joystick.button(13,1); break;
    case 'm': Joystick.button(14,1); break;
    case ',': Joystick.button(15,1); break;
  }
}

//void onJoystickPress()

void OnRelease(int key){
  switch (key){
    case 'w': Joystick.Y(512); break;
    case 'a': Joystick.X(512); break;
    case 's': Joystick.Y(512); break;
    case 'd': Joystick.x(512); break;
    case ' ': Joystick.button(4,0); break;
    case 'j': Joystick.button(1,0); break;
    case 'k': Joystick.button(2,0); break;
    case 'l': Joystick.button(3,0); break;
    case ';': Joystick.button(11,0); break;
    case 'u': Joystick.button(5,0; break;
    case 'i': Joystick.button(6,0); break;
    case 'ESC': Joystick.button(10,0); break;
    case 'CR': Joystick.button(9,0); break;
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