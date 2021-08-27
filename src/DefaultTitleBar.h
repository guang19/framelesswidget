//
// Created by guang19 on 2021/8/27.
//

#ifndef DEFAULTTITLEBAR_H
#define DEFAULTTITLEBAR_H


#include "AbstractTitleBar.h"

namespace FramelessWidget
{
#define _TITLEBAR_OBJECT_NAME "TitleBar"
#define _TITLEBAR_HEIGHT 32
#define _WINDOW_ICON_SIZE QSize(28,28)
#define _WINDOW_BUTTON_ICONFONT ":/img/window-button.ttf"
#define _MINIMIZE_BUTTON_OBJECT_NAME "MinimizeButton"
#define _MAXIMIZE_BUTTON_OBJECT_NAME "MaximizeButton"
#define _CLOSE_BUTTON_OBJECT_NAME "CloseButton"
#define _WINDOW_BUTTON_SIZE QSize(22,22)
#define _MINIMIZE_BUTTON_FONT_INDEX 0xe652
#define _MAXIMIZE_BUTTON_FONT_INDEX 0xe64a
#define _RESTORE_BUTTON_FONT_INDEX 0xe649
#define _CLOSE_BUTTON_FONT_INDEX 0xe612

    class DefaultTitleBar : public AbstractTitleBar
    {
        Q_OBJECT
        public:
            explicit DefaultTitleBar(QWidget* parent = nullptr);
            ~DefaultTitleBar() = default;

        public slots:
            void setWindowIcon(const QIcon &icon) override;
            void setWindowTitle(const QString& title) override;
            void setWindowTitleAlignCenter(bool centreAlign) override;
            void setButtonType(WindowButtonType windowButtonType) override;

        protected:
            void resizeEvent(QResizeEvent *event) override;
    };

}

#endif //DEFAULTTITLEBAR_H