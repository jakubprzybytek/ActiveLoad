EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
LIBS:sparkfun
LIBS:ActiveLoad-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L LM358 U4
U 2 1 5AAAB5D7
P 8100 1700
F 0 "U4" H 8100 1900 50  0000 L CNN
F 1 "LM358" H 8100 1500 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 8100 1700 50  0001 C CNN
F 3 "" H 8100 1700 50  0001 C CNN
	2    8100 1700
	1    0    0    -1  
$EndComp
$Comp
L LM358 U4
U 1 1 5AAAB6B6
P 8100 3100
F 0 "U4" H 8100 3300 50  0000 L CNN
F 1 "LM358" H 8100 2900 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 8100 3100 50  0001 C CNN
F 3 "" H 8100 3100 50  0001 C CNN
	1    8100 3100
	-1   0    0    -1  
$EndComp
$Comp
L R R20
U 1 1 5AAAB723
P 9000 3400
F 0 "R20" V 9080 3400 50  0000 C CNN
F 1 "0R1" V 9000 3400 50  0000 C CNN
F 2 "JPResistors:R_Axial_Power_L48.0mm_W12.5mm_P50.8mm" V 8930 3400 50  0001 C CNN
F 3 "" H 9000 3400 50  0001 C CNN
	1    9000 3400
	1    0    0    -1  
$EndComp
$Comp
L BD911 Q3
U 1 1 5AAAB88A
P 9600 1350
F 0 "Q3" H 9850 1425 50  0000 L CNN
F 1 "BD911" H 9850 1350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220-3_Vertical" H 9850 1275 50  0001 L CIN
F 3 "" H 9600 1350 50  0001 L CNN
	1    9600 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5AAAB978
P 9000 3650
F 0 "#PWR01" H 9000 3400 50  0001 C CNN
F 1 "GND" H 9000 3500 50  0000 C CNN
F 2 "" H 9000 3650 50  0001 C CNN
F 3 "" H 9000 3650 50  0001 C CNN
	1    9000 3650
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J5
U 1 1 5AAABC28
P 10600 1150
F 0 "J5" H 10600 1250 50  0000 C CNN
F 1 "PowerInput" H 10600 950 50  0000 C CNN
F 2 "JPConnectors:PowerSocketSMD" H 10600 1150 50  0001 C CNN
F 3 "" H 10600 1150 50  0001 C CNN
	1    10600 1150
	1    0    0    1   
$EndComp
$Comp
L R R17
U 1 1 5AAABDF2
P 8750 3000
F 0 "R17" V 8830 3000 50  0000 C CNN
F 1 "1k" V 8750 3000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8680 3000 50  0001 C CNN
F 3 "" H 8750 3000 50  0001 C CNN
	1    8750 3000
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 5AAABE46
P 8500 3400
F 0 "R14" V 8580 3400 50  0000 C CNN
F 1 "1k" V 8500 3400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8430 3400 50  0001 C CNN
F 3 "" H 8500 3400 50  0001 C CNN
	1    8500 3400
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR02
U 1 1 5AAABEE4
P 8500 3650
F 0 "#PWR02" H 8500 3400 50  0001 C CNN
F 1 "GND" H 8500 3500 50  0000 C CNN
F 2 "" H 8500 3650 50  0001 C CNN
F 3 "" H 8500 3650 50  0001 C CNN
	1    8500 3650
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 5AAABF3D
P 7950 2700
F 0 "R13" V 8030 2700 50  0000 C CNN
F 1 "3k" V 7950 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7880 2700 50  0001 C CNN
F 3 "" H 7950 2700 50  0001 C CNN
	1    7950 2700
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR03
U 1 1 5AAAC029
P 8200 3650
F 0 "#PWR03" H 8200 3400 50  0001 C CNN
F 1 "GND" H 8200 3500 50  0000 C CNN
F 2 "" H 8200 3650 50  0001 C CNN
F 3 "" H 8200 3650 50  0001 C CNN
	1    8200 3650
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR04
U 1 1 5AAAC062
P 8200 2500
F 0 "#PWR04" H 8200 2350 50  0001 C CNN
F 1 "+3.3V" H 8200 2640 50  0000 C CNN
F 2 "" H 8200 2500 50  0001 C CNN
F 3 "" H 8200 2500 50  0001 C CNN
	1    8200 2500
	1    0    0    -1  
$EndComp
$Comp
L C C15
U 1 1 5AAAC0BB
P 8500 2550
F 0 "C15" H 8525 2650 50  0000 L CNN
F 1 "100n" H 8525 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 8538 2400 50  0001 C CNN
F 3 "" H 8500 2550 50  0001 C CNN
	1    8500 2550
	0    1    1    0   
$EndComp
$Comp
L GND #PWR05
U 1 1 5AAAC170
P 8650 2550
F 0 "#PWR05" H 8650 2300 50  0001 C CNN
F 1 "GND" H 8650 2400 50  0000 C CNN
F 2 "" H 8650 2550 50  0001 C CNN
F 3 "" H 8650 2550 50  0001 C CNN
	1    8650 2550
	0    -1   -1   0   
$EndComp
$Comp
L BC817 Q2
U 1 1 5AAAC416
P 9150 1700
F 0 "Q2" H 9350 1775 50  0000 L CNN
F 1 "BC817" H 9350 1700 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 9350 1625 50  0001 L CIN
F 3 "" H 9150 1700 50  0001 L CNN
	1    9150 1700
	1    0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 5AAAC4CC
P 9450 1050
F 0 "R21" V 9530 1050 50  0000 C CNN
F 1 "510" V 9450 1050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 9380 1050 50  0001 C CNN
F 3 "" H 9450 1050 50  0001 C CNN
	1    9450 1050
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 5AAAC55B
P 7700 2350
F 0 "R12" V 7780 2350 50  0000 C CNN
F 1 "10k" V 7700 2350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7630 2350 50  0001 C CNN
F 3 "" H 7700 2350 50  0001 C CNN
	1    7700 2350
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR06
U 1 1 5AAAC655
P 9250 1900
F 0 "#PWR06" H 9250 1650 50  0001 C CNN
F 1 "GND" H 9250 1750 50  0000 C CNN
F 2 "" H 9250 1900 50  0001 C CNN
F 3 "" H 9250 1900 50  0001 C CNN
	1    9250 1900
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 5AAAC734
P 8600 1700
F 0 "R16" V 8680 1700 50  0000 C CNN
F 1 "2k2" V 8600 1700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8530 1700 50  0001 C CNN
F 3 "" H 8600 1700 50  0001 C CNN
	1    8600 1700
	0    1    1    0   
