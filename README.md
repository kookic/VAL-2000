# VAL-2000

## The VAL-2000 is the easiest, fastest, cheapest, safest, wireless and best stepper motor motion controller. 

Precisely control a motor's distance, speed, current, and stall characteristics within minutes of receiving it. No programming experience is required. 

<img src="https://github.com/Valar-Systems/VAL-2000/blob/main/Media/VAL-2000-Overview.jpg" width="650">

## Why does it exist?

Due to the popularity of 3D printers, the costs of stepper motors have come down substantially and we belive they can be used much more extensively around the house. The board was initially designed for [Glasscalibur](https://github.com/Valar-Systems/Glasscalibur) which is an automatic window opener, but I've decided to sell it seperately as well.

#### If you want to program it yourself, you can find the code [here](https://github.com/Valar-Systems/VAL-2000/tree/main/Firmware).

#### If you want to learn how Trinamic drivers work and a deep dive into the code, please visit [this guide](https://valarsystems.com/blogs/val-2000/ultimate-guide).

### 1. Elderly & Disabled

Many windows and sliding doors are very heavy and require a substantial amount of force to move them. This board can be turned into an automatic window opener like the [Glasscalibur](https://github.com/Valar-Systems/Glasscalibur) or a sliding door opener like [this](https://youtu.be/Wihzpsax5Kg). The possibilities are endless.

### 2. Energy efficiency

Using Home Assistant, you can automate your windows to automatically close when the air conditining turns on, or to open to let the cool night air in. You can control different vents in your HVAC system as well or maybe build some exteriour shading devices that adjust with the sun. For example, the [MorningRope](https://github.com/Valar-Systems/MorningRope) can be programmed to close your blackout curtains to keep the sun from increasing your room temp.

### 3. Privacy

Convert your curtains into smart curtains. For example, set the [MorningRope](https://github.com/Valar-Systems/MorningRope) curtains to close during sunset so that no one can see inside your home.

### 4. Waking up

Wake up naturally and feel more rested with the [MorningRope](https://github.com/Valar-Systems/MorningRope) by letting the sun gently wake you. This board open your curtains for you like a natural alarm close.

## Where can I buy it?

To purchase the VAL-2000, please visit out website [here](https://valarsystems.com/products/val-2000).

## Do I need to buy one?

Absolutely not, but in the end it's much faster and cheaper to buy the board than to recreate an ESP32/TMC2209 board.

Shipping this out of the US can be expensive so it may make more sense to build one yourself. Please visit the [schematic page](https://github.com/Valar-Systems/VAL-2000/blob/main/Schematic.pdf) to build one.


## What can it do?

The VAL-2000 contains the following components in a very small package:

1. Espressif ESP32 dual-core wifi controller
2. Trinamic TMC2209 motor driver with StallGuard and StealthChop
3. Synchronous 12V to 3.3V DC/DC converter
4. Silicon Labs USB/TTL bridge
5. Two limit switch inputs
6. Two-button inputs

This combination will get you started building nearly any motion control project you can think of.
 

## Setup
Setup only takes 3 minutes and 3 steps

1. Connect any bipolar (4-wire) stepper motor
2. Connect 12V 2A+ power to terminal block
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

