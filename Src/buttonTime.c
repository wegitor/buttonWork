#include "ButtonTime.h"

#define HIGH 1
#define true 1
#define LOW 0
#define false 0

const static unsigned long debounceTime = 25;
const static int rising = 1;
const static int falling = -1;


int readByDebounce(GPIO_TypeDef * gpioX, int pin){
	unsigned long prevBounceTime = 0;
	unsigned long currBounceTime = 0;
	unsigned long startTime = HAL_GetTick();
	unsigned long endTime = 0;

	int prevState = HIGH;
  	int pressed = false;
  	int stateChange;
  	do{

			int state = HAL_GPIO_ReadPin(gpioX, pin);

			stateChange = state - prevState;

			if (stateChange == falling){
				if (HAL_GetTick() - prevBounceTime > debounceTime) {
				  endTime=HAL_GetTick();
				  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
				  break;
				}
			}
			if (stateChange == rising) {

			  prevBounceTime = HAL_GetTick();
			  startTime=HAL_GetTick();

			}
			prevState = state;

	 }while(stateChange==0);
  	return round((double)(endTime-startTime)/1000);
}