$EndComp
$Comp
L R R18
U 1 1 5AAAC84D
P 8850 1950
F 0 "R18" V 8930 1950 50  0000 C CNN
F 1 "1k" V 8850 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8780 1950 50  0001 C CNN
F 3 "" H 8850 1950 50  0001 C CNN
	1    8850 1950
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR07
U 1 1 5AAAC8E7
P 8850 2100
F 0 "#PWR07" H 8850 1850 50  0001 C CNN
F 1 "GND" H 8850 1950 50  0000 C CNN
F 2 "" H 8850 2100 50  0001 C CNN
F 3 "" H 8850 2100 50  0001 C CNN
	1    8850 2100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5AAACB8B
P 10350 1200
F 0 "#PWR08" H 10350 950 50  0001 C CNN
F 1 "GND" H 10350 1050 50  0000 C CNN
F 2 "" H 10350 1200 50  0001 C CNN
F 3 "" H 10350 1200 50  0001 C CNN
	1    10350 1200
	1    0    0    -1  
$EndComp
$Comp
L ATXMEGA32E5-AU U3
U 1 1 5AAACD3E
P 4550 4600
F 0 "U3" H 3400 5650 50  0000 L BNN
F 1 "ATXMEGA32E5-AU" H 5200 3500 50  0000 L BNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 4550 4600 50  0001 C CIN
F 3 "" H 4550 4600 50  0001 C CNN
	1    4550 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 5AAAD27C
P 4500 5750
F 0 "#PWR09" H 4500 5500 50  0001 C CNN
F 1 "GND" H 4500 5600 50  0000 C CNN
F 2 "" H 4500 5750 50  0001 C CNN
F 3 "" H 4500 5750 50  0001 C CNN
	1    4500 5750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 5AAAD2F0
P 4600 5750
F 0 "#PWR010" H 4600 5500 50  0001 C CNN
F 1 "GND" H 4600 5600 50  0000 C CNN
F 2 "" H 4600 5750 50  0001 C CNN
F 3 "" H 4600 5750 50  0001 C CNN
	1    4600 5750
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR011
U 1 1 5AAAD3A0
P 4300 3000
F 0 "#PWR011" H 4300 2850 50  0001 C CNN
F 1 "+3.3V" H 4300 3140 50  0000 C CNN
F 2 "" H 4300 3000 50  0001 C CNN
F 3 "" H 4300 3000 50  0001 C CNN
	1    4300 3000
	1    0    0    -1  
$EndComp
$Comp
L L_Small L1
U 1 1 5AAAD4F8
P 4550 3100
F 0 "L1" H 4580 3140 50  0000 L CNN
F 1 "10u" H 4580 3060 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 4550 3100 50  0001 C CNN
F 3 "" H 4550 3100 50  0001 C CNN
	1    4550 3100
	0    -1   -1   0   
$EndComp
$Comp
L C C5
U 1 1 5AAAD5B2
P 4050 3100
F 0 "C5" H 4075 3200 50  0000 L CNN
F 1 "100n" H 4075 3000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4088 2950 50  0001 C CNN
F 3 "" H 4050 3100 50  0001 C CNN
	1    4050 3100
	0    -1   -1   0   
$EndComp
$Comp
L C C10
U 1 1 5AAAD655
P 5050 3100
F 0 "C10" H 5075 3200 50  0000 L CNN
F 1 "100n" H 5075 3000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5088 2950 50  0001 C CNN
F 3 "" H 5050 3100 50  0001 C CNN
	1    5050 3100
	0    -1   -1   0   
$EndComp
$Comp
L CP C6
U 1 1 5AAAD6BC
P 4050 3350
F 0 "C6" H 4075 3450 50  0000 L CNN
F 1 "10u" H 4075 3250 50  0000 L CNN
F 2 "Capacitors_SMD:CP_Elec_4x5.8" H 4088 3200 50  0001 C CNN
F 3 "" H 4050 3350 50  0001 C CNN
	1    4050 3350
	0    1    1    0   
$EndComp
$Comp
L CP C11
U 1 1 5AAAD7B4
P 5050 3350
F 0 "C11" H 5075 3450 50  0000 L CNN
F 1 "10u" H 5075 3250 50  0000 L CNN
F 2 "Capacitors_SMD:CP_Elec_4x5.8" H 5088 3200 50  0001 C CNN
F 3 "" H 5050 3350 50  0001 C CNN
	1    5050 3350
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR012
U 1 1 5AAADA39
P 5200 3350
F 0 "#PWR012" H 5200 3100 50  0001 C CNN
F 1 "GND" H 5200 3200 50  0000 C CNN
F 2 "" H 5200 3350 50  0001 C CNN
F 3 "" H 5200 3350 50  0001 C CNN
	1    5200 3350
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 5AAADAD0
P 5200 3100
F 0 "#PWR013" H 5200 2850 50  0001 C CNN
F 1 "GND" H 5200 2950 50  0000 C CNN
F 2 "" H 5200 3100 50  0001 C CNN
F 3 "" H 5200 3100 50  0001 C CNN
	1    5200 3100
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR014
U 1 1 5AAADBA3
P 3900 3100
F 0 "#PWR014" H 3900 2850 50  0001 C CNN
F 1 "GND" H 3900 2950 50  0000 C CNN
F 2 "" H 3900 3100 50  0001 C CNN
F 3 "" H 3900 3100 50  0001 C CNN
	1    3900 3100
	0    1    1    0   
$EndComp
$Comp
L GND #PWR015
U 1 1 5AAADBEA
P 3900 3350
F 0 "#PWR015" H 3900 3100 50  0001 C CNN
F 1 "GND" H 3900 3200 50  0000 C CNN
F 2 "" H 3900 3350 50  0001 C CNN
F 3 "" H 3900 3350 50  0001 C CNN
	1    3900 3350
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 5AAADD35
P 3100 3550
F 0 "R4" V 3180 3550 50  0000 C CNN
F 1 "10k" V 3100 3550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 3030 3550 50  0001 C CNN
F 3 "" H 3100 3550 50  0001 C CNN
	1    3100 3550
	-1   0    0    1   
$EndComp
$Comp
L +3.3V #PWR016
U 1 1 5AAADECF
P 3100 3400
F 0 "#PWR016" H 3100 3250 50  0001 C CNN
F 1 "+3.3V" H 3100 3540 50  0000 C CNN
F 2 "" H 3100 3400 50  0001 C CNN
F 3 "" H 3100 3400 50  0001 C CNN
	1    3100 3400
	1    0    0    -1  
