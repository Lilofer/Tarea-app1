CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

Tarea-app1: main.c src/lectorcsv.c src/metricas.c src/utilidades.c
	$(CC) $(CFLAGS) $^ -o Tarea-app1
clean:
	rm -f Tarea-app1
all: Tarea-app1