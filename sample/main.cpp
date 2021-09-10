#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QColor>
#include <QDir>
#include "DemoWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    DemoWindow* w = new DemoWindow;
    w->resize(300,300);
    w->setWindowTitle("DemoWindow");
    w->setTitleBarBGColor(QColor("red").rgb());
    w->show();
    return QApplication::exec();
}
