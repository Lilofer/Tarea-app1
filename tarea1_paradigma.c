//Empezare por hacer las funciones basicas, no se donde esta el .CSV que tenemos que usar tho
//Recuerden que hay que entregar un .exe C al correr el codigo genera el .exe por si solo 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LINE 1024 //maximo de 1024 cracateres por fila
#define MAX_ORDERS 1000 //maximo 1000 filas 

// Estructura para almacenar cada pedido de pizza
typedef struct {
    char pizza_id[20];
    char order_id[20];
    char pizza_name_id[50];
    int quantity;
    char order_date[20];
    char order_time[20];
    float unit_price;
    float total_price;
    char pizza_size[5];
    char pizza_category[20];
    char pizza_ingredients[200];
    char pizza_name[50];
} PizzaOrder;

PizzaOrder orders[MAX_ORDERS];
int order_count = 0;

// Función para cargar datos desde el CSV
void load_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return;
    }
    char line[MAX_LINE];
    fgets(line, MAX_LINE, file); // Saltar encabezado
    
    while (fgets(line, MAX_LINE, file) && order_count < MAX_ORDERS) {
        orders[order_count].pizza_id, orders[order_count].order_id, orders[order_count].pizza_name_id,
        &orders[order_count].quantity, orders[order_count].order_date, orders[order_count].order_time,
        sscanf(line,"%[^,],%[^,],%[^,],%d,%[^,],%[^,],%f,%f,%[^,],%[^,],\"%[^\"]\",%[^,]",
               &orders[order_count].unit_price, &orders[order_count].total_price,
               orders[order_count].pizza_size, orders[order_count].pizza_category,
               orders[order_count].pizza_ingredients, orders[order_count].pizza_name);
        order_count++;
    }
    fclose(file);
}

// Función para encontrar la pizza más vendida
void pms() {
    char best_seller[50];
    int max_quantity = 0;
    for (int i = 0; i < order_count; i++) {
        if (orders[i].quantity > max_quantity) {
            max_quantity = orders[i].quantity;
            strcpy(best_seller, orders[i].pizza_name);
        }
    }
    printf("Pizza más vendida: %s con %d unidades\n", best_seller, max_quantity);
}

// Función para encontrar la pizza menos vendida
void pls() {
    char worst_seller[50];
    int min_quantity = INT_MAX;
    for (int i = 0; i < order_count; i++) {
        if (orders[i].quantity < min_quantity) {
            min_quantity = orders[i].quantity;
            strcpy(worst_seller, orders[i].pizza_name);
        }
    }
    printf("Pizza menos vendida: %s con %d unidades\n", worst_seller, min_quantity);
}