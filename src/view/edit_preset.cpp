#include "edit_preset.h"

#include "ui/ui_edit_preset.h"

EditPresetDialog::EditPresetDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::EditPrinter) {
  ui->setupUi(this);
  setFixedSize(size());

  connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
    QString newName = ui->input_name->toPlainText().trimmed();
    double power = ui->input_power->value();
    double age = ui->input_age->value();
    double cost = ui->input_price->value();

    if (newName.isEmpty())
      QMessageBox::warning(this, "Ошибка", "Заполните все поля");
    else {
      emit printerEdited(oldName, newName, power, age, cost);
      close();
    }
  });

  connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::reject);
}

void EditPresetDialog::setPreset(QHash<QString, QVariant>& preset) {
  if (preset.contains("name")) {
    ui->input_name->setText(preset["name"].toString());
    oldName = ui->input_name->toPlainText().trimmed();
  }
  if (preset.contains("power"))
    ui->input_power->setValue(preset["power"].toDouble());
  if (preset.contains("age")) ui->input_age->setValue(preset["age"].toInt());
  if (preset.contains("cost"))
    ui->input_price->setValue(preset["cost"].toDouble());
}

EditPresetDialog::~EditPresetDialog() { delete ui; }