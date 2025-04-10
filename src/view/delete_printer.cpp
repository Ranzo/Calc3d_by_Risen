#include "delete_printer.h"

#include "ui/ui_del_printer.h"

DeletePrinterDialog::DeletePrinterDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::DelPreset) {
  ui->setupUi(this);
  setFixedSize(size());
  setupTable();

  connect(ui->delete_button, &QPushButton::clicked, this, [this]() {
    const int row = ui->tableWidget->currentRow();
    if (row >= 0) {
      const QString name = ui->tableWidget->item(row, 0)->text();
      emit deleteRequested(name);
    }
  });

  connect(ui->edit_button, &QPushButton::clicked, this, [this]() {
    const int row = ui->tableWidget->currentRow();
    if (row >= 0) {
      const QString name = ui->tableWidget->item(row, 0)->text();
      emit editRequested(name);
    }
  });

  connect(ui->reject_button, &QPushButton::clicked, this, &QDialog::reject);
}

DeletePrinterDialog::~DeletePrinterDialog() { delete ui; }

void DeletePrinterDialog::setupTable() {
  ui->tableWidget->setColumnCount(1);
  ui->tableWidget->setHorizontalHeaderLabels({"Выберите принтер"});
  ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
  ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

void DeletePrinterDialog::loadPresets(const QList<QString> &data) {
  ui->tableWidget->clearContents();
  ui->tableWidget->setRowCount(0);

  ui->tableWidget->setRowCount(data.size());

  for (int row = 0; row < data.size(); ++row) {
    QTableWidgetItem *item = new QTableWidgetItem(data[row]);
    ui->tableWidget->setItem(row, 0, item);
  }

  ui->tableWidget->resizeColumnsToContents();
}