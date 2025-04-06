#pragma once

#include <cmath>
#include <utility>

// p -
// h -
// d -
// st - стоимость катушки
// mk - вес катушки
// md - вес детали
// marge -
// x - количество экземпляров
// mod -
// t -
// a - стоимость принтера
// spi -
struct Params {
  double p;      // номинальная мощность принтера
  double t;      // время печати, в минутах
  double h;      // тариф электроэнергии
  double md;     //
  double d;      // коэффициент выбраковки
  double st;     //
  double mk;     //
  double a;      //
  double post;   //
  int x;         //
  double marge;  // наценка
  double mod;    // стоимость моделирования
  double spi;    // срок полезного использования
};

class Calculator {
 public:
  Calculator() = delete;

  static std::pair<double, double> calculateCostAndTotalPrice(Params& param);

 private:
  static double calcCostPrice(Params& param);

  static double calcTotalPrice(Params& param, double costPrice);

  static double calcAmortization(double a, double t, double spi);

 private:
  static constexpr double MINUTES_PER_YEAR = 525600.0;
};