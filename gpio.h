/*
 * GPIO.h
 *
 *  Created on: Apr 17, 2023
 *      Author: EGYPT
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "std_types.h"

#define OK                         1
#define NOK                        0

#define STATE_OUTPUT_PUSH_PULL     0
#define STATE_OUTPUT_OPEN_DRAIN    1

#define STATE_INPUT_NO_PULL        0
#define STATE_INPUT_PULL_UP        1
#define STATE_INPUT_PULL_DOWN      2

#define NUM_OF_PORTS               5
#define NUM_OF_PINS                15

#define PORTA_ID                   0
#define PORTB_ID                   1
#define PORTC_ID                   2
#define PORTD_ID                   3
#define PORTE_ID                   4

#define PIN0_ID                    0
#define PIN1_ID                    1
#define PIN2_ID                    2
#define PIN3_ID                    3
#define PIN4_ID                    4
#define PIN5_ID                    5
#define PIN6_ID                    6
#define PIN7_ID                    7
#define PIN8_ID                    8
#define PIN9_ID                    9
#define PIN10_ID                   10
#define PIN11_ID                   11
#define PIN12_ID                   12
#define PIN13_ID                   13
#define PIN14_ID                   14

#define GPIOA_PUPDR   (*(unsigned long*) (0x40020000+0x0C))
#define RCC_AHB1ENR   (*(unsigned long*) (0x40023800+0x30))
#define RCC_RC        (*(unsigned long*) (0x40023800))
#define GPIOA_ODR     (*(unsigned long*) (0x40020000+0x14))
#define GPIOA_MODER   (*(unsigned long*) (0x40020000))
#define GPIOA_IDR     (*(unsigned long*) (0x40020000+0x10))
#define GPIOA_OTYPER  (*(unsigned long*) (0x40020000+0x04))

#define GPIOB_PUPDR   (*(unsigned long*) (0x40020400+0x0C))
#define RCC_AHB1ENR   (*(unsigned long*) (0x40023800+0x30))
#define RCC_RC        (*(unsigned long*) (0x40023800))
#define GPIOB_ODR     (*(unsigned long*) (0x40020400+0x14))
#define GPIOB_MODER   (*(unsigned long*) (0x40020400))
#define GPIOB_IDR     (*(unsigned long*) (0x40020400+0x10))
#define GPIOB_OTYPER  (*(unsigned long*) (0x40020400+0x04))

#define GPIOC_PUPDR   (*(unsigned long*) (0x40020800+0x0C))
#define RCC_AHB1ENR   (*(unsigned long*) (0x40023800+0x30))
#define RCC_RC        (*(unsigned long*) (0x40023800))
#define GPIOC_ODR     (*(unsigned long*) (0x40020800+0x14))
#define GPIOC_MODER   (*(unsigned long*) (0x40020800))
#define GPIOC_IDR     (*(unsigned long*) (0x40020800+0x10))
#define GPIOC_OTYPER  (*(unsigned long*) (0x40020800+0x04))

#define GPIOD_PUPDR   (*(unsigned long*) (0x40020C00+0x0C))
#define RCC_AHB1ENR   (*(unsigned long*) (0x40023800+0x30))
#define RCC_RC        (*(unsigned long*) (0x40023800))
#define GPIOD_ODR     (*(unsigned long*) (0x40020C00+0x14))
#define GPIOD_MODER   (*(unsigned long*) (0x40020C00))
#define GPIOD_IDR     (*(unsigned long*) (0x40020C00+0x10))
#define GPIOD_OTYPER  (*(unsigned long*) (0x40020C00+0x04))

#define GPIOE_PUPDR   (*(unsigned long*) (0x40021000+0x0C))
#define RCC_AHB1ENR   (*(unsigned long*) (0x40023800+0x30))
#define RCC_RC        (*(unsigned long*) (0x40023800))
#define GPIOE_ODR     (*(unsigned long*) (0x40021000+0x14))
#define GPIOE_MODER   (*(unsigned long*) (0x40021000))
#define GPIOE_IDR     (*(unsigned long*) (0x40021000+0x10))
#define GPIOE_OTYPER  (*(unsigned long*) (0x40021000+0x04))


typedef enum{
	PIN_INPUT, PIN_OUTPUT, PIN_ALTERNATIVE, PIN_ANALOGE
}GPIO_PinModeType;

void GPIO_ConfigPin(uint8 port_name, uint8 pin_num, GPIO_PinModeType mode, uint8 state);

uint8 GPIO_WritePin(uint8 port_name, uint8 pin_num, uint8 data);

uint8 GPIO_ReadPin(uint8 port_name, uint8 pin_num);


#endif /* GPIO_H_ */
