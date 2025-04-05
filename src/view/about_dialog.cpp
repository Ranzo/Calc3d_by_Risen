#include "about_dialog.h"

#include "ui/ui_about.h"

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent), ui(new Ui::About) {
  ui->setupUi(this);
  setFixedSize(size());
}

AboutDialog::~AboutDialog() { delete ui; }