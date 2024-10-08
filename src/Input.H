/*
    WIZARDS.EXE
        seg036
*/
#ifndef INPUT_H
#define INPUT_H

#include "MoX_TYPE.H"

#ifdef STU_DEBUG
#include "stu/STU_DBG.H"
extern int16_t DBG_In_MouseButtonLeft;
extern int16_t DBG_In_MouseButtonRight;
extern int16_t DBG_movement_map_grid_field_idx;
extern int16_t DBG_reduced_map_grid_field_idx;

//char field_names[][];  // ¿ ~== char ** field_names; ?
#define FIELD_COUNT_MAX 128
// char field_names[][];
char * field_names[];
#endif


/*! @defgroup keys Keyboard keys
 *  @brief Keyboard key IDs.
 *
 *  See [key input](@ref input_key) for how these are used.
 *
 *  These key codes are inspired by the _USB HID Usage Tables v1.12_ (p. 53-60),
 *  but re-arranged to map to 7-bit ASCII for printable keys (function keys are
 *  put in the 256+ range).
 *
 *  The naming of the key codes follow these rules:
 *   - The US keyboard layout is used
 *   - Names of printable alphanumeric characters are used (e.g. "A", "R",
 *     "3", etc.)
 *   - For non-alphanumeric characters, Unicode:ish names are used (e.g.
 *     "COMMA", "LEFT_SQUARE_BRACKET", etc.). Note that some names do not
 *     correspond to the Unicode standard (usually for brevity)
 *   - Keys that lack a clear US mapping are named "WORLD_x"
 *   - For non-printable keys, custom names are used (e.g. "F4",
 *     "BACKSPACE", etc.)
 *
 *  @ingroup input
 *  @{
 */

/* The unknown key */
#define GLFW_KEY_UNKNOWN            -1

