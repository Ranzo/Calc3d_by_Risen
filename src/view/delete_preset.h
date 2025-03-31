#ifndef DELPRESETDIALOG_H
#define DELPRESETDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class DelPreset;
}

class DeletePresetDialog : public QDialog {
  Q_OBJECT

 public:
  explicit DeletePresetDialog(QWidget *parent = nullptr);
  ~DeletePresetDialog();

  void loadPresets(const QList<QString> &data);

 signals:
  void deleteRequested(const QString &printerName);
  void editRequested(const QString &printerName);

 private:
  void setupTable();
  Ui::DelPreset *ui;
};

#endif  // DELPRESETDIALOG_H