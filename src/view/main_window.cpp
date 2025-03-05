#include "main_window.h"

#include "ui/ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(373, 471);

  progInfo = new AboutDialog(this);
  formulaInfo = new FormulaDialog(this);
  updateInfo = new UpdatesDialog(this);
  printerSettings = new PrinterSettingsDialog(this);
  addPresetDialog = new AddPresetDialog(this);
  deletePresetDialog = new DeletePresetDialog(this);
  editPresetDialog = new EditPresetDialog(this);
  //      <!-- <property name="styleSheet"> // бледно серый для тепскта
  //     <string>color: rgb(146, 152, 159);</string>
  //   </property> -->

  //   Action with menu "Файл"
  connect(ui->settings_2, &QAction::triggered, this,
          [this]() { printerSettings->exec(); });
    connect(ui->add_preset, &QAction::triggered, this,
            [this]() { addPresetDialog->exec(); });
    connect(ui->edit_printer, &QAction::triggered, this,
            [this]() { editPresetDialog->exec(); });
    connect(ui->del_printer, &QAction::triggered, this,
            [this]() { deletePresetDialog->exec(); });
  connect(ui->action_3, &QAction::triggered, this, [this]() {
    //! smth will be saved?
    qDebug() << "SMTH NEEDS TO SAVE?";
    close();
  });

  //    Action with menu "Помощь"
  connect(ui->check_update, &QAction::triggered, this,
          [this]() { updateInfo->exec(); });
  connect(ui->formula, &QAction::triggered, this,
          [this]() { formulaInfo->exec(); });
  connect(ui->about, &QAction::triggered, this, [this]() { progInfo->exec(); });

  //    Action with buttons
  connect(ui->get_result_btn, &QPushButton::clicked, this, [this]() {
    // TODO отправляет на расчет
    qDebug() << "SMTH COUNT";
  });
  connect(ui->exit_btn, &QPushButton::clicked, this, [this]() {
    //! smth will be saved?
    qDebug() << "SMTH NEEDS TO SAVE?";
    close();
  });
}

MainWindow::~MainWindow() { delete ui; }