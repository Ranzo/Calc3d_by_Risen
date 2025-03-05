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

  void loadPresets(const QList<QStringList> &data);
  QString getSelectedPreset() const;
  int getSelectedRow() const;

 signals:
  void deleteRequested(int row);
  void editRequested(int row);

 private slots:
  void onDeleteClicked();
  void onEditClicked();

 private:
  void setupTable();
  Ui::DelPreset *ui;
};

#endif  // DELPRESETDIALOG_H