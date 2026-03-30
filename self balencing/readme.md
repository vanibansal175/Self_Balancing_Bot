# Self-Balancing Robot

This is a simple self-balancing robot built using ESP32.

the robot tries to stay upright on two wheels.  
It keeps checking its tilt and adjusts the motors to prevent falling.

---

## How it works

- The MPU6050 sensor measures the tilt of the robot  
- The ESP32 continuously reads this data  
- A PID controller calculates how much correction is needed  
- The motors move forward or backward to maintain balance  

All of this runs in a fast loop, so the robot keeps correcting itself in real time.

---

## Components used

- ESP32 
- MPU6050 (gyroscope + accelerometer)  
- Motor driver (L298N or similar)  
- 2 DC motors  
- Battery  

---

## Features

- real-time angle tracking  
- PID-based balancing  
- smooth motor control  
- basic filtering for improved stability  

---

## Things to know

- PID values need to be tuned based on your setup  
- The robot may not balance properly at first, which is expected  
- This project is mainly for learning and experimentation  

---

## Final note

This project is a good starting point for understanding control systems and robotics.  
It may take some time to get stable results, but the process is useful and rewarding.

---

## Photos

![alt text](image.png)