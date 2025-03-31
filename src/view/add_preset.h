#ifndef ADDPRINTERDIALOG_H
#define ADDPRINTERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QShowEvent>

#include "ui/ui_add_preset.h"

namespace Ui {
class AddPrinter;
}

class AddPresetDialog : public QDialog {
  Q_OBJECT

 public:
  explicit AddPresetDialog(QWidget *parent = nullptr);
  ~AddPresetDialog();

  QString getPresetName() const { return ui->input_name->toPlainText(); }

  double getPower() const { return ui->input_power->value(); }

  double getLifespan() const { return ui->input_age->value(); }

  double getPrinterPrice() const { return ui->input_price->value(); }

 signals:
  void printerAdded(const QString &name, double power, double age, double cost);

 protected:
  void showEvent(QShowEvent *event) override;

 private:
  Ui::AddPrinter *ui;

  void resetForm();
};

#endif  // ADDPRINTERDIALOG_H