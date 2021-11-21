# EMBSYS 310
# ASSIGNMENT 01
# Problem 1. Embedded device example

# Embedded device example:

## Engine Management System

This system would work my monitoring an array of sensor
inputs such as:
1) Rotational position of crankshaft
2) velocity of rotation of crankshaft
3) Vacuum of intake manifold
4) Exaust gas composition
5) Engine temperature


Based on sensor input, algorithms would define the outputs necessary to control actuator actions required for proper engine function:
1) Fuel injection timing/control(metering of fuel to engine in the             exact quantity required).
2) Opening/closing of Input/Exhaust valves
3) Ignition System Timing

## Challenges

**Throughput**
System must respond in real-time to a constant stream of input sensor information in order to provide control signals to engine actuators at precise times in a specific order.


**Response**
Sensor input information must be processed quickly so that output signals to actuators occur at the precise time required.

**Reliability**
This system would need to work perfectly all the time as the consequences could be poor engine performance or even catastrophic engine failure.

**Testability**
Testing should probably occur with an external computer providing
virtual engine simulation that mimics engine sensors and corresponding actuator actions. Initial development could be rather expensive if you performed test with real engines, and kept blowing them up.
