#ifndef BLANKPRESENTER_HPP
#define BLANKPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class BlankView;

class BlankPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    BlankPresenter(BlankView& v);

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

    virtual ~BlankPresenter() {};

private:
    BlankPresenter();

    BlankView& view;
};

#endif // BLANKPRESENTER_HPP
