#pragma once

#include <memory>

#include "printer_db.h"

class Facade {
 public:
  Facade(const Facade &other) = delete;
  Facade(Facade &&other) = delete;
  void operator=(const Facade &other) = delete;
  ~Facade() = default;

  static std::shared_ptr<Facade> GetInstance() {
    static auto instance = std::shared_ptr<Facade>(new Facade);
    return instance;
  }

  bool addPrinter(const QString &name, double power, int age, double cost) {
    return db.addPrinter(name, power, age, cost);
  }

  QList<QString> getPrinterList() { return db.getPrinterList(); }

  bool deletePrinterByName(const QString &name) {
    return db.deletePrinterByName(name);
  }

  bool Database::updatePrinter(const QString &name,
                               const QHash<QString, QVariant> &updates) {
    return db.updatePrinter(name, updates);
  }

 private:
  Database db;

  Facade() {
    //! TODO create if doesn't exist
    QString dbPath =
        QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) +
        "/printers.db";  //! TODO name!
    db(dbPath);
    if (!db.init()) {
      qFatal("Database initialization failed!");
      // TODO make exc
    }
  }
};