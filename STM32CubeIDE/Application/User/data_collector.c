#include "data_collector.h"
#include "adc_wrapper.h"
#include <string.h>


volatile uint16_t rgb_16bit_buffer[200*120];
volatile uint16_t rgb_16bit_buffer_swope[200*120];
volatile Status_Frame status;

//uint16_t itter;

void init_collector()
{

    memset((uint16_t*)rgb_16bit_buffer, 0, sizeof(uint16_t) * 120*200);
    memset((uint16_t*)rgb_16bit_buffer_swope, 0, sizeof(uint16_t) * 120*200);
    status = Status_Frame_Loaded;

}



uint16_t* get_pixel_buffer()
{
	return (uint16_t*) rgb_16bit_buffer;
}
uint16_t* get_swope()
{
	return (uint16_t*) rgb_16bit_buffer_swope;
}
Status_Frame* get_frame_status()
{
	return (Status_Frame*)&status;
}

void set_frame_status(Status_Frame frame_status)
{
	status = frame_status;
}

void frame_dump()
{
	//memcpy((uint16_t*)rgb_16bit_buffer_swope, (uint16_t*)rgb_16bit_buffer, sizeof(rgb_16bit_buffer_swope));
	status = Status_Frame_New;
}

void load_adc_to_buffers(int itter)
{
	rgb_16bit_buffer[itter] = ((get_r() >> 3) << 11) | ((get_g() >> 2) << 5) | (get_b() >> 3);
}
