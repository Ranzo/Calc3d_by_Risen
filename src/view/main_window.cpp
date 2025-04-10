#include "main_window.h"

#include "ui/ui_main_window.h"

MainWindow::MainWindow(std::shared_ptr<Facade> fcd, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), facade(fcd) {
  ui->setupUi(this);
  setFixedSize(373, 521);

  progInfo = new AboutDialog(this);
  formulaInfo = new FormulaDialog(this);
  updateInfo = new UpdatesDialog(this);
  printerSettings = new PrinterSettingsDialog(this);
  addPrinterDialog = new AddPrinterDialog(this);
  addPlasticDialog = new AddPlasticDialog(this);
  deleteListDialog = new DeleteListDialog(this);

  refreshPrinterList();
  refreshPlasticList();

  setLastChoice();
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
    deleteListDialog->loadList(ElemType::Printer, printers);
    deleteListDialog->exec();
  });

  connect(ui->del_plastic, &QAction::triggered, this, [this]() {
    QList<QString> plastics = facade->getPlasticList();
    deleteListDialog->loadList(ElemType::Plastic, plastics);

    deleteListDialog->exec();
  });

  connect(ui->action_3, &QAction::triggered, this, [this]() {
    saveLastChoice();
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
    QString printerName = ui->printer_menu->currentText();
    QString plasticName = ui->plastic_menu->currentText();

    if (printerName.isEmpty() || plasticName.isEmpty()) {
      QMessageBox::warning(this, "Ошибка",
                           "Убедитесь, что принтер и катушка выбраны");
      return;
    }

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
      QMessageBox::warning(this, "Ошибка", exc.getMessage());
    }
  });

  connect(ui->exit_btn, &QPushButton::clicked, this, [this]() {
    saveLastChoice();
    close();
  });

  // Ловля стороних сигналов
  connect(addPrinterDialog, &AddPrinterDialog::printerAdded, this,
          [this](const QString &name, double power, int age, double cost) {
            try {
              facade->addPrinter(name, power, age, cost);
              refreshPrinterList();
            } catch (const FacadeException &exc) {
              QMessageBox::warning(this, "Ошибка", exc.getMessage());
            }
          });

  connect(addPrinterDialog, &AddPrinterDialog::printerEdited, this,
          [this](const QString &oldName, const QString &newName, double power,
                 int age, double cost) {
            try {
              facade->updatePrinterByName(oldName, newName, power, age, cost);
              refreshPrinterList();
            } catch (const FacadeException &exc) {
              QMessageBox::warning(this, "Ошибка", exc.getMessage());
            }
          });

  connect(addPlasticDialog, &AddPlasticDialog::plasticAdded, this,
          [this](const QString &name, double weight, double cost) {
            try {
              facade->addPlastic(name, weight, cost);
              refreshPlasticList();
            } catch (const FacadeException &exc) {
              QMessageBox::warning(this, "Ошибка", exc.getMessage());
            }
          });

  connect(addPlasticDialog, &AddPlasticDialog::plasticEdited, this,
          [this](const QString &oldName, const QString &newName, double weight,
                 double cost) {
            try {
              facade->updatePlasticByName(oldName, newName, weight, cost);
              refreshPlasticList();
            } catch (const FacadeException &exc) {
              QMessageBox::warning(this, "Ошибка", exc.getMessage());
            }
          });

  connect(deleteListDialog, &DeleteListDialog::deletePlasticRequested, this,
          [this](const QString &name) {
            try {
              facade->deletePlasticByName(name);
              refreshPlasticList();
            } catch (const FacadeException &exc) {
              QMessageBox::warning(this, "Ошибка", exc.getMessage());
            }
          });

  connect(deleteListDialog, &DeleteListDialog::editPlasticRequested, this,
          [this](const QString &name) {
            auto preset = facade->getPlasticByName(name);
            addPlasticDialog->setEditMode(preset);
            addPlasticDialog->exec();
          });

  connect(deleteListDialog, &DeleteListDialog::deletePrinterRequested, this,
          [this](const QString &name) {
            try {
              facade->deletePrinterByName(name);
              refreshPrinterList();
            } catch (const FacadeException &exc) {
              QMessageBox::warning(this, "Ошибка", exc.getMessage());
            }
          });

  connect(deleteListDialog, &DeleteListDialog::editPrinterRequested, this,
          [this](const QString &name) {
            auto preset = facade->getPrinterByName(name);
            addPrinterDialog->setEditMode(preset);
            addPrinterDialog->exec();
          });

  connect(printerSettings, &PrinterSettingsDialog::settingsSaved, this,
          [this](double tarif, double qTrash, double overprice) {
            try {
              facade->updateSettings(tarif, qTrash, overprice);
            } catch (const FacadeException &exc) {
              QMessageBox::warning(this, "Ошибка", exc.getMessage());
            }
          });
}

void MainWindow::closeEvent(QCloseEvent *event) {
  saveLastChoice();
  event->accept();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::refreshPrinterList() {
  bool isEmpty = (ui->printer_menu->count() == 0);
  QString currentPrinter = ui->printer_menu->currentText();

  QList<QString> printers = facade->getPrinterList();
  ui->printer_menu->clear();
  ui->printer_menu->addItems(QStringList::fromList(printers));
  deleteListDialog->loadList(ElemType::Printer, printers);
  if (printers.isEmpty()) {
    ui->printer_menu->setCurrentIndex(-1);
    ui->printer_menu->setPlaceholderText("Выбор принтера");
    return;
  }
  if (isEmpty)
    ui->printer_menu->setCurrentIndex(0);
  else {
    int idx = ui->printer_menu->findText(currentPrinter);
    ui->printer_menu->setCurrentIndex(idx != -1 ? idx : -1);
  }
}

void MainWindow::refreshPlasticList() {
  bool isEmpty = (ui->plastic_menu->count() == 0);
  QString currentPrinter = ui->plastic_menu->currentText();

  QList<QString> plastics = facade->getPlasticList();
  ui->plastic_menu->clear();
  ui->plastic_menu->addItems(QStringList::fromList(plastics));
  deleteListDialog->loadList(ElemType::Plastic, plastics);
  if (plastics.isEmpty()) {
    ui->plastic_menu->setCurrentIndex(-1);
    ui->plastic_menu->setPlaceholderText("Выбор катушки");
    return;
  }
  if (isEmpty)
    ui->plastic_menu->setCurrentIndex(0);
  else {
    int idx = ui->plastic_menu->findText(currentPrinter);
    ui->plastic_menu->setCurrentIndex(idx != -1 ? idx : -1);
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

void MainWindow::setLastChoice() {
  auto userChoice = facade->getUserLastChoice();

  QString lastPrinter = userChoice["lastPrinter"].toString();
  auto printerIndx = ui->printer_menu->findText(lastPrinter);
  if (!lastPrinter.isEmpty() && printerIndx != -1)
    ui->printer_menu->setCurrentIndex(printerIndx);

  QString lastPlastic = userChoice["lastPlastic"].toString();
  auto plasticIndx = ui->plastic_menu->findText(lastPlastic);
  if (!lastPlastic.isEmpty() && plasticIndx != -1)
    ui->plastic_menu->setCurrentIndex(plasticIndx);
}

void MainWindow::saveLastChoice() {
  QString printer = ui->printer_menu->currentText().trimmed();
  QString plastic = ui->plastic_menu->currentText().trimmed();
  facade->updateUserChoice(printer, plastic);
}