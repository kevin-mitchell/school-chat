#define RGB_BRIGHTNESS 64 // Change white brightness (max 255)
// note this number, 48, coresponds with the pin 48 you can see in this
// schematic: https://github.com/Freenove/Freenove_ESP32_S3_WROOM_Board_Lite/blob/main/ESP32S3_Lite_Pinout.png
// to go really deep, if you google "WS2812" (which is what the schematic says pin 48 is hooked to!) you 
// can find tons of technical details on the LED https://cdn-shop.adafruit.com/datasheets/WS2812.pdf - cool!
#define RGB_BUILTIN 48

void setup() {
  // No need to initialize the RGB LED
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RGB_BUILTIN, HIGH);  // Turn the RGB LED white
  delay(1000);
  digitalWrite(RGB_BUILTIN, LOW);  // Turn the RGB LED off
  delay(1000);

  rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0);  // Red
  delay(1000);
  rgbLedWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0);  // Green
  delay(1000);
  rgbLedWrite(RGB_BUILTIN, 0, 0, RGB_BRIGHTNESS);  // Blue
  delay(1000);
  rgbLedWrite(RGB_BUILTIN, 0, 0, 0);  // Off / black
  delay(1000);
}