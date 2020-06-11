#include "stm32l1xx_hal.h"

#include "devices/RVT28AETNWC00.hpp"
#include "main.h"

void RVT28AETNWC00::init() {

	HAL_GPIO_WritePin(Display_Reset_GPIO_Port, Display_Select_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(Display_Reset_GPIO_Port, Display_Reset_Pin, GPIO_PIN_SET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(Display_Reset_GPIO_Port, Display_Reset_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(Display_Reset_GPIO_Port, Display_Reset_Pin, GPIO_PIN_SET);
	HAL_Delay(50);

	HAL_GPIO_WritePin(Display_Write_GPIO_Port, Display_Write_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Display_Read_GPIO_Port, Display_Read_Pin, GPIO_PIN_SET);

	writeCommand(0x01); // Software reset
	HAL_Delay(5);
	writeCommand(RVT28AETNWC00_COMMAND_DISPLAY_OFF); //Display off

	//---------------------------------------------------------
	writeCommand(0xcf); //Power control B
	writeData(0x00);
	writeData(0x83);
	writeData(0x30);
	writeCommand(0xed); //Power on sequence control
	writeData(0x64);
	writeData(0x03);
	writeData(0x12);
	writeData(0x81);
	writeCommand(0xe8); //Driver timing control A
	writeData(0x85);
	writeData(0x01);
	writeData(0x79);
	writeCommand(0xcb); //Power control A
	writeData(0x39);
	writeData(0x2c);
	writeData(0x00);
	writeData(0x34);
	writeData(0x02);
	writeCommand(0xf7); //Pump ratio control
	writeData(0x20);
	writeCommand(0xea); //Driver timing control B
	writeData(0x00);
	writeData(0x00);
	//-----------------------Power Control--------------------
	writeCommand(0xc0); // Power Control 1
	writeData(0x26);
	writeCommand(0xc1); // Power Control 2
	writeData(0x11);
	//-------------------VCOM setting ------------------------
	writeCommand(0xc5); // VCOM Control
	writeData(0x35);
	writeData(0x3e);
	writeCommand(0xc7); // VCOM Control
	writeData(0xbe);
	//--------------Memory Access Control--------------
	writeCommand(0x36); //Memory Access Control
	writeData(0b01001000); //my, mx, mv, ml, BGR, mh, 0.0
	writeCommand(0x3a); // Pixel Format set
	writeData(0x55); // 16bit /pixel

	//------------------ Frame Rate------------------------
	writeCommand(0xb1); // Frame rate
	writeData(0x00);
	writeData(0x10);
	//------------------Gamma--------------------------------
	writeCommand(0xf2); // 3 Gamma Function Disable
	writeData(0x08);
	writeCommand(0x26); // Gamma set 4 gamma curve 01/02/04/08
	writeData(0x01);
	writeCommand(0xE0); // Positive Gamma Correction
	writeData(0x1f);
	writeData(0x1a);
	writeData(0x18);
	writeData(0x0a);
	writeData(0x0f);
	writeData(0x06);
	writeData(0x45);
	writeData(0x87);
	writeData(0x32);
	writeData(0x0a);
	writeData(0x07);
	writeData(0x02);
	writeData(0x07);
	writeData(0x05);
	writeData(0x00);
	writeCommand(0xE1); // Negative Gamma Correction
	writeData(0x00);
	writeData(0x25);
	writeData(0x27);
	writeData(0x05);
	writeData(0x10);
	writeData(0x09);
	writeData(0x3a);
	writeData(0x78);
	writeData(0x4d);
	writeData(0x05);
	writeData(0x18);
	writeData(0x0d);
	writeData(0x38);
	writeData(0x3a);
	writeData(0x1f);
	//-------------------ddram------------------------
	writeCommand(0x2a); // Column Set
	writeData(0x00);
	writeData(0x00);
	writeData(0x00);
	writeData(0xEF);
	writeCommand(0x2b); // Page address set
	writeData(0x00);
	writeData(0x00);
	writeData(0x01);
	writeData(0x3F);
	writeCommand(0xb7); // Entry mode set
	writeData(0x07);
	//---------------------Display-----------------------
	writeCommand(0xb6); // Display function control
	writeData(0x0a);
	writeData(0x82);
	writeData(0x27);
	writeData(0x00);

	writeCommand(0x11); // Sleep out
	HAL_Delay(100);
	writeCommand(RVT28AETNWC00_COMMAND_DISPLAY_ON); // Display on
	HAL_Delay(50);
}

void RVT28AETNWC00::deinit() {
	writeCommand(RVT28AETNWC00_COMMAND_SLEEP_IN); //Display off
}

void RVT28AETNWC00::writeCommand(uint8_t command) {

	HAL_GPIO_WritePin(Display_Data_Command_GPIO_Port, Display_Data_Command_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(Display_Write_GPIO_Port, Display_Write_Pin, GPIO_PIN_RESET);
	GPIOC->ODR = command;
	HAL_GPIO_WritePin(Display_Write_GPIO_Port, Display_Write_Pin, GPIO_PIN_SET);
}

void RVT28AETNWC00::writeData(uint16_t data) {

	HAL_GPIO_WritePin(Display_Data_Command_GPIO_Port, Display_Data_Command_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(Display_Write_GPIO_Port, Display_Write_Pin, GPIO_PIN_RESET);
	GPIOC->ODR = data;
	HAL_GPIO_WritePin(Display_Write_GPIO_Port, Display_Write_Pin, GPIO_PIN_SET);
}

void RVT28AETNWC00::writeData(uint16_t *pixels, uint16_t x, uint16_t y, uint16_t width, uint16_t height) {

	uint16_t endY = y + height - 1;

	writeCommand(0x2a); // Column set
	writeData(0x00);
	writeData(x);
	writeData(0x00);
	writeData(x + width - 1);

	writeCommand(0x2b); // Page address set
	writeData(y >> 8);
	writeData(y);
	writeData(endY >> 8);
	writeData(endY);

	writeCommand(0x2c);

	HAL_GPIO_WritePin(Display_Data_Command_GPIO_Port, Display_Data_Command_Pin, GPIO_PIN_SET);

	for (uint16_t i = 0; i < width * height; i++) {
		HAL_GPIO_WritePin(Display_Write_GPIO_Port, Display_Write_Pin, GPIO_PIN_RESET);
		GPIOC->ODR = pixels[i];
		HAL_GPIO_WritePin(Display_Write_GPIO_Port, Display_Write_Pin, GPIO_PIN_SET);
	}

}
