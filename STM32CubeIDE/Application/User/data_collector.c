#include "data_collector.h"
#include "adc_wrapper.h"
#include "memory.h"

static volatile uint8_t x_buffer[WIDTH];
static volatile uint8_t y_buffer[HIGH];

static volatile uint8_t r_buffer[WIDTH];
static volatile uint8_t g_buffer[WIDTH];
static volatile uint8_t b_buffer[WIDTH];

//uint16_t itter;

void init_collector()
{

    memset((uint8_t*)r_buffer, 0, sizeof(uint8_t) * WIDTH);
    memset((uint8_t*)g_buffer, 0, sizeof(uint8_t) * WIDTH);
    memset((uint8_t*)b_buffer, 0, sizeof(uint8_t) * WIDTH);
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

uint8_t* get_R_buffer()
{
    return (uint8_t*) r_buffer;
}

uint8_t* get_G_buffer()
{
    return (uint8_t*) g_buffer;
}

uint8_t* get_B_buffer()
{
    return (uint8_t*) b_buffer;
}

void load_adc_to_buffers(int itter)
{
    r_buffer[itter] = get_r();
    g_buffer[itter] = get_g();
    b_buffer[itter] = get_b();


    if(itter==MAX_ITER) // it should reload when framebuffer will update display
    {
        itter=0;
    }
}
