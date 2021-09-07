//
// Created by guang19 on 2021/9/5.
//

#ifndef FRAMELESSWIDGET_WINUITL_H
#define FRAMELESSWIDGET_WINUITL_H

#pragma once

#include <QWidget>
#include <QtGlobal>

#ifdef Q_OS_WIN
#include <QByteArray>
#include <windows.h>
#include <windowsx.h>
#include <winuser.h>
#include <uxtheme.h>
#include <dwmapi.h>

namespace FramelessWidget
{
    namespace WINUtil
    {
        enum class CornerEdge
        {
            WInvalid = 0,
            WTop = 1,
            WRight = 2,
            WBottom = 4,
            WLeft = 8,
            WTopLeft = 1 | 8,
            WTopRight = 1 | 2,
            WBottomLeft = 4 | 8,
            WBottomRight = 4 | 2,
        };

        enum class XCursorType
        {
            WInvalid = -1,
            WArrow = 2,
            WTop = 138,
            WTopRight = 136,
            WRight = 96,
            WBottomRight = 14,
            WBottom = 16,
            WBottomLeft = 12,
            WLeft = 70,
            WTopLeft = 134,
         };
        ///////////////////////////////////////////////////////////////////////////
        //加载dwmapi库
        static HINSTANCE dwmapi = LoadLibrary("dwmapi.dll");
        typedef HRESULT WINAPI (*DwmExtendFrameIntoClientArea_ADDR)(HWND , const MARGINS *);
        //获取DwmExtendFrameIntoClientArea函数地址
        static DwmExtendFrameIntoClientArea_ADDR _DwmExtendFrameIntoClientArea = (DwmExtendFrameIntoClientArea_ADDR)GetProcAddress(dwmapi,"DwmExtendFrameIntoClientArea");
        ///////////////////////////////////////////////////////////////////////////
        HRESULT WINAPI M_DwmExtendFrameIntoClientArea(HWND hWnd, const MARGINS *pMarInset);
        CornerEdge GetCornerEdge(const QWidget *widget, int x, int y, const QMargins &margins, int border_width);
    }   
}

#endif

#endif //FRAMELESSWIDGET_WINUITL_H
