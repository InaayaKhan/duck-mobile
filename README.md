# Duck Mobile – Wi-Fi-Controlled Arduino RC Car

A duck-themed RC car that is driven from any phone, tablet or laptop browser over Wi-Fi, designed as a playful, educational toy for children.

**Tech:** C++ (Arduino), ESP8266 (D1 Mini Lite), L298N motor driver, HTML/CSS

**Context:** Course project at Saarland University. I handled the hardware assembly, firmware, web interface, testing and documentation.

## How it works

The D1 Mini Lite connects to a Wi-Fi hotspot and hosts a small web server. Its control page (directional buttons, laid out with CSS flexbox) sends requests such as `/forward`, `/left` or `/stop`, and the board sets the motor driver inputs accordingly. No app needs to be installed.

## Hardware

- Microcontroller: D1 Mini Lite (ESP8266)
- Motor driver: L298N
- Four motors with wheels (one pair on each side)
- Battery pack with four AAA batteries, powering both the board and the motor driver
- Breadboard, LED power indicator, and a rubber duck on top

**Wiring:** L298N `IN1`–`IN4` are connected to D1 Mini pins `D1`–`D4`.

## Setup

1. Open `duckmobile_sourcecode.ino` in the Arduino IDE with ESP8266 board support installed.
2. Enter your Wi-Fi or phone hotspot name and password in `ssid` and `password`.
3. Upload the sketch and open the Serial Monitor to see the car's IP address.
4. Open that IP address in a browser on the same network to drive the car.

## Evaluation

Four users rated the car from 1 to 5 on functionality, intuitiveness, responsiveness, appearance and user interface. The average rating was **4.2 out of 5**.

## Limitations

- About one second of delay between a button press and the car's reaction
- One command at a time (for example, no forward and turning simultaneously)
- Range depends on the Wi-Fi signal

The project report, poster and a video presentation are included in this repository.
