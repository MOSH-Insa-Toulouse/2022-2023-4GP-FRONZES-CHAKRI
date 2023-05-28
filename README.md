# 2022-2023-4GP-FRONZES-CHAKRI
## General description

During the UF “Du capteur au banc de test” (“From sensor to test bench”), a 4th year course in the Physics Engineering Department at INSA Toulouse, we produced a graphite-based strain gauge that is low-tech, low-cost and transportable. We used an Arduino Uno board, a PCB, a Bluetooth module, an OLED screen, a flex sensor and designed an application using MIT App Inventor.

## Table of contents
* [Deliverables](#deliv)
* [Components](#comp)
* [LTSpice](#spice)
* [PCB Shield](#pcb)
* [Application](#app)
* [Arduino](#ard)
* [Test bench](#bench)
* [Datasheet](#data)
* [Improvements](#improv)

<div id='deliv'/>

## Deliverables

The deliverables of this project are the following:

* An example of the analogue circuit to which the sensor can be connected, produced using LTSpice software
* A PCB Shield
* An Arduino code to transmit the measurements made by the sensor to an OLED screen and a Bluetooth module, connected to an Android system
* An APK application
* A test bench
* A datasheet

<div id='comp'/>

## Components

The components required to build the analogue circuit are listed below:

* Arduino Uno
* LTC1050 amplifier
* HC05 Bluetooth module
* 128x64 OLED screen
* GT055 rotary encoder
* Paper sensor
* Resistors: 1 of 1 kΩ, 1 of 10 kΩ, 1 of 39 kΩ, 2 of 100 kΩ
* Capacitors: 2 of 100 nF, 1 of 1 F

<div id='spice'/>

## LTSpice

We used the LTSpice software to simulate the analogue circuit in which our sensor is integrated. The signal is filtered and amplified by an LTC1050.

![spice](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/LTSpice/Circuit%20LTSpice.PNG)

This circuit can be found in the [LTSpice] folder (https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/tree/main/LTSpice).

<div id='pcb'/>

## PCB Schield

To design the PCB, we drew the electronic schematic and its components with KiCad, in a Schematic file. We had to connect the pins of the components to those of the Arduino and to choose their footprints.

![schematic](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/KiCad/KiCad_sch%C3%A9matique.png)

Secondly, we placed the components on the PCB so that they did not overlap, making sure that the tracks and pins were the right width.

![pcb](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/KiCad/KiCad_PCB.png)

Thirdly, Mrs Crouzet helped us print the circuit, and then we drilled the PCB (0.8 mm holes for all the pins, except those of the Arduino which are 1 mm).

The folder containing all the KiCad files is available [here](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/tree/main/KiCad).

<div id='app'/>

## Application

The measurements taken using the graphite sensor are sent via the Bluetooth module to an Android APK application created using MIT App Inventor ([link to website](https://appinventor.mit.edu/)).

This is the screen with the graph, i.e. the front panel:

![fpanel](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/Bluetooth_Application/Front_Panel.jpg)

Below is a block diagram of the rear panel:

![rpanel](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/Bluetooth_Application/Back_Panel.PNG)

You can find the application code in the [Application] folder (https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/tree/main/Bluetooth_Application).

<div id='ard'/>

## Arduino

The entire project is based on the Arduino code, which links all the system's components and functions. The Arduino retrieves and stores the resistance values from the graphite sensor. It displays them on the OLED screen and connects to the Bluetooth module to send the data to the application.

[Here](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/tree/main/Arduino_Program) is the Arduino code.

<div id='bench'/>

## Test bench

To check that the sensor was working properly and to create our datasheet, we used a pre-existing test bench made up of half-spheres of varying radii. The sheet of paper on which the graphite is deposited can be folded along the curve of the half-sphere, in order to measure the change in resistance of the sensor at regular intervals.

The variation curves obtained can be accessed via the [datasheet](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/Datasheet/Datasheet.pdf).

<div id='data'/>

## Datasheet

It was established by using the test bench. We measured the variations in resistance depending on the deformation for HB and 2B pencils. For each half-sphere radius, we took five tensile measurements and then calculated their average value. We reproduced the process for compression. It is important to note that the measured resistance depends on the amount of graphite deposited on the paper (and therefore on the intensity with which you press while colouring). But we established the ratio of these average values compared to the resting resistance, so the deformation graphs can be used for any amount of deposited graphite.

The datasheet is available [here](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/Datasheet/Datasheet.pdf).

<div id='improv'/>

## Improvements

The pins used to connect the clips of the sheet of paper to the PCB are too close to the OLED screen, which makes the connection a little difficult.

We could have used the digital potentiometer to add a new function, as it already has a slot on the PCB, but we ran out of time to code it.

We could have tested more pencil types to include them in the datasheet, and compared the values we obtained with those of other pairs, to make the datasheet more precise and accurate.


