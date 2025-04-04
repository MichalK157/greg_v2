
#include "adc_wrapper.h"
#include "stdint.h"
#include "memory.h"

volatile uint16_t adc_buffer[3];

void adc_start()
{
	memset((uint16_t*)&adc_buffer, 0, sizeof(adc_buffer));
    extern ADC_HandleTypeDef hadc2;
    HAL_ADC_Start_DMA(&hadc2, (uint32_t*)&adc_buffer, sizeof(uint16_t)*3);

}



uint8_t get_r()
{
	return (uint8_t) adc_buffer[0];
}
uint8_t get_g()
{
	return (uint8_t) adc_buffer[1];
}
uint8_t get_b()
{
	return (uint8_t) adc_buffer[2];
}
