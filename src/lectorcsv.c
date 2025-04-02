#include "../include/lectorcsv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int load_csv(const char *filename, PizzaOrder *orders, int max_orders) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return -1; 
    }

    char line[MAX_LINE];
    fgets(line, MAX_LINE, file); 

    int order_count = 0;
    while (fgets(line, MAX_LINE, file) && order_count < max_orders) {
        int result = sscanf(line, "%[^,],%[^,],%[^,],%d,%[^,],%[^,],%f,%f,%[^,],%[^,],\"%[^\"]\",%[^,]",
                            orders[order_count].pizza_id, orders[order_count].order_id, orders[order_count].pizza_name_id,
                            &orders[order_count].quantity, orders[order_count].order_date, orders[order_count].order_time,
                            &orders[order_count].unit_price, &orders[order_count].total_price,
                            orders[order_count].pizza_size, orders[order_count].pizza_category,
                            orders[order_count].pizza_ingredients, orders[order_count].pizza_name);

        if (result != 12) {
            printf("Error al leer la línea %d del CSV.\n", order_count + 1);
            continue;
        }

        order_count++;
    }

    fclose(file);
    return order_count;
}