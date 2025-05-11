/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --font D:/DACN/Computer_engineer_project/squareline/assets/SoulDaisy.otf -o D:/DACN/Computer_engineer_project/squareline/assets\ui_font_Font20.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT20
#define UI_FONT_FONT20 1
#endif

#if UI_FONT_FONT20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x66, 0x66, 0x66, 0x66, 0x62, 0x0, 0xff, 0xf0,

    /* U+0022 "\"" */
    0xde, 0xf7, 0x29, 0x0,

    /* U+0023 "#" */
    0x8, 0x83, 0x31, 0xff, 0xbf, 0xef, 0xfc, 0x62,
    0xc, 0xc1, 0x98, 0xff, 0xdf, 0xfb, 0xff, 0x33,
    0x6, 0x60, 0x88, 0x0,

    /* U+0024 "$" */
    0x6, 0x0, 0xc0, 0x18, 0x1f, 0xc7, 0xfd, 0xff,
    0xb0, 0x16, 0x0, 0xff, 0x87, 0xf8, 0x1, 0xc0,
    0x3e, 0xf, 0xff, 0xdf, 0xf1, 0xfc, 0x6, 0x0,
    0xc0, 0x18, 0x0,

    /* U+0025 "%" */
    0x70, 0xdf, 0x12, 0x26, 0x44, 0x8f, 0xa0, 0xec,
    0x1, 0x0, 0x6e, 0xb, 0xe2, 0x44, 0x48, 0x91,
    0x16, 0x3e, 0x83, 0x80,

    /* U+0026 "&" */
    0x7f, 0x83, 0xfe, 0x1f, 0xf0, 0x60, 0x3, 0x80,
    0xc, 0x0, 0xf0, 0x8e, 0xc6, 0xc7, 0x36, 0x19,
    0xb0, 0x79, 0xc3, 0xc7, 0xfe, 0x1f, 0xf8, 0x7c,
    0xe0, 0x0,

    /* U+0027 "'" */
    0x66, 0x64, 0xc0,

    /* U+0028 "(" */
    0x1, 0xdc, 0xee, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x39, 0xc7, 0x0,

    /* U+0029 ")" */
    0x47, 0x1c, 0xe3, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0xb9, 0xdc, 0x0,

    /* U+002A "*" */
    0x33, 0x4c, 0xf3, 0x0,

    /* U+002B "+" */
    0x18, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0x1c, 0x1c,
    0xc,

    /* U+002C "," */
    0x7f, 0xf6, 0x40,

    /* U+002D "-" */
    0xfe,

    /* U+002E "." */
    0xff, 0xf0,

    /* U+002F "/" */
    0x0, 0x0, 0xc0, 0x40, 0x60, 0x20, 0x30, 0x10,
    0x18, 0xc, 0xc, 0x6, 0x2, 0x3, 0x1, 0x1,
    0x80, 0x80, 0xc0, 0x0,

    /* U+0030 "0" */
    0xf, 0xc0, 0xff, 0xc7, 0xff, 0x9c, 0xe, 0xe0,
    0x1f, 0x0, 0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xf,
    0x80, 0x77, 0x83, 0x9f, 0xfe, 0x3f, 0xf0, 0x3f,
    0x0,

    /* U+0031 "1" */
    0x78, 0x7c, 0x3e, 0x3, 0x1, 0x80, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x6, 0x3, 0xf, 0xf7, 0xfd,
    0xfe,

    /* U+0032 "2" */
    0x3f, 0x1f, 0xef, 0xff, 0x7, 0x0, 0xc0, 0x70,
    0x38, 0x3c, 0x1e, 0x1e, 0xe, 0x3, 0xfe, 0xff,
    0xff, 0xf0,

    /* U+0033 "3" */
    0x3e, 0x7f, 0xbf, 0xf8, 0x30, 0x19, 0xf8, 0xfc,
    0x7, 0x1, 0x80, 0xf0, 0xff, 0xff, 0xf1, 0xf0,

    /* U+0034 "4" */
    0x0, 0xc0, 0x1c, 0x3, 0xc0, 0x7c, 0xe, 0xc1,
    0xcc, 0x38, 0xc7, 0xc, 0x7f, 0xf7, 0xff, 0x7f,
    0xe0, 0xc, 0x0, 0xc0, 0xc,

    /* U+0035 "5" */
    0x7f, 0xbf, 0xef, 0xf3, 0x0, 0xc0, 0x3f, 0xcf,
    0xf9, 0x7, 0x0, 0xc0, 0x38, 0xf, 0x7, 0xff,
    0xbf, 0xe3, 0xe0,

    /* U+0036 "6" */
    0xf, 0xc3, 0xfe, 0x7f, 0xe7, 0xfa, 0xdf, 0xef,
    0xfe, 0xf0, 0x7c, 0x3, 0xc0, 0x3c, 0x3, 0x60,
    0x77, 0xfe, 0x3f, 0xc1, 0xf8,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0xf8, 0xc, 0x7, 0x3, 0x80,
    0xe0, 0x70, 0x1c, 0x7, 0x3, 0x80, 0xe0, 0x38,
    0xe, 0x3, 0x80,

    /* U+0038 "8" */
    0x3f, 0x7, 0xfc, 0xff, 0xec, 0x6, 0x40, 0x63,
    0xfc, 0x60, 0x8c, 0x6, 0xc0, 0x3c, 0x3, 0xe0,
    0x7f, 0xff, 0x7f, 0xe1, 0xf8,

    /* U+0039 "9" */
    0x1f, 0x87, 0xfc, 0x7f, 0xee, 0x6, 0xc0, 0x3c,
    0x3, 0xe0, 0x7f, 0xff, 0x7f, 0xb1, 0xf7, 0x40,
    0xe7, 0xfe, 0x7f, 0xc3, 0xf0,

    /* U+003A ":" */
    0xff, 0xf0, 0x0, 0x0, 0xf, 0xff,

    /* U+003B ";" */
    0xff, 0xf0, 0x0, 0x0, 0x7, 0xff, 0x64,

    /* U+003C "<" */
    0x0, 0x77, 0xbe, 0xf3, 0xf, 0xe, 0x8,

    /* U+003D "=" */
    0xff, 0xff, 0x0, 0x0, 0xff, 0xff,

    /* U+003E ">" */
    0x83, 0x87, 0xf, 0x1d, 0xff, 0xbc, 0xc0,

    /* U+003F "?" */
    0x3f, 0x8f, 0xfb, 0xff, 0xf0, 0x78, 0x6, 0x0,
    0xc0, 0x38, 0xfe, 0x1f, 0x83, 0x0, 0x0, 0x0,
    0x3, 0xc0, 0x78, 0xf, 0x0,

    /* U+0040 "@" */
    0x7, 0xf0, 0x1f, 0xf8, 0x38, 0x1c, 0x60, 0x6,
    0x47, 0xc2, 0x4f, 0xf3, 0x88, 0x39, 0x80, 0x19,
    0x87, 0xf9, 0x8c, 0x19, 0x98, 0x19, 0x98, 0x39,
    0x9f, 0xfb, 0x4f, 0xde, 0x47, 0x8e, 0x60, 0x0,
    0x30, 0x10, 0x1f, 0xf0, 0x7, 0xc0,

    /* U+0041 "A" */
    0x6, 0x0, 0x78, 0x3, 0xe0, 0x3b, 0x1, 0x98,
    0xc, 0xe0, 0xe3, 0x6, 0x18, 0x7f, 0xe3, 0xff,
    0x1f, 0xf9, 0x80, 0x6c, 0x3, 0x60, 0x18,

    /* U+0042 "B" */
    0x7f, 0x8f, 0xfc, 0xff, 0xec, 0xe, 0xc0, 0x6c,
    0xe, 0xff, 0xcf, 0xfe, 0xc0, 0x7c, 0x3, 0xc0,
    0x7f, 0xff, 0xff, 0xe7, 0xfc,

    /* U+0043 "C" */
    0xf, 0xf0, 0xff, 0xf7, 0xff, 0x9e, 0x0, 0xe0,
    0x3, 0x0, 0xc, 0x0, 0x30, 0x0, 0xc0, 0x3,
    0x80, 0x7, 0x0, 0x1f, 0xfe, 0x3f, 0xf8, 0x1f,
    0xe0,

    /* U+0044 "D" */
    0xff, 0xf, 0xfc, 0xff, 0xec, 0xe, 0xc0, 0x7c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x7, 0xc0,
    0xef, 0xfe, 0xff, 0xc7, 0xf0,

    /* U+0045 "E" */
    0xff, 0xff, 0xff, 0xff, 0x60, 0xc, 0x1, 0xff,
    0xbf, 0xf7, 0xfc, 0xc0, 0x18, 0x3, 0x0, 0x7f,
    0xff, 0xff, 0xff, 0x80,

    /* U+0046 "F" */
    0xff, 0xdf, 0xfb, 0xff, 0x60, 0xc, 0x1, 0x80,
    0x3f, 0xf7, 0xfe, 0xff, 0x98, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x0,

    /* U+0047 "G" */
    0xf, 0xe0, 0xff, 0xe7, 0xff, 0x9c, 0x0, 0xe0,
    0x3, 0x0, 0xc, 0x1f, 0xf0, 0xff, 0xc3, 0xff,
    0x80, 0x37, 0x80, 0xdf, 0xff, 0x3f, 0xfc, 0x3f,
    0xc0,

    /* U+0048 "H" */
    0xc0, 0x78, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xc0, 0x78, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x0, 0xc0,

    /* U+0049 "I" */
    0x7f, 0xff, 0xfe, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x7f, 0xff, 0xfe,

    /* U+004A "J" */
    0x1, 0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6,
    0x3, 0x1, 0x80, 0xc0, 0xef, 0xe7, 0xf3, 0xe0,

    /* U+004B "K" */
    0xc0, 0xec, 0x3e, 0xc7, 0xcc, 0xf8, 0xdf, 0xf,
    0xe0, 0xfc, 0xf, 0xe0, 0xfe, 0xe, 0x70, 0xc3,
    0x8c, 0x1c, 0xc0, 0xec, 0x6,

    /* U+004C "L" */
    0xc0, 0x18, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x18, 0x3, 0x0, 0x7f,
    0xcf, 0xfd, 0xff, 0x80,

    /* U+004D "M" */
    0xe0, 0x1f, 0xc0, 0x7f, 0x3, 0xfe, 0xf, 0xf8,
    0x7f, 0xf1, 0xff, 0xcf, 0xf7, 0x37, 0xdf, 0xdf,
    0x3e, 0x7c, 0xf9, 0xf1, 0xc7, 0xc7, 0x1f, 0x18,
    0x60,

    /* U+004E "N" */
    0xe0, 0x7e, 0xf, 0xe1, 0xfc, 0x3f, 0xc7, 0xfc,
    0xf7, 0xde, 0x7b, 0xc7, 0xf8, 0xff, 0xf, 0xe0,
    0xfc, 0xf, 0x80, 0xc0,

    /* U+004F "O" */
    0xf, 0xe0, 0x7f, 0xf1, 0xff, 0xf3, 0xc1, 0xee,
    0x0, 0xf8, 0x0, 0xf0, 0x1, 0xe0, 0x3, 0xc0,
    0x7, 0xc0, 0x1d, 0xe0, 0xf3, 0xff, 0xe1, 0xff,
    0x81, 0xfc, 0x0,

    /* U+0050 "P" */
    0xff, 0x9f, 0xfb, 0xff, 0xe0, 0x3c, 0x7, 0x81,
    0xff, 0xff, 0xfe, 0xff, 0x98, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x0,

    /* U+0051 "Q" */
    0xf, 0xe0, 0x7f, 0xf1, 0xff, 0xf3, 0xc1, 0xee,
    0x0, 0xf8, 0x0, 0xf0, 0x1, 0xe0, 0x3, 0xc0,
    0x7, 0xc0, 0x1d, 0xe0, 0xf1, 0xff, 0xe1, 0xff,
    0x80, 0x7c, 0x0, 0xc0, 0x1, 0x80, 0x3, 0xf0,
    0x7, 0xe0, 0x7, 0x80,

    /* U+0052 "R" */
    0xff, 0x9f, 0xfb, 0xff, 0xe0, 0x3c, 0x7, 0xff,
    0xff, 0xf7, 0xfc, 0xcc, 0x18, 0x83, 0x18, 0x63,
    0xfc, 0x3f, 0x83, 0x80,

    /* U+0053 "S" */
    0x1f, 0x83, 0xff, 0x3f, 0xfd, 0xc0, 0xec, 0x0,
    0x7e, 0x3, 0xff, 0xc7, 0xff, 0x0, 0x7c, 0x0,
    0xfc, 0xf, 0xff, 0xe7, 0xff, 0xf, 0xe0,

    /* U+0054 "T" */
    0x7f, 0xff, 0xff, 0xff, 0x3, 0x0, 0x60, 0xc,
    0x1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x18, 0x3,
    0x0, 0x60, 0xc, 0x0,

    /* U+0055 "U" */
    0xc0, 0x78, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x7c, 0xf, 0xc3, 0xbf,
    0xe7, 0xfc, 0x3e, 0x0,

    /* U+0056 "V" */
    0xc0, 0x3e, 0x7, 0xf0, 0x67, 0xe, 0x70, 0xc7,
    0x8c, 0x39, 0xc3, 0x98, 0x1f, 0x81, 0xf8, 0x1f,
    0x0, 0xf0, 0xe, 0x0, 0xe0,

    /* U+0057 "W" */
    0xe1, 0xc1, 0xf0, 0xe0, 0xf8, 0x78, 0xfe, 0x3c,
    0x67, 0x3e, 0x33, 0x9f, 0xb9, 0xcd, 0xdc, 0x76,
    0xec, 0x3f, 0x76, 0x1f, 0x3f, 0xf, 0x9f, 0x3,
    0xc7, 0x81, 0xe3, 0xc0, 0xe0, 0xc0,

    /* U+0058 "X" */
    0xe0, 0x6f, 0xf, 0xf8, 0xe7, 0xdc, 0x3f, 0x81,
    0xf8, 0x1f, 0x0, 0xf8, 0x1f, 0x83, 0xfc, 0x3b,
    0xe7, 0x1f, 0xf0, 0xfe, 0xf,

    /* U+0059 "Y" */
    0xe0, 0xf8, 0x37, 0x19, 0xce, 0x3b, 0xf, 0xc1,
    0xe0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0,

    /* U+005A "Z" */
    0xff, 0xef, 0xfe, 0x7f, 0xe0, 0x1c, 0x3, 0xc0,
    0x78, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80, 0x60,
    0xf, 0xfe, 0xff, 0xff, 0xff,

    /* U+005B "[" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
    0xcf,

    /* U+005C "\\" */
    0xc0, 0x40, 0x60, 0x20, 0x30, 0x10, 0x18, 0x8,
    0xc, 0x4, 0x6, 0x6, 0x3, 0x3,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x3f,

    /* U+005E "^" */
    0x71, 0x6d, 0x80,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0060 "`" */
    0xcc,

    /* U+0061 "a" */
    0x3f, 0xf, 0xf9, 0xff, 0x20, 0x70, 0x6, 0x3f,
    0xd8, 0x1e, 0x3, 0xc1, 0xff, 0xfd, 0xfd, 0x9f,
    0x30,

    /* U+0062 "b" */
    0xc0, 0x18, 0x3, 0x3c, 0x7f, 0xcf, 0xfd, 0xe1,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xf, 0x83, 0xff,
    0xef, 0xf9, 0x9e, 0x0,

    /* U+0063 "c" */
    0x1f, 0x87, 0xf9, 0xff, 0x78, 0x2c, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xf0, 0x4f, 0xf8, 0xff, 0xf,
    0xc0,

    /* U+0064 "d" */
    0x0, 0x60, 0xc, 0x79, 0x9f, 0xf7, 0xff, 0xc1,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xf, 0x87, 0xbf,
    0xf3, 0xfe, 0x3c, 0xc0,

    /* U+0065 "e" */
    0xf, 0x87, 0xf9, 0xff, 0xb8, 0x76, 0x6, 0xff,
    0xf8, 0x3, 0x0, 0x70, 0x6f, 0xfc, 0xff, 0x7,
    0xc0,

    /* U+0066 "f" */
    0x7, 0x83, 0xf1, 0xfc, 0x70, 0x18, 0x1f, 0xf7,
    0xfd, 0xfe, 0x18, 0x6, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x0,

    /* U+0067 "g" */
    0x1e, 0x67, 0xfd, 0xff, 0xf0, 0xfc, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xe1, 0xef, 0xfc, 0xff, 0x8f,
    0xb0, 0xe, 0x83, 0xdf, 0xf3, 0xfc, 0x3f, 0x0,

    /* U+0068 "h" */
    0xc0, 0x18, 0x3, 0x7c, 0x7f, 0xef, 0xfd, 0xe1,
    0xf8, 0x3e, 0x3, 0xc0, 0x78, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xc0,

    /* U+0069 "i" */
    0xff, 0xf0, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,

    /* U+006A "j" */
    0x1e, 0x3c, 0x78, 0x60, 0xc1, 0x83, 0x6, 0xc,
    0x18, 0x30, 0x60, 0xc1, 0x83, 0x6, 0x1c, 0xf9,
    0xe3, 0x80,

    /* U+006B "k" */
    0xc0, 0x30, 0xc, 0x1f, 0x1e, 0xcf, 0x37, 0xcf,
    0xe3, 0xf0, 0xfc, 0x3f, 0x8e, 0x73, 0xe, 0xc1,
    0xf0, 0x30,

    /* U+006C "l" */
    0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0xf7,
    0xb8,

    /* U+006D "m" */
    0xdf, 0x1f, 0x3f, 0xef, 0xef, 0xff, 0xfb, 0x87,
    0x87, 0xc0, 0xe0, 0xf0, 0x30, 0x3c, 0xc, 0xf,
    0x3, 0x3, 0xc0, 0xc0, 0xf0, 0x30, 0x3c, 0xc,
    0xf, 0x3, 0x3,

    /* U+006E "n" */
    0xdf, 0x1f, 0xfb, 0xff, 0x78, 0x7e, 0xf, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xf, 0x1, 0xe0,
    0x30,

    /* U+006F "o" */
    0x1f, 0x83, 0xfc, 0x7f, 0xee, 0x7, 0xc0, 0x3c,
    0x3, 0xc0, 0x3c, 0x3, 0xe0, 0x77, 0xfe, 0x3f,
    0xc1, 0xf8,

    /* U+0070 "p" */
    0xcf, 0x1f, 0xf3, 0xff, 0x70, 0x7c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xe0, 0xff, 0xfb, 0xfe, 0x67,
    0x8c, 0x1, 0x80, 0x0,

    /* U+0071 "q" */
    0x1e, 0x67, 0xfd, 0xff, 0xf0, 0x7c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xe1, 0xef, 0xfc, 0xff, 0x8f,
    0x30, 0x6, 0x0, 0xc0, 0x18,

    /* U+0072 "r" */
    0xdf, 0xff, 0xff, 0xf0, 0xe0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0073 "s" */
    0x3f, 0x1f, 0xef, 0xfb, 0x2, 0xc0, 0x3f, 0xe7,
    0xfc, 0x3, 0xc1, 0xff, 0xf7, 0xf8, 0xfc,

    /* U+0074 "t" */
    0x30, 0xc, 0xf, 0xf3, 0xfe, 0x7f, 0x8c, 0x3,
    0x0, 0xc0, 0x30, 0xc, 0x3, 0x80, 0xfe, 0x1f,
    0x83, 0xc0,

    /* U+0075 "u" */
    0xc0, 0x78, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x7, 0xe0, 0xef, 0xfd, 0xff, 0x8f,
    0xb0,

    /* U+0076 "v" */
    0xc0, 0xf8, 0x6e, 0x19, 0xc6, 0x73, 0x1c, 0xc3,
    0xb0, 0xfc, 0x3e, 0x7, 0x81, 0xe0, 0x70,

    /* U+0077 "w" */
    0xc3, 0x87, 0x8e, 0x3e, 0x38, 0xd8, 0xe3, 0x73,
    0xc9, 0xdf, 0x67, 0x7d, 0x8d, 0xb6, 0x34, 0xd0,
    0xf3, 0xc3, 0xcf, 0xf, 0x1c,

    /* U+0078 "x" */
    0xe0, 0xfc, 0x67, 0xb8, 0xec, 0x3e, 0x7, 0x81,
    0xe0, 0x7c, 0x3f, 0x9c, 0xe6, 0x3f, 0x87,

    /* U+0079 "y" */
    0xc0, 0x78, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x7, 0xe1, 0xef, 0xfd, 0xff, 0x8f,
    0xb0, 0xe, 0x83, 0xdf, 0xf3, 0xfc, 0x3f, 0x0,

    /* U+007A "z" */
    0xff, 0xff, 0xdf, 0xe0, 0xe0, 0xe0, 0xe0, 0x60,
    0x70, 0x70, 0x7f, 0xbf, 0xff, 0xf0,

    /* U+007B "{" */
    0x3b, 0x18, 0xc3, 0x18, 0xc6, 0xe1, 0x8c, 0x63,
    0x31, 0x8c, 0x38,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xf0,

    /* U+007D "}" */
    0xe1, 0x8c, 0x66, 0x31, 0x8c, 0x3b, 0x18, 0xc6,
    0x18, 0xc6, 0xe0,

    /* U+007E "~" */
    0x71, 0x64, 0x91, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 112, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 81, .box_w = 4, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 9, .adv_w = 99, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 13, .adv_w = 196, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 33, .adv_w = 210, .box_w = 11, .box_h = 19, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 60, .adv_w = 203, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 225, .box_w = 13, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 106, .adv_w = 55, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 11},
    {.bitmap_index = 109, .adv_w = 103, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 120, .adv_w = 101, .box_w = 5, .box_h = 17, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 131, .adv_w = 90, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 10},
    {.bitmap_index = 135, .adv_w = 143, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 144, .adv_w = 70, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 147, .adv_w = 122, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 148, .adv_w = 69, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 142, .box_w = 9, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 170, .adv_w = 253, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 154, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 212, .adv_w = 187, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 230, .adv_w = 179, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 246, .adv_w = 197, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 186, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 286, .adv_w = 208, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 170, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 206, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 208, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 368, .adv_w = 76, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 76, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 381, .adv_w = 110, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 388, .adv_w = 143, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 394, .adv_w = 110, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 401, .adv_w = 195, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 282, .box_w = 16, .box_h = 19, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 460, .adv_w = 195, .box_w = 13, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 483, .adv_w = 202, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 504, .adv_w = 217, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 529, .adv_w = 216, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 550, .adv_w = 192, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 570, .adv_w = 181, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 590, .adv_w = 235, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 212, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 635, .adv_w = 133, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 649, .adv_w = 142, .box_w = 9, .box_h = 14, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 665, .adv_w = 196, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 686, .adv_w = 172, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 706, .adv_w = 250, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 731, .adv_w = 210, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 751, .adv_w = 251, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 778, .adv_w = 194, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 798, .adv_w = 251, .box_w = 15, .box_h = 19, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 834, .adv_w = 200, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 854, .adv_w = 220, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 877, .adv_w = 167, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 205, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 917, .adv_w = 185, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 938, .adv_w = 271, .box_w = 17, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 968, .adv_w = 191, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 989, .adv_w = 158, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1007, .adv_w = 190, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1028, .adv_w = 94, .box_w = 4, .box_h = 18, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1037, .adv_w = 134, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1051, .adv_w = 94, .box_w = 4, .box_h = 18, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1060, .adv_w = 93, .box_w = 6, .box_h = 3, .ofs_x = 0, .ofs_y = 10},
    {.bitmap_index = 1063, .adv_w = 142, .box_w = 9, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1065, .adv_w = 55, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 12},
    {.bitmap_index = 1066, .adv_w = 193, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1083, .adv_w = 198, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1103, .adv_w = 181, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1120, .adv_w = 198, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1140, .adv_w = 181, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1157, .adv_w = 149, .box_w = 10, .box_h = 17, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1179, .adv_w = 199, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1203, .adv_w = 195, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1223, .adv_w = 58, .box_w = 4, .box_h = 16, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1231, .adv_w = 57, .box_w = 7, .box_h = 20, .ofs_x = -3, .ofs_y = -5},
    {.bitmap_index = 1249, .adv_w = 173, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1267, .adv_w = 88, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1276, .adv_w = 315, .box_w = 18, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1303, .adv_w = 195, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1320, .adv_w = 198, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1338, .adv_w = 199, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1358, .adv_w = 199, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1379, .adv_w = 135, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1391, .adv_w = 180, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1406, .adv_w = 154, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1424, .adv_w = 195, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1441, .adv_w = 152, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1456, .adv_w = 227, .box_w = 14, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1477, .adv_w = 163, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1492, .adv_w = 196, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1516, .adv_w = 156, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1530, .adv_w = 92, .box_w = 5, .box_h = 17, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1541, .adv_w = 51, .box_w = 2, .box_h = 18, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1546, .adv_w = 92, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1557, .adv_w = 143, .box_w = 9, .box_h = 3, .ofs_x = 0, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 4, 1, 0, 0, 0, 0, 0,
    0, 0, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 16,
    12, 22, 12, 23, 24, 25, 18, 26,
    27, 28, 29, 30, 0, 0, 0, 0,
    0, 0, 31, 32, 33, 21, 34, 35,
    36, 37, 38, 39, 40, 41, 42, 42,
    43, 43, 36, 44, 45, 46, 47, 48,
    48, 49, 36, 50, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 1, 2, 0, 0, 0, 0,
    3, 4, 5, 6, 0, 7, 8, 7,
    9, 10, 11, 12, 13, 14, 15, 16,
    17, 18, 19, 20, 20, 0, 0, 0,
    21, 0, 22, 0, 23, 0, 0, 0,
    23, 0, 24, 25, 0, 0, 0, 0,
    23, 0, 23, 0, 26, 27, 28, 29,
    30, 31, 32, 33, 0, 34, 35, 0,
    36, 0, 37, 0, 38, 39, 38, 40,
    38, 0, 41, 42, 0, 0, 43, 43,
    38, 44, 38, 43, 45, 46, 47, 48,
    49, 50, 47, 51, 52, 0, 53, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -13, -12, -12, -9, -7, -4,
    -13, -9, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -14, 0,
    -7, -11, -15, -12, -14, -16, -13, -14,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -11, -10, 0, -10, -14,
    -9, -11, -13, -11, -8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -8, -10, -7, 0, -6, -6, -7, -13,
    -5, -11, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -8, -13, -12,
    -11, 0, -10, -7, -14, -7, -12, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, -12, -9, -8, -6, 0,
    -5, -13, -6, -11, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    -12, -9, -8, -6, -7, 0, -13, -6,
    -11, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -15, -14, -15, -15,
    -17, -14, -15, 0, -15, -15, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -15, -15, -8, 0, -15, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -14, 0, -4, 0,
    0, 0, -25, -3, -21, -18, 0, -24,
    0, -16, 0, 0, 0, 0, -2, -18,
    0, 0, 0, 0, 0, -18, 0, -16,
    -12, 0, 0, -4, 0, -3, -7, -4,
    0, -10, -6, 0, 0, -12, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -12, 0, 0, 0, 0, 0, -5,
    0, -6, -5, 0, -9, 0, -14, -15,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, -2, 0, -2, 0, 0, 0,
    -6, -10, 0, 0, 0, -7, 0, 0,
    0, -19, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, -8, 0, 0, -6,
    -7, -4, 0, 0, 0, 0, 0, 0,
    -4, 0, 0, 0, 0, -5, -9, -4,
    -3, -3, 0, -12, -2, -6, 0, -14,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -8, -5, 0, -3, -10,
    0, -2, 0, -3, 0, -6, -7, -4,
    -14, -15, -11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -11, 0, 0, 0, -5,
    -3, 0, 0, 0, -8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, -12, 0,
    0, -2, -3, -3, 0, 0, 0, 0,
    0, 0, 0, -2, -2, 0, 0, -4,
    -10, 0, 0, 0, 0, -5, 0, -15,
    0, -16, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, -16, 0,
    0, -29, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -15, -17, -7, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, -7, -2, -11, 0, -3,
    -2, 0, -7, -5, 0, 0, -10, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, 0, 0, 0, 0,
    -3, 0, -2, 0, 0, -3, 0, -14,
    -13, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 0, -4, 0, -2, 0, 0,
    0, -3, -10, -3, 0, 0, 0, -9,
    0, 0, 0, -13, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -12, -14, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -4, -12,
    0, 0, 0, -5, -2, 0, 0, -13,
    -7, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, 0, -3, -3, -5,
    0, 0, 0, 0, 0, 0, -2, 0,
    -3, 0, 0, -4, -10, -4, 0, 0,
    0, -10, 0, -4, 0, -14, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -8, -14,
    -10, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, -12, 0, 0, 0, -11, 0, 0,
    0, -14, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -4, 0,
    -11, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -10,
    -11, -12, 0, 0, 0, 0, -2, -4,
    -8, -10, -11, 0, 0, -4, 0, 0,
    -21, -21, -14, 0, -21, 0, -18, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -18, 0, -12, 0, 0,
    -4, -36, -8, -33, -27, 0, -35, 0,
    -20, 0, 0, 0, -5, -8, -24, 0,
    0, 0, 0, 0, -24, -5, -25, -17,
    0, 0, -6, 0, -3, 0, 0, 0,
    -8, 0, 0, 0, -13, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -11, -14, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    -12, 0, 0, 0, 0, -13, 0, -16,
    0, -16, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -18, 0,
    0, -30, 0, 0, 0, 0, 0, 0,
    0, 0, -10, -16, -17, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -11, -2, 0,
    0, 0, -9, 0, 0, 0, -13, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -13,
    -14, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, -11, -4, -3, 0, 0, -11,
    -2, 0, 0, -14, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -9,
    0, 0, 0, 0, 0, 0, 0, -3,
    -2, 0, -5, 0, -14, -14, -4, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -6, -11,
    0, 0, 0, -6, 0, 0, -15, -15,
    -17, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -26, -6, 0,
    -34, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, -14, -18, -21, -20, 0,
    0, 0, -8, -9, -16, 0, -5, 0,
    0, 0, 0, -5, -8, 0, 0, 0,
    -5, 0, 0, -15, -8, -17, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -22, -4, 0, -31, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -11,
    -15, -13, -13, -14, 0, 0, 0, -8,
    -9, -11, 0, -6, 0, 0, 0, -5,
    -5, -7, 0, 0, 0, -4, 0, 0,
    -13, 0, -16, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -19,
    0, 0, -27, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -12, -12, -9, -8,
    -8, 0, 0, 0, -4, -5, -7, 0,
    -2, 0, 0, 0, -2, -4, -9, 0,
    0, 0, -8, 0, 0, 0, -12, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, 0, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, -6, 0, 0, -4, -5, -9, 0,
    0, 0, 0, 0, -2, -3, -6, -6,
    0, 0, -4, -9, 0, 0, 0, -7,
    0, 0, -15, -12, -17, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, -25, -7, 0, -33, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -11, -14,
    -18, -20, -20, -3, 0, 0, -11, -12,
    -16, 0, -10, 0, 0, 0, -6, -5,
    -7, 0, 0, 0, -7, 0, 0, 0,
    -13, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, -8, 0, 0, -3, -5,
    -4, 0, 0, 0, 0, 0, 0, -2,
    0, 0, 0, 0, -4, -9, -2, -11,
    -11, 0, -7, -10, 0, 0, -8, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -13, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -15,
    -13, 0, 0, 0, 0, 0, -4, -5,
    0, 0, 0, -3, 0, -2, 0, 0,
    0, -3, -11, -7, -13, -13, 0, -13,
    -12, -2, 0, -15, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, -14,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -15, -16, -10, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, 0, 0, 0, -5, -3, -4, -13,
    -2, -2, 0, 0, -11, 0, 0, 0,
    -11, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -9, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -15, -15, 0, 0, 0, 0, 0,
    -4, -5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -12, -4, -8, -7,
    0, -12, -7, 0, 0, -13, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -13, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -15, -15,
    -4, 0, 0, 0, 0, -5, -6, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, -12, 0, 0, 0, 0, 0, 0,
    -29, -21, -18, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -49, -8, -11,
    -9, 0, 0, 0, 0, 0, -6, 0,
    0, 0, 0, 0, 0, -3, 0, -3,
    0, 0, 0, -8, 0, 0, 0, -9,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -7, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -15, -11, 0, 0, 0, 0, 0, -7,
    -7, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, -10, -4, -13, -13, 0,
    -10, -12, 0, 0, -12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -13, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -15, -15, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    0, -4, 0, -2, 0, 0, 0, -5,
    -13, -3, 0, 0, -2, 0, 0, -8,
    -6, -14, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -10, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -13, -5, -4, 0,
    0, 0, 0, -7, -7, -5, 0, -4,
    0, -3, -2, -4, -2, 0, -3, 0,
    0, -3, 0, 0, -9, -7, -8, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -11, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, -3, -6, -5, 0, 0, 0, 0,
    -8, -8, -6, 0, -5, -2, -4, -3,
    -4, -2, 0, 0, 0, 0, -4, 0,
    0, 0, -12, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -14, -4, 0, 0,
    -6, -8, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -6, -7,
    0, -13, -13, -6, -4, -14, 0, -12,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -15, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -16, -10, 0, 0, 0, 0, -20,
    0, 0, 0, 0, 0, -17, 0, -17,
    -11, 0, 0, -6, -11, -2, -11, -10,
    0, -7, -10, 0, 0, -9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -13, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -15, -14,
    0, 0, 0, 0, 0, -4, -5, 0,
    0, 0, -2, 0, -2, 0, 0, 0,
    -3, -11, -6, -11, -11, 0, -12, -10,
    0, 0, -13, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, -13, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -15, -15, -10, 0, 0,
    0, 0, -4, -5, 0, 0, 0, -2,
    0, 0, 0, -5, -2, 0, -11, -2,
    0, 0, 0, -15, 0, -18, 0, -17,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -15, -18, -18, 0, 0, 0, 0, -2,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, -12, -3, -9, -8, 0,
    -11, -8, 0, 0, -11, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -13, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -15, -15, 0,
    0, 0, 0, 0, -5, -6, 0, 0,
    0, -2, 0, -2, 0, -2, 0, -7,
    -12, -3, -5, -6, -4, -9, -3, 0,
    -8, -11, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -10, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -15, -15, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -8, -13, -3, 0,
    0, 0, -8, 0, 0, 0, -9, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -9, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -15,
    -12, 0, 0, 0, 0, 0, -7, -8,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, -10, -2, 0, 0, 0, -13,
    0, -13, 0, -15, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -14, -16, -13, -2,
    0, 0, 0, -3, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -6, -11,
    0, 0, 0, -5, 0, 0, 0, -12,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -16, -4, 0, 0, -6, -6, 0,
    -2, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, -6, 0, 0, 0,
    -2, -2, 0, 0, -10, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -16, -6,
    0, 0, -3, -4, 0, -4, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -5, -9
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 50,
    .right_class_cnt     = 53,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Font20 = {
#else
lv_font_t ui_font_Font20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 22,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONT20*/

