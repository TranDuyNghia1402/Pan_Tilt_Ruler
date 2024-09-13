#ifndef TILTRULER_H
#define TILTRULER_H

#include "baseruler.h"

class TiltRuler : public BaseRuler
{
public:
    TiltRuler(LvBaseObject *parent, const int32_t &width = 55, const int32_t &height = 400);

    void setValue(const int32_t &value) override;
};

#endif // TILTRULER_H
