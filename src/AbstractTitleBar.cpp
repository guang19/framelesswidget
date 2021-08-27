//
// Created by guang19 on 2021/8/26.
//


#include "AbstractTitleBar.h"

FramelessWidget::AbstractTitleBar::AbstractTitleBar(QWidget *parent):
QWidget(parent)
{
    setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    setMouseTracking(true);
    installEventFilter(this);
}

void FramelessWidget::AbstractTitleBar::onMinimizeButtonClick()
{
    emit onMinimizeButtonClicked();
}

void FramelessWidget::AbstractTitleBar::onMaximizeButtonClick()
{
    emit onMaximizeButtonClicked();
}

void FramelessWidget::AbstractTitleBar::onCloseButtonClick()
{
    emit onCloseButtonClicked();
}

void FramelessWidget::AbstractTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit onMaximizeButtonClicked();
}
