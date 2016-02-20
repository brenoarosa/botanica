#include <Wire.h>

uint8_t general_call = 0x0;

void setup() {
  
  Serial.begin(57600);
  Serial.println("Hello darkness, my old friend");
  
  uint8_t node_addr = 0x2;
  
  Wire.begin(node_addr);
  TWAR = (node_addr << 1) | 1;
  
  Wire.onReceive(message_handler);
}

void loop() {
  Wire.beginTransmission(general_call); // transmit to device #8
  Wire.write("Hello from the other siiiiide.");        // sends five bytes
  Wire.endTransmission();    // stop transmitting
  delay(100);
}

void message_handler(int byteCount) {

  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  Serial.println();

  return;
}
