#ifndef EDITPRINTERDIALOG_H
#define EDITPRINTERDIALOG_H

#include <QDialog>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QMessageBox>

#include "ui/ui_edit_preset.h"

namespace Ui {
class EditPrinter;
}

class EditPresetDialog : public QDialog {
  Q_OBJECT

 public:
  explicit EditPresetDialog(QWidget *parent = nullptr);
  ~EditPresetDialog();

  QString getPresetName() const { return ui->input_name->toPlainText(); }

  double getPower() const { return ui->input_power->value(); }

  double getLifespan() const { return ui->input_age->value(); }

  double getPrinterPrice() const { return ui->input_price->value(); }

  void setPreset(QHash<QString, QVariant> &preset);

 signals:
  void printerEdited(const QString &oldName, const QString &newName,
                     double power, double age, double cost);

 private:
  Ui::EditPrinter *ui;
  QString oldName;
};

#endif  // EDITPRINTERDIALOG_H