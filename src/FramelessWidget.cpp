//
// Created by guang19 on 2021/8/25.
//

#include <QGridLayout>
#include <QMouseEvent>
#include <QDebug>

#ifdef Q_OS_WIN
#include <QByteArray>
#include <windows.h>
#include <windowsx.h>
#include <winuser.h>
#endif

#include "FramelessWidget.h"


FramelessWidget::FramelessWidget::FramelessWidget(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(this->windowFlags() | Qt::WindowType::FramelessWindowHint);
    setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    setAttribute(Qt::WidgetAttribute::WA_TranslucentBackground);
    setMouseTracking(true);
    installEventFilter(this);

    _resizable = true;
    _isPress = false;
#ifdef Q_OS_LINUX
    _resizingCornerEdge = XUtils::CornerEdge::kInvalid;
#endif
    //设置Layout
    QGridLayout* layout = new QGridLayout(this);
    layout->setSpacing(0);
    //给窗口边框留出resize范围
    layout->setContentsMargins(_RESIZE_HANDLE_SIZE,_RESIZE_HANDLE_SIZE,_RESIZE_HANDLE_SIZE,_RESIZE_HANDLE_SIZE);
    setLayout(layout);
}

void FramelessWidget::FramelessWidget::mousePressEvent(QMouseEvent *event)
{
#ifdef Q_OS_LINUX
    const int x = event->x();
    const int y = event->y();
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
#ifdef Q_OS_WIN
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        _isPress = true;
        _pressPos = event->pos();
    }
#endif
    return QWidget::mousePressEvent(event);
}

void FramelessWidget::FramelessWidget::mouseReleaseEvent(QMouseEvent *event)
{
    _isPress = false;
#ifdef Q_OS_LINUX
    _resizingCornerEdge = XUtils::CornerEdge::kInvalid;
#endif
#ifdef Q_OS_WIN
    _pressPos = QPoint(0,0);
#endif
    return QWidget::mouseReleaseEvent(event);
}

void FramelessWidget::FramelessWidget::mouseMoveEvent(QMouseEvent *event)
{
#ifdef Q_OS_LINUX
    const int x = event->x();
    const int y = event->y();
    if(_resizable)
    {
        //改变鼠标在窗体各个部分的的shape
        if (_resizingCornerEdge == XUtils::CornerEdge::kInvalid)
        {
            XUtils::UpdateCursorShape(this,x,y,this->layout()->contentsMargins(),_RESIZE_HANDLE_SIZE);
        }
    }
#endif
#ifdef Q_OS_WIN
    if(_isPress)
    {
        move(event->pos() + pos() - _pressPos);
    }
#endif
    return QWidget::mouseMoveEvent(event);
}

void FramelessWidget::FramelessWidget::resizeEvent(QResizeEvent *event)
{
#ifdef Q_OS_LINUX
    XUtils::SetWindowExtents(this,this->layout()->contentsMargins(),_RESIZE_HANDLE_SIZE);
#endif

    QWidget::resizeEvent(event);
}


bool FramelessWidget::FramelessWidget::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    if (_resizable)
    {
#ifdef Q_OS_WIN
        MSG* msg = (MSG*)message;
    switch(msg->message)
    {
        case WM_NCHITTEST:
            int x = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
			int y = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
			int nUseFulWidth = width() - _RESIZE_HANDLE_SIZE;
			int nUseFulHeight = height() - _RESIZE_HANDLE_SIZE;
			if (x < _RESIZE_HANDLE_SIZE && y < _RESIZE_HANDLE_SIZE)	//左上角
				*result = HTTOPLEFT;
			else if (x>= nUseFulWidth && y < _RESIZE_HANDLE_SIZE)	//右上角
				*result = HTTOPRIGHT;
			else if (x < _RESIZE_HANDLE_SIZE && y >= nUseFulHeight)	//左下角
				*result = HTBOTTOMLEFT;
			else if (x >= nUseFulWidth && y >= nUseFulHeight)	//右下角
				*result = HTBOTTOMRIGHT;
			else if (x < _RESIZE_HANDLE_SIZE)	//左边
				*result =  HTLEFT;
			else if (x >= nUseFulWidth)	//右边
				*result = HTRIGHT;
			else if (y < _RESIZE_HANDLE_SIZE)	//上边
				*result = HTTOP;
			else if (y >= nUseFulHeight)	//下边
				*result = HTBOTTOM;
			else
				return false;
			return true;
    }
#endif
    }
    return QWidget::nativeEvent(eventType,message,result);
}

void FramelessWidget::FramelessWidget::setResizable(bool resizable)
{
    _resizable = resizable;
}

bool FramelessWidget::FramelessWidget::resizable() const
{
    return _resizable;
}
