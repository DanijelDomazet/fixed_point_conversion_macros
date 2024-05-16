/**
 * @file    q_debug.h
 * @brief   Macros used for printing out fixed-point variable values
 *          during debugging.
 *
 *          Prints any Q format, words 8, 16, 32, and 64 bit.
 *          Prints arrays.
 *
 * @note    Use only when debugging.
 */

#ifndef SRC_Q_DEBUG_H_
#define SRC_Q_DEBUG_H_


#include "q_macros.h"
#include <stdio.h>

/**
 * @brief Prints fixed-point value as float.
 *        First conversion is done via F_Qx_b macro, then the values is printed
 *        out.
 *        @note RARELY USE DIRECTLY.
 * */
#define PRINT_Q(MAXSIZE, N, name)                                             \
    {                                                                         \
        float32_t grbmqpxtk = F_Qx_b##MAXSIZE(N,name);                        \
        printf("Q" #N "\t- " );                                               \
        printf("%-48s", #name);                                               \
        printf(": %27.21f  \n", grbmqpxtk);                                   \
    }

/**
 * @brief Prints fixed-point value of array element, together with array index.
 *        @note RARELY USE DIRECTLY.
 * */
#define PRINT_ARRAY_ELEMENT_Q(MAXSIZE, N, name, index)                         \
    {                                                                          \
        float32_t grbmqpxtk = F_Q##N##b##MAXSIZE(name[index]);                 \
        printf("Q" #N " - " );                                                 \
        printf("%s[%2d]", #name, index);                                       \
        printf(": %+.21f \n", grbmqpxtk);                                      \
    }

/**
 * @brief Prints fixed-point array, together with array index, from start to
 *        stop possition.
 *        @note RARELY USE DIRECTLY.
 * */
#define PRINT_ARRAY_Q(MAXSIZE, N, name, start, stop)                           \
    {                                                                          \
        for(int index=start;index<=stop;index++)                               \
        {                                                                      \
            PRINT_ARRAY_ELEMENT_Q(MAXSIZE, N, name, index);                    \
        }                                                                      \
        printf("...\n");                                                       \
    }


// Print variables

// 16-bit
#define PRINT_Q7_8b(name)   PRINT_Q(08, 7, name)  /**< @brief Prints single 8-bit Q7 fixed-point variable as float. */
#define PRINT_Q6_8b(name)   PRINT_Q(08, 6, name)  /**< @brief Prints single 8-bit Q6 fixed-point variable as float. */

// 16-bit
#define PRINT_Q15_16b(name) PRINT_Q(16, 15, name) /**< @brief Prints single 16-bit Q15 fixed-point variable as float. */
#define PRINT_Q14_16b(name) PRINT_Q(16, 14, name) /**< @brief Prints single 16-bit Q14 fixed-point variable as float. */

// 32-bit
#define PRINT_Q31_32b(name) PRINT_Q(32, 31, name) /**< @brief Prints single 32-bit Q31 fixed-point variable as float. */
#define PRINT_Q30_32b(name) PRINT_Q(32, 30, name) /**< @brief Prints single 32-bit Q30 fixed-point variable as float. */

// 64-bit
#define PRINT_Q63_64b(name) PRINT_Q(64, 63, name) /**< @brief Prints single 64-bit Q63 fixed-point variable as float. */
#define PRINT_Q62_64b(name) PRINT_Q(64, 62, name) /**< @brief Prints single 64-bit Q62 fixed-point variable as float. */


// PRINTING ARRAYS:

// 8 bit arrays
#define PRINT_ARRAY_Q7_8b(name, start, stop)    PRINT_ARRAY_Q(8, 7, name, start, stop)   /**< @brief Prints array of 8-bit Q7 fixed-point variables as floats. */
#define PRINT_ARRAY_Q6_8b(name, start, stop)    PRINT_ARRAY_Q(8, 6, name, start, stop)   /**< @brief Prints array of 8-bit Q6 fixed-point variables as floats. */

// 16 bit arrays
#define PRINT_ARRAY_Q15_16b(name, start, stop)  PRINT_ARRAY_Q(16, 15, name, start, stop) /**< @brief Prints array of 16-bit Q15 fixed-point variables as floats. */
#define PRINT_ARRAY_Q14_16b(name, start, stop)  PRINT_ARRAY_Q(16, 14, name, start, stop) /**< @brief Prints array of 16-bit Q14 fixed-point variables as floats. */

// 32-bit arrays
#define PRINT_ARRAY_Q31_32b(name, start, stop)  PRINT_ARRAY_Q(32, 31, name, start, stop) /**< @brief Prints array of 32-bit Q31 fixed-point variables as floats. */
#define PRINT_ARRAY_Q30_32b(name, start, stop)  PRINT_ARRAY_Q(32, 30, name, start, stop) /**< @brief Prints array of 32-bit Q30 fixed-point variables as floats. */

// 64 bit arrays
#define PRINT_ARRAY_Q63_64b(name, start, stop)  PRINT_ARRAY_Q(64, 63, name, start, stop) /**< @brief Prints array of 64-bit Q63 fixed-point variables as floats. */
#define PRINT_ARRAY_Q62_64b(name, start, stop)  PRINT_ARRAY_Q(64, 62, name, start, stop) /**< @brief Prints array of 64-bit Q62 fixed-point variables as floats. */


#endif /* SRC_Q_DEBUG_H_ */
