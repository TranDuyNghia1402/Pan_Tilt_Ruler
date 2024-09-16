 #include "graphic.h"
#include <QDebug>

#define BG_COLOR    0x181818
#define GUI_COLOR   0x00E8E8

Graphic::Graphic()
{
    lvTickTimer = new QTimer();
    lvTimeTimer = new QTimer();

    testTimer = new QTimer();

    lvTickTimer->setSingleShot(false);
    lvTimeTimer->setSingleShot(false);
    testTimer->setSingleShot(false);

    connect(lvTickTimer, &QTimer::timeout, this, &Graphic::onLvTickHandler);
    connect(lvTimeTimer, &QTimer::timeout, this, &Graphic::onLvTimerHandler);
    connect(testTimer, &QTimer::timeout, this, &Graphic::onTestTimerHandler);

    lvTickTimer->start(5);
    lvTimeTimer->start(5);

    halInit();

    csdspSimulator();
}

void Graphic::halInit()
{
    lv_init();
    lv_sdl_window_create(MONITOR_WIDTH, MONITOR_HEIGHT);
}

void Graphic::csdspSimulator()
{
    LV_IMAGE_DECLARE(bg);
    backGround = new LvImage(LvCurrentActScreen::getActiveScreen(), &bg);
    backGround->create();

    LV_IMAGE_DECLARE(reticle1x_200x100);
    LvImage *reticle1x = new LvImage(LvCurrentActScreen::getActiveScreen(), &reticle1x_200x100);
    reticle1x->create();
    reticle1x->setInnerAlign(LV_IMAGE_ALIGN_CENTER);
    reticle1x->center();

    static LvObjectStyle labelStyle;
    labelStyle.setWidth(60);
    labelStyle.setBorderWidth(1);
    labelStyle.setRadius(3);
    labelStyle.setTextAlign(LV_TEXT_ALIGN_CENTER);
    labelStyle.setBorderColor(lv_color_hex(GUI_COLOR));
    labelStyle.setBgOpa(LV_OPA_COVER);
    labelStyle.setBgColor(lv_color_hex(BG_COLOR));
    labelStyle.setTextColor(lv_color_hex(GUI_COLOR));

    LvLabel *lbCameraChannel = new LvLabel(LvCurrentActScreen::getActiveScreen(), "DAY");
    lbCameraChannel->create();
    lbCameraChannel->addStyle(labelStyle);

    LvLabel *lbZoomLevel = new LvLabel(LvCurrentActScreen::getActiveScreen(), "1X");
    lbZoomLevel->create();
    lbZoomLevel->setAlign(LV_ALIGN_TOP_RIGHT);
    lbZoomLevel->addStyle(labelStyle);

    LvLabel *lbGunnerState = new LvLabel(LvCurrentActScreen::getActiveScreen(), "GUNNER");
    lbGunnerState->create();
    lbGunnerState->setWidth(80);
    lbGunnerState->setAlign(LV_ALIGN_BOTTOM_LEFT);
    lbGunnerState->addStyle(labelStyle);

    LvLabel *lbBmsState = new LvLabel(LvCurrentActScreen::getActiveScreen(), "BMS");
    lbBmsState->create();
    lbBmsState->setWidth(80);
    lbBmsState->setAlignTo(lbGunnerState, LV_ALIGN_OUT_TOP_LEFT, 0, -5);
    lbBmsState->addStyle(labelStyle);

    LvLabel *lbXavierState = new LvLabel(LvCurrentActScreen::getActiveScreen(), "MTXLA");
    lbXavierState->create();
    lbXavierState->setWidth(80);
    lbXavierState->setAlignTo(lbBmsState, LV_ALIGN_OUT_TOP_LEFT, 0, -5);
    lbXavierState->addStyle(labelStyle);

    LvLabel *lbPtuState = new LvLabel(LvCurrentActScreen::getActiveScreen(), "PTU");
    lbPtuState->create();
    lbPtuState->setWidth(80);
    lbPtuState->setAlignTo(lbXavierState, LV_ALIGN_OUT_TOP_LEFT, 0, -5);
    lbPtuState->addStyle(labelStyle);

    LvLabel *lbLaserResult = new LvLabel(LvCurrentActScreen::getActiveScreen(), "DISTANCE:");
    lbLaserResult->create();
    lbLaserResult->setWidth(150);
    lbLaserResult->setTextAlign(LV_TEXT_ALIGN_LEFT);
    lbLaserResult->setAlign(LV_ALIGN_TOP_MID);
    lbLaserResult->addStyle(labelStyle);

    tiltRuler = new TiltRuler(LvCurrentActScreen::getActiveScreen());
    tiltRuler->align(LV_ALIGN_LEFT_MID, 0, 0);
    tiltRuler->setRange(-120, 120);



    testTimer->start(200);
}

void Graphic::onLvTickHandler()
{
    lv_tick_inc(5);
}

void Graphic::onLvTimerHandler()
{
    lv_timer_handler();
}

void Graphic::onTestTimerHandler()
{
    double i = QRandomGenerator::global()->bounded(-90, 90);
    tiltRuler->setValue(i);
}
