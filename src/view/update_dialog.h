#ifndef UPDATESDIALOG_H
#define UPDATESDIALOG_H

#include <QDialog>
#include <QUrl>

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

 private:
  Ui::Updates *ui;
  const QUrl WEBSITE_URL = QUrl("https://calc3d.ru/");
};

#endif  // UPDATESDIALOG_H