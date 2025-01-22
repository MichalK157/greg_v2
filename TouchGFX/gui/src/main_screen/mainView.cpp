#include <gui/main_screen/mainView.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <cstdint>
#include "adc_wrapper.h"

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

	__background.setColor(touchgfx::Color::getColorFromRGB(r++, g++, b++));

	uint16_t* framebuffer = reinterpret_cast<uint16_t*>(touchgfx::HAL::getInstance()->getTFTFrameBuffer());
	uint32_t* buff = reinterpret_cast<uint32_t*>(get_adc_buffer());
	if (!framebuffer) {
	    // Add a debug breakpoint or log an error if framebuffer is null
	    return;
	}
	    uint16_t screenWidth = 800;

	   framebuffer[20 * screenWidth + 0] = (buff[2] << 11) | (buff[1] << 5) | buff[0];
	   framebuffer[20 * screenWidth + 1] = (buff[2] << 11) | (buff[1] << 5) | buff[0];
	   framebuffer[20 * screenWidth + 2] = (buff[2] << 11) | (buff[1] << 5) | buff[0];
	   framebuffer[20 * screenWidth + 3] = (buff[2] << 11) | (buff[1] << 5) | buff[0];
	   framebuffer[20 * screenWidth + 4] = (buff[2] << 11) | (buff[1] << 5) | buff[0];


	touchgfx::HAL::getInstance()->unlockFrameBuffer();
	touchgfx::Rect rect(0, 0, 800, 480); // Define the area to refresh
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
