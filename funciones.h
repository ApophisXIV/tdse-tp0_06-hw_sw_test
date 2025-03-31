/**
 * @file funciones.h
 * @author Guido Rodriguez (guerodriguez@fi.uba.ar)
 * @brief 
 * @version 0.1
 * @date 2025-03-28
 * 
 * @copyright Copyright (c) 2025. All rights reserved.
 * 
 * Licensed under the MIT License, see LICENSE for details.
 * SPDX-License-Identifier: MIT
 * 
 */

#include <stdint.h>

/**
 * @brief Clear the desired bit
 * @param  *number: Number to modify
 * @param  n_bit: Bit position from zero to n
 * @retval None
 */
void clear_n_bit(int *number, uint8_t n_bit);

/**
 * @brief Set the desired bit
 * @param  *number: Number to modify
 * @param  n_bit: Bit position from zero to n
 * @retval None
 */
void set_n_bit(int *number, uint8_t n_bit);

/**
 * @brief  Print the binary representation of a byte
 * @param  byte: Byte to print
 * @retval None
 */
void print_byte(uint8_t byte);

