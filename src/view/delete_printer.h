#ifndef DELPRESETDIALOG_H
#define DELPRESETDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class DelPreset;
}

class DeletePrinterDialog : public QDialog {
  Q_OBJECT

 public:
  explicit DeletePrinterDialog(QWidget *parent = nullptr);
  ~DeletePrinterDialog();

  void loadPresets(const QList<QString> &data);

 signals:
  void deleteRequested(const QString &printerName);
  void editRequested(const QString &printerName);

 private:
  void setupTable();
  Ui::DelPreset *ui;
};

#endif  // DELPRESETDIALOG_H