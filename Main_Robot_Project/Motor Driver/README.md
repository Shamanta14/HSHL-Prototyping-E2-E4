##Tinkercad Motor Driver Test:

Testing the following components together:

-> Two gear motors -> One slide switch -> One Motor Driver(L293D)

The system is powered using a 9V battery with a slide switch for power control.

The Enable1&2 and Enable3&4 pins of motor driver are connected to Arduino pins 6 and 9. Because they are PWM pins which can be used to control the motor speed.

The Input pins 1,2,3 and 4 are connected to Arduino pins 3,2,12 and 13 respectively. These Input pins can be used to control the motor direction.

The purpose of this testing is to verify that the motor driver can control the speed and direction of the gear motors, as well as stop and start them flexibly.
