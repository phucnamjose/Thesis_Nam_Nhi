#ifndef JOYSTICKS_H
#define JOYSTICKS_H

#include <QtGamepad/QGamepad>
#include <QtGamepad/QGamepadManager>

class Joysticks : public QGamepad
{
public:
    explicit Joysticks(int device = 0, QObject *parent = nullptr);
    virtual   ~Joysticks();


    enum joysticksFunction_t {
        FUNC_X_V0_INC = 0,
        FUNC_X_V0_DEC,
        FUNC_Y_V1_INC,
        FUNC_Y_V1_DEC,
        FUNC_Z_V2_INC,
        FUNC_Z_V2_DEC,
        FUNC_ROLL_V3_INC,
        FUNC_ROLL_V3_DEC,
        FUNC_OUTPUT,
        FUNC_CHANGE_SPACE,
        FUNC_INC_SPEED,
        FUNC_DEC_SPEED
    };
};

#endif // JOYSTICKS_H
