//
// Created by guang19 on 2021/8/26.
//

#include <QColor>
#include <QDebug>
#include <QGridLayout>
#include <QGraphicsDropShadowEffect>
#include "DefaultTitleBar.h"
#include "FramelessWindow.h"

FramelessWidget::FramelessWindow::FramelessWindow(QWidget *parent) : FramelessWidget(parent)
{
    //主区域
    _mainArea = new QWidget(this);
    _mainArea->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    _mainArea->setMouseTracking(true);
    _mainArea->setObjectName(_MAINAREA_OBJECT_NAME);
    _mainArea->setStyleSheet("#MainArea{background-color:#ffffff;}");
    installEventFilter(_mainArea);
    QGridLayout* lyt = dynamic_cast<QGridLayout*>(layout());
    lyt->addWidget(_mainArea,0,0);

    //设置阴影
    QGraphicsDropShadowEffect* dropShadowEffect = new QGraphicsDropShadowEffect(this);
    dropShadowEffect->setColor(QColor("#555555"));
    dropShadowEffect->setOffset(0,0);
    dropShadowEffect->setBlurRadius(20);
    _mainArea->setGraphicsEffect(dropShadowEffect);

    QGridLayout* mainLyt = new QGridLayout(_mainArea);
    mainLyt->setSpacing(0);
    mainLyt->setContentsMargins(0,0,0,0);
    _mainArea->setLayout(mainLyt);

    _titleBar = new DefaultTitleBar(_mainArea);
    mainLyt->addWidget(_titleBar,0,0,Qt::AlignmentFlag::AlignTop);

    _centreWidget = new QWidget(_mainArea);
    mainLyt->addWidget(_centreWidget,1,0,Qt::AlignmentFlag::AlignBottom);

    initConnectionWithTitleBar(_titleBar);
    resize(300,300);
}

void FramelessWidget::FramelessWindow::initConnectionWithTitleBar(AbstractTitleBar *titleBar)
{
    connect(this,&FramelessWindow::setTitleBarHeight,_titleBar,&AbstractTitleBar::setTitleBarHeight);
    connect(this,&FramelessWindow::setTitleBarBGColor,_titleBar,&AbstractTitleBar::setTitleBarBGColor);
    connect(this,&FramelessWindow::setWindowIcon,_titleBar,&AbstractTitleBar::setWindowIcon);
    connect(this,&FramelessWindow::setWindowTitle,_titleBar,&AbstractTitleBar::setWindowTitle);
    connect(this,&FramelessWindow::setWindowTitleAlignCenter,_titleBar,&AbstractTitleBar::setWindowTitleAlignCenter);
    connect(this,&FramelessWindow::setButtonType,_titleBar,&AbstractTitleBar::setButtonType);
    connect(_titleBar,&AbstractTitleBar::onMinimizeButtonClicked,this,&FramelessWindow::onMinimizeButtonClick);
    connect(_titleBar,&AbstractTitleBar::onMaximizeButtonClicked,this,&FramelessWindow::onMaximizeButtonClick);
    connect(_titleBar,&AbstractTitleBar::onCloseButtonClicked,this,&FramelessWindow::onCloseButtonClick);
}

void FramelessWidget::FramelessWindow::destroyConnectionWithTitleBar(AbstractTitleBar *titleBar)
{
    disconnect(this,&FramelessWindow::setTitleBarHeight,_titleBar,&AbstractTitleBar::setTitleBarHeight);
    disconnect(this,&FramelessWindow::setTitleBarBGColor,_titleBar,&AbstractTitleBar::setTitleBarBGColor);
    disconnect(this,&FramelessWindow::setWindowIcon,_titleBar,&AbstractTitleBar::setWindowIcon);
    disconnect(this,&FramelessWindow::setWindowTitle,_titleBar,&AbstractTitleBar::setWindowTitle);
    disconnect(this,&FramelessWindow::setWindowTitleAlignCenter,_titleBar,&AbstractTitleBar::setWindowTitleAlignCenter);
    disconnect(this,&FramelessWindow::setButtonType,_titleBar,&AbstractTitleBar::setButtonType);
    disconnect(_titleBar,&AbstractTitleBar::onMinimizeButtonClicked,this,&FramelessWindow::onMinimizeButtonClick);
    disconnect(_titleBar,&AbstractTitleBar::onMaximizeButtonClicked,this,&FramelessWindow::onMaximizeButtonClick);
    disconnect(_titleBar,&AbstractTitleBar::onCloseButtonClicked,this,&FramelessWindow::onCloseButtonClick);
}

void FramelessWidget::FramelessWindow::setTitleBar(AbstractTitleBar *titleBar)
{
    QGridLayout* lyt = dynamic_cast<QGridLayout*>(_mainArea->layout());
    if (_titleBar != nullptr)
    {
        destroyConnectionWithTitleBar(_titleBar);
        lyt->removeWidget(_titleBar);
        _titleBar->setParent(nullptr);
        delete _titleBar;
    }
    _titleBar = titleBar;
    initConnectionWithTitleBar(titleBar);
    _titleBar->setParent(_mainArea);
    lyt->addWidget(_titleBar,0,0,Qt::AlignmentFlag::AlignTop);
}

void FramelessWidget::FramelessWindow::setCentreWidget(QWidget *centreWidget)
{
    QGridLayout* lyt = dynamic_cast<QGridLayout*>(_mainArea->layout());
    if (_centreWidget != nullptr)
    {
        lyt->removeWidget(_centreWidget);
        _centreWidget->setParent(nullptr);
        delete _centreWidget;
    }
    _centreWidget = centreWidget;
    _centreWidget->setParent(_mainArea);
    lyt->addWidget(_centreWidget,1,0,Qt::AlignmentFlag::AlignBottom);
}

QWidget *FramelessWidget::FramelessWindow::centreWidget() const
{
    return _centreWidget;
}

FramelessWidget::AbstractTitleBar *FramelessWidget::FramelessWindow::titleBar() const
{
    return _titleBar;
}

void FramelessWidget::FramelessWindow::onMinimizeButtonClick()
{
    if (windowState() != Qt::WindowState::WindowMinimized)
    {
        setWindowState(Qt::WindowState::WindowMinimized);
    }
}

void FramelessWidget::FramelessWindow::onMaximizeButtonClick()
{
    if (resizable())
    {
        if (windowState() != Qt::WindowState::WindowMaximized)
        {
            setWindowState(Qt::WindowState::WindowMaximized);
        }
        else
        {
            setWindowState(Qt::WindowState::WindowNoState);
        }
    }
}

void FramelessWidget::FramelessWindow::onCloseButtonClick()
{
    close();
}
