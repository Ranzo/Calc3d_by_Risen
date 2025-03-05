#include "update_dialog.h"
#include "ui/ui_updates.h"
#include <QDesktopServices>

UpdatesDialog::UpdatesDialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::Updates)
{
    ui->setupUi(this);
    
    setWindowIcon(QIcon("img/logo-1.png"));
    
    connect(ui->pushButton_2, &QPushButton::clicked, this, &UpdatesDialog::onCloseClicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &UpdatesDialog::onVisitWebsiteClicked);
}

UpdatesDialog::~UpdatesDialog() {
    delete ui;
}

void UpdatesDialog::setCurrentVersion(const QString &version) {
    ui->label_3->setText(version);
}

void UpdatesDialog::setLatestVersion(const QString &version) {
    ui->label_4->setText(version);
}

void UpdatesDialog::onCloseClicked() {
    close();
}

void UpdatesDialog::onVisitWebsiteClicked() {
    // TODO занести сайт
    QDesktopServices::openUrl(WEBSITE_URL);
}