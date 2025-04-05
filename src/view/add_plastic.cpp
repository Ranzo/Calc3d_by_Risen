#include "add_plastic.h"
#include "ui/ui_add_plastic.h"

AddPlasticDialog::AddPlasticDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::AddPlastic) {
  ui->setupUi(this);
  setFixedSize(size());

  connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
    QString name = ui->input_name->toPlainText().trimmed();
    double weight = ui->input_weight->value();
    double cost = ui->input_price->value();

    if (name.isEmpty())
      QMessageBox::warning(this, "Ошибка", "Заполните все поля");
    else {
      if (status == PlasticDialogStatus::Edit)
        emit plasticEdited(oldName, name, weight, cost);
      else
        emit plasticAdded(name, weight, cost);
      close();
    }
  });

  connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::reject);
}

void AddPlasticDialog::setAddMode() {
  status = PlasticDialogStatus::Add;

  ui->input_name->clear();
  ui->input_weight->setValue(0.0);
  ui->input_price->setValue(0.0);
}

void AddPlasticDialog::setEditMode(QHash<QString, QVariant>& preset) {
  status = PlasticDialogStatus::Edit;

  if (preset.contains("name")) {
    ui->input_name->setText(preset["name"].toString());
    oldName = ui->input_name->toPlainText().trimmed();
  }
  if (preset.contains("weight"))
    ui->input_weight->setValue(preset["weight"].toDouble());
  if (preset.contains("cost"))
    ui->input_price->setValue(preset["cost"].toDouble());
}

AddPlasticDialog::~AddPlasticDialog() { delete ui; }