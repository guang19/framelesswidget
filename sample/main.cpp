#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QColor>
#include <QDir>
#include "../src/FramelessWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    FramelessWidget::FramelessWindow *w = new FramelessWidget::FramelessWindow;
//    w->setResizable(false);
    w->setWindowTitleAlignCenter(false);
//    w->setTitleBarBGColor(QColor("#dee0e2").rgba());
//    w->setTitleBarBGColor(QColor(0,0,0,0).rgba());

    w->setButtonType(FramelessWidget::WindowButtonType::MinimizeButton);
    w->setButtonType(FramelessWidget::WindowButtonType::MaximizeButton);
    w->setButtonType(FramelessWidget::WindowButtonType::MinimizeMaximizeButton);
//    w->setButtonType(FramelessWidget::WindowButtonType::MaximizeButton);
//    w->setButtonType(FramelessWidget::WindowButtonType::MinimizeButton);
//    w->setButtonType(FramelessWidget::WindowButtonType::MaximizeButton);
    w->show();
    return QApplication::exec();
}
