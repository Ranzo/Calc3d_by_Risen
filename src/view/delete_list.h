#ifndef DELLISTDIALOG_H
#define DELLISTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QTableWidgetItem>

namespace Ui {
class DelList;
}

enum class ElemType { Printer, Plastic };

class DeleteListDialog : public QDialog {
  Q_OBJECT

 public:
  explicit DeleteListDialog(QWidget *parent = nullptr);
  ~DeleteListDialog();

  void loadList(ElemType type, const QList<QString> &data);

 signals:
  void deletePrinterRequested(const QString &name);
  void editPrinterRequested(const QString &name);

  void deletePlasticRequested(const QString &name);
  void editPlasticRequested(const QString &name);

 private:
  ElemType elemType;
  static constexpr int iconSize = 35;

  void setupTable();
  Ui::DelList *ui;
};

#endif  // DELLISTDIALOG_H