/* Printable keys */
#define GLFW_KEY_SPACE              32
#define GLFW_KEY_APOSTROPHE         39  /* ' */
#define GLFW_KEY_COMMA              44  /* , */
#define GLFW_KEY_MINUS              45  /* - */
#define GLFW_KEY_PERIOD             46  /* . */
#define GLFW_KEY_SLASH              47  /* / */
#define GLFW_KEY_0                  48
#define GLFW_KEY_1                  49
#define GLFW_KEY_2                  50
#define GLFW_KEY_3                  51
#define GLFW_KEY_4                  52
#define GLFW_KEY_5                  53
#define GLFW_KEY_6                  54
#define GLFW_KEY_7                  55
#define GLFW_KEY_8                  56
#define GLFW_KEY_9                  57
#define GLFW_KEY_SEMICOLON          59  /* ; */
#define GLFW_KEY_EQUAL              61  /* = */
#define GLFW_KEY_A                  65
#define GLFW_KEY_B                  66
#define GLFW_KEY_C                  67
#define GLFW_KEY_D                  68
#define GLFW_KEY_E                  69
#define GLFW_KEY_F                  70
#define GLFW_KEY_G                  71
#define GLFW_KEY_H                  72
#define GLFW_KEY_I                  73
#define GLFW_KEY_J                  74
#define GLFW_KEY_K                  75
#define GLFW_KEY_L                  76
#define GLFW_KEY_M                  77
#define GLFW_KEY_N                  78
#define GLFW_KEY_O                  79
#define GLFW_KEY_P                  80
#define GLFW_KEY_Q                  81
#define GLFW_KEY_R                  82
#define GLFW_KEY_S                  83
#define GLFW_KEY_T                  84
#define GLFW_KEY_U                  85
#define GLFW_KEY_V                  86
#define GLFW_KEY_W                  87
#define GLFW_KEY_X                  88
#define GLFW_KEY_Y                  89
#define GLFW_KEY_Z                  90
#define GLFW_KEY_LEFT_BRACKET       91  /* [ */
#define GLFW_KEY_BACKSLASH          92  /* \ */
#define GLFW_KEY_RIGHT_BRACKET      93  /* ] */
#define GLFW_KEY_GRAVE_ACCENT       96  /* ` */
#define GLFW_KEY_WORLD_1            161 /* non-US #1 */
#define GLFW_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define GLFW_KEY_ESCAPE             256
#define GLFW_KEY_ENTER              257
#define GLFW_KEY_TAB                258
#define GLFW_KEY_BACKSPACE          259
#define GLFW_KEY_INSERT             260
#define GLFW_KEY_DELETE             261
#define GLFW_KEY_RIGHT              262
#define GLFW_KEY_LEFT               263
#define GLFW_KEY_DOWN               264
#define GLFW_KEY_UP                 265
#define GLFW_KEY_PAGE_UP            266
#define GLFW_KEY_PAGE_DOWN          267
#define GLFW_KEY_HOME               268
#define GLFW_KEY_END                269
#define GLFW_KEY_CAPS_LOCK          280
#define GLFW_KEY_SCROLL_LOCK        281
#define GLFW_KEY_NUM_LOCK           282
#define GLFW_KEY_PRINT_SCREEN       283
#define GLFW_KEY_PAUSE              284
#define GLFW_KEY_F1                 290
#define GLFW_KEY_F2                 291
#define GLFW_KEY_F3                 292
#define GLFW_KEY_F4                 293
#define GLFW_KEY_F5                 294
#define GLFW_KEY_F6                 295
#define GLFW_KEY_F7                 296
#define GLFW_KEY_F8                 297
#define GLFW_KEY_F9                 298
#define GLFW_KEY_F10                299
#define GLFW_KEY_F11                300
#define GLFW_KEY_F12                301
#define GLFW_KEY_F13                302
#define GLFW_KEY_F14                303
#define GLFW_KEY_F15                304
#define GLFW_KEY_F16                305
#define GLFW_KEY_F17                306
#define GLFW_KEY_F18                307
#define GLFW_KEY_F19                308
#define GLFW_KEY_F20                309
#define GLFW_KEY_F21                310
#define GLFW_KEY_F22                311
#define GLFW_KEY_F23                312
#define GLFW_KEY_F24                313
#define GLFW_KEY_F25                314
#define GLFW_KEY_KP_0               320
#define GLFW_KEY_KP_1               321
#define GLFW_KEY_KP_2               322
#define GLFW_KEY_KP_3               323
#define GLFW_KEY_KP_4               324
#define GLFW_KEY_KP_5               325
#define GLFW_KEY_KP_6               326
#define GLFW_KEY_KP_7               327
#define GLFW_KEY_KP_8               328
#define GLFW_KEY_KP_9               329
#define GLFW_KEY_KP_DECIMAL         330
#define GLFW_KEY_KP_DIVIDE          331
#define GLFW_KEY_KP_MULTIPLY        332
#define GLFW_KEY_KP_SUBTRACT        333
#define GLFW_KEY_KP_ADD             334
#define GLFW_KEY_KP_ENTER           335
#define GLFW_KEY_KP_EQUAL           336
#define GLFW_KEY_LEFT_SHIFT         340
#define GLFW_KEY_LEFT_CONTROL       341
#define GLFW_KEY_LEFT_ALT           342
#define GLFW_KEY_LEFT_SUPER         343
#define GLFW_KEY_RIGHT_SHIFT        344
#define GLFW_KEY_RIGHT_CONTROL      345
#define GLFW_KEY_RIGHT_ALT          346
#define GLFW_KEY_RIGHT_SUPER        347
#define GLFW_KEY_MENU               348

#define GLFW_KEY_LAST               GLFW_KEY_MENU


/*
    ? need 4 arrays ?
    normal, shift, control, alt
    ~ [4][128]
    enum Keystroke_Modifier { none, shift, control, alt }, provided by Platform
    
    NOTE: for SCCC, "a" is normal, "A" is shifted

    Keypad  NumPad
    ¿ Num Lock ?
    ¿ Arrow Keys vs. NumPad ?


*/
enum ScanCodeCharCode
{
    SCCC_ESC = 0x011B,      // "Esc" key

    SCCC_A = 0x1E61,        // "A" key
    SCCC_B = 0x3062,        // "B" key
    SCCC_C = 0x2E63,        // "C" key
    SCCC_D = 0x2064,        // "D" key
    SCCC_E = 0x1265,        // "E" key
    SCCC_F = 0x2166,        // "F" key
    SCCC_G = 0x2267,        // "G" key
    SCCC_H = 0x2368,        // "H" key
    SCCC_I = 0x1769,        // "I" key
    SCCC_J = 0x246A,        // "J" key
    SCCC_K = 0x256B,        // "K" key
    SCCC_L = 0x266C,        // "L" key
    SCCC_M = 0x326D,        // "M" key
    SCCC_N = 0x316E,        // "N" key
    SCCC_O = 0x186F,        // "O" key
    SCCC_P = 0x1970,        // "P" key
    SCCC_Q = 0x1071,        // "Q" key
    SCCC_R = 0x1372,        // "R" key
    SCCC_S = 0x1F73,        // "S" key
    SCCC_T = 0x1474,        // "T" key
    SCCC_U = 0x1675,        // "U" key
    SCCC_V = 0x2F76,        // "V" key
    SCCC_W = 0x1177,        // "W" key
    SCCC_X = 0x2D78,        // "X" key
    SCCC_Y = 0x1579,        // "Y" key
    SCCC_Z = 0x2C7A,        // "Z" key

