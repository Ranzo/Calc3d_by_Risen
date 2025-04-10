#pragma once

#include <cmath>
#include <utility>

struct Params {
  int p;         // номинальная мощность принтера
  int t;         // время печати, в минутах
  double h;      // тариф электроэнергии
  double md;     // вес детали
  double d;      // коэффициент выбраковки
  double st;     // стоимость катушки
  int mk;        // вес катушки
  double a;      // стоимость принтера
  double post;   // стоимость постобработки
  int x;         // количество экземпляров
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

  static double calcAmortization(double a, int t, double spi);

 private:
  static constexpr double MINUTES_PER_YEAR = 525600.0;
};