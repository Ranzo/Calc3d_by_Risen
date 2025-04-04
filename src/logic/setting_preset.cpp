#include "setting_preset.h"

SettingPreset::SettingPreset(const QString& dir)
    : filePath(dir + "/settings_preset.xml") {
  qDebug() << "Setting preset file path:" << filePath;
}

bool SettingPreset::updateSettings(double tarif, double qTrash,
                                   double pricePlastik, double overprice,
                                   int weightPlastik) {
  QSettings settings(filePath, format);

  settings.setValue("tarif", tarif);
  settings.setValue("qTrash", qTrash);
  settings.setValue("pricePlastik", pricePlastik);
  settings.setValue("overprice", overprice);
  settings.setValue("weightPlastik", weightPlastik);

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
  settingData["pricePlastik"] = settings.value("pricePlastik", 0.0).toDouble();
  settingData["overprice"] = settings.value("overprice", 0.0).toDouble();
  settingData["weightPlastik"] = settings.value("weightPlastik", 0).toInt();

  return settingData;
}