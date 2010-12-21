#ifndef __ASM_AVR32_SYSREGS_H
#define __ASM_AVR32_SYSREGS_H

#define SYSREG_SR	  0
#define SYSREG_EVBA	  4
#define SYSREG_ACBA	  8
#define SYSREG_CPUCR	 12
#define SYSREG_ECR       16
#define SYSREG_RSR_SUP	 20
#define SYSREG_RSR_INT0	 24
#define SYSREG_RSR_INT1	 28
#define SYSREG_RSR_INT2	 32
#define SYSREG_RSR_INT3	 36
#define SYSREG_RSR_EX	 40
#define SYSREG_RSR_NMI	 44
#define SYSREG_RSR_DBG	 48
#define SYSREG_RAR_SUP	 52
#define SYSREG_RAR_INT0	 56
#define SYSREG_RAR_INT1	 60
#define SYSREG_RAR_INT2	 64
#define SYSREG_RAR_INT3	 68
#define SYSREG_RAR_EX	 72
#define SYSREG_RAR_NMI	 76
#define SYSREG_RAR_DBG	 80
#define SYSREG_JECR       84
#define SYSREG_JOSP       88
#define SYSREG_JAVA_LV0   92
#define SYSREG_JAVA_LV1   96
#define SYSREG_JAVA_LV2   100
#define SYSREG_JAVA_LV3   104
#define SYSREG_JAVA_LV4   108
#define SYSREG_JAVA_LV5   112
#define SYSREG_JAVA_LV6   116
#define SYSREG_JAVA_LV7   120
#define SYSREG_JTBA       124
#define SYSREG_JBCR       128

#define SYSREG_CONFIG0	256
#define SYSREG_CONFIG1	260
#define SYSREG_COUNT	264
#define SYSREG_COMPARE	268

#define SYSREG_BEAR 316

/* MMU interface registers */
#define SYSREG_TLBEHI	272
#define SYSREG_TLBELO	276
#define SYSREG_PTBR	280
#define SYSREG_TLBEAR	284
#define SYSREG_MMUCR	288
#define SYSREG_TLBARLO	292
#define SYSREG_TLBDRLO	296
#define SYSREG_TLBARHI	300
#define SYSREG_TLBDRHI	304

/* Performance counter */
#define SYSREG_PCCR	320

 // Status register bits
#define SR_C_OFFSET    0
#define SR_Z_OFFSET    1
#define SR_N_OFFSET    2
#define SR_V_OFFSET    3
#define SR_Q_OFFSET    4
#define SR_T_OFFSET    14
#define SR_R_OFFSET    15
#define SR_GM_OFFSET   16
#define SR_I0M_OFFSET  17
#define SR_I1M_OFFSET  18
#define SR_I2M_OFFSET  19
#define SR_I3M_OFFSET  20
#define SR_EM_OFFSET   21
#define SR_M0_OFFSET   22
#define SR_M1_OFFSET   23
#define SR_M2_OFFSET   24
#define SR_D_OFFSET    26
#define SR_DM_OFFSET   27
#define SR_J_OFFSET    28

#define SR_C    (1 << 0)
#define SR_Z    (1 << 1)
#define SR_N    (1 << 2)
#define SR_V    (1 << 3)
#define SR_Q    (1 << 4)
#define SR_T    (1 << 14)
#define SR_R    (1 << 15)
#define SR_GM   (1 << 16)
#define SR_I0M  (1 << 17)
#define SR_I1M  (1 << 18)
#define SR_I2M  (1 << 19)
#define SR_I3M  (1 << 20)
#define SR_EM   (1 << 21)
#define SR_M0   (1 << 22)
#define SR_M1   (1 << 23)
#define SR_M2   (1 << 24)
#define SR_D    (1 << 26)
#define SR_DM   (1 << 27)
#define SR_J    (1 << 28)

//PCCR bits
#define PCCRS  (1<<3)
#define PCCRC  (1<<2)
#define PCCRR  (1<<1)
#define PCCRE  (1<<0)
#define PCCNT_PRESCALE 64

//TLBEHI bits
#define TLBEHIVPN  (1<<10)
#define TLBEHIV  (1<<9)
#define TLBEHII  (1<<0)
 
//TLBELO = bits
#define TLBELOPFN  (1<<10)
#define TLBELOC  (1<<9)
#define TLBELOG  (1<<8)
#define TLBELOB  (1<<7)
#define TLBELOAP  (1<<5)
#define TLBELOSZ  (1<<2)
#define TLBELOD  (1<<1)
#define TLBELOW  (1<<0)
 
//MMUCR bits
#define MMUIRP  (1<<26)
#define MMUILA  (1<<20)
#define MMUDRP  (1<<14)
#define MMUDLA  (1<<8)
#define MMUS  (1<<4)
#define MMUN  (1<<3)
#define MMUI  (1<<2)
#define MMUM  (1<<1)
#define MMUE  (1<<0)
 
// Relative offsets to EVBA
#define H_UNREC_EX  0x000
#define H_TLB_MH    0x004
#define H_BUS_ERR_D 0x008
#define H_BUS_ERR_I 0x00C
#define H_NMI       0x010
#define H_INST_ADDR 0x014
#define H_ITLB_MISS 0x050
#define H_ITLB_PROT 0x018
#define H_DEBUG     0x01C
#define H_ILL_OPC   0x020
#define H_UNIMPL_INST 0x024
#define H_PRIV_VIOL 0x028
#define H_FLOAT_PT  0x02C
#define H_COPROC_ABS 0x030
#define H_SCALL  0x100
#define H_DATA_ADDR_R  0x034
#define H_DATA_ADDR_W  0x038
#define H_DTLB_MISS_R  0x060
#define H_DTLB_MISS_W  0x070
#define H_DTLB_PROT_R  0x03C
#define H_DTLB_PROT_W  0x040
#define H_DTLB_MOD  0x044


#endif /* __ASM_AVR32_SYSREGS_H */
