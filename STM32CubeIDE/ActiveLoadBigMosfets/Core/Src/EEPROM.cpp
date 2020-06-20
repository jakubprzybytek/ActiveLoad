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
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_BYTE, eepromAddress++, applicationState.timer.hours) != HAL_OK) {}
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_BYTE, eepromAddress++, applicationState.timer.minutes) != HAL_OK) {}
	while (HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_BYTE, eepromAddress++, applicationState.timer.seconds) != HAL_OK) {}

	while (HAL_FLASHEx_DATAEEPROM_Lock() != HAL_OK) {}
}

void EEPROM::read(ApplicationState &applicationState) {
	uint32_t eepromAddress = 0x08080000;

	uint16_t versionFromEeprom = *((__IO uint16_t*) eepromAddress);
	eepromAddress += 2;
	this->writes = *((__IO uint16_t*) eepromAddress);
	eepromAddress += 2;

	if (versionFromEeprom == EEPROM_DATA_VERSION) {
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

		applicationState.timer.hours = *((__IO uint8_t*) eepromAddress++);
		applicationState.timer.minutes = *((__IO uint8_t*) eepromAddress++);
		applicationState.timer.seconds = *((__IO uint8_t*) eepromAddress++);
	}
}
