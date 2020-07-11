#include <gui/debug_screen/DebugView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DebugView::DebugView() {
}

void DebugView::setupScreen() {
	DebugViewBase::setupScreen();

	for (uint8_t i = 0; i < DEBUG_LINES; i++) {

		this->lineTextAreas[i].setPosition(2, 2 + i * DEBUG_LINE_HEIGHT, 236, DEBUG_LINE_HEIGHT);
		this->lineTextAreas[i].setColor(PAST_LINE_COLOR);
		this->lineTextAreas[i].setLinespacing(0);
		this->lineTextAreas[i].setTypedText(touchgfx::TypedText(T_DEFAULTPLACEHOLDER));
		this->lineTextAreas[i].setWildcard(this->lineBuffers[i]);

		Unicode::snprintf(this->lineBuffers[i], TEXTAREA_SIZE, "Line %d", i);
		//powerValueTextArea.invalidate();

		add(this->lineTextAreas[i]);
	}
}

void DebugView::tearDownScreen() {
	DebugViewBase::tearDownScreen();
}

void DebugView::printLine(char *line) {
	// grey out previous line
	this->lineTextAreas[this->currentLine].setColor(PAST_LINE_COLOR);
	this->lineTextAreas[this->currentLine].invalidate();

	this->currentLine++;
	if (this->currentLine >= DEBUG_LINES) {
		this->currentLine = 0;
	}

	// update current line
	Unicode::fromUTF8((uint8_t*) line, this->lineBuffers[this->currentLine], TEXTAREA_SIZE);
	this->lineTextAreas[this->currentLine].setColor(CURRENT_LINE_COLOR);
	this->lineTextAreas[this->currentLine].invalidate();
}
