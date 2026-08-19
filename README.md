# bt carduino

an arduino powered 4 wheel bluetooth controlled car. learning hardware by building fun projects.

## hardware requirements
* - Arduino Uno (R3)
* - L298N Dual H-Bridge Motor Driver
* - HC-05 Bluetooth Module
* - 3x 18650 Li-ion Batteries
* - 4x DC BO Motors

## controls

connect via any Bluetooth Serial Terminal app and use these keys:

| action | code |
| :--- | :--- |
| **Forward** | `F` |
| **Backward** | `B` |
| **Turn Left** | `L` |
| **Turn Right** | `R` |
| **Stop** | `S` |
|[*WILL ADD IN NEAR FUTURE*]|..|
| **Honk Horn** | `H` | 

## picss

<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/4279cc66-2833-4ab6-9b43-248bca51e422" />
<img width="900" height="1600" alt="image" src="https://github.com/user-attachments/assets/7e69a4fd-e85d-4994-8a69-eace5bd08995" />

## basic wiring diagram:

<img width="1355" height="937" alt="WiringDiagram" src="https://github.com/user-attachments/assets/f7f07d7d-50be-462f-939a-4be662940013" />


## flashing instructions [platformIO]
1. Add the PlatformIO extension to vscode and open this repo folder in vscode.
2. Connect the Arduino to your PC.
3. Open the PlatformIO terminal and type ```pio run``` to compile the code.
4. To upload it, type ```pio run --target upload``` 

## BOM

| reference | value | datasheet | footprint | qty | purchase link |
| :--- | :--- | :--- | :--- | :---: | :--- |
| ARDUINO UNO REV3 | ATmega328P | [Datasheet](https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf) | Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical | 1 | [Link](https://store.arduino.cc/products/arduino-uno-rev3/) |
| M1, M2, M3, M4 | BO_MOTOR | | | 4 | [Link](https://www.amazon.in/SP-Electron-Reinforced-Robotics-Projects/dp/B0H66912XV/ref=sr_1_5?sr=8-5) |
| R1 | 3.2k | | | 1 | |
| R2 | 47k | | | 1 | |
| U1 | HC-05 | [Datasheet](https://components101.com/sites/default/files/component_datasheet/HC-05%20Datasheet.pdf) | HC-05:XCVR_HC-05 | 1 | [Link](https://www.amazon.in/HC-05-Bluetooth-Module-10g/dp/B00X86U4RW) |
| U2 | L298N | [Datasheet](http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00000240.pdf) | Package_TO_SOT_THT:TO-220-15_P2.54x5.08mm_StaggerOdd_Lead4.58mm_Vertical | 1 | [Link](https://www.amazon.com/L298N-Motor-Driver-Controller-Board/dp/B0D95GBYQF) |
| WHEELS | | | | 4 | |

## issues
* lags if sent a lot of commands too fast
