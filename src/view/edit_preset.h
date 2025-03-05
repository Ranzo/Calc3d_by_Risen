#ifndef EDITPRESETDIALOG_H
#define EDITPRESETDIALOG_H

#include <QDialog>

namespace Ui {
class EditPreset;
}

class EditPresetDialog : public QDialog {
    Q_OBJECT

public:
    explicit EditPresetDialog(QWidget *parent = nullptr);
    ~EditPresetDialog();

private:
    Ui::EditPreset *ui;
};

#endif // EDITPRESETDIALOG_H