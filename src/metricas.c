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
    
    while (fgets(line, MAX_LINE, file) && count < MAX_ORDERS) {
        Order *o = &orders[count];
        char *token = strtok(line, ",");
        for (int i = 0; i < 2; i++) token = strtok(NULL, ","); // Saltar pizza_id y order_id
        strcpy(o->pizza_name, strtok(NULL, ","));
        o->quantity = atoi(strtok(NULL, ","));
        strcpy(o->order_date, strtok(NULL, ","));
        strtok(NULL, ","); // Saltar order_time
        strtok(NULL, ","); // Saltar unit_price
        o->total_price = atof(strtok(NULL, ","));
        count++;
    }
    fclose(file);
    return count;
}

// Métricas
char* pizza_mas_vendida(int *size, Order orders[]) {
    static char best_pizza[100];
    int max_count = 0;
    for (int i = 0; i < *size; i++) {
        int count = 0;
        for (int j = 0; j < *size; j++) {
            if (strcmp(orders[i].pizza_name, orders[j].pizza_name) == 0) {
                count += orders[j].quantity;
            }
        }
        if (count > max_count) {
            max_count = count;
            strcpy(best_pizza, orders[i].pizza_name);
        }
    }
    return best_pizza;
}

char* pizza_menos_vendida(int *size, Order orders[]) {
    static char worst_pizza[100];
    int min_count = 100000;
    for (int i = 0; i < *size; i++) {
        int count = 0;
        for (int j = 0; j < *size; j++) {
            if (strcmp(orders[i].pizza_name, orders[j].pizza_name) == 0) {
                count += orders[j].quantity;
            }
        }
        if (count < min_count) {
            min_count = count;
            strcpy(worst_pizza, orders[i].pizza_name);
        }
    }
    return worst_pizza;
}

// Mapeo de métricas
typedef char* (*metric_func)(int *, Order *);
typedef struct {
    char *name;
    metric_func func;
} Metric;

Metric metrics[] = {
    {"pms", pizza_mas_vendida},
    {"pls", pizza_menos_vendida}
};

// Función principal
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s archivo.csv metrica1 metrica2 ...\n", argv[0]);
        return 1;
    }
    Order orders[MAX_ORDERS];
    int size = read_orders(argv[1], orders);
    
    for (int i = 2; i < argc; i++) {
        for (int j = 0; j < sizeof(metrics) / sizeof(Metric); j++) {
            if (strcmp(argv[i], metrics[j].name) == 0) {
                printf("%s: %s\n", argv[i], metrics[j].func(&size, orders));
                break;
            }
        }
    }
    return 0;
}
