#include <QApplication>

#include "Views/View.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  View calc;
  calc.show();

  return a.exec();
}
