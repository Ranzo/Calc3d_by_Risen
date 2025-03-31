#include "formula_dialog.h"

#include "ui/ui_formula.h"

FormulaDialog::FormulaDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Formula) {
  ui->setupUi(this);
  setFixedSize(size());

  connect(ui->pushButton, &QPushButton::clicked, this, &FormulaDialog::close);
}

FormulaDialog::~FormulaDialog() { delete ui; }

void FormulaDialog::on_pushButton_clicked() { close(); }