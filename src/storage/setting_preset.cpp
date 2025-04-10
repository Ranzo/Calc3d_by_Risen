#include "setting_preset.h"

SettingPreset::SettingPreset(const QString& dir)
    : filePath(dir + QDir::separator() + "settings_preset.ini") {
  qDebug() << "Setting preset file path:" << filePath;
}

bool SettingPreset::updateSettings(double tarif, double qTrash,
                                   double overprice) {
  QSettings settings(filePath, format);

  settings.setValue("tarif", tarif);
  settings.setValue("qTrash", qTrash);
  settings.setValue("overprice", overprice);

  if (settings.status() != QSettings::NoError) {
    qCritical() << "Error saving settings";
    return false;
  }

  return true;
}

QHash<QString, QVariant> SettingPreset::getSettings() {
  QHash<QString, QVariant> settingData;
  QSettings settings(filePath, format);

  settingData["tarif"] = settings.value("tarif", 0.0).toDouble();
  settingData["qTrash"] = settings.value("qTrash", 0.0).toDouble();
  settingData["overprice"] = settings.value("overprice", 0.0).toDouble();

  return settingData;
}

QHash<QString, QVariant> SettingPreset::getUserLastChoice() {
  QHash<QString, QVariant> settingData;
  QSettings settings(filePath, format);

  settingData["lastPrinter"] = settings.value("lastPrinter", "").toString();
  settingData["lastPlastic"] = settings.value("lastPlastic", "").toString();

  return settingData;
}

void SettingPreset::updateUserChoice(QString& printer, QString& plastic) {
  QSettings settings(filePath, format);

  settings.setValue("lastPrinter", printer);
  settings.setValue("lastPlastic", plastic);
}