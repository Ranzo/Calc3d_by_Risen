/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *check_update;
    QAction *formula;
    QAction *about;
    QAction *settings_2;
    QAction *add_preset;
    QAction *del_printer;
    QAction *action_3;
    QWidget *centralwidget;
    QLabel *quantity;
    QLabel *weight;
    QLabel *time_print;
    QLabel *printer;
    QComboBox *printer_menu;
    QLCDNumber *lcd_result_total;
    QLCDNumber *lcd_result_cost;
    QLabel *cost_price;
    QSpinBox *input_hours;
    QLabel *text_time_hours;
    QSpinBox *input_minutes;
    QLabel *text_time_minuts;
    QSpinBox *input_gram;
    QSpinBox *input_things;
    QDoubleSpinBox *input_mod;
    QDoubleSpinBox *input_post;
    QLabel *text_gram;
    QLabel *text_things;
    QLabel *text_rub_mod;
    QLabel *text_rub_post;
    QLabel *ico_rub;
    QFrame *frame;
    QFrame *frame_2;
    QWidget *layoutWidget;
    QHBoxLayout *buttons;
    QPushButton *get_result_btn;
    QPushButton *exit_btn;
    QLabel *modeling;
    QLabel *post_print;
    QMenuBar *menubar;
    QMenu *settings;
    QMenu *pressets;
    QMenu *help;

    void setupUi(QMainWindow *Calc3DbyRisen)
    {
        if (Calc3DbyRisen->objectName().isEmpty())
            Calc3DbyRisen->setObjectName("Calc3DbyRisen");
        Calc3DbyRisen->resize(373, 471);
        QFont font;
        font.setBold(true);
        Calc3DbyRisen->setFont(font);
        Calc3DbyRisen->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/logo-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        Calc3DbyRisen->setWindowIcon(icon);
        Calc3DbyRisen->setAutoFillBackground(true);
        Calc3DbyRisen->setStyleSheet(QString::fromUtf8(""));
        Calc3DbyRisen->setDockOptions(QMainWindow::DockOption::AllowTabbedDocks|QMainWindow::DockOption::AnimatedDocks);
        check_update = new QAction(Calc3DbyRisen);
        check_update->setObjectName("check_update");
        check_update->setCheckable(false);
        formula = new QAction(Calc3DbyRisen);
        formula->setObjectName("formula");
        about = new QAction(Calc3DbyRisen);
        about->setObjectName("about");
        settings_2 = new QAction(Calc3DbyRisen);
        settings_2->setObjectName("settings_2");
        add_preset = new QAction(Calc3DbyRisen);
        add_preset->setObjectName("add_preset");
        del_printer = new QAction(Calc3DbyRisen);
        del_printer->setObjectName("del_printer");
        action_3 = new QAction(Calc3DbyRisen);
        action_3->setObjectName("action_3");
        action_3->setMenuRole(QAction::MenuRole::QuitRole);
        centralwidget = new QWidget(Calc3DbyRisen);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"    background-color: rgb(42, 45, 46);\n"
"    color: white; \n"
"        "));
        quantity = new QLabel(centralwidget);
        quantity->setObjectName("quantity");
        quantity->setGeometry(QRect(20, 270, 171, 17));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        quantity->setFont(font1);
        quantity->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        weight = new QLabel(centralwidget);
        weight->setObjectName("weight");
        weight->setGeometry(QRect(20, 240, 101, 17));
        weight->setFont(font1);
        weight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        time_print = new QLabel(centralwidget);
        time_print->setObjectName("time_print");
        time_print->setGeometry(QRect(20, 210, 101, 17));
        time_print->setFont(font1);
        time_print->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        printer = new QLabel(centralwidget);
        printer->setObjectName("printer");
        printer->setGeometry(QRect(21, 171, 81, 17));
        printer->setFont(font1);
        printer->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        printer_menu = new QComboBox(centralwidget);
        printer_menu->setObjectName("printer_menu");
        printer_menu->setGeometry(QRect(181, 170, 171, 25));
        printer_menu->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(77, 77, 77);"));
        printer_menu->setAcceptDrops(true);
        printer_menu->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(77, 77, 77);"));
        printer_menu->setInsertPolicy(QComboBox::InsertPolicy::NoInsert);
        lcd_result_total = new QLCDNumber(centralwidget);
        lcd_result_total->setObjectName("lcd_result_total");
        lcd_result_total->setGeometry(QRect(20, 10, 301, 71));
        lcd_result_total->setFont(font1);
        lcd_result_total->setAutoFillBackground(false);
        lcd_result_total->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 36, 36);"));
        lcd_result_total->setFrameShape(QFrame::Shape::StyledPanel);
        lcd_result_total->setFrameShadow(QFrame::Shadow::Raised);
        lcd_result_total->setDigitCount(10);
        lcd_result_total->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        lcd_result_cost = new QLCDNumber(centralwidget);
        lcd_result_cost->setObjectName("lcd_result_cost");
        lcd_result_cost->setGeometry(QRect(180, 90, 141, 41));
        lcd_result_cost->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 36, 36);"));
        lcd_result_cost->setDigitCount(10);
        lcd_result_cost->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        cost_price = new QLabel(centralwidget);
        cost_price->setObjectName("cost_price");
        cost_price->setGeometry(QRect(20, 110, 141, 17));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        cost_price->setFont(font2);
        cost_price->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        input_hours = new QSpinBox(centralwidget);
        input_hours->setObjectName("input_hours");
        input_hours->setGeometry(QRect(180, 210, 55, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(input_hours->sizePolicy().hasHeightForWidth());
        input_hours->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setStyleStrategy(QFont::PreferAntialias);
        input_hours->setFont(font3);
        input_hours->setAcceptDrops(false);
        input_hours->setToolTipDuration(0);
        input_hours->setAutoFillBackground(false);
        input_hours->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgb(77, 77, 77);\n"
"            padding-right: 5px;  \n"
"            text-align: right; \n"
"          "));
        input_hours->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        input_hours->setMinimum(0);
        input_hours->setMaximum(999);
        input_hours->setValue(0);
        text_time_hours = new QLabel(centralwidget);
        text_time_hours->setObjectName("text_time_hours");
        text_time_hours->setGeometry(QRect(240, 210, 21, 17));
        text_time_hours->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        text_time_hours->setFont(font1);
        text_time_hours->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        input_minutes = new QSpinBox(centralwidget);
        input_minutes->setObjectName("input_minutes");
        input_minutes->setGeometry(QRect(260, 210, 55, 21));
        sizePolicy.setHeightForWidth(input_minutes->sizePolicy().hasHeightForWidth());
        input_minutes->setSizePolicy(sizePolicy);
        input_minutes->setFont(font3);
        input_minutes->setAcceptDrops(false);
        input_minutes->setToolTipDuration(0);
        input_minutes->setAutoFillBackground(false);
        input_minutes->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgb(77, 77, 77);\n"
