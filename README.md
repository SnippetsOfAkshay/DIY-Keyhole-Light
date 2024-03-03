# DIY Keyhole Light 🔑💡

Ever found yourself fumbling for keys in the dark? I did too, until I decided to shed some light on the situation. Enter the DIY Door Key Light, a bright idea born from frustration and crafted with creativity. In this post, I'll guide you through the process of building your own illuminating solution using ESP32 microcontroller. Get ready to light up your entryway and say goodbye to dark door dilemmas!

## Components 🛠️

### 1. Main Controller: ESP32

I went with the ESP32 microcontroller because it seemed like the perfect brain for my project. It's got this awesome dual-core processor and built-in WiFi and BLE, which felt like overkill but also kinda cool. Plus, it plays nice with the Arduino IDE, so programming it was a breeze. Oh, and the fact that it supports BLE means I can add fancy features later on if I want to control it from my phone or something.

### 2. LED: WS2812B

When it came to lighting up the keyhole, I knew I needed something bright and colorful. That's where the WS2812B LED, or Neopixel as some folks call it, came in. These little guys are like magic – each one can be controlled individually, so I can make all sorts of cool patterns and effects. Another thing about Neopixels is that they're popular, and many people have written drivers for them, so I don't have to worry about it. Plus, they're super efficient, which is perfect for running off a battery.

### 3. Wireless Connectivity: WiFi Support

I decided to throw in WiFi support because, well, why not? It opens up a whole world of possibilities for future upgrades like OTA. I added a special button for WiFi setup and an LED indicator to make connecting a breeze. Who knows, maybe I'll integrate it with my smart home setup down the line or control it from my phone when I'm feeling lazy.

### 4. Sensor: Ultrasonic

Originally, I thought about using a light sensor, but they can be a bit finicky, especially in different lighting conditions. So, I went with an ultrasonic sensor instead. It's reliable and accurate, which means it'll always know when someone's getting close to the door. No more fumbling around in the dark trying to find the keyhole!

### 5. Power Source: 18650 Lithium-Ion Battery

For power, I went with a trusty old 18650 lithium-ion battery. They're rechargeable, so I don't have to worry about constantly buying new batteries. Plus, they've got plenty of juice (around 3000mAh) to keep the light running for a long time. I hooked it up to a TP4056 charge control module, so recharging is as easy as plugging in a USB-type C cable.

## Design and Development 🎨💻

With these components handpicked and tailored to my needs, the DIY Door Key Light isn't just a solution to my dimly lit doorway – it's a reflection of my creativity and ingenuity.

## In-Circuit Testing Firmware 🧪

After soldering together a symphony of components on our PCB, it's only natural to want to see if everything is firing on all cylinders. So, buckle up and join me on this testing adventure!

## Main Firmware 💻

We want our Door Key Light to greet guests with a mesmerizing display before guiding them to the keyhole with a steady glow. To achieve this, we'll need a custom animation pattern that captures the essence of hospitality and functionality.

Animation: To bring our vision to life, I turned to the FASTLED animator website. With its intuitive interface, I whipped up a custom green animation using frame-by-frame design. By specifying the number of LEDs, frames, and frames per second, I tailored the animation to fit our Door Key Light perfectly.

Fine-Tuning the Parameters: Once the animation was complete, it was time to fine-tune the parameters for our specific LED setup. With a few tweaks and adjustments, I ensured that every pixel would dance to the beat of our carefully choreographed animation.

Proximity: Now, let's talk distance. Using a combination of low, high, and low trigger pulses sent at precise intervals to the sensor's trigger pin, we can calculate the distance to the nearest object. With a bit of math and the speed of sound equation, we're able to pinpoint the distance in centimeters.

Adding Deep Sleep Capability: But wait, there's more! We're not just about dazzling animations – we're also all about efficiency. That's why we're incorporating deep sleep capability using the ESP-IDF's handy functions. After waking up, computing the distance, and performing our magic, we'll put the microcontroller to sleep for a set period. Talk about energy-saving smarts!

Dynamic Functionality: With the groundwork laid, our code will dynamically respond to the user's proximity. If the distance is within the desired range, the animation will kick into gear, setting the stage for a warm welcome. But if things get a little too close for comfort, we'll switch to a static white light, guiding guests safely to the keyhole.

With each line of code, we're not just creating a Door Key Light – we're crafting an experience. So buckle up, folks. The journey to illumination is about to get a whole lot brighter!
