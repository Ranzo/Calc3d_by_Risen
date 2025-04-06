#include "delete_list.h"

#include "ui/ui_del_list.h"

DeletePlasticDialog::DeletePlasticDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::DelList) {
  ui->setupUi(this);
  setFixedSize(size());
  setupTable();

  connect(ui->close_button, &QPushButton::clicked, this, &QDialog::reject);
}

DeletePlasticDialog::~DeletePlasticDialog() { delete ui; }

void DeletePlasticDialog::setupTable() {
  ui->tableWidget->setColumnCount(3);
  ui->tableWidget->setHorizontalHeaderLabels({"Название", "", ""});
  ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

  ui->tableWidget->horizontalHeader()->setSectionResizeMode(
      0, QHeaderView::Stretch);
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,
                                                            QHeaderView::Fixed);
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(2,
                                                            QHeaderView::Fixed);

  QPushButton editButton("Изменить");   // TODO заменить фейк иконками
  QPushButton deleteButton("Удалить");  // TODO заменить фейк иконками
  const int editWidth = editButton.sizeHint().width() + 10;
  const int deleteWidth = deleteButton.sizeHint().width() + 10;

  ui->tableWidget->setColumnWidth(1, editWidth);
  ui->tableWidget->setColumnWidth(2, deleteWidth);

  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableWidget->horizontalHeader()->setSectionsMovable(false);
  ui->tableWidget->horizontalHeader()->setSectionsClickable(false);
}

void DeletePlasticDialog::loadList(ElemType type, const QList<QString> &data) {
  elemType = type;
  if (elemType == ElemType::Printer) setWindowTitle("Настройка принтеров");
  if (elemType == ElemType::Plastic) setWindowTitle("Настройка катушек");

  ui->tableWidget->clearContents();
  ui->tableWidget->setRowCount(data.size());

  for (int row = 0; row < data.size(); ++row) {
    QTableWidgetItem *item = new QTableWidgetItem(data[row]);
    ui->tableWidget->setItem(row, 0, item);

    QPushButton *editButton = new QPushButton("Изменить");
    connect(editButton, &QPushButton::clicked, this, [this, row]() {
      QString name = ui->tableWidget->item(row, 0)->text();

      if (elemType == ElemType::Printer)
        emit editPrinterRequested(name);
      else if (elemType == ElemType::Plastic)
        emit editPlasticRequested(name);
    });

    ui->tableWidget->setCellWidget(row, 1, editButton);

    QPushButton *deleteButton = new QPushButton("Удалить");
    connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
      QString name = ui->tableWidget->item(row, 0)->text();
      if (elemType == ElemType::Printer)
        emit deletePrinterRequested(name);
      else if (elemType == ElemType::Plastic)
        emit deletePlasticRequested(name);
    });
    ui->tableWidget->setCellWidget(row, 2, deleteButton);
  }
}