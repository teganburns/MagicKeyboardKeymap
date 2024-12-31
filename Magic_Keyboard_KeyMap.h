#ifndef MAGIC_KEYBOARD_KEYMAP_H
#define MAGIC_KEYBOARD_KEYMAP_H

#include <avr/pgmspace.h>

// Define a struct to hold key information
struct KeyInfo {
    uint8_t hexCode;         // Hexadecimal keycode
    int asciiValue;          // ASCII value (or -1 if not applicable)
    const char* description; // Key description
};

// Special keys map (last byte of HID report)
const KeyInfo specialKeyMap[] PROGMEM = {
    {0x04, -1, "Fingerprint Reader"}, // Special key: Fingerprint reader
    {0x01, -1, "Power Button"},       // Special key: Power button
    {0x02, -1, "Siri Button"}         // Special key: Siri activation button (if applicable)
};

// Modifier keys map
const KeyInfo modifierKeyMap[] PROGMEM = {
    {0xE0, -1, "Left Control"}, {0xE1, -1, "Left Shift"},
    {0xE2, -1, "Left Option"}, {0xE3, -1, "Left Command"},
    {0xE4, -1, "Right Control"}, {0xE5, -1, "Right Shift"},
    {0xE6, -1, "Right Option"}, {0xE7, -1, "Right Command"}
};

// State-changing keys map (e.g., lock keys)
const KeyInfo stateKeyMap[] PROGMEM = {
    {0x39, -1, "Caps Lock"},
    {0x47, -1, "Scroll Lock"},
    {0x53, -1, "Num Lock"},
    {0x82, -1, "Locking Caps Lock"},
    {0x83, -1, "Locking Num Lock"},
    {0x84, -1, "Locking Scroll Lock"}
};

// Top Row Special Characters (Shifted variants)
const KeyInfo shiftedKeyMap[] PROGMEM = {

    {0x1E, '!', "!"},  // Shift + 1 = !
    {0x1F, '@', "@"},  // Shift + 2 = @
    {0x20, '#', "#"},  // Shift + 3 = #
    {0x21, '$', "$"},  // Shift + 4 = $
    {0x22, '%', "%"},  // Shift + 5 = %
    {0x23, '^', "^"},  // Shift + 6 = ^
    {0x24, '&', "&"},  // Shift + 7 = &
    {0x25, '*', "*"},  // Shift + 8 = *
    {0x26, '(', "("},  // Shift + 9 = (
    {0x27, ')', ")"},  // Shift + 0 = )

    // Symbols and Punctuation
    {0x2D, '_', "_"},  // Shift + '-' = _
    {0x2E, '+', "+"},  // Shift + '=' = +
    {0x2F, '{', "{"},  // Shift + '[' = {
    {0x30, '}', "}"},  // Shift + ']' = }
    {0x31, '|', "|"},  // Shift + '\' = |
    {0x33, ':', ":"},  // Shift + ';' = :
    {0x34, '"', "\""}, // Shift + '\'' = "
    {0x35, '~', "~"},  // Shift + '`' = ~
    {0x36, '<', "<"},  // Shift + ',' = <
    {0x37, '>', ">"},  // Shift + '.' = >
    {0x38, '?', "?"},   // Shift + '/' = ?

    // Alphanumeric Keys
    {0x04, 'a', "A"},
    {0x05, 'b', "B"},
    {0x06, 'c', "C"},
    {0x07, 'd', "D"},
    {0x08, 'e', "E"},
    {0x09, 'f', "F"},
    {0x0A, 'g', "G"},
    {0x0B, 'h', "H"},
    {0x0C, 'i', "I"},
    {0x0D, 'j', "J"},
    {0x0E, 'k', "K"},
    {0x0F, 'l', "L"},
    {0x10, 'm', "M"},
    {0x11, 'n', "N"},
    {0x12, 'o', "O"},
    {0x13, 'p', "P"},
    {0x14, 'q', "Q"},
    {0x15, 'r', "R"},
    {0x16, 's', "S"},
    {0x17, 't', "T"},
    {0x18, 'u', "U"},
    {0x19, 'v', "V"},
    {0x1A, 'w', "W"},
    {0x1B, 'x', "X"},
    {0x1C, 'y', "Y"},
    {0x1D, 'z', "Z"}

};

