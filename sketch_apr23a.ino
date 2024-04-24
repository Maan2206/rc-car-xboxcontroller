#include <USBHost.h>

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
XBOXUSB Xbox(&Usb);

void setup() {
  Serial.begin(115200);
  if (Usb.Init() == -1) {
    Serial.println("USB host shield did not initialize.");
  }
  }
  pinMode(motorPinLeftForward, OUTPUT);
  pinMode(motorPinLeftBackward, OUTPUT);
  pinMode(motorPinRightForward, OUTPUT);
  pinMode(motorPinRightBackward, OUTPUT);  
  
  {
  delay(200);
  }

void loop() {
  Usb.Task();
  
  if (Xbox.XboxConnected) {
    if (Xbox.getButtonPress(L2)) { 
      digitalWrite(motorPinLeftForward, HIGH);
      digitalWrite(motorPinRightForward, HIGH);
      digitalWrite(motorPinLeftBackward, LOW);
      digitalWrite(motorPinRightBackward, LOW);
    } else if (Xbox.getButtonPress(R2)) { 
      digitalWrite(motorPinLeftBackward, HIGH);
      digitalWrite(motorPinRightBackward, HIGH);
      digitalWrite(motorPinLeftForward, LOW);
      digitalWrite(motorPinRightForward, LOW);
    } else if (Xbox.getButtonPress(LEFT)) { 
      digitalWrite(motorPinLeftBackward, HIGH);
      digitalWrite(motorPinRightForward, HIGH);
      digitalWrite(motorPinLeftForward, LOW);
      digitalWrite(motorPinRightBackward, LOW);
    } else if (Xbox.getButtonPress(RIGHT)) { 
      digitalWrite(motorPinLeftForward, HIGH);
      digitalWrite(motorPinRightBackward, HIGH);
      digitalWrite(motorPinLeftBackward, LOW);
      digitalWrite(motorPinRightForward, LOW);
    } else {               // Stop all motors
      digitalWrite(motorPinLeftForward, LOW);
      digitalWrite(motorPinLeftBackward, LOW);
      digitalWrite(motorPinRightForward, LOW);
      digitalWrite(motorPinRightBackward, LOW);
    }
  }
}
