#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/mainViewBase.hpp>
#include <gui/main_screen/mainPresenter.hpp>
#include <touchgfx/widgets/Widget.hpp>
#include <touchgfx/hal/Types.hpp>

class CustomSquareWidget : public touchgfx::Widget {
public:
    CustomSquareWidget() : x(0), y(0), size(50), color(0xFFFF) {} // Default values

    void setSquareProperties(int16_t x, int16_t y, uint16_t size, uint32_t color) {
        this->x = x;
        this->y = y;
        this->size = size;
        this->color = color;
        invalidate(); // Mark the widget for redrawing
    }

    virtual void draw(const touchgfx::Rect& invalidatedArea) const override {
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

    virtual touchgfx::Rect getSolidRect() const override {
        return touchgfx::Rect(x, y, size, size); // Defines the solid rectangular area of the widget
    }

private:
    int16_t x, y;     // Position
    uint16_t size;    // Square size
    uint32_t color;   // Color (ARGB or RGB format)
};


class mainView : public mainViewBase
{
public:
    mainView();
    virtual ~mainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void updateScrean();
protected:
    uint8_t r,g,b;
    CustomSquareWidget squareWidget;
};




#endif // MAINVIEW_HPP
