# P-ARM-Robotic-Arm-Project

**Authors:** Elliott Hanke & Kaitlyn Surovy  
**Course:** Kinematics and Control of Robotic Systems (EEL4664.01)

---

## Overview
This project demonstrates a 3D-printed robotic arm controlled by an Arduino microcontroller. The arm can pick up a small object (like a plastic duck) and place it back down either manually using a smartphone emulator or autonomously with stored sequences. The project showcases servo motor control, microcontroller programming, power management, and basic robotic kinematics.

---

## Assembly & Setup

### Mechanical Assembly
1. Assemble the base, shoulder, elbow, wrist, and gripper using 3D-printed parts.  
2. Mount servo motors at each joint and attach servo horns.  
3. Secure parts with screws and bolts. Use rubber bands to reduce servo load where necessary.  

### Electronics
1. Connect each servo signal wire to a specific Arduino digital pin.  
2. Connect servo power wires to the external 5V supply.  
3. Connect all grounds (Arduino and power supply) together.  

### Arduino Code
1. Open the `AutomationCode.ino` file in the Arduino IDE.  
2. The code uses a **for loop iterating through an array of strings**, each string representing a servo ID and target angle.  
3. Commands can be sent using the smartphone emulator for manual control or automated sequences.  

---

## Demo
The arm can perform pick-and-place tasks autonomously and manually. The demo video shows the robot arm transferring a plastic duck from one location to another autonomously.

---

## GitHub Repository
[https://github.com/ksurovy/P-ARM-Robotic-Arm-Project](https://github.com/ksurovy/P-ARM-Robotic-Arm-Project)

---

## References
1. Dejan, “DIY Arduino Robot Arm with Smartphone Control,” HowToMechatronics, Sep. 11, 2018. [Link](https://howtomechatronics.com/tutorials/arduino/diy-arduino-robot-arm-with-smartphone-control/)  
2. P. Corke, “Robotics Toolbox for MATLAB® release 10,” GitHub, Nov. 08, 2023. [Link](https://github.com/petercorke/robotics-toolbox-matlab)
