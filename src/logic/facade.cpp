#include "facade.h"

std::shared_ptr<Facade> Facade::GetInstance() {
  static auto instance = std::shared_ptr<Facade>(new Facade);
  return instance;
}

bool Facade::addPrinter(const QString &name, double power, int age,
                        double cost) {
  return db->addPrinter(name, power, age, cost);
}

QList<QString> Facade::getPrinterList() { return db->getPrinterList(); }

bool Facade::deletePrinterByName(const QString &name) {
  return db->deletePrinterByName(name);
}

void Facade::updatePrinterByName(const QString &oldName, const QString &newName,
                                 double power, int age, double cost) {
  db->updatePrinterByName(oldName, newName, power, age, cost);
}

QHash<QString, QVariant> Facade::getPrinterByName(const QString &name) {
  return db->getPrinterByName(name);
}

std::pair<double, double> Facade::calculate(const QString &printerName, int hrs,
                                            int min, double detailWeight,
                                            int quantity, double post,
                                            double mod) {
  auto printerData = db->getPrinterByName(printerName);
  auto settingsData = settingPreset->getSettings();
  min = hrs * 60 + min;

  return Calculator::calculateCostAndTotalPrice(
      printerData["power"].toDouble(), min, settingsData["tarif"].toDouble(),
      detailWeight, settingsData["qTrash"].toDouble(),
      settingsData["pricePlastik"].toDouble(),
      settingsData["weightPlastik"].toDouble(), printerData["cost"].toDouble(),
      post, quantity, settingsData["overprice"].toDouble(), mod,
      printerData["age"].toDouble());
}

void Facade::updateSettings(double tarif, double qTrash, double pricePlastik,
                            double overprice, int weightPlastik) {
  settingPreset->updateSettings(tarif, qTrash, pricePlastik, overprice,
                                weightPlastik);
}

QHash<QString, QVariant> Facade::getSettings() {
  return settingPreset->getSettings();
}

Facade::Facade() {
  QString dir =
      QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

  try {
    db = std::make_unique<Database>(dir);
    settingPreset = std::make_unique<SettingPreset>(dir);

    if (!db->init()) {
      throw FacadeException(
          QString("Ошибка инициализации БД. Путь: %1").arg(dir));
    }
  } catch (std::exception &ex) {
    throw FacadeException(
        QString("Ошибка инициализации Facade: %1").arg(ex.what()));
  }
}