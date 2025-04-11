#include "update_dialog.h"

#include "ui/ui_updates.h"

UpdatesDialog::UpdatesDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Updates) {
  ui->setupUi(this);
  networkManager = new QNetworkAccessManager(this);
  ui->local_ver->setText(currentVersion);

  setFixedSize(size());

  connect(ui->exitButton, &QPushButton::clicked, this,
          &UpdatesDialog::onCloseClicked);
  connect(ui->websiteButton, &QPushButton::clicked, this,
          &UpdatesDialog::onVisitWebsiteClicked);
  connect(networkManager, &QNetworkAccessManager::finished, this,
          &UpdatesDialog::onCheckVersionFinished);

  QNetworkRequest request(CHECK_URL);
  networkManager->get(request);
}

UpdatesDialog::~UpdatesDialog() { delete ui; }

void UpdatesDialog::onCloseClicked() { close(); }

void UpdatesDialog::onVisitWebsiteClicked() {
  QDesktopServices::openUrl(WEBSITE_URL);
}

void UpdatesDialog::onCheckVersionFinished(QNetworkReply *reply) {
  if (reply->error() != QNetworkReply::NoError) {
    QMessageBox::warning(this, "Ошибка", "Не удалось проверить обновления");
    reply->deleteLater();
    return;
  }

  QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
  QJsonObject json = doc.object();
  QString latestVersion = json["version"].toString();
  ui->remote_ver->setText((latestVersion[0] == 'v') ? latestVersion
                                                    : ("v" + latestVersion));

  reply->deleteLater();
}