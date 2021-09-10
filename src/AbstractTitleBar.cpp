//
// Created by guang19 on 2021/8/26.
//


#include "AbstractTitleBar.h"

FW::AbstractTitleBar::AbstractTitleBar(QWidget *parent):
QWidget(parent)
{
    setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    setMouseTracking(true);
    installEventFilter(this);
}

void FW::AbstractTitleBar::onMinimizeButtonClick()
{
    emit onMinimizeButtonClicked();
}

void FW::AbstractTitleBar::onMaximizeButtonClick()
{
    emit onMaximizeButtonClicked();
}

void FW::AbstractTitleBar::onCloseButtonClick()
{
    emit onCloseButtonClicked();
}

void FW::AbstractTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit onMaximizeButtonClicked();
}
