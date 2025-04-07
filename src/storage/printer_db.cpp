#include "printer_db.h"

PrinterDB::PrinterDB(const QString &dir) {
  QString dbPath = dir + "/printers.sqlite";
  qDebug() << "PrinterDB path:" << dbPath;
  db = QSqlDatabase::addDatabase("QSQLITE", "printers_db");
  db.setDatabaseName(dbPath);
}

bool PrinterDB::init() {
  if (!db.open()) {
    qWarning() << "Error opening PrinterDB:" << db.lastError();
    return false;
  }

  QSqlQuery query(db);
  query.exec(
      "CREATE TABLE IF NOT EXISTS printers ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
      "name TEXT UNIQUE,"
      "power INTEGER,"
      "age REAL,"
      "cost REAL)");

  return true;
}

bool PrinterDB::addPrinter(const QString &name, int power, double age,
                           double cost) {
  QSqlQuery query(db);
  query.prepare(
      "INSERT INTO printers (name, power, age, cost) VALUES (:name, :power, "
      ":age, :cost)");
  query.bindValue(":name", name);
  query.bindValue(":power", power);
  query.bindValue(":age", age);
  query.bindValue(":cost", cost);
  return query.exec();
}

QList<QString> PrinterDB::getPrinterList() {
  QList<QString> printers;
  QSqlQuery query(db);
  if (!query.exec("SELECT name FROM printers")) {
    qWarning() << "Error getting printers:" << query.lastError().text();
    return printers;
  }
  while (query.next()) {
    printers.append(query.value("name").toString());
  }
  return printers;
}

bool PrinterDB::deletePrinterByName(const QString &name) {
  QSqlQuery query(db);
  query.prepare("DELETE FROM printers WHERE name = :name");
  query.bindValue(":name", name);

  if (!query.exec()) {
    qWarning() << "Delete failed:" << query.lastError().text();
    return false;
  }
  qDebug() << "Delete printer:" << name;
  return query.numRowsAffected() > 0;
}

bool PrinterDB::updatePrinterByName(const QString &oldName,
                                    const QString &newName, int power, int age,
                                    double cost) {
  QSqlQuery query(db);

  query.prepare(
      "UPDATE printers SET "
      "name = :newName, "
      "power = :power, "
      "age = :age, "
      "cost = :cost "
      "WHERE name = :oldName");

  query.bindValue(":oldName", oldName);
  query.bindValue(":newName", newName);
  query.bindValue(":power", power);
  query.bindValue(":age", age);
  query.bindValue(":cost", cost);

  if (!query.exec()) {
    qCritical() << "Error updating printer:" << oldName;
    return false;
  }

  return query.numRowsAffected() > 0;
}

QHash<QString, QVariant> PrinterDB::getPrinterByName(const QString &name) {
  QHash<QString, QVariant> printerData;

  QSqlQuery query(db);
  query.prepare("SELECT * FROM printers WHERE name = :name");
  query.bindValue(":name", name);

  if (!query.exec()) {
    qWarning() << "Error getting printer:" << query.lastError().text();
    return printerData;
  }

  if (query.next()) {
    printerData["name"] = query.value("name").toString();
    printerData["power"] = query.value("power").toInt();
    printerData["age"] = query.value("age").toDouble();
    printerData["cost"] = query.value("cost").toDouble();
  }

  return printerData;
}