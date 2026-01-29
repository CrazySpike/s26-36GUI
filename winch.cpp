#include "winch.h"

winch::winch(int num) {
    winchNumber = num;
    winchID = 12345;
    connected = true;
    cageHeight = 2.13;
    waterLevel = 4.52;
}

int winch::displayNumber() {
    return winchNumber;
}

int winch::displayID()
{
    return winchID;
}

bool winch::isConnected()
{
    return connected;
}

bool winch::isDown() {
    return cageDown;
}

double winch::displayCageHeight()
{
    return cageHeight;
}

double winch::displayWaterLevel()
{
    return waterLevel;
}

