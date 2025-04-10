#include "plastic_db.h"

PlasticDB::PlasticDB(const QString &dir) {
  QString dbPath = dir + QDir::separator() + "plastics.sqlite";
  qDebug() << "PlasticDB path:" << dbPath;
  db = QSqlDatabase::addDatabase("QSQLITE", "plastics_db");
  db.setDatabaseName(dbPath);
}

bool PlasticDB::init() {
  if (!db.open()) {
    qWarning() << "Error opening PlasticDB:" << db.lastError();
    return false;
  }

  QSqlQuery query(db);
  query.exec(
      "CREATE TABLE IF NOT EXISTS plastics ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
      "name TEXT UNIQUE,"
      "weight INTEGER,"
      "cost REAL)");

  return true;
}

bool PlasticDB::addPlastic(const QString &name, int weight, double cost) {
  QSqlQuery query(db);
  query.prepare(
      "INSERT INTO plastics (name, weight, cost) VALUES (:name, :weight, "
      ":cost)");
  query.bindValue(":name", name);
  query.bindValue(":weight", weight);
  query.bindValue(":cost", cost);
  return query.exec();
}

QList<QString> PlasticDB::getPlasticList() {
  QList<QString> plastics;
  QSqlQuery query(db);
  if (!query.exec("SELECT name FROM plastics")) {
    qWarning() << "Error getting plastics:" << query.lastError().text();
    return plastics;
  }
  while (query.next()) {
    plastics.append(query.value("name").toString());
  }
  return plastics;
}

bool PlasticDB::deletePlasticByName(const QString &name) {
  QSqlQuery query(db);
  query.prepare("DELETE FROM plastics WHERE name = :name");
  query.bindValue(":name", name);

  if (!query.exec()) {
    qWarning() << "Delete failed:" << query.lastError().text();
    return false;
  }
  qDebug() << "Delete plastic:" << name;
  return query.numRowsAffected() > 0;
}

bool PlasticDB::updatePlasticByName(const QString &oldName,
                                    const QString &newName, int weight,
                                    double cost) {
  QSqlQuery query(db);

  query.prepare(
      "UPDATE plastics SET "
      "name = :newName, "
      "weight = :weight, "
      "cost = :cost "
      "WHERE name = :oldName");

  query.bindValue(":oldName", oldName);
  query.bindValue(":newName", newName);
  query.bindValue(":weight", weight);
  query.bindValue(":cost", cost);

  if (!query.exec()) {
    qWarning() << "Error updating printer:" << oldName;
    return false;
  }

  return query.numRowsAffected() > 0;
}

QHash<QString, QVariant> PlasticDB::getPlasticByName(const QString &name) {
  QHash<QString, QVariant> printerData;

  QSqlQuery query(db);
  query.prepare("SELECT * FROM plastics WHERE name = :name");
  query.bindValue(":name", name);

  if (!query.exec()) {
    qWarning() << "Error getting printer:" << query.lastError().text();
    return printerData;
  }

  if (query.next()) {
    printerData["name"] = query.value("name").toString();
    printerData["weight"] = query.value("weight").toInt();
    printerData["cost"] = query.value("cost").toDouble();
  }

  return printerData;
}

int PlasticDB::getPlasticCount() {
  QSqlQuery query(db);
  query.prepare("SELECT COUNT(*) FROM plastics;");

  if (!query.exec()) {
    qWarning() << "Error counting plastics: " << query.lastError().text();
    return -1;
  }

  if (query.next()) return query.value(0).toInt();

  return 0;
}