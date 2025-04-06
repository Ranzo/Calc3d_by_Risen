#ifndef ADDPRINTERDIALOG_H
#define ADDPRINTERDIALOG_H

#include <QDialog>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QMessageBox>
#include <QShowEvent>

#include "ui/ui_add_printer.h"

namespace Ui {
class AddPrinter;
}

enum class PresetDialogStatus { Add, Edit };

class AddPrinterDialog : public QDialog {
  Q_OBJECT

 public:
  explicit AddPrinterDialog(QWidget *parent = nullptr);
  ~AddPrinterDialog();

  QString getPresetName() const { return ui->input_name->text(); }

  int getPower() const { return ui->input_power->text().toInt(); }

  double getLifespan() const {
    return ui->input_age->text().replace(",", ".").toDouble();
  }

  double getPrinterPrice() const {
    return ui->input_price->text().replace(",", ".").toDouble();
  }

  void setEditMode(QHash<QString, QVariant> &preset);
  void setAddMode();

 signals:
  void printerAdded(const QString &name, int power, double age, double cost);
  void printerEdited(const QString &oldName, const QString &newName, int power,
                     double age, double cost);

 private:
  Ui::AddPrinter *ui;
  QString oldName;
  PresetDialogStatus status = PresetDialogStatus::Add;
};

#endif  // ADDPRINTERDIALOG_H