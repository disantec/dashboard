/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
#define TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

namespace touchgfx
{
class FlashDataReader;
}

struct Typography
{
    static const touchgfx::FontId DEFAULT = 0;
    static const touchgfx::FontId DEFAULT_AUTO_GENERATED_FOR_GB = 1;
    static const touchgfx::FontId LARGE = 2;
    static const touchgfx::FontId LARGE_AUTO_GENERATED_FOR_GB = 3;
    static const touchgfx::FontId SMALL = 4;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId DEFAULT = 0;                       // verdana_40_4bpp
    static const touchgfx::FontId DEFAULT_AUTO_GENERATED_FOR_GB = 1; // verdana_20_4bpp
    static const touchgfx::FontId LARGE = 0;                         // verdana_40_4bpp
    static const touchgfx::FontId LARGE_AUTO_GENERATED_FOR_GB = 2;   // verdana_87_4bpp
    static const touchgfx::FontId SMALL = 3;                         // verdana_10_4bpp
    static const uint16_t NUMBER_OF_FONTS = 4;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);

    static void setFlashReader(touchgfx::FlashDataReader* /*flashReader*/)
    {
    }

    static touchgfx::FlashDataReader* getFlashReader()
    {
        return 0;
    }
};

#endif // TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
