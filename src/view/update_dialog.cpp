#include "update_dialog.h"

#include <QDesktopServices>

#include "ui/ui_updates.h"

UpdatesDialog::UpdatesDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Updates) {
  ui->setupUi(this);

  setFixedSize(size());

  connect(ui->pushButton_2, &QPushButton::clicked, this,
          &UpdatesDialog::onCloseClicked);
  connect(ui->pushButton, &QPushButton::clicked, this,
          &UpdatesDialog::onVisitWebsiteClicked);
}

UpdatesDialog::~UpdatesDialog() { delete ui; }

void UpdatesDialog::onCloseClicked() { close(); }

void UpdatesDialog::onVisitWebsiteClicked() {
  QDesktopServices::openUrl(WEBSITE_URL);
}