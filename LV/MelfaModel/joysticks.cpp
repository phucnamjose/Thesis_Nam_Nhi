#include "joysticks.hpp"

Joysticks::Joysticks(int device, QObject *parent):QGamepad(device, parent)
{

}

// Deconstructor
Joysticks::~Joysticks()
{

}
