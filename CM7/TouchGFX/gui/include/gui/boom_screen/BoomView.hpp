#ifndef BOOMVIEW_HPP
#define BOOMVIEW_HPP

#include <gui_generated/boom_screen/BoomViewBase.hpp>
#include <gui/boom_screen/BoomPresenter.hpp>

class BoomView : public BoomViewBase
{
public:
    BoomView();
    ~BoomView() {}
    void setupScreen();
    void tearDownScreen();
private:
};

#endif // BOOMVIEW_HPP
