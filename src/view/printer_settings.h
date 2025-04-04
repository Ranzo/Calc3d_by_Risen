#ifndef PrinterSettingsDialog_H
#define PrinterSettingsDialog_H

#include <QDialog>
#include <QDoubleValidator>

#include "ui/ui_printer_settings.h"

namespace Ui {
class PrinterSettingsDialog;
}

class PrinterSettingsDialog : public QDialog {
  Q_OBJECT

 public:
  explicit PrinterSettingsDialog(QWidget *parent = nullptr);
  ~PrinterSettingsDialog();

  // Методы доступа к данным
  inline double getTariff() const { return ui->input_tarif->value(); }

  inline double getRejectCoefficient() const {
    return ui->input_q_trash->value();
  }

  inline double getFilamentCost() const {
    return ui->input_price_pastik->value();
  }

  inline double getMarkupPercent() const {
    return ui->input_overprice->value();
  }

  inline int getFilamentWeight() const { return ui->plastik_menu->value(); }

  // Методы установки значений
  inline void setTariff(double value) { ui->input_tarif->setValue(value); }

  inline void setRejectCoefficient(double value) {
    ui->input_q_trash->setValue(value);
  }

  inline void setFilamentCost(double value) {
    ui->input_price_pastik->setValue(value);
  }

  inline void setMarkupPercent(double value) {
    ui->input_overprice->setValue(value);
  }

  inline void setFilamentWeight(int value) {
    ui->plastik_menu->setValue(value);
  }

  void loadSettings(QHash<QString, QVariant> settings);

 signals:
  void settingsSaved(double tarif, double qTrash, double pricePlastik,
                     double overprice, int weightPlastik);

 private:
  Ui::PrinterSettingsDialog *ui;
};

#endif  // PrinterSettingsDialog_H