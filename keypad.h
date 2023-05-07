/*===========================================================
 = Module: KEYPAD                                           =
 = File Name: keybad.h                                      =
 = Description: Header file for the keypad driver           =
 = Author: Saeed Elsayed                                    =
 ===========================================================*/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "gpio.h"

/*===========================================================
 =                       Definitions                        =
 ===========================================================*/

#define KEYPAD_COLS_PORT         PORTA_ID
#define KEYPAD_ROWS_PORT         PORTB_ID

#define COLS_START_PIN_ID        PIN3_ID
#define ROWS_START_PIN_ID        PIN4_ID

#define NUM_OF_COLS               4
#define NUM_OF_ROWS               4

#define KEYPAD_BUTTON_PRESSED    LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED   LOGIC_HIGH

/*===========================================================
 =                 Declaration of functions                 =
 ===========================================================*/

void KEYPAD_Init();
uint8 KEYPAD_getPressedKey();


#endif /* KEYPAD_H_ */
