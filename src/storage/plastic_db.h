#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class PlasticDB {
 public:
  explicit PlasticDB(const QString &path);
  bool init();
  bool addPlastic(const QString &name, double weight, double cost);
  QHash<QString, QVariant> getPlasticByName(const QString &name);
  bool deletePlasticByName(const QString &name);
  QList<QString> getPlasticList();
  bool updatePlasticByName(const QString &oldName, const QString &newName,
                           double weight, double cost);

 private:
  QSqlDatabase db;
};