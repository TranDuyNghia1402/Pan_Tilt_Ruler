#ifndef TILTRULER_H
#define TILTRULER_H

#include "baseruler.h"

class TiltRuler : public BaseRuler
{
public:
    TiltRuler(LvBaseObject *parent, const int32_t &width = 60, const int32_t &height = 400);

    void setValue(const double &value) override;

private:
    int32_t mWidth = 60;
    int32_t mHeight = 400;

    int32_t mCurrentScalePos = 1800; // default pos of scaler

    const int32_t mScaleDownLimit = -200;
    const int32_t mScaleUpLimit = 200;
    const int32_t mScaleHeight = 4000;  // total height of the scaler
};

#endif // TILTRULER_H
