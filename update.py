import requests
import webbrowser
import json
import PySimpleGUI as Sgi
import os

from text_ru import ver


def upd_check():
    with open(os.path.expanduser('~\Documents\Calc3DbyRisen\setts.json')) as json_file:
        data = json.load(json_file)
        set_theme = data["settings"]["theme"]

    version_new = requests.get('https://risenhome.xyz/feed/Risen.json').json()["version"]["ver"]
    version_old = ver

    if version_new > version_old:

        Sgi.theme(set_theme)
        layout = [
            [Sgi.Text("Обновление")],
            [Sgi.Text("Вышла новая версия программы\nНужно обновиться")],
            [Sgi.Button(' Скачать '), Sgi.Push(), Sgi.Button(' Отмена ')]
        ]

        window = Sgi.Window("Проверка обновления", layout, modal=True)

        while True:
            event, button = window.read()
            if event == ' Скачать ':
                webbrowser.open('https://risenhome.xyz/calc.html', new=2, autoraise=True)
                window.close()
            elif event == ' Отмена ':
                window.close()
            elif event == "Exit" or event == Sgi.WIN_CLOSED:
                break
    else:
        Sgi.theme(set_theme)
        layout = [
            [Sgi.Text(f"Последняя версия: {version_new}\nВаша версия: {version_old}\n\nОбновление не требуется")],
            [Sgi.Button(' Закрыть ')]
        ]

        window = Sgi.Window("Проверка обновления", layout, modal=True)

        while True:
            event, button = window.read()
            if event == ' Закрыть ':
                window.close()
            elif event == "Exit" or event == Sgi.WIN_CLOSED:
                break


def upd_start():
    with open(os.path.expanduser('~\Documents\Calc3DbyRisen\setts.json')) as json_file:
        data = json.load(json_file)
        set_theme = data["settings"]["theme"]

    version_new = requests.get('https://risenhome.xyz/feed/Risen.json').json()["version"]["ver"]
    version_old = ver

    if version_new > version_old:

        Sgi.theme(set_theme)
        layout = [
            [Sgi.Text("Обновление")],
            [Sgi.Text("Вышла новая версия программы\nНужно обновиться")],
            [Sgi.Button(' Скачать '), Sgi.Push(), Sgi.Button(' Отмена ')]
        ]

        window = Sgi.Window("Вышла новая версия!", layout, modal=True)

        while True:
            event, button = window.read()
            if event == ' Скачать ':
                webbrowser.open('https://risenhome.xyz', new=2, autoraise=True)
                window.close()
            elif event == ' Отмена ':
                window.close()
            elif event == "Exit" or event == Sgi.WIN_CLOSED:
                break
