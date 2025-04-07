#include "facade.h"

std::shared_ptr<Facade> Facade::GetInstance() {
  static auto instance = std::shared_ptr<Facade>(new Facade);
  return instance;
}

void Facade::addPrinter(const QString &name, int power, int age, double cost) {
  if (!printerDB->addPrinter(name, power, age, cost))
    throw FacadeException("Принтер с таким именем уже существует");
}

QList<QString> Facade::getPrinterList() { return printerDB->getPrinterList(); }

void Facade::deletePrinterByName(const QString &name) {
  printerDB->deletePrinterByName(name);
}

void Facade::updatePrinterByName(const QString &oldName, const QString &newName,
                                 int power, int age, double cost) {
  if (!printerDB->updatePrinterByName(oldName, newName, power, age, cost))
    throw FacadeException("Объект не был обновлен");
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

  if (min < 0 || hrs < 0)
    throw FacadeException("Проверьте правильность запонения полей времени");
  min = hrs * 60 + min;

  // Заполнение структуры Params
  Params params;
  params.p = printerData["power"].toInt();  // номинальная мощность
  params.t = min;                           // время печати
  params.h = settingsData["tarif"].toDouble();  // тариф
  params.md = detailWeight;                     // вес детали
  params.d = settingsData["qTrash"].toDouble();  // коэффициент выбраковки
  params.st = plasticData["cost"].toDouble();  // стоимость катушки
  params.mk = plasticData["weight"].toInt();  // вес катушки
  params.a = printerData["cost"].toDouble();  // стоимость принтера
  params.post = post;                         // постобработка
  params.x = quantity;                        // количество
  params.marge = settingsData["overprice"].toDouble();  // наценка
  params.mod = mod;                            // моделирование
  params.spi = printerData["age"].toDouble();  // срок использования

  checkParams(params);

  return Calculator::calculateCostAndTotalPrice(params);
}

void Facade::checkParams(Params &param) {
  if (param.p < 0)
    throw FacadeException("Проверьте правильность заполнения поля Мощность");
  if (param.t < 1)
    throw FacadeException("Проверьте правильность заполнения полей времени");
  if (param.h < 0)
    throw FacadeException("Проверьте правильность заполнения поля Тариф");
  if (param.md <= 0.01)
    throw FacadeException("Проверьте правильность заполнения поля Вес детали");
  if (param.d < 0)
    throw FacadeException(
        "Проверьте правильность заполнения поля Коэффициент выбраковки");
  if (param.st < 0)
    throw FacadeException(
        "Проверьте правильность заполнения поля Стоимость катушки");
  if (param.mk < 1)
    throw FacadeException("Проверьте правильность заполнения поля Вес катушки");
  if (param.mk < param.md * param.x)
    throw FacadeException(
        QString("В катушке недостаточно пластика для печати %1 деталей")
            .arg(param.x));
  if (param.a < 0)
    throw FacadeException(
        "Проверьте правильность заполнения поля Стоимость принтера");
  if (param.post < 0)
    throw FacadeException(
        "Проверьте правильность заполнения поля Стоимость постобработки");
  if (param.x < 1)
    throw FacadeException(
        "Проверьте правильность заполнения поля Количество деталей");
  if (param.marge < 0)
    throw FacadeException("Проверьте правильность заполнения поля Наценка");
  if (param.mod < 0)
    throw FacadeException(
        "Проверьте правильность заполнения поля Моделирование");
  if (param.spi < 0)
    throw FacadeException(
        "Проверьте правильность заполнения поля Срок полезного использования");
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

void Facade::addPlastic(const QString &name, int weight, double cost) {
  if (!plasticDB->addPlastic(name, weight, cost))
    throw FacadeException("Катушка с таким именем уже существует");
}

QList<QString> Facade::getPlasticList() { return plasticDB->getPlasticList(); }

void Facade::deletePlasticByName(const QString &name) {
  plasticDB->deletePlasticByName(name);
}

void Facade::updatePlasticByName(const QString &oldName, const QString &newName,
                                 int weight, double cost) {
  if (!plasticDB->updatePlasticByName(oldName, newName, weight, cost))
    throw FacadeException("Объект не был обновлен");
}

QHash<QString, QVariant> Facade::getPlasticByName(const QString &name) {
  return plasticDB->getPlasticByName(name);
}

QHash<QString, QVariant> Facade::getUserLastChoice() {
  return settingPreset->getUserLastChoice();
}

void Facade::updateUserChoice(QString &printer, QString &plastic) {
  settingPreset->updateUserChoice(printer, plastic);
}
