#include "bst.h"
#include <stddef.h>
#include <stdint.h>

typedef struct node_bst node_bst_t;
struct node_bst {
    void *element;
    node_bst_t *node_left;
    node_bst_t *node_right;
};

struct bst{
    bool is_instance_in_use;
    uint32_t size;
    cmp_fn_t cmp_fn;
    node_bst_t *root;
};

static bst_t bst_instances[BST_INSTANCES_LIMIT] = {0};

static bst_t *get_first_instance_avaliable() {
    for (uint8_t i = 0; i < BST_INSTANCES_LIMIT; i++)
        if (!bst_instances[i].is_instance_in_use)
            return &bst_instances[i];
    return NULL;
}

bst_t *get_bst_instance(cmp_fn_t fn) {
    bst_t *new_bst = get_first_instance_avaliable();
    if (new_bst == NULL) return NULL;

    new_bst->is_instance_in_use = true;

    new_bst->size   = 0;
    new_bst->root   = NULL;
    new_bst->cmp_fn = fn;

    return new_bst;
}

node_bst_t *bst_add_node_handler(node_bst_t *root, void *element, bst_t *bst) {
    if (root == NULL) {
        node_bst_t *new_node;
        new_node->element    = element;
        new_node->node_left  = NULL;
        new_node->node_right = NULL;
        bst->size++;
        return new_node;
    }

    if (bst->cmp_fn(element, root->element) <= 0)
        root->node_left = bst_add_node_handler(root->node_left, element, bst);
    else
        root->node_right = bst_add_node_handler(root->node_right, element, bst);

    return root;
}

bool bst_add(bst_t *bst, void *element) {
    if (bst == NULL || bst->cmp_fn == NULL) return false;

    bst->root = bst_add_node_handler(bst->root, element, bst);

    return true;
}




