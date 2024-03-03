/* Copyright: Akshay Momaya for Mission Critical.

   Disclaimer of Warranty!
   This Work is provided "as is". Any express or implied warranties, including but not limited to, the implied warranties of merchantability and fitness for a particular purpose are disclaimed.In no event shall the Mission Critical be liable for any direct, indirect, incidental,special, exemplary or consequential damages (including, but not limited to, procurement of substitute goods or services, loss of use, data or profits, or business interruption) however caused and on any theory of liability, whether in contract, strict liability, or tort (including negligence or otherwise) arising in any way out of the use of this Work, even if advised of the possibility of such damage. The User of this Work agrees to hold harmless and indemnify the Mission Critical, its agents and employees from every claim or liability (whether in tort or in contract), including attorneys' fees, court costs, and expenses, arising in direct consequence of Recipient's use of the item, including but not limited to,claims or liabilities made for injury to or death of personnel of User or third parties, damage to or destruction of property of User or third parties,infringement or other violations of intellectual property or technical data rights. Nothing in this Work is intended to constitute an endorsement, explicit or implied, by Mission Critical of any particular manufacturer's product or service.

   Firmware Usecase:
   To test All the Peripherals connected to ESP32 of the SMART KEY ILLUMINATION (board REV1, FEB 2024)
   
   Written by Akshay Momaya :: Date: 02/18/2024

   ESP32
   https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32d_esp32-wroom-32u_datasheet_en.pdf

   Refrence to Usable GPIOs of ESP32
   https://randomnerdtutorials.com/esp32-pinout-reference-gpios/

   VERSION Details:
   ESP32 Version: v2.0.13 (Check in board manager).
*/

/*Libraries.*/
#include <FastLED.h>

/* Private Defines */
#define NUM_LEDS 7
#define DATA_PIN 13
#define MAX_FRAMES 7
#define uS_TO_S_FACTOR 1000000ULL  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  2           /* Time ESP32 will go to sleep (in seconds) */


/*Pin Definations*/
/*Buttons*/
#define WIFI_RST GPIO_NUM_12 

/*SENSORS*/
#define TRIG GPIO_NUM_5
#define ECHO GPIO_NUM_18

/*LEDs*/
//#define RGB_DATA GPIO_NUM_13  
#define WIFI_LED GPIO_NUM_2


/*Variables*/
CRGB leds[NUM_LEDS];
int frameIndex = 0;
long duration, cm;

int nextFrameIndex() 
{
  if (frameIndex < MAX_FRAMES - 1) 
  {
      return frameIndex + 1;
    } 
  else 
  {
      return 0;
    }
}

void setup() 
{
    /*LEDs*/
  pinMode(WIFI_LED, OUTPUT);

  /*Button Pin Config*/
  pinMode(WIFI_RST, INPUT);

  /*Sensor Config*/
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  
  Serial.begin(115200);
  vTaskDelay(10 / portTICK_PERIOD_MS);
  
  Serial.println("......Mission Critical.......");
  
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
  FastLED.clear();
  FastLED.show();
}

void loop() 
{
  /* Checks the Distance */
  Dist_Test();                  
  
  /* First Situation which is greeting - led animation*/
  if( cm < 70 && cm > 30 )
  {
    //EVERY_N_MILLISECONDS(130)
    EVERY_N_MILLISECONDS(40)  
    {
        frameIndex = nextFrameIndex();
        setColors();
    }
    FastLED.show();
  }

  /* Second situation where the light should be constant white */
  else if(cm < 30 && cm > 2 )
  {
      FastLED.setBrightness(255);
      leds[0].setRGB(255, 255, 255);
      leds[1].setRGB(255, 255, 255);
      leds[2].setRGB(255, 255, 255);
      leds[3].setRGB(255, 255, 255);
      leds[4].setRGB(255, 255, 255);
      leds[5].setRGB(255, 255, 255);
      leds[6].setRGB(255, 255, 255);
      FastLED.show();
      Serial.flush();
      esp_sleep_enable_timer_wakeup(10 * uS_TO_S_FACTOR);
      esp_deep_sleep_start();
  }

  /* this is out of range mode where Uc will sleep*/
  else if(cm > 100)
  {
    Serial.flush();
    esp_sleep_enable_timer_wakeup(2 * uS_TO_S_FACTOR);
    esp_deep_sleep_start();
  }
  else
  {
    FastLED.clear();
    FastLED.show();
  }
}

/* Animation Function*/
void setColors() 
{
    switch (frameIndex) 
    {
    case 0:
      leds[0].setRGB(38, 255, 0);
      leds[1].setRGB(38, 255, 0);
      leds[2].setRGB(38, 255, 0);
      leds[3].setRGB(38, 255, 0);
      leds[4].setRGB(38, 255, 0);
      leds[5].setRGB(38, 255, 0);
      leds[6].setRGB(38, 255, 0);
      break;
    case 1:
      leds[3].setRGB(125, 125, 125);
      break;
    case 2:
      leds[2].setRGB(125, 125, 125);
      leds[4].setRGB(125, 125, 125);
      break;
    case 3:
      leds[1].setRGB(125, 125, 125);
      leds[5].setRGB(125, 125, 125);
      break;
    case 4:
      leds[1].setRGB(38, 255, 0);
      leds[5].setRGB(38, 255, 0);
      break;
    case 5:
      leds[2].setRGB(38, 255, 0);
      leds[4].setRGB(38, 255, 0);
      break;
    case 6:
      leds[3].setRGB(38, 255, 0);
      break;

    }
}


/* Distance Function*/
void Dist_Test()
{
    digitalWrite(TRIG, LOW);
    vTaskDelay(5 / portTICK_PERIOD_MS);
    digitalWrite(TRIG, HIGH);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    digitalWrite(TRIG, LOW);
    
    //pinMode(ECHO, INPUT);
    
    duration = pulseIn(ECHO, HIGH);
    cm = (duration/2) / 29.1;
    
    Serial.print("Distance = ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    vTaskDelay(30 / portTICK_PERIOD_MS);
}
    
