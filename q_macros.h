/**
 * @file    q_macros.h
 * @brief   Float-to-fixed and fixed-to-float conversion macros for 8, 16, 32 and 64 bit words.
 */

#ifndef SRC_Q_MACROS_H_
#define SRC_Q_MACROS_H_

#include "types.h"

#define SCALE_FACTOR_08(N) ( 1U   << (N) )                /* Scalefactor for any  8 bit Qn number representation. */
#define SCALE_FACTOR_16(N) ( 1U   << (N) )                /* Scalefactor for any 16 bit Qn number representation. */
#define SCALE_FACTOR_32(N) ( 1UL  << (N) )                /* Scalefactor for any 32 bit Qn number representation. */
#define SCALE_FACTOR_64(N) ( 1ULL << (N) )                /* Scalefactor for any 64 bit Qn number representation. */

// Fixed-point max-min limits
#define Q_MAXb08           ( (fix8_t )( SCALE_FACTOR_08( 8-1) - 1U ) )  /* Max  8 bit positive value in fixed-point domain. */
#define Q_MAXb16           ( (fix16_t)( SCALE_FACTOR_16(16-1) - 1U ) )  /* Max 16 bit positive value in fixed-point domain. */
#define Q_MAXb32           ( (fix32_t)( SCALE_FACTOR_32(32-1) - 1U ) )  /* Max 32 bit positive value in fixed-point domain. */
#define Q_MAXb64           ( (fix64_t)( SCALE_FACTOR_64(64-1) - 1U ) )  /* Max 64 bit positive value in fixed-point domain. */

#define Q_MINb08           ( (fix8_t )( SCALE_FACTOR_08( 8-1)      ) )  /* Min  8 bit negative value in fixed-point domain. */
#define Q_MINb16           ( (fix16_t)( SCALE_FACTOR_16(16-1)      ) )  /* Min 16 bit negative value in fixed-point domain. */
#define Q_MINb32           ( (fix32_t)( SCALE_FACTOR_32(32-1)      ) )  /* Min 32 bit negative value in fixed-point domain. */
#define Q_MINb64           ( (fix64_t)( SCALE_FACTOR_64(64-1)      ) )  /* Min 64 bit negative value in fixed-point domain. */

// Float max-min limits
#define F_MAXb08(N)        ( (float32_t)( 1U   << ( 8-1-(N)) ) )        /* Max  8 bit positive value as float. */
#define F_MAXb16(N)        ( (float32_t)( 1U   << (16-1-(N)) ) )        /* Max 16 bit positive value as float. */
#define F_MAXb32(N)        ( (float32_t)( 1UL  << (32-1-(N)) ) )        /* Max 32 bit positive value as float. */
#define F_MAXb64(N)        ( (float32_t)( 1ULL << (64-1-(N)) ) )        /* Max 64 bit positive value as float. */

#define F_MINb08(N)        ( -F_MAXb08(N) )                             /* Min  8 bit positive value as float. */
#define F_MINb16(N)        ( -F_MAXb16(N) )                             /* Min 16 bit positive value as float. */
#define F_MINb32(N)        ( -F_MAXb32(N) )                             /* Min 32 bit positive value as float. */
#define F_MINb64(N)        ( -F_MAXb64(N) )                             /* Min 64 bit positive value as float. */


