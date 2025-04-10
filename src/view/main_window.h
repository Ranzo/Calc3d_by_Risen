#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <memory>

#include "../logic/facade.h"
#include "about_dialog.h"
#include "add_plastic.h"
#include "add_printer.h"
#include "delete_plastic.h"
#include "delete_printer.h"
#include "formula_dialog.h"
#include "printer_settings.h"
#include "update_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(std::shared_ptr<Facade> facade, QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  AboutDialog *progInfo;
  FormulaDialog *formulaInfo;
  UpdatesDialog *updateInfo;
  PrinterSettingsDialog *printerSettings;
  AddPrinterDialog *addPrinterDialog;
  DeletePrinterDialog *deletePrinterDialog;
  AddPlasticDialog *addPlasticDialog;
  DeletePlasticDialog *deletePlasticDialog;

  std::shared_ptr<Facade> facade;

  void refreshPrinterList();
};
#endif  // MAINWINDOW_H
