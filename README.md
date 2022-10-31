# Device Driver Generation of ADC Peripheral Using STM32F407
By Uttam Deshpande et. al.,

Device Driver solution for STM32F407 ADC (Analog to Digital Converter) peripheral is demonstrated in this work. ADC is used in many applications like Digital Signal Processing, Music Recording etc.. 

## Introduction
The first step to understand the working of ADC and about the board was through Data Sheet and the components related to ADC where studied. The analog value is provided as input to specified channel and components related to ADC where studied. The analog value is provided as input to specified channel and prescale, sampling, data alignment, resolution bit is set. The conversion is started by setting Start bit and at the end of the conversion the converted data is stored. 

There are four AP's (Application programming interface) used one is for setting prescale next one to set adc parameters like resolution and data alignment and other two are used for taking channel sampling rate, sequence and start the conversion and store converted Data. This APl's are given as sequence in DPS file. For drivers we write two files that is RTS (Run Time Specification) and DPS (Device programming Specification). In DPS we specify all the details of the ADC registers and function of each register and its bits. In RTS file we define the Base address of the ADC. The company has its own tool for making a driver and hat tool is DDGen. DPS and RTS file are given as input to DDGen Tool and the driver is generated. The driver is first tested in Keil software by write a test code for it. Then later the code is dumped on the STM32F407 board and verified by giving Potentiometer input and checking the Data Register. 

![image](https://user-images.githubusercontent.com/107185323/198996560-9b044c6e-e3d7-43e3-95e0-61576b08f006.png)

Requirements: Software
* DDGen Software
* Microvsion Keil
* STM32CubeIDE

Hardware
* STM32F407

### REGISTERS
ADC status register (ADC_SR):  This Register is used to check the status of the bits.
ADC control register 1(ADC_CRI): This Register is used to set ADC parameter resolution and change modes.
ADC control register 2(ADC_CR2): This Register is used to tum on ADC and start the conversion.
ADC sample time register 1(ADC_SMPR1):  This Register used to set sampling rate of each Channel.
ADC sample time register 2(ADC_SMPR2): This Register is also used to set sampling time of remaining channels.
ADC regular sequence register 1(ADC_SQRI): This Register takes the length of sequence to be Converted.
ADC regular sequence register 2(ADC_SQR2):  This Register takes sequence of channel Conversion.
ADC regular sequence register 3(ADC_SQR3):  This Register also takes sequence of remaining Channels.
ADC regular data register (ADC_DR):  This Register stores the converted Data.
	
### ADC procedure
Step I: Configure clock by setting prescale value.
Step 2: configure channel by taking channel length sampling rate and sequence number as input for sequence and sample time register.
Step 3: set resolution and alignment bit in control register.
Step 4:  Set the SWSTART bit in control register to start the conversion.
Step 5:  Check for EOC bit in status register if its set the analog input is converted and value is stored in data register.


### API's Used
1.	adc_start@:  This API sets Prescale for clock division.
2.	config_channeJO: This API configures number of conversions and sampling rate.
3.	configure_adc_parameters@:  This API configures resolution and data alignment.
4.	adc_conv():  This API turns on ADC and starts the conversion.

## Test Cases
Using Potentiometer to provide input under debugging mode
Step I: The setting and resetting of all the bits is checked under simulation mode. 
Step 2: The Driver code is dumped in Hardware and debugging mode is turned on.
Step 3: In Debugging mode setting and resetting of bits is with respect to program is checked by line by line execution.
Step 4: Then the potentiometer is connected to the assigned in input pin and rotated to give analog input. 
Step 5: The program is executed completely and the Data Register is updated with Converted Value.


