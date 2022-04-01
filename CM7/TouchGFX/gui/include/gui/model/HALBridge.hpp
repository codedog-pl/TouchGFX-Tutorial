/**
 * HAL access bridge betwen main and TouchGFX code. TouchGFX side.
 */

#ifndef SIMULATOR
extern "C"
{
bool HAL_BRIDGE_GetTestPinState();
void HAL_BRIDGE_SetLED1(bool state);
void HAL_BRIDGE_SetLED2(bool state);
void HAL_BRIDGE_SetLED3(bool state);
void HAL_BRIDGE_SetLED4(bool state);
}
#endif

class HALBridge
{
public:
	enum LEDs : int
	{
		LEDS_NONE = 0,
		LEDS_GREEN = 1,
		LEDS_ORANGE = 2,
		LEDS_RED = 4,
		LEDS_BLUE = 8,
		LEDS_ALL = 15
	};
	static bool getTestPinState()
	{
		return HAL_BRIDGE_GetTestPinState();
	}
	static void setLEDs(int state)
	{
		HAL_BRIDGE_SetLED1((state & LEDS_GREEN) > 0);
		HAL_BRIDGE_SetLED2((state & LEDS_ORANGE) > 0);
		HAL_BRIDGE_SetLED3((state & LEDS_RED) > 0);
		HAL_BRIDGE_SetLED4((state & LEDS_BLUE) > 0);
	}
private:
#ifdef SIMULATOR
	static bool HAL_BRIDGE_GetTestPinState() { return true; }
	static void HAL_BRIDGE_SetLED1(bool state) { }
	static void HAL_BRIDGE_SetLED2(bool state) { }
	static void HAL_BRIDGE_SetLED3(bool state) { }
	static void HAL_BRIDGE_SetLED4(bool state) { }
#endif
};
