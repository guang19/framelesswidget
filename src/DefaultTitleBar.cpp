//
// Created by guang19 on 2021/8/27.
//

#include <QHBoxLayout>
#include <QFont>
#include <QChar>
#include <QDebug>
#include "uihelper.h"
#include "DefaultTitleBar.h"

FramelessWidget::DefaultTitleBar::DefaultTitleBar(QWidget *parent) : AbstractTitleBar(parent)
{
    setFixedHeight(_TITLEBAR_HEIGHT);
    setObjectName(_TITLEBAR_OBJECT_NAME);
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(3,0,3,0);
    setLayout(layout);

    _titleCentreAlign = true;
    _windowButtonType = WindowButtonType::MinimizeMaximizeButton;

    _icon = new QLabel(this);
    _icon->setFixedSize(_WINDOW_ICON_SIZE);
    QPixmap pic(":/img/dog.jpg");
    _icon->setPixmap(pic.scaled(_icon->size(),Qt::AspectRatioMode::KeepAspectRatioByExpanding,Qt::TransformationMode::SmoothTransformation));
    layout->addWidget(_icon,0,Qt::AlignmentFlag::AlignLeft | Qt::AlignmentFlag::AlignVCenter);

    _title = new QLabel("FramelessWidget",this);
    layout->addSpacing(15);
    layout->addWidget(_title,1,Qt::AlignmentFlag::AlignCenter);
    layout->addSpacing(15);

    QFont buttonFont = UIHelper::instance()->getIconFont(_WINDOW_BUTTON_ICONFONT);
    _minimizeButton = new QPushButton(this);
    _minimizeButton->setObjectName(_MINIMIZE_BUTTON_OBJECT_NAME);
    _minimizeButton->setFlat(true);
    _minimizeButton->setFont(buttonFont);
    _minimizeButton->setText(QChar(_MINIMIZE_BUTTON_FONT_INDEX));
    _minimizeButton->setFixedSize(_WINDOW_BUTTON_SIZE);
    layout->addWidget(_minimizeButton,0,Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter);
    layout->addSpacing(3);

    _maximizeButton = new QPushButton(this);
    _maximizeButton->setObjectName(_MAXIMIZE_BUTTON_OBJECT_NAME);
    _maximizeButton->setFont(buttonFont);
    _maximizeButton->setText(QChar(_MAXIMIZE_BUTTON_FONT_INDEX));
    _maximizeButton->setFixedSize(_WINDOW_BUTTON_SIZE);
    layout->addWidget(_maximizeButton,0,Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter);
    layout->addSpacing(3);

    _closeButton = new QPushButton(this);
    _closeButton->setObjectName(_CLOSE_BUTTON_OBJECT_NAME);
    _closeButton->setFont(buttonFont);
    _closeButton->setText(QChar(_CLOSE_BUTTON_FONT_INDEX));
    _closeButton->setFixedSize(_WINDOW_BUTTON_SIZE);
    layout->addWidget(_closeButton,0,Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter);

    connect(_minimizeButton,&QPushButton::clicked,this,&AbstractTitleBar::onMinimizeButtonClick);
    connect(_maximizeButton,&QPushButton::clicked,this,&AbstractTitleBar::onMaximizeButtonClick);
    connect(_closeButton,&QPushButton::clicked,this,&AbstractTitleBar::onCloseButtonClick);

    setAutoFillBackground(true);
    setAttribute(Qt::WidgetAttribute::WA_StyledBackground);
    UIHelper::instance()->setStyleSheet(this,":/qss/DefaultTitleBar.qss");
}

void FramelessWidget::DefaultTitleBar::setWindowTitle(const QString &title)
{
    _title->setText(title);
}

void FramelessWidget::DefaultTitleBar::setWindowIcon(const QIcon &icon)
{
    _icon->setPixmap(icon.pixmap(_WINDOW_ICON_SIZE));
}

void FramelessWidget::DefaultTitleBar::setWindowTitleAlignCenter(bool centreAlign)
{
    if (centreAlign)
    {
        if (!_titleCentreAlign)
        {
            QHBoxLayout* lyt = dynamic_cast<QHBoxLayout*>(layout());
            lyt->setAlignment(_title,Qt::AlignmentFlag::AlignCenter);
        }
    }
    else
    {
        if (_titleCentreAlign)
        {
            QHBoxLayout* lyt = dynamic_cast<QHBoxLayout*>(layout());
            lyt->setAlignment(_title,Qt::AlignmentFlag::AlignLeft | Qt::AlignVCenter);
        }
    }
}

