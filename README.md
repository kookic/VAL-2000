# VAL-2000

## The VAL-2000 is the easiest, fastest, cheapest, safest, and wireless way to spin a stepper motor. 

<img src="https://github.com/Valar-Systems/VAL-2000/blob/main/Media/VAL-2000-Overview.jpg" width="650">

You can precisely control a motor's distance, speed, current, and stall characteristics within minutes of receiving it. No programming experience is required. 

This is the exact board used in [Glasscalibur](https://github.com/Valar-Systems/Glasscalibur).

If you want to program it yourself, you can find the code [here](/VAL-2000/tree/main/VAL-2000).

The VAL-2000 contains the following components in a very small package:

1. Espressif ESP32 dual-core wifi controller
2. Trinamic TMC2209 motor driver with StallGuard and StealthChop
3. Synchronous 12V to 3.3V DC/DC converter
4. Silicon Labs USB/TTL bridge
5. Two limit switch inputs
6. Two-button inputs

 

## Setup
Setup only takes 3 minutes and 3 steps

1. Connect any bipolar (4-wire) stepper motor
2. Connect a 12V 2A+ power cord (2.1mm x 5.5mm barrel connector)
3. Open a browser and connect via WiFi

To learn how to program the TMC2209. please visit the [Ultimate Guide](https://valarsystems.com/blogs/val-2000/ultimate-guide) to programming it.

If you want to program it we've made it extremely simple to do so. Download the source code in the VAL-2000 folder and plug in a USB cord to quickly flash your new firmware. 

To view the schematic, click [here](https://github.com/Valar-Systems/VAL-2000/blob/main/Schematic.pdf).

 
## WiFi Control
The VAL-2000 is already loaded with firmware to get you going right away. 

Simply connect to it via WiFi and get the motor going right away.


## Detailed Features

### Trinamic TMC2209/2226
The actual stepper driver is a TMC2226 which IS the TMC2209 in a larger form factor that can handle more current and better dissipate heat. I will refer to is as the TMC2209.

The Trinamic TMC2209 is one of the best stepper motor drivers on the market. It is very feature-rich while being affordable. 

Easily program from the ESP32 via UART

Includes the extremely popular and useful StallGuard feature. Easily set it to stop whenever the force on your motor exceeds a certain force. This makes it very safe to use for all types of projects. 

### Customizable Stepper Motor Connector
You will receive a 4-pin screw terminal AND a 4-pin JST XH plug. You can solder either to your board.

### Micro USB Port
Easily flash the firmware using the micro USB port and CP2104 USB-to-UART Bridge. We've also included the automatic flashing circuit so you don't have to open up your device and press G0 and Reset. Everything is automatic.

### Two Buttons
Sometimes it's nice to press a button to open or close your device. That's why we've included two buttons to do just that.

### Dual Sensor Connectors
If you want to connect two limit switches or any other type of sensor, we've included 6 pins for that. You will get access to two GPIO, two GND, and two 3.3V pins to make it simple to connect. 

### PTC Thermistor
In the unlikely event of an overcurrent, we've added a PTC thermistor for added safety.

### Stepper Motor
Connect any 4-Wire Bipolar stepper motor

### On-Board Voltage Regulator
The Texas Instruments TPS62162DSGR 1A Synchronous DC/DC converter provides ultra-high efficient voltage regulation in a compact design. 

### ESP32-WROOM-32D
This dual-core ESP32 sits at the heart of the board. Its low-cost to high-performance ratio is unlike any other. It provides stepper motor control as well as maintains the wireless connection for WiFi and MQTT access.

![alt text](/Media/VAL-2000-angle.jpg)

