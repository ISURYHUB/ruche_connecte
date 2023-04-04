#include <DHT.h>
#include <WiFi.h>
#include <UbidotsWiFi.h>

#define DHTPIN 2
#define DHTTYPE DHT11

const char* ssid = "xxx";
const char* password = "xxx";
const char* token = "xxx";
const char* ssid = "xxx";

DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;
Ubidots client(token);

void setup() {
  Serial.begin(9600);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");

  dht.begin();
}

void loop() {
  delay(2000);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  client.add("temperature", temperature);
  client.add("humidity", humidity);
  client.sendAll();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" *C ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}