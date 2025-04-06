#include "printer_settings.h"

#include "ui/ui_printer_settings.h"

PrinterSettingsDialog::PrinterSettingsDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::PrinterSettingsDialog) {
  ui->setupUi(this);
  setFixedSize(size());

  connect(ui->save, &QPushButton::clicked, this, [this]() {
    double tarif = ui->input_tarif->value();
    double qTrash = ui->input_q_trash->value();
    double overprice = ui->input_overprice->value();

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
    ui->input_tarif->setValue(settings.value("tarif").toDouble());
  if (settings.contains("qTrash"))
    ui->input_q_trash->setValue(settings.value("qTrash").toDouble());
  if (settings.contains("overprice"))
    ui->input_overprice->setValue(settings.value("overprice").toDouble());
}

PrinterSettingsDialog::~PrinterSettingsDialog() { delete ui; }