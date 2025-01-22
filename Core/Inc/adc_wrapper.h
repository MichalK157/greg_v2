
#include "main.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C"
{

#endif


#define ADC_2_CHANELS 3
#define ADC_3_CHANELS 3
#define MAX_CHANELS ADC_2_CHANELS + ADC_3_CHANELS


void adc_start();
uint32_t* get_adc_buffer();

#ifdef __cplusplus
}
#endif
