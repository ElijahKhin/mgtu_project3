#ifndef TASKS_H
#define TASKS_H

#include "../common/common.h"
#include "errors.h"
#include <iomanip>

#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define E 2.718281828459045
#define ALLOWED_ERROR 0.000001000000

typedef struct s_task3 {
  float x;
  double ref;
  double taylor;
  short last_n;
  struct s_task3 *next;
  struct s_task3 *prev;
} t_task3;

int task1(int n, int m);
double task2(double a);
void task3(t_task3 *&table);
double task4(double *&checkpoints, short i, short n);

#endif
