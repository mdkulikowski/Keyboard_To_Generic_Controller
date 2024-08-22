#include <USBHost_t36.h>

USBHost myusb;
KeyboardController keyboard1(myusb);
USBHIDParser hid1(myusb);

void OnPress(int key){
  digitalWrite(LED_BUILTIN, HIGH);
  switch (key){
    case 'w': Serial.print('w'); break;
    case 'a': Serial.print('a'); break;
    case 's': Serial.print('s'); break;
    case 'd': Serial.print('d'); break;
    case ' ': Serial.print("space"); break;
    case 'j': Serial.print('j'); break;
    case 'k': Serial.print('k'); break;
    case 'l': Serial.print('l'); break;
    case ';': Serial.print(';'); break;
    case 'u': Serial.print('u'); break;
    case 'i': Serial.print('i'); break;
    case 'o': Serial.print('o'); break;
    case 'n': Serial.print('n'); break;
    case 'm': Serial.print('m'); break;
    case ',': Serial.print(','); break;
  }
  Serial.print(" ");
}

void OnRelease(int key){
  digitalWrite(LED_BUILTIN, LOW);
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