$EndComp
$Comp
L Conn_02x03_Odd_Even J3
U 1 1 5AAADF06
P 1800 6000
F 0 "J3" H 1850 6200 50  0000 C CNN
F 1 "PDI" H 1850 5800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_2x03_Pitch2.54mm" H 1800 6000 50  0001 C CNN
F 3 "" H 1800 6000 50  0001 C CNN
	1    1800 6000
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR017
U 1 1 5AAAE341
P 2200 5800
F 0 "#PWR017" H 2200 5650 50  0001 C CNN
F 1 "+3.3V" H 2200 5940 50  0000 C CNN
F 2 "" H 2200 5800 50  0001 C CNN
F 3 "" H 2200 5800 50  0001 C CNN
	1    2200 5800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 5AAAE38E
P 2200 6200
F 0 "#PWR018" H 2200 5950 50  0001 C CNN
F 1 "GND" H 2200 6050 50  0000 C CNN
F 2 "" H 2200 6200 50  0001 C CNN
F 3 "" H 2200 6200 50  0001 C CNN
	1    2200 6200
	1    0    0    -1  
$EndComp
NoConn ~ 2100 6000
NoConn ~ 1600 6000
$Comp
L R R24
U 1 1 5AAAE8F2
P 10100 1650
F 0 "R24" V 10180 1650 50  0000 C CNN
F 1 "100k" V 10100 1650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 10030 1650 50  0001 C CNN
F 3 "" H 10100 1650 50  0001 C CNN
	1    10100 1650
	-1   0    0    1   
$EndComp
$Comp
L R R25
U 1 1 5AAAE9A7
P 10100 2050
F 0 "R25" V 10180 2050 50  0000 C CNN
F 1 "3k3" V 10100 2050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 10030 2050 50  0001 C CNN
F 3 "" H 10100 2050 50  0001 C CNN
	1    10100 2050
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR019
U 1 1 5AAAECEC
P 10100 2200
F 0 "#PWR019" H 10100 1950 50  0001 C CNN
F 1 "GND" H 10100 2050 50  0000 C CNN
F 2 "" H 10100 2200 50  0001 C CNN
F 3 "" H 10100 2200 50  0001 C CNN
	1    10100 2200
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x04 J2
U 1 1 5AAAF431
P 1100 7100
F 0 "J2" H 1100 7300 50  0000 C CNN
F 1 "TWI" H 1100 6800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 1100 7100 50  0001 C CNN
F 3 "" H 1100 7100 50  0001 C CNN
	1    1100 7100
	-1   0    0    -1  
$EndComp
$Comp
L +3.3V #PWR020
U 1 1 5AAAF8B9
P 1400 6600
F 0 "#PWR020" H 1400 6450 50  0001 C CNN
F 1 "+3.3V" H 1400 6740 50  0000 C CNN
F 2 "" H 1400 6600 50  0001 C CNN
F 3 "" H 1400 6600 50  0001 C CNN
	1    1400 6600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR021
U 1 1 5AAAF90F
P 1500 7100
F 0 "#PWR021" H 1500 6850 50  0001 C CNN
F 1 "GND" H 1500 6950 50  0000 C CNN
F 2 "" H 1500 7100 50  0001 C CNN
F 3 "" H 1500 7100 50  0001 C CNN
	1    1500 7100
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 5AAAFF80
P 1750 6850
F 0 "R1" V 1830 6850 50  0000 C CNN
F 1 "2k2" V 1750 6850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1680 6850 50  0001 C CNN
F 3 "" H 1750 6850 50  0001 C CNN
	1    1750 6850
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 5AAB0237
P 1850 6850
F 0 "R2" V 1930 6850 50  0000 C CNN
F 1 "2k2" V 1850 6850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1780 6850 50  0001 C CNN
F 3 "" H 1850 6850 50  0001 C CNN
	1    1850 6850
	-1   0    0    1   
$EndComp
$Comp
L +12V #PWR022
U 1 1 5AAB0AE2
P 10550 4750
F 0 "#PWR022" H 10550 4600 50  0001 C CNN
F 1 "+12V" H 10550 4890 50  0000 C CNN
F 2 "" H 10550 4750 50  0001 C CNN
F 3 "" H 10550 4750 50  0001 C CNN
	1    10550 4750
	1    0    0    -1  
$EndComp
$Comp
L BD136 Q4
U 1 1 5AAB0B2E
P 10450 5150
F 0 "Q4" H 10650 5225 50  0000 L CNN
F 1 "BD136" H 10650 5150 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-126_Vertical" H 10650 5075 50  0001 L CIN
F 3 "" H 10450 5150 50  0001 L CNN
	1    10450 5150
	1    0    0    1   
$EndComp
$Comp
L R R26
U 1 1 5AAB0BBA
P 10300 4850
F 0 "R26" V 10380 4850 50  0000 C CNN
F 1 "1k" V 10300 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 10230 4850 50  0001 C CNN
F 3 "" H 10300 4850 50  0001 C CNN
	1    10300 4850
	0    -1   -1   0   
$EndComp
$Comp
L R R23
U 1 1 5AAB0D8C
P 9900 5150
F 0 "R23" V 9980 5150 50  0000 C CNN
F 1 "1k" V 9900 5150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 9830 5150 50  0001 C CNN
F 3 "" H 9900 5150 50  0001 C CNN
	1    9900 5150
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR023
U 1 1 5AAB12DB
P 10550 5750
F 0 "#PWR023" H 10550 5500 50  0001 C CNN
F 1 "GND" H 10550 5600 50  0000 C CNN
F 2 "" H 10550 5750 50  0001 C CNN
F 3 "" H 10550 5750 50  0001 C CNN
	1    10550 5750
	1    0    0    -1  
$EndComp
$Comp
L R R19
U 1 1 5AAB16F8
P 8950 5800
F 0 "R19" V 9030 5800 50  0000 C CNN
F 1 "10k" V 8950 5800 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8880 5800 50  0001 C CNN
F 3 "" H 8950 5800 50  0001 C CNN
	1    8950 5800
	-1   0    0    1   
$EndComp
$Comp
L R R22
U 1 1 5AAB17BC
P 9600 5550
F 0 "R22" V 9680 5550 50  0000 C CNN
F 1 "120k" V 9600 5550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 9530 5550 50  0001 C CNN
F 3 "" H 9600 5550 50  0001 C CNN
	1    9600 5550
	0    -1   -1   0   
