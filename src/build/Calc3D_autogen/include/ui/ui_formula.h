/********************************************************************************
** Form generated from reading UI file 'formula.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULA_H
#define UI_FORMULA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Formula
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QDialog *Formula)
    {
        if (Formula->objectName().isEmpty())
            Formula->setObjectName("Formula");
        Formula->setStyleSheet(QString::fromUtf8("\n"
"    background-color: rgb(42, 45, 46);\n"
"    color: white; \n"
"      "));
        Formula->resize(367, 377);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/logo-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        Formula->setWindowIcon(icon);
        label = new QLabel(Formula);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 10, 171, 41));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        label->setTextFormat(Qt::MarkdownText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2 = new QLabel(Formula);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 50, 341, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sans Serif")});
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setKerning(false);
        label_2->setFont(font1);
        label_2->setAutoFillBackground(false);
        label_2->setTextFormat(Qt::MarkdownText);
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(false);
        label_3 = new QLabel(Formula);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 341, 281));
        QFont font2;
        font2.setPointSize(10);
        label_3->setFont(font2);
        label_3->setTextFormat(Qt::MarkdownText);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3->setWordWrap(true);
        pushButton = new QPushButton(Formula);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 340, 161, 25));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 80, 0);"));

        retranslateUi(Formula);

        QMetaObject::connectSlotsByName(Formula);
    } // setupUi

    void retranslateUi(QDialog *Formula)
    {
        Formula->setWindowTitle(QCoreApplication::translate("Formula", "\320\244\320\276\321\200\320\274\321\203\320\273\320\260 \321\200\320\260\321\201\321\207\320\265\321\202\320\260", nullptr));
        label->setText(QCoreApplication::translate("Formula", "## \320\244\320\276\321\200\320\274\321\203\320\273\320\260 \321\200\320\260\321\201\321\207\320\265\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("Formula", "S = ((p/1000*t/60*h)+(md*d*st/mk)+(a+post))*x+mod", nullptr));
        label_3->setText(QCoreApplication::translate("Formula", "\320\263\320\264\320\265\n"
"```\n"
"S - \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \320\277\320\265\321\207\320\260\321\202\320\270, \321\200\321\203\320\261.\n"
"p - \320\274\320\276\321\211\320\275\320\276\321\201\321\202\321\214 \320\277\321\200\320\270\320\275\321\202\320\265\321\200\320\260, \320\222\321\202\n"
"t - \320\262\321\200\320\265\320\274\321\217 \320\277\320\265\321\207\320\260\321\202\320\270, \320\274\320\270\320\275.\n"
"h - \321\202\320\260\321\200\320\270\321\204 \320\275\320\260 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\321\215\320\275\320\265\321\200\320\263\320\270\321\216, \320\272\320\222\321\202/\321\207\n"
"md - \320\262\320\265\321\201 \320\264\320\265\321\202\320\260\320\273\320\270, \320\263\321\200.\n"
"d - \320\274\320\275\320\276\320\266\320\270\321\202\320\265\320\273\321\214 \320\276\321\202\320\261\321\200\320\260\320\272\320\276\320\262\320\272\320\270.\n"
"st - \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321"
                        "\214 \320\272\320\260\321\202\321\203\321\210\320\272\320\270 \320\277\320\273\320\260\321\201\321\202\320\270\320\272\320\260, \321\200\321\203\320\261.\n"
"mk - \320\262\320\265\321\201 \320\277\320\273\320\260\321\201\321\202\320\270\320\272\320\260 \320\262 \320\272\320\260\321\202\321\203\321\210\320\272\320\265, \320\263\321\200.\n"
"a - \320\260\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\270\320\275\321\202\320\265\321\200\320\260, \321\200\321\203\320\261.\n"
"post - \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \320\277\320\276\321\201\321\202\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270, \321\200\321\203\320\261.\n"
"\321\205 - \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\265\321\207\320\260\321\202\320\260\320\265\320\274\321\213\321\205 \320\264\321\203\320\261\320\273\320\270\320\272\320\260\321\202\320\276\320\262, \321\210\321\202.\n"
"m"
                        "od - \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217, \321\200\321\203\320\261\n"
"```", nullptr));
        pushButton->setText(QCoreApplication::translate("Formula", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Formula: public Ui_Formula {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULA_H
