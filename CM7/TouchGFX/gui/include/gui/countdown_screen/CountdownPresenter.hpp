#ifndef COUNTDOWNPRESENTER_HPP
#define COUNTDOWNPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class CountdownView;

class CountdownPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    CountdownPresenter(CountdownView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    void secondTick();

    virtual ~CountdownPresenter() {};

private:
    CountdownPresenter();

    CountdownView& view;
};

#endif // COUNTDOWNPRESENTER_HPP
