#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class PrinterDB {
 public:
  explicit PrinterDB(const QString &path);
  bool init();
  bool addPrinter(const QString &name, double power, double age, double cost);
  QHash<QString, QVariant> getPrinterByName(const QString &name);
  bool deletePrinterByName(const QString &name);
  QList<QString> getPrinterList();
  bool updatePrinterByName(const QString &oldName, const QString &newName,
                           double power, int age, double cost);

 private:
  QSqlDatabase db;
};