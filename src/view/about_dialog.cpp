#include "about_dialog.h"
#include "ui/ui_about.h"

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent), ui(new Ui::About) {
  ui->setupUi(this);

  setWindowIcon(QIcon("img/logo-1.png"));
}

AboutDialog::~AboutDialog() { delete ui; }