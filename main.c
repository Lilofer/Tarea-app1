#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lectorcsv.h"
#include "../include/metricas.h"
#include "../include/utilidades.h"

#define MAX_ORDERS 1000

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No se ingresaron argumentos.\n");
        return 1;
    }

    char *archivoCSV = argv[1];
    PizzaOrder orders[MAX_ORDERS];
    int order_count = load_csv(archivoCSV, orders, MAX_ORDERS);

    if (order_count == -1) return 1;

    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "pms") == 0) pms(orders, order_count);
            else if (strcmp(argv[i], "pls") == 0) pls(orders, order_count);
            else if (strcmp(argv[i], "dms") == 0) dms(orders, order_count);
            else if (strcmp(argv[i], "dls") == 0) dls(orders, order_count);
            else if (strcmp(argv[i], "dmsp") == 0) dmsp(orders, order_count);
            else if (strcmp(argv[i], "dlsp") == 0) dlsp(orders, order_count);
            else if (strcmp(argv[i], "apo") == 0) apo(orders, order_count);
            else if (strcmp(argv[i], "apd") == 0) apd(orders, order_count);
            else printf("Función desconocida: %s\n", argv[i]);
        }
    }
    return 0;
}