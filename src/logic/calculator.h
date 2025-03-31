#pragma once

#include <cmath>
#include <utility>

class Calculator {
 public:
  Calculator() = delete;

  // p - номинальная мощность принтера
  // h - тариф электроэнергии
  // d - коэффициент выбраковки
  // st - стоимость катушки
  // mk - вес катушки
  // md - вес детали
  // marge - наценка
  // x - количество экземпляров
  // mod - стоимость моделирования
  // t - время печати, в минутах
  // a - стоимость принтера
  // spi - срок полезного использования
  static std::pair<double, double> calculateCostAndTotalPrice(
      double p, int t, double h, double md, double d, double st, double mk,
      double a, double post, int x, double marge, double mod, double spi);

 private:
  static double calcCostPrice(double p, double t, double h, double md, double d,
                              double st, double mk, double am, double post,
                              int x);

  static double calcTotalPrice(double cost, double mod, double margin);

  static double calcAmortization(double a, double t, double spi);

 private:
  static constexpr double MINUTES_PER_YEAR = 525600.0;
};