#include "ButtonTime.h"

#define HIGH 1
#define true 1
#define LOW 0
#define false 0

const static unsigned long debounceTime = 10;
const static int rising = 1;
const static int falling = -1;

/*
 * This function count second of button holding
 * */
int readByDebounce(GPIO_TypeDef * gpioX, int pin){

	unsigned long prevBounceTime = 0;
	unsigned long currBounceTime = 0;

	unsigned long startTime = HAL_GetTick();
	unsigned long endTime = 0;

	int prevState = HIGH;
  	int pressed = false;
  	int stateChange;
  	int state;

  	do{
  			//read button state
			state = HAL_GPIO_ReadPin(gpioX, pin);
			//state tracking var
			stateChange = state - prevState;

			if (stateChange == falling){
				//when bounce time expired button consider released
				if (HAL_GetTick() - prevBounceTime > debounceTime) {

					pressed=true;

					int continuePress=0;

					//fix end time for calculate holding duration
					endTime=HAL_GetTick();
					//release button bounce loop
					while(HAL_GetTick() - endTime < debounceTime){
						if(HAL_GPIO_ReadPin(gpioX, pin)){
							continuePress=1;
							state = HIGH;
							// read the button's state
							stateChange = state - prevState;
							break;
						}
					}
					if(!continuePress){
						pressed = true;
						break;
					}
				}
			}
			//execute update start time when
			if (stateChange == rising) {
				prevBounceTime = HAL_GetTick();
				//if(!pressed)
				startTime=HAL_GetTick();
			}

			//update preview state for feature detect changing
			prevState = state;

	}while(stateChange==0);

  	//blink LED for debugging state
  	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);

  	//convert milliseconds to seconds and rounding
  	return round(((double)(endTime-startTime))/((double)1000));
}