/** @brief Converts from  float32 to  8-bit fixed-point with saturation. @note RARELY USE DIRECTLY. */
#define Qx_b08(N,x)        ( (float32_t)(x)>=F_MAXb08(N) ? Q_MAXb08 : ( (float32_t)(x)<F_MINb08(N) ? Q_MINb08 : (fix8_t )( (float32_t)(x)*(float32_t)SCALE_FACTOR_08(N) ) ) )
/** @brief Converts from  float32 to 16-bit fixed-point with saturation. @note RARELY USE DIRECTLY. */
#define Qx_b16(N,x)        ( (float32_t)(x)>=F_MAXb16(N) ? Q_MAXb16 : ( (float32_t)(x)<F_MINb16(N) ? Q_MINb16 : (fix16_t)( (float32_t)(x)*(float32_t)SCALE_FACTOR_16(N) ) ) )
/** @brief Converts from  float32 to 32-bit fixed-point with saturation. @note RARELY USE DIRECTLY. */
#define Qx_b32(N,x)        ( (float32_t)(x)>=F_MAXb32(N) ? Q_MAXb32 : ( (float32_t)(x)<F_MINb32(N) ? Q_MINb32 : (fix32_t)( (float32_t)(x)*(float32_t)SCALE_FACTOR_32(N) ) ) )
/** @brief Converts from  float32 to 64-bit fixed-point with saturation. @note RARELY USE DIRECTLY. */
#define Qx_b64(N,x)        ( (float32_t)(x)>=F_MAXb64(N) ? Q_MAXb64 : ( (float32_t)(x)<F_MINb64(N) ? Q_MINb64 : (fix64_t)( (float32_t)(x)*(float32_t)SCALE_FACTOR_64(N) ) ) )


// Use this!

// Float-to-fixed

// 8 bit (outputs 8 bit fixed point number)
#define Q7_b8(x)    Qx_b08(7,x) /**< Converts float to 8-bit Q7. */
#define Q6_b8(x)    Qx_b08(6,x) /**< Converts float to 8-bit Q6. */
#define Q5_b8(x)    Qx_b08(5,x)
#define Q4_b8(x)    Qx_b08(4,x)
#define Q3_b8(x)    Qx_b08(3,x)
#define Q2_b8(x)    Qx_b08(2,x)
#define Q1_b8(x)    Qx_b08(1,x)

// 16 bit (outputs 16 bit fixed point number)
#define Q15_b16(x)  Qx_b16(15,x) /**< Converts float to 16-bit Q15. */
#define Q14_b16(x)  Qx_b16(14,x) /**< Converts float to 16-bit Q14. */
#define Q13_b16(x)  Qx_b16(13,x)
#define Q12_b16(x)  Qx_b16(12,x)
#define Q11_b16(x)  Qx_b16(11,x)
#define Q10_b16(x)  Qx_b16(10,x)
#define Q9_b16(x)   Qx_b16( 9,x)
#define Q8_b16(x)   Qx_b16( 8,x)
#define Q7_b16(x)   Qx_b16( 7,x)
#define Q6_b16(x)   Qx_b16( 6,x)
#define Q5_b16(x)   Qx_b16( 5,x)
#define Q4_b16(x)   Qx_b16( 4,x)
#define Q3_b16(x)   Qx_b16( 3,x)
#define Q2_b16(x)   Qx_b16( 2,x)
#define Q1_b16(x)   Qx_b16( 1,x)

// 32 bit (outputs 32 bit fixed point number)
#define Q31_b32(x)  Qx_b32(31,x) /**< Converts float to 32-bit Q31. */
#define Q30_b32(x)  Qx_b32(30,x) /**< Converts float to 32-bit Q30. */
#define Q29_b32(x)  Qx_b32(29,x)
#define Q28_b32(x)  Qx_b32(28,x)
#define Q27_b32(x)  Qx_b32(27,x)
#define Q26_b32(x)  Qx_b32(26,x)
#define Q25_b32(x)  Qx_b32(25,x)
#define Q24_b32(x)  Qx_b32(24,x)
#define Q23_b32(x)  Qx_b32(23,x)
#define Q22_b32(x)  Qx_b32(22,x)
#define Q21_b32(x)  Qx_b32(21,x)
#define Q20_b32(x)  Qx_b32(20,x)
#define Q19_b32(x)  Qx_b32(19,x)
#define Q18_b32(x)  Qx_b32(18,x)
#define Q17_b32(x)  Qx_b32(17,x)
#define Q16_b32(x)  Qx_b32(16,x)
#define Q15_b32(x)  Qx_b32(15,x)
#define Q14_b32(x)  Qx_b32(14,x)
#define Q13_b32(x)  Qx_b32(13,x)
#define Q12_b32(x)  Qx_b32(12,x)
#define Q11_b32(x)  Qx_b32(11,x)
#define Q10_b32(x)  Qx_b32(10,x)
#define  Q9_b32(x)  Qx_b32( 9,x)
#define  Q8_b32(x)  Qx_b32( 8,x)
#define  Q7_b32(x)  Qx_b32( 7,x)
#define  Q6_b32(x)  Qx_b32( 6,x)
#define  Q5_b32(x)  Qx_b32( 5,x)
#define  Q4_b32(x)  Qx_b32( 4,x)
#define  Q3_b32(x)  Qx_b32( 3,x)
#define  Q2_b32(x)  Qx_b32( 2,x)
#define  Q1_b32(x)  Qx_b32( 1,x)
// end 32 bit.

