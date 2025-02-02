#include <ArduinoJson.h>
#include <ArduinoJson.hpp>
#include <WiFi.h>
#include <FastLED.h>

#define LED_PIN 48
#define NUM_LEDS 1  // Update to the number of LEDs you have
CRGB leds[NUM_LEDS];

const char *ssid = "Kevin's iPhone";      // Change this to your WiFi Network name
const char *password = "133701134";  // Change this to your WiFi password

const char *host = "api.open-meteo.com";  // This should not be changed
const int httpPort = 80;                  // This should not be changed


const String latitude = "35.6895";
const String longitude = "139.6917";

// this is how long each loop will pause for
int delayTimeInit = 2000;
int loopCountTotal = 60 * 1000 / delayTimeInit;
int loopCount = 0;


// variables to keep track of the rain amount and temperature
double temp = 0;
double rain = 0;


void setup() {
  Serial.begin(115200);

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println("******************************************************");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// Helper function to check if a string is hexadecimal
bool isHexadecimal(String str) {
  for (int i = 0; i < str.length(); i++) {
    char c = str.charAt(i);
    if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
      return false;
    }
  }
  return true;
}

String readResponse(NetworkClient *client) {
  unsigned long timeout = millis();
  String response = "";
  while (client->available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client->stop();
      return "";
    }
  }

  bool isBody = false;  // Flag to indicate when the body starts

  while (client->available()) {
    String line = client->readStringUntil('\n');  // Read until '\n'

    line.trim();  // Remove leading and trailing whitespace

    if (line.isEmpty() && !isBody) {
      // Headers end after the first empty line
      isBody = true;
      continue;
    }

    if (isBody) {
      // Parse chunked response
      if (line.length() > 0 && isHexadecimal(line)) {
        // Skip the chunk size line (hexadecimal number)
        continue;
      }
      if (line == "0") {
        // End of chunked transfer
        break;
      }
      response += line;  // Append valid body data
    }
  }

  return response;

  Serial.printf("\nClosing connection\n\n");
}

void loop() {

  if (loopCount == 0) {
    NetworkClient client;
    String footer = String(" HTTP/1.1\r\n") + "Host: " + String(host) + "\r\n" + "Connection: close\r\n\r\n";

    if (!client.connect(host, httpPort)) {
      return;
    }

    String readRequest = "GET /v1/forecast?latitude=" + latitude + "&longitude=" + longitude + "&current=temperature_2m,rain&forecast_days=1 " + "HTTP/1.1\r\nHost: " + host + "\r\n"
                         + "Connection: close\r\n\r\n";


    // Uncomment to print out what the actual raw HTTP request looks like
    // Serial.println(readRequest);

    if (!client.connect(host, httpPort)) {
      return;
    }

    client.print(readRequest);

    String response = readResponse(&client);

    // Uncomment if you want to see what the HTTP request looks like
    // Serial.println("Response from HTTP request:");
    // Serial.println(response);


    // This code will parse the JSON response
    JsonDocument doc;
    deserializeJson(doc, response);

    temp = doc["current"]["temperature_2m"];
    rain = doc["current"]["rain"];

    Serial.print("Rain: ");
    Serial.println(rain);
    Serial.print("Temp: ");
    Serial.println(temp);
  }

  int delayTime = delayTimeInit;

  if (temp > 25) {
    // Hot!!!!
    leds[0] = CRGB::Red;
    FastLED.show();
  } else if (temp < 5) {
    // Cold!!!
    leds[0] = CRGB::LightSkyBlue;
    FastLED.show();
  } else if (rain > 0) {
    // Rain!!!
    leds[0] = CRGB::Blue;
    FastLED.show();
    delay(500);
    delayTime -= 500;
    FastLED.clear();
    FastLED.show();
  } else {
    int fadeDelayStepSize = 20;
    // Great weather!
    // leds[0] = CRGB::Green;
    // FastLED.show();
    // Gradually increase brightness
    for (int brightness = 60; brightness <= 255; brightness+= 5) {
      leds[0] = CHSV(100, 255, brightness);  // Hue 160 is blue in HSV
      FastLED.show();
      delayTime -= fadeDelayStepSize;
      delay(fadeDelayStepSize);  // Adjust for smoother or faster pulsing
    }
    // Gradually decrease brightness
    for (int brightness = 255; brightness >= 60; brightness-= 5) {
      leds[0] = CHSV(100, 255, brightness);
      FastLED.show();
      delayTime -= fadeDelayStepSize;
      delay(fadeDelayStepSize);
    }
  }

  loopCount++;
  if (loopCount > loopCountTotal) {
    loopCount = 0;
  }

  if (delayTime < 0) {
    delayTime = 0;
  }
  delay(delayTime);
}
