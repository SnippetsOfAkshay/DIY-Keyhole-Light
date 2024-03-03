void SER_TASK(void *pvParameters)  //CLI Information print.
{
  (void) pvParameters;
  menu();
  for (;;)
  {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    clid();
  }
}


void clid()
{
  if (Serial.available() > 0)
  {
    long int inData = Serial.parseInt();

    /* Tests */
    if (inData == 1)
    {
      Serial.println("1.  WiFi LED TEST: ");
      Serial.println("");
      _led();
      Serial.println("have a look at all the LEDs, if any LED is not working, check connections");
      Serial.println("");
      menu();
      Serial.println("");
    }
    if(inData == 2)
    {
       Serial.println("2.  Setup Button TEST: ");
       Serial.println("");
       attachInterrupt(WIFI_RST, wifi_interrupt_handle, RISING);
       vTaskDelay(15000/portTICK_PERIOD_MS);
       detachInterrupt(WIFI_RST);
       menu();
      Serial.println("");
    }
    if(inData == 3)
    {
      Serial.println("3. Distance Sensor TEST: ");
      Serial.println("");
      Dist_Test();
      menu();
      Serial.println("");
    }
    if(inData ==4)
    {
        Serial.println("4.  RGB LED TEST: ");
        _RGB();
        Serial.println("");
        menu();
       Serial.println("");
      }
  }
}
