#include "printer_settings.h"

#include "ui/ui_printer_settings.h"

PrinterSettingsDialog::PrinterSettingsDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::PrinterSettingsDialog) {
  ui->setupUi(this);
  setWindowIcon(QIcon("img/logo-1.png"));

  // TODO валидаторы
  //   setupValidators(SMTH);

  connect(ui->save, &QPushButton::clicked, this, [this]() {
    // TODO save new printer settings
    qDebug() << "SAVE SETTINGS";
  });
  connect(ui->exit, &QPushButton::clicked, this, &QDialog::reject);
}

PrinterSettingsDialog::~PrinterSettingsDialog() { delete ui; }

void PrinterSettingsDialog::setupValidators() {
  // TODO make validators
  qDebug() << "SET VALIDATORS";

  //   ui->input_tarif->setValidator(SMTH);
  //   ui->input_q_trash->setValidator(SMTH);
  //   ui->input_price_pastik->setValidator(SMTH);
  //   ui->input_overprice->setValidator(SMTH);
}