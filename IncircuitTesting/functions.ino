void menu()
{
  Serial.println("");
  Serial.println("    --- MENU ---   ");
  Serial.println("");
  Serial.println("1.  WiFi LED TEST: ");
  Serial.println("2.  Setup Button TEST: ");
  Serial.println("3.  Distance Sensor TEST: ");
  Serial.println("4.  RGB LED TEST: ");
  Serial.println("");
}

void _led()
{
  for(int i = 0; i <4; i++)
  {
    digitalWrite(WIFI_LED, HIGH);
    vTaskDelay(250 / portTICK_PERIOD_MS);
    digitalWrite(WIFI_LED, LOW);
    vTaskDelay(250 / portTICK_PERIOD_MS);
  }
}
 void IRAM_ATTR wifi_interrupt_handle()
 {
  button_time = millis();
  if (button_time - last_button_time > 250)
  {
    Serial.println("WiFi Setup button is pressed.");
    last_button_time = button_time;
  }
 }

void Dist_Test()
{
  for(int i = 0; i < 26; i++)
  {
    long duration, cm;
    digitalWrite(TRIG, LOW);
    vTaskDelay(5 / portTICK_PERIOD_MS);
    digitalWrite(TRIG, HIGH);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    digitalWrite(TRIG, LOW);
    pinMode(ECHO, INPUT);
    duration = pulseIn(ECHO, HIGH);
    cm = (duration/2) / 29.1;
    Serial.print("Distance = ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    vTaskDelay(250 / portTICK_PERIOD_MS);
  }
}

void _RGB()
{
  pixels.setBrightness(30);
  for(int i=0; i<7; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
    for(int i=0; i<7; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
    for(int i=0; i<7; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
  for(int i=7; i>0; i--)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
  pixels.clear();
  pixels.show();
}
