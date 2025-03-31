#include "printer_db.h"

Database::Database(const QString &dir) {
  QString dbPath = dir + "/printers.sqlite";
  qDebug() << "Database path:" << dbPath;
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(dbPath);
}

bool Database::init() {
  if (!db.open()) {
    qWarning() << "Error opening database:" << db.lastError();
    return false;
  }

  QSqlQuery query;
  query.exec(
      "CREATE TABLE IF NOT EXISTS printers ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
      "name TEXT NOT NULL UNIQUE,"
      "power REAL NOT NULL,"
      "age REAL NOT NULL,"
      "cost REAL NOT NULL)");

  return true;
}

bool Database::addPrinter(const QString &name, double power, double age,
                          double cost) {
  QSqlQuery query;
  query.prepare(
      "INSERT INTO printers (name, power, age, cost) VALUES (:name, :power, "
      ":age, :cost)");
  query.bindValue(":name", name);
  query.bindValue(":power", power);
  query.bindValue(":age", age);
  query.bindValue(":cost", cost);
  return query.exec();
}

QList<QString> Database::getPrinterList() {
  QList<QString> printers;
  QSqlQuery query("SELECT name FROM printers");
  while (query.next()) {
    printers.append({query.value("name").toString()});
  }
  return printers;
}
bool Database::deletePrinterByName(const QString &name) {
  QSqlQuery query;
  query.prepare("DELETE FROM printers WHERE name = :name");
  query.bindValue(":name", name);

  if (!query.exec()) {
    qWarning() << "Delete failed:" << query.lastError().text();
    return false;
  }
  qDebug() << "Delete printer:" << name;
  return query.numRowsAffected() > 0;
}

bool Database::updatePrinterByName(const QString &oldName,
                                   const QString &newName, double power,
                                   int age, double cost) {
  QSqlQuery query;

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

QHash<QString, QVariant> Database::getPrinterByName(const QString &name) {
  QHash<QString, QVariant> printerData;

  QSqlQuery query;
  query.prepare("SELECT * FROM printers WHERE name = :name");
  query.bindValue(":name", name);

  if (!query.exec()) {
    qWarning() << "Error getting printer:" << query.lastError().text();
    return printerData;
  }

  if (query.next()) {
    printerData["name"] = query.value("name").toString();
    printerData["power"] = query.value("power").toDouble();
    printerData["age"] = query.value("age").toDouble();
    printerData["cost"] = query.value("cost").toDouble();
  }

  return printerData;
}