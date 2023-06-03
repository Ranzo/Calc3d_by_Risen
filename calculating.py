def cost_prise(p, t, h, md, d, st, mk, am, post, x):
    p = int(p)  # номинальная мощность принтера
    t = int(t)  # время печати, в минутах!!!
    h = float(h)  # тариф электроэнергии
    md = float(md)  # вес детали
    d = float(d)  # коэффициент выбраковки
    st = float(st)  # стоимость катушки
    mk = float(mk)  # вес катушки
    am = float(am)  # амортизация
    try:
        post = float(post)  # постобработка
    except ValueError:
        post = 0
    try:
        x = int(x)  # количество экземпляров
    except ValueError:
        x = 1
    result = (abs(p) / 1000 * abs(t) / 60 * abs(h)) + (abs(md) * abs(d) * (abs(st) / abs(mk)) + abs(am) + abs(post)) * abs(x)
    return round(result, 2)


def calculating(cost, mod, marg):
    try:
        mod = float(mod)  # моделирование
    except ValueError:
        mod = 0
    try:
        margin = float(marg)  # процент наценки
    except ValueError:
        margin = 0
    result = (cost / 100 * margin + cost) + mod
    return round(result, 2)


def amortization(a, t, spi, year):
    if (year % 400 == 0) or (year % 100 != 0) and (year % 4 == 0):
        minutes_in_year = 527040 / 2
    else:
        minutes_in_year = 525600 / 2
    try:
        year_norm = 100 / float(spi)
    except ZeroDivisionError:
        year_norm = 100 / 1
    year_am = float(a) / 100 * round(year_norm, 1)
    am_per_minute = year_am / minutes_in_year * t
    return round(am_per_minute, 2)
