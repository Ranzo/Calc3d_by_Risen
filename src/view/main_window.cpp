#include "main_window.h"

#include "ui/ui_main_window.h"

MainWindow::MainWindow(std::shared_ptr<Facade> fcd, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  facade = fcd;
  ui->setupUi(this);
  setFixedSize(373, 471);

  progInfo = new AboutDialog(this);
  formulaInfo = new FormulaDialog(this);
  updateInfo = new UpdatesDialog(this);
  printerSettings = new PrinterSettingsDialog(this);
  addPresetDialog = new AddPresetDialog(this);
  deletePresetDialog = new DeletePresetDialog(this);
  editPresetDialog = new EditPresetDialog(this);

  refreshPrinterList();
  printerSettings->loadSettings(facade->getSettings());

  connect(ui->settings_2, &QAction::triggered, this,
          [this]() { printerSettings->exec(); });
  connect(ui->add_preset, &QAction::triggered, this,
          [this]() { addPresetDialog->exec(); });

  connect(ui->del_printer, &QAction::triggered, this, [this]() {
    QList<QString> printers = facade->getPrinterList();

    deletePresetDialog->exec();
  });

  connect(ui->action_3, &QAction::triggered, this, [this]() { close(); });

  //    Action with menu "Помощь"
  connect(ui->check_update, &QAction::triggered, this,
          [this]() { updateInfo->exec(); });
  connect(ui->formula, &QAction::triggered, this,
          [this]() { formulaInfo->exec(); });
  connect(ui->about, &QAction::triggered, this, [this]() { progInfo->exec(); });

  //    Action with buttons
  connect(ui->get_result_btn, &QPushButton::clicked, this, [this]() {
    QString printerName = ui->printer_menu->currentText();
    auto [cost, total] = facade->calculate(
        printerName, ui->input_hours->value(), ui->input_minutes->value(),
        ui->input_gram->value(), ui->input_things->value(),
        ui->input_post->value(), ui->input_mod->value());

    ui->lcd_result_total->display(QString::number(total, 'f', 2));
    ui->lcd_result_cost->display(QString::number(cost, 'f', 2));
  });

  connect(ui->exit_btn, &QPushButton::clicked, this, [this]() { close(); });

  // Ловля стороних сигналов
  connect(addPresetDialog, &AddPresetDialog::printerAdded, this,
          [this](const QString &name, double power, int age, double cost) {
            if (facade->addPrinter(name, power, age, cost))
              refreshPrinterList();
            else
              QMessageBox::warning(this, "Ошибка",
                                   "Не удалось добавить принтер");
          });

  connect(deletePresetDialog, &DeletePresetDialog::deleteRequested, this,
          [this](const QString &name) {
            if (facade->deletePrinterByName(name))
              refreshPrinterList();
            else
              QMessageBox::warning(this, "Ошибка",
                                   "Не удалось удалить принтер");
          });

  connect(deletePresetDialog, &DeletePresetDialog::editRequested, this,
          [this](const QString &name) {
            auto preset = facade->getPrinterByName(name);
            editPresetDialog->setPreset(preset);
            editPresetDialog->exec();
          });

  connect(editPresetDialog, &EditPresetDialog::printerEdited, this,
          [this](const QString &oldName, const QString &newName, double power,
                 int age, double cost) {
            facade->updatePrinterByName(oldName, newName, power, age, cost);
            refreshPrinterList();
          });

  connect(printerSettings, &PrinterSettingsDialog::settingsSaved, this,
          [this](double tarif, double qTrash, double pricePlastik,
                 double overprice, int weightPlastik) {
            facade->updateSettings(tarif, qTrash, pricePlastik, overprice,
                                   weightPlastik);
          });
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::refreshPrinterList() {
  bool wasEmpty = ui->printer_menu->count() == 0;
  QString currentPrinter = ui->printer_menu->currentText();

  QList<QString> printers = facade->getPrinterList();
  ui->printer_menu->clear();
  ui->printer_menu->addItems(QStringList::fromList(printers));
  deletePresetDialog->loadPresets(printers);
  if (printers.isEmpty()) {
    ui->printer_menu->setCurrentIndex(-1);
    ui->printer_menu->setPlaceholderText("Выбор принтера");
  } else {
    if (wasEmpty) {
      ui->printer_menu->setCurrentIndex(0);
    } else {
      int idx = ui->printer_menu->findText(currentPrinter);
      ui->printer_menu->setCurrentIndex(idx != -1 ? idx : -1);
    }
  }
}