"            padding-right: 5px;\n"
"            text-align: right; \n"
"          "));
        input_minutes->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        input_minutes->setMinimum(0);
        input_minutes->setMaximum(999);
        input_minutes->setValue(0);
        text_time_minuts = new QLabel(centralwidget);
        text_time_minuts->setObjectName("text_time_minuts");
        text_time_minuts->setGeometry(QRect(320, 210, 31, 17));
        text_time_minuts->setFont(font1);
        text_time_minuts->setStyleSheet(QString::fromUtf8("\n"
"          color: rgb(255, 255, 255);\n"
"          text-align: right; \n"
"          "));
        input_gram = new QSpinBox(centralwidget);
        input_gram->setObjectName("input_gram");
        input_gram->setGeometry(QRect(230, 240, 85, 20));
        sizePolicy.setHeightForWidth(input_gram->sizePolicy().hasHeightForWidth());
        input_gram->setSizePolicy(sizePolicy);
        input_gram->setFont(font3);
        input_gram->setAcceptDrops(false);
        input_gram->setToolTipDuration(0);
        input_gram->setAutoFillBackground(false);
        input_gram->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgb(77, 77, 77);\n"
"            padding-right: 15px;  \n"
"            text-align: right;                                                                                                                         "));
        input_gram->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        input_gram->setMinimum(0);
        input_gram->setMaximum(99999);
        input_gram->setValue(0);
        input_things = new QSpinBox(centralwidget);
        input_things->setObjectName("input_things");
        input_things->setGeometry(QRect(230, 270, 85, 20));
        sizePolicy.setHeightForWidth(input_things->sizePolicy().hasHeightForWidth());
        input_things->setSizePolicy(sizePolicy);
        input_things->setFont(font3);
        input_things->setAcceptDrops(false);
        input_things->setToolTipDuration(0);
        input_things->setAutoFillBackground(false);
        input_things->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgb(77, 77, 77);\n"
