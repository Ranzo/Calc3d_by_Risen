import json
import PySimpleGUI as Sgi
import os.path

from text_ru import amortization_calc, new_sets
from themes_list import themes_list


def mk_dir_json():
    if not os.path.exists(os.path.expanduser('~\Documents\Calc3DbyRisen')):
        os.makedirs(os.path.expanduser('~\Documents\Calc3DbyRisen'))

    if not os.path.isfile(os.path.expanduser('~\Documents\Calc3DbyRisen\setts.json')):
        with open(os.path.expanduser('~\Documents\Calc3DbyRisen\setts.json'), 'w') as file:
            data = {"settings": {"theme": "Dark",
                                 "p": "270",
                                 "h": "3",
                                 "d": "1.5",
                                 "st": "1500",
                                 "mk": "1000",
                                 "a": "0",
                                 "spi": "3",
                                 "marg": "0"}}
            json.dump(data, file, indent=2)


def window_setts():
    with open(os.path.expanduser('~\Documents\Calc3DbyRisen\setts.json')) as file:
        old_data = json.load(file)
        theme = old_data["settings"]["theme"]
        p = old_data["settings"]["p"]
        h = old_data["settings"]["h"]
        d = old_data["settings"]["d"]
        st = old_data["settings"]["st"]
        mk = old_data["settings"]["mk"]
        a = old_data["settings"]["a"]
        try:
            spi = old_data["settings"]["spi"]
        except KeyError:
            Sgi.popup_ok(new_sets)
            spi = 0
        try:
            marg = old_data["settings"]["marge"]
        except KeyError:
            marg = 0

    layout1 = [
        [Sgi.Text("ВНИМАНИЕ! Перед установкой параметра\n'Коэффициент выбраковки' прочитайте раздел\n"
                  "Help, с описанием формулы расчета!\n", text_color="red")],
        [Sgi.Text('Мощность принтера, Вт'), Sgi.Push(), Sgi.InputText(p, size=(10, 10), justification='right')],
        [Sgi.Text('Тариф электроэнергии, кВт/ч'), Sgi.Push(), Sgi.InputText(h, size=(10, 10), justification='right')],
        [Sgi.Text('Коэффициент выбраковки'), Sgi.Push(), Sgi.InputText(d, size=(10, 10), justification='right')],
        [Sgi.Text('Стоимость катушки, руб.'), Sgi.Push(), Sgi.InputText(st, size=(10, 10), justification='right')],
        [Sgi.Text('Вес катушки, гр.'), Sgi.Push(), Sgi.Combo(['225', '250', '450', '500', '750', '850', '1000', '2250',
                                                              '2500'], size=(8, 20), default_value=mk)],
        [Sgi.Text('Наценка, %.'), Sgi.Push(), Sgi.InputText(marg, size=(10, 10), justification='right')],
        [Sgi.Text('')]
    ]
    layout2 = [
        [Sgi.Text('Стоимость вашего принтера, руб.'), Sgi.Push(), Sgi.InputText(a, size=(10, 10),
                                                                                justification='right')],
        [Sgi.Text('Срок полезного использования, лет.'), Sgi.Push(), Sgi.InputText(spi, size=(10, 10),
                                                                                   justification='right')],
        [Sgi.Text('_' * 45)], [Sgi.Text(amortization_calc)],
        [Sgi.Text('')]
    ]
    layout3 = [
        [Sgi.Text('Оформление')],
        [Sgi.Text("Выбор темы"), Sgi.Push(), Sgi.Combo(themes_list, size=(20, 20), default_value=theme)],
    ]

    tab_group = [
        [Sgi.TabGroup(
            [[Sgi.Tab('Основные настройки', layout1), Sgi.Tab('Амортизация', layout2), Sgi.Tab('Оформление', layout3)]]
        ), [Sgi.Push(), Sgi.Button('Применить')]]]

    window = Sgi.Window("Настройки", tab_group, modal=True)
    while True:
        event, values = window.read()
        if event == 'Применить':
            if values[8] == theme:
                new_theme = theme
            else:
                new_theme = values[8]
            if values[0] == p:
                new_p = p
            else:
                new_p = values[0]
            if values[1] == h:
                new_h = h
            else:
                new_h = values[1].replace(',', '.')
            if values[2] == d:
                new_d = d
            else:
                new_d = values[2].replace(',', '.')
            if values[3] == st:
                new_st = st
            else:
                new_st = values[3]
            if values[4] == mk:
                new_mk = mk
            else:
                new_mk = values[4]
            if values[5] == marg:
                new_marg = marg
            else:
                new_marg = values[5].replace(',', '.')
            if values[6] == a:
                new_a = a
            else:
                new_a = values[6]
            if values[7] == spi:
                new_spi = spi
            else:
                new_spi = values[7]
            with open(os.path.expanduser('~\Documents\Calc3DbyRisen\setts.json'), 'w') as file:
                data = {"settings": {"theme": new_theme,
                                     "p": new_p,
                                     "h": new_h,
                                     "d": new_d,
                                     "st": new_st,
                                     "mk": new_mk,
                                     "a": new_a,
                                     "spi": new_spi,
                                     "marge": new_marg
                                     }
                        }
                json.dump(data, file, indent=2)

            window.close()

        if event == "Exit" or event == Sgi.WIN_CLOSED:
            break