void FramelessWidget::DefaultTitleBar::setButtonType(FramelessWidget::WindowButtonType windowButtonType)
{
    if (_windowButtonType == windowButtonType)
    {
        return;
    }
    QHBoxLayout* lyt = dynamic_cast<QHBoxLayout*>(layout());
    switch (windowButtonType)
    {
        case WindowButtonType::MinimizeMaximizeButton:
            if (_windowButtonType == WindowButtonType::MaximizeButton)
            {
                //添加最小化按钮以及右边的spacing
                int index = lyt->indexOf(_maximizeButton);
                _minimizeButton = new QPushButton(this);
                _minimizeButton->setObjectName(_MINIMIZE_BUTTON_OBJECT_NAME);
                _minimizeButton->setFont(UIHelper::instance()->getIconFont(_WINDOW_BUTTON_ICONFONT));
                _minimizeButton->setText(QChar(_MINIMIZE_BUTTON_FONT_INDEX));
                _minimizeButton->setFixedSize(_WINDOW_BUTTON_SIZE);
                connect(_minimizeButton,&QPushButton::clicked,this,&AbstractTitleBar::onMinimizeButtonClick);
                lyt->insertWidget(index ,_minimizeButton,0,Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter);
                lyt->insertSpacing(index + 1,3);
            }
            else if (_windowButtonType == WindowButtonType::MinimizeButton)
            {
                //添加最大化按钮
                int index = lyt->indexOf(_closeButton);
                _maximizeButton = new QPushButton(this);
                _maximizeButton->setObjectName(_MAXIMIZE_BUTTON_OBJECT_NAME);
                _maximizeButton->setFont(UIHelper::instance()->getIconFont(_WINDOW_BUTTON_ICONFONT));
                _maximizeButton->setText(QChar(_MAXIMIZE_BUTTON_FONT_INDEX));
                _maximizeButton->setFixedSize(_WINDOW_BUTTON_SIZE);
                connect(_maximizeButton,&QPushButton::clicked,this,&AbstractTitleBar::onMaximizeButtonClick);
                lyt->insertWidget(index,_maximizeButton,0,Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter);
                lyt->insertSpacing(index + 1,3);
            }
            break;
        case WindowButtonType::MinimizeButton:
            if (_windowButtonType == WindowButtonType::MinimizeMaximizeButton)
            {
                //移除最大化按钮和最大化按钮右边的spacing
                disconnect(_maximizeButton,&QPushButton::clicked,this,&AbstractTitleBar::onMaximizeButtonClick);
                int index = lyt->indexOf(_maximizeButton);
                lyt->removeItem(lyt->itemAt(index + 1));
                lyt->removeWidget(_maximizeButton);
                _maximizeButton->setParent(nullptr);
                delete _maximizeButton;
                _maximizeButton = nullptr;
            }
            else if(_windowButtonType == WindowButtonType::MaximizeButton)
            {
                //移除最大化按钮，改为最小化按钮
                disconnect(_maximizeButton,&QPushButton::clicked,this,&AbstractTitleBar::onMaximizeButtonClick);
                int index = lyt->indexOf(_maximizeButton);
                lyt->removeWidget(_maximizeButton);
                _maximizeButton->setParent(nullptr);
                delete _maximizeButton;
                _maximizeButton = nullptr;
                _minimizeButton = new QPushButton(this);
                _minimizeButton->setObjectName(_MINIMIZE_BUTTON_OBJECT_NAME);
                _minimizeButton->setFont(UIHelper::instance()->getIconFont(_WINDOW_BUTTON_ICONFONT));
                _minimizeButton->setText(QChar(_MINIMIZE_BUTTON_FONT_INDEX));
                _minimizeButton->setFixedSize(_WINDOW_BUTTON_SIZE);
                connect(_minimizeButton,&QPushButton::clicked,this,&AbstractTitleBar::onMinimizeButtonClick);
                lyt->insertWidget(index,_minimizeButton,0,Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter);
            }
            break;
        case WindowButtonType::MaximizeButton:
            if (_windowButtonType == WindowButtonType::MinimizeMaximizeButton)
            {
                //移除最小化按钮过河最小化按钮右边的spacing
                disconnect(_minimizeButton,&QPushButton::clicked,this,&AbstractTitleBar::onMinimizeButtonClick);
                int index = lyt->indexOf(_minimizeButton);
                lyt->removeItem(lyt->itemAt(index + 1));
                lyt->removeWidget(_minimizeButton);
                _minimizeButton->setParent(nullptr);
                delete _minimizeButton;
                _minimizeButton = nullptr;
            }
            else if (_windowButtonType == WindowButtonType::MinimizeButton)
            {
                //移除最小化按钮，改为最大化按钮
                disconnect(_minimizeButton,&QPushButton::clicked,this,&AbstractTitleBar::onMinimizeButtonClick);
                int index = lyt->indexOf(_minimizeButton);
                lyt->removeWidget(_minimizeButton);
                _minimizeButton->setParent(nullptr);
                delete _minimizeButton;
                _minimizeButton = nullptr;
                _maximizeButton = new QPushButton(this);
                _maximizeButton->setObjectName(_MAXIMIZE_BUTTON_OBJECT_NAME);
                _maximizeButton->setFont(UIHelper::instance()->getIconFont(_WINDOW_BUTTON_ICONFONT));
                _maximizeButton->setText(QChar(_MAXIMIZE_BUTTON_FONT_INDEX));
                _maximizeButton->setFixedSize(_WINDOW_BUTTON_SIZE);
                connect(_maximizeButton,&QPushButton::clicked,this,&AbstractTitleBar::onMaximizeButtonClick);
                lyt->insertWidget(index,_maximizeButton,0,Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter);
            }
            break;
    }
    _windowButtonType = windowButtonType;
}

void FramelessWidget::DefaultTitleBar::resizeEvent(QResizeEvent *event)
{
    //根据大小变化修改最大化按钮icon
    if (_windowButtonType == WindowButtonType::MinimizeMaximizeButton ||
    _windowButtonType == WindowButtonType::MaximizeButton)
    {
        //修改最大化按钮icon为还原按钮icon
        if (window()->windowState() == Qt::WindowState::WindowMaximized)
        {
            _maximizeButton->setText(QChar(_RESTORE_BUTTON_FONT_INDEX));
        }
        else if (window()->windowState() == Qt::WindowState::WindowNoState)
        {
            _maximizeButton->setText(QChar(_MAXIMIZE_BUTTON_FONT_INDEX));
        }
    }
    QWidget::resizeEvent(event);
}