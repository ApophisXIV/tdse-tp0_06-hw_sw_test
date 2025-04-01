#ifndef PARSER_XML_H
#define PARSER_XML_H

#include <stdbool.h>

struct xml;
typedef struct xml xml_t;

bool dump_xml(const char *filename);

#endif    // PARSER_XML_H