#ifndef WINCH_H
#define WINCH_H

class winch
{
public:
    winch(int num);

    int displayNumber();
    int displayID();
    bool isConnected();
    bool isDown();
    double displayCageHeight();
    double displayWaterLevel();

private:
    int winchNumber = 0;
    int winchID = 0;
    bool connected = false;
    bool cageDown = false;
    double cageHeight = 0;
    double waterLevel = 0;

};

#endif // WINCH_H
