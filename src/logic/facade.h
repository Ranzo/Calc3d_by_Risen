#pragma once

#include <QDir>
#include <QHash>
#include <QStandardPaths>
#include <QVariant>
#include <memory>
#include <stdexcept>
#include <string>

#include "calculator.h"
#include "printer_db.h"
#include "setting_preset.h"

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

  bool addPrinter(const QString &name, double power, int age, double cost);

  QList<QString> getPrinterList();

  bool deletePrinterByName(const QString &name);

  void updatePrinterByName(const QString &oldName, const QString &newName,
                           double power, int age, double cost);

  QHash<QString, QVariant> getPrinterByName(const QString &name);

  std::pair<double, double> calculate(const QString &printerName, int hrs,
                                      int min, double detailWeight,
                                      int quantity, double post, double mod);

  void updateSettings(double tarif, double qTrash, double pricePlastik,
                      double overprice, int weightPlastik);

  QHash<QString, QVariant> getSettings();

 private:
  std::unique_ptr<Database> db;
  std::unique_ptr<SettingPreset> settingPreset;

  Facade();
};