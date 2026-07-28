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

[wiring diagram](./include/img/WiringDiagram.png)


## issues
* lags if sent a lot of commands too fast
