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


| ##Component                  | ##Quantity |
|------------------------------|----------|
| Arduino Uno                  | 1        |
| Hobby Gearmotor              | 2        |
| IR Sensor                    | 2        |
| Ultrasonic Sensor (4‑pin)    | 2        |
| 9V Battery                   | 1        |
| Slide Switch                 | 1        |

