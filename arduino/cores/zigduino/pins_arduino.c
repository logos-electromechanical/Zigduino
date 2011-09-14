/*
  pins_arduino.c - pin definitions for the Arduino board
  Part of Arduino / Wiring Lite

  Copyright (c) 2005 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id$
*/

#include <avr/io.h>
#include "wiring_private.h"
#include "pins_arduino.h"

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.

// ATMEL ATMEGA8 & 168 / ARDUINO
//
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5)
//      (D 0) PD0  2|    |27  PC4 (AI 4)
//      (D 1) PD1  3|    |26  PC3 (AI 3)
//      (D 2) PD2  4|    |25  PC2 (AI 2)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1)
//      (D 4) PD4  6|    |23  PC0 (AI 0)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13)
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM
//      (D 7) PD7 13|    |16  PB2 (D 10) PWM
//      (D 8) PB0 14|    |15  PB1 (D 9) PWM
//                  +----+
//
// (PWM+ indicates the additional PWM pins on the ATmega168.)

// ATMEL ATMEGA1280 / ARDUINO
//
// 0-7 PE0-PE7   works
// 8-13 PB0-PB5  works
// 14-21 PA0-PA7 works 
// 22-29 PH0-PH7 works
// 30-35 PG5-PG0 works
// 36-43 PC7-PC0 works
// 44-51 PJ7-PJ0 works
// 52-59 PL7-PL0 works
// 60-67 PD7-PD0 works
// A0-A7 PF0-PF7
// A8-A15 PK0-PK7

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8
#define PJ 10
#define PK 11
#define PL 12

#define REPEAT8(x) x, x, x, x, x, x, x, x
#define BV0TO7 _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7)
#define BV7TO0 _BV(7), _BV(6), _BV(5), _BV(4), _BV(3), _BV(2), _BV(1), _BV(0)

