#include "tasks.h"

inline static void SetUpList(t_task3 *&table) {
  t_task3 *tmp;

  table->next = new t_task3;
  tmp = table;
  table = table->next;
  table->prev = tmp;
}

inline static double ReferenceFormula(float x) {
  return (1 + 2.0 * x * x) * std::pow(E, x * x);
}

inline static bool IsAllowedError(double error) {
  //	std::cout << std::setprecision(7) << std::fixed << "error: " << error <<
  //" | AE:" << ALLOWED_ERROR << std::endl;
  if (-ALLOWED_ERROR <= error && error <= ALLOWED_ERROR)
    return true;
  return false;
}

inline static double SeriaMember(short n, float x) {
  return (2.0 * n + 1) / sw_factorial(n) * std::pow(x, 2 * n);
}

static void TaylorSeria(t_task3 *&table) {
  table->last_n = 0;
  while (table->last_n < 13 && !IsAllowedError(table->ref - table->taylor))
    table->taylor += SeriaMember(table->last_n++, table->x);
}

void task3(t_task3 *&table) {
  table->prev = NULL;
  table->x = 0;
  for (int i = 0; i < 6; i++) {
    //		std::cout << "current i: " << i << " and x: " << table->x <<
    // std::endl;
    table->ref = ReferenceFormula(table->x);
    TaylorSeria(table);
    if (i != 5) {
      SetUpList(table);
      table->x = table->prev->x + 0.2;
    } else
      table->next = NULL;
  }
}
