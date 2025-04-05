/********************************************************************************
** Form generated from reading UI file 'del_preset.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEL_PRESET_H
#define UI_DEL_PRESET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DelPreset
{
public:
    QTableWidget *tableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *edit_button;
    QPushButton *delete_button;
    QPushButton *reject_button;

    void setupUi(QDialog *DelPreset)
    {
        if (DelPreset->objectName().isEmpty())
            DelPreset->setObjectName("DelPreset");
        DelPreset->setStyleSheet(QString::fromUtf8("\n"
"    background-color: rgb(42, 45, 46);\n"
"    color: white; \n"
"      "));
        DelPreset->resize(369, 347);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/logo-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        DelPreset->setWindowIcon(icon);
        tableWidget = new QTableWidget(DelPreset);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 20, 321, 271));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 36, 36);"));
        widget = new QWidget(DelPreset);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(23, 310, 321, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        edit_button = new QPushButton(widget);
        edit_button->setObjectName("edit_button");
        edit_button->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 80, 0);"));

        horizontalLayout->addWidget(edit_button);

        delete_button = new QPushButton(widget);
        delete_button->setObjectName("delete_button");
        delete_button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(delete_button);

        reject_button = new QPushButton(widget);
        reject_button->setObjectName("reject_button");
        reject_button->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 80, 0);"));

        horizontalLayout->addWidget(reject_button);


        retranslateUi(DelPreset);

        QMetaObject::connectSlotsByName(DelPreset);
    } // setupUi

    void retranslateUi(QDialog *DelPreset)
    {
        DelPreset->setWindowTitle(QCoreApplication::translate("DelPreset", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\321\200\320\270\320\275\321\202\320\265\321\200\320\260", nullptr));
        edit_button->setText(QCoreApplication::translate("DelPreset", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        delete_button->setText(QCoreApplication::translate("DelPreset", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        reject_button->setText(QCoreApplication::translate("DelPreset", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DelPreset: public Ui_DelPreset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEL_PRESET_H