const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t)&DDRB,
	NOT_A_PORT,
	(uint16_t)&DDRD,
	(uint16_t)&DDRE,
	(uint16_t)&DDRF,
	(uint16_t)&DDRG,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t)&PORTB,
	NOT_A_PORT,
	(uint16_t)&PORTD,
	(uint16_t)&PORTE,
	(uint16_t)&PORTF,
	(uint16_t)&PORTG,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	(uint16_t)&PINC,
	(uint16_t)&PIND,
	(uint16_t)&PINE,
	(uint16_t)&PINF,
	(uint16_t)&PING,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST		
	// -------------------------------------------		
	PE	, // PE 0 ** 0 ** USART0_RX	
	PE	, // PE 1 ** 1 ** USART0_TX	
	PE	, // PE 6 ** 2 ** D2
	PE	, // PE 5 ** 3 ** PWM3
	PE	, // PE 2 ** 4 ** PWM4
	PE	, // PE 3 ** 5 ** D5
	PE	, // PE 4 ** 6 ** PWM6
	PE	, // PE 7 ** 7 ** D7
	PB	, // PB 4 ** 8 ** PWM8
	PB	, // PB 7 ** 9 ** PWM9
	PB	, // PB 6 ** 10 ** PWM10
	PB	, // PB 5 ** 11 ** PWM11
	PB	, // PB 3 ** 12 ** SPI_MISO
	PB	, // PB 1 ** 13 ** SPI_SCK
	PF	, // PF 0 ** 14 ** A0	
	PF	, // PF 1 ** 15 ** A1	
	PF	, // PF 2 ** 16 ** A2	
	PF	, // PF 3 ** 17 ** A3	
	PF	, // PF 4 ** 18 ** A4	
	PF	, // PF 5 ** 19 ** A5
	PB	, // PB 2 ** 20 ** SPI_MOSI
	PD	, // PD 0 ** 21 ** I2C_SCL
	PD	, // PD 1 ** 22 ** I2C_SDA
	PD  , // PD 5 ** 23 ** RFTX
	PD  , // PD 6 ** 24 ** RFRX
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------		
	_BV( 0 )	, // PE 0 ** 0 ** USART0_RX	
	_BV( 1 )	, // PE 1 ** 1 ** USART0_TX	
	_BV( 6 )	, // PE 6 ** 2 ** D2
	_BV( 5 )	, // PE 5 ** 3 ** PWM3
	_BV( 2 )	, // PE 2 ** 4 ** PWM4
	_BV( 3 )	, // PE 3 ** 5 ** D5
	_BV( 4 )	, // PE 4 ** 6 ** PWM6
	_BV( 7 )	, // PE 7 ** 7 ** D7
	_BV( 4 )	, // PB 4 ** 8 ** PWM8
	_BV( 7 )	, // PB 7 ** 9 ** PWM9
	_BV( 6 )	, // PB 6 ** 10 ** PWM10
	_BV( 5 )	, // PB 5 ** 11 ** PWM11
	_BV( 3 )	, // PB 3 ** 12 ** SPI_MISO
	_BV( 1 )	, // PB 1 ** 13 ** SPI_SCK
	_BV( 0 )	, // PF 0 ** 14 ** A0	
	_BV( 1 )	, // PF 1 ** 15 ** A1	
	_BV( 2 )	, // PF 2 ** 16 ** A2	
	_BV( 3 )	, // PF 3 ** 17 ** A3	
	_BV( 4 )	, // PF 4 ** 18 ** A4	
	_BV( 5 )	, // PF 5 ** 19 ** A5
	_BV( 2 )	, // PB 2 ** 20 ** SPI_MOSI
	_BV( 0 )	, // PD 0 ** 21 ** I2C_SCL
	_BV( 1 )	, // PD 1 ** 22 ** I2C_SDA	
	_BV( 5 )  	, // PD 5 ** 23 ** RFTX
	_BV( 6 )  	, // PD 6 ** 24 ** RFRX
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		
	// -------------------------------------------	
	NOT_ON_TIMER	, // PE 0 ** 0 ** USART0_RX	
	NOT_ON_TIMER	, // PE 1 ** 1 ** USART0_TX	
	NOT_ON_TIMER	, // PE 2 ** 2 ** D2
	TIMER3C	, // PE 3 ** 3 ** PWM3
	NOT_ON_TIMER	, // PE 4 ** 4 ** D4
	TIMER3A	, // PE 6 ** 5 ** PWM5
	TIMER3B	, // PE 5 ** 6 ** PWM6
	NOT_ON_TIMER	, // PE 7 ** 7 ** D7
	TIMER2A	, // PB 4 ** 8 ** PWM8
	TIMER1C	, // PB 7 ** 9 ** PWM9
	TIMER1B	, // PB 6 ** 10 ** PWM10
	TIMER1A	, // PB 5 ** 11 ** PWM11
	NOT_ON_TIMER	, // PB 3 ** 12 ** SPI_MISO
	NOT_ON_TIMER	, // PB 1 ** 13 ** SPI_SCK
	NOT_ON_TIMER	, // PF 0 ** 14 ** A0	
	NOT_ON_TIMER	, // PF 1 ** 15 ** A1	
	NOT_ON_TIMER	, // PF 2 ** 16 ** A2	
	NOT_ON_TIMER	, // PF 3 ** 17 ** A3	
	NOT_ON_TIMER	, // PF 4 ** 18 ** A4	
	NOT_ON_TIMER	, // PF 5 ** 19 ** A5
	NOT_ON_TIMER	, // PB 2 ** 20 ** SPI_MOSI
	NOT_ON_TIMER	, // PD 0 ** 21 ** I2C_SCL
	NOT_ON_TIMER	, // PD 1 ** 22 ** I2C_SDA	
	NOT_ON_TIMER  	, // PD 5 ** 23 ** RFTX
	NOT_ON_TIMER  	, // PD 6 ** 24 ** RFRX
};