"            padding-right: 15px;\n"
"            text-align: right; \n"
"          "));
        input_things->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        input_things->setMinimum(0);
        input_things->setMaximum(100000);
        input_things->setValue(0);
        input_mod = new QDoubleSpinBox(centralwidget);
        input_mod->setObjectName("input_mod");
        input_mod->setGeometry(QRect(220, 330, 95, 20));
        sizePolicy.setHeightForWidth(input_mod->sizePolicy().hasHeightForWidth());
        input_mod->setSizePolicy(sizePolicy);
        input_mod->setFont(font3);
        input_mod->setAcceptDrops(false);
        input_mod->setToolTipDuration(0);
        input_mod->setAutoFillBackground(false);
        input_mod->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgb(77, 77, 77);\n"
"            padding-right: 15px;\n"
"            text-align: right; \n"
"          "));
        input_mod->setInputMethodHints(Qt::InputMethodHint::ImhFormattedNumbersOnly);
        input_mod->setDecimals(2);
        input_mod->setMinimum(0.000000000000000);
        input_mod->setMaximum(100000.000000000000000);
        input_mod->setSingleStep(1.000000000000000);
        input_mod->setValue(0.000000000000000);
        input_post = new QDoubleSpinBox(centralwidget);
        input_post->setObjectName("input_post");
        input_post->setGeometry(QRect(220, 360, 95, 20));
        sizePolicy.setHeightForWidth(input_post->sizePolicy().hasHeightForWidth());
        input_post->setSizePolicy(sizePolicy);
        input_post->setFont(font3);
        input_post->setAcceptDrops(false);
        input_post->setToolTipDuration(0);
        input_post->setAutoFillBackground(false);
        input_post->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgb(77, 77, 77);\n"
