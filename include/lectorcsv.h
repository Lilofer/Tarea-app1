#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include "orden.h"

int load_csv(const char *filename, PizzaOrder *orders, int max_orders);

#endif