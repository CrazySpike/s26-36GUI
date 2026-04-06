#ifndef WINCH_H
#define WINCH_H

#include <QStringList>
#include <QImage>
#include <QPixmap>
#include <QBuffer>
#include <QDebug>

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
    QVector<QPixmap> displayImages();

private:
    int winchNumber = 0;
    int winchID = 0;
    bool connected = false;
    bool cageDown = false;
    double cageHeight = 0;
    double waterLevel = 0;
    QStringList operationsSchedule;
    const QString imagesPath = "/Users/bwr/Qt/Widgets/s26-36GUI/images/";
    QStringList winchImages;

};

#endif // WINCH_H
