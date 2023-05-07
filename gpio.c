#include "GPIO.h"
#include "common_macros.h"

void GPIO_ConfigPin(uint8 port_name, uint8 pin_num, GPIO_PinModeType mode, uint8 state)
{
	if(port_name >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS)
	{
		// do nothing
	}

	else
	{
		switch(port_name)
		{
		case PORTA_ID:
			SET_BIT(RCC_AHB1ENR, PORTA_ID);
			CLEAR_BIT_MODE(GPIOA_MODER, pin_num);
			SET_BIT_MODE(GPIOA_MODER, pin_num, mode);
			if(mode == PIN_OUTPUT)
			{
				if(state == STATE_OUTPUT_OPEN_DRAIN)
					SET_BIT(GPIOA_OTYPER, pin_num);
				else
				{
					CLEAR_BIT(GPIOA_OTYPER, pin_num);
				}
			}
			else
			{
				CLEAR_BIT_MODE(GPIOA_PUPDR, pin_num);
				SET_BIT_MODE(GPIOA_PUPDR, pin_num, state);
			}
			break;
		case PORTB_ID:
			SET_BIT(RCC_AHB1ENR, PORTB_ID);
			CLEAR_BIT_MODE(GPIOB_MODER, pin_num);
			SET_BIT_MODE(GPIOB_MODER, pin_num, mode);
			if(mode == PIN_OUTPUT)
			{
				if(state == STATE_OUTPUT_OPEN_DRAIN)
					SET_BIT(GPIOB_OTYPER, pin_num);
				else
				{
					CLEAR_BIT(GPIOB_OTYPER, pin_num);
				}
			}
			else
			{
				CLEAR_BIT_MODE(GPIOB_PUPDR, pin_num);
				SET_BIT_MODE(GPIOB_PUPDR, pin_num, state);
			}
			break;
		case PORTC_ID:
			SET_BIT(RCC_AHB1ENR, PORTC_ID);
			CLEAR_BIT_MODE(GPIOC_MODER, pin_num);
			SET_BIT_MODE(GPIOC_MODER, pin_num, mode);
			if(mode == PIN_OUTPUT)
			{
				if(state == STATE_OUTPUT_OPEN_DRAIN)
					SET_BIT(GPIOC_OTYPER, pin_num);
				else
				{
					CLEAR_BIT(GPIOC_OTYPER, pin_num);
				}
			}
			else
			{
				CLEAR_BIT_MODE(GPIOC_PUPDR, pin_num);
				SET_BIT_MODE(GPIOC_PUPDR, pin_num, state);
			}
			break;
		case PORTD_ID:
			SET_BIT(RCC_AHB1ENR, PORTD_ID);
			CLEAR_BIT_MODE(GPIOD_MODER, pin_num);
			SET_BIT_MODE(GPIOD_MODER, pin_num, mode);
			if(mode == PIN_OUTPUT)
			{
				if(state == STATE_OUTPUT_OPEN_DRAIN)
					SET_BIT(GPIOD_OTYPER, pin_num);
				else
				{
					CLEAR_BIT(GPIOD_OTYPER, pin_num);
				}
			}
			else
			{
				CLEAR_BIT_MODE(GPIOD_PUPDR, pin_num);
				SET_BIT_MODE(GPIOD_PUPDR, pin_num, state);
			}
			break;
		case PORTE_ID:
			SET_BIT(RCC_AHB1ENR, PORTE_ID);
			CLEAR_BIT_MODE(GPIOE_MODER, pin_num);
			SET_BIT_MODE(GPIOE_MODER, pin_num, mode);
			if(mode == PIN_OUTPUT)
			{
				if(state == STATE_OUTPUT_OPEN_DRAIN)
					SET_BIT(GPIOE_OTYPER, pin_num);
				else
				{
					CLEAR_BIT(GPIOE_OTYPER, pin_num);
				}
			}
			else
			{
				CLEAR_BIT_MODE(GPIOE_PUPDR, pin_num);
				SET_BIT_MODE(GPIOE_PUPDR, pin_num, state);
			}
			break;

		}
	}


}


uint8 GPIO_WritePin(uint8 port_name, uint8 pin_num, uint8 data)
{
	uint8 status;
	if(port_name >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS)
	{
		status = NOK;
	}

	else
	{
		switch(port_name){

		case PORTA_ID:
			if( GET_BIT(RCC_AHB1ENR, PORTA_ID) && ( GET_MODE_BITS(GPIOA_MODER, pin_num) == 1 ) )
			{
				if(data == 0)
				{
					CLEAR_BIT(GPIOA_ODR,pin_num);
				}
				else
				{
					SET_BIT(GPIOA_ODR,pin_num);
				}

				status = OK;
			}
			else
			{
				status = NOK;
			}
			break;
		case PORTB_ID:
			if( GET_BIT(RCC_AHB1ENR, PORTB_ID) && ( GET_MODE_BITS(GPIOB_MODER, pin_num) == 1 ) ){
				if(data == 0)
				{
					CLEAR_BIT(GPIOB_ODR,pin_num);
				}
				else
				{
					SET_BIT(GPIOB_ODR,pin_num);
				}

				status = OK;
			}
			else
			{
				status = NOK;
			}
			break;
		case PORTC_ID:
			if( GET_BIT(RCC_AHB1ENR, PORTC_ID) && ( GET_MODE_BITS(GPIOC_MODER, pin_num) == 1 ) ){
				if(data == 0)
				{
					CLEAR_BIT(GPIOC_ODR,pin_num);
				}
				else
				{
					SET_BIT(GPIOC_ODR,pin_num);
				}

				status = OK;
			}
			else
			{
				status = NOK;
			}
			break;
		case PORTD_ID:
			if( GET_BIT(RCC_AHB1ENR, PORTD_ID) && ( GET_MODE_BITS(GPIOD_MODER, pin_num) == 1 ) ){
				if(data == 0)
				{
					CLEAR_BIT(GPIOD_ODR,pin_num);
				}
				else
				{
					SET_BIT(GPIOD_ODR,pin_num);
				}

				status = OK;
			}
			else
			{
				status = NOK;
			}
			break;
		case PORTE_ID:
			if( GET_BIT(RCC_AHB1ENR, PORTE_ID) && ( GET_MODE_BITS(GPIOE_MODER, pin_num) == 1 ) ){
				if(data == 0)
				{
					CLEAR_BIT(GPIOE_ODR,pin_num);
				}
				else
				{
					SET_BIT(GPIOE_ODR,pin_num);
				}

				status = OK;
			}
			else
			{
				status = NOK;
			}
			break;
		}
	}

	return status;
}

uint8 GPIO_ReadPin(uint8 port_name, uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;

	if(port_name >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS)
	{
		// do nothing
	}

	else
	{
		switch(port_name)
		{
		case PORTA_ID:
			if(BIT_IS_SET(GPIOA_IDR,pin_num)){
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(GPIOB_IDR,pin_num)){
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(GPIOC_IDR,pin_num)){
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(GPIOD_IDR,pin_num)){
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTE_ID:
			if(BIT_IS_SET(GPIOE_IDR,pin_num)){
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		}
	}
	return pin_value;
}

