#ifndef DELPLASTICDIALOG_H
#define DELPLASTICDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class DelPlastic;
}

class DeletePlasticDialog : public QDialog {
  Q_OBJECT

 public:
  explicit DeletePlasticDialog(QWidget *parent = nullptr);
  ~DeletePlasticDialog();

  void loadPlastics(const QList<QString> &data);

 signals:
  void deleteRequested(const QString &printerName);
  void editRequested(const QString &printerName);

 private:
  void setupTable();
  Ui::DelPlastic *ui;
};

#endif  // DELPLASTICDIALOG_H