$EndComp
$Comp
L TL081 U5
U 1 1 5AAB1871
P 9350 5150
F 0 "U5" H 9350 5400 50  0000 L CNN
F 1 "TL081" H 9350 5300 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 9400 5200 50  0001 C CNN
F 3 "" H 9500 5300 50  0001 C CNN
	1    9350 5150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 5AAB1AE0
P 9250 5600
F 0 "#PWR024" H 9250 5350 50  0001 C CNN
F 1 "GND" H 9250 5450 50  0000 C CNN
F 2 "" H 9250 5600 50  0001 C CNN
F 3 "" H 9250 5600 50  0001 C CNN
	1    9250 5600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 5AAB1FFC
P 8950 5950
F 0 "#PWR025" H 8950 5700 50  0001 C CNN
F 1 "GND" H 8950 5800 50  0000 C CNN
F 2 "" H 8950 5950 50  0001 C CNN
F 3 "" H 8950 5950 50  0001 C CNN
	1    8950 5950
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR026
U 1 1 5AAB2070
P 9250 4750
F 0 "#PWR026" H 9250 4600 50  0001 C CNN
F 1 "+12V" H 9250 4890 50  0000 C CNN
F 2 "" H 9250 4750 50  0001 C CNN
F 3 "" H 9250 4750 50  0001 C CNN
	1    9250 4750
	1    0    0    -1  
$EndComp
$Comp
L C C17
U 1 1 5AAB21AD
P 9550 4800
F 0 "C17" H 9575 4900 50  0000 L CNN
F 1 "100n" H 9575 4700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 9588 4650 50  0001 C CNN
F 3 "" H 9550 4800 50  0001 C CNN
	1    9550 4800
	0    1    1    0   
$EndComp
$Comp
L GND #PWR027
U 1 1 5AAB23D9
P 9700 4800
F 0 "#PWR027" H 9700 4550 50  0001 C CNN
F 1 "GND" H 9700 4650 50  0000 C CNN
F 2 "" H 9700 4800 50  0001 C CNN
F 3 "" H 9700 4800 50  0001 C CNN
	1    9700 4800
	0    -1   -1   0   
$EndComp
$Comp
L CP C18
U 1 1 5AAB261C
P 9900 5750
F 0 "C18" H 9925 5850 50  0000 L CNN
F 1 "200u" H 9925 5650 50  0000 L CNN
F 2 "Capacitors_SMD:CP_Elec_6.3x7.7" H 9938 5600 50  0001 C CNN
F 3 "" H 9900 5750 50  0001 C CNN
	1    9900 5750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR028
U 1 1 5AAB2859
P 9900 5900
F 0 "#PWR028" H 9900 5650 50  0001 C CNN
F 1 "GND" H 9900 5750 50  0000 C CNN
F 2 "" H 9900 5900 50  0001 C CNN
F 3 "" H 9900 5900 50  0001 C CNN
	1    9900 5900
	1    0    0    -1  
$EndComp
$Comp
L CP C16
U 1 1 5AAB2DED
P 8750 5500
F 0 "C16" H 8775 5600 50  0000 L CNN
F 1 "1u" H 8775 5400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 8788 5350 50  0001 C CNN
F 3 "" H 8750 5500 50  0001 C CNN
	1    8750 5500
	1    0    0    -1  
$EndComp
$Comp
L R R15
U 1 1 5AAB2EED
P 8500 5250
F 0 "R15" V 8580 5250 50  0000 C CNN
F 1 "14k7" V 8500 5250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8430 5250 50  0001 C CNN
F 3 "" H 8500 5250 50  0001 C CNN
	1    8500 5250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR029
U 1 1 5AAB30F8
P 8750 5650
F 0 "#PWR029" H 8750 5400 50  0001 C CNN
F 1 "GND" H 8750 5500 50  0000 C CNN
F 2 "" H 8750 5650 50  0001 C CNN
F 3 "" H 8750 5650 50  0001 C CNN
	1    8750 5650
	1    0    0    -1  
$EndComp
$Comp
L CP C14
U 1 1 5AAB3C19
P 7350 2050
F 0 "C14" H 7375 2150 50  0000 L CNN
F 1 "1u" H 7375 1950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 7388 1900 50  0001 C CNN
F 3 "" H 7350 2050 50  0001 C CNN
	1    7350 2050
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 5AAB3C1F
P 7100 1800
F 0 "R11" V 7180 1800 50  0000 C CNN
F 1 "14k7" V 7100 1800 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7030 1800 50  0001 C CNN
F 3 "" H 7100 1800 50  0001 C CNN
	1    7100 1800
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR030
U 1 1 5AAB3C29
P 7350 2200
F 0 "#PWR030" H 7350 1950 50  0001 C CNN
F 1 "GND" H 7350 2050 50  0000 C CNN
F 2 "" H 7350 2200 50  0001 C CNN
F 3 "" H 7350 2200 50  0001 C CNN
	1    7350 2200
	1    0    0    -1  
$EndComp
Text Notes 6350 6500 0    60   ~ 0
32E5 (1.2mA)\nDisplay 0111 100 (80mW, 25mA)\nTC74   1001 xxx (0.3mA)\nRot (1mA)\nLM358 (2mA)\n1. NC\n2. SDA\n3. GND\n4. SCK\n5. VDD
$Comp
L Conn_01x05 J4
U 1 1 5AAB49AA
P 2500 7100
F 0 "J4" H 2500 7400 50  0000 C CNN
F 1 "TC74X-3.3" H 2500 6800 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220-5_Vertical" H 2500 7100 50  0001 C CNN
F 3 "" H 2500 7100 50  0001 C CNN
	1    2500 7100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR031
U 1 1 5AAB4F25
P 2100 7100
F 0 "#PWR031" H 2100 6850 50  0001 C CNN
F 1 "GND" H 2100 6950 50  0000 C CNN
F 2 "" H 2100 7100 50  0001 C CNN
F 3 "" H 2100 7100 50  0001 C CNN
	1    2100 7100
	0    1    1    0   
$EndComp
NoConn ~ 2300 6900
$Comp
L ROTARY-ENCODER ROT1
U 1 1 5AAC1424
P 5000 7050
F 0 "ROT1" H 4910 7300 60  0000 C CNN
F 1 "ROTARY-ENCODER" H 5000 6770 60  0000 C CNN
F 2 "sparkfun:SF-ROTARY-ENCODER" H 5000 7050 60  0001 C CNN
F 3 "" H 5000 7050 60  0000 C CNN
	1    5000 7050
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5AAC1523
P 4450 6900
F 0 "R6" V 4530 6900 50  0000 C CNN
F 1 "10k" V 4450 6900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4380 6900 50  0001 C CNN
F 3 "" H 4450 6900 50  0001 C CNN
	1    4450 6900
	-1   0    0    1   
