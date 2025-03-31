#include "printer_settings.h"

#include "ui/ui_printer_settings.h"

PrinterSettingsDialog::PrinterSettingsDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::PrinterSettingsDialog) {
  ui->setupUi(this);
  setFixedSize(size());

  connect(ui->save, &QPushButton::clicked, this, [this]() {
    double tarif = ui->input_tarif->value();
    double qTrash = ui->input_q_trash->value();
    double pricePlastik = ui->input_price_pastik->value();
    double overprice = ui->input_overprice->value();
    int weightPlastik = ui->plastik_menu->value();

    emit settingsSaved(tarif, qTrash, pricePlastik, overprice, weightPlastik);
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
  if (settings.contains("pricePlastik"))
    ui->input_price_pastik->setValue(settings.value("pricePlastik").toDouble());
  if (settings.contains("overprice"))
    ui->input_overprice->setValue(settings.value("overprice").toDouble());
  if (settings.contains("weightPlastik"))
    ui->plastik_menu->setValue(settings.value("weightPlastik").toInt());
}

PrinterSettingsDialog::~PrinterSettingsDialog() { delete ui; }