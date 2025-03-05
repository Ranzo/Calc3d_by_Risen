#include "add_preset.h"

#include "ui/ui_add_preset.h"

AddPresetDialog::AddPresetDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddPrinter) {
  ui->setupUi(this);
  setWindowIcon(QIcon("img/logo-1.png"));
  // TODO validators
  //   setupValidators();

  connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
    // TODO save new printer settings
    qDebug() << "SAVE SETTINGS";
  });
  connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::reject);
}

AddPresetDialog::~AddPresetDialog() { delete ui; }

void AddPresetDialog::setupValidators() {
  // TODO make validators
  qDebug() << "SET VALIDATORS";
  //   ui->input_power_3->setValidator(SMTH);  // Мощность
  //   ui->input_power->setValidator(SMTH);    // Срок службы

  //   ui->input_power_2->setValidator(SMTH);  // Стоимость
}