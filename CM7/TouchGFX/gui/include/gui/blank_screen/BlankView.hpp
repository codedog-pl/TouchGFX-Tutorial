#ifndef BLANKVIEW_HPP
#define BLANKVIEW_HPP

#include <gui_generated/blank_screen/BlankViewBase.hpp>
#include <gui/blank_screen/BlankPresenter.hpp>

class BlankView : public BlankViewBase
{
public:
    BlankView();
    virtual ~BlankView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // BLANKVIEW_HPP
