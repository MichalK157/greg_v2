#include "data_collector.h"
#include "adc_wrapper.h"
#include "memory.h"

volatile uint8_t x_buffer[WIDTH];
volatile uint8_t y_buffer[HIGH];

volatile uint16_t rgb_16bit_buffer[WIDTH];


//uint16_t itter;

void init_collector()
{

    memset((uint16_t*)rgb_16bit_buffer, 0, sizeof(uint16_t) * WIDTH);
    memset((uint8_t*)x_buffer, 0, sizeof(uint8_t) * WIDTH);
    memset((uint8_t*)y_buffer, 0, sizeof(uint8_t) * HIGH);
}

uint8_t* get_X_mask_buffer()
{
    return (uint8_t*) x_buffer;
}

uint8_t* get_Y_mask_buffer()
{
    return (uint8_t*) y_buffer;
}

uint16_t* get_pixel_buffer()
{
    return (uint16_t*) rgb_16bit_buffer;
}



void load_adc_to_buffers(int itter)
{
    rgb_16bit_buffer[itter] = (get_rg()<<8) | get_gb();
    x_buffer[itter] = get_x();
}
