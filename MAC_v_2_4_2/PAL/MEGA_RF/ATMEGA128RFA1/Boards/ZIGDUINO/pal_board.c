/**
 * @file pal_board.c
 *
 * @brief PAL board specific functionality
 *
 * This file implements PAL board specific functionality.
 *
 * $Id: pal_board.c 19641 2009-12-21 15:15:39Z sschneid $
 *
 * @author    Atmel Corporation: http://www.atmel.com
 * @author    Support email: avr@atmel.com
 */
/*
 * Copyright (c) 2009, Atmel Corporation All rights reserved.
 *
 * Licensed under Atmel's Limited License Agreement --> EULA.txt
 */

/* === Includes ============================================================ */

#include <stdbool.h>
#include <stdlib.h>
#include "pal.h"
#include "pal_boardtypes.h"
#include "pal_config.h"

#if (BOARD_TYPE == ZIGDUINO)

/* === Macros ============================================================== */


/* === Types =============================================================== */


/* === Globals ============================================================= */


/* === Prototypes ========================================================== */


/* === Implementation ====================================================== */

/**
 * @brief Calibrates the internal RC oscillator
 *
 * This function calibrates the internal RC oscillator, based
 * on the external 32.768 Hz crystal clock source.
 *
 * It will also set the seed for the random generator based as
 * a side effect of the calibration.
 *
 * @return True if calibration is successful, false otherwise.
 */
bool pal_calibrate_rc_osc(void)
{
    /* Nothing to be done. */
    return true;
}



/**
 * @brief Initialize LEDs
 */
void pal_led_init(void)
{
    LED_PORT |= (1 << LED_PIN_0);
    LED_PORT_DIR |= (1 << LED_PIN_0);
    LED_PORT |= (1 << LED_PIN_1);
    LED_PORT_DIR |= (1 << LED_PIN_1);
    LED_PORT |= (1 << LED_PIN_2);
    LED_PORT_DIR |= (1 << LED_PIN_2);
}



/**
 * @brief Control LED status
 *
 * @param[in]  led_no LED ID
 * @param[in]  led_setting LED_ON, LED_OFF, LED_TOGGLE
 */
void pal_led(led_id_t led_no, led_action_t led_setting)
{
    switch (led_no)
    {
    default:
    case 0:
        switch (led_setting)
        {
            case LED_ON:    LED_PORT &= ~(1 << LED_PIN_0); break;
            case LED_OFF:   LED_PORT |= (1 << LED_PIN_0); break;
            case LED_TOGGLE: LED_PORT ^= (1 << LED_PIN_0); break;
        }
        break;

    case 1:
        switch (led_setting)
        {
            case LED_ON:    LED_PORT &= ~(1 << LED_PIN_1); break;
            case LED_OFF:   LED_PORT |= (1 << LED_PIN_1); break;
            case LED_TOGGLE: LED_PORT ^= (1 << LED_PIN_1); break;
        }
        break;

    case 2:
        switch (led_setting)
        {
            case LED_ON:    LED_PORT &= ~(1 << LED_PIN_2); break;
            case LED_OFF:   LED_PORT |= (1 << LED_PIN_2); break;
            case LED_TOGGLE: LED_PORT ^= (1 << LED_PIN_2); break;
        }
        break;

    }
}


/**
 * @brief Initialize the button
 */
void pal_button_init(void)
{
    BUTTON_PORT |= (1 << BUTTON_PIN_0);
    BUTTON_PORT_DIR &= ~(1 << BUTTON_PIN_0);
}



/**
 * @brief Read button
 *
 * @param button_no Button ID
 */
button_state_t pal_button_read(button_id_t button_no)
{
    /* Keep compiler happy. */
    button_no = button_no;

    if ((BUTTON_INPUT_PINS & (1 << BUTTON_PIN_0)) == 0x00)
    {
        return BUTTON_PRESSED;
    }
    else
    {
        return BUTTON_OFF;
    }
}

#endif /* EK1 */

/* EOF */
