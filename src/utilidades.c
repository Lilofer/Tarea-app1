#include "../include/utilidades.h"
#include <string.h>

int compare_dates(const char *date1, const char *date2) {
    // Implementación mínima para comparar dos fechas.
    // Usar date1 y date2 para realizar la comparación.
    // Retornar un valor que indique el resultado de la comparación.
    return strcmp(date1, date2); //Compara strings, retorna 0 si son iguales, negativo si date1<date2 y positivo si date1>date2
}

void trim_string(char *str) {
    // Implementación mínima para eliminar espacios en blanco al inicio y final de una cadena.
    // Usar str para modificar la cadena original.
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    // Encuentra el primer carácter no blanco.
    while (str[start] == ' ') {
        start++;
    }

    // Encuentra el último carácter no blanco.
    while (end > start && str[end] == ' ') {
        end--;
    }

    // Mueve los caracteres no blancos al inicio de la cadena.
    for (int i = start; i <= end; i++) {
        str[i - start] = str[i];
    }

    // Agrega el terminador nulo al final de la cadena.
    str[end - start + 1] = '\0';
}