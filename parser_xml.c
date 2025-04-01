#include "parser_xml.h"

#include <stdint.h>
#include <stdio.h>

typedef struct {
    char *key;
    int value;
} token_xml_t;

struct xml {
    token_xml_t *tokens;
    uint32_t n_tokens;
};

typedef struct {
    node_t *r_node;
    node_t *l_node;
    void *element;
} node_t;

typedef struct {
} tree_t;

char *dump_xml(const char *filename) {

    FILE *file_xml = fopen(filename, 'r');
    if (file_xml == NULL) return NULL;

    char *line;

    // fgets(line,,file_xml);

    fclose(file_xml);
}
