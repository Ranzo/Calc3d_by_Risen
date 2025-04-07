#include "delete_list.h"

#include <QFile>

#include "ui/ui_del_list.h"

DeleteListDialog::DeleteListDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::DelList) {
  ui->setupUi(this);
  setFixedSize(size());
  setupTable();

  connect(ui->close_button, &QPushButton::clicked, this, &QDialog::reject);
}

DeleteListDialog::~DeleteListDialog() { delete ui; }

void DeleteListDialog::setupTable() {
  ui->tableWidget->setColumnCount(2);
  ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

  ui->tableWidget->setColumnWidth(1, iconSize * 2);

  ui->tableWidget->verticalHeader()->setDefaultSectionSize(iconSize);

  ui->tableWidget->horizontalHeader()->setSectionResizeMode(
      0, QHeaderView::Stretch);
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,
                                                            QHeaderView::Fixed);

  ui->tableWidget->horizontalHeader()->hide();
  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
  ui->tableWidget->horizontalHeader()->setSectionsMovable(false);
  ui->tableWidget->horizontalHeader()->setSectionsClickable(false);
}

void DeleteListDialog::loadList(ElemType type, const QList<QString> &data) {
  elemType = type;
  if (elemType == ElemType::Printer) setWindowTitle("Настройка принтеров");
  if (elemType == ElemType::Plastic) setWindowTitle("Настройка катушек");

  ui->tableWidget->clearContents();
  ui->tableWidget->setRowCount(data.size());

  for (int row = 0; row < data.size(); ++row) {
    QTableWidgetItem *item = new QTableWidgetItem(data[row]);
    ui->tableWidget->setItem(row, 0, item);

    QWidget *buttonsContainer = new QWidget(this);
    QHBoxLayout *buttonsLayout = new QHBoxLayout(buttonsContainer);
    buttonsLayout->setContentsMargins(0, 0, 0, 0);
    buttonsLayout->setSpacing(2);

    QPushButton *editButton = new QPushButton(buttonsContainer);
    editButton->setFixedSize(iconSize, iconSize);
    editButton->setIcon(QIcon(":/img/edit_note.png"));

    QPushButton *deleteButton = new QPushButton(buttonsContainer);
    deleteButton->setFixedSize(iconSize, iconSize);
    deleteButton->setIcon(QIcon(":/img/delete.png"));

    buttonsLayout->addWidget(editButton);
    buttonsLayout->addWidget(deleteButton);

    ui->tableWidget->setCellWidget(row, 1, buttonsContainer);

    connect(editButton, &QPushButton::clicked, this, [this, row]() {
      QString name = ui->tableWidget->item(row, 0)->text();

      if (elemType == ElemType::Printer)
        emit editPrinterRequested(name);
      else if (elemType == ElemType::Plastic)
        emit editPlasticRequested(name);
    });

    connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
      QString name = ui->tableWidget->item(row, 0)->text();

      QMessageBox confirmationDialog(this);
      confirmationDialog.setWindowTitle("Подтверждение");
      confirmationDialog.setText(
          QString("Удалить объект <b>%1</b>?").arg(name));
      confirmationDialog.setIcon(QMessageBox::Question);

      QPushButton *deleteButton =
          confirmationDialog.addButton("Удалить", QMessageBox::AcceptRole);
      QPushButton *cancelButton =
          confirmationDialog.addButton("Отмена", QMessageBox::RejectRole);
      confirmationDialog.setDefaultButton(cancelButton);

      confirmationDialog.exec();

      if (confirmationDialog.clickedButton() == deleteButton) {
        if (elemType == ElemType::Printer)
          emit deletePrinterRequested(name);
        else if (elemType == ElemType::Plastic)
          emit deletePlasticRequested(name);
      }
    });
  }
}