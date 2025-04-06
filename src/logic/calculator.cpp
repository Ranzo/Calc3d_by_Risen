#include "calculator.h"

std::pair<double, double> Calculator::calculateCostAndTotalPrice(
    Params& param) {
  double costPrice = calcCostPrice(param);
  double totalPrice = calcTotalPrice(param, costPrice);

  return {costPrice, totalPrice};
}

double Calculator::calcCostPrice(Params& param) {
  param.d = (param.d < 1) ? 1 : param.d;  // коэффициент выбраковки

  double am = calcAmortization(param.a, param.t, param.spi);
  double result =
      ((param.p / 1000) * (param.t / 60) * param.h +
       (param.md * param.d * (param.st / param.mk)) + (am + param.post)) *
      param.x;
  return std::round(result * 100) /
         100;  // округление до 2 знаков после запятой
}

// Функция calculating
double Calculator::calcTotalPrice(Params& param, double costPrice) {
  double result = (param.marge / 100 * costPrice + costPrice) + param.mod;
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