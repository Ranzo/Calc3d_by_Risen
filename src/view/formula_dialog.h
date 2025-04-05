#ifndef FORMULADIALOG_H
#define FORMULADIALOG_H

#include <QDialog>

namespace Ui {
class Formula;
}

class FormulaDialog : public QDialog {
  Q_OBJECT

 public:
  explicit FormulaDialog(QWidget *parent = nullptr);
  ~FormulaDialog();

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::Formula *ui;
};

#endif  // FORMULADIALOG_H