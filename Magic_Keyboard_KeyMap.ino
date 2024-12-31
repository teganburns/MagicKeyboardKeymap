#include <hidboot.h>
#include <usbhub.h>
#include <SPI.h>
#include "Magic_Keyboard_KeyMap.h" // Include your updated header file

#define DEBUG_MODE true // Set to true to enable raw hex output

// Function to find a key in a specific map
const char* getKeyDescription(const KeyInfo* map, size_t mapSize, uint8_t hexCode) {
    for (size_t i = 0; i < mapSize; i++) {
        KeyInfo key;
        memcpy_P(&key, &map[i], sizeof(KeyInfo)); // Read from PROGMEM
        if (key.hexCode == hexCode) {
            return key.description; // Return the description
        }
    }
    return nullptr; // If no match is found
}

// Custom parser class
class CustomKeyboardParser : public KeyboardReportParser {
protected:
    void Parse(USBHID* hid, bool is_rpt_id, uint8_t len, uint8_t* buf) override {
        if (len < 8) return; // Ensure report length is valid

        // Debug: Print raw hex data
        if (DEBUG_MODE) {
            Serial.print("Raw Hex: ");
            for (uint8_t i = 0; i < len; i++) {
                if (buf[i] < 0x10) Serial.print("0"); // Add leading zero for single-digit hex values
                Serial.print(buf[i], HEX);
                Serial.print(" ");
            }
            Serial.println();
        }

        // Process modifier keys (second byte of HID report)
        uint8_t modifiers = buf[1];
        bool isShiftPressed = modifiers & 0x22; // Check Left Shift (0x02) or Right Shift (0x20)
        if (modifiers > 0) {
            for (int i = 0; i < 8; i++) {
                if (modifiers & (1 << i)) { // Check each bit
                    const char* modifierDesc = getKeyDescription(modifierKeyMap, modifierKeyMapSize, 0xE0 + i);
                    if (modifierDesc) {
                        Serial.print(modifierDesc);
                        Serial.print(" ");
                    }
                }
            }
        }

        // Process state-changing keys (e.g., Caps Lock)
        for (int i = 2; i < len - 1; i++) {
            uint8_t keyCode = buf[i];
            if (keyCode > 0) {
                const char* stateDesc = getKeyDescription(stateKeyMap, stateKeyMapSize, keyCode);
                if (stateDesc) {
                    Serial.print(stateDesc);
                    Serial.print(" ");
                    continue; // Skip standard or shifted processing for state keys
                }
            }
        }

        // Process standard or shifted keys
        for (int i = 2; i < len - 1; i++) {
            uint8_t keyCode = buf[i];
            if (keyCode > 0) {
                if (isShiftPressed) {
                    const char* shiftedDesc = getKeyDescription(shiftedKeyMap, shiftedKeyMapSize, keyCode);
                    if (shiftedDesc) {
                        Serial.print(shiftedDesc);
                        Serial.print(" ");
                        continue; // Skip standard key processing if shifted key found
                    }
                }
                const char* keyDesc = getKeyDescription(standardKeyMap, standardKeyMapSize, keyCode);
                if (keyDesc) {
                    Serial.print(keyDesc);
                    Serial.print(" ");
                }
            }
        }

        // Process special buttons (last byte of HID report)
        uint8_t specialButton = buf[len - 1];
        if (specialButton > 0) {
            const char* specialDesc = getKeyDescription(specialKeyMap, specialKeyMapSize, specialButton);
            if (specialDesc) {
                Serial.print(specialDesc);
                Serial.print(" ");
            }
        }

        Serial.println(); // Add a newline at the end of the processed output
    }
};

// USB and HID setup
USB Usb;
HIDBoot<USB_HID_PROTOCOL_KEYBOARD> HidKeyboard(&Usb);
CustomKeyboardParser Parser;

void setup() {
    Serial.begin(921600); // Set baud rate
    while (!Serial); // Wait for serial connection (for boards like Leonardo)

    if (Usb.Init() == -1) {
        Serial.println("USB initialization failed");
        while (1); // Stop here if USB initialization fails
    }
    Serial.println("USB initialized");

    HidKeyboard.SetReportParser(0, &Parser); // Set the custom parser
}

void loop() {
    Usb.Task(); // USB task
}