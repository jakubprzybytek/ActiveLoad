// Generated by imageconverter. Please, do not edit!

#ifndef BITMAPDATABASE_HPP
#define BITMAPDATABASE_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <touchgfx/Bitmap.hpp>

const uint16_t BITMAP_CHECKBOX_CHECKED_ID = 0;
const uint16_t BITMAP_CHECKBOX_UNCHECKED_ID = 1;
const uint16_t BITMAP_DARK_ICONS_ALERT_32_ID = 2;
const uint16_t BITMAP_MODALBACKGROUND_ID = 3;

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance();
uint16_t getInstanceSize();
}

#endif
