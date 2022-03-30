#ifndef BOOMPRESENTER_HPP
#define BOOMPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class BoomView;

class BoomPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    BoomPresenter(BoomView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    void deactivate();

    ~BoomPresenter() {};

private:
    BoomPresenter();

    BoomView& view;
};

#endif // BOOMPRESENTER_HPP
