#include "winch.h"

winch::winch(int num) {
    winchNumber = num;
    winchID = 12345;
    connected = true;
    cageHeight = 2.13;
    waterLevel = 4.52;
}

void winch::addID(const int id)
{
    winchID = id;
}

void winch::addConnection(const bool conn)
{
    connected = conn;
}

void winch::addSubmersion(const bool sub)
{
    cageDown = sub;
}

void winch::addCageHeight(const double height)
{
    cageHeight = height;
}

void winch::addWaterLevel(const double level)
{
    waterLevel = level;
}

void winch::addOperationsSchedule(const QStringList schedule)
{
    operationsSchedule = schedule;
}

void winch::addImages(const QStringList images)
{
    winchImages = images;
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

QString winch::displayCageStatus() {
    QString status = "Cage Status: ";

    return (cageDown) ? status + "Down" : status + "Up";
}

double winch::displayCageHeight()
{
    return cageHeight;
}

double winch::displayWaterLevel()
{
    return waterLevel;
}

QString winch::displayOperationsSchedule()
{
    QString schedule = "Next Scheduled Action(s):";

    for (const QString &entry : std::as_const(operationsSchedule))
        schedule += "\n    " + entry;

    return schedule;
}

QVector<QPixmap> winch::displayImages()
{
    QVector<QPixmap> images;

    for (const QString &entry : std::as_const(winchImages))
    {
        QPixmap pixmap;

        if (pixmap.load(imagesPath + entry))
        {
            images.append(pixmap);
            // qDebug() << entry;
        }
        else
        {
            qDebug() << "Failed to load image:" << entry;
        }
    }

    return images;
}

