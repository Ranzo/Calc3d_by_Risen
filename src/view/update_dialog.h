#ifndef UPDATESDIALOG_H
#define UPDATESDIALOG_H

#include <QDesktopServices>
#include <QDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class Updates;
}

class UpdatesDialog : public QDialog {
  Q_OBJECT

 public:
  explicit UpdatesDialog(QWidget *parent = nullptr);
  ~UpdatesDialog();

 private slots:
  void onCloseClicked();
  void onVisitWebsiteClicked();
  void onCheckVersionFinished(QNetworkReply *reply);

 private:
  Ui::Updates *ui;
  QNetworkAccessManager *networkManager;
  QString currentVersion = "v.1.0.0b";
  const QUrl WEBSITE_URL = QUrl("https://calc3d.ru/");
  const QUrl CHECK_URL = QUrl("https://calc3d.ru/api/version");
};

#endif  // UPDATESDIALOG_H