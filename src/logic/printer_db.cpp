#include "printer_db.h"

Database::Database(const QString &path) {
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(path);
}

bool Database::init() {
  if (!db.open()) {
    qWarning() << "Error opening database:" << db.lastError();
    // TODO return ERROR
    return false;
  }

  QSqlQuery query;
  return query.exec(
      "CREATE TABLE IF NOT EXISTS printers ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
      "name TEXT NOT NULL UNIQUE,"
      "power REAL NOT NULL,"  //! int??
      "age INTEGER NOT NULL,"
      "cost REAL NOT NULL");
}

bool Database::addPrinter(const QString &name, double power, int age,
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
    printers.append({query.value(0).toString()});
  }
  return printers;
}
bool Database::deletePrinterByName(const QString &name) {
  QSqlQuery query;
  query.prepare("DELETE FROM printers WHERE name = :name");
  query.bindValue(":name", name);

  if (!query.exec()) {
    // TODO exc
    qWarning() << "Delete failed:" << query.lastError().text();
    return false;
  }

  // была ли удалена хотя бы одна запись?
  return query.numRowsAffected() > 0;
}

bool Database::updatePrinter(const QString &name,
                                    const QHash<QString, QVariant> &updates) {
  QStringList setClauses;
  QSqlQuery query;

  for (auto it = updates.begin(); it != updates.end(); ++it) {
    setClauses << QString("%1 = :%2").arg(it.key(), it.key());
    query.bindValue(":" + it.key(), it.value());
  }

  query.prepare("UPDATE printers SET " + setClauses.join(", ") +
                " WHERE name = :name");
  query.bindValue(":name", name);

  return query.exec();

  //! Как создать новое из фасада:
  // !проще забрать сразу все
  //   QHash<QString, QVariant> updates;
  // updates["power"] = 350.0;
  // updates["cost"] = 27000.0;
  // db->updatePrinterPartial("MyPrinter", updates);
}
