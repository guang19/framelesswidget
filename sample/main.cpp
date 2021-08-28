#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QDir>
#include "../src/FramelessWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    FramelessWidget::FramelessWindow *w = new FramelessWidget::FramelessWindow;
//    w->setResizable(false);
    w->setWindowTitleAlignCenter(false);
    w->setButtonType(FramelessWidget::WindowButtonType::MinimizeButton);
    w->setButtonType(FramelessWidget::WindowButtonType::MaximizeButton);
    w->setButtonType(FramelessWidget::WindowButtonType::MinimizeMaximizeButton);
//    w->setButtonType(FramelessWidget::WindowButtonType::MaximizeButton);
//    w->setButtonType(FramelessWidget::WindowButtonType::MinimizeButton);
//    w->setButtonType(FramelessWidget::WindowButtonType::MaximizeButton);
    w->show();
    return QApplication::exec();
}
