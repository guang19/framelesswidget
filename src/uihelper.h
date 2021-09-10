//
// Created by guang19 on 2021/8/27.
//

#ifndef UIHELPER_H
#define UIHELPER_H

#include <QWidget>
#include <QMutex>
#include <QMap>

namespace FW
{
    class UIHelper
    {
        private:
            explicit UIHelper() = default;
        public:
            ~UIHelper() = default;
            UIHelper(const UIHelper&) = delete;
            UIHelper(const UIHelper&&) = delete;
            UIHelper& operator=(const UIHelper&) = delete;
            UIHelper& operator=(const UIHelper&&) = delete;

            static UIHelper* instance();

        //为widget设置qss
        public:
            void setStyleSheet(QWidget* w , const QString& qssFile);

            //获取icon font图标
            QFont getIconFont(const QString& iconfont);

        private:
            static UIHelper* _UIHelper;
            static QMutex _mtx;
            QMap<QString,QFont> _fontMap;
    };
}

#endif //UIHELPER_H
