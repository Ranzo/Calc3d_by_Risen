/********************************************************************************
** Form generated from reading UI file 'updates.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATES_H
#define UI_UPDATES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Updates
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Updates)
    {
        if (Updates->objectName().isEmpty())
            Updates->setObjectName("Updates");
        Updates->setStyleSheet(QString::fromUtf8("\n"
"    background-color: rgb(42, 45, 46);\n"
"    color: white; \n"
"      "));
        Updates->resize(379, 99);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/logo-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        Updates->setWindowIcon(icon);
        label = new QLabel(Updates);
        label->setObjectName("label");
        label->setGeometry(QRect(73, 10, 191, 25));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(Updates);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 30, 191, 25));
        label_2->setFont(font);
        label_3 = new QLabel(Updates);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 10, 54, 25));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label_3->setFont(font1);
        label_4 = new QLabel(Updates);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(250, 30, 54, 25));
        label_4->setFont(font1);
        layoutWidget = new QWidget(Updates);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 60, 331, 27));
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


        retranslateUi(Updates);

        QMetaObject::connectSlotsByName(Updates);
    } // setupUi

    void retranslateUi(QDialog *Updates)
    {
        Updates->setWindowTitle(QCoreApplication::translate("Updates", "\320\236\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("Updates", "\320\222\320\260\321\210\320\260 \320\262\320\265\321\200\321\201\320\270\321\217:", nullptr));
        label_2->setText(QCoreApplication::translate("Updates", "\320\222\320\265\321\200\321\201\320\270\321\217 \320\275\320\260 \321\201\320\260\320\271\321\202\320\265:", nullptr));
        label_3->setText(QCoreApplication::translate("Updates", "1.0.0", nullptr));
        label_4->setText(QCoreApplication::translate("Updates", "1.0.0", nullptr));
        pushButton->setText(QCoreApplication::translate("Updates", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\275\320\260 \321\201\320\260\320\271\321\202", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Updates", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Updates: public Ui_Updates {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATES_H
