Autonomous Electric Car (Line Follower)

🚗 What is it?

A hardware-software integration project featuring an autonomous robotic car. The vehicle is capable of tracking lines using infrared sensors, being remote-controlled via Bluetooth, and calculating the shortest path to a destination using mathematical algorithms.

🛠️ Technologies Used

Languages: C, VHDL

Hardware: Raspberry Pi, Basys 3 FPGA, L298N Motor Driver, QTR-8RC IR Sensor Array

Communications: UART, Bluetooth (PmodBLE)

OS: Linux (Lubuntu)

✨ Key Features

Line Tracking Logic: Continuous feedback loop reading IR sensors to adjust motor speeds and steer the car.

Shortest Path Algorithm: Implementation of the Floyd-Warshall algorithm in C to compute optimal navigation routes across a mapped grid.

FPGA Remote Control: A VHDL-based state machine on a Basys 3 board that transmits control signals over Bluetooth to the Raspberry Pi.
