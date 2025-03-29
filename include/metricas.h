#ifndef METRICS_H
  #define METRICS_H

  #include "orden.h"

  char* pms(int size, orden* orders);
  char* pls(int size, orden* orders);
  char* dms(int size, orden* orders);
  char* dls(int size, orden* orders);
  char* dmsp(int size, orden* orders);
  char* dlsp(int size, orden* orders);
  float apo(int size, orden* orders);
  float apd(int size, orden* orders);
  char* ims(int size, orden* orders);
  char* hp(int size, orden* orders);

  typedef char* (*metrica_func)(int size, orden* orders);

  #endif