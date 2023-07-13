import requests
import webbrowser
import json
import PySimpleGUI as Sgi
import os
import gettext

from texts import ver
from setts import language


lang = gettext.translation('locale', localedir='locale', languages=[language()])
lang.install()
_ = lang.gettext


def upd_check():
    with open('setts.json') as json_file:
        data = json.load(json_file)
        set_theme = data["settings"]["theme"]

    version_new = requests.get('https://risenhome.xyz/feed/Risen.json').json()["version"]["ver"]
    version_old = ver

    if version_new > version_old:

        Sgi.theme(set_theme)
        layout = [
            [Sgi.Text(_("Обновление"))],
            [Sgi.Text(_("Вышла новая версия программы\nНужно обновиться"))],
            [Sgi.Button(_(' Скачать ')), Sgi.Push(), Sgi.Button(_(' Отмена '))]
        ]

        window = Sgi.Window(_("Проверка обновления"), layout, modal=True)

        while True:
            event, button = window.read()
            if event == _(' Скачать '):
                webbrowser.open('https://risenhome.xyz/calc.html', new=2, autoraise=True)
                window.close()
            elif event == _(' Отмена '):
                window.close()
            elif event == "Exit" or event == Sgi.WIN_CLOSED:
                break
    else:
        Sgi.theme(set_theme)
        layout = [
            [Sgi.Text(_('Последняя версия: ')+f'{version_new}'+_('\nВаша версия: ')+f'{version_old}'+_('\n\nОбновление не требуется'))],
            [Sgi.Button(_(' Закрыть '))]
        ]

        window = Sgi.Window(_("Проверка обновления"), layout, modal=True)

        while True:
            event, button = window.read()
            if event == _(' Закрыть '):
                window.close()
            elif event == "Exit" or event == Sgi.WIN_CLOSED:
                break


def upd_start():
    with open('setts.json') as json_file:
        data = json.load(json_file)
        set_theme = data["settings"]["theme"]

    version_new = requests.get('https://risenhome.xyz/feed/Risen.json').json()["version"]["ver"]
    version_old = ver

    if version_new > version_old:

        Sgi.theme(set_theme)
        layout = [
            [Sgi.Text(_("Обновление"))],
            [Sgi.Text(_("Вышла новая версия программы\nНужно обновиться"))],
            [Sgi.Button(_(' Скачать ')), Sgi.Push(), Sgi.Button(' Отмена ')]
        ]

        window = Sgi.Window(_("Вышла новая версия!"), layout, modal=True)

        while True:
            event, button = window.read()
            if event == _(' Скачать '):
                webbrowser.open('https://risenhome.xyz', new=2, autoraise=True)
                window.close()
            elif event == _(' Отмена '):
                window.close()
            elif event == "Exit" or event == Sgi.WIN_CLOSED:
                break
