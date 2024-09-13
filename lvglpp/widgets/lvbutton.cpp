#include "lvbutton.h"

LvButton::LvButton(LvBaseObject *parent, const uint32_t &width, const uint32_t &height, QString text) :
    LvBaseObject(parent, width, height), mContent(text)
{
    mButtonPressedEffectTimer = new QTimer();
    mButtonPressedEffectTimer->setSingleShot(true);
    mButtonPressedEffectTimer->setInterval(100);

    connect(mButtonPressedEffectTimer, &QTimer::timeout, this, &LvButton::onButtonPressedEffectTimerHandler);
}

void LvButton::create()
{
    if (mLvObj != nullptr)
    {
        isCreated = true;
        return;
    }

    isCreated = true;

    if (mParent)
        mLvObj = lv_button_create(mParent->getLvObject());
    else
        mLvObj = lv_button_create(lv_screen_active());

    mContentLabel = lv_label_create(mLvObj);
    lv_label_set_text(mContentLabel, mContent.toStdString().c_str());
    lv_obj_center(mContentLabel);
    this->setSize(mWidth, mHeight);
}

void LvButton::press()
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] button was not created!";
        return;
    }
    mButtonPressedEffectTimer->start();
    this->setBgOpa(LV_OPA_50);
    emit pressed();
}

void LvButton::onButtonPressedEffectTimerHandler()
{
    if (!isCreated || !mLvObj)
    {
        qDebug() << "[Warning] button was not created!";
        mButtonPressedEffectTimer->stop();
    }
    this->setBgOpa(LV_OPA_100);
}
