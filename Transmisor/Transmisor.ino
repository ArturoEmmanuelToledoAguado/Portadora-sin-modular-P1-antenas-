#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

byte addresses[][6] = {"node1", "node2"};

void setup() {
  radio.begin();
  radio.setChannel(115);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.setRetries(15, 15);
  radio.openWritingPipe(addresses[1]);
}

void loop() {
  radio.writeFast("PORTADORA", 9);
  delay(1000);
}