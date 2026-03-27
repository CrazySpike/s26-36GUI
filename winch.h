#ifndef WINCH_H
#define WINCH_H

#include <QStringList>

class winch
{
public:
    winch(int num);

    void addID(const int id);
    void addConnection(const bool conn);
    void addSubmersion(const bool sub);
    void addCageHeight(const double height);
    void addWaterLevel(const double level);
    void addOperationsSchedule(const QStringList schedule);
    void addImages(const QStringList images);

    int displayNumber();
    int displayID();
    bool isConnected();
    QString displayCageStatus();
    double displayCageHeight();
    double displayWaterLevel();
    QString displayOperationsSchedule();
    QString displayImages();

private:
    int winchNumber = 0;
    int winchID = 0;
    bool connected = false;
    bool cageDown = false;
    double cageHeight = 0;
    double waterLevel = 0;
    QStringList operationsSchedule;
    QStringList winchImages;

};

#endif // WINCH_H
