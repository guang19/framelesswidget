//
// Created by guang19 on 2021/8/26.
//

#ifndef FRAMELESSWINDOW_H
#define FRAMELESSWINDOW_H

#include "FramelessWidget.h"
#include "AbstractTitleBar.h"

namespace FW
{
#define _MAINAREA_OBJECT_NAME "MainArea"
    class FramelessWindow : public FramelessWidget
    {
        Q_OBJECT
        public:
            explicit FramelessWindow(QWidget*  = nullptr);
            ~FramelessWindow() = default;

        private:
            void initConnectionWithTitleBar(AbstractTitleBar* titleBar);
            void destroyConnectionWithTitleBar(AbstractTitleBar* titleBar);

        public:
            void setTitleBar(AbstractTitleBar* titleBar);
            AbstractTitleBar* titleBar() const;
            void setCentreWidget(QWidget* centreWidget);
            QWidget* centreWidget() const;

        signals:
            void setTitleBarHeight(int height);
            void setTitleBarBGColor(QRgb rgba);
            void setWindowTitle(const QString& title);
            void setWindowIcon(const QIcon &icon);
            void setWindowTitleAlignCenter(bool centreAlign = true);
            void setButtonType(WindowButtonType windowButtonType);

        private slots:
            //窗口事件
            void onMinimizeButtonClick();
            void onMaximizeButtonClick();
            void onCloseButtonClick();

        private:
            //主区域
            QWidget* _mainArea;
            //标题栏
            AbstractTitleBar* _titleBar;
            //客户区centreWidget
            QWidget* _centreWidget;
    };
}

#endif //FRAMELESSWINDOW_H