$EndComp
$Comp
L C C13
U 1 1 5AAC1673
P 6300 7350
F 0 "C13" H 6325 7450 50  0000 L CNN
F 1 "10n" H 6325 7250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6338 7200 50  0001 C CNN
F 3 "" H 6300 7350 50  0001 C CNN
	1    6300 7350
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5AAC1A34
P 4200 7150
F 0 "R5" V 4280 7150 50  0000 C CNN
F 1 "10k" V 4200 7150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4130 7150 50  0001 C CNN
F 3 "" H 4200 7150 50  0001 C CNN
	1    4200 7150
	0    1    1    0   
$EndComp
$Comp
L C C7
U 1 1 5AAC1AF5
P 3950 7400
F 0 "C7" H 3975 7500 50  0000 L CNN
F 1 "10n" H 3975 7300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3988 7250 50  0001 C CNN
F 3 "" H 3950 7400 50  0001 C CNN
	1    3950 7400
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR032
U 1 1 5AAC1C33
P 3950 7550
F 0 "#PWR032" H 3950 7300 50  0001 C CNN
F 1 "GND" H 3950 7400 50  0000 C CNN
F 2 "" H 3950 7550 50  0001 C CNN
F 3 "" H 3950 7550 50  0001 C CNN
	1    3950 7550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR033
U 1 1 5AAC1CC8
P 4650 6950
F 0 "#PWR033" H 4650 6700 50  0001 C CNN
F 1 "GND" H 4650 6800 50  0000 C CNN
F 2 "" H 4650 6950 50  0001 C CNN
F 3 "" H 4650 6950 50  0001 C CNN
	1    4650 6950
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR034
U 1 1 5AAC2011
P 4450 6750
F 0 "#PWR034" H 4450 6600 50  0001 C CNN
F 1 "+3.3V" H 4450 6890 50  0000 C CNN
F 2 "" H 4450 6750 50  0001 C CNN
F 3 "" H 4450 6750 50  0001 C CNN
	1    4450 6750
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 5AAC222A
P 5850 6950
F 0 "R9" V 5930 6950 50  0000 C CNN
F 1 "10k" V 5850 6950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5780 6950 50  0001 C CNN
F 3 "" H 5850 6950 50  0001 C CNN
	1    5850 6950
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 5AAC231C
P 5450 6700
F 0 "R7" V 5530 6700 50  0000 C CNN
F 1 "10k" V 5450 6700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5380 6700 50  0001 C CNN
F 3 "" H 5450 6700 50  0001 C CNN
	1    5450 6700
	-1   0    0    1   
$EndComp
$Comp
L R R8
U 1 1 5AAC23DA
P 5600 6700
F 0 "R8" V 5680 6700 50  0000 C CNN
F 1 "10k" V 5600 6700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5530 6700 50  0001 C CNN
F 3 "" H 5600 6700 50  0001 C CNN
	1    5600 6700
	-1   0    0    1   
$EndComp
$Comp
L R R10
U 1 1 5AAC24BE
P 5850 7150
F 0 "R10" V 5930 7150 50  0000 C CNN
F 1 "10k" V 5850 7150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5780 7150 50  0001 C CNN
F 3 "" H 5850 7150 50  0001 C CNN
	1    5850 7150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR035
U 1 1 5AAC2568
P 5350 7050
F 0 "#PWR035" H 5350 6800 50  0001 C CNN
F 1 "GND" H 5350 6900 50  0000 C CNN
F 2 "" H 5350 7050 50  0001 C CNN
F 3 "" H 5350 7050 50  0001 C CNN
	1    5350 7050
	0    -1   -1   0   
$EndComp
$Comp
L C C12
U 1 1 5AAC2609
P 6050 7350
F 0 "C12" H 6075 7450 50  0000 L CNN
F 1 "10n" H 6075 7250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6088 7200 50  0001 C CNN
F 3 "" H 6050 7350 50  0001 C CNN
	1    6050 7350
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR036
U 1 1 5AAC2E8B
P 5450 6550
F 0 "#PWR036" H 5450 6400 50  0001 C CNN
F 1 "+3.3V" H 5450 6690 50  0000 C CNN
F 2 "" H 5450 6550 50  0001 C CNN
F 3 "" H 5450 6550 50  0001 C CNN
	1    5450 6550
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR037
U 1 1 5AAC2F2F
P 5600 6550
F 0 "#PWR037" H 5600 6400 50  0001 C CNN
F 1 "+3.3V" H 5600 6690 50  0000 C CNN
F 2 "" H 5600 6550 50  0001 C CNN
F 3 "" H 5600 6550 50  0001 C CNN
	1    5600 6550
	1    0    0    -1  
$EndComp
Text GLabel 6400 6950 2    60   Input ~ 0
ENC_A
Text GLabel 6400 7150 2    60   Input ~ 0
ENC_B
$Comp
L GND #PWR038
U 1 1 5AAC316F
P 6050 7500
F 0 "#PWR038" H 6050 7250 50  0001 C CNN
F 1 "GND" H 6050 7350 50  0000 C CNN
F 2 "" H 6050 7500 50  0001 C CNN
F 3 "" H 6050 7500 50  0001 C CNN
	1    6050 7500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR039
U 1 1 5AAC3213
P 6300 7500
F 0 "#PWR039" H 6300 7250 50  0001 C CNN
F 1 "GND" H 6300 7350 50  0000 C CNN
F 2 "" H 6300 7500 50  0001 C CNN
F 3 "" H 6300 7500 50  0001 C CNN
	1    6300 7500
	1    0    0    -1  
