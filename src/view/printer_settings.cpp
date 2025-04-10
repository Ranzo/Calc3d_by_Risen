#include "printer_settings.h"

#include "ui/ui_printer_settings.h"

PrinterSettingsDialog::PrinterSettingsDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::PrinterSettingsDialog) {
  ui->setupUi(this);
  setFixedSize(size());

  // Валидатор дробные 0.00 - 9,999,999.99
  QRegularExpression doubleRegex("^(0|([1-9]\\d{0,6}))([.,]\\d{2})?$");

  ui->input_tarif->setValidator(
      new QRegularExpressionValidator(doubleRegex, this));
  ui->input_q_trash->setValidator(
      new QRegularExpressionValidator(doubleRegex, this));
  ui->input_overprice->setValidator(
      new QRegularExpressionValidator(doubleRegex, this));

  connect(ui->save, &QPushButton::clicked, this, [this]() {
    bool checkTarif, checkQTrash, checkOverprice;

    double tarif =
        ui->input_tarif->text().replace(",", ".").toDouble(&checkTarif);
    double qTrash =
        ui->input_q_trash->text().replace(",", ".").toDouble(&checkQTrash);
    double overprice =
        ui->input_overprice->text().replace(",", ".").toDouble(&checkOverprice);

    if (!checkTarif || !checkQTrash || !checkOverprice) {
      QMessageBox::warning(this, "Ошибка", "Проверьте корректность данных");
      return;
    }

    emit settingsSaved(tarif, qTrash, overprice);
    accept();
  });

  connect(ui->exit, &QPushButton::clicked, this, &QDialog::reject);
}

void PrinterSettingsDialog::loadSettings(QHash<QString, QVariant> settings) {
  if (settings.isEmpty()) {
    qWarning() << "Failed to load settings: empty data";
    return;
  }
  if (settings.contains("tarif"))
    ui->input_tarif->setText(QString::number(settings["tarif"].toDouble()));
  if (settings.contains("qTrash"))
    ui->input_q_trash->setText(QString::number(settings["qTrash"].toDouble()));
  if (settings.contains("overprice"))
    ui->input_overprice->setText(
        QString::number(settings["overprice"].toDouble()));
}

PrinterSettingsDialog::~PrinterSettingsDialog() { delete ui; }