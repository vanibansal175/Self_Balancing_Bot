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

## Why I made it?

- it is something i want to make because i think balencing a bot on two wheels is somewhat challenging and i never did this project before so i want to do it.

---
## Photos

![alt text](image.png)