    SCCC_Shift_A = 0x1E41,  // "Shift" key + "A" key
    SCCC_Shift_B = 0x3042,  // "Shift" key + "B" key
    SCCC_Shift_C = 0x2E42,  // "Shift" key + "C" key
    SCCC_Shift_D = 0x2044,  // "Shift" key + "D" key
    SCCC_Shift_E = 0x1245,  // "Shift" key + "E" key
    SCCC_Shift_F = 0x2146,  // "Shift" key + "F" key
    SCCC_Shift_G = 0x2247,  // "Shift" key + "G" key
    SCCC_Shift_H = 0x2348,  // "Shift" key + "H" key
    SCCC_Shift_I = 0x1749,  // "Shift" key + "I" key
    SCCC_Shift_J = 0x244A,  // "Shift" key + "J" key
    SCCC_Shift_K = 0x254B,  // "Shift" key + "K" key
    SCCC_Shift_L = 0x264C,  // "Shift" key + "L" key
    SCCC_Shift_M = 0x324D,  // "Shift" key + "M" key
    SCCC_Shift_N = 0x314E,  // "Shift" key + "N" key
    SCCC_Shift_O = 0x184F,  // "Shift" key + "O" key
    SCCC_Shift_P = 0x1950,  // "Shift" key + "P" key
    SCCC_Shift_Q = 0x1051,  // "Shift" key + "Q" key
    SCCC_Shift_R = 0x1352,  // "Shift" key + "R" key
    SCCC_Shift_S = 0x1F53,  // "Shift" key + "S" key
    SCCC_Shift_T = 0x1454,  // "Shift" key + "T" key
    SCCC_Shift_U = 0x1655,  // "Shift" key + "U" key
    SCCC_Shift_V = 0x2F56,  // "Shift" key + "V" key
    SCCC_Shift_W = 0x1157,  // "Shift" key + "W" key
    SCCC_Shift_X = 0x2D58,  // "Shift" key + "X" key
    SCCC_Shift_Y = 0x1559,  // "Shift" key + "Y" key
    SCCC_Shift_Z = 0x2C5A,  // "Shift" key + "Z" key

    SCCC_Ctrl_A = 0x1E01,   // "Control" key + "A" key
    SCCC_Ctrl_B = 0x3002,   // "Control" key + "B" key
    SCCC_Ctrl_C = 0x2E03,   // "Control" key + "C" key
    SCCC_Ctrl_D = 0x2004,   // "Control" key + "D" key
    SCCC_Ctrl_E = 0x1205,   // "Control" key + "E" key
    SCCC_Ctrl_F = 0x2106,   // "Control" key + "F" key
    SCCC_Ctrl_G = 0x2207,   // "Control" key + "G" key
    SCCC_Ctrl_H = 0x2308,   // "Control" key + "H" key
    SCCC_Ctrl_I = 0x1709,   // "Control" key + "I" key
    SCCC_Ctrl_J = 0x240A,   // "Control" key + "J" key
    SCCC_Ctrl_K = 0x250B,   // "Control" key + "K" key
    SCCC_Ctrl_L = 0x260C,   // "Control" key + "L" key
    SCCC_Ctrl_M = 0x320D,   // "Control" key + "M" key
    SCCC_Ctrl_N = 0x310E,   // "Control" key + "N" key
    SCCC_Ctrl_O = 0x180F,   // "Control" key + "O" key
    SCCC_Ctrl_P = 0x1910,   // "Control" key + "P" key
    SCCC_Ctrl_Q = 0x1011,   // "Control" key + "Q" key
    SCCC_Ctrl_R = 0x1312,   // "Control" key + "R" key
    SCCC_Ctrl_S = 0x1F13,   // "Control" key + "S" key
    SCCC_Ctrl_T = 0x1414,   // "Control" key + "T" key
    SCCC_Ctrl_U = 0x1615,   // "Control" key + "U" key
    SCCC_Ctrl_V = 0x2F16,   // "Control" key + "V" key
    SCCC_Ctrl_W = 0x1117,   // "Control" key + "W" key
    SCCC_Ctrl_X = 0x2D18,   // "Control" key + "X" key
    SCCC_Ctrl_Y = 0x1519,   // "Control" key + "Y" key
    SCCC_Ctrl_Z = 0x2C1A,   // "Control" key + "Z" key

