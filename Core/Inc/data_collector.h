
#include "stdint.h"

#ifdef __cplusplus
extern "C"
{

#endif

#define WIDTH 200
#define HIGH 120
#define MAX_ITER WIDTH


	typedef enum _Status_Frame{
		Status_Frame_Loaded,
		Status_Frame_New,
	} Status_Frame;

	void init_collector();

    uint16_t* get_pixel_buffer();
    uint16_t* get_swope();
    Status_Frame* get_frame_status();
    void set_frame_status(Status_Frame frame_status);

    void frame_dump();
    void load_adc_to_buffers(int itter);

#ifdef __cplusplus
}
#endif
