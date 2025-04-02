#include "../include/metricas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>




PizzaFrequency *pizza_frequencies[100];
DateSales *date_sales[100];


void initialize_pizza_frequencies() {
    for (int i = 0; i < 100; i++) pizza_frequencies[i] = NULL;
}

void initialize_date_sales() {
    for (int i = 0; i < 100; i++) date_sales[i] = NULL;
}

int hash_pizza_name(char *pizza_name) {
    int hash = 0;
    for (int i = 0; pizza_name[i]; i++) hash = (hash * 31 + pizza_name[i]) % 100;
    return hash;
}

int hash_date(char *date) {
    int hash = 0;
    for (int i = 0; date[i]; i++) hash = (hash * 31 + date[i]) % 100;
    return hash;
}


void update_pizza_frequency(char *pizza_name, int quantity) {
    int index = hash_pizza_name(pizza_name);
    PizzaFrequency *curr = pizza_frequencies[index];
    while (curr) {
        if (strcmp(curr->pizza_name, pizza_name) == 0) {
            curr->quantity += quantity;
            return;
        }
        curr = curr->next;
    }
    PizzaFrequency *new_node = (PizzaFrequency *)malloc(sizeof(PizzaFrequency));
    strcpy(new_node->pizza_name, pizza_name);
    new_node->quantity = quantity;
    new_node->next = pizza_frequencies[index];
    pizza_frequencies[index] = new_node;
}

void update_date_sales(char *date, float sales, int quantity) {
    int index = hash_date(date);
    DateSales *curr = date_sales[index];
    while (curr) {
        if (strcmp(curr->date, date) == 0) {
            curr->sales += sales;
            curr->quantity += quantity;
            return;
        }
        curr = curr->next;
    }
    DateSales *new_node = (DateSales *)malloc(sizeof(DateSales));
    strcpy(new_node->date, date);
    new_node->sales = sales;
    new_node->quantity = quantity;
    new_node->next = date_sales[index];
    date_sales[index] = new_node;
}

