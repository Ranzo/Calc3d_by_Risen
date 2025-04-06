#pragma once

#include <QDir>
#include <QHash>
#include <QStandardPaths>
#include <QVariant>
#include <memory>
#include <stdexcept>
#include <string>

#include "../storage/plastic_db.h"
#include "../storage/printer_db.h"
#include "../storage/setting_preset.h"
#include "calculator.h"

class FacadeException : public std::runtime_error {
 public:
  explicit FacadeException(const QString &message)
      : std::runtime_error(message.toLocal8Bit().data()) {}
  virtual ~FacadeException() noexcept = default;
};

class Facade {
 public:
  Facade(const Facade &other) = delete;
  Facade(Facade &&other) = delete;
  Facade &operator=(const Facade &other) = delete;
  ~Facade() = default;

  static std::shared_ptr<Facade> GetInstance();

  // Функции для работы с принтерами
  bool addPrinter(const QString &name, int power, int age, double cost);
  QList<QString> getPrinterList();
  bool deletePrinterByName(const QString &name);
  void updatePrinterByName(const QString &oldName, const QString &newName,
                           int power, int weight, double cost);
  QHash<QString, QVariant> getPrinterByName(const QString &name);

  // Функции для работы с катушками
  bool addPlastic(const QString &name, int weight, double cost);
  QList<QString> getPlasticList();
  bool deletePlasticByName(const QString &name);
  void updatePlasticByName(const QString &oldName, const QString &newName,
                           int weight, double cost);
  QHash<QString, QVariant> getPlasticByName(const QString &name);

  // Функции для работы с пресетами
  void updateSettings(double tarif, double qTrash, double overprice);
  QHash<QString, QVariant> getSettings();

  // Функции для расчетов
  std::pair<double, double> calculate(const QString &printerName,
                                      const QString &plasticName, int hrs,
                                      int min, double detailWeight,
                                      int quantity, double post, double mod);

 private:
  std::unique_ptr<PrinterDB> printerDB;
  std::unique_ptr<PlasticDB> plasticDB;
  std::unique_ptr<SettingPreset> settingPreset;

  Facade();

  void checkParams(Params &param);
};