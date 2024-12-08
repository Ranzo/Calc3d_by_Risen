import sys
from PySide6.QtWidgets import QApplication, QMainWindow
from calc3dui import Ui_Calc3DbyRisen


class App(QMainWindow):
    def __init__(self):
        super(App, self).__init__()
        self.ui = Ui_Calc3DbyRisen()
        self.ui.setupUi(self)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = App()
    window.show()
    sys.exit(app.exec())
