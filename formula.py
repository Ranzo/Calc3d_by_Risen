# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'formula.ui'
##
## Created by: Qt User Interface Compiler version 6.8.1
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QDialog, QLabel, QPushButton,
    QSizePolicy, QWidget)

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        if not Dialog.objectName():
            Dialog.setObjectName(u"Dialog")
        Dialog.resize(367, 377)
        icon = QIcon()
        icon.addFile(u"img/logo-1.png", QSize(), QIcon.Mode.Normal, QIcon.State.Off)
        Dialog.setWindowIcon(icon)
        self.label = QLabel(Dialog)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(100, 10, 171, 41))
        font = QFont()
        font.setPointSize(9)
        self.label.setFont(font)
        self.label.setTextFormat(Qt.MarkdownText)
        self.label.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignTop)
        self.label_2 = QLabel(Dialog)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(30, 50, 341, 21))
        font1 = QFont()
        font1.setFamilies([u"Sans Serif"])
        font1.setPointSize(10)
        font1.setBold(True)
        font1.setKerning(False)
        self.label_2.setFont(font1)
        self.label_2.setAutoFillBackground(False)
        self.label_2.setTextFormat(Qt.MarkdownText)
        self.label_2.setScaledContents(True)
        self.label_2.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignTop)
        self.label_2.setWordWrap(False)
        self.label_3 = QLabel(Dialog)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(10, 80, 341, 281))
        font2 = QFont()
        font2.setPointSize(10)
        self.label_3.setFont(font2)
        self.label_3.setTextFormat(Qt.MarkdownText)
        self.label_3.setScaledContents(False)
        self.label_3.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignTop)
        self.label_3.setWordWrap(True)
        self.pushButton = QPushButton(Dialog)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(100, 340, 161, 25))
        self.pushButton.setStyleSheet(u"background-color: rgb(0, 80, 0);")

        self.retranslateUi(Dialog)

        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"\u0424\u043e\u0440\u043c\u0443\u043b\u0430 \u0440\u0430\u0441\u0447\u0435\u0442\u0430", None))
        self.label.setText(QCoreApplication.translate("Dialog", u"## \u0424\u043e\u0440\u043c\u0443\u043b\u0430 \u0440\u0430\u0441\u0447\u0435\u0442\u0430", None))
        self.label_2.setText(QCoreApplication.translate("Dialog", u"S = ((p/1000*t/60*h)+(md*d*st/mk)+(a+post))*x+mod", None))
        self.label_3.setText(QCoreApplication.translate("Dialog", u"\u0433\u0434\u0435\n"
"```\n"
"S - \u0441\u0442\u043e\u0438\u043c\u043e\u0441\u0442\u044c \u043f\u0435\u0447\u0430\u0442\u0438, \u0440\u0443\u0431.\n"
"p - \u043c\u043e\u0449\u043d\u043e\u0441\u0442\u044c \u043f\u0440\u0438\u043d\u0442\u0435\u0440\u0430, \u0412\u0442\n"
"t - \u0432\u0440\u0435\u043c\u044f \u043f\u0435\u0447\u0430\u0442\u0438, \u043c\u0438\u043d.\n"
"h - \u0442\u0430\u0440\u0438\u0444 \u043d\u0430 \u044d\u043b\u0435\u043a\u0442\u0440\u043e\u044d\u043d\u0435\u0440\u0433\u0438\u044e, \u043a\u0412\u0442/\u0447\n"
"md - \u0432\u0435\u0441 \u0434\u0435\u0442\u0430\u043b\u0438, \u0433\u0440.\n"
"d - \u043c\u043d\u043e\u0436\u0438\u0442\u0435\u043b\u044c \u043e\u0442\u0431\u0440\u0430\u043a\u043e\u0432\u043a\u0438.\n"
"st - \u0441\u0442\u043e\u0438\u043c\u043e\u0441\u0442\u044c \u043a\u0430\u0442\u0443\u0448\u043a\u0438 \u043f\u043b\u0430\u0441\u0442\u0438\u043a\u0430, \u0440\u0443\u0431.\n"
"mk - \u0432\u0435\u0441 \u043f\u043b\u0430\u0441\u0442\u0438\u043a\u0430 \u0432 \u043a\u0430\u0442\u0443\u0448"
                        "\u043a\u0435, \u0433\u0440.\n"
"a - \u0430\u043c\u043e\u0440\u0442\u0438\u0437\u0430\u0446\u0438\u044f \u043f\u0440\u0438\u043d\u0442\u0435\u0440\u0430, \u0440\u0443\u0431.\n"
"post - \u0441\u0442\u043e\u0438\u043c\u043e\u0441\u0442\u044c \u043f\u043e\u0441\u0442\u043e\u0431\u0440\u0430\u0431\u043e\u0442\u043a\u0438, \u0440\u0443\u0431.\n"
"\u0445 - \u043a\u043e\u043b\u0438\u0447\u0435\u0441\u0442\u0432\u043e \u043f\u0435\u0447\u0430\u0442\u0430\u0435\u043c\u044b\u0445 \u0434\u0443\u0431\u043b\u0438\u043a\u0430\u0442\u043e\u0432, \u0448\u0442.\n"
"mod - \u0441\u0442\u043e\u0438\u043c\u043e\u0441\u0442\u044c \u043c\u043e\u0434\u0435\u043b\u0438\u0440\u043e\u0432\u0430\u043d\u0438\u044f, \u0440\u0443\u0431\n"
"```", None))
        self.pushButton.setText(QCoreApplication.translate("Dialog", u"\u0417\u0430\u043a\u0440\u044b\u0442\u044c", None))
    # retranslateUi

