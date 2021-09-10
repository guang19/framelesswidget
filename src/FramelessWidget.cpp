//
// Created by guang19 on 2021/8/25.
//

#include <QGridLayout>
#include <QMouseEvent>
#include <QDebug>
#include "FramelessWidget.h"


FW::FramelessWidget::FramelessWidget(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::WindowType::FramelessWindowHint);
    setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    setMouseTracking(true);
    installEventFilter(this);
#ifdef Q_OS_LINUX
    setAttribute(Qt::WidgetAttribute::WA_TranslucentBackground);
    _resizingCornerEdge = XUtils::CornerEdge::kInvalid;
#endif
    _resizable = true;
    _isPress = false;
    //设置Layout
    QGridLayout* layout = new QGridLayout(this);
    layout->setSpacing(0);
    //给窗口边框留出resize范围
#ifdef Q_OS_LINUX
    layout->setContentsMargins(_RESIZE_HANDLE_SIZE,_RESIZE_HANDLE_SIZE,_RESIZE_HANDLE_SIZE,_RESIZE_HANDLE_SIZE);
#endif
    setLayout(layout);

}

void FW::FramelessWidget::mousePressEvent(QMouseEvent *event)
{
    const int x = event->x();
    const int y = event->y();
#ifdef Q_OS_LINUX
    if (event->button() == Qt::MouseButton::LeftButton)
    {
        _isPress = true;
        //获取缩放方向
        const XUtils::CornerEdge rce = XUtils::GetCornerEdge(this,x,y,this->layout()->contentsMargins(),_RESIZE_HANDLE_SIZE);
        //如果鼠标不处于缩放边缘，那么移动窗口
        if(rce == XUtils::CornerEdge::kInvalid)
        {
            //需要在move或resize时调用此函数通知系统鼠标抬起的事件，否则窗口会收不到这个事件
            XUtils::SendButtonRelease(this,event->pos(),event->globalPos());
            XUtils::MoveWindow(this,Qt::MouseButton::LeftButton);
        }
        //缩放
        else
        {
            if (_resizable)
            {
                _resizingCornerEdge = rce;
                XUtils::SendButtonRelease(this,event->pos(),event->globalPos());
                //x函数开始缩放
                XUtils::StartResizing(this,QCursor::pos(),rce);
            }
        }
    }
#endif
    return QWidget::mousePressEvent(event);
}

void FW::FramelessWidget::mouseReleaseEvent(QMouseEvent *event)
{
    _isPress = false;
#ifdef Q_OS_LINUX
    _resizingCornerEdge = XUtils::CornerEdge::kInvalid;
#endif
    return QWidget::mouseReleaseEvent(event);
}

void FW::FramelessWidget::mouseMoveEvent(QMouseEvent *event)
{
#ifdef Q_OS_LINUX
    const int x = event->x();
    const int y = event->y();
    if(_resizable)
    {
        //改变鼠标在窗体各个部分的shape
        if (_resizingCornerEdge == XUtils::CornerEdge::kInvalid)
        {
            XUtils::UpdateCursorShape(this,x,y,this->layout()->contentsMargins(),_RESIZE_HANDLE_SIZE);
        }
    }
#endif
    return QWidget::mouseMoveEvent(event);
}

void FW::FramelessWidget::resizeEvent(QResizeEvent *event)
{
#ifdef Q_OS_LINUX
    XUtils::SetWindowExtents(this,this->layout()->contentsMargins(),_RESIZE_HANDLE_SIZE);
#endif
    QWidget::resizeEvent(event);
}

void FW::FramelessWidget::setResizable(bool resizable)
{
    _resizable = resizable;
}

bool FW::FramelessWidget::resizable() const
{
    return _resizable;
}
