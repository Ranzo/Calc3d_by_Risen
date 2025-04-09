#include <QApplication>

#include "view/main_window.h"

int main(int argc, char *argv[]) {
  QLocale::setDefault(QLocale::C);
  QApplication app(argc, argv);
  try {
    auto facade = Facade::GetInstance();
    facade->updateSettings(1.5, 1, 100);
    MainWindow window(facade);
    window.show();
    return app.exec();
  } catch (const std::exception &ex) {
    QMessageBox::critical(nullptr, QApplication::tr("Fatal Error"),
                          QApplication::tr("Application failed with error:\n%1")
                              .arg(QString::fromUtf8(ex.what())));
    return EXIT_FAILURE;
  }
}
