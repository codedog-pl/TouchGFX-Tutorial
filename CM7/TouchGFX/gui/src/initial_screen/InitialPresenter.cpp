#include <gui/initial_screen/InitialView.hpp>
#include <gui/initial_screen/InitialPresenter.hpp>

InitialPresenter::InitialPresenter(InitialView& v)
    : view(v)
{

}

void InitialPresenter::activate()
{

}

void InitialPresenter::deactivate()
{

}

void InitialPresenter::testPinStateChanged(bool state)
{
	view.testPinStateChanged(state);
}
