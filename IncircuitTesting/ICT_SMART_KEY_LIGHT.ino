
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

/*Libraries*/
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>

/*RTOS Unicore Setup*/
#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

/*RTOS Task Handlers*/
TaskHandle_t Task2_handle;

/*Pin Definations*/
/*Buttons*/
#define WIFI_RST GPIO_NUM_12 

/*SENSORS*/
#define TRIG GPIO_NUM_5
#define ECHO GPIO_NUM_18

/*LEDs*/
#define RGB_DATA GPIO_NUM_13  
#define WIFI_LED GPIO_NUM_2


/*Variables used by Interrupt*/
unsigned long button_time = 0;  
unsigned long last_button_time = 0; 

/*Other Configs*/
Adafruit_NeoPixel pixels(7, RGB_DATA, NEO_GRB + NEO_KHZ800);

#define NUM_LEDS 7
#define DATA_PIN 13
#define MAX_FRAMES 30

CRGB leds[NUM_LEDS];
int frameIndex = 0;

int nextFrameIndex() 
{
  if (frameIndex < MAX_FRAMES - 1) 
  {
      return frameIndex + 1;
    } else {
      return 0;
    }
}

void setup() 
{
  pin_defs();
  settings();
}

void loop() 
{
  //My code wont ever reach this stage!
}
