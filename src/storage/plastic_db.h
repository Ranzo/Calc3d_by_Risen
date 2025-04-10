#include <QDebug>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class PlasticDB {
 public:
  explicit PlasticDB(const QString &path);
  bool init();
  bool addPlastic(const QString &name, int weight, double cost);
  QHash<QString, QVariant> getPlasticByName(const QString &name);
  bool deletePlasticByName(const QString &name);
  QList<QString> getPlasticList();
  bool updatePlasticByName(const QString &oldName, const QString &newName,
                           int weight, double cost);
  int getPlasticCount();

 private:
  QSqlDatabase db;
};