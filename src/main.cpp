#include <QApplication>

#include "view/main_window.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  // MainWindow window(s21::Controller::GetInstance());
  MainWindow window;
  window.show();
  return app.exec();
}
