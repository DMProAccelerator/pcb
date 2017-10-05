EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:freetronics_schematic
LIBS:EFM32GG990F1024
LIBS:DMPro17-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Crystal_GND23 Y1
U 1 1 59D16A4D
P 5400 3200
F 0 "Y1" H 5525 3400 50  0000 L CNN
F 1 "Crystal_GND23" H 5525 3325 50  0000 L CNN
F 2 "Crystals:Crystal_SMD_3225-4pin_3.2x2.5mm" H 5400 3200 50  0001 C CNN
F 3 "" H 5400 3200 50  0001 C CNN
	1    5400 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR032
U 1 1 59D16B3C
P 5400 3000
F 0 "#PWR032" H 5400 2750 50  0001 C CNN
F 1 "GND" H 5400 2850 50  0000 C CNN
F 2 "" H 5400 3000 50  0001 C CNN
F 3 "" H 5400 3000 50  0001 C CNN
	1    5400 3000
	-1   0    0    1   
$EndComp
Wire Wire Line
	5550 3200 6200 3200
$Comp
L +3.3V #PWR033
U 1 1 59D16B76
P 6200 3200
F 0 "#PWR033" H 6200 3050 50  0001 C CNN
F 1 "+3.3V" H 6200 3340 50  0000 C CNN
F 2 "" H 6200 3200 50  0001 C CNN
F 3 "" H 6200 3200 50  0001 C CNN
	1    6200 3200
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR034
U 1 1 59D16C11
P 5250 3200
F 0 "#PWR034" H 5250 3050 50  0001 C CNN
F 1 "+3.3V" H 5250 3340 50  0000 C CNN
F 2 "" H 5250 3200 50  0001 C CNN
F 3 "" H 5250 3200 50  0001 C CNN
	1    5250 3200
	0    -1   -1   0   
$EndComp
Text HLabel 5400 3400 3    60   Output ~ 0
HFXTAL_N
$EndSCHEMATC
