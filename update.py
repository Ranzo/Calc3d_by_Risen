import requests
import webbrowser
import json
import gettext
from texts import ver


lang = gettext.translation('locale', localedir='locale', languages=[language()])
lang.install()
_ = lang.gettext


def upd_check():
    with open('setts.json') as json_file:
        data = json.load(json_file)
        set_theme = data["settings"]["theme"]

    version_new = requests.get('https://risenhome.xyz/feed/Risen.json').json()["version"]["ver"]
    version_old = ver