// 64 bit (outputs 64 bit fixed point number)
#define Q63_b64(x)  Qx_b64(63,x) /**< Converts float to 64-bit Q63. */
#define Q62_b64(x)  Qx_b64(62,x) /**< Converts float to 64-bit Q62. */
#define Q61_b64(x)  Qx_b64(61,x)
#define Q60_b64(x)  Qx_b64(60,x)
#define Q59_b64(x)  Qx_b64(59,x)
#define Q58_b64(x)  Qx_b64(58,x)
#define Q57_b64(x)  Qx_b64(57,x)
#define Q56_b64(x)  Qx_b64(56,x)
#define Q55_b64(x)  Qx_b64(55,x)
#define Q54_b64(x)  Qx_b64(54,x)
#define Q53_b64(x)  Qx_b64(53,x)
#define Q52_b64(x)  Qx_b64(52,x)
#define Q51_b64(x)  Qx_b64(51,x)
#define Q50_b64(x)  Qx_b64(50,x)
#define Q49_b64(x)  Qx_b64(49,x)
#define Q48_b64(x)  Qx_b64(48,x)
#define Q47_b64(x)  Qx_b64(47,x)
#define Q46_b64(x)  Qx_b64(46,x)
#define Q45_b64(x)  Qx_b64(45,x)
#define Q44_b64(x)  Qx_b64(44,x)
#define Q43_b64(x)  Qx_b64(43,x)
#define Q42_b64(x)  Qx_b64(42,x)
#define Q41_b64(x)  Qx_b64(41,x)
#define Q40_b64(x)  Qx_b64(40,x)
#define Q39_b64(x)  Qx_b64(39,x)
#define Q38_b64(x)  Qx_b64(38,x)
#define Q37_b64(x)  Qx_b64(37,x)
#define Q36_b64(x)  Qx_b64(36,x)
#define Q35_b64(x)  Qx_b64(35,x)
#define Q34_b64(x)  Qx_b64(34,x)
#define Q33_b64(x)  Qx_b64(33,x)
#define Q32_b64(x)  Qx_b64(32,x)
#define Q31_b64(x)  Qx_b64(31,x)
#define Q30_b64(x)  Qx_b64(30,x)
#define Q29_b64(x)  Qx_b64(29,x)
#define Q28_b64(x)  Qx_b64(28,x)
#define Q27_b64(x)  Qx_b64(27,x)
#define Q26_b64(x)  Qx_b64(26,x)
#define Q25_b64(x)  Qx_b64(25,x)
#define Q24_b64(x)  Qx_b64(24,x)
#define Q23_b64(x)  Qx_b64(23,x)
#define Q22_b64(x)  Qx_b64(22,x)
#define Q21_b64(x)  Qx_b64(21,x)
#define Q20_b64(x)  Qx_b64(20,x)
#define Q19_b64(x)  Qx_b64(19,x)
#define Q18_b64(x)  Qx_b64(18,x)
#define Q17_b64(x)  Qx_b64(17,x)
#define Q16_b64(x)  Qx_b64(16,x)
#define Q15_b64(x)  Qx_b64(15,x)
#define Q14_b64(x)  Qx_b64(14,x)
#define Q13_b64(x)  Qx_b64(13,x)
#define Q12_b64(x)  Qx_b64(12,x)
#define Q11_b64(x)  Qx_b64(11,x)
#define Q10_b64(x)  Qx_b64(10,x)
#define Q9_b64(x)   Qx_b64(9,x)
#define Q8_b64(x)   Qx_b64(8,x)
#define Q7_b64(x)   Qx_b64(7,x)
#define Q6_b64(x)   Qx_b64(6,x)
#define Q5_b64(x)   Qx_b64(5,x)
#define Q4_b64(x)   Qx_b64(4,x)
#define Q3_b64(x)   Qx_b64(3,x)
#define Q2_b64(x)   Qx_b64(2,x)
#define Q1_b64(x)   Qx_b64(1,x)
// // end 64 bit.

