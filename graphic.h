#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QObject>
#include <QTimer>
#include "lvglpp/core/lv_conf.h"
#include "lvglpp/core/lvgl/src/drivers/sdl/lv_sdl_window.h"
#include "lvglpp/widgets/lvbaseobject.h"
#include "lvglpp/widgets/lvcuractivescreen.h"
#include "lvglpp/widgets/lvlabel.h"
#include "lvglpp/widgets/lvbutton.h"
#include "lvglpp/widgets/lvscale.h"
#include "lvglpp/widgets/lvimage.h"
#include "lvglpp/widgets/lvbuttonmaxtrix.h"
#include "lvglpp/widgets/lvtabview.h"
#include "lvglpp/widgets/lvlist.h"
#include "lvglpp/widgets/lvline.h"
#include "lvglpp/widgets/lvwindow.h"
#include "lvglpp/widgets/lvbar.h"
#include "lvglpp/widgets/lvspinbox.h"
#include "lvglpp/widgets/lvroller.h"
#include "lvglpp/widgets/lvdropdownlist.h"
#include "lvglpp/lvstyle.h"

#include "ruler/tiltruler.h"

#define MONITOR_WIDTH   1280
#define MONITOR_HEIGHT  720

class Graphic : public QObject
{
    Q_OBJECT
public:
    Graphic();

private:
    QTimer *lvTickTimer = nullptr;
    QTimer *lvTimeTimer = nullptr;

    void halInit(void);
    void csdspSimulator(void);

    LvImage *backGround = nullptr;
    TiltRuler *tiltRuler = nullptr;

    QTimer *autoPressTimer = nullptr;

public slots:
    void onLvTickHandler();
    void onLvTimerHandler();

    void onAutoPressTimerHandler();
};

#endif // GRAPHIC_H
