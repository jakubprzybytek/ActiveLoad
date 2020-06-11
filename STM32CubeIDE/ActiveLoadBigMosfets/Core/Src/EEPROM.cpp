#include "stdio.h"
#include "stm32l1xx_hal.h"

#include "EEPROM.hpp"
#include "main.h"

void EEPROM::write(ApplicationState &applicationState) {

	uint32_t eepromAddress = 0x08080000;

	while (HAL_FLASHEx_DATAEEPROM_Unlock() != HAL_OK) {}

	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_HALFWORD, eepromAddress, EEPROM_DATA_VERSION) != HAL_OK) {}
	eepromAddress += 2;
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_HALFWORD, eepromAddress, ++writes) != HAL_OK) {}
	eepromAddress += 2;
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD, eepromAddress, applicationState.chargeMiliAmpSeconds >> 32) != HAL_OK) {}
	eepromAddress += 4;
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD, eepromAddress, applicationState.chargeMiliAmpSeconds) != HAL_OK) {}
	eepromAddress += 4;
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD, eepromAddress, applicationState.chargeMiliWattSeconds >> 32) != HAL_OK) {}
	eepromAddress += 4;
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD, eepromAddress, applicationState.chargeMiliWattSeconds) != HAL_OK) {}
	eepromAddress += 4;
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_BYTE, eepromAddress++, applicationState.time.Hours) != HAL_OK) {}
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_BYTE, eepromAddress++, applicationState.time.Minutes) != HAL_OK) {}
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_BYTE, eepromAddress++, applicationState.time.Seconds) != HAL_OK) {}

	while (HAL_FLASHEx_DATAEEPROM_Lock() != HAL_OK) {}
}

void EEPROM::read(ApplicationState &applicationState) {
	uint32_t eepromAddress = 0x08080000;

	if (*((__IO uint16_t*) eepromAddress) == EEPROM_DATA_VERSION) {
		eepromAddress += 2;
		writes = *((__IO uint16_t*) eepromAddress);
		eepromAddress += 2;
		applicationState.chargeMiliAmpSeconds = *((__IO uint32_t*) eepromAddress);
		applicationState.chargeMiliAmpSeconds <<= 32;
		eepromAddress += 4;
		applicationState.chargeMiliAmpSeconds += *((__IO uint32_t*) eepromAddress);
		eepromAddress += 4;
		applicationState.chargeMiliWattSeconds = *((__IO uint32_t*) eepromAddress);
		applicationState.chargeMiliWattSeconds <<= 32;
		eepromAddress += 4;
		applicationState.chargeMiliWattSeconds += *((__IO uint32_t*) eepromAddress);
		eepromAddress += 4;

		applicationState.time.Hours = *((__IO uint8_t*) eepromAddress++);
		applicationState.time.Minutes = *((__IO uint8_t*) eepromAddress++);
		applicationState.time.Seconds = *((__IO uint8_t*) eepromAddress++);
	}
}