    SCCC_Alt_A = 0x1E00,    // "Alt" key + "A" key
    SCCC_Alt_B = 0x3000,    // "Alt" key + "B" key
    SCCC_Alt_C = 0x2E00,    // "Alt" key + "C" key
    SCCC_Alt_D = 0x2000,    // "Alt" key + "D" key
    SCCC_Alt_E = 0x1200,    // "Alt" key + "E" key
    SCCC_Alt_F = 0x2100,    // "Alt" key + "F" key
    SCCC_Alt_G = 0x2200,    // "Alt" key + "G" key
    SCCC_Alt_H = 0x2300,    // "Alt" key + "H" key
    SCCC_Alt_I = 0x1700,    // "Alt" key + "I" key
    SCCC_Alt_J = 0x2400,    // "Alt" key + "J" key
    SCCC_Alt_K = 0x2500,    // "Alt" key + "K" key
    SCCC_Alt_L = 0x2600,    // "Alt" key + "L" key
    SCCC_Alt_M = 0x3200,    // "Alt" key + "M" key
    SCCC_Alt_N = 0x3100,    // "Alt" key + "N" key
    SCCC_Alt_O = 0x1800,    // "Alt" key + "O" key
    SCCC_Alt_P = 0x1900,    // "Alt" key + "P" key
    SCCC_Alt_Q = 0x1000,    // "Alt" key + "Q" key
    SCCC_Alt_R = 0x1300,    // "Alt" key + "R" key
    SCCC_Alt_S = 0x1F00,    // "Alt" key + "S" key
    SCCC_Alt_T = 0x1400,    // "Alt" key + "T" key
    SCCC_Alt_U = 0x1600,    // "Alt" key + "U" key
    SCCC_Alt_V = 0x2F00,    // "Alt" key + "V" key
    SCCC_Alt_W = 0x1100,    // "Alt" key + "W" key
    SCCC_Alt_X = 0x2D00,    // "Alt" key + "X" key
    SCCC_Alt_Y = 0x1500,    // "Alt" key + "Y" key
    SCCC_Alt_Z = 0x2C00,    // "Alt" key + "Z" key

/*
Key     Normal    Shifted   w/Ctrl    w/Alt
1      0231        0221        7800
2      0332        0340      0300    7900
3      0433        0423        7A00
4      0534        0524        7B00
5      0635        0625        7C00
6      0736        075E      071E    7D00
7      0837        0826        7E00
8      0938        092A        7F00
9      0A39        0A28        8000
0      0B30        0B29        8100
*/
/*
Key     Normal    Shifted   w/Ctrl    w/Alt
-      0C2D        0C5F      0C1F    8200
=      0D3D        0D2B        8300
[      1A5B        1A7B      1A1B    1A00
]      1B5D        1B7D      1B1D    1B00
;      273B        273A        2700
'      2827        2822
`      2960        297E
\      2B5C        2B7C      2B1C    2600 (same as Alt L)
,      332C        333C
.      342E        343E
/      352F        353F
*/
SCCC_MINUS = 0x0C2D,      // '-' "minus" key
SCCC_EQUALS = 0x0D3D,      // '=' "equals" key

SCCC_PLUS = 0x0D2B,      // '+' "plus" key

/*
Key     Normal      Shifted   w/Ctrl  w/Alt
F1      3B00        5400      5E00    6800
F2      3C00        5500      5F00    6900
F3      3D00        5600      6000    6A00
F4      3E00        5700      6100    6B00
F5      3F00        5800      6200    6C00
F6      4000        5900      6300    6D00
F7      4100        5A00      6400    6E00
F8      4200        5B00      6500    6F00
F9      4300        5C00      6600    7000
F10     4400        5D00      6700    7100
F11     8500        8700      8900    8B00
F12     8600        8800      8A00    8C00
*/
    SCCC_F10 = 0x4400,      // "F10" key

