/*PIN Definations*/

void pin_defs()
{

  /*LEDs*/
  pinMode(WIFI_LED, OUTPUT);

  /*Button Pin Config*/
  pinMode(WIFI_RST, INPUT);

  /*Sensor Config*/
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}
