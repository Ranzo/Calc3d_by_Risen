#ifndef PrinterSettingsDialog_H
#define PrinterSettingsDialog_H

#include <QDialog>
#include <QDoubleValidator>
#include <QMessageBox>

#include "ui/ui_printer_settings.h"

namespace Ui {
class PrinterSettingsDialog;
}

class PrinterSettingsDialog : public QDialog {
  Q_OBJECT

 public:
  explicit PrinterSettingsDialog(QWidget *parent = nullptr);
  ~PrinterSettingsDialog();

  inline double getTariff() const {
    return ui->input_tarif->text().replace(",", ".").toDouble();
  }

  inline double getRejectCoefficient() const {
    return ui->input_q_trash->text().replace(",", ".").toDouble();
  }

  inline double getMarkupPercent() const {
    return ui->input_overprice->text().replace(",", ".").toDouble();
  }

  void loadSettings(QHash<QString, QVariant> settings);

 signals:
  void settingsSaved(double tarif, double qTrash, double overprice);

 private:
  Ui::PrinterSettingsDialog *ui;
};

#endif  // PrinterSettingsDialog_H