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
  inline double getTariff() const {
    return ui->input_tarif->toPlainText().toDouble();
  }

  inline double getRejectCoefficient() const {
    return ui->input_q_trash->toPlainText().toDouble();
  }

  inline double getFilamentCost() const {
    return ui->input_price_pastik->toPlainText().toDouble();
  }

  inline double getMarkupPercent() const {
    return ui->input_overprice->toPlainText().toDouble();
  }

  inline int getFilamentWeight() const {
    return ui->plastik_menu->currentText().toInt();
  }

  // Методы установки значений
  inline void setTariff(double value) {
    ui->input_tarif->setPlainText(QString::number(value));
  }

  inline void setRejectCoefficient(double value) {
    ui->input_q_trash->setPlainText(QString::number(value));
  }

  inline void setFilamentCost(double value) {
    ui->input_price_pastik->setPlainText(QString::number(value));
  }

  inline void setMarkupPercent(double value) {
    ui->input_overprice->setPlainText(QString::number(value));
  }

  inline void setFilamentWeight(int value) {
    int index = ui->plastik_menu->findText(QString::number(value));
    if (index != -1) ui->plastik_menu->setCurrentIndex(index);
  }

 private:
  Ui::PrinterSettingsDialog *ui;

  // QDoubleValidator *doubleValidator;
  void setupValidators();
};

#endif  // PrinterSettingsDialog_H