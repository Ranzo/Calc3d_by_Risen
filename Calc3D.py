import datetime
import json
import os
import PySimpleGUI as Sgi
import gettext
import requests

from calculating import calculating, amortization, cost_prise
from setts import window_setts, language, currency_setts
from texts import calc, about, new_marge, ver, not_connect
from update import upd_check, upd_start

now = datetime.datetime.now()


lang = gettext.translation('locale', localedir='locale', languages=[language()])
lang.install()
_ = lang.gettext


def create_window():
    with open('setts.json') as f:
        theme = json.load(f)['settings']['theme']
    Sgi.theme(theme)
    menu_def = [
        [_('Файл'), [_('Настройки')], [_('Выход')]],
        [_('Помощь'), [_('Как рассчитывается стоимость'), _('Обо мне'), _('Проверить обновления')]],
    ]

    layout = [
        [Sgi.Menu(menu_def)],
        [Sgi.Txt('_' * 46)],
        [Sgi.Text('0', size=(7, 1), font=('Consolas', 32),
                  text_color='white', key='result', auto_size_text=True, justification='right', expand_x=True),
         Sgi.Text(currency_setts(), font=('Consolas', 32), text_color='white', key='result')],
        [Sgi.Text(_('Себестоимость:'), font=12, text_color='white'),
         Sgi.Text('0', size=(7, 1), font=12, text_color='white', key='cost', auto_size_text=True,
                  justification='right', expand_x=True),
         Sgi.Text(currency_setts(), font=('Consolas', 12), text_color='white', key='cost')],
        [Sgi.Txt('_' * 46, pad=(10, 5))],
        [Sgi.Text(_('Время печати')), Sgi.Push(), Sgi.InputText('0', size=(5, 20)), Sgi.Text(_('ч.')),
         Sgi.InputText('0', size=(5, 0)), Sgi.Text(_('мин.  '))],
        [Sgi.Text(_('Масса детали')), Sgi.Push(), Sgi.InputText('0', size=(10, 20), justification='right', ),
         Sgi.Text(_('г.      '))],
        [Sgi.Text(_('Количество экземпляров')), Sgi.Push(), Sgi.InputText('1', size=(10, 20), justification='right', ),
         Sgi.Text(_('шт.    '))],
        [Sgi.Txt('_' * 46)],
        [Sgi.Text(_('Моделирование')), Sgi.Push(), Sgi.InputText('0', size=(10, 20), justification='right', ),
         Sgi.Text(f'{currency_setts()}   ')],
        [Sgi.Text(_('Постобработка')), Sgi.Push(), Sgi.InputText('0', size=(10, 20), justification='right', ),
         Sgi.Text(f'{currency_setts()}   ')],
        [Sgi.Txt('_' * 46)],
        [Sgi.Txt(' ' * 15), Sgi.ReadFormButton(_('Рассчитать'), size=(10, 2)), Sgi.Cancel(_('Выход'), size=(10, 2))]

    ]
    return Sgi.Window(f'Calc3D by Risen ver.{ver}', layout, icon='logo.ico')


def main():
    upd_start()
    window = create_window()

    while True:
        event, values = window.read()

        if event == _("Настройки"):
            window_setts()
            window.close()
            window = create_window()

        elif event == _("Как рассчитывается стоимость"):
            Sgi.popup_ok(calc)

        elif event == _("Обо мне"):
            Sgi.popup(about)

        elif event == "Проверить обновления":
            try:
                upd_check()
            except requests.exceptions.ConnectionError:
                Sgi.popup_ok(not_connect)

        elif event == _('Рассчитать'):
            with open('setts.json') as f:
                params = json.load(f)["settings"]
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
                result = calculating(abs(cost), values[5], params['marge'])  # cost, mod, marg
            except KeyError:
                Sgi.popup_ok(new_marge)
                result = 0
            window.find_element('result').Update(result)
            window.find_element('cost').Update(cost)

        elif event in (Sgi.WIN_CLOSED, _('Выход')):
            break


if __name__ == "__main__":
    main()
