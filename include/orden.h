#ifndef ORDEN_H
#define ORDEN_H

typedef struct {
    int pizza_id;
    int orden_id;
    char pizza_nombre_id[50];
    int cantidad;
    char orden_dato[11];
    char orden_tiempo[9];
    float precio_unidad;
    float precio_total;
    char tamaño_pizza[2];
    char categoria_pizza[50];
    char ingredientes_pizza[200];
    char nombre_pizza[100];
} orden;

#endif