$EndComp
Text GLabel 3850 7150 0    60   Input ~ 0
ENC_Switch
Text GLabel 5950 5400 2    60   Input ~ 0
ENC_Switch
Text GLabel 5950 5100 2    60   Input ~ 0
ENC_B
Text GLabel 5950 5200 2    60   Input ~ 0
ENC_A
Text GLabel 1500 6100 0    60   Input ~ 0
PDI_CLK
Text GLabel 2950 3800 0    60   Input ~ 0
PDI_CLK
Text GLabel 2950 3900 0    60   Input ~ 0
PDI_DATA
Text GLabel 1500 5900 0    60   Input ~ 0
PDI_DATA
Text GLabel 1750 7400 3    60   Input ~ 0
SDA
Text GLabel 1850 7400 3    60   Input ~ 0
SCK
Text GLabel 5950 4700 2    60   Input ~ 0
SDA
Text GLabel 5950 4800 2    60   Input ~ 0
SCK
$Comp
L GND #PWR040
U 1 1 5AAC69F5
P 2900 2550
F 0 "#PWR040" H 2900 2300 50  0001 C CNN
F 1 "GND" H 2900 2400 50  0000 C CNN
F 2 "" H 2900 2550 50  0001 C CNN
F 3 "" H 2900 2550 50  0001 C CNN
	1    2900 2550
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5AAC6EB1
P 3300 2500
F 0 "C2" H 3325 2600 50  0000 L CNN
F 1 "100n" H 3325 2400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3338 2350 50  0001 C CNN
F 3 "" H 3300 2500 50  0001 C CNN
	1    3300 2500
	1    0    0    -1  
$EndComp
$Comp
L CP C3
U 1 1 5AAC6FAC
P 3550 2500
F 0 "C3" H 3575 2600 50  0000 L CNN
F 1 "47u" H 3575 2400 50  0000 L CNN
F 2 "Capacitors_SMD:CP_Elec_6.3x5.8" H 3588 2350 50  0001 C CNN
F 3 "" H 3550 2500 50  0001 C CNN
	1    3550 2500
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR041
U 1 1 5AAC7427
P 3550 2150
F 0 "#PWR041" H 3550 2000 50  0001 C CNN
F 1 "+3.3V" H 3550 2290 50  0000 C CNN
F 2 "" H 3550 2150 50  0001 C CNN
F 3 "" H 3550 2150 50  0001 C CNN
	1    3550 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR042
U 1 1 5AAC77D9
P 3300 2650
F 0 "#PWR042" H 3300 2400 50  0001 C CNN
F 1 "GND" H 3300 2500 50  0000 C CNN
F 2 "" H 3300 2650 50  0001 C CNN
F 3 "" H 3300 2650 50  0001 C CNN
	1    3300 2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR043
U 1 1 5AAC788C
P 3550 2650
F 0 "#PWR043" H 3550 2400 50  0001 C CNN
F 1 "GND" H 3550 2500 50  0000 C CNN
F 2 "" H 3550 2650 50  0001 C CNN
F 3 "" H 3550 2650 50  0001 C CNN
	1    3550 2650
	1    0    0    -1  
$EndComp
Text GLabel 10250 1850 2    60   Input ~ 0
VOLTAGE_LEVEL
Text GLabel 9850 3000 2    60   Input ~ 0
CURRENT_LEVEL
Text GLabel 5950 4500 2    60   Input ~ 0
CURRENT_LEVEL
Text GLabel 5950 4400 2    60   Input ~ 0
VOLTAGE_LEVEL
Text GLabel 10000 850  0    60   Input ~ 0
PowerInput
Text GLabel 1300 1300 0    60   Input ~ 0
PowerInput
$Comp
L Conn_01x02 J1
U 1 1 5AAC9C84
P 1100 1600
F 0 "J1" H 1100 1700 50  0000 C CNN
F 1 "AuxPower" H 1100 1400 50  0000 C CNN
F 2 "JPConnectors:PowerSocketSMD" H 1100 1600 50  0001 C CNN
F 3 "" H 1100 1600 50  0001 C CNN
	1    1100 1600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR044
U 1 1 5AAC9FAD
P 1400 1700
F 0 "#PWR044" H 1400 1450 50  0001 C CNN
F 1 "GND" H 1400 1550 50  0000 C CNN
F 2 "" H 1400 1700 50  0001 C CNN
F 3 "" H 1400 1700 50  0001 C CNN
	1    1400 1700
	1    0    0    -1  
$EndComp
$Comp
L SW_SPDT SW1
U 1 1 5AACA7BE
P 1700 1400
F 0 "SW1" H 1700 1570 50  0000 C CNN
F 1 "SW_SPDT" H 1700 1200 50  0000 C CNN
F 2 "JPConnectors:SlideSwitch3Poles" H 1700 1400 50  0001 C CNN
F 3 "" H 1700 1400 50  0001 C CNN
	1    1700 1400
	-1   0    0    -1  
$EndComp
$Comp
L L7812 U2
U 1 1 5AACCCE2
P 3100 1250
F 0 "U2" H 2950 1375 50  0000 C CNN
F 1 "L78M12" H 3100 1375 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:TO-252-2_Rectifier" H 3125 1100 50  0001 L CIN
F 3 "" H 3100 1200 50  0001 C CNN
	1    3100 1250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR045
U 1 1 5AACD477
P 3100 1850
F 0 "#PWR045" H 3100 1600 50  0001 C CNN
F 1 "GND" H 3100 1700 50  0000 C CNN
F 2 "" H 3100 1850 50  0001 C CNN
F 3 "" H 3100 1850 50  0001 C CNN
	1    3100 1850
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 5AACD983
P 3850 1500
F 0 "C8" H 3875 1600 50  0000 L CNN
F 1 "100n" H 3875 1400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3888 1350 50  0001 C CNN
F 3 "" H 3850 1500 50  0001 C CNN
	1    3850 1500
	1    0    0    -1  
$EndComp
$Comp
L CP C9
U 1 1 5AACDA71
P 4100 1500
F 0 "C9" H 4125 1600 50  0000 L CNN
F 1 "100u" H 4125 1400 50  0000 L CNN
F 2 "Capacitors_SMD:CP_Elec_6.3x7.7" H 4138 1350 50  0001 C CNN
F 3 "" H 4100 1500 50  0001 C CNN
	1    4100 1500
	1    0    0    -1  
$EndComp
$Comp
L CP C4
U 1 1 5AACDB5C
P 2000 1650
F 0 "C4" H 2025 1750 50  0000 L CNN
F 1 "100u" H 2025 1550 50  0000 L CNN
F 2 "Capacitors_SMD:CP_Elec_6.3x7.7" H 2038 1500 50  0001 C CNN
F 3 "" H 2000 1650 50  0001 C CNN
	1    2000 1650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR046
U 1 1 5AACDC4E
P 2000 1800
F 0 "#PWR046" H 2000 1550 50  0001 C CNN
F 1 "GND" H 2000 1650 50  0000 C CNN
F 2 "" H 2000 1800 50  0001 C CNN
F 3 "" H 2000 1800 50  0001 C CNN
	1    2000 1800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR047
