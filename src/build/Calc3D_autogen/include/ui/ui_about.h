/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *label;

    void setupUi(QDialog *progInfo)
    {
        if (progInfo->objectName().isEmpty())
            progInfo->setObjectName("progInfo");
        progInfo->setStyleSheet(QString::fromUtf8("\n"
"    background-color: rgb(42, 45, 46);\n"
"    color: white; \n"
"      "));
        progInfo->resize(365, 97);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/logo-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        progInfo->setWindowIcon(icon);
        label = new QLabel(progInfo);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 331, 231));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);

        retranslateUi(progInfo);

        QMetaObject::connectSlotsByName(progInfo);
    } // setupUi

    void retranslateUi(QDialog *progInfo)
    {
        progInfo->setWindowTitle(QCoreApplication::translate("About", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        label->setText(QCoreApplication::translate("About", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200 Calc3D by Risen \320\277\321\200\320\265\320\264\320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275 \320\264\320\273\321\217 \320\261\321\213\321\201\321\202\321\200\320\276\320\271 \320\276\321\206\320\265\320\275\320\272\320\270 \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\320\270 \320\277\320\265\321\207\320\260\321\202\320\270 \320\275\320\260 3D \320\277\321\200\320\270\320\275\321\202\320\265\321\200\320\265,\n"
"\320\270\321\201\321\205\320\276\320\264\321\217 \320\270\320\267 \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\320\270 \320\277\320\273\320\260\321\201\321\202\320\270\320\272\320\260, \320\262\320\265\321\201\320\260, \321\202\320\260\321\200\320\270\321\204\320\260 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\321\215\320\275\320\265\321\200\320\263\320\270\320\270 \320\270 \320\277\321\200\320\276\321\207\320\265\320\263\320\276...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
