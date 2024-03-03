void settings()
{
  Serial.begin(115200);
  Serial.println("......Mission Critical.......");
  Serial.println("In circuit Testing: Board version Rev 1, Feb 2024");
  Serial.println("");
  xTaskCreatePinnedToCore(SER_TASK, "Task2", 50000, NULL, 2, &Task2_handle, 0); /*Serial Read Task*/ 
  pixels.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();            // Turn OFF all pixels ASAP

    FastLED.addLeds<WS2812, DATA_PIN, BRG>(leds, NUM_LEDS);
    FastLED.setBrightness(255);
    // Frame 1
  leds[0].setRGB(0, 0, 0);
  leds[1].setRGB(0, 0, 0);
  leds[2].setRGB(0, 0, 0);
  leds[3].setRGB(0, 0, 0);
  leds[4].setRGB(0, 0, 0);
  leds[5].setRGB(0, 0, 0);
  leds[6].setRGB(0, 0, 0);
  
}
