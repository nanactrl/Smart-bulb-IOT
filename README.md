# Smart Home Smart Bulb IoT Project

## Overview
This project is an IoT-based smart bulb system that connects to the Mobius server, which supports the oneM2M standard for IoT interoperability. The smart bulb is controlled using an Android phone app, enabling users to manage the bulb remotely. The ESP32 microcontroller is chosen for this project because it integrates both Wi-Fi and Bluetooth connectivity, providing flexible and reliable communication options for controlling the smart bulb and enhancing overall device performance.

## Features
This setup utilizes a 5V relay module for appliance control and an external 7-12V breadboard power supply for rail stability, interfaced via a custom Bluetooth Android dashboard.
<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/ecf41c3f-2637-4a45-85a1-7365f7e7599b" />

- Remote control of smart bulbs via Android phone
- Adjustable brightness and on/off switching
- Scheduling functionality for automated control
- Real-time status updates from bulbs
- User-friendly interface for easy management

# Smart Bulb Diagram
<img width="1280" height="865" alt="image" src="https://github.com/user-attachments/assets/e81850cb-9f8c-4cce-9f20-1df5fa8229ab" />
*Diagram showing how the smart bulb, microcontroller, and other hardware communicate.*


## Hardware Used
- ESP32 microcontroller
- Bulb
- Power Supply
- Jumper Wire
- Usb Cable
- Relay Module
- Breadboard
- Android phone
  
## Software Stack
- Arduino IDE 
- Arduino Bluetooth control
- Mobius
