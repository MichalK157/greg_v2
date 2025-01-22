#include "data_collector.h"
#include "memory.h"

static volatile uint8_t x_buffer[WIDTH];
static volatile uint8_t y_buffer[HIGH];

static volatile uint8_t r_buffer[WIDTH];
static volatile uint8_t g_buffer[WIDTH];
static volatile uint8_t b_buffer[WIDTH];

static volatile uint16_t itter;

void init_collector()
{
    itter = 0;
    memset(r_buffer, 0, sizeof(uint8_t) * WIDTH);
    memset(g_buffer, 0, sizeof(uint8_t) * WIDTH);
    memset(b_buffer, 0, sizeof(uint8_t) * WIDTH);
    memset(x_buffer, 0, sizeof(uint8_t) * WIDTH);
    memset(y_buffer, 0, sizeof(uint8_t) * HIGH);
}

uint8_t* get_X_mask_buffer()
{
    return x_buffer;
}

uint8_t* get_Y_mask_buffer()
{
    return y_buffer;
}

uint8_t* get_R_buffer()
{
    return r_buffer;
}

uint8_t* get_G_buffer()
{
    return g_buffer;
}

uint8_t* get_B_buffer()
{
    return b_buffer;
}

void load_adc_to_buffers(const uint32_t* adc_buffer)
{
    r_buffer[itter] = adc_buffer[0];
    g_buffer[itter] = adc_buffer[1];
    b_buffer[itter] = adc_buffer[2];
    x_buffer[itter] = adc_buffer[3];

    itter++;
    if(itter==MAX_ITER) // it should reload when framebuffer will update display 
    {
        itter=0;
    }
}
