/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef APPLICATIONFONTPROVIDER_HPP
#define APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

struct Typography
{
    static const touchgfx::FontId DEFAULT = 0;
    static const touchgfx::FontId LARGE = 1;
    static const touchgfx::FontId SMALL = 2;
    static const touchgfx::FontId LCD_DEFAULT = 3;
    static const touchgfx::FontId LCD_LARGE = 4;
    static const touchgfx::FontId TINY = 5;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId DEFAULT = 0;     // verdana_20_4bpp
    static const touchgfx::FontId LARGE = 1;       // verdana_40_4bpp
    static const touchgfx::FontId SMALL = 2;       // verdana_14_4bpp
    static const touchgfx::FontId LCD_DEFAULT = 3; // liquidcrystal_20_4bpp
    static const touchgfx::FontId LCD_LARGE = 4;   // liquidcrystal_40_4bpp
    static const touchgfx::FontId TINY = 5;        // verdana_11_4bpp
    static const uint16_t NUMBER_OF_FONTS = 6;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);
};

#endif // APPLICATIONFONTPROVIDER_HPP
