
#include "adc_wrapper.h"
#include "stdint.h"

static volatile uint32_t adc_buffer[MAX_CHANELS];

void adc_start()
{
    ADC_HandleTypeDef hadc2;
    ADC_HandleTypeDef hadc3;
    HAL_ADC_Start_DMA(&hadc2, (uint32_t*)adc_buffer, ADC_2_CHANELS);
    HAL_ADC_Start_DMA(&hadc3, (uint32_t*)adc_buffer + ADC_2_CHANELS, ADC_3_CHANELS);
}

uint32_t* get_adc_buffer()
{
    return (uint32_t*)adc_buffer;
}
