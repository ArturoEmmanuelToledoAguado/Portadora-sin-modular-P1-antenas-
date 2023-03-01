#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

byte addresses[][6] = {"node1", "node2"};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setChannel(115);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.setRetries(15, 15);
  radio.openReadingPipe(0, addresses[1]);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char buffer[32];
    radio.read(&buffer, sizeof(buffer));
    Serial.println(buffer);
  }
}