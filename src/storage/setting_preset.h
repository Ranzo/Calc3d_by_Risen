#include <QSettings>

class SettingPreset {
 public:
  explicit SettingPreset(const QString& dir);

  bool updateSettings(double tarif, double qTrash, double overprice);

  QHash<QString, QVariant> getSettings();

 private:
  QString filePath;
  QSettings::Format format = QSettings::NativeFormat;
};