#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargar_csv(const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombre_archivo);
        return;
    }

    char linea[1024];

    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }

    fclose(archivo);
}

int main() {
    const char *nombre_archivo = "C:\\Users\\lilof\\Desktop\\c program\\pizza_orders.csv" ;  // Nombre del archivo CSV

    cargar_csv(nombre_archivo);

    return 0;
}

