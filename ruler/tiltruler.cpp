#include "tiltruler.h"

TiltRuler::TiltRuler(LvBaseObject *parent, const int32_t &width, const int32_t &height) :
    BaseRuler(parent, width, height)
{

    static LvObjectStyle containerStyle;
    containerStyle.setRadius(0);
    containerStyle.setBorderWidth(0);
    containerStyle.setSize(mWidth, mHeight);
    containerStyle.setPadAll(0);

    mContainer = new LvBaseObject(mParent);
    mContainer->create();
    mContainer->addStyle(containerStyle);
    mContainer->setScrollBarMode(ScrollBarMode::OFF);
    mContainer->setBgOpa(LV_OPA_40);
    mContainer->setBgColor(lv_color_hex(0x181818));

    mMoveSection = new LvBaseObject(mContainer);
    mMoveSection->create();
    mMoveSection->addStyle(containerStyle);
    mMoveSection->setScrollBarMode(ScrollBarMode::OFF);
    mMoveSection->setBgOpa(LV_OPA_0);
    mMoveSection->center();
    mMoveSection->setScrollDir(ScrollDirection::VER);

    static LvObjectStyle scaleTickStyle;
    static LvObjectStyle scaleMainStyle;
    scaleTickStyle.setTextColor(lv_color_hex(0x00E8E8));
    scaleTickStyle.setLineColor(lv_color_hex(0x00E8E8));
    scaleMainStyle.setLineOpa(LV_OPA_0);

    mScaler = new LvScale(mMoveSection);
    mScaler->create();
    mScaler->setSize(mWidth - 10, mScaleHeight);
    mScaler->setRange(mMin, mMax);
    mScaler->addStyle(scaleTickStyle, LV_PART_ITEMS);
    mScaler->addStyle(scaleTickStyle, LV_PART_INDICATOR);
    mScaler->addStyle(scaleMainStyle, LV_PART_MAIN);
    mScaler->setMode(LV_SCALE_MODE_VERTICAL_LEFT);
    mScaler->align(LV_ALIGN_TOP_MID, 0, 0);
    mScaler->setMajorTickEvery(10);
    mScaler->setMajorTickLength(20);
    mScaler->setMinorTickLength(10);
    mScaler->setRange(mScaleDownLimit, mScaleUpLimit);
    mScaler->setTotalTickCount(qAbs(mScaleDownLimit) + qAbs(mScaleUpLimit) + 1);

    mValuePointer = new LvBaseObject(mContainer);
    mValuePointer->create();
    mValuePointer->setSize(mWidth, 20);
    mValuePointer->setScrollBarMode(ScrollBarMode::OFF);
    mValuePointer->align(LV_ALIGN_CENTER, 0, 0);
    mValuePointer->setBorderSide(LV_BORDER_SIDE_LEFT);
    mValuePointer->setBorderWidth(2);
    mValuePointer->setBorderColor(lv_color_hex(0x00E8E8));
    mValuePointer->setBgColor(lv_color_hex(0x181818));
    mValuePointer->setBgOpa(LV_OPA_100);
    mValuePointer->addStyle(containerStyle);

    static LvObjectStyle labelStyle;
    labelStyle.setTextColor(lv_color_hex(0x00E8E8));

    mPointerLabel = new LvLabel(mValuePointer, LV_SYMBOL_RIGHT);
    mPointerLabel->create();
    mPointerLabel->align(LV_ALIGN_RIGHT_MID, 0, 0);
    mPointerLabel->addStyle(labelStyle);

    mValueLabel = new LvLabel(mValuePointer, "0.00");
    mValueLabel->create();
    mValueLabel->align(LV_ALIGN_LEFT_MID, 5, 0);
    mValueLabel->addStyle(labelStyle);

    mMoveSection->scrollToY(mCurrentScalePos, LV_ANIM_OFF); // move to root
}

void TiltRuler::setValue(const double &value)
{
    mCurrentScalePos = 1800 - 10 * value;
    if (mCurrentScalePos >= 3600)
        mCurrentScalePos = 0;
    else if (mCurrentScalePos <= 0)
        mCurrentScalePos = 3600;
    mMoveSection->scrollToY(mCurrentScalePos, LV_ANIM_ON);
    mValueLabel->setText(QString::number(value));
}
