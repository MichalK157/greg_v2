#include <gui/main_screen/mainView.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <cstdint>
#include "adc_wrapper.h"
#include "data_collector.h"
#include "memory.h"

mainView::mainView()
{
	r = 0;
	g = 100;
	b = 200;
}

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

	//__background.setColor(touchgfx::Color::getColorFromRGB(r++, g++, b++));


	Status_Frame* status = reinterpret_cast<Status_Frame*>(get_frame_status());

		uint16_t* framebuffer = reinterpret_cast<uint16_t*>(touchgfx::HAL::getInstance()->getTFTFrameBuffer());

		if (!framebuffer) {
			    // Add a debug breakpoint or log an error if framebuffer is null
			    return;
			}

		uint16_t* buff_pixel = reinterpret_cast<uint16_t*>(get_pixel_buffer());
		uint16_t*swope = reinterpret_cast<uint16_t*>(get_pixel_buffer());
		if(*status == Status_Frame_New)
	    {
			memcpy((uint16_t*)swope,(uint16_t*)buff_pixel,sizeof(uint16_t)*120*200);
	    	set_frame_status(Status_Frame_Loaded);
	    }
		uint16_t row = 120;
	    uint16_t wide = 200;
	    uint16_t screenWidth = 800;

	    for(uint16_t i = 0; i<row;i++)
	    {
	    	//memcpy((uint16_t*)framebuffer+i*screenWidth,(uint16_t*)swope+i*wide,sizeof(uint16_t)*wide);
	    	for(uint16_t j=0; j<wide;j++)
	    	{
	    		framebuffer[i*screenWidth + j] = swope[i*wide+j];
	    	}
	    }

	    touchgfx::HAL::getInstance()->unlockFrameBuffer();
	    touchgfx::Rect rect(0, 0, 200,120 ); // Define the area to refresh
	    invalidateRect(rect);



}

/*
void CustomSquareWidget::setSquareProperties(int16_t x, int16_t y, uint16_t size, uint32_t color) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->color = color;
    invalidate(); // Trigger a redraw
}

void CustomSquareWidget::draw(const touchgfx::Rect& invalidatedArea) const {
	uint16_t* framebuffer = reinterpret_cast<uint16_t*>(touchgfx::HAL::getInstance()->lockFrameBuffer());
    if (!framebuffer) return;

    uint16_t screenWidth = touchgfx::HAL::DISPLAY_WIDTH;
    uint16_t screenHeight = touchgfx::HAL::DISPLAY_HEIGHT;

    for (int16_t i = y; i < y + size && i < screenHeight; ++i) {
        for (int16_t j = x; j < x + size && j < screenWidth; ++j) {
            framebuffer[i * screenWidth + j] = static_cast<uint16_t>(color);
        }
    }
    touchgfx::HAL::getInstance()->unlockFrameBuffer();
}

touchgfx::Rect CustomSquareWidget::getMinimalRect() const {
    return touchgfx::Rect(x, y, size, size);
}
*/
