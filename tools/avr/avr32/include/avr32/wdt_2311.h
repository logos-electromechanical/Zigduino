/*****************************************************************************
 *
 * Copyright (C) 2009 Atmel Corporation
 * 
 * Model        : UC3B1512
 * Revision     : $Revision: 62294 $
 * Checkin Date : $Date: 2008-12-16 13:03:18 +0100 (ti., 16 des. 2008) $ 
 *
 ****************************************************************************/
#ifndef AVR32_WDT_2311_H_INCLUDED
#define AVR32_WDT_2311_H_INCLUDED

#include "avr32/abi.h"


/*
 Note to user:

 The following defines are always generated:
 - Register offset: AVR32_WDT_<register>
 - Bitfield mask:   AVR32_WDT_<register>_<bitfield>
 - Bitfield offset: AVR32_WDT_<register>_<bitfield>_OFFSET
 - Bitfield size:   AVR32_WDT_<register>_<bitfield>_SIZE
 - Bitfield values: AVR32_WDT_<register>_<bitfield>_<value name>

 The following defines are generated if they don't cause ambiguities,
 i.e. the name is unique, or all values with that name are the same.
 - Bitfield mask:   AVR32_WDT_<bitfield>
 - Bitfield offset: AVR32_WDT_<bitfield>_OFFSET
 - Bitfield size:   AVR32_WDT_<bitfield>_SIZE
 - Bitfield values: AVR32_WDT_<bitfield>_<value name>
 - Bitfield values: AVR32_WDT_<value name>

 All defines are sorted alphabetically.
*/


#define AVR32_WDT_CLR                                      0x00000004
#define AVR32_WDT_CLR_MASK                                 0x00000000
#define AVR32_WDT_CLR_RESETVALUE                           0x00000000
#define AVR32_WDT_CTRL                                     0x00000000
#define AVR32_WDT_CTRL_EN                                           0
#define AVR32_WDT_CTRL_EN_MASK                             0x00000001
#define AVR32_WDT_CTRL_EN_OFFSET                                    0
#define AVR32_WDT_CTRL_EN_SIZE                                      1
#define AVR32_WDT_CTRL_KEY                                         24
#define AVR32_WDT_CTRL_KEY_MASK                            0xff000000
#define AVR32_WDT_CTRL_KEY_OFFSET                                  24
#define AVR32_WDT_CTRL_KEY_SIZE                                     8
#define AVR32_WDT_CTRL_MASK                                0xff001f01
#define AVR32_WDT_CTRL_PSEL                                         8
#define AVR32_WDT_CTRL_PSEL_MASK                           0x00001f00
#define AVR32_WDT_CTRL_PSEL_OFFSET                                  8
#define AVR32_WDT_CTRL_PSEL_SIZE                                    5
#define AVR32_WDT_CTRL_RESETVALUE                          0x00000000
#define AVR32_WDT_EN                                                0
#define AVR32_WDT_EN_MASK                                  0x00000001
#define AVR32_WDT_EN_OFFSET                                         0
#define AVR32_WDT_EN_SIZE                                           1
#define AVR32_WDT_KEY                                              24
#define AVR32_WDT_KEY_MASK                                 0xff000000
#define AVR32_WDT_KEY_OFFSET                                       24
#define AVR32_WDT_KEY_SIZE                                          8
#define AVR32_WDT_PSEL                                              8
#define AVR32_WDT_PSEL_MASK                                0x00001f00
#define AVR32_WDT_PSEL_OFFSET                                       8
#define AVR32_WDT_PSEL_SIZE                                         5

#define AVR32_WDT_KEY_VALUE                            0x00000055



#ifdef __AVR32_ABI_COMPILER__


typedef struct avr32_wdt_ctrl_t {
    unsigned int key             : 8;
    unsigned int                 :11;
    unsigned int psel            : 5;
    unsigned int                 : 7;
    unsigned int en              : 1;
} avr32_wdt_ctrl_t;



typedef struct avr32_wdt_t {
  union {
          unsigned long                  ctrl      ;//0x0000
          avr32_wdt_ctrl_t               CTRL      ;
  };
          unsigned long                  clr       ;//0x0004
} avr32_wdt_t;



/*#ifdef __AVR32_ABI_COMPILER__*/
#endif

/*#ifdef AVR32_WDT_2311_H_INCLUDED*/
#endif