// Aliases when using Qxy() only
#define Q63(x)  Qx_b64(63,x) /**< Converts float to 64-bit. */
#define Q62(x)  Qx_b64(62,x)
#define Q61(x)  Qx_b64(61,x)
#define Q60(x)  Qx_b64(60,x)
#define Q59(x)  Qx_b64(59,x)
#define Q58(x)  Qx_b64(58,x)
#define Q57(x)  Qx_b64(57,x)
#define Q56(x)  Qx_b64(56,x)
#define Q55(x)  Qx_b64(55,x)
#define Q54(x)  Qx_b64(54,x)
#define Q53(x)  Qx_b64(53,x)
#define Q52(x)  Qx_b64(52,x)
#define Q51(x)  Qx_b64(51,x)
#define Q50(x)  Qx_b64(50,x)
#define Q49(x)  Qx_b64(49,x)
#define Q48(x)  Qx_b64(48,x)
#define Q47(x)  Qx_b64(47,x)
#define Q46(x)  Qx_b64(46,x)
#define Q45(x)  Qx_b64(45,x)
#define Q44(x)  Qx_b64(44,x)
#define Q43(x)  Qx_b64(43,x)
#define Q42(x)  Qx_b64(42,x)
#define Q41(x)  Qx_b64(41,x)
#define Q40(x)  Qx_b64(40,x)
#define Q39(x)  Qx_b64(39,x)
#define Q38(x)  Qx_b64(38,x)
#define Q37(x)  Qx_b64(37,x)
#define Q36(x)  Qx_b64(36,x)
#define Q35(x)  Qx_b64(35,x)
#define Q34(x)  Qx_b64(34,x)
#define Q33(x)  Qx_b64(33,x)
#define Q32(x)  Qx_b64(32,x)
#define Q31(x)  Qx_b32(31,x) /**< Converts float to 32-bit. */
#define Q30(x)  Qx_b32(30,x)
#define Q29(x)  Qx_b32(29,x)
#define Q28(x)  Qx_b32(28,x)
#define Q27(x)  Qx_b32(27,x)
#define Q26(x)  Qx_b32(26,x)
#define Q25(x)  Qx_b32(25,x)
#define Q24(x)  Qx_b32(24,x)
#define Q23(x)  Qx_b32(23,x)
#define Q22(x)  Qx_b32(22,x)
#define Q21(x)  Qx_b32(21,x)
#define Q20(x)  Qx_b32(20,x)
#define Q19(x)  Qx_b32(19,x)
#define Q18(x)  Qx_b32(18,x)
#define Q17(x)  Qx_b32(17,x)
#define Q16(x)  Qx_b32(16,x)
#define Q15(x)  Qx_b16(15,x) /**< Converts float to 16-bit. */
#define Q14(x)  Qx_b16(14,x)
#define Q13(x)  Qx_b16(13,x)
#define Q12(x)  Qx_b16(12,x)
#define Q11(x)  Qx_b16(11,x)
#define Q10(x)  Qx_b16(10,x)
#define Q9(x)   Qx_b16( 9,x)
#define Q8(x)   Qx_b16( 8,x)
#define Q7(x)   Qx_b08( 7,x) /**< Converts float to 8-bit. */
#define Q6(x)   Qx_b08( 6,x)
#define Q5(x)   Qx_b08( 5,x)
#define Q4(x)   Qx_b08( 4,x)
#define Q3(x)   Qx_b08( 3,x)
#define Q2(x)   Qx_b08( 2,x)
#define Q1(x)   Qx_b08( 1,x)
// end 32 bit.