    // BackSpace   0E08
    // Del         5300
    SCCC_KP_2       = 0x5000,   // Numeric Keypad 2 (Down)
    SCCC_DOWN       = 0x50E0,   // Down Arrow  ||  NumLock + Numeric Keypad 2 (Down)
    SCCC_KP_1       = 0x4F00,   // Numeric Keypad 1 (End)
    SCCC_DOWNLEFT   = 0x4FE0,   // NumLock + Numeric Keypad 1 (DownLeft)
    // Enter       1C0D
    // Esc         011B
    SCCC_KP_7       = 0x4700,   // Numeric Keypad 7 (Home)
    SCCC_UPLEFT     = 0x47E0,   // NumLock + Numeric Keypad 7 (UpLeft)
    // Ins         5200
    // Keypad 5        
    // Keypad *    372A
    // Keypad -    4A2D
    // Keypad +    4E2B
    // Keypad /    352F
    SCCC_KP_4       = 0x4B00,   // Numeric Keypad 4 (Left)
    SCCC_LEFT       = 0x4BE0,   // Left Arrow  ||  NumLock + Numeric Keypad 4 (Left)
    SCCC_KP_3       = 0x5100,   // Numeric Keypad 3 (PgDn)
    SCCC_DOWNRIGHT  = 0x51E0,   // NumLock + Numeric Keypad 3 (DownRight)
    SCCC_KP_9       = 0x4900,   // Numeric Keypad 9 (PgUp)
    SCCC_UPRIGHT    = 0x49E0,   // NumLock + Numeric Keypad 9 (UpRight)
    // PrtSc           
    SCCC_KP_6       = 0x4D00,   // Numeric Keypad 6 (Right)
    SCCC_RIGHT      = 0x4DE0,   // Right Arrow  ||  NumLock + Numeric Keypad 6 (Right)
    // SpaceBar    3920
    // Tab         0F09
    SCCC_KP_8       = 0x4800,   // Numeric Keypad 8 (Up)
    SCCC_UP         = 0x48E0,   // Up Arrow  ||  NumLock + Numeric Keypad 8 (Up)

/*
Key         Normal  Shifted     w/Ctrl  w/Alt
BackSpace   0E08    0E08        0E7F    0E00
Del         5300    532E        9300    A300
Down Arrow  5000    5032        9100    A000
End         4F00    4F31        7500    9F00
Enter       1C0D    1C0D        1C0A    A600
Esc         011B    011B        011B    0100
Home        4700    4737        7700    9700
Ins         5200    5230        9200    A200
Keypad 5            4C35        8F00
Keypad *    372A                9600    3700
Keypad -    4A2D    4A2D        8E00    4A00
Keypad +    4E2B    4E2B                4E00
Keypad /    352F    352F        9500    A400
Left Arrow  4B00    4B34        7300    9B00
PgDn        5100    5133        7600    A100
PgUp        4900    4939        8400    9900
PrtSc                           7200
Right Arrow 4D00    4D36        7400    9D00
SpaceBar    3920    3920        3920    3920
Tab         0F09    0F00        9400    A500
Up Arrow    4800    4838        8D00    9800
*/

    SCCC_OVERRUN
};
//     /*  32 0x20 */  0x3920,  /* VK_SPACE */
//     /*  48 0x30 */  0x0B30,  /* VK_0 */
//     /*  49 0x31 */  0x0231,  /* VK_1 */
//     /*  50 0x32 */  0x0332,  /* VK_2 */
//     /*  51 0x33 */  0x0433,  /* VK_3 */
//     /*  52 0x34 */  0x0534,  /* VK_4 */
//     /*  53 0x35 */  0x0635,  /* VK_5 */
//     /*  54 0x36 */  0x0736,  /* VK_6 */
//     /*  55 0x37 */  0x0837,  /* VK_7 */
//     /*  56 0x38 */  0x0938,  /* VK_8 */
//     /*  57 0x39 */  0x0A39,  /* VK_9 */


//     /*  66 0x42 */  0x3062,  /* VK_B */
//     /*  67 0x43 */  0x2E63,  /* VK_C */
//     /*  68 0x44 */  0x2064,  /* VK_D */
//     /*  69 0x45 */  0x1265,  /* VK_E */
//     /*  70 0x46 */  0x2166,  /* VK_F */
//     /*  71 0x47 */  0x2267,  /* VK_G */
//     /*  72 0x48 */  0x2368,  /* VK_H */
//     /*  73 0x49 */  0x1769,  /* VK_I */
//     /*  74 0x4A */  0x246A,  /* VK_J */
//     /*  75 0x4B */  0x256B,  /* VK_K */
//     /*  76 0x4C */  0x266C,  /* VK_L */
//     /*  77 0x4D */  0x326D,  /* VK_M */
//     /*  78 0x4E */  0x316E,  /* VK_N */
//     /*  79 0x4F */  0x186F,  /* VK_O */
//     /*  80 0x50 */  0x1970,  /* VK_P */