U 1 1 5AACDD19
P 3850 1650
F 0 "#PWR047" H 3850 1400 50  0001 C CNN
F 1 "GND" H 3850 1500 50  0000 C CNN
F 2 "" H 3850 1650 50  0001 C CNN
F 3 "" H 3850 1650 50  0001 C CNN
	1    3850 1650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR048
U 1 1 5AACDDE4
P 4100 1650
F 0 "#PWR048" H 4100 1400 50  0001 C CNN
F 1 "GND" H 4100 1500 50  0000 C CNN
F 2 "" H 4100 1650 50  0001 C CNN
F 3 "" H 4100 1650 50  0001 C CNN
	1    4100 1650
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR049
U 1 1 5AACE45F
P 4100 1150
F 0 "#PWR049" H 4100 1000 50  0001 C CNN
F 1 "+12V" H 4100 1290 50  0000 C CNN
F 2 "" H 4100 1150 50  0001 C CNN
F 3 "" H 4100 1150 50  0001 C CNN
	1    4100 1150
	1    0    0    -1  
$EndComp
Text GLabel 8200 5250 0    60   Input ~ 0
FAN_CONTROL
Text GLabel 5950 4000 2    60   Input ~ 0
FAN_CONTROL
Text GLabel 6800 1800 0    60   Input ~ 0
DRAIN_CONTROL
Text GLabel 5950 4100 2    60   Input ~ 0
DRAIN_CONTROL
Text Notes 8750 6450 0    60   ~ 0
G=12V/1V=12\nFan Control: 0-1V\nFan Voltage: 0-12V
Text Notes 10300 2150 0    60   ~ 0
G=1/30\nVoltage 0-30\n
Text Notes 9250 3350 0    60   ~ 0
Input Current 0-10A\nCurrent Level 0-1V
Text Notes 7200 2950 0    60   ~ 0
G=3
$Comp
L Conn_01x03 J6
U 1 1 5AAD8D8B
P 10850 5550
F 0 "J6" H 10850 5750 50  0000 C CNN
F 1 "FAN" H 10850 5350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x03_Pitch2.54mm" H 10850 5550 50  0001 C CNN
F 3 "" H 10850 5550 50  0001 C CNN
	1    10850 5550
	1    0    0    1   
$EndComp
NoConn ~ 10650 5450
$Comp
L SW_SPDT SW2
U 1 1 5AAE5D74
P 2550 1150
F 0 "SW2" H 2550 1320 50  0000 C CNN
F 1 "SW_SPDT" H 2550 950 50  0000 C CNN
F 2 "JPConnectors:SlideSwitch3Poles" H 2550 1150 50  0001 C CNN
F 3 "" H 2550 1150 50  0001 C CNN
	1    2550 1150
	1    0    0    -1  
$EndComp
$Comp
L L7812 U1
U 1 1 5AAE87F8
P 2900 2250
F 0 "U1" H 2750 2375 50  0000 C CNN
F 1 "UA78M33" H 2900 2375 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:TO-252-2_Rectifier" H 2925 2100 50  0001 L CIN
F 3 "" H 2900 2200 50  0001 C CNN
	1    2900 2250
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 5AAF3128
P 10250 5800
F 0 "D1" H 10250 5900 50  0000 C CNN
F 1 "1N4148" H 10250 5700 50  0000 C CNN
F 2 "Diodes_SMD:D_1206" H 10250 5800 50  0001 C CNN
F 3 "" H 10250 5800 50  0001 C CNN
	1    10250 5800
	0    1    1    0   
$EndComp
$Comp
L GND #PWR050
U 1 1 5AAF3916
P 10250 5950
F 0 "#PWR050" H 10250 5700 50  0001 C CNN
F 1 "GND" H 10250 5800 50  0000 C CNN
F 2 "" H 10250 5950 50  0001 C CNN
F 3 "" H 10250 5950 50  0001 C CNN
	1    10250 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 3650 8500 3550
Wire Wire Line
	9000 3650 9000 3550
Wire Wire Line
	8400 3000 8600 3000
Wire Wire Line
	8900 3000 9850 3000
Wire Wire Line
	9000 3000 9000 3250
Connection ~ 9000 3000
Wire Wire Line
	8400 3200 8500 3200
Wire Wire Line
	8500 2700 8500 3250
Wire Wire Line
	8500 2700 8100 2700
Connection ~ 8500 3200
Wire Wire Line
	7800 2700 7700 2700
Wire Wire Line
	7700 2500 7700 3100
Wire Wire Line
	7700 3100 7800 3100
Wire Wire Line
	8200 3650 8200 3400
Wire Wire Line
	8200 2500 8200 2800
Wire Wire Line
	8350 2550 8200 2550
Connection ~ 8200 2550
Connection ~ 7700 2700
Wire Wire Line
	7700 2200 7700 1600
Wire Wire Line
	7700 1600 7800 1600
Wire Wire Line
	8400 1700 8450 1700
Wire Wire Line
	8750 1700 8950 1700
Wire Wire Line
	8850 1800 8850 1700
Connection ~ 8850 1700
Wire Wire Line
	9250 1050 9250 1500
Wire Wire Line
	9250 1050 9300 1050
Wire Wire Line
	9400 1350 9250 1350
Connection ~ 9250 1350
Wire Wire Line
	9600 1050 10400 1050
Wire Wire Line
	9700 1050 9700 1150
Connection ~ 9700 1050
Wire Wire Line
	10350 1200 10350 1150
Wire Wire Line
	10350 1150 10400 1150
Wire Wire Line
	5850 4700 5950 4700
Wire Wire Line
	5850 4800 5950 4800
Wire Wire Line
	9700 3000 9700 1550
Wire Wire Line
	4300 3000 4300 3450
Wire Wire Line
	4200 3100 4450 3100
Connection ~ 4300 3100
Wire Wire Line
	4650 3100 4900 3100
Wire Wire Line
	4800 3100 4800 3450
Wire Wire Line
	4900 3350 4800 3350
Connection ~ 4800 3350
Connection ~ 4800 3100
Wire Wire Line
	4200 3350 4300 3350
Connection ~ 4300 3350
Wire Wire Line
	3100 3700 3100 3800
Wire Wire Line
	2950 3800 3200 3800
Wire Wire Line
	3200 3900 2950 3900
Connection ~ 3100 3800
Wire Wire Line
	1600 5900 1500 5900
