#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Database {
 public:
  Database(const QString &path);
  bool init();
  bool addPrinter(const QString &name, double power, int age, double cost);
  bool deletePrinterByName(const QString &name);
  QList<QString> getPrinterList();
  bool updatePrinter(const QString &name,
                               const QHash<QString, QVariant> &updates);

 private:
  QSqlDatabase db;
};