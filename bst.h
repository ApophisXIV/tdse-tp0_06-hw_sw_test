#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stdint.h>

#define BST_INSTANCES_LIMIT 5

struct bst;
typedef struct bst bst_t;

typedef int8_t (*cmp_fn_t)(void *element_1,void *element_2);

typedef void (*print_t)(void *element);

bst_t *get_bst_instance(cmp_fn_t fn);

bool bst_add(bst_t * bst, void *element);

void bst_remove(bst_t *bst, void *element);

void array(bst_t *bst, print_t);







#endif    // BST_H