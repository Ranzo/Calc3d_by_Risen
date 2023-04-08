import datetime
import json
import os
import requests
import PySimpleGUI as Sgi

from calculating import calculating, amortization, cost_prise
from setts import window_setts, mk_dir_json
from text_ru import calc, about, not_connect, new_marge, ver
from update import upd_start, upd_check

now = datetime.datetime.now()


def create_window():
    with open(os.path.expanduser('~\Documents\Calc3DbyRisen\setts.json')) as file:
        theme = json.load(file)['settings']['theme']
    Sgi.theme(theme)
    menu_def = [
        ['File', ['Настройки'], ['Выход']],
        ['Help', ['Как рассчитывается стоимость', 'Обо мне', 'Проверить обновления']],
    ]

    layout = [
        [Sgi.Menu(menu_def)],
        [Sgi.Txt('_' * 46)],
        [Sgi.Text('0', size=(7, 1), font=('Consolas', 32),
                  text_color='white', key='result', auto_size_text=True, justification='right', expand_x=True),
         Sgi.Text('руб.', font=('Consolas', 32), text_color='white', key='result')],
        [Sgi.Text('Себестоимость:', font=12, text_color='white'),
         Sgi.Text('0', size=(7, 1), font=12, text_color='white', key='cost', auto_size_text=True,
                  justification='right', expand_x=True),
         Sgi.Text('руб.', font=('Consolas', 12), text_color='white', key='cost')],
        [Sgi.Txt('_' * 46, pad=(10, 5))],
        [Sgi.Text('Время печати'), Sgi.Push(), Sgi.InputText('0', size=(5, 20)), Sgi.Text('ч.'),
         Sgi.InputText('0', size=(5, 0)), Sgi.Text('мин.  ')],
        [Sgi.Text('Вес детали'), Sgi.Push(), Sgi.InputText('0', size=(10, 20), justification='right', ),
         Sgi.Text('гр.     ')],
        [Sgi.Text('Количество экземпляров'), Sgi.Push(), Sgi.InputText('1', size=(10, 20), justification='right', ),
         Sgi.Text('шт.    ')],
        [Sgi.Txt('_' * 46)],
        [Sgi.Text('Моделирование'), Sgi.Push(), Sgi.InputText('0', size=(10, 20), justification='right', ),
         Sgi.Text('руб.   ')],
        [Sgi.Text('Постобработка'), Sgi.Push(), Sgi.InputText('0', size=(10, 20), justification='right', ),
         Sgi.Text('руб.   ')],
        [Sgi.Txt('_' * 46)],
        [Sgi.Txt(' ' * 15), Sgi.ReadFormButton('Расчитать', size=(10, 2)), Sgi.Cancel('Выход', size=(10, 2))]

    ]
    return Sgi.Window(f'Calc3D by Risen ver.{ver}', layout, icon='logo.ico')


def main():
    mk_dir_json()
    window = create_window()
    try:
        upd_start()
    except requests.exceptions.ConnectionError:
        Sgi.popup_ok(not_connect)

    while True:
        event, values = window.read()

        if event == "Настройки":
            window_setts()
            window.close()
            window = create_window()

        elif event == "Как рассчитывается стоимость":
            Sgi.popup_ok(calc)

        elif event == "Обо мне":
            Sgi.popup(about)

        elif event == "Проверить обновления":
            try:
                upd_check()
            except requests.exceptions.ConnectionError:
                Sgi.popup_ok(not_connect)

        elif event == 'Расчитать':
            with open(os.path.expanduser('~\Documents\Calc3DbyRisen\setts.json')) as file:
                params = json.load(file)["settings"]
            try:
                hours = float(values[1])
            except ValueError:
                hours = 0
            try:
                minutes = float(values[2])
            except ValueError:
                minutes = 0

            if minutes > 60:
                hours = hours + minutes // 60
                minutes = minutes % 60
            t = hours * 60 + minutes

            try:
                md = values[3]
            except ValueError:
                md = 0

            am = amortization(params['a'], t, params['spi'], now.year)  # a, t, spi, year

            cost = cost_prise(params['p'], t, params['h'], md, params['d'], params['st'], params['mk'], am,
                              values[6], values[4])  # p, t, h, md, d, st, mk, am, post, x

            try:
                result = calculating(cost, values[5], params['marge'])  # cost, mod, marg
            except KeyError:
                Sgi.popup_ok(new_marge)
                result = 0
            window.find_element('result').Update(result)
            window.find_element('cost').Update(cost)

        elif event in (Sgi.WIN_CLOSED, 'Выход'):
            break


if __name__ == "__main__":
    main()
