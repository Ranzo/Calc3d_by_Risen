#include "add_printer.h"

#include "ui/ui_add_printer.h"

AddPrinterDialog::AddPrinterDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::AddPrinter) {
  ui->setupUi(this);
  setFixedSize(size());

  // Валидатор целые числа 0-9,999,999
  QRegularExpression integerRegex("^(0|[1-9]\\d{0,6})$");
  // Валидатор дробные 0.00 - 9,999,999.99
  QRegularExpression doubleRegex("^(0|([1-9]\\d{0,6}))([.,]\\d{2})?$");

  ui->input_power->setValidator(
      new QRegularExpressionValidator(integerRegex, this));
  ui->input_age->setValidator(
      new QRegularExpressionValidator(doubleRegex, this));
  ui->input_price->setValidator(
      new QRegularExpressionValidator(doubleRegex, this));

  connect(ui->actButton, &QPushButton::clicked, this, [this]() {
    QString name = ui->input_name->text().trimmed();

    bool checkPower, checkPrice, checkAge;
    double power = ui->input_power->text().toInt(&checkPower);
    double age = ui->input_age->text().replace(",", ".").toDouble(&checkAge);
    double cost =
        ui->input_price->text().replace(",", ".").toDouble(&checkPrice);

    if (name.isEmpty() || !checkPower || !checkAge || !checkPrice) {
      QMessageBox::warning(this, "Ошибка", "Проверьте корректность данных");
      return;
    }

    if (status == PresetDialogStatus::Edit)
      emit printerEdited(oldName, name, power, age, cost);
    else
      emit printerAdded(name, power, age, cost);
    close();
  });

  connect(ui->rejectButton, &QPushButton::clicked, this, &QDialog::reject);
}

void AddPrinterDialog::setAddMode() {
  status = PresetDialogStatus::Add;
  setWindowTitle("Добавить принтер");

  ui->input_name->clear();
  ui->input_power->clear();
  ui->input_age->clear();
  ui->input_price->clear();
}

void AddPrinterDialog::setEditMode(QHash<QString, QVariant>& preset) {
  status = PresetDialogStatus::Edit;
  setWindowTitle("Изменить принтер");

  if (preset.contains("name")) {
    ui->input_name->setText(preset["name"].toString());
    oldName = preset["name"].toString();
  }
  if (preset.contains("power"))
    ui->input_power->setText(QString::number(preset["power"].toInt()));
  if (preset.contains("age"))
    ui->input_age->setText(QString::number(preset["age"].toInt()));
  if (preset.contains("cost"))
    ui->input_price->setText(
        QString::number(preset["cost"].toDouble(), 'f', 2));
}

AddPrinterDialog::~AddPrinterDialog() { delete ui; }