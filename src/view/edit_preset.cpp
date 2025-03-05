#include "edit_preset.h"

#include "ui/ui_edit_preset.h"

EditPresetDialog::EditPresetDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::EditPreset) {
  ui->setupUi(this);
  setWindowIcon(QIcon("img/logo-1.png"));

  connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
    // TODO save new printer settings
    qDebug() << "SAVE SETTINGS";
  });
  connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::reject);
}

EditPresetDialog::~EditPresetDialog() { delete ui; }
