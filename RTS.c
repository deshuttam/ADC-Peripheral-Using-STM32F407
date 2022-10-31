PROCESSOR_SPEC { 
NAME arm7; //arm Cortex 
CLOCK FREQUENCY =60MHz;
}

ENTRY_POINT { 
QUALIFIER = SYNCHRONOUS_BLOCKING; 
}

BUS_SPEC { 
BASE_ADDRESS = Ox40012000; //Base Address of ADC 
REG_ACCESS TYPE = MEMORY_MAPPED; 
}

COMPILER_SPEC{ 
COMPILER NAME = GCC; 
}

CODEGEN_SPEC{ 
thin_api = yes, 
env_file_name = "env.h"; 
env_file_location = "./"; //change to dedicated folder if possible
}
