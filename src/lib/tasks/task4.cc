#include "tasks.h"

double task4(double *&checkpoints, short i, short n) {
  if (i == n)
    return 1;
  checkpoints[i] = 1.0 / (2 * (i + 1) + task4(checkpoints, i + 1, n));
  return checkpoints[i];
}