"            text-align: right; \n"
"            padding-right: 15px;\n"
"          "));
        input_post->setInputMethodHints(Qt::InputMethodHint::ImhFormattedNumbersOnly);
        input_post->setDecimals(2);
        input_post->setMinimum(0.000000000000000);
        input_post->setMaximum(100000.000000000000000);
        input_post->setSingleStep(1.000000000000000);
        input_post->setValue(0.000000000000000);
        text_gram = new QLabel(centralwidget);
        text_gram->setObjectName("text_gram");
        text_gram->setGeometry(QRect(320, 240, 31, 17));
        text_gram->setFont(font1);
        text_gram->setStyleSheet(QString::fromUtf8("\n"
"          color: rgb(255, 255, 255);\n"
"          text-align: right; \n"
"          "));
        text_things = new QLabel(centralwidget);
        text_things->setObjectName("text_things");
        text_things->setGeometry(QRect(320, 270, 31, 17));
        text_things->setFont(font1);
        text_things->setStyleSheet(QString::fromUtf8("\n"
"          color: rgb(255, 255, 255);\n"
"          text-align: right; \n"
"          "));
        text_rub_mod = new QLabel(centralwidget);
        text_rub_mod->setObjectName("text_rub_mod");
        text_rub_mod->setGeometry(QRect(320, 330, 31, 17));
        text_rub_mod->setFont(font1);
        text_rub_mod->setStyleSheet(QString::fromUtf8("\n"
"          color: rgb(255, 255, 255);\n"
"          text-align: right; \n"
"          "));
        text_rub_post = new QLabel(centralwidget);
        text_rub_post->setObjectName("text_rub_post");
        text_rub_post->setGeometry(QRect(320, 360, 31, 17));
        text_rub_post->setFont(font1);
        text_rub_post->setStyleSheet(QString::fromUtf8("\n"
"          color: rgb(255, 255, 255);\n"
"          text-align: right; \n"
"          "));
        ico_rub = new QLabel(centralwidget);
        ico_rub->setObjectName("ico_rub");
        ico_rub->setGeometry(QRect(330, 50, 31, 31));
        ico_rub->setPixmap(QPixmap(QString::fromUtf8(":/img/rubl.png")));
        ico_rub->setScaledContents(true);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 130, 331, 31));
        frame->setFrameShape(QFrame::Shape::HLine);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame->setLineWidth(2);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(20, 300, 331, 31));
        frame_2->setFrameShape(QFrame::Shape::HLine);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        frame_2->setLineWidth(2);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 400, 331, 41));
        buttons = new QHBoxLayout(layoutWidget);
        buttons->setObjectName("buttons");
        buttons->setContentsMargins(0, 0, 0, 0);
        get_result_btn = new QPushButton(layoutWidget);
        get_result_btn->setObjectName("get_result_btn");
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setKerning(true);
        font4.setStyleStrategy(QFont::PreferAntialias);
        get_result_btn->setFont(font4);
        get_result_btn->setAcceptDrops(true);
        get_result_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 80, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/calc.png"), QSize(), QIcon::Normal, QIcon::Off);
        get_result_btn->setIcon(icon1);
        get_result_btn->setIconSize(QSize(20, 20));

        buttons->addWidget(get_result_btn);

        exit_btn = new QPushButton(layoutWidget);
        exit_btn->setObjectName("exit_btn");
        exit_btn->setFont(font1);
        exit_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 80, 0);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit_btn->setIcon(icon2);
        exit_btn->setIconSize(QSize(20, 20));

        buttons->addWidget(exit_btn);

        modeling = new QLabel(centralwidget);
        modeling->setObjectName("modeling");
        modeling->setGeometry(QRect(20, 330, 141, 17));
        modeling->setFont(font1);
        modeling->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        post_print = new QLabel(centralwidget);
        post_print->setObjectName("post_print");
        post_print->setEnabled(false);
        post_print->setGeometry(QRect(20, 360, 121, 17));
        post_print->setFont(font1);
        post_print->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Calc3DbyRisen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Calc3DbyRisen);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 373, 22));
        settings = new QMenu(menubar);
        settings->setObjectName("settings");
        pressets = new QMenu(settings);
        pressets->setObjectName("pressets");
        help = new QMenu(menubar);
        help->setObjectName("help");
        help->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        help->setAutoFillBackground(false);
        help->setTearOffEnabled(false);
        help->setSeparatorsCollapsible(false);
        Calc3DbyRisen->setMenuBar(menubar);

        menubar->addAction(settings->menuAction());
        menubar->addAction(help->menuAction());
        settings->addAction(settings_2);
        settings->addAction(pressets->menuAction());
        settings->addSeparator();
        settings->addSeparator();
        settings->addAction(action_3);
        pressets->addAction(add_preset);
        pressets->addAction(del_printer);
        help->addAction(check_update);
        help->addAction(formula);
        help->addAction(about);

        retranslateUi(Calc3DbyRisen);

        printer_menu->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Calc3DbyRisen);
    } // setupUi

    void retranslateUi(QMainWindow *Calc3DbyRisen)
    {
        Calc3DbyRisen->setWindowTitle(QCoreApplication::translate("MainWindow", "Calc3D by Risen v.1.0.0", nullptr));
        check_update->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        formula->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\272 \321\200\320\260\321\201\321\207\320\270\321\202\321\213\320\262\320\260\320\265\321\202\321\201\321\217 \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        about->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\265", nullptr));
        settings_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        add_preset->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\270\320\275\321\202\320\265\321\200", nullptr));
        del_printer->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214/\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\321\200\320\270\320\275\321\202\320\265\321\200", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        quantity->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\215\320\272\320\267\320\265\320\274\320\277\320\273\321\217\321\200\320\276\320\262", nullptr));
        weight->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\201\320\260 \320\264\320\265\321\202\320\260\320\273\320\270", nullptr));
        time_print->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\277\320\265\321\207\320\260\321\202\320\270", nullptr));
        printer->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\275\321\202\320\265\321\200", nullptr));
        printer_menu->setCurrentText(QString());
        printer_menu->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\277\321\200\320\270\320\275\321\202\320\265\321\200\320\260", nullptr));
        cost_price->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\320\261\320\265\321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        text_time_hours->setText(QCoreApplication::translate("MainWindow", "\321\207.", nullptr));
        text_time_minuts->setText(QCoreApplication::translate("MainWindow", "\320\274\320\270\320\275.", nullptr));
        text_gram->setText(QCoreApplication::translate("MainWindow", "\320\263.", nullptr));
        text_things->setText(QCoreApplication::translate("MainWindow", "\321\210\321\202.", nullptr));
        text_rub_mod->setText(QCoreApplication::translate("MainWindow", "\321\200\321\203\320\261.", nullptr));
        text_rub_post->setText(QCoreApplication::translate("MainWindow", "\321\200\321\203\320\261.", nullptr));
        ico_rub->setText(QString());
        get_result_btn->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        exit_btn->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        modeling->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        post_print->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260", nullptr));
        settings->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        pressets->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\321\201\320\265\321\202\321\213 \320\277\321\200\320\270\320\275\321\202\320\265\321\200\320\260", nullptr));
        help->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
