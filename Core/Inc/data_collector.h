
#include "stdint.h"

#ifdef __cplusplus
extern "C"
{

#endif

#define WIDTH 800
#define HIGH 480
#define MAX_ITER WIDTH

    void init_collector();

    uint8_t* get_X_mask_buffer();
    uint8_t* get_Y_mask_buffer();

    uint16_t* get_pixel_buffer();

    void load_adc_to_buffers(int itter);

#ifdef __cplusplus
}
#endif