//     /*  82 0x52 */  0x1372,  /* VK_R */
//     /*  83 0x53 */  0x1F73,  /* VK_S */
//     /*  84 0x54 */  0x1474,  /* VK_T */
//     /*  85 0x55 */  0x1675,  /* VK_U */
//     /*  86 0x56 */  0x2F76,  /* VK_V */
//     /*  87 0x57 */  0x1177,  /* VK_W */
//     /*  88 0x58 */  0x2D78,  /* VK_X */
//     /*  89 0x59 */  0x1579,  /* VK_Y */
//     /*  90 0x5A */  0x2C7A,  /* VK_Z */

/*

    the manual says "by hitting the keys on the numeric keypad"
    {1,2,3,4,5,6,7,8}
    {KP_Left, KP_Right, KP_Up, KP_Down, KP_RightUp, KP_RightDown, KP_LeftUp, KP_LeftDown}

KP_Left  = 1
KP_Right  = 2
KP_Up  = 3
KP_Down  = 4
KP_RightUp  = 5
KP_RightDown  = 6
KP_LeftUp  = 7
KP_LeftDown  = 8

The regular Home, End, PgUp, PgDn keys do not do anything.
Not sure what 'Enter' is doing with Unit Movement, or why it is even matching an input field.


SCANCODES FOR SCANCODE SET 1 (XT)
US 104-key keyboard, set 1 scancodes
When the kayboard's internal NumLock is active:
    two-byte repeat code  = E0nn

4 (L)  4B
(L) E04B

So, ...
Numeric Keypad 4 is 0x4B
Left is 0xE04B
Anywhoodle, ...
    just map Numeric Keypard 4 and Left to SimTex Left

*/

enum e_SimTex_Key_Codes
{
//     KP_NumMult         = 0x00,
    ST_KEY_LEFT             = 0x01,
    ST_KEY_RIGHT            = 0x02,
    ST_KEY_UP               = 0x03,
    ST_KEY_DOWN             = 0x04,
    ST_KEY_RIGHTUP          = 0x05,
    ST_KEY_RIGHTDOWN        = 0x06,
    ST_KEY_LEFTUP           = 0x07,
    ST_KEY_LEFTDOWN         = 0x08,
//     KP_Insert          = 0x09,
//     KP_Delete          = 0x0A,
    ST_KEY_BACKSPACE        = 0x0B,
    ST_KEY_ENTER            = 0x0C,
    ST_KEY_TAB              = 0x0D,
    ST_KEY_F1               = 0x0E,
    ST_KEY_F2               = 0x0F,
    ST_KEY_F3               = 0x10,
    ST_KEY_F4               = 0x11,
    ST_KEY_F5               = 0x12,
    ST_KEY_F6               = 0x13,
    ST_KEY_F7               = 0x14,
    ST_KEY_F8               = 0x15,
    ST_KEY_F9               = 0x16,
    ST_KEY_F10              = 0x17,
    // IDK ST_KEY_KP_9             = 0x19,  /* PAGEUP */
    // IDK ST_KEY_KP_7             = 0x1A,  /* HOME */
    ST_KEY_ESCAPE           = 0x1B,
//     KP_End             = 0x1C,
    // IDK ST_KEY_KP_3             = 0x1D,  /* PAGEDOWN */
//     KP_Center          = 0x1E,
//     KP_NumPlus         = 0x2B,
//     KP_NumMinus        = 0x2D,
//     KP_Ctrl_Right      = 0x80,
//     KP_Ctrl_Left       = 0x81,
//     KP_Ctrl_Up         = 0x82,
//     KP_Ctrl_Down       = 0x83,
//     KP_Ctrl_LeftUp     = 0x84,
//     KP_Ctrl_RightUp    = 0x85,
//     KP_Ctrl_LeftDown   = 0x86,
//     KP_Ctrl_RightDown  = 0x87,
//     KP_Ctrl_s          = 0x90,
    ST_KEY_F11              = 0x91,
    ST_KEY_F12              = 0x92,
/* MoO2  Get_Alt_Alpha_Key()  character => alpha_key */
    ST_KEY_ALT_A            = 0xA0,  /* 160d  160 - 95 = 65 41h 'A' */
//     KP_Alt_b           = 0xA1,
//     KP_Alt_c           = 0xA2,
//     KP_Alt_d           = 0xA3,
//     KP_Alt_e           = 0xA4,
//     KP_Alt_f           = 0xA5,
//     KP_Alt_g           = 0xA6,
//     KP_Alt_h           = 0xA7,
//     KP_Alt_i           = 0xA8,
//     KP_Alt_j           = 0xA9,
//     KP_Alt_k           = 0xAA,
//     KP_Alt_l           = 0xAB,
//     KP_Alt_m           = 0xAC,
//     KP_Alt_n           = 0xAD,
//     KP_Alt_o           = 0xAE,
//     KP_Alt_p           = 0xAF,
//     KP_Alt_q           = 0xB0,
//     KP_Alt_r           = 0xB1,
//     KP_Alt_s           = 0xB2,
//     KP_Alt_t           = 0xB3,
//     KP_Alt_u           = 0xB4,
//     KP_Alt_v           = 0xB5,
//     KP_Alt_w           = 0xB6,
//     KP_Alt_x           = 0xB7,
//     KP_Alt_y           = 0xB8,
//     KP_Alt_z           = 0xB9,
    ST_KEY_OVERRUN
};


