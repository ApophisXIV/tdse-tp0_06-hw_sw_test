/**
 * @file queue.h
 * @author Guido Rodriguez (guerodriguez@fi.uba.ar)
 * @brief Queue data structure
 * @version 0.1
 * @date 2025-03-29
 *
 * @copyright Copyright (c) 2025. All rights reserved.
 *
 * Licensed under the MIT License, see LICENSE for details.
 * SPDX-License-Identifier: MIT
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdint.h>

#define QUEUE_INSTANCE_LIMIT 10
#define QUEUE_MAX_SIZE       10

struct queue;
typedef struct queue queue_t;

/**
 * @brief  Get a queue instance
 * @note   QUEUE_INSTANCE_LIMIT instances are available
 * @retval Pointer to the queue instance, or NULL if no instance is available
 */
queue_t *get_queue_instance();

/**
 * @brief  Check if the queue is empty
 * @param  *queue_instance: Queue instance
 * @retval True if the queue is empty, false otherwise
 */
bool is_empty(queue_t *queue_instance);

/**
 * @brief  Check if the queue is full
 * @param  *queue_instance: Queue instance
 * @retval True if the queue is full, false otherwise
 */
bool is_full(queue_t *queue_instance);

/**
 * @brief  Add an element to the queue
 * @param  *queue_instance: Queue instance
 * @param  *element: Pointer to the element to enqueue
 * @retval True if the element was added successfully, false if the queue is full
 */
bool enqueue(queue_t *queue_instance, void *element);

/**
 * @brief  Remove an element from the queue
 * @param  *queue_instance: Queue instance
 * @param  **element: Pointer to store the dequeued element
 * @retval True if the element was removed successfully, false if the queue is empty
 */
bool dequeue(queue_t *queue_instance, void **element);

/**
 * @brief  Get the front element of the queue without removing it
 * @param  *queue_instance: Queue instance
 * @retval Pointer to the front element of the queue
 */
void *peek(queue_t *queue_instance);

/**
 * @brief  Print the queue elements using a custom print function
 * @param  *queue_instance: Queue instance
 * @param  *print_fn: Function to print an element
 */
void print(queue_t *queue_instance, void (*print_fn)(void *));

/**
 * @brief  Free the queue and its elements using a custom free function
 * @param  *queue_instance: Queue instance
 * @param  *free_element_fn: Function to free an element
 */
void free_queue(queue_t *queue_instance, void (*free_element_fn)(void *));

#endif    // QUEUE_H