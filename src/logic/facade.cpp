#include "facade.h"

std::shared_ptr<Facade> Facade::GetInstance() {
  static auto instance = std::shared_ptr<Facade>(new Facade);
  return instance;
}

bool Facade::addPrinter(const QString &name, double power, int age,
                        double cost) {
  return printerDB->addPrinter(name, power, age, cost);
}

QList<QString> Facade::getPrinterList() { return printerDB->getPrinterList(); }

bool Facade::deletePrinterByName(const QString &name) {
  return printerDB->deletePrinterByName(name);
}

void Facade::updatePrinterByName(const QString &oldName, const QString &newName,
                                 double power, int age, double cost) {
  printerDB->updatePrinterByName(oldName, newName, power, age, cost);
}

QHash<QString, QVariant> Facade::getPrinterByName(const QString &name) {
  return printerDB->getPrinterByName(name);
}

std::pair<double, double> Facade::calculate(const QString &printerName,
                                            const QString &plasticName, int hrs,
                                            int min, double detailWeight,
                                            int quantity, double post,
                                            double mod) {
  auto printerData = printerDB->getPrinterByName(printerName);
  auto plasticData = plasticDB->getPlasticByName(plasticName);
  auto settingsData = settingPreset->getSettings();
  min = hrs * 60 + min;

  // Заполнение структуры Params
  Params params;
  params.p = printerData["power"].toDouble();  // номинальная мощность
  params.t = min;                              // время печати
  params.h = settingsData["tarif"].toDouble();  // тариф
  params.md = detailWeight;                     // вес детали
  params.d = settingsData["qTrash"].toDouble();  // коэффициент выбраковки
  params.st = plasticData["cost"].toDouble();  // стоимость катушки
  params.mk = plasticData["weight"].toDouble();  // вес катушки
  params.a = printerData["cost"].toDouble();  // стоимость принтера
  params.post = post;                         // постобработка
  params.x = quantity;                        // количество
  params.marge = settingsData["overprice"].toDouble();  // наценка
  params.mod = mod;                            // моделирование
  params.spi = printerData["age"].toDouble();  // срок использования

  return Calculator::calculateCostAndTotalPrice(params);
}

void Facade::updateSettings(double tarif, double qTrash, double overprice) {
  settingPreset->updateSettings(tarif, qTrash, overprice);
}

QHash<QString, QVariant> Facade::getSettings() {
  return settingPreset->getSettings();
}

Facade::Facade() {
  QString dir =
      QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
  QDir().mkpath(dir);  // создает, если папки не было

  try {
    printerDB = std::make_unique<PrinterDB>(dir);
    plasticDB = std::make_unique<PlasticDB>(dir);
    settingPreset = std::make_unique<SettingPreset>(dir);

    if (!printerDB->init() || !plasticDB->init()) {
      throw FacadeException(
          QString("Ошибка инициализации БД. Путь: %1").arg(dir));
    }
  } catch (std::exception &ex) {
    throw FacadeException(
        QString("Ошибка инициализации Facade: %1").arg(ex.what()));
  }
}

bool Facade::addPlastic(const QString &name, double weight, double cost) {
  return plasticDB->addPlastic(name, weight, cost);
}

QList<QString> Facade::getPlasticList() { return plasticDB->getPlasticList(); }

bool Facade::deletePlasticByName(const QString &name) {
  return plasticDB->deletePlasticByName(name);
}

void Facade::updatePlasticByName(const QString &oldName, const QString &newName,
                                 double weight, double cost) {
  plasticDB->updatePlasticByName(oldName, newName, weight, cost);
}

QHash<QString, QVariant> Facade::getPlasticByName(const QString &name) {
  return plasticDB->getPlasticByName(name);
}
