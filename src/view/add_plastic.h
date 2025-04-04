#ifndef ADDPLASTICDIALOG_H
#define ADDPLASTICDIALOG_H

#include <QDialog>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QMessageBox>
#include <QShowEvent>

#include "ui/ui_add_plastic.h"

namespace Ui {
class AddPlastic;
}

enum class PlasticDialogStatus { Add, Edit };

class AddPlasticDialog : public QDialog {
  Q_OBJECT

 public:
  explicit AddPlasticDialog(QWidget *parent = nullptr);
  ~AddPlasticDialog();

  QString getPresetName() const { return ui->input_name->toPlainText(); }

  double getWeight() const { return ui->input_weight->value(); }

  double getPlasticPrice() const { return ui->input_price->value(); }

  void setEditMode(QHash<QString, QVariant> &preset);
  void setAddMode();

 signals:
  void plasticAdded(const QString &name, double weight, double cost);
  void plasticEdited(const QString &oldName, const QString &newName,
                     double weight, double cost);

 private:
  Ui::AddPlastic *ui;
  QString oldName;
  PlasticDialogStatus status =  PlasticDialogStatus::Add;
};

#endif  // ADDPLASTICDIALOG_H