/*
 * HAL bindings for the TouchGFX Model.
 */

#ifndef BRIDGE_H
#define BRIDGE_H

#include "main.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

bool BRIDGE_GetTestPinState() { return HAL_GPIO_ReadPin(TEST_PIN_GPIO_Port, TEST_PIN_Pin) == GPIO_PIN_SET; }
void BRIDGE_SetLED1(bool state) { HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);  }
void BRIDGE_SetLED2(bool state) { HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);  }
void BRIDGE_SetLED3(bool state) { HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);  }
void BRIDGE_SetLED4(bool state) { HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);  }

#ifdef __cplusplus
}
#endif

#endif /* BRIDGE_H */
