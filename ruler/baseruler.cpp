#include "baseruler.h"

BaseRuler::BaseRuler(LvBaseObject *parent, const int32_t &width, const int32_t &height) :
    mParent(parent), mWidth(width), mHeight(height) { }

void BaseRuler::setRange(const int32_t &min, const int32_t &max)
{
    mScaler->setRange(min, max);
    mMin = min;
    mMax = max;
}

void BaseRuler::setSize(const int32_t &width, const int32_t &height)
{
    mContainer->setSize(width, height);
    mWidth = width;
    mHeight = height;
}

void BaseRuler::setWidth(const int32_t &width)
{
    mContainer->setWidth(width);
    mWidth = width;
}

void BaseRuler::setHeight(const int32_t &height)
{
    mContainer->setHeight(height);
    mHeight = height;
}

void BaseRuler::setAlign(const LvAlign &align)
{
    mContainer->setAlign(align);
}

void BaseRuler::align(const LvAlign &align, const int32_t &x, const int32_t &y)
{
    mContainer->align(align, x, y);
}

int32_t BaseRuler::getWidth() const
{
    return mWidth;
}

int32_t BaseRuler::getHeigth() const
{
    return mHeight;
}

int32_t BaseRuler::getMin() const
{
    return mMin;
}

int32_t BaseRuler::getMax() const
{
    return mMax;
}
