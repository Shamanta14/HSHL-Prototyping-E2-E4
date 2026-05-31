## Sensor and motor testing.

This folder contains the individual test programs used to verify the correct operation of each sensor and actuator before integrating them into the full autonomous robot system.Testing each component separately helps identify wiring issues, incorrect pin mappings, faulty sensors, or logic errors early in the development process.

## Components tested individually 
-> Two IR sensors

-> Two gear motors

-> Two ultrasonic sensors

## power setup 

The system is powered using a 9V battery with a slide switch for power control.

The system powers on when the switch is closed.

The purpose of this testing is to identify and eliminate bugs or issues related to each individual sensor and component before integrating the complete system.

## Repository Structure

| Folder/File Name     | Description                                      |
|-----------------------|--------------------------------------------------|
| GearMotor            | Contains code and pin connections for gear motors |
| IR_Sensor            | Contains IR sensor code and pin mapping           |
| Ultra_Sonic_Sensor   | Contains ultrasonic sensor code and pin mappings  |
| README.md            | Documentation describing sensor and motor setup   |

