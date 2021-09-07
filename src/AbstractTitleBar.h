//
// Created by guang19 on 2021/8/26.
//

#ifndef ABSTRACTTITLEBAR_H
#define ABSTRACTTITLEBAR_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>

namespace FramelessWidget
{
    //窗口按钮类型（无论何种类型都会伴随close按钮）
    enum WindowButtonType
    {
        MinimizeButton = 0,
        MinimizeMaximizeButton,
        MaximizeButton
    };

    class AbstractTitleBar : public QWidget
    {
            Q_OBJECT
        public:
            explicit AbstractTitleBar(QWidget* parent = nullptr);
            ~AbstractTitleBar() = default;

        public slots:
            //设置标题栏高度
            virtual void setTitleBarHeight(int height) = 0;
            //设置标题栏背景颜色
            virtual void setTitleBarBGColor(QRgb rgba) = 0;
            //设置背景标题栏背景颜色
            //设置窗口Icon
            virtual void setWindowIcon(const QIcon &icon) = 0;
            //设置窗口标题
            virtual void setWindowTitle(const QString& title) = 0;
            //设置窗口标题是否居中
            virtual void setWindowTitleAlignCenter(bool centreAlign) = 0;
            //设置窗口按钮类型
            virtual void setButtonType(WindowButtonType windowButtonType) = 0;

            //窗口事件
            void onMinimizeButtonClick();
            void onMaximizeButtonClick();
            void onCloseButtonClick();

        public:
            signals:
            void onMinimizeButtonClicked();
            void onMaximizeButtonClicked();
            void onCloseButtonClicked();

        protected:
            void mouseDoubleClickEvent(QMouseEvent *event) override;

        protected:
            //title是否需要居中对齐
            bool _titleCentreAlign;
            QLabel* _title;
            QLabel* _icon;
            WindowButtonType _windowButtonType;
            QPushButton* _minimizeButton;
            QPushButton* _maximizeButton;
            QPushButton* _closeButton;
    };
}

#endif //ABSTRACTTITLEBAR_H