Wire Wire Line
	1600 6100 1500 6100
Wire Wire Line
	2100 6100 2200 6100
Wire Wire Line
	2200 6100 2200 6200
Wire Wire Line
	2100 5900 2200 5900
Wire Wire Line
	2200 5900 2200 5800
Connection ~ 9700 3000
Wire Wire Line
	10100 1800 10100 1900
Wire Wire Line
	10100 850  10100 1500
Connection ~ 10100 1050
Connection ~ 10100 1850
Wire Wire Line
	1300 7300 2150 7300
Wire Wire Line
	1300 7200 2300 7200
Wire Wire Line
	1300 7100 1500 7100
Wire Wire Line
	1400 7000 1300 7000
Wire Wire Line
	1400 6600 1400 7000
Wire Wire Line
	1750 7000 1750 7400
Connection ~ 1750 7300
Wire Wire Line
	1850 7000 1850 7400
Connection ~ 1850 7200
Wire Wire Line
	1850 6650 1850 6700
Wire Wire Line
	1400 6650 2250 6650
Connection ~ 1400 6650
Wire Wire Line
	1750 6700 1750 6650
Connection ~ 1750 6650
Wire Wire Line
	10050 5150 10250 5150
Wire Wire Line
	10150 4850 10100 4850
Wire Wire Line
	10100 4850 10100 5150
Connection ~ 10100 5150
Wire Wire Line
	10550 4750 10550 4950
Wire Wire Line
	10450 4850 10550 4850
Connection ~ 10550 4850
Wire Wire Line
	10550 5550 10550 5350
Wire Wire Line
	9750 5550 10650 5550
Wire Wire Line
	10550 5750 10550 5650
Wire Wire Line
	10550 5650 10650 5650
Wire Wire Line
	9650 5150 9750 5150
Wire Wire Line
	9250 5450 9250 5600
Connection ~ 10550 5550
Wire Wire Line
	9450 5550 8950 5550
Wire Wire Line
	8950 5050 8950 5650
Connection ~ 8950 5550
Wire Wire Line
	9250 4750 9250 4850
Wire Wire Line
	9400 4800 9250 4800
Connection ~ 9250 4800
Wire Wire Line
	9900 5600 9900 5550
Connection ~ 9900 5550
Wire Wire Line
	8650 5250 9050 5250
Wire Wire Line
	8750 5250 8750 5350
Connection ~ 8750 5250
Wire Wire Line
	8350 5250 8200 5250
Wire Wire Line
	7250 1800 7800 1800
Wire Wire Line
	7350 1900 7350 1800
Connection ~ 7350 1800
Wire Wire Line
	6950 1800 6800 1800
Wire Wire Line
	5850 4000 5950 4000
Wire Wire Line
	5850 4100 5950 4100
Wire Wire Line
	2150 7300 2150 7000
Wire Wire Line
	2150 7000 2300 7000
Wire Wire Line
	2300 7300 2250 7300
Wire Wire Line
	2250 7300 2250 6650
Connection ~ 1850 6650
Wire Wire Line
	2100 7100 2300 7100
Wire Wire Line
	4450 7050 4450 7150
Connection ~ 4450 7150
Wire Wire Line
	3950 7250 3950 7150
Wire Wire Line
	3850 7150 4050 7150
Connection ~ 3950 7150
Wire Wire Line
	5350 6950 5700 6950
Wire Wire Line
	5350 7150 5700 7150
Wire Wire Line
	5450 6850 5450 6950
Connection ~ 5450 6950
Wire Wire Line
	5600 6850 5600 7150
Connection ~ 5600 7150
Wire Wire Line
	6000 6950 6400 6950
Wire Wire Line
	6000 7150 6400 7150
Wire Wire Line
	6050 7200 6050 6950
Connection ~ 6050 6950
Wire Wire Line
	6300 7150 6300 7200
Connection ~ 6300 7150
Wire Wire Line
	3550 2150 3550 2350
Wire Wire Line
	3300 2350 3300 2250
Connection ~ 3300 2250
Connection ~ 3550 2250
Wire Wire Line
	10100 1850 10250 1850
Wire Wire Line
	10000 850  10100 850 
Wire Wire Line
	1300 1600 1400 1600
Wire Wire Line
	1400 1600 1400 1700
Wire Wire Line
	1300 1300 1500 1300
Wire Wire Line
	1300 1500 1500 1500
Wire Wire Line
	2250 1150 2250 2250
Connection ~ 2250 1400
Wire Wire Line
	4100 1150 4100 1350
Connection ~ 3850 1250
Connection ~ 4100 1250
Wire Wire Line
	8950 5050 9050 5050
Wire Wire Line
	3200 2250 3550 2250
Connection ~ 2000 1400
Wire Wire Line
	2000 1500 2000 1400
Wire Wire Line
	1900 1400 2250 1400
Wire Wire Line
	2250 2250 2600 2250
Wire Wire Line
	10250 5650 10250 5550
Connection ~ 10250 5550
Wire Wire Line
	4350 7150 4650 7150
Wire Wire Line
	5850 5400 5950 5400
Wire Wire Line
	5950 4500 5850 4500
Wire Wire Line
	5850 4400 5950 4400
Wire Wire Line
	5950 5100 5850 5100
Wire Wire Line
	5950 5200 5850 5200
Wire Wire Line
	2750 1250 2800 1250
Wire Wire Line
	2750 1050 3850 1050
Wire Wire Line
	3850 1050 3850 1350
$Comp
L D D2
U 1 1 5AC556E6
P 3100 1700
F 0 "D2" H 3100 1800 50  0000 C CNN
F 1 "1N4148" H 3100 1600 50  0000 C CNN
F 2 "Diodes_SMD:D_1206" H 3100 1700 50  0001 C CNN
F 3 "" H 3100 1700 50  0001 C CNN
	1    3100 1700
	0    -1   -1   0   
$EndComp
$Comp
L D D3
U 1 1 5AC55ED7
P 3650 1250
F 0 "D3" H 3650 1350 50  0000 C CNN
F 1 "BYS10-45" H 3650 1150 50  0000 C CNN
F 2 "Diodes_SMD:D_SMA" H 3650 1250 50  0001 C CNN
F 3 "" H 3650 1250 50  0001 C CNN
	1    3650 1250
	-1   0    0    1   
$EndComp
Wire Wire Line
	2250 1150 2350 1150
Wire Wire Line
	3400 1250 3500 1250
Wire Wire Line
	3800 1250 4100 1250
$EndSCHEMATC
