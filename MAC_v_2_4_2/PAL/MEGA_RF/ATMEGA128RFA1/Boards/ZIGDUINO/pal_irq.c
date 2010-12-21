/**
 * @file pal_irq.c
 *
 * @brief PAL IRQ functionality
 *
 * This file contains functions to initialize, enable, disable and install
 * handler for the transceiver interrupts. It also contains functions to enable,
 * disable and get the status of global interrupt
 *
 * $Id: pal_irq.c 20082 2010-01-29 11:50:27Z sschneid $
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

#include <stdint.h>
#include "pal.h"
#include "pal_boardtypes.h"

#if (BOARD_TYPE == ZIGDUINO)

/* === Types =============================================================== */

/**
 * This is a typedef of the function which is called from the transceiver ISR
 */
typedef void (*irq_handler_t)(void);

/* === Globals ============================================================= */

/*
 * Function pointers to store the callback function of
 * the transceiver interrupt
 */
static irq_handler_t irq_handler[NO_OF_TRX_IRQS];

/* === Prototypes ========================================================== */

/* === Implementation ====================================================== */

/**
 * @brief Initializes the transceiver interrupts
 *
 * This function sets the microcontroller specific registers
 * responsible for handling the transceiver interrupts
 *
 * @param trx_irq_num Transceiver interrupt line to be initialized
 * @param trx_irq_cb Callback function for the given transceiver
 * interrupt
 */
void pal_trx_irq_init(trx_irq_hdlr_idx_t trx_irq_num, FUNC_PTR trx_irq_cb)
{
    if (trx_irq_num >= NO_OF_TRX_IRQS)
    {
        /* Illegal request. */
        return;
    }
    /*
     * Set the handler function.
     * The handler is set before enabling the interrupt to prepare for spurious
     * interrupts, that can pop up the moment they are enabled
     */
    irq_handler[trx_irq_num] = (irq_handler_t)trx_irq_cb;
    ENABLE_TRX_IRQ(trx_irq_num);
}


/**
 * @brief ISR for transceiver's PLL lock interrupt
 */
ISR(TRX24_PLL_LOCK_vect)
{
    irq_handler[RFA1_PLL_LOCK_IRQ_HDLR_IDX]();
}

/**
 * @brief ISR for transceiver's PLL unlock interrupt
 */
ISR(TRX24_PLL_UNLOCK_vect)
{
    irq_handler[RFA1_PLL_UNLOCK_IRQ_HDLR_IDX]();
}

/**
 * @brief ISR for transceiver's rx start interrupt
 *
 * By the time the SFD is detected, the hardware timestamps the
 * current frame in the SCTSR register.
 */
ISR(TRX24_RX_START_vect)
{
    irq_handler[RFA1_RX_START_IRQ_HDLR_IDX]();
}

/**
 * @brief ISR for transceiver's receive end interrupt
 */
ISR(TRX24_RX_END_vect)
{
    irq_handler[RFA1_RX_END_IRQ_HDLR_IDX]();
}

/**
 * @brief ISR for transceiver's CCA/ED measurement done interrupt
 */
ISR(TRX24_CCA_ED_DONE_vect)
{
    irq_handler[RFA1_CCA_ED_DONE_IRQ_HDLR_IDX]();
}

/**
 * @brief ISR for transceiver's transmit end interrupt
 */
ISR(TRX24_TX_END_vect)
{
    irq_handler[RFA1_TX_END_IRQ_HDLR_IDX]();
}

/**
 * @brief ISR for transceiver's address match interrupt
 */
ISR(TRX24_XAH_AMI_vect)
{
    irq_handler[RFA1_AMI_IRQ_HDLR_IDX]();
}

/**
 * @brief ISR for transceiver's battery low interrupt
 */
ISR(BAT_LOW_vect)
{
    irq_handler[RFA1_BAT_LOW_IRQ_HDLR_IDX]();
}

/**
 * @brief ISR for transceiver's Awake interrupt
 */
ISR(TRX24_AWAKE_vect)
{
    irq_handler[RFA1_AWAKE_IRQ_HDLR_IDX]();
}

/**
 * @brief ISR for transceiver's AES interrupt
 */
ISR(AES_READY_vect)
{
    irq_handler[RFA1_AES_READY_IRQ_HDLR_IDX]();
}

#endif /* EK1 */

/* EOF */
