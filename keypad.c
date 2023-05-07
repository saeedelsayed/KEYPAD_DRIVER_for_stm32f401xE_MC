/*===========================================================
 = Module: KEYPAD                                           =
 = File Name: keybad.c                                      =
 = Description: Source file for the keypad driver           =
 = Author: Saeed Elsayed                                    =
 ===========================================================*/

#include "keypad.h"


#if (NUM_OF_COLS == 3)
uint8 KEYPAD_Buttons[4][3] = {
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9},
			   {'*',0,'#'},
							 };
#elif (NUM_OF_COLS == 4)
uint8 KEYPAD_Buttons[4][4] = {
				{7, 8, 9, '/'},
				{4, 5, 6, '*'},
				{1, 2, 3, '-'},
			   {13 ,0,'=', '+'},
			 // 13: ASCII code for enter
							 };
#endif

void KEYPAD_Init()
{
	for(uint8 col = 0; col < NUM_OF_COLS; col++)
	{
		GPIO_ConfigPin(KEYPAD_COLS_PORT, COLS_START_PIN_ID + col, PIN_INPUT, STATE_INPUT_PULL_UP);
	}
	for(uint8 row = 0; row < NUM_OF_ROWS; row++)
	{
		GPIO_ConfigPin(KEYPAD_ROWS_PORT, ROWS_START_PIN_ID + row, PIN_OUTPUT, STATE_OUTPUT_PUSH_PULL);
	}
}

uint8 KEYPAD_getPressedKey()
{
	GPIO_WritePin(KEYPAD_ROWS_PORT, ROWS_START_PIN_ID, LOGIC_HIGH);
	GPIO_WritePin(KEYPAD_ROWS_PORT, ROWS_START_PIN_ID + 1, LOGIC_HIGH);
	GPIO_WritePin(KEYPAD_ROWS_PORT, ROWS_START_PIN_ID + 2, LOGIC_HIGH);
	GPIO_WritePin(KEYPAD_ROWS_PORT, ROWS_START_PIN_ID + 3, LOGIC_HIGH);

	while(1)
	{
		for(uint8 row = 0; row < NUM_OF_ROWS; row++)
		{
			GPIO_WritePin(KEYPAD_ROWS_PORT, ROWS_START_PIN_ID + row, LOGIC_LOW);

			for(uint8 col = 0; col < NUM_OF_COLS; col++)
			{
				if( GPIO_ReadPin(KEYPAD_COLS_PORT, COLS_START_PIN_ID + col) == KEYPAD_BUTTON_PRESSED )
				{
					for(uint8 i = 0; i < 30; i++);
					if( GPIO_ReadPin(KEYPAD_COLS_PORT, COLS_START_PIN_ID + col) == KEYPAD_BUTTON_PRESSED )
					{
							return KEYPAD_Buttons[row][col];
					}

				}

			}
			GPIO_WritePin(KEYPAD_ROWS_PORT, ROWS_START_PIN_ID + row, LOGIC_HIGH);
		}

	}
}

