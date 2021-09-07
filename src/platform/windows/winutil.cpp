//
// Created by guang19 on 2021/9/5.
//

#include "winutil.h"

#ifdef Q_OS_WIN

namespace FramelessWidget
{
    namespace WINUtil
    {
        HRESULT WINAPI M_DwmExtendFrameIntoClientArea(HWND hWnd, const MARGINS *pMarInset)
        {
            return _DwmExtendFrameIntoClientArea(hWnd,pMarInset);
        }

        CornerEdge GetCornerEdge(const QWidget *widget, int x, int y, const QMargins &margins, int border_width)
        {
            QRect fullRect = widget->rect();
            fullRect = fullRect.marginsRemoved(margins);
            unsigned int ce = static_cast<unsigned int>(CornerEdge::WInvalid);
            if ((y - fullRect.top() >= -border_width)
                && (y < fullRect.top())) {
                ce = ce | static_cast<unsigned int>(CornerEdge::WTop);
            }
            if ((x - fullRect.left() >= -border_width)
                && (x < fullRect.left())) {
                ce = ce | static_cast<unsigned int>(CornerEdge::WLeft);
            }
            if ((y - fullRect.bottom() <= border_width)
                && (y > fullRect.bottom())) {
                ce = ce | static_cast<unsigned int>(CornerEdge::WBottom);
            }
            if ((x - fullRect.right() <= border_width)
                && (x > fullRect.right())) {
                ce = ce | static_cast<unsigned int>(CornerEdge::WRight);
            }
            return static_cast<CornerEdge>(ce);
        }
    }
}
#endif
