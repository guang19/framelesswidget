//
// Created by guang19 on 2021/8/25.
//

#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include <QWidget>
#include <QtGlobal>
#include <QPoint>
#ifdef Q_OS_LINUX
#include "platform/x11/xutil.h"
#endif


namespace FW
{
    //窗口缩放resize时的边框范围
    #define _RESIZE_HANDLE_SIZE 10

    class FramelessWidget : public QWidget
    {
        Q_OBJECT
        public:
            explicit FramelessWidget(QWidget* parent = nullptr);
            ~FramelessWidget() = default;

        public:
            //设置可缩放的（这个函数不能限制系统的边缘动作，只能限制按钮级别的事件），如果想取消边缘放大，并列等一系列系统事件，最好直接setFixedSize
            void setResizable(bool resizable);
            bool resizable() const;

        protected:
            //重写窗口事件逻辑
            void mousePressEvent(QMouseEvent *event) override;
            void mouseReleaseEvent(QMouseEvent *event) override;
            void mouseMoveEvent(QMouseEvent *event) override;
            void resizeEvent(QResizeEvent *event) override;

        private:
#ifdef Q_OS_LINUX
            //resize方向
            XUtils::CornerEdge _resizingCornerEdge;
#endif
            //当前鼠标是否按下
            bool _isPress;

            //是否允许缩放
            bool _resizable;
    };

}

#endif //FRAMELESSWIDGET_H
