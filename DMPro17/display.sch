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
Sheet 8 8
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
L LS013B4DN04 D13
U 1 1 59CC9ADB
P 7200 4100
F 0 "D13" H 6650 4750 60  0000 C CNN
F 1 "LS013B4DN04" H 6900 3500 60  0000 C CNN
F 2 "myfootprint:LS013B4DN04" H 7150 4800 60  0001 C CNN
F 3 "" H 7150 4800 60  0001 C CNN
	1    7200 4100
	1    0    0    -1  
$EndComp
Text HLabel 4650 3750 0    60   BiDi ~ 0
MOSI
Text HLabel 4650 3650 0    60   BiDi ~ 0
SCK
Text HLabel 4650 3850 0    60   BiDi ~ 0
CS
$Comp
L GND #PWR039
U 1 1 59CC9C2A
P 4650 4450
F 0 "#PWR039" H 4650 4200 50  0001 C CNN
F 1 "GND" H 4650 4300 50  0000 C CNN
F 2 "" H 4650 4450 50  0001 C CNN
F 3 "" H 4650 4450 50  0001 C CNN
	1    4650 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 4350 4650 4350
Wire Wire Line
	4950 4450 4650 4450
$Comp
L Board_Connector B1
U 1 1 59CD1642
P 5350 4100
F 0 "B1" H 5250 4700 60  0000 C CNN
F 1 "Board_Connector" H 5400 3500 60  0000 C CNN
F 2 "myfootprint:Board_Connector" H 5700 5050 60  0001 C CNN
F 3 "" H 5700 5050 60  0001 C CNN
	1    5350 4100
	1    0    0    -1  
$EndComp
Wire Notes Line
	6400 3650 5500 3650
Wire Notes Line
	6400 3750 5500 3750
Wire Notes Line
	6400 3850 5500 3850
Wire Notes Line
	6400 3950 5500 3950
Wire Notes Line
	6400 4050 5500 4050
Wire Notes Line
	6400 4150 5500 4150
Wire Notes Line
	6400 4250 5500 4250
Wire Notes Line
	6400 4350 5500 4350
Wire Notes Line
	6400 4450 5500 4450
Wire Notes Line
	6400 4550 5500 4550
NoConn ~ 4950 4150
Wire Wire Line
	4650 3650 4950 3650
Wire Wire Line
	4950 3750 4650 3750
Wire Wire Line
	4650 3850 4950 3850
$Comp
L +3.3V #PWR040
U 1 1 59D38FA7
P 4650 4050
F 0 "#PWR040" H 4650 3900 50  0001 C CNN
F 1 "+3.3V" H 4650 4190 50  0000 C CNN
F 2 "" H 4650 4050 50  0001 C CNN
F 3 "" H 4650 4050 50  0001 C CNN
	1    4650 4050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4950 4050 4650 4050
Text HLabel 4650 3950 0    60   BiDi ~ 0
EXTCOMIN
Text HLabel 4650 4350 0    60   BiDi ~ 0
EXTMODE
Wire Wire Line
	4650 3950 4950 3950
Wire Wire Line
	4950 4250 4750 4250
Wire Wire Line
	4750 4250 4750 4050
Connection ~ 4750 4050
NoConn ~ 4950 4550
$EndSCHEMATC