void pms(PizzaOrder *orders, int order_count) {
    initialize_pizza_frequencies();
    for (int i = 0; i < order_count; i++) {
        update_pizza_frequency(orders[i].pizza_name, orders[i].quantity);
    }
    char best_seller[50] = "";
    int max_quantity = 0;
    for (int i = 0; i < 100; i++) {
        PizzaFrequency *curr = pizza_frequencies[i];
        while (curr) {
            if (curr->quantity > max_quantity) {
                max_quantity = curr->quantity;
                strcpy(best_seller, curr->pizza_name);
            }
            curr = curr->next;
        }
    }
    printf("Pizza más vendida: %s con %d unidades\n", best_seller, max_quantity);
    for (int i = 0; i < 100; i++) {
        PizzaFrequency *curr = pizza_frequencies[i];
        while (curr) {
            PizzaFrequency *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

void pls(PizzaOrder *orders, int order_count) {
    initialize_pizza_frequencies();
    for (int i = 0; i < order_count; i++) {
        update_pizza_frequency(orders[i].pizza_name, orders[i].quantity);
    }
    char worst_seller[50] = "";
    int min_quantity = INT_MAX;
    for (int i = 0; i < 100; i++) {
        PizzaFrequency *curr = pizza_frequencies[i];
        while (curr) {
            if (curr->quantity < min_quantity) {
                min_quantity = curr->quantity;
                strcpy(worst_seller, curr->pizza_name);
            }
            curr = curr->next;
        }
    }
    printf("Pizza menos vendida: %s con %d unidades\n", worst_seller, min_quantity);
    for (int i = 0; i < 100; i++) {
        PizzaFrequency *curr = pizza_frequencies[i];
        while (curr) {
            PizzaFrequency *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

void dms(PizzaOrder *orders, int order_count) {
    initialize_date_sales();
    for (int i = 0; i < order_count; i++) {
        update_date_sales(orders[i].order_date, orders[i].total_price, orders[i].quantity);
    }
    char best_date[20] = "";
    float max_sales = 0;
    for (int i = 0; i < 100; i++) {
        DateSales *curr = date_sales[i];
        while (curr) {
            if (curr->sales > max_sales) {
                max_sales = curr->sales;
                strcpy(best_date, curr->date);
            }
            curr = curr->next;
        }
    }
    printf("Fecha con más ventas en dinero: %s con $%.2f\n", best_date, max_sales);
    for (int i = 0; i < 100; i++) {
        DateSales *curr = date_sales[i];
        while (curr) {
            DateSales *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

void dls(PizzaOrder *orders, int order_count) {
    initialize_date_sales();
    for (int i = 0; i < order_count; i++) {
        update_date_sales(orders[i].order_date, orders[i].total_price, orders[i].quantity);
    }
    char worst_date[20] = "";
    float min_sales = INT_MAX;
    for (int i = 0; i < 100; i++) {
        DateSales *curr = date_sales[i];
        while (curr) {
            if (curr->sales < min_sales) {
                min_sales = curr->sales;
                strcpy(worst_date, curr->date);
            }
            curr = curr->next;
        }
    }
    printf("Fecha con menos ventas en dinero: %s con $%.2f\n", worst_date, min_sales);
    for (int i = 0; i < 100; i++) {
        DateSales *curr = date_sales[i];
        while (curr) {
            DateSales *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

void dmsp(PizzaOrder *orders, int order_count) {
    initialize_date_sales();
    for (int i = 0; i < order_count; i++) {
        update_date_sales(orders[i].order_date, 0, orders[i].quantity);
    }
    char best_date[20] = "";
    int max_quantity = 0;
    for (int i = 0; i < 100; i++) {
        DateSales *curr = date_sales[i];
        while (curr) {
            if (curr->quantity > max_quantity) {
                max_quantity = curr->quantity;
                strcpy(best_date, curr->date);
            }
            curr = curr->next;
        }
    }
    printf("Fecha con más ventas en cantidad de pizzas: %s con %d pizzas\n", best_date, max_quantity);
    for (int i = 0; i < 100; i++) {
        DateSales *curr = date_sales[i];
        while (curr) {
            DateSales *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

void dlsp(PizzaOrder *orders, int order_count) {
    initialize_date_sales();
    for (int i = 0; i < order_count; i++) {
        update_date_sales(orders[i].order_date, 0, orders[i].quantity);
    }
    char worst_date[20] = "";
    int min_quantity = INT_MAX;
    for (int i = 0; i < 100; i++) {
        DateSales *curr = date_sales[i];
        while (curr) {
            if (curr->quantity < min_quantity) {
                min_quantity = curr->quantity;
                strcpy(worst_date, curr->date);
            }
            curr = curr->next;
        }
    }
    printf("Fecha con menos ventas en cantidad de pizzas: %s con %d pizzas\n", worst_date, min_quantity);
    for (int i = 0; i < 100; i++) {
        DateSales *curr = date_sales[i];
        while (curr) {
            DateSales *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

void apo(PizzaOrder *orders, int order_count) {
    if (order_count == 0) {
        printf("No hay órdenes para calcular el promedio.\n");
        return;
    }
    float total_pizzas = 0;
    for (int i = 0; i < order_count; i++) {
        total_pizzas += orders[i].quantity;
    }
    printf("Promedio de pizzas por orden: %.2f\n", total_pizzas / order_count);
}

void apd(PizzaOrder *orders, int order_count) {
    if (order_count == 0) {
        printf("No hay órdenes para calcular el promedio.\n");
        return;
    }
    initialize_date_sales();
    for (int i = 0; i < order_count; i++) {
        update_date_sales(orders[i].order_date, 0, orders[i].quantity);
    }
    int total_days = 0;
    float total_pizzas = 0;
    for (int i = 0; i < 100; i++) {
        DateSales *curr = date_sales[i];
        if (curr) total_days++;
        while (curr) {
            total_pizzas += curr->quantity;
            curr = curr->next;
        }
    }
    printf("Promedio de pizzas por día: %.2f\n", total_pizzas / total_days);
    for (int i = 0; i < 100; i++) {
        DateSales *curr = date_sales[i];
        while (curr) {
            DateSales *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}