// Fixed to float

/** @brief Converts back from  8-bit fixed-point to floating-point. @note RARELY USE DIRECTLY. */
#define F_Qx_b08(N,x)  ( (float32_t)(x)/(float32_t)(SCALE_FACTOR_08(N)) )
/** @brief Converts back from 16-bit fixed-point to floating-point. @note RARELY USE DIRECTLY. */
#define F_Qx_b16(N,x)  ( (float32_t)(x)/(float32_t)(SCALE_FACTOR_16(N)) )
/** @brief Converts back from 32-bit fixed-point to floating-point. @note RARELY USE DIRECTLY. */
#define F_Qx_b32(N,x)  ( (float32_t)(x)/(float32_t)(SCALE_FACTOR_32(N)) )
/** @brief Converts back from 64-bit fixed-point to floating-point. @note RARELY USE DIRECTLY. */
#define F_Qx_b64(N,x)  ( (float32_t)(x)/(float32_t)(SCALE_FACTOR_64(N)) )

// 8-bit
#define  F_Q7b8(x)  F_Qx_b08( 7,x) /**< Converts from 8-bit Q7 to float. */
#define  F_Q6b8(x)  F_Qx_b08( 6,x) /**< Converts from 8-bit Q6 to float. */
#define  F_Q5b8(x)  F_Qx_b08( 5,x)
#define  F_Q4b8(x)  F_Qx_b08( 4,x)
#define  F_Q3b8(x)  F_Qx_b08( 3,x)
#define  F_Q2b8(x)  F_Qx_b08( 2,x)
#define  F_Q1b8(x)  F_Qx_b08( 1,x)

// 16-bit
#define F_Q15b16(x) F_Qx_b16(15,x) /**< Converts from 16-bit Q15 to float. */
#define F_Q14b16(x) F_Qx_b16(14,x) /**< Converts from 16-bit Q14 to float. */
#define F_Q13b16(x) F_Qx_b16(13,x)
#define F_Q12b16(x) F_Qx_b16(12,x)
#define F_Q11b16(x) F_Qx_b16(11,x)
#define F_Q10b16(x) F_Qx_b16(10,x)
#define  F_Q9b16(x) F_Qx_b16( 9,x)
#define  F_Q8b16(x) F_Qx_b16( 8,x)
#define  F_Q7b16(x) F_Qx_b16( 7,x)
#define  F_Q6b16(x) F_Qx_b16( 6,x)
#define  F_Q5b16(x) F_Qx_b16( 5,x)
#define  F_Q4b16(x) F_Qx_b16( 4,x)
#define  F_Q3b16(x) F_Qx_b16( 3,x)
#define  F_Q2b16(x) F_Qx_b16( 2,x)
#define  F_Q1b16(x) F_Qx_b16( 1,x)

