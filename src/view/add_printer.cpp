#include "add_printer.h"

#include "ui/ui_add_printer.h"

AddPrinterDialog::AddPrinterDialog(QWidget* parent)
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
      if (status == PresetDialogStatus::Edit)
        emit printerEdited(oldName, name, power, age, cost);
      else
        emit printerAdded(name, power, age, cost);
      close();
    }
  });

  connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::reject);
}

void AddPrinterDialog::setAddMode() {
  status = PresetDialogStatus::Add;
  setWindowTitle("Добавить принтер");

  ui->input_name->clear();
  ui->input_power->setValue(0.0);
  ui->input_age->setValue(0.0);
  ui->input_price->setValue(0.0);
}

void AddPrinterDialog::setEditMode(QHash<QString, QVariant>& preset) {
  status = PresetDialogStatus::Edit;
  setWindowTitle("Изменить принтер");

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

AddPrinterDialog::~AddPrinterDialog() { delete ui; }