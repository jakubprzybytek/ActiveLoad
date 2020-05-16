#include "LoadController.hpp"

void LoadController::enable() {
	HAL_DAC_Start(hdac, DAC_CHANNEL_1);
	HAL_GPIO_WritePin(Load_Op_Amps_Ctrl_GPIO_Port, Load_Op_Amps_Ctrl_Pin, GPIO_PIN_SET);
}

void LoadController::disable() {
	HAL_GPIO_WritePin(Load_Op_Amps_Ctrl_GPIO_Port, Load_Op_Amps_Ctrl_Pin, GPIO_PIN_RESET);
	HAL_DAC_Stop(hdac, DAC_CHANNEL_1);
}

void LoadController::setLoad(uint16_t loadLevel) {
	if (loadLevel == 0 && enabled == true) {
		disable();
	}

	HAL_DAC_SetValue(hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, loadLevel);

	if (loadLevel > 0 && enabled == false) {
		enable();
	}
}
