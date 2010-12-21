/**
 * @file pal_config.h
 *
 * @brief PAL configuration for ATmega128RFA1
 *
 * This header file contains configuration parameters for ATmega128RFA1.
 *
 * $Id: pal_config.h 19923 2010-01-14 11:00:19Z sschneid $
 *
 * @author    Atmel Corporation: http://www.atmel.com
 * @author    Support email: avr@atmel.com
 */
/*
 * Copyright (c) 2009, Atmel Corporation All rights reserved.
 *
 * Licensed under Atmel's Limited License Agreement --> EULA.txt
 */

/* Prevent double inclusion */
#ifndef PAL_CONFIG_H
#define PAL_CONFIG_H

/* === Includes =============================================================*/

#include "pal_boardtypes.h"

#if (BOARD_TYPE == ZIGDUINO)

/*
 * This header file is required since a function with
 * return type retval_t is declared
 */
#include "return_val.h"

/* === Types ================================================================*/

/* Enumerations used to idenfify LEDs */
typedef enum led_id_tag
{
    LED_0,
    LED_1,
    LED_2
} led_id_t;

#define NO_OF_LEDS                      (3)


/* Enumerations used to idenfify buttons */
typedef enum button_id_tag
{
    BUTTON_0
} button_id_t;

#define NO_OF_BUTTONS                   (1)

/* === Externals ============================================================*/


/* === Macros ===============================================================*/

/*
 * The default CPU clock
 *
 * The board must be configured for 16 MHz clock, which can be fused
 * for either the 16 MHz internal RC oscillator, or for the 16 MHz
 * crystal oscillator that is required for the transceiver operation.
 */
#define F_CPU                           (16000000UL)


/*
 * Wait for 65 ns.
 * time t7: SLP_TR time (see data sheet or SWPM).
 * In case the system clock is slower than 32 MHz we do not need
 * to have this value filled.
 */
#define PAL_WAIT_65_NS()                // empty


/*
 * PORT where LEDs are connected
 */
#define LED_PORT                        (PORTD)
#define LED_PORT_DIR                    (DDRD)

/*
 * PINs where LEDs are connected
 */
#define LED_PIN_0                       (PB1)
#define LED_PIN_1                       (PD5)
#define LED_PIN_2                       (PD6)

/*
 * PORT where button is connected
 */
#define BUTTON_PORT                     (PORTE)
#define BUTTON_PORT_DIR                 (DDRE)
#define BUTTON_INPUT_PINS               (PINE)

/*
 * PINs where buttons are connected
 */
#define BUTTON_PIN_0                    (PE0)

/*
 * UART0 and UART1 non-generic (board specific) initialization part.
 */
#define UART_0_INIT_NON_GENERIC()       // Empty macro
#define UART_1_INIT_NON_GENERIC()       // Empty macro


/*
 * This board does NOT have an external eeprom available.
 */
#ifndef EXTERN_EEPROM_AVAILABLE
#define EXTERN_EEPROM_AVAILABLE            (0)
#endif

/*
 * Alert initialization
 */
#define ALERT_INIT()                    do {    \
        LED_PORT = 0;                           \
        LED_PORT_DIR = 0xFF;                    \
} while (0)

/*
 * Alert indication
 * One loop cycle below is about 6 clock cycles (or more, depending
 * on optimization settings), so it takes 2...3 loop iterations per
 * microsecond.  60000 cycles thus results in 20...30 ms of delay,
 * so the LEDs should be seen as flickering.
 */
#define ALERT_INDICATE()                do {    \
        LED_PORT ^= 0xFF;                       \
} while (0)


/* === Prototypes ===========================================================*/
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
} /* extern "C" */
#endif


/*
 * MCU pins used for debugging
 */
#define TST_PIN_0_HIGH()
#define TST_PIN_0_LOW()
#define TST_PIN_1_HIGH()
#define TST_PIN_1_LOW()
#define TST_PIN_2_HIGH()
#define TST_PIN_2_LOW()
#define TST_PIN_3_HIGH()
#define TST_PIN_3_LOW()
#define TST_PIN_4_HIGH()
#define TST_PIN_4_LOW()
#define TST_PIN_5_HIGH()
#define TST_PIN_5_LOW()
#define TST_PIN_6_HIGH()
#define TST_PIN_6_LOW()
#define TST_PIN_7_HIGH()
#define TST_PIN_7_LOW()
#define TST_PIN_8_HIGH()
#define TST_PIN_8_LOW()

#endif /* EK1 */

#endif  /* PAL_CONFIG_H */
/* EOF */
