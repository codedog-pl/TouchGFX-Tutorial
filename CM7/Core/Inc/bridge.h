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

#ifdef __cplusplus
}
#endif

#endif /* BRIDGE_H */
