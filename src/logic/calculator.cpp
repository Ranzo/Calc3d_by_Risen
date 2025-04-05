#include "calculator.h"

std::pair<double, double> Calculator::calculateCostAndTotalPrice(
    double p, int t, double h, double md, double d, double st, double mk,
    double a, double post, int x, double marge, double mod, double spi) {
  double amortization = calcAmortization(a, t, spi);
  double costPrice =
      calcCostPrice(p, t, h, md, d, st, mk, amortization, post, x);
  double totalPrice = calcTotalPrice(costPrice, mod, marge);

  return {costPrice, totalPrice};
}

double Calculator::calcCostPrice(double p, double t, double h, double md,
                                 double d, double st, double mk, double am,
                                 double post, int x) {
  d = (d < 1) ? 1 : fabs(d);  // коэффициент выбраковки

  double result =
      ((p / 1000) * (t / 60) * h + (md * d * (st / mk)) + (am + post)) * x;
  return std::round(result * 100) /
         100;  // округление до 2 знаков после запятой
}

// Функция calculating
double Calculator::calcTotalPrice(double cost, double mod, double margin) {
  double result = (margin / 100 * cost + cost) + mod;
  return std::round(result * 100) /
         100;  // округление до 2 знаков после запятой
}

// Функция amortization
double Calculator::calcAmortization(double a, double t, double spi) {
  // Если СПИ установлен на 0, то присваеваем 1 (год)
  double year_norm = (!spi) ? 100 : 100 / spi;

  // Считаем годовую амортизациюcost
  double year_am = a * year_norm / 100;

  // Считаем амортизацию за минуту и умножаем на время печати
  double am_per_minute = year_am / MINUTES_PER_YEAR * t;

  return am_per_minute;  // округление до 2 знаков после запятой
}