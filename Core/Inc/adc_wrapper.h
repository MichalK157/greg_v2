
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

uint8_t get_r();
uint8_t get_g();
uint8_t get_b();


#ifdef __cplusplus
}
#endif
