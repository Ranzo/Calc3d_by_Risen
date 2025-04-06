#ifndef CALCULATING_H
#define CALCULATING_H

#include <math.h>
#include <stdlib.h>

// Объявления функций
double cost_prise(int p, int t, double h, double md, double d, double st,
                  int mk, double am, double post, int x);
double calculating(double cost, double mod, double marg);
double amortization(double a, int t, double spi);

#endif  // CALCULATING_H