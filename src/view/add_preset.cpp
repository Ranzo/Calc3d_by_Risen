#include "add_preset.h"

#include "ui/ui_add_preset.h"

AddPresetDialog::AddPresetDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::AddPrinter) {
  ui->setupUi(this);
  setFixedSize(size());

  connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
    QString name = ui->input_name->toPlainText().trimmed();
    double power = ui->input_power->value();
    double age = ui->input_age->value();
    double cost = ui->input_price->value();

    if (name.isEmpty())
      QMessageBox::warning(this, "Ошибка", "Заполните все поля");
    else {
      emit printerAdded(name, power, age, cost);
      close();
    }
  });

  connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::reject);
}

void AddPresetDialog::resetForm() {
  ui->input_name->clear();
  ui->input_power->setValue(0.0);
  ui->input_age->setValue(0.0);
  ui->input_price->setValue(0.0);
}

void AddPresetDialog::showEvent(QShowEvent* event) {
  QDialog::showEvent(event);
  resetForm();
}

AddPresetDialog::~AddPresetDialog() { delete ui; }