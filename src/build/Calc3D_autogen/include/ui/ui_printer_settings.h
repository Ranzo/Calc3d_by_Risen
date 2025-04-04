/********************************************************************************
** Form generated from reading UI file 'printer_settings.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTER_SETTINGS_H
#define UI_PRINTER_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrinterSettingsDialog
{
public:
    QDoubleSpinBox *input_tarif;
    QLabel *Tarif;
    QDoubleSpinBox *input_q_trash;
    QLabel *Q_trash;
    QDoubleSpinBox *input_price_pastik;
    QLabel *Price_plastik;
    QDoubleSpinBox *input_overprice;
    QLabel *Over_price;
    QLabel *weight_plastik;
    QSpinBox *plastik_menu;
    QLabel *warning_text;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *save;
    QPushButton *exit;

    void setupUi(QDialog *PrinterSettingsDialog)
    {
        if (PrinterSettingsDialog->objectName().isEmpty())
            PrinterSettingsDialog->setObjectName("PrinterSettingsDialog");
        PrinterSettingsDialog->setStyleSheet(QString::fromUtf8("\n"
"    background-color: rgb(42, 45, 46);\n"
"    color: white; \n"
"      "));
        PrinterSettingsDialog->resize(379, 337);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/logo-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        PrinterSettingsDialog->setWindowIcon(icon);
        input_tarif = new QDoubleSpinBox(PrinterSettingsDialog);
        input_tarif->setObjectName("input_tarif");
        input_tarif->setGeometry(QRect(280, 90, 71, 25));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(input_tarif->sizePolicy().hasHeightForWidth());
        input_tarif->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        input_tarif->setFont(font);
        input_tarif->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);"));
        input_tarif->setMinimum(0.000000000000000);
        input_tarif->setMaximum(10000.000000000000000);
        Tarif = new QLabel(PrinterSettingsDialog);
        Tarif->setObjectName("Tarif");
        Tarif->setGeometry(QRect(20, 90, 221, 25));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        Tarif->setFont(font1);
        Tarif->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        input_q_trash = new QDoubleSpinBox(PrinterSettingsDialog);
        input_q_trash->setObjectName("input_q_trash");
        input_q_trash->setGeometry(QRect(280, 130, 71, 25));
        sizePolicy.setHeightForWidth(input_q_trash->sizePolicy().hasHeightForWidth());
        input_q_trash->setSizePolicy(sizePolicy);
        input_q_trash->setFont(font);
        input_q_trash->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);"));
        input_q_trash->setMinimum(0.000000000000000);
        input_q_trash->setMaximum(10000.000000000000000);
        Q_trash = new QLabel(PrinterSettingsDialog);
        Q_trash->setObjectName("Q_trash");
        Q_trash->setGeometry(QRect(20, 130, 201, 25));
        Q_trash->setFont(font1);
        Q_trash->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        input_price_pastik = new QDoubleSpinBox(PrinterSettingsDialog);
        input_price_pastik->setObjectName("input_price_pastik");
        input_price_pastik->setGeometry(QRect(280, 170, 71, 25));
        sizePolicy.setHeightForWidth(input_price_pastik->sizePolicy().hasHeightForWidth());
        input_price_pastik->setSizePolicy(sizePolicy);
        input_price_pastik->setFont(font);
        input_price_pastik->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);"));
        input_price_pastik->setMinimum(0.000000000000000);
        input_price_pastik->setMaximum(10000.000000000000000);
        Price_plastik = new QLabel(PrinterSettingsDialog);
        Price_plastik->setObjectName("Price_plastik");
        Price_plastik->setGeometry(QRect(20, 170, 181, 25));
        Price_plastik->setFont(font1);
        Price_plastik->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        input_overprice = new QDoubleSpinBox(PrinterSettingsDialog);
        input_overprice->setObjectName("input_overprice");
        input_overprice->setGeometry(QRect(280, 210, 71, 25));
        sizePolicy.setHeightForWidth(input_overprice->sizePolicy().hasHeightForWidth());
        input_overprice->setSizePolicy(sizePolicy);
        input_overprice->setFont(font);
        input_overprice->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);"));
        input_overprice->setMinimum(0.000000000000000);
        input_overprice->setMaximum(10000.000000000000000);
        Over_price = new QLabel(PrinterSettingsDialog);
        Over_price->setObjectName("Over_price");
        Over_price->setGeometry(QRect(20, 210, 181, 25));
        Over_price->setFont(font1);
        Over_price->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        weight_plastik = new QLabel(PrinterSettingsDialog);
        weight_plastik->setObjectName("weight_plastik");
        weight_plastik->setGeometry(QRect(20, 250, 181, 25));
        weight_plastik->setFont(font1);
        weight_plastik->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        plastik_menu = new QSpinBox(PrinterSettingsDialog);
        plastik_menu->setObjectName("plastik_menu");
        plastik_menu->setGeometry(QRect(280, 250, 71, 25));
        plastik_menu->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);"));
        plastik_menu->setMinimum(0);
        plastik_menu->setMaximum(10000);
        plastik_menu->setValue(0);
        plastik_menu->setFont(font);
        warning_text = new QLabel(PrinterSettingsDialog);
        warning_text->setObjectName("warning_text");
        warning_text->setGeometry(QRect(30, 10, 311, 51));
        warning_text->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        warning_text->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        warning_text->setWordWrap(true);
        layoutWidget = new QWidget(PrinterSettingsDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 300, 331, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        save = new QPushButton(layoutWidget);
        save->setObjectName("save");
        save->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 80, 0);"));

        horizontalLayout->addWidget(save);

        exit = new QPushButton(layoutWidget);
        exit->setObjectName("exit");
        exit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 80, 0);"));

        horizontalLayout->addWidget(exit);


        retranslateUi(PrinterSettingsDialog);

        QMetaObject::connectSlotsByName(PrinterSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *PrinterSettingsDialog)
    {
        PrinterSettingsDialog->setWindowTitle(QCoreApplication::translate("PrinterSettingsDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        Tarif->setText(QCoreApplication::translate("PrinterSettingsDialog", "\320\242\320\260\321\200\320\270\321\204 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\321\215\320\275\320\265\321\200\320\263\320\270\320\270, \320\272\320\222\320\242/\321\207", nullptr));
        Q_trash->setText(QCoreApplication::translate("PrinterSettingsDialog", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\262\321\213\320\261\321\200\320\260\320\272\320\276\320\262\320\272\320\270", nullptr));
        Price_plastik->setText(QCoreApplication::translate("PrinterSettingsDialog", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \320\272\320\260\321\202\321\203\321\210\320\272\320\270, \321\200\321\203\320\261", nullptr));
        Over_price->setText(QCoreApplication::translate("PrinterSettingsDialog", "\320\235\320\260\321\206\320\265\320\275\320\272\320\260, %", nullptr));
        weight_plastik->setText(QCoreApplication::translate("PrinterSettingsDialog", "\320\222\320\265\321\201 \320\272\320\260\321\202\321\203\321\210\320\272\320\270, \320\263\321\200", nullptr));
        warning_text->setText(QCoreApplication::translate("PrinterSettingsDialog", "\320\222\320\235\320\230\320\234\320\220\320\235\320\230\320\225! \320\237\320\265\321\200\320\265\320\264 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\276\320\271 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260 \"\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\262\321\213\320\261\321\200\320\260\320\272\320\276\320\262\320\272\320\270\" \320\277\321\200\320\276\321\207\320\270\321\202\320\260\320\271\321\202\320\265 \321\200\320\260\320\267\320\264\320\265\320\273 \320\237\320\276\320\274\320\276\321\211\321\214, \321\201 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265\320\274 \321\204\320\276\321\200\320\274\321\203\320\273\321\213 \321\200\320\260\321\201\321\207\320\265\321\202\320\260!", nullptr));
        save->setText(QCoreApplication::translate("PrinterSettingsDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        exit->setText(QCoreApplication::translate("PrinterSettingsDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrinterSettingsDialog: public Ui_PrinterSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTER_SETTINGS_H
