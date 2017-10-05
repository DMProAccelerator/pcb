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
Sheet 6 8
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
L C C4
U 1 1 59CC4AAA
P 4900 3900
F 0 "C4" H 4925 4000 50  0000 L CNN
F 1 "100n" H 4925 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4938 3750 50  0001 C CNN
F 3 "" H 4900 3900 50  0001 C CNN
	1    4900 3900
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 59CC4AAB
P 5300 3900
F 0 "C5" H 5325 4000 50  0000 L CNN
F 1 "100n" H 5325 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5338 3750 50  0001 C CNN
F 3 "" H 5300 3900 50  0001 C CNN
	1    5300 3900
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 59CC4AAC
P 5700 3900
F 0 "C6" H 5725 4000 50  0000 L CNN
F 1 "100n" H 5725 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5738 3750 50  0001 C CNN
F 3 "" H 5700 3900 50  0001 C CNN
	1    5700 3900
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 59CC4AAD
P 6100 3900
F 0 "C7" H 6125 4000 50  0000 L CNN
F 1 "100n" H 6125 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6138 3750 50  0001 C CNN
F 3 "" H 6100 3900 50  0001 C CNN
	1    6100 3900
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 59CC4AAE
P 6500 3900
F 0 "C8" H 6525 4000 50  0000 L CNN
F 1 "100n" H 6525 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6538 3750 50  0001 C CNN
F 3 "" H 6500 3900 50  0001 C CNN
	1    6500 3900
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 59CC4AAF
P 6900 3900
F 0 "C9" H 6925 4000 50  0000 L CNN
F 1 "10u" H 6925 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6938 3750 50  0001 C CNN
F 3 "" H 6900 3900 50  0001 C CNN
	1    6900 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4100 6900 4100
Wire Wire Line
	4900 4100 4900 4050
Wire Wire Line
	4500 3700 6900 3700
Wire Wire Line
	4900 3700 4900 3750
Wire Wire Line
	5300 3700 5300 3750
Connection ~ 4900 3700
Wire Wire Line
	5700 3700 5700 3750
Connection ~ 5300 3700
Wire Wire Line
	6100 3700 6100 3750
Connection ~ 5700 3700
Wire Wire Line
	6500 3700 6500 3750
Connection ~ 6100 3700
Wire Wire Line
	6900 3700 6900 3750
Connection ~ 6500 3700
Wire Wire Line
	5300 4100 5300 4050
Connection ~ 4900 4100
Wire Wire Line
	5700 4100 5700 4050
Connection ~ 5300 4100
Wire Wire Line
	6100 4100 6100 4050
Connection ~ 5700 4100
Wire Wire Line
	6500 4100 6500 4050
Connection ~ 6100 4100
Wire Wire Line
	6900 4100 6900 4050
Connection ~ 6500 4100
$Comp
L GND #PWR035
U 1 1 59CC4AB0
P 6900 4100
F 0 "#PWR035" H 6900 3850 50  0001 C CNN
F 1 "GND" H 6900 3950 50  0000 C CNN
F 2 "" H 6900 4100 50  0001 C CNN
F 3 "" H 6900 4100 50  0001 C CNN
	1    6900 4100
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR036
U 1 1 59CC4AB1
P 6900 3700
F 0 "#PWR036" H 6900 3550 50  0001 C CNN
F 1 "+3.3V" H 6900 3840 50  0000 C CNN
F 2 "" H 6900 3700 50  0001 C CNN
F 3 "" H 6900 3700 50  0001 C CNN
	1    6900 3700
	1    0    0    -1  
$EndComp
Text HLabel 4500 3700 0    60   BiDi ~ 0
IOVDD_6
Text HLabel 4500 4100 0    60   BiDi ~ 0
VSS_DREG
$EndSCHEMATC
