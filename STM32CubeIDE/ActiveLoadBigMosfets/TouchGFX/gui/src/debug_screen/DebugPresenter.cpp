#include <gui/debug_screen/DebugView.hpp>
#include <gui/debug_screen/DebugPresenter.hpp>

DebugPresenter::DebugPresenter(DebugView &v) : view(v) {
}

void DebugPresenter::activate() {
}

void DebugPresenter::deactivate() {
}

void DebugPresenter::lineLogged(char *line) {
	this->view.printLine(line);
}