// 32-bit
#define F_Q31b32(x) F_Qx_b32(31,x) /**< Converts from 32-bit Q31 to float. */
#define F_Q30b32(x) F_Qx_b32(30,x) /**< Converts from 32-bit Q30 to float. */
#define F_Q29b32(x) F_Qx_b32(29,x)
#define F_Q28b32(x) F_Qx_b32(28,x)
#define F_Q27b32(x) F_Qx_b32(27,x)
#define F_Q26b32(x) F_Qx_b32(26,x)
#define F_Q25b32(x) F_Qx_b32(25,x)
#define F_Q24b32(x) F_Qx_b32(24,x)
#define F_Q23b32(x) F_Qx_b32(23,x)
#define F_Q22b32(x) F_Qx_b32(22,x)
#define F_Q21b32(x) F_Qx_b32(21,x)
#define F_Q20b32(x) F_Qx_b32(20,x)
#define F_Q19b32(x) F_Qx_b32(19,x)
#define F_Q18b32(x) F_Qx_b32(18,x)
#define F_Q17b32(x) F_Qx_b32(17,x)
#define F_Q16b32(x) F_Qx_b32(16,x)
#define F_Q15b32(x) F_Qx_b32(15,x)
#define F_Q14b32(x) F_Qx_b32(14,x)
#define F_Q13b32(x) F_Qx_b32(13,x)
#define F_Q12b32(x) F_Qx_b32(12,x)
#define F_Q11b32(x) F_Qx_b32(11,x)
#define F_Q10b32(x) F_Qx_b32(10,x)
#define  F_Q9b32(x) F_Qx_b32( 9,x)
#define  F_Q8b32(x) F_Qx_b32( 8,x)
#define  F_Q7b32(x) F_Qx_b32( 7,x)
#define  F_Q6b32(x) F_Qx_b32( 6,x)
#define  F_Q5b32(x) F_Qx_b32( 5,x)
#define  F_Q4b32(x) F_Qx_b32( 4,x)
#define  F_Q3b32(x) F_Qx_b32( 3,x)
#define  F_Q2b32(x) F_Qx_b32( 2,x)
#define  F_Q1b32(x) F_Qx_b32( 1,x)

// 64-bit
#define F_Q63b64(x) F_Qx_b64(63,x) /**< Converts from 64-bit Q63 to float. */
#define F_Q62b64(x) F_Qx_b64(62,x) /**< Converts from 64-bit Q62 to float. */
#define F_Q61b64(x) F_Qx_b64(61,x)
#define F_Q60b64(x) F_Qx_b64(60,x)
#define F_Q59b64(x) F_Qx_b64(59,x)
#define F_Q58b64(x) F_Qx_b64(58,x)
#define F_Q57b64(x) F_Qx_b64(57,x)
#define F_Q56b64(x) F_Qx_b64(56,x)
#define F_Q55b64(x) F_Qx_b64(55,x)
#define F_Q54b64(x) F_Qx_b64(54,x)
#define F_Q53b64(x) F_Qx_b64(53,x)
#define F_Q52b64(x) F_Qx_b64(52,x)
#define F_Q51b64(x) F_Qx_b64(51,x)
#define F_Q50b64(x) F_Qx_b64(50,x)
#define F_Q49b64(x) F_Qx_b64(49,x)
#define F_Q48b64(x) F_Qx_b64(48,x)
#define F_Q47b64(x) F_Qx_b64(47,x)
#define F_Q46b64(x) F_Qx_b64(46,x)
#define F_Q45b64(x) F_Qx_b64(45,x)
#define F_Q44b64(x) F_Qx_b64(44,x)
#define F_Q43b64(x) F_Qx_b64(43,x)
#define F_Q42b64(x) F_Qx_b64(42,x)
#define F_Q41b64(x) F_Qx_b64(41,x)
#define F_Q40b64(x) F_Qx_b64(40,x)
#define F_Q39b64(x) F_Qx_b64(39,x)
#define F_Q38b64(x) F_Qx_b64(38,x)
#define F_Q37b64(x) F_Qx_b64(37,x)
#define F_Q36b64(x) F_Qx_b64(36,x)
#define F_Q35b64(x) F_Qx_b64(35,x)
#define F_Q34b64(x) F_Qx_b64(34,x)
#define F_Q33b64(x) F_Qx_b64(33,x)
#define F_Q32b64(x) F_Qx_b64(32,x)
#define F_Q31b64(x) F_Qx_b64(31,x)
#define F_Q30b64(x) F_Qx_b64(30,x)
#define F_Q29b64(x) F_Qx_b64(29,x)
// add more when needed.
//... end 64-bit.
#endif /* SRC_Q_MACROS_H_ */
