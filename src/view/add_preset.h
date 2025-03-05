#ifndef ADDPRINTERDIALOG_H
#define ADDPRINTERDIALOG_H

#include <QDialog>
#include <QDoubleValidator>
#include <QIntValidator>

#include "ui/ui_add_preset.h"

namespace Ui {
class AddPrinter;
}

class AddPresetDialog : public QDialog {
  Q_OBJECT

 public:
  explicit AddPresetDialog(QWidget *parent = nullptr);
  ~AddPresetDialog();

  QString getPresetName() const { return ui->textEdit->toPlainText(); }

  int getPower() const { return ui->input_power_3->toPlainText().toInt(); }

  int getLifespan() const { return ui->input_power->toPlainText().toInt(); }

  double getPrinterCost() const {
    return ui->input_power_2->toPlainText().toDouble();
  }

 private:
  void setupValidators();
  Ui::AddPrinter *ui;
  // QIntValidator *intValidator;
  // QDoubleValidator *doubleValidator;
};

#endif  // ADDPRINTERDIALOG_H