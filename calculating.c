#include "calculating.h"

// Функция cost_prise
double cost_prise(double p, double t, double h, double md, double d, double st, double mk, double am, double post, int x) {
    p = fabs(p);  // номинальная мощность принтера (insignet int 0-5000)
    t = fabs(t);  // время печати, в минутах (insignet int)
    h = fabs(h);  // тариф электроэнергии, руб. (double)
    md = fabs(md);  // вес детали, гр. (double)
    d = (d < 1) ? 1 : fabs(d);  // коэффициент выбраковки (double)
    st = fabs(st);  // стоимость катушки, руб (double 0-10000)
    mk = fabs(mk);  // вес катушки, гр. (1- 10000)
    am = fabs(am);  // амортизация, руб. (double)
    post = fabs(post);  // постобработка, руб. (double)
    x = abs(x);  // количество экземпляров, шт. (insignet int)

    double result = ((p / 1000) * (t / 60) * h + (md * d * (st / mk)) + (am + post)) * x;
    return round(result * 100) / 100;  // округление до 2 знаков после запятой
}

// Функция calculating
double calculating(double cost, double mod, double marg) {
    mod = fabs(mod);  // моделирование
    double margin = fabs(marg);  // процент наценки

    double result = (margin / 100 * cost + cost) + mod;
    return round(result * 100) / 100;  // округление до 2 знаков после запятой
}

// Функция amortization
double amortization(double a, double t, double spi, int year) {

    // количество минут в году
    double minutes_in_year = 525600;    

    // Если СПИ установлен на 0, то присваеваем 1 (год)
    double year_norm;
    if (spi == 0) {
        year_norm = 100 / 1;
    } else {
        year_norm = 100 / spi;
    }

    //Считаем годовую амортизацию
    double year_am = a * year_norm / 100;

    //Считаем амортизацию за минуту и умножаем на время печати
    double am_per_minute = year_am / minutes_in_year * (t*60);

    return am_per_minute;  // округление до 2 знаков после запятой
}