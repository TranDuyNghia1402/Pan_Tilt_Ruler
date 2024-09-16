#include "panruler.h"

PanRuler::PanRuler(LvBaseObject *parent, const int32_t &width, const int32_t &height) :
    BaseRuler(parent, width, height)
{
    static LvObjectStyle containerStyle;
    containerStyle.setSize(mWidth, mHeight);
    containerStyle.setBorderWidth(0);
    containerStyle.setRadius(0);
    containerStyle.setPadAll(0);

    mContainer = new LvBaseObject(parent);
    mContainer->create();
    mContainer->addStyle(containerStyle);
    mContainer->setBgOpa(LV_OPA_40);
    mContainer->setBgColor(lv_color_hex(0x181818));
}

void PanRuler::setValue(const double &value)
{

}
