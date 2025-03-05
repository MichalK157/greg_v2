#include "../../include/gui/main_screen/mainView.hpp"
#include "adc_wrapper.h"
#include "data_collector.h"
#include "memory.h"
#include <cstdint>
#include <gui/main_screen/mainView.hpp>
#include <stdlib.h>
#include <touchgfx/Color.hpp>
#include <touchgfx/hal/HAL.hpp>

void mainView::setupScreen()
{
    mainViewBase::setupScreen();
}

void mainView::tearDownScreen()
{
    mainViewBase::tearDownScreen();
}

void mainView::updateScrean()
{
    Status_Frame* status = reinterpret_cast<Status_Frame*>(get_frame_status());
    if(counter++%4==0)
    {
        return;
    }
    if(*status == Status_Frame_Loaded)
    {
        return;
    }

    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    //touchgfx::HAL::getInstance()->lockFrameBuffer();
    uint16_t* framebuffer = reinterpret_cast<uint16_t*>(touchgfx::HAL::getInstance()->getTFTFrameBuffer());
    uint16_t* swope = reinterpret_cast<uint16_t*>(get_swope());
    uint16_t* buff = reinterpret_cast<uint16_t*>(get_pixel_buffer());
    memcpy((uint16_t*)swope,(uint16_t*)buff,sizeof(uint16_t)*120*200);

    if(!framebuffer)
    {
        // Add a debug breakpoint or log an error if framebuffer is null
        return;
    }
    
    uint16_t row = 120;
    uint16_t wide = 200;
    uint16_t screenWidth = getScreenWidth();
    uint16_t screanHigh = getScreenHeight();

    bresenham_upscale(swope, framebuffer, wide, row, screenWidth, screanHigh);
    // bilinear_upscale(swope, framebuffer, wide, row, screenWidth, screanHigh);
    // simple_upscale(swope, framebuffer, wide, row, screenWidth, screanHigh);
    set_frame_status(Status_Frame_Loaded);
    touchgfx::HAL::getInstance()->unlockFrameBuffer();
    touchgfx::Rect rect(0, 0, 400, 480); // Define the area to refresh
    invalidateRect(rect);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
}

void mainView::simple_upscale(uint16_t* src, uint16_t* dst, uint16_t src_w, uint16_t src_h, uint16_t dst_w,
                              uint16_t dst_h)
{
    for(uint16_t i = 0; i < src_h - 1; i++)
    {
        for(uint16_t j = 0; j < src_w - 1; j++)
        {
            for(uint8_t y = 0; y < scale; y++)
            {
                dst[(((i * scale) + y) * dst_w) + (scale * j )] = src[i * src_w + j];
                dst[(((i * scale) + y) * dst_w) + (scale * j + 1)] = src[i * src_w + j];
                dst[(((i * scale) + y) * dst_w) + (scale * j + 2)] = src[i * src_w + j];
                dst[(((i * scale) + y) * dst_w) + (scale * j + 3)] = src[i * src_w + j];
            }
        }
    }
}

void mainView::bilinear_upscale(uint16_t* src, uint16_t* dst, uint16_t src_w, uint16_t src_h, uint16_t dst_w,
                                uint16_t dst_h)
{
    for(uint16_t i = 0; i < src_h - 1; i++)
    {
        for(uint16_t j = 0; j < src_w - 1; j++)
        {
            for(uint8_t y = 0; y < scale; y++)
            {
                for(uint8_t x = 0; x < scale; x++)
                {

                    dst[(((i * scale) + y) * dst_w) + (scale * j + x)] =
                        bilinear(src[i * src_w + j], src[i * src_w + j + 1], src[(i + 1) * src_w + j],
                                 src[(i + 1) * src_w + j + 1], x, y);
                }
            }
        }
    }
}

uint16_t mainView::bilinear(uint16_t P00, uint16_t P01, uint16_t P10, uint16_t P11, uint8_t dx, uint8_t dy)
{
    // it is too slow
    uint8_t r00 = (P00 >> 11) & 0x1F;
    uint8_t g00 = (P00 >> 5) & 0x3F;
    uint8_t b00 = P00 & 0x1F;

    uint8_t r01 = (P01 >> 11) & 0x1F;
    uint8_t g01 = (P01 >> 5) & 0x3F;
    uint8_t b01 = P01 & 0x1F;

    uint8_t r10 = (P10 >> 11) & 0x1F;
    uint8_t g10 = (P10 >> 5) & 0x3F;
    uint8_t b10 = P10 & 0x1F;

    uint8_t r11 = (P11 >> 11) & 0x1F;
    uint8_t g11 = (P11 >> 5) & 0x3F;
    uint8_t b11 = P11 & 0x1F;

    uint8_t r = ((r00 * (3 - dx) * (3 - dy) + r01 * dx * (3 - dy) + r10 * (3 - dx) * dy + r11 * dx * dy) >> 4);
    uint8_t g = ((g00 * (3 - dx) * (3 - dy) + g01 * dx * (3 - dy) + g10 * (3 - dx) * dy + g11 * dx * dy) >> 4);
    uint8_t b = ((b00 * (3 - dx) * (3 - dy) + b01 * dx * (3 - dy) + b10 * (3 - dx) * dy + b11 * dx * dy) >> 4);

    return (r << 11) | (g << 5) | b;

    // return (uint16_t)(P00 * (1 - dx) * (1 - dy) + P01 * dx * (1 - dy) + P10 * (1 - dx) * dy + P11 * dx * dy);
}

void mainView::bresenham_upscale(uint16_t* src, uint16_t* dst, uint16_t src_w, uint16_t src_h, uint16_t dst_w,
                                 uint16_t dst_h)
{
    for(uint16_t sy = 0; sy < src_h; sy++)
    {
        for(uint16_t sx = 0; sx < src_w; sx++)
        {
            uint16_t pixel = src[sy * src_w + sx]; // Pobierz piksel źródłowy

            // Wstawiamy ten sam piksel do obszaru SCALE x SCALE
            for(uint16_t dy = 0; dy < scale; dy++)
            {
                for(uint16_t dx = 0; dx < scale; dx++)
                {
                    uint16_t dst_x = (sx << 2) + dx; // sx * 4 → shift bitowy przyspiesza mnożenie
                    uint16_t dst_y = (sy << 2) + dy; // sy * 4 → szybkie przesunięcie bitowe
                    dst[dst_y * dst_w + dst_x] = pixel;
                }
            }
        }
    }
}