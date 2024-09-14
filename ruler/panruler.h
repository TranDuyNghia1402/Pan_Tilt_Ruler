#ifndef PANRULER_H
#define PANRULER_H

#include "baseruler.h"

class PanRuler
{
public:
    PanRuler(LvBaseObject *parent, const int32_t &width = 60, const int32_t &height = 600);

private:
    int32_t mWidth = 60;
    int32_t mHeight = 600;

    int32_t mCurrentScalePos = 0;
};

#endif // PANRULER_H
