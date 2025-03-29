#ifndef CSV_PARSER_H
  #define CSV_PARSER_H

  #include "orden.h"

  orden* parse_csv(const char* filename, int* size);
  void ordenes_listado(orden* ordenes, int size);

  #endif