/*
enum EKEYCODES
EKey_Num7_Home  = 47h
EKey_Num8_Up  = 48h
EKey_Num9_PgUp  = 49h
EKey_NumMinus  = 4Ah
EKey_Num4_Left  = 4Bh
EKey_Num5  = 4Ch
EKey_Num6_Right  = 4Dh
EKey_NumPlus  = 4Eh
EKey_Num1_End  = 4Fh
EKey_Num2_Down  = 50h
EKey_Num3_PgDn  = 51h
EKey_Esc  = 11Bh
EKey_NumMult  = 92Ah
EKey_Backspace  = 0E08h
EKey_Tab  = 0F09h
EKey_Alt_q  = 1000h
EKey_Alt_w  = 1100h
EKey_Alt_e  = 1200h
EKey_Alt_r  = 1300h
EKey_Alt_t  = 1400h
EKey_Alt_y  = 1500h
EKey_Alt_u  = 1600h
EKey_Alt_i  = 1700h
EKey_Alt_o  = 1800h
EKey_Alt_p  = 1900h
EKey_Enter  = 1C0Dh
EKey_Alt_a  = 1E00h
EKey_Alt_s  = 1F00h
EKey_Ctrl_s  = 1F13h
EKey_Alt_d  = 2000h
EKey_Alt_f  = 2100h
EKey_Alt_g  = 2200h
EKey_Alt_h  = 2300h
EKey_Alt_j  = 2400h
EKey_Alt_k  = 2500h
EKey_Alt_l  = 2600h
EKey_Alt_z  = 2C00h
EKey_Alt_x  = 2D00h
EKey_Alt_c  = 2E00h
EKey_Alt_v  = 2F00h
EKey_Alt_b  = 3000h
EKey_Alt_n  = 3100h
EKey_Alt_m  = 3200h
EKey_F1  = 3B00h
EKey_F2  = 3C00h
EKey_F3  = 3D00h
EKey_F4  = 3E00h
EKey_F5  = 3F00h
EKey_F6  = 4000h
EKey_F7  = 4100h
EKey_F8  = 4200h
EKey_F9  = 4300h
EKey_F10  = 4400h
EKey_Home  = 47E0h
EKey_Up  = 48E0h
EKey_PgUp  = 49E0h
EKey_Left  = 4BE0h
EKey_Right  = 4DE0h
EKey_End  = 4FE0h
EKey_Down  = 50E0h
EKey_PgDn  = 51E0h
EKey_Ins  = 52E0h
EKey_Del  = 53E0h
EKey_Ctrl_Num4  = 7300h
EKey_Ctrl_Left  = 73E0h
EKey_Ctrl_Num6  = 7400h
EKey_Ctrl_Right  = 74E0h
EKey_Ctrl_Num1  = 7500h
EKey_Ctrl_Num3  = 7600h
EKey_Ctrl_Num7  = 7700h
EKey_Ctrl_Num9  = 8400h
EKey_F11  = 8500h
EKey_F12  = 8600h
EKey_Ctrl_Num8  = 8D00h
EKey_Ctrl_Up  = 8DE0h
EKey_Ctrl_Num2  = 9100h
EKey_Ctrl_Down  = 91E0h
EKey_NumEnter  = 0E00Dh
*/



