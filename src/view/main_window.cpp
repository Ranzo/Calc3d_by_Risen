#include "main_window.h"

#include "ui/ui_main_window.h"

MainWindow::MainWindow(std::shared_ptr<Facade> fcd, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  facade = fcd;
  ui->setupUi(this);
  setFixedSize(373, 521);

  progInfo = new AboutDialog(this);
  formulaInfo = new FormulaDialog(this);
  updateInfo = new UpdatesDialog(this);
  printerSettings = new PrinterSettingsDialog(this);
  addPrinterDialog = new AddPrinterDialog(this);
  deletePrinterDialog = new DeletePrinterDialog(this);
  addPlasticDialog = new AddPlasticDialog(this);
  deletePlasticDialog = new DeletePlasticDialog(this);

  refreshPrinterList();
  refreshPlasticList();

  setValidators();

  printerSettings->loadSettings(facade->getSettings());

  connect(ui->settings_2, &QAction::triggered, this,
          [this]() { printerSettings->exec(); });

  connect(ui->add_printer, &QAction::triggered, this, [this]() {
    addPrinterDialog->setAddMode();
    addPrinterDialog->exec();
  });

  connect(ui->add_plastic, &QAction::triggered, this, [this]() {
    addPlasticDialog->setAddMode();
    addPlasticDialog->exec();
  });

  connect(ui->del_printer, &QAction::triggered, this, [this]() {
    QList<QString> printers = facade->getPrinterList();

    deletePrinterDialog->exec();
  });

  connect(ui->del_plastic, &QAction::triggered, this, [this]() {
    QList<QString> plastics = facade->getPlasticList();

    deletePlasticDialog->exec();
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
    QString plasticName = ui->plastic_menu->currentText();
    try {
      auto [cost, total] = facade->calculate(
          printerName, plasticName, ui->input_hours->text().toInt(),
          ui->input_minutes->text().toInt(),
          ui->input_gram->text().replace(",", ".").toDouble(),
          ui->input_things->text().toInt(),
          ui->input_post->text().replace(",", ".").toDouble(),
          ui->input_mod->text().replace(",", ".").toDouble());

      ui->lcd_result_total->display(QString::number(total, 'f', 2));
      ui->lcd_result_cost->display(QString::number(cost, 'f', 2));
    } catch (const FacadeException &exc) {
      QMessageBox::warning(this, "Ошибка", exc.what());
    }
  });

  connect(ui->exit_btn, &QPushButton::clicked, this, [this]() { close(); });

  // Ловля стороних сигналов
  connect(addPrinterDialog, &AddPrinterDialog::printerAdded, this,
          [this](const QString &name, double power, int age, double cost) {
            if (facade->addPrinter(name, power, age, cost))
              refreshPrinterList();
            else
              QMessageBox::warning(this, "Ошибка",
                                   "Не удалось добавить принтер");
          });

  connect(deletePrinterDialog, &DeletePrinterDialog::deleteRequested, this,
          [this](const QString &name) {
            if (facade->deletePrinterByName(name))
              refreshPrinterList();
            else
              QMessageBox::warning(this, "Ошибка",
                                   "Не удалось удалить принтер");
          });

  connect(deletePrinterDialog, &DeletePrinterDialog::editRequested, this,
          [this](const QString &name) {
            auto preset = facade->getPrinterByName(name);
            addPrinterDialog->setEditMode(preset);
            addPrinterDialog->exec();
          });

  connect(addPrinterDialog, &AddPrinterDialog::printerEdited, this,
          [this](const QString &oldName, const QString &newName, double power,
                 int age, double cost) {
            facade->updatePrinterByName(oldName, newName, power, age, cost);
            refreshPrinterList();
          });

  connect(addPlasticDialog, &AddPlasticDialog::plasticAdded, this,
          [this](const QString &name, double weight, double cost) {
            if (facade->addPlastic(name, weight, cost))
              refreshPlasticList();
            else
              QMessageBox::warning(this, "Ошибка",
                                   "Не удалось добавить катушку");
          });

  connect(deletePlasticDialog, &DeletePlasticDialog::deleteRequested, this,
          [this](const QString &name) {
            if (facade->deletePlasticByName(name))
              refreshPlasticList();
            else
              QMessageBox::warning(this, "Ошибка",
                                   "Не удалось удалить катушку");
          });

  connect(deletePlasticDialog, &DeletePlasticDialog::editRequested, this,
          [this](const QString &name) {
            auto preset = facade->getPlasticByName(name);
            addPlasticDialog->setEditMode(preset);
            addPlasticDialog->exec();
          });

  connect(addPlasticDialog, &AddPlasticDialog::plasticEdited, this,
          [this](const QString &oldName, const QString &newName, double weight,
                 double cost) {
            facade->updatePlasticByName(oldName, newName, weight, cost);
            refreshPlasticList();
          });

  connect(printerSettings, &PrinterSettingsDialog::settingsSaved, this,
          [this](double tarif, double qTrash, double overprice) {
            facade->updateSettings(tarif, qTrash, overprice);
          });
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::refreshPrinterList() {
  bool isEmpty = (ui->printer_menu->count() == 0);
  QString currentPrinter = ui->printer_menu->currentText();

  QList<QString> printers = facade->getPrinterList();
  ui->printer_menu->clear();
  ui->printer_menu->addItems(QStringList::fromList(printers));
  deletePrinterDialog->loadPresets(printers);
  if (printers.isEmpty()) {
    ui->printer_menu->setCurrentIndex(-1);
    ui->printer_menu->setPlaceholderText("Выбор принтера");
  } else {
    if (isEmpty) {
      ui->printer_menu->setCurrentIndex(0);
    } else {
      int idx = ui->printer_menu->findText(currentPrinter);
      ui->printer_menu->setCurrentIndex(idx != -1 ? idx : -1);
    }
  }
}

void MainWindow::refreshPlasticList() {
  bool isEmpty = (ui->plastic_menu->count() == 0);
  QString currentPrinter = ui->plastic_menu->currentText();

  QList<QString> plastics = facade->getPlasticList();
  ui->plastic_menu->clear();
  ui->plastic_menu->addItems(QStringList::fromList(plastics));
  deletePlasticDialog->loadPlastics(plastics);
  if (plastics.isEmpty()) {
    ui->plastic_menu->setCurrentIndex(-1);
    ui->plastic_menu->setPlaceholderText("Выбор катушки");
  } else {
    if (isEmpty) {
      ui->plastic_menu->setCurrentIndex(0);
    } else {
      int idx = ui->plastic_menu->findText(currentPrinter);
      ui->plastic_menu->setCurrentIndex(idx != -1 ? idx : -1);
    }
  }
}

void MainWindow::setValidators() {
  QRegularExpression integerRegex("^(0|[1-9]\\d{0,6})$");
  QRegularExpression doubleRegex("^(0|([1-9]\\d{0,6}))([.,]\\d{2})?$");

  ui->input_hours->setValidator(
      new QRegularExpressionValidator(integerRegex, this));
  ui->input_minutes->setValidator(
      new QRegularExpressionValidator(integerRegex, this));
  ui->input_gram->setValidator(
      new QRegularExpressionValidator(doubleRegex, this));
  ui->input_things->setValidator(
      new QRegularExpressionValidator(integerRegex, this));
  ui->input_post->setValidator(
      new QRegularExpressionValidator(doubleRegex, this));
  ui->input_mod->setValidator(
      new QRegularExpressionValidator(doubleRegex, this));
}