#ifndef METRICS_H
#define METRICS_H

#include "orden.h"

typedef struct {
    char pizza_name[50];
    int quantity;
    struct PizzaFrequency *next;
} PizzaFrequency;

typedef struct {
    char date[20];
    float sales;
    int quantity;
    struct DateSales *next;
} DateSales;

void pms(PizzaOrder *orders, int order_count);
void pls(PizzaOrder *orders, int order_count);
void dms(PizzaOrder *orders, int order_count);
void dls(PizzaOrder *orders, int order_count);
void dmsp(PizzaOrder *orders, int order_count);
void dlsp(PizzaOrder *orders, int order_count);
void apo(PizzaOrder *orders, int order_count);
void apd(PizzaOrder *orders, int order_count);

#endif