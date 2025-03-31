#include "queue.h"
#include <string.h>

/* -------------------------------------------------------------------------- */
// Representation ivariant
/* -------------------------------------------------------------------------- */
// - 0 <= size <= QUEUE_MAX_SIZE
// - size represent the logical size of the queue in terms of her elements
// - If size == 0 -> The queue is empty and each element is NULL
// - is_instance_in_use flag is true for any valid queue
// - If tail_index == head_index the queue is full
/* -------------------------------------------------------------------------- */

struct queue {
    bool is_instance_in_use;
    uint8_t size;
    void *elements[QUEUE_MAX_SIZE];
    uint8_t tail_index, head_index;
};

static queue_t queue_arr[QUEUE_INSTANCE_LIMIT];

/**
 * @brief  Retrieve the first queue instance avaliable
 * @note   O(n) complexity
 * @retval NULL if no instance is avaliable, otherwise the avaliable instance
 */
static queue_t *get_first_instance_avaliable() {

    for (uint8_t i = 0; i < QUEUE_INSTANCE_LIMIT; i++)
        if (!queue_arr[i].is_instance_in_use)
            return &queue_arr[i];
    return NULL;
}

queue_t *get_queue_instance() {

    queue_t *new_queue = get_first_instance_avaliable();
    if (new_queue == NULL) return NULL;

    new_queue->is_instance_in_use = true;

    new_queue->size = 0;

    new_queue->tail_index = 0;
    new_queue->head_index = 0;

    // Initialize all elements pointers to NULL
    memset(new_queue->elements, 0, QUEUE_MAX_SIZE * sizeof(new_queue->elements[0]));

    return new_queue;
}

uint8_t size(queue_t *queue_instance) {
    return queue_instance->size;
}

bool is_empty(queue_t *queue_instance) {
    return queue_instance->size == 0;
}

bool is_full(queue_t *queue_instance) {
    return queue_instance->size == QUEUE_MAX_SIZE;
}

bool enqueue(queue_t *queue_instance, void *element) {

    if (is_full(queue_instance)) return false;

    queue_instance->elements[queue_instance->tail_index] = element;

    queue_instance->tail_index = (queue_instance->tail_index + 1) % QUEUE_MAX_SIZE;

    queue_instance->size++;

    return true;
}

bool dequeue(queue_t *queue_instance, void **element) {

    if (is_empty(queue_instance)) return false;

    if (element != NULL)
        *element = queue_instance->elements[queue_instance->head_index];

    queue_instance->elements[queue_instance->head_index] = NULL;

    queue_instance->head_index = (queue_instance->head_index + 1) % QUEUE_MAX_SIZE;

    queue_instance->size--;

    return true;
}

void *peek(queue_t *queue_instance) {
    return queue_instance->elements[queue_instance->head_index];
}

void print(queue_t *queue_instance, void (*print_fn)(void *)) {
    for (uint8_t i = 0; i < queue_instance->size; i++) {
        print_fn(queue_instance->elements[(queue_instance->head_index + i) % QUEUE_MAX_SIZE]);
    }
}

void free_queue(queue_t *queue_instance, void (*free_element_fn)(void *)) {

    void *element;
    while (queue_instance->size != 0) {
        dequeue(queue_instance, &element);
        if (free_element_fn != NULL) free_element_fn(element);
    }

    queue_instance->is_instance_in_use = false;
}
