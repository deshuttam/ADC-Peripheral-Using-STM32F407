# Device Driver Generation of ADC Peripheral Using STM32F407
By Uttam Deshpande et. al.,

Device Driver solution for STM32F407 ADC (Analog to Digital Converter) peripheral is demonstrated in this work. ADC is used in many applications like Digital Signal Processing, Music Recording etc.. 

## Introduction
The first step to understand the working of ADC and about the board was through Data Sheet and the components related to ADC where studied. The analog value is provided as input to specified channel and components related to ADC where studied. The analog value is provided as input to specified channel and prescale, sampling, data alignment, resolution bit is set. The conversion is started by setting Start bit and at the end of the conversion the converted data is stored. 

There are four AP's (Application programming interface) used one is for setting prescale next one to set adc parameters like resolution and data alignment and other two are used for taking channel sampling rate, sequence and start the conversion and store converted Data. This APl's are given as sequence in DPS file. For drivers we write two files that is RTS (Run Time Specification) and DPS (Device programming Specification). In DPS we specify all the details of the ADC registers and function of each register and its bits. In RTS file we define the Base address of the ADC. The company has its own tool for making a driver and hat tool is DDGen. DPS and RTS file are given as input to DDGen Tool and the driver is generated. The driver is first tested in Keil software by write a test code for it. Then later the code is dumped on the STM32F407 board and verified by giving Potentiometer input and checking the Data Register. 

![image](https://user-images.githubusercontent.com/107185323/198996560-9b044c6e-e3d7-43e3-95e0-61576b08f006.png)

