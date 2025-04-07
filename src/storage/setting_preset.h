#include <QSettings>

class SettingPreset {
 public:
  explicit SettingPreset(const QString& dir);

  bool updateSettings(double tarif, double qTrash, double overprice);

  QHash<QString, QVariant> getSettings();

  QHash<QString, QVariant> getUserLastChoice();

  void updateUserChoice(QString& printer, QString& plastic);

 private:
  QString filePath;
  QSettings::Format format = QSettings::NativeFormat;
};