CC = gcc
  CFLAGS = -Wall -Wextra -g

  app1: src/main.c src/lectorcsv.c src/metricas.c src/utilidades.c
      $(CC) $(CFLAGS) $^ -o app1

  clean:
      rm -f app1

  all: app1