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
  delay(200);
}

void loop() {
  Usb.Task();
  if (Xbox.XboxConnected) {
    if (Xbox.getButtonPress(L2)) {
      driveForward();
    } else if (Xbox.getButtonPress(R2)) {
      driveBackward();
    }
  }
}



