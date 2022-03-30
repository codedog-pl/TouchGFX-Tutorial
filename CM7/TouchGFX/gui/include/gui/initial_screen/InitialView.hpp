#ifndef INITIALVIEW_HPP
#define INITIALVIEW_HPP

#include <gui_generated/initial_screen/InitialViewBase.hpp>
#include <gui/initial_screen/InitialPresenter.hpp>

class InitialView : public InitialViewBase
{
public:
    InitialView();
    ~InitialView() {}
    void setupScreen();
    void tearDownScreen();
    void handleTickEvent();
private:
    uint32_t coreTemp = 20;
};

#endif // INITIALVIEW_HPP
