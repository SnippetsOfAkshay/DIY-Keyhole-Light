# DIY Keyhole Light Testing Firmware 🧪

After soldering together a symphony of components on our PCB, it's only natural to want to see if everything is firing on all cylinders. So, buckle up and join me on this testing adventure!

## In-Circuit Testing Firmware

### Ultrasonic Sensor

First up on our testing checklist is the trusty ultrasonic sensor. This little gadget is our eyes and ears, helping us detect when someone's getting up close and personal with our door. With a few quick measurements and a bit of tinkering, we'll make sure it's primed and ready to go.

### WiFi LED

Next, let's shed some light on our WiFi status. Our handy LED indicator is like a beacon in the night, letting us know when we're connected to the digital world. A quick flicker here and there, and we'll be ready to surf the web like pros.

### WiFi Button

Ah, the WiFi button – our gateway to connectivity nirvana. With a simple press, we can initiate the magical process of connecting to the interwebs. Let's give it a few clicks and ensure it's doing its job with finesse.

### NEOPIXEL LED

Last but not least, it's time to unleash the mesmerizing glow of our Neopixel LED. This little gem is the pièce de résistance, adding a splash of color and flair to our creation. With a rainbow of hues at our fingertips, let's make sure it's ready to dazzle.

Once we've run the gamut of tests and confirmed that each component is pulling its weight, we'll be one step closer to firmware nirvana. So, grab your multimeter and your favorite testing tunes – it's time to make some magic happen!

## QUICK TIP: Uploading Firmware to ESP32

Most of the ESP32s don't have an Arduino Bootloader, which means we won't be able to directly upload the code on ESP32, for which I have made a custom connector, refer to the diagram attached in this step for connections.

1. Find the "Boot" header on your connector.
2. Press and hold "Boot."
3. While holding "Boot," press "Enable" and then release both.

I know this process is kind of annoying but bear with me guys it's gonna be worth the effort.
