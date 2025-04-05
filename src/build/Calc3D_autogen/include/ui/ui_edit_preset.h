/********************************************************************************
** Form generated from reading UI file 'edit_preset.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_PRESET_H
#define UI_EDIT_PRESET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditPrinter
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *power_printer;
    QDoubleSpinBox *input_age;
    QLabel *power_printer_2;
    QDoubleSpinBox *input_price;
    QLabel *power_printer_3;
    QDoubleSpinBox *input_power;
    QLabel *power_printer_4;
    QTextEdit *input_name;

    void setupUi(QDialog *EditPrinter)
    {
        if (EditPrinter->objectName().isEmpty())
            EditPrinter->setObjectName("EditPrinter");
        EditPrinter->setStyleSheet(QString::fromUtf8("\n"
"    background-color: rgb(42, 45, 46);\n"
"    color: white; \n"
"      "));
        EditPrinter->resize(376, 196);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/logo-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditPrinter->setWindowIcon(icon);
        layoutWidget = new QWidget(EditPrinter);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 160, 341, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 80, 0);"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 80, 0);"));

        horizontalLayout->addWidget(pushButton_2);

        power_printer = new QLabel(EditPrinter);
        power_printer->setObjectName("power_printer");
        power_printer->setGeometry(QRect(20, 90, 261, 17));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        power_printer->setFont(font);
        power_printer->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        input_age = new QDoubleSpinBox(EditPrinter);
        input_age->setObjectName("input_age");
        input_age->setGeometry(QRect(290, 90, 71, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(input_age->sizePolicy().hasHeightForWidth());
        input_age->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setStyleStrategy(QFont::PreferAntialias);
        input_age->setFont(font1);
        input_age->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);"));
        input_age->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        input_age->setMinimum(0.000000000000000);
        input_age->setMaximum(99999.000000000000000);
        input_age->setValue(0.000000000000000);
        power_printer_2 = new QLabel(EditPrinter);
        power_printer_2->setObjectName("power_printer_2");
        power_printer_2->setGeometry(QRect(20, 120, 181, 17));
        power_printer_2->setFont(font);
        power_printer_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        input_price = new QDoubleSpinBox(EditPrinter);
        input_price->setObjectName("input_price");
        input_price->setGeometry(QRect(290, 120, 71, 20));
        sizePolicy.setHeightForWidth(input_price->sizePolicy().hasHeightForWidth());
        input_price->setSizePolicy(sizePolicy);
        input_price->setFont(font1);
        input_price->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);"));
        input_price->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        input_price->setMinimum(0.000000000000000);
        input_price->setMaximum(99999.000000000000000);
        input_price->setValue(0.000000000000000);
        power_printer_3 = new QLabel(EditPrinter);
        power_printer_3->setObjectName("power_printer_3");
        power_printer_3->setGeometry(QRect(20, 60, 181, 17));
        power_printer_3->setFont(font);
        power_printer_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        input_power = new QDoubleSpinBox(EditPrinter);
        input_power->setObjectName("input_power");
        input_power->setGeometry(QRect(290, 60, 71, 20));
        sizePolicy.setHeightForWidth(input_power->sizePolicy().hasHeightForWidth());
        input_power->setSizePolicy(sizePolicy);
        input_power->setFont(font1);
        input_power->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);"));
        input_power->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        input_power->setMinimum(0.000000000000000);
        input_power->setMaximum(99999.000000000000000);
        input_power->setValue(0.000000000000000);
        power_printer_4 = new QLabel(EditPrinter);
        power_printer_4->setObjectName("power_printer_4");
        power_printer_4->setGeometry(QRect(20, 20, 181, 17));
        power_printer_4->setFont(font);
        power_printer_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        input_name = new QTextEdit(EditPrinter);
        input_name->setObjectName("input_name");
        input_name->setEnabled(true);
        input_name->setGeometry(QRect(180, 20, 181, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setKerning(false);
        font2.setStyleStrategy(QFont::PreferAntialias);
        input_name->setFont(font2);
        input_name->setTabletTracking(false);
        input_name->setAcceptDrops(true);
        input_name->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 77, 77);"));
        input_name->setFrameShape(QFrame::NoFrame);
        input_name->setFrameShadow(QFrame::Sunken);
        input_name->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_name->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_name->setAutoFormatting(QTextEdit::AutoBulletList);
        input_name->setTabChangesFocus(true);
        input_name->setDocumentTitle(QString::fromUtf8(""));
        input_name->setUndoRedoEnabled(false);
        input_name->setLineWrapMode(QTextEdit::WidgetWidth);
        input_name->setAcceptRichText(false);
        input_name->setCursorWidth(1);
        input_name->setTextInteractionFlags(Qt::TextEditorInteraction);

        retranslateUi(EditPrinter);

        QMetaObject::connectSlotsByName(EditPrinter);
    } // setupUi

    void retranslateUi(QDialog *EditPrinter)
    {
        EditPrinter->setWindowTitle(QCoreApplication::translate("EditPrinter", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\321\205 \320\277\321\200\320\270\320\275\321\202\320\265\321\200\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("EditPrinter", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EditPrinter", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        power_printer->setText(QCoreApplication::translate("EditPrinter", "\320\241\321\200\320\276\320\272 \320\277\320\276\320\273\320\265\320\267\320\275\320\276\320\263\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\321\217, \320\273\320\265\321\202", nullptr));
        power_printer_2->setText(QCoreApplication::translate("EditPrinter", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \320\277\321\200\320\270\320\275\320\265\321\202\321\200\320\260, \321\200\321\203\320\261", nullptr));
        power_printer_3->setText(QCoreApplication::translate("EditPrinter", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214 \320\277\321\200\320\270\320\275\321\202\320\265\321\200\320\260, \320\222\321\202", nullptr));
        power_printer_4->setText(QCoreApplication::translate("EditPrinter", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\265\321\201\320\265\321\202\320\260", nullptr));
        input_name->setMarkdown(QString());
        input_name->setPlaceholderText(QCoreApplication::translate("EditPrinter", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\270\320\275\321\202\320\265\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditPrinter: public Ui_EditPrinter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_PRESET_H
