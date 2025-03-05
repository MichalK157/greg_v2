#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui/main_screen/mainPresenter.hpp>
#include <gui_generated/main_screen/mainViewBase.hpp>
#include <touchgfx/hal/Types.hpp>
#include <touchgfx/widgets/Widget.hpp>


#define SCALE 4

class mainView : public mainViewBase
{
  public:
    mainView() : scale(SCALE),counter(0) {}
    virtual ~mainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void updateScrean();

  protected:
    uint8_t scale;
    uint8_t counter;

  private:
    void simple_upscale(uint16_t* src, uint16_t* dst, uint16_t src_w, uint16_t src_h, uint16_t dst_w, uint16_t dst_h);
    void bilinear_upscale(uint16_t* src, uint16_t* dst, uint16_t src_w, uint16_t src_h, uint16_t dst_w, uint16_t dst_h);
    uint16_t bilinear(uint16_t P00, uint16_t P01, uint16_t P10, uint16_t P11, uint8_t x, uint8_t y);
    void bresenham_upscale(uint16_t* src, uint16_t* dst, uint16_t src_w, uint16_t src_h, uint16_t dst_w, uint16_t dst_h);
};

#endif // MAINVIEW_HPP
