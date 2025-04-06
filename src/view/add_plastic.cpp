#include "add_plastic.h"

#include "ui/ui_add_plastic.h"

AddPlasticDialog::AddPlasticDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::AddPlastic) {
  ui->setupUi(this);
  setFixedSize(size());

  // Валидатор целые числа 0-9,999,999
  QRegularExpression integerRegex("^(0|[1-9]\\d{0,6})$");
  ui->input_weight->setValidator(
      new QRegularExpressionValidator(integerRegex, this));

  // Валидатор дробные 0.00 - 9,999,999.99
  QRegularExpression doubleRegex("^(0|([1-9]\\d{0,6}))([.,]\\d{2})?$");
  ui->input_price->setValidator(
      new QRegularExpressionValidator(doubleRegex, this));

  connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
    QString name = ui->input_name->text().trimmed();

    bool checkWeight, checkPrice;
    int weight = ui->input_weight->text().toInt(&checkWeight);
    double cost =
        ui->input_price->text().replace(",", ".").toDouble(&checkPrice);

    if (name.isEmpty() || !checkWeight || !checkPrice) {
      QMessageBox::warning(this, "Ошибка", "Проверьте корректность данных");
      return;
    }

    if (status == PlasticDialogStatus::Edit)
      emit plasticEdited(oldName, name, weight, cost);
    else
      emit plasticAdded(name, weight, cost);

    close();
  });

  connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::reject);
}

void AddPlasticDialog::setAddMode() {
  status = PlasticDialogStatus::Add;
  setWindowTitle("Добавить катушку");
  ui->input_name->clear();
  ui->input_weight->clear();
  ui->input_price->clear();
}

void AddPlasticDialog::setEditMode(QHash<QString, QVariant>& preset) {
  status = PlasticDialogStatus::Edit;
  setWindowTitle("Изменить катушку");

  if (preset.contains("name")) {
    ui->input_name->setText(preset["name"].toString());
    oldName = preset["name"].toString();
  }
  if (preset.contains("weight"))
    ui->input_weight->setText(QString::number(preset["weight"].toInt()));
  if (preset.contains("cost"))
    ui->input_price->setText(
        QString::number(preset["cost"].toDouble(), 'f', 2));
}

AddPlasticDialog::~AddPlasticDialog() { delete ui; }