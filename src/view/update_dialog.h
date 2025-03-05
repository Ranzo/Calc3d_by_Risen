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

    // Методы для обновления информации о версиях
    void setCurrentVersion(const QString &version);
    void setLatestVersion(const QString &version);

private slots:
    void onCloseClicked();
    void onVisitWebsiteClicked();

private:
    Ui::Updates *ui;
    const QUrl WEBSITE_URL = QUrl("https://your-update-website.com");
};

#endif // UPDATESDIALOG_H