#ifndef DEBUGVIEW_HPP
#define DEBUGVIEW_HPP

#include <gui_generated/debug_screen/DebugViewBase.hpp>
#include <gui/debug_screen/DebugPresenter.hpp>
#include <touchgfx/Color.hpp>

#define DEBUG_LINES 14
#define DEBUG_LINE_HEIGHT 22

class DebugView: public DebugViewBase {
private:
	const colortype CURRENT_LINE_COLOR = touchgfx::Color::getColorFrom24BitRGB(180, 179, 179);
	const colortype PAST_LINE_COLOR = touchgfx::Color::getColorFrom24BitRGB(100, 100, 100);

	static const uint16_t TEXTAREA_SIZE = 20;
	touchgfx::TextAreaWithOneWildcard lineTextAreas[DEBUG_LINES];
	touchgfx::Unicode::UnicodeChar lineBuffers[DEBUG_LINES][TEXTAREA_SIZE];
	uint8_t currentLine = DEBUG_LINES - 1;

public:
	DebugView();
	virtual ~DebugView() {
	}
	virtual void setupScreen();
	virtual void tearDownScreen();

	void printLine(char *line);
protected:
};

#endif // DEBUGVIEW_HPP