// Standard keys map (alphanumeric and functional keys)
const KeyInfo standardKeyMap[] PROGMEM = {

    // Alphanumeric Keys
    {0x04, 'a', "a"},
    {0x05, 'b', "b"},
    {0x06, 'c', "c"},
    {0x07, 'd', "d"},
    {0x08, 'e', "e"},
    {0x09, 'f', "f"},
    {0x0A, 'g', "g"},
    {0x0B, 'h', "h"},
    {0x0C, 'i', "i"},
    {0x0D, 'j', "j"},
    {0x0E, 'k', "k"},
    {0x0F, 'l', "l"},
    {0x10, 'm', "m"},
    {0x11, 'n', "n"},
    {0x12, 'o', "o"},
    {0x13, 'p', "p"},
    {0x14, 'q', "q"},
    {0x15, 'r', "r"},
    {0x16, 's', "s"},
    {0x17, 't', "t"},
    {0x18, 'u', "u"},
    {0x19, 'v', "v"},
    {0x1A, 'w', "w"},
    {0x1B, 'x', "x"},
    {0x1C, 'y', "y"},
    {0x1D, 'z', "z"},

    // Numbers (Top Row)
    {0x1E, '1', "1 (Top Row)"},
    {0x1F, '2', "2 (Top Row)"},
    {0x20, '3', "3 (Top Row)"},
    {0x21, '4', "4 (Top Row)"},
    {0x22, '5', "5 (Top Row)"},
    {0x23, '6', "6 (Top Row)"},
    {0x24, '7', "7 (Top Row)"},
    {0x25, '8', "8 (Top Row)"},
    {0x26, '9', "9 (Top Row)"},
    {0x27, '0', "0 (Top Row)"},

    // Numeric Keypad
    {0x62, '0', "0 (Numpad)"},
    {0x59, '1', "1 (Numpad)"},
    {0x5A, '2', "2 (Numpad)"},
    {0x5B, '3', "3 (Numpad)"},
    {0x5C, '4', "4 (Numpad)"},
    {0x5D, '5', "5 (Numpad)"},
    {0x5E, '6', "6 (Numpad)"},
    {0x5F, '7', "7 (Numpad)"},
    {0x60, '8', "8 (Numpad)"},
    {0x61, '9', "9 (Numpad)"},
    {0x58, -1, "Enter (Numpad)"},
    {0x54, '/', "Divide (Numpad)"},
    {0x55, '*', "Multiply (Numpad)"},
    {0x56, '-', "Subtract (Numpad)"},
    {0x57, '+', "Add (Numpad)"},
    {0x63, '.', "Decimal (Numpad)"},
    {0x67, '=', "Equal (Numpad)"},


    // Symbol Keys
    {0x2D, '-', "Hyphen"},
    {0x2E, '=', "EqualSign"},
    {0x2F, '[', "OpenBracket"},
    {0x30, ']', "CloseBracket"},
    {0x31, '\\', "Backslash"},
    {0x33, ';', "Semicolon"},
    {0x34, '\'', "Quote"},
    {0x35, '`', "GraveAccentAndTilde"},
    {0x36, ',', "Comma"},
    {0x37, '.', "Period"},
    {0x38, '/', "Slash"},
    {0x32, -1, "NonUSPound"},
    {0x64, -1, "NonUSBackslash"},

    // Special Keys
    {0x2C, ' ', "Spacebar"},
    {0x28, '\n', "Enter"},
    {0x29, 27, "Escape"},        // 27 = ESC
    {0x2A, 8, "Backspace"},      // 8 = BS
    {0x2B, '\t', "Tab"},         // 9 = Tab
    {0x4C, -1, "Delete"},
    {0x52, -1, "Arrow Up"},
    {0x51, -1, "Arrow Down"},
    {0x50, -1, "Arrow Left"},
    {0x4F, -1, "Arrow Right"},
    {0x4A, -1, "Home"},
    {0x4B, -1, "PageUp"},
    {0x4D, -1, "End"},
    {0x4E, -1, "PageDown"},
    {0x49, -1, "Insert"},

    // Function Keys
    {0x3A, -1, "F1"},
    {0x3B, -1, "F2"},
    {0x3C, -1, "F3"},
    {0x3D, -1, "F4"},
    {0x3E, -1, "F5"},
    {0x3F, -1, "F6"},
    {0x40, -1, "F7"},
    {0x41, -1, "F8"},
    {0x42, -1, "F9"},
    {0x43, -1, "F10"},
    {0x44, -1, "F11"},
    {0x45, -1, "F12"},
    {0x68, -1, "F13"},
    {0x69, -1, "F14"},
    {0x6A, -1, "F15"},
    {0x6B, -1, "F16"},
    {0x6C, -1, "F17"},
    {0x6D, -1, "F18"},
    {0x6E, -1, "F19"},
    // Add more if needed:
    {0x6F, -1, "F20"},
    {0x70, -1, "F21"},
    {0x71, -1, "F22"},
    {0x72, -1, "F23"},
    {0x73, -1, "F24"},

    // Media Keys
    {0x48, -1, "Pause"},
    {0x78, -1, "Stop"},
    {0x7F, -1, "Mute"},
    {0x80, -1, "VolumeUp"},
    {0x81, -1, "VolumeDown"},

    // Input Method / LANG Keys
    {0x90, -1, "LANG1"},
    {0x91, -1, "LANG2"},
    {0x92, -1, "LANG3"},
    {0x93, -1, "LANG4"},
    {0x94, -1, "LANG5"},
    {0x95, -1, "LANG6"},
    {0x96, -1, "LANG7"},
    {0x97, -1, "LANG8"},
    {0x98, -1, "LANG9"},

    // International Keys
    {0x87, -1, "International1"},
    {0x88, -1, "International2"},
    {0x89, -1, "International3"},
    {0x8A, -1, "International4"},
    {0x8B, -1, "International5"},
    {0x8C, -1, "International6"},
    {0x8D, -1, "International7"},
    {0x8E, -1, "International8"},
    {0x8F, -1, "International9"},

    // Other / System Keys
    {0x01, -1, "ErrorRollOver"},
    {0x03, -1, "ErrorUndefined"},
    {0x79, -1, "Again"},
    {0x99, -1, "AlternateErase"},
    {0x65, -1, "Application"},
    {0x9B, -1, "Cancel"},
    {0x9C, -1, "Clear"},
    {0xA2, -1, "ClearOrAgain"},
    {0x7C, -1, "Copy"},
    {0xA3, -1, "CrSelOrProps"},
    {0x7B, -1, "Cut"},
    {0xA4, -1, "ExSel"},
    {0x74, -1, "Execute"},
    {0x7E, -1, "Find"},
    {0x75, -1, "Help"},
    {0x76, -1, "Menu"},
    {0xA1, -1, "Oper"},
    {0xA0, -1, "Out"},
    {0x02, -1, "POSTFail"},
    {0x7D, -1, "Paste"},
    {0x66, -1, "Power"},
    {0x46, -1, "PrintScreen"},
    {0x9D, -1, "Prior"},
    {0x77, -1, "Select"},
    {0x9A, -1, "SysReqOrAttention"},
    {0x7A, -1, "Undo"}

// Add other special buttons as needed, based on their hex codes
};


// Number of entries in each key map array
constexpr size_t specialKeyMapSize = sizeof(specialKeyMap) / sizeof(KeyInfo);
constexpr size_t modifierKeyMapSize = sizeof(modifierKeyMap) / sizeof(KeyInfo);
constexpr size_t stateKeyMapSize = sizeof(stateKeyMap) / sizeof(KeyInfo);
constexpr size_t shiftedKeyMapSize = sizeof(shiftedKeyMap) / sizeof(KeyInfo);
constexpr size_t standardKeyMapSize = sizeof(standardKeyMap) / sizeof(KeyInfo);

#endif // MAGIC_KEYBOARD_KEYMAP_H
