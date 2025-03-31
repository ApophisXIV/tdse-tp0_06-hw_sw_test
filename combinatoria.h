/**
 * @file combinatoria.h
 * @author Guido Rodriguez (guerodriguez@fi.uba.ar)
 * @brief
 * @version 0.1
 * @date 2025-03-29
 *
 * @copyright Copyright (c) 2025. All rights reserved.
 *
 * Licensed under the MIT License, see LICENSE for details.
 * SPDX-License-Identifier: MIT
 *
 */

/**
 * @brief  Calculate the diferents forms of ordenate a group
 * @note   Recursive implementation
 * @param  n: The integer whose factorial is to be computed (n!)
 * @retval n!
 */
unsigned long factorial(const unsigned int n);

/**
 * @brief  Calculate the binomial coefficient C(n, k)
 * @note   Represents the number of ways to choose k elements from a set of n elements with order
 * @param  n: Total number of elements
 * @param  k: Number of elements to select
 * @retval n! / (k! * (n-k)!)
 */
unsigned long binomial_coefficient(const unsigned int n, const unsigned int k);

/**
 * @brief  Calculate the number of permutations P(n, k)
 * @note   Represents the number of ways to arrange k elements selected from a set of n elements without order
 * @param  n: Total number of elements
 * @param  k: Number of elements to arrange
 * @retval n! / (n-k)!
 */
unsigned long permutations(const unsigned int n, const unsigned int k);