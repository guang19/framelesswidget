//
// Created by guang19 on 2021/9/10.
//

#ifndef SAMPLE_DEMOWINDOW_H
#define SAMPLE_DEMOWINDOW_H

#include "../src/FramelessWindow.h"

class DemoWindow : public FW::FramelessWindow
{
    Q_OBJECT
    public:
        ~DemoWindow() override = default;
};


#endif //SAMPLE_DEMOWINDOW_H
