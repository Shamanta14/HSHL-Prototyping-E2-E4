## Track following robot.
-> Battery-powered system with a slide switch.

-> PWM (Pulse Width Modulation) Speed Control using analogWrite() for the Gearmotor speed.

-> Two Ultra Sonic Sensor detects the presence of an obstacle within a specified threshold distance.

## Detection threshold 
   Any object detected at or below the specified threshold distance will be considered as "Detected".

   Else "Not Detected".

->The Two IR sensor detect the presence of the track.

## IR sensor reading 

   LOW (0) when detecting black track

   HIGH (1) when detecting white surface

## System Behaviour 

-> The robot moves forward only when it is on the track and there is no obstacle ahead.

-> If the robot moves away from the track, it automatically self-corrects its position

   and continues moving along the track.

-> If an obstacle is detected ahead within the threshold distance, the robot stops moving.


## Bill of material


| Component                    |Quantity |
|------------------------------|----------|
| Arduino Uno                  | 1        |
| Hobby Gearmotor              | 2        |
| IR Sensor                    | 2        |
| Ultrasonic Sensor (4‑pin)    | 2        |
| 9V Battery                   | 1        |
| Slide Switch                 | 1        |


 ## Repository Structure

| Folder/File             | Description                                                  |
|--------------------------|--------------------------------------------------------------|
| Assembled Parts          | Mechanical assembly files for robot chassis                 |
| Motor Driver             | Code for PWM motor control                                  |
| Sensors Code Function    | Functions for IR,ultrasonic sensors and motor.                     |
| Tinkercad_circuitwiring  | Circuit wiring diagrams                                     |
| Code.cc                  | Main Arduino logic implementation                           |
| Pin_Connections.h        | Pin mapping for sensors and motors                          |
| README.md                | Project documentation                                       |




