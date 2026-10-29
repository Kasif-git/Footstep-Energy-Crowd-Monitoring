# Footstep-Based Power Generation with Crowd Monitoring & Surge Alert System

An IoT-based team project using an ESP32 and piezoelectric sensors to detect footsteps, monitor activity, and generate potential crowd-surge alerts through Blynk IoT.

## Project Overview

Crowded public spaces such as railway stations, college campuses, and event venues can experience sudden increases in pedestrian activity. Monitoring footstep activity can provide an additional indicator of unusual movement.

This project uses piezoelectric sensors to detect mechanical vibrations associated with footsteps. An ESP32 processes the sensor readings, counts detected footsteps, and sends monitoring data to a Blynk dashboard. A time-window-based algorithm identifies unusually high footstep activity and triggers an alert when a configured threshold is exceeded.

Footstep-based energy harvesting is a planned extension and has not yet been experimentally validated.

## Objectives

- Detect footsteps using piezoelectric sensor signals.
- Process sensor readings using an ESP32 microcontroller.
- Implement threshold-based footstep detection and step counting.
- Reduce duplicate detections using a lockout mechanism.
- Monitor footstep activity over a five-second time window.
- Display sensor readings and step counts using Blynk IoT.
- Generate alerts when footstep activity exceeds the configured threshold.
- Explore mechanical energy harvesting from footsteps as a future enhancement.

## Technology Stack

| Component | Technology |
|---|---|
| Microcontroller | ESP32 |
| Programming language | C++ (Arduino framework) |
| Sensors | Piezoelectric sensors |
| IoT platform | Blynk IoT |
| Connectivity | Wi-Fi |
| Development environment | Arduino IDE |
| Circuit prototyping | Breadboard and jumper wires |

## Hardware Prototype

The project was assembled as a physical prototype using an ESP32, piezoelectric sensing elements, a breadboard circuit, and connecting wires.

### Full Hardware Prototype

![Full hardware prototype](images/full-prototype.jpg)

*Physical prototype showing the sensor arrangement and ESP32-based monitoring circuit.*

### ESP32 and Circuit Connections

![ESP32 and circuit connections](images/esp32-circuit.jpg)

*Close-up of the ESP32 development board, breadboard, and electronic components.*

### Piezoelectric Sensor Arrangement

![Piezoelectric sensor arrangement](images/piezoelectric-sensors.jpg)

*Arrangement of piezoelectric sensing elements intended to detect mechanical vibrations associated with footsteps.*

**Note:** These photographs document the physical prototype. Actual energy-harvesting performance and generated electrical power have not yet been measured.

## How the System Works

1. **Sensor input:** Piezoelectric sensors respond to mechanical vibrations produced by footsteps.
2. **Signal acquisition:** The ESP32 reads the analog sensor signal.
3. **Footstep detection:** The firmware compares the sensor reading against a configured threshold.
4. **Step counting:** Accepted detections increment the cumulative step count.
5. **Lockout mechanism:** A lockout interval helps prevent repeated detections from a single vibration.
6. **Activity monitoring:** The firmware evaluates detected steps over a five-second window.
7. **Alert generation:** More than five detected steps within a window triggers the configured crowd-surge alert.
8. **IoT visualization:** Sensor readings, step counts, and alert information are communicated to Blynk.

## Detection Parameters

| Parameter | Configured value |
|---|---:|
| Analog sensor threshold | 4000 |
| Step lockout interval | 350 ms |
| Activity monitoring window | 5 seconds |
| Alert condition | More than 5 steps per window |
| Serial Monitor baud rate | 115200 |

These are initial firmware settings and may require calibration based on sensor sensitivity, mounting conditions, and environmental vibrations.

The alert identifies unusually high detected footstep activity. It does not directly measure the number of people present or independently establish that a stampede is occurring.

## Blynk IoT Integration

Blynk provides remote monitoring of sensor activity and configured crowd-surge alerts.

| Virtual pin / event | Purpose |
|---|---|
| V1 | Cumulative detected step count |
| V3 | Raw analog sensor reading |
| V4 | Crowd-surge alert indicator |
| `crowd_alert` | Event used to report a potential crowd surge |

The corresponding datastreams and event must be configured in the Blynk project. The monitoring and alert functionality has been tested with the prototype.

## Software Requirements

- Arduino IDE
- ESP32 board support package
- Blynk library
- Wi-Fi connectivity
- Configured Blynk IoT template and datastreams

## Setup Instructions

1. Install the Arduino IDE and ESP32 board support.
2. Install the Blynk library.
3. Configure the Blynk template, datastreams, and alert event.
4. Open `Foot_step_generation.ino` in the Arduino IDE.
5. Configure Wi-Fi credentials and the Blynk authentication token securely.
6. Connect the sensor circuit to the appropriate ESP32 input.
7. Select the correct ESP32 board and serial port.
8. Upload the firmware.
9. Open the Serial Monitor at 115200 baud.
10. Test footstep detection, step counting, and Blynk alerts.
11. Calibrate the threshold and timing parameters for the physical setup.

**Security:** Never commit Wi-Fi passwords or Blynk authentication tokens to a public repository. Keep secrets in local configuration files excluded from version control.

**Electrical safety:** Use appropriate signal conditioning and voltage protection before connecting piezoelectric elements to ESP32 inputs.

## My Contribution

**Role: ESP32 Firmware and Detection Logic**

As part of a team project, my contribution focused on:

- Implementing threshold-based footstep detection using analog sensor readings.
- Developing step-counting logic with a lockout mechanism.
- Implementing a five-second activity window and threshold-based crowd-surge detection.
- Integrating sensor readings, step counts, and alert events with Blynk IoT.

## Current Project Status

### Implemented and Tested

- Physical ESP32 and sensor prototype.
- Threshold-based footstep detection and step counting.
- Time-window-based crowd-surge alert logic.
- Blynk monitoring and alert integration.

### Planned Future Development

- Piezoelectric energy harvesting with measured electrical output.
- Rectification and energy-storage circuitry.
- Measurement of generated voltage, current, and usable energy.
- Improved filtering to reduce false detections.
- Experimental evaluation of the alert algorithm under different conditions.
- Historical activity graphs and event logging.

## Limitations

- Sensor readings may vary with mounting conditions and surface vibrations.
- Non-footstep vibrations can cause false detections.
- Footstep counts are not a direct measurement of crowd density.
- The alert threshold has not been validated as a real-world crowd-safety threshold.
- Energy generation and storage performance have not yet been experimentally verified.

This prototype is intended for educational and experimental use, not as a certified crowd-safety system.

## Future Scope

- Develop and test a piezoelectric energy-harvesting circuit.
- Integrate rectification, energy storage, and power-management components.
- Evaluate sensor calibration and filtering techniques.
- Test the detection algorithm using recorded sensor data.
- Enhance the Blynk dashboard with historical activity visualization.
- Evaluate additional sensing methods for improved crowd monitoring.

## License

Add a license after confirming the ownership and redistribution rights of all included code and components.

## Author

**Kasif Nawaz**

GitHub: [Kasif-git](https://github.com/Kasif-git)

B.Tech Electrical Engineering  
Jamia Millia Islamia, New Delhi
