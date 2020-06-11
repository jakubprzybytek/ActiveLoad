/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/Texts.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/TypedText.hpp>
#include <texts/TypedTextDatabase.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <touchgfx/TextProvider.hpp>

touchgfx::Font::StringWidthFunctionPointer touchgfx::Font::getStringWidthFunction = &touchgfx::Font::getStringWidthLTR;
touchgfx::LCD::DrawStringFunctionPointer touchgfx::LCD::drawStringFunction = &touchgfx::LCD::drawStringLTR;
touchgfx::TextProvider::UnicodeConverterInitFunctionPointer touchgfx::TextProvider::unicodeConverterInitFunction = static_cast<touchgfx::TextProvider::UnicodeConverterInitFunctionPointer>(0);
touchgfx::TextProvider::UnicodeConverterFunctionPointer touchgfx::TextProvider::unicodeConverterFunction = static_cast<touchgfx::TextProvider::UnicodeConverterFunctionPointer>(0);

//Default typed text database
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE =
{
    0x41, 0x63, 0x74, 0x69, 0x76, 0x65, 0x20, 0x4c, 0x6f, 0x61, 0x64, 0x20, 0x34, 0x30, 0x56, 0x2f, 0x38, 0x41, 0x20, 0x6d, 0x61, 0x78, 0x0, // @0 "Active Load 40V/8A max"
    0x56, 0x6f, 0x6c, 0x74, 0x61, 0x67, 0x65, 0x20, 0x2f, 0x20, 0x43, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x0, // @23 "Voltage / Current"
    0x45, 0x6c, 0x61, 0x70, 0x73, 0x65, 0x64, 0x20, 0x74, 0x69, 0x6d, 0x65, 0x0, // @41 "Elapsed time"
    0x52, 0x65, 0x73, 0x65, 0x74, 0x20, 0x74, 0x69, 0x6d, 0x65, 0x72, 0x3f, 0x0, // @54 "Reset timer?"
    0x4c, 0x6f, 0x61, 0x64, 0x20, 0x4c, 0x69, 0x6d, 0x69, 0x74, 0x73, 0x0, // @67 "Load Limits"
    0x43, 0x61, 0x70, 0x61, 0x63, 0x69, 0x74, 0x79, 0x0, // @79 "Capacity"
    0x52, 0x61, 0x64, 0x69, 0x61, 0x74, 0x6f, 0x72, 0x0, // @88 "Radiator"
    0x2, 0x0, // @97 "<>"
    0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65, 0x0, // @99 "Enable"
    0x43, 0x68, 0x61, 0x72, 0x67, 0x65, 0x0, // @106 "Charge"
    0x43, 0x61, 0x6e, 0x63, 0x65, 0x6c, 0x0, // @113 "Cancel"
    0x49, 0x6e, 0x70, 0x75, 0x74, 0x0, // @120 "Input"
    0x53, 0x74, 0x61, 0x72, 0x74, 0x0, // @126 "Start"
    0x54, 0x65, 0x6d, 0x70, 0x2e, 0x0, // @132 "Temp."
    0x50, 0x6f, 0x77, 0x65, 0x72, 0x0, // @138 "Power"
    0x52, 0x65, 0x73, 0x65, 0x74, 0x0, // @144 "Reset"
    0x6f, 0x66, 0x66, 0x0, // @150 "off"
    0x31, 0x2f, 0x6d, 0x0, // @154 "1/m"
    0x52, 0x50, 0x4d, 0x0, // @158 "RPM"
    0x59, 0x65, 0x73, 0x0, // @162 "Yes"
    0x46, 0x61, 0x6e, 0x0, // @166 "Fan"
    0x41, 0x68, 0x0, // @170 "Ah"
    0xb0, 0x43, 0x0, // @173 "?C"
    0x57, 0x68, 0x0, // @176 "Wh"
    0x56, 0x0, // @179 "V"
    0x25, 0x0, // @181 "%"
    0x41, 0x0, // @183 "A"
    0x57, 0x0 // @185 "W"
};
extern uint32_t const indicesGb[];

//array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

//Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] =
{
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            //dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            //compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}

