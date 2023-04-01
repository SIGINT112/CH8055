#ifndef __USB_HID_KBD_H__
#define __USB_HID_KBD_H__

#include <stdint.h>
#include "include/ch5xx.h"
#include "include/ch5xx_usb.h"

#ifdef __cplusplus
extern "C" {
#endif

void USBInit(void);

uint8_t Keyboard_press(uint8_t x,uint8_t y,uint8_t z,uint8_t k);
uint8_t Keyboard_release(uint8_t k);
void Keyboard_releaseAll(void);

uint8_t Keyboard_write(uint8_t c);

uint8_t Keyboard_getLEDStatus();

#ifdef __cplusplus
} // extern "C"
#endif

#endif

