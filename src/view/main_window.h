#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <memory>

#include "about_dialog.h"
#include "formula_dialog.h"
#include "update_dialog.h"
#include "printer_settings.h"
#include "delete_preset.h"
#include "add_preset.h"
#include "edit_preset.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  AboutDialog *progInfo;
  FormulaDialog *formulaInfo;
  UpdatesDialog *updateInfo;
  PrinterSettingsDialog *printerSettings;
  AddPresetDialog *addPresetDialog;
  DeletePresetDialog *deletePresetDialog;
  EditPresetDialog *editPresetDialog;
};
#endif  // MAINWINDOW_H
