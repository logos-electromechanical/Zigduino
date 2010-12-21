/**
 * @file pal_boardtypes.h
 *
 * @brief PAL board types for ATmega128RFA1
 *
 * This header file contains board types based on ATmega128RFA1.
 *
 * $Id: pal_boardtypes.h 19640 2009-12-21 15:14:49Z sschneid $
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
#ifndef PAL_BOARDTYPES_H
#define PAL_BOARDTYPES_H

/* Atmel internal */
#define EMURFA1                 (0x01)

/* Atmel internal */
#define EVALRFA1                (0x02)

/*
 * Plain Radio Controller board RCB V6.3 with ATmega128RFA1
 */
#define RCB_6_3_PLAIN           (0x03)

/*
 * STK541 USB Adapter board with Radio Controller board RCB V6.3 with ATmega128RFA1
 */
#define RCB_6_3_STK541          (0x04)

/*
 * Radio Controller board RCB V6.3 connected to Key Remote Controller Board
 */
#define RCB_6_3_KEY_RC          (0x05)

/*
 * RCB Breakout Board with Radio Controller board RCB 6.3
 * http://www.dresden-elektronik.de/shop/prod85.html
 *
 * RCB Breakout Board Light with Radio Controller board RCB 6.3
 * http://www.dresden-elektronik.de/shop/prod84.html
 */
#define RCB_6_3_BREAKOUT_BOARD  (0x06)

/*
 * Sensor Terminal board with Radio Controller board RCB 6.3
 * http://www.dresden-elektronik.de/shop/prod75.html
 */
#define RCB_6_3_SENS_TERM_BOARD (0x07)

/*
 * ATmega128RFA1-EK1 Evaluation Kit
 * http://www.atmel.com/dyn/products/tools_card_mcu.asp?tool_id=4677
 */
#define EK1                     (0x11)

/*
 * Zigduino
 * http://www.logos-electro.com/zigduino
 */
 
#define ZIGDUINO                (0xa1)

#endif  /* PAL_BOARDTYPES_H */
/* EOF */
