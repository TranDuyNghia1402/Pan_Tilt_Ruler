#ifndef RULER_H
#define RULER_H

#include <QList>
#include "lvglpp/widgets/lvbaseobject.h"
#include "lvglpp/widgets/lvcuractivescreen.h"
#include "lvglpp/widgets/lvscale.h"
#include "lvglpp/widgets/lvlabel.h"
#include "lvglpp/lvstyle.h"

class BaseRuler
{
public:
    BaseRuler(LvBaseObject *parent, const int32_t &width, const int32_t &height);

    /**
     * @brief setValue: set value to pan/tilt ruler
     * @param value
     */
    virtual void setValue(const double &value) = 0;

    /**
     * @brief setRange: set the minimum and the maximum of the pan/tilt ruler
     * @param min
     * @param max
     */
    void setRange(const int32_t &min, const int32_t &max);

    /**
     * @brief setSize: set size for pan/tilt ruler
     * @param width
     * @param height
     */
    void setSize(const int32_t &width, const int32_t &height);

    /**
     * @brief setWidth: set pan/titl ruler's width
     * @param width
     */
    void setWidth(const int32_t &width);

    /**
     * @brief setHeight: set pan/tilt ruler's height
     * @param height
     */
    void setHeight(const int32_t &height);

    /**
     * @brief align: align pan/tilt ruler without offset
     * @param align
     */
    void setAlign(const LvAlign &align);

    /**
     * @brief setAlign: align pan/tilt ruler with offset
     * @param align
     */
    void align(const LvAlign &align, const int32_t &x, const int32_t &y);

    /**
     * @brief getWidth: get pan/tilt ruler's width
     * @return
     */
    int32_t getWidth() const;

    /**
     * @brief getHeigth: get pan/tilt ruler's height
     * @return
     */
    int32_t getHeigth() const;

    /**
     * @brief getMin: get minimum value of pan/tilt ruler
     * @return
     */
    int32_t getMin() const;

    /**
     * @brief getMax: get maximum value of pan/tilt ruler
     * @return
     */
    int32_t getMax() const;

protected:
    LvBaseObject *mParent;
    int32_t mWidth;
    int32_t mHeight;
    int32_t mMin = 0;
    int32_t mMax = 100;

    LvBaseObject *mContainer = nullptr;
    LvBaseObject *mMoveSection = nullptr;
    LvScale *mScaler = nullptr;
    LvBaseObject *mValuePointer = nullptr;
    LvLabel *mPointerLabel = nullptr;
    LvLabel *mValueLabel = nullptr;

};

#endif // RULER_H
