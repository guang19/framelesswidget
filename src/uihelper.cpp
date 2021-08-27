//
// Created by guang19 on 2021/8/27.
//

#include <QFile>
#include <QFontDatabase>
#include "uihelper.h"

FramelessWidget::UIHelper* FramelessWidget::UIHelper::_UIHelper = nullptr;
QMutex FramelessWidget::UIHelper::_mtx;

FramelessWidget::UIHelper* FramelessWidget::UIHelper::instance()
{
    if (_UIHelper == nullptr)
    {
        QMutexLocker lock(&_mtx);
        if (_UIHelper == nullptr)
        {
            _UIHelper = new UIHelper;
        }
    }
    return _UIHelper;
}

void FramelessWidget::UIHelper::setStyleSheet(QWidget* w , const QString& qssFile)
{
    QFile f(qssFile);
    f.open(QFile::OpenModeFlag::ReadOnly);
    w->setStyleSheet(f.readAll());
    f.close();
}

//获取icon font图标
QFont FramelessWidget::UIHelper::getIconFont(const QString& iconfont)
{
    if (_fontMap.contains(iconfont))
    {
        return _fontMap[iconfont];
    }
    else
    {
        int fontId = QFontDatabase::addApplicationFont(iconfont);
        QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont f = QFont(fontName);
        _fontMap.insert(iconfont,f);
        return f;
    }
}
