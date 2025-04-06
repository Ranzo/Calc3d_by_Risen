#ifndef DELLISTDIALOG_H
#define DELLISTDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class DelList;
}

enum class ElemType { Printer, Plastic };

class DeletePlasticDialog : public QDialog {
  Q_OBJECT

 public:
  explicit DeletePlasticDialog(QWidget *parent = nullptr);
  ~DeletePlasticDialog();

  void loadList(ElemType type, const QList<QString> &data);

 signals:
  void deletePrinterRequested(const QString &name);
  void editPrinterRequested(const QString &name);

  void deletePlasticRequested(const QString &name);
  void editPlasticRequested(const QString &name);

 private:
  ElemType elemType;

  void setupTable();
  Ui::DelList *ui;
};

#endif  // DELLISTDIALOG_H