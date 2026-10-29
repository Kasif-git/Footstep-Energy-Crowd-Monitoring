# Footstep-Based Power Generation & Crowd Surge Monitoring

An IoT-based team project that combines footstep detection, real-time sensor monitoring, and crowd-surge alerts using an ESP32, piezoelectric sensor, and Blynk IoT platform.

## Overview

Sudden increases in pedestrian activity can create safety concerns in crowded environments such as railway stations, campuses, public venues, and event spaces.

This project explores a sensor-based approach to monitoring footstep activity and identifying potential crowd surges. An ESP32 processes signals from a piezoelectric sensor, counts detected footsteps, and transmits monitoring data to a Blynk dashboard. A threshold-based algorithm evaluates activity over a five-second window and triggers an alert when the configured limit is exceeded.

Footstep-based energy harvesting is a planned extension of the project and has not yet been experimentally validated.

## Objectives

- Detect footsteps using piezoelectric sensor signals.
- Process sensor readings using an ESP32.
- Count footsteps using threshold-based peak detection and a lockout interval.
- Monitor footstep activity within configurable time windows.
- Display sensor readings and step counts through Blynk.
- Trigger a remote notification when footstep activity exceeds the configured threshold.
- Explore mechanical energy harvesting from footsteps as a future enhancement.

## Technology Stack

- **Microcontroller:** ESP32
- **Sensor:** Piezoelectric sensor
- **Programming language:** C++ (Arduino framework)
- **IoT platform:** Blynk IoT
- **Connectivity:** Wi-Fi
- **Development environment:** Arduino IDE

## Hardware Components

- ESP32 development board
- Piezoelectric sensor
- Sensor interface and appropriate signal-conditioning components
- Connecting wires and breadboard or prototype assembly
- USB cable and suitable power supply

The precise sensor interface and circuit configuration should match the physical prototype. Appropriate voltage protection and signal conditioning are necessary before connecting a piezoelectric element to an ESP32 input.

## How It Works

1. **Sensor acquisition:** The piezoelectric sensor responds to mechanical vibration associated with footsteps.
2. **Footstep detection:** The ESP32 reads the analog sensor signal and compares it with a configured threshold.
3. **Duplicate-event reduction:** A 350 ms lockout interval helps prevent repeated detections from the same vibration.
4. **Step counting:** Each accepted detection increments the total step count.
5. **IoT monitoring:** Sensor readings and the cumulative count are sent to Blynk.
6. **Activity evaluation:** The firmware evaluates the number of detected steps within each five-second interval.
7. **Alert generation:** More than five detected steps in a window triggers the configured crowd-surge alert.

## Detection Parameters

| Parameter | Configured value |
|---|---:|
| Analog detection threshold | 4000 |
| Step lockout interval | 350 ms |
| Activity monitoring window | 5 seconds |
| Alert condition | More than 5 steps per window |
| Serial Monitor baud rate | 115200 |

These values are initial firmware settings and should be calibrated for the sensor, mounting arrangement, and deployment environment.

The alert indicates unusually high detected footstep activity. It does not independently establish actual crowd density or guarantee that a dangerous situation is occurring.

## Blynk IoT Integration

The firmware uses Blynk to monitor sensor activity and communicate potential crowd-surge events.

| Virtual pin / event | Function |
|---|---|
| V1 | Cumulative detected step count |
| V3 | Raw analog sensor reading |
| V4 | Crowd-surge alert indicator |
| `crowd_alert` | Blynk event for a potential crowd surge |

The corresponding datastreams and event must be configured in the Blynk project. The firmware has been tested with the Blynk monitoring and alert functionality.

## Setup Instructions

1. Install the Arduino IDE.
2. Install ESP32 board support and select the appropriate ESP32 board.
3. Install the Blynk library.
4. Create a Blynk template and configure the required datastreams and event.
5. Open `Foot_step_generation.ino`.
6. Configure Wi-Fi and Blynk credentials securely without committing them to the repository.
7. Connect the piezoelectric sensor through an appropriate, protected input circuit.
8. Upload the firmware to the ESP32.
9. Open the Serial Monitor at 115200 baud.
10. Test footstep detection and verify sensor readings, step counts, and Blynk alerts.
11. Calibrate the threshold and lockout settings for the physical setup.

## Project Contribution

**My contribution: ESP32 firmware and detection logic**

- Implemented threshold-based footstep detection using analog sensor readings.
- Developed step-counting logic with a lockout interval to reduce duplicate detections.
- Implemented a five-second activity window and threshold-based crowd-surge alert logic.
- Integrated sensor readings, step counts, and alert events with Blynk IoT.

This was a team project involving a physical prototype. The contribution above describes my individual area of responsibility.

## Current Status

**Implemented and tested:**
- Physical ESP32 and sensor prototype
- Threshold-based footstep detection and step counting
- Time-window-based alert logic
- Blynk monitoring and alert integration

**Planned / not yet validated:**
- Mechanical energy harvesting and measured power output
- Energy storage and power-management circuitry
- Experimental validation of the alert threshold against actual crowd conditions

## Limitations

- Sensor thresholds may require adjustment for different surfaces and mounting conditions.
- Vibrations unrelated to footsteps can cause false detections.
- A footstep count is a proxy for activity, not a direct measurement of the number of people present.
- The five-second alert rule has not been established as a validated safety threshold.
- Energy generation, storage efficiency, and usable electrical output have not yet been experimentally verified.

## Future Improvements

- Develop and test a piezoelectric energy-harvesting circuit with suitable rectification and storage.
- Measure generated voltage, current, and usable energy under controlled conditions.
- Improve signal filtering and footstep classification.
- Evaluate the alert algorithm against recorded sensor data.
- Add historical activity graphs and event logging to the dashboard.
- Explore adaptive thresholds and additional sensing methods for more reliable crowd monitoring.

## Safety and Security

- Do not commit Wi-Fi passwords, Blynk authentication tokens, or other secrets.
- Store credentials in a local configuration file excluded through `.gitignore`, or use another secure configuration method.
- Use appropriate electrical protection for sensor inputs.
- Treat the prototype as an experimental monitoring system, not a certified crowd-safety solution.

## License

Specify a license only after confirming that the project code and any reused components can legally be distributed under the chosen terms.
