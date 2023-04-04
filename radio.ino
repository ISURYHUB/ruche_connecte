#include <RH_RF95.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_SHT31.h>

#define RFM95_CS 10
#define RFM95_RST 9
#define RFM95_INT 2

#define BEES_IN_PIN 3
#define BEES_OUT_PIN 4

Adafruit_SHT31 sht31 = Adafruit_SHT31();

RH_RF95 rf95(RFM95_CS, RFM95_INT);

unsigned long previousMillis = 0;
const long interval = 300000;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!rf95.init()) {
    Serial.println("LoRa radio init failed");
    while (1);
  }
  Serial.println("LoRa radio init OK!");

  if (!sht31.begin(0x44)) {
    Serial.println("Couldn't find SHT31 sensor!");
    while (1);
  }

  pinMode(BEES_IN_PIN, INPUT_PULLUP);
  pinMode(BEES_OUT_PIN, INPUT_PULLUP);
}

void loop() {
  float temp_c = sht31.readTemperature();
  float humidity = sht31.readHumidity();

  int bees_in = digitalRead(BEES_IN_PIN);
  int bees_out = digitalRead(BEES_OUT_PIN);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    char packet[50];
    sprintf(packet, "%f,%f,%d,%d", temp_c, humidity, bees_in, bees_out);

    rf95.send((uint8_t *)packet, strlen(packet));
    rf95.waitPacketSent();
    Serial.println("Data sent to Ubidots!");
  }
}