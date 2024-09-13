#include "tiltruler.h"

TiltRuler::TiltRuler(LvBaseObject *parent, const int32_t &width, const int32_t &height) :
    BaseRuler(parent, width, height)
{

    static LvObjectStyle containerStyle;
//    containerStyle.setSize(mWidth, mHeight);
    containerStyle.setRadius(0);
    containerStyle.setBorderWidth(0);

    mContainer = new LvBaseObject(mParent);
    mContainer->create();
    mContainer->setScrollBarMode(ScrollBarMode::OFF);
    mContainer->setSize(mWidth, mHeight);
    mContainer->setBgOpa(LV_OPA_40);
    mContainer->setBgColor(lv_color_hex(0x181818));
    mContainer->addStyle(containerStyle);

    mMoveSection = new LvBaseObject(mContainer);
    mMoveSection->create();
    mMoveSection->setScrollBarMode(ScrollBarMode::OFF);
    mMoveSection->setSize(mWidth, mHeight);
    mMoveSection->setBgOpa(LV_OPA_0);
    mMoveSection->center();
    mMoveSection->addStyle(containerStyle);
    mMoveSection->setScrollDir(ScrollDirection::HOR);

    static LvObjectStyle scaleTickStyle;
    static LvObjectStyle scaleMainPartStyle2;
    scaleTickStyle.setLineColor(lv_color_hex(0x00E8E8));
    scaleTickStyle.setWidth(100U);
    scaleMainPartStyle2.setLineOpa(LV_OPA_0);

    mScaler = new LvScale(mMoveSection);
    mScaler->create();
    mScaler->addStyle(scaleTickStyle, LV_PART_ITEMS);
    mScaler->addStyle(scaleTickStyle, LV_PART_INDICATOR);
    mScaler->addStyle(scaleMainPartStyle2, LV_PART_MAIN);
    mScaler->setSize(mWidth - 10, mHeight * 2);
    mScaler->setMode(LV_SCALE_MODE_VERTICAL_LEFT);
    mScaler->align(LV_ALIGN_CENTER, -7, 0);
    mScaler->setTotalTickCount((mMax - mMin) / 2);
    mScaler->setMajorTickEvery(1);
    mScaler->hideLabel();
    mScaler->setMajorTickLength(10);

    mValuePointer = new LvBaseObject(mContainer);
    mValuePointer->create();
    mValuePointer->setSize(mWidth, 20);
    mValuePointer->setScrollBarMode(ScrollBarMode::OFF);
    mValuePointer->center();
    mValuePointer->setBorderSide(LV_BORDER_SIDE_LEFT);
    mValuePointer->setBorderWidth(2);
    mValuePointer->setBorderColor(lv_color_hex(0x00E8E8));
    mValuePointer->setBgColor(lv_color_hex(0x181818));
    mValuePointer->setBgOpa(LV_OPA_100);
    mValuePointer->setRadius(0);
    mValuePointer->setPadAll(0);

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
}

void TiltRuler::setValue(const int32_t &value)
{
    mMoveSection->scrollToY(value, LV_ANIM_ON);
    mValueLabel->setText(QString::number(value));
}
