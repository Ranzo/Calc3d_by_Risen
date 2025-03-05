#include "delete_preset.h"
#include "ui/ui_del_preset.h"

DeletePresetDialog::DeletePresetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DelPreset)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("img/logo-1.png"));
    
    setupTable();
    
    connect(ui->pushButton_3, &QPushButton::clicked, this, &DeletePresetDialog::onDeleteClicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &DeletePresetDialog::onEditClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::reject);
}

DeletePresetDialog::~DeletePresetDialog() {
    delete ui;
}

void DeletePresetDialog::setupTable() {
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({"Название", "Мощность"});
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

void DeletePresetDialog::loadPresets(const QList<QStringList> &data) {
    ui->tableWidget->setRowCount(data.size());
    
    for(int row = 0; row < data.size(); ++row) {
        const QStringList &rowData = data[row];
        for(int col = 0; col < rowData.size(); ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(rowData[col]));
        }
    }
}

QString DeletePresetDialog::getSelectedPreset() const {
    const int row = getSelectedRow();
    return row >= 0 ? ui->tableWidget->item(row, 0)->text() : "";
}

int DeletePresetDialog::getSelectedRow() const {
    return ui->tableWidget->currentRow();
}

void DeletePresetDialog::onDeleteClicked() {
    const int row = getSelectedRow();
    if(row >= 0) {
        emit deleteRequested(row);
        ui->tableWidget->removeRow(row);
    }
}

void DeletePresetDialog::onEditClicked() {
    const int row = getSelectedRow();
    if(row >= 0) {
        emit editRequested(row);
        accept();
    }
}