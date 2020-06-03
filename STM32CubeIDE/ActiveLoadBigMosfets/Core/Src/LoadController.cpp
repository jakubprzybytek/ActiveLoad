#include "LoadController.hpp"

void LoadController::enable() {
	HAL_DAC_Start(this->hdac, DAC_CHANNEL_1);
	HAL_GPIO_WritePin(Load_Op_Amps_Ctrl_GPIO_Port, Load_Op_Amps_Ctrl_Pin, GPIO_PIN_SET);

	this->enabled = true;
}

void LoadController::disable() {
	HAL_GPIO_WritePin(Load_Op_Amps_Ctrl_GPIO_Port, Load_Op_Amps_Ctrl_Pin, GPIO_PIN_RESET);
	HAL_DAC_Stop(this->hdac, DAC_CHANNEL_1);

	this->enabled = false;
}

void LoadController::setLoad(uint16_t loadLevel) {
	if (loadLevel == 0 && this->enabled == true) {
		disable();
	}

	if (loadLevel > 50) {
		loadLevel = 50;
	}

	HAL_DAC_SetValue(this->hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, loadLevel);

	if (loadLevel > 0 && this->enabled == false) {
		enable();
	}
}
