#include "main_window.h"

#include "ui/ui_about.h"
#include "ui/ui_add_printer.h"
#include "ui/ui_del_preset.h"
#include "ui/ui_edit_preset.h"
#include "ui/ui_formula.h"
#include "ui/ui_main_window.h"
#include "ui/ui_settings.h"
#include "ui/ui_settings_preset.h"
#include "ui/ui_updates.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  setWindowTitle("Calc3D");
  setFixedSize(373, 471);
  // menu_window = new MenuWindow(this);
  // game_window = new GameWindow(this);
  // controller = new s21::GameController();

  // lay_out = new QStackedLayout(this);
  // setLayout(lay_out);
  // lay_out->addWidget(menu_window);
  // lay_out->addWidget(game_window);

  // menu_window->setFocus();

  // connect(menu_window, &MenuWindow::signalGame, this,
  // &DesktopView::slotShowGame); connect(menu_window, &MenuWindow::signalExit,
  // this, &DesktopView::slotExit); connect(game_window,
  // &GameWindow::signalExit, this, &DesktopView::slotShowMenu);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
