/******************************************************************************
 MicroOLED_Wemos.ino
 SFE_MicroOLED Wemos Demo
 Piotr Borkowski
 2017
 https://github.com/kefasb/MicroOLED_64x48

 This sketch lights up a familiar pattern on the MicroOLED.
 It's a great way to prove you've connected everything
 correctly and that your display is in working order.

 Hardware Connections:
 We'll be using the I2C interface on the MicroOLED, though it
 also supports SPI (and a really messy parallel). If you want
 to swap in SPI, read through the comments to find out how.

 Development environment specifics:
 IDE: Sloeber 4.1
 Hardware Platform: MicroOLED Wemos Shield
 Wemos D1 Mini 3.3V/80MHz

 Note: The display on the MicroOLED is a 1.8V-3.3V device only.
 Don't try to connect a 5V Arduino directly to it! Use level
 shifters in between the data signals if you have to resort to
 a 5V board.

 Distributed as-is; no warranty is given.
 *******************************************************************************/
#include <Wire.h>  // Include Wire if you're using I2C
#include <SPI.h>  // Include SPI if you're using SPI
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_RESET 255  // Connect RST to pin 255 (req. for SPI and I2C)

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
// Declare a MicroOLED object. The parameters include:
// 1 - Reset pin: Any digital pin
// 2 - D/C pin: Any digital pin (SPI mode only)
// 3 - CS pin: Any digital pin (SPI mode only, 10 recommended)
//SpiCommunicationOled communicationSpi = SpiCommunicationOled(PIN_DC, PIN_CS); // Example SPI
I2cCommunicationOled communicationI2c = I2cCommunicationOled();
MicroOLED oled(I2cCommunicationOled, PIN_RESET);

// I2C is great, but will result in a much slower update rate. The
// slower framerate may be a worthwhile tradeoff, if you need more
// pins, though.
void setup() {
    // These three lines of code are all you need to initialize the
    // OLED and print the splash screen.

    // Before you can start using the OLED, call begin() to init
    // all of the pins and configure the OLED.
    oled.begin();
    // clear(ALL) will clear out the OLED's graphic memory.
    // clear(PAGE) will clear the Arduino's display buffer.
    oled.clear(OledClearMode::ALL); // Clear the display's memory (gets rid of artifacts)
    // To actually draw anything on the display, you must call the
    // display() function.
    oled.display();
}

void loop() {
}
