#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LINE 1024
#define MAX_ORDERS 1000

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

void load_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE];
    fgets(line, MAX_LINE, file); // Saltar encabezado
    
    while (fgets(line, MAX_LINE, file) && order_count < MAX_ORDERS) {
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

// Función para encontrar la fecha con más ventas en términos de dinero
void dms() {
    char best_day[20];
    float max_sales = 0;
    for (int i = 0; i < order_count; i++) {
        if (orders[i].total_price > max_sales) {
            max_sales = orders[i].total_price;
            strcpy(best_day, orders[i].order_date);
        }
    }
    printf("Fecha con más ventas en dinero: %s con $%.2f\n", best_day, max_sales);
}




// Función para encontrar la fecha con menos ventas en términos de dinero
void dls() {
    char worst_day[20];
    float min_sales = INT_MAX;
    for (int i = 0; i < order_count; i++) {
        if (orders[i].total_price < min_sales) {
            min_sales = orders[i].total_price;
            strcpy(worst_day, orders[i].order_date);
        }
    }
    printf("Fecha con menos ventas en dinero: %s con $%.2f\n", worst_day, min_sales);
}

// Función para encontrar la fecha con más ventas en términos de cantidad de pizzas
void dmsp() {
    char best_day[20];
    int max_quantity = 0;
    for (int i = 0; i < order_count; i++) {
        if (orders[i].quantity > max_quantity) {
            max_quantity = orders[i].quantity;
            strcpy(best_day, orders[i].order_date);
        }
    }
    printf("Fecha con más ventas en cantidad de pizzas: %s con %d pizzas\n", best_day, max_quantity);
}

// Función para encontrar la fecha con menos ventas en términos de cantidad de pizzas
void dlsp() {
    char worst_day[20];
    int min_quantity = INT_MAX;
    for (int i = 0; i < order_count; i++) {
        if (orders[i].quantity < min_quantity) {
            min_quantity = orders[i].quantity;
            strcpy(worst_day, orders[i].order_date);
        }
    }
    printf("Fecha con menos ventas en cantidad de pizzas: %s con %d pizzas\n", worst_day, min_quantity);
}

// Función para calcular el promedio de pizzas por orden
void apo() {
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

// Función para calcular el promedio de pizzas por día
void apd() {
    if (order_count == 0) {
        printf("No hay órdenes para calcular el promedio.\n");
        return;
    }
    // Asumimos que cada orden es de un día diferente para simplificar
    float total_pizzas = 0;
    for (int i = 0; i < order_count; i++) {
        total_pizzas += orders[i].quantity;
    }
    printf("Promedio de pizzas por día: %.2f\n", total_pizzas / order_count);
}

void main (){
    char funcionEjecutable;
    printf("seleccione la funcion a ejecutar"); //no creo que sea asi
    scanf("%s", &funcionEjecutable);
}