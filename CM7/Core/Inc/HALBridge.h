/**
 * HAL access bridge between main and TouchGFX code. Main side.
 */

#ifndef HAL_BRIDGE_H
#define HAL_BRIDGE_H

#ifndef SIMULATOR

#include "main.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

bool HAL_BRIDGE_GetTestPinState() { return HAL_GPIO_ReadPin(TEST_PIN_GPIO_Port, TEST_PIN_Pin) == GPIO_PIN_SET; }
void HAL_BRIDGE_SetLED1(bool state) { HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET); }
void HAL_BRIDGE_SetLED2(bool state) { HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET); }
void HAL_BRIDGE_SetLED3(bool state) { HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET); }
void HAL_BRIDGE_SetLED4(bool state) { HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET); }

#ifdef __cplusplus
}
#endif

#endif // !SIMULATOR

#endif // HAL_BRIDGE_H