#ifdef __cplusplus
extern "C" {
#endif
    /* C and Asm Function Prototypes */



// Interpret_Mouse_Input                          seg036     0000000C 00000F5F R F . . B T .
// UU_GUI_SetTimeOutP                             seg036     00000F90 0000001C R F . . B T .
// UU_GUI_SetTimeOutN                             seg036     00000FAC 0000001C R F . . B T .
// UU_GUI_EditStart                               seg036     00000FC8 00000010 R F . . B T .
// UU_GUI_SetClickBuffer                          seg036     00000FD8 00000031 R F . . B T .
// UU_GUI_LoadClickFile                           seg036     00001009 00000054 R F . . B T .
// UU_GUI_SaveClickFile                           seg036     0000105D 00000047 R F . . B T .
// 
// G_GUI_ClearInput                               seg036     00002EE2 0000003C R F . . B T .
// G_GUI_PressAnyKey                              seg036     00002F1E 0000018B R F . . B T .
// GUI_ProcessDirKey                              seg036     000030A9 000002C8 R F . . B T .
// GUI_EditBoxControl                             seg036     0000339F 0000042B R F . . B T .
// GUI_TextEditDialog                             seg036     000037E1 000003C9 R F . . B T .
// GUI_EditBoxRedraw                              seg036     00003BC1 000003E7 R F . . B T .
// GUI_CreateEditBox                              seg036     00003FA8 000001CF R F . . B T .
// 
// GUI_CreateImageLabel                           seg036     00004667 00000147 R F . . B T .
// UU_GUI_CreateWndImgLbl                         seg036     000047AE 000001D0 R F . . B T .
// Set_Button_Down_Offsets                        seg036     0000497E 00000011 R F . . B T .



/*
    WIZARDS.EXE seg036
    MAGIC.EXE seg034
*/

// WZD s36p01
int16_t Interpret_Mouse_Input(void);


// WZD s36p08
void Set_Global_ESC(void);


// WZD s36p12
// // // void Set_Help_List(struct s_HELP_FIELD * help_pointer, int16_t count);
// // // void Set_Help_List(struct s_HELP_FIELD * help_pointer[], int16_t count);
// // void Set_Help_List(struct s_HELP_FIELD ** help_pointer, int16_t count);
// void Set_Help_List(int16_t * help_pointer, int16_t count);
void Set_Help_List(char * help_pointer, int16_t count);

// WZD s36p13
void Deactivate_Help_List(void);

// WZD s36p14
int16_t Check_Help_List__STUB(void);

// UU_GUI_GetControlWidth                         seg036     000011C1 0000004D R F . . B T .
// UU_GUI_GetControlHeight                        seg036     0000120E 0000004E R F . . B T .
// UU_GUI_GetLastClickX                           seg036     0000125C 0000000A R F . . B T .
// UU_GUI_GetLastClickY                           seg036     00001266 0000000A R F . . B T .
// UU_GUI_GetLastClickBtns                        seg036     00001270 0000000A R F . . B T .
// Get_Mouse_Field                                seg036     0000127A 0000000A R F . . B T .
// RP_GUI_KeyInputOnly                            seg036     00001284 00000675 R F . . B T .
// Interpret_Keyboard_Input                       seg036     000018F9 000004AB R F . . B T .
// GUI_GetNextControl                             seg036     00001DC5 00000DAC R F . . B T .

// WZD s36p24
void UU_GUI_MouseEMUMoveTo(int16_t field_idx);


// WZD s36p25
int16_t Scan_Field(void);

// WZD s36p26
int16_t Scan_Input(void);

// WZD s36p27
// drake178: UU_GUI_KeyWaitLoop()

// WZD s36p28
// drake178: G_GUI_ClearInput()
// MoO2  Module: fields  Reset_Wait_For_Input()
void Reset_Wait_For_Input(void);

// WZD s36p29
// drake178: G_GUI_PressAnyKey()
// MoO2  Module: fields  Wait_For_Input()
int16_t Wait_For_Input(void);

// WZD s36p30
// drake178: GUI_ProcessDirKey()
int16_t Process_Direction_Key__STUB(int16_t dir_key);

// WZD s36p65  AKA GUI_Init()  AKA IN_Init()
void Init_Mouse_Keyboard(int16_t input_type);



// PLATFORM
// WZD s36p66
/*
    returns field_idx/num
*/
int16_t Get_Input(void);



// WZD s36p67
void Set_Input_Delay(int16_t delay);

// WZD s36p68
int16_t Get_Input_Delay(void);


// WZD s36p85
// drake178: GUI_SimplePageFlip()
// AKA SCRN_SimplePageFlip()
// MoO2  Module: video  Toggle_Pages()  &&  Module: MOX2  _TOGGLE_PAGES_
void Toggle_Pages(void);



#ifdef __cplusplus
}
#endif

#endif  /* INPUT_H */
