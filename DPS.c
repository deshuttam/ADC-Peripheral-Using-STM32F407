DPS File: 
DPS SEQENCES 
DESCRIPTION = "This function configure the ADC clock";
SEQUENCE adc_start 
{
INPUT unsigned int adon; 
INPUT unsigned int cont; 
ADC_CR2.ADON=adon; 
ADC_CR2.CONT=cont;
} 
DESCRIPTION = "This function is for Channel selection";
SEQUENCE config_channel
{
INPUT unsigned int channel_conversions; 
INPUT unsigned int sample_ratel; 
INPUT unsigned int seq; 

ADC_SQR1.L=channel_conversions; 
ADC_SMPR1.SMP12=sample_ratel ;
ADC_SQR3.SQI=seq;
}

DESCRIPTION = "this function Configure the ADC parameters”;
SEQUENCE configure_ADC_parameters 
{
INPUT unsigned int resolution; 
INPUT unsigned int data_alignment;


ADC_CR1.RES=resolution; 
ADC_CR2.ALIGN=data_alignment;
}

DESCRIPTION ="This function is for ADC conversion”;
SEQUENCE ADC_conv
{ 
OUTPUT unsigned int data, 
ADC_ CR2.SWSTART=1;
poll until(ADC_SR.EOC =1){ 
ADC _CR2.EOCS =0; 
data = ADC_DR.DATA;
}
}

BUS_SPEC{ 
REG_ACCESS_TYPE = MEMORY_MAPPED; 
}
