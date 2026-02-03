#ifndef PAGES_H
#define PAGES_H

#pragma once

#include "winch.h"

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QStringList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>

class QLabel;
class QPushButton;
class QVBoxLayout;

class Pages : public QWidget {
    Q_OBJECT

public:
    enum PageType { Start, Login, Account, Dashboard, Winch, Settings,
                    Sensor, Solar, Operations, Camera, Winch_Help,
                    Find_Winch_Auto, Find_Winch_Manual, Found_Winch,
                    Find_Winch_Help, Found_Winch_Help };

    explicit Pages(QWidget *parent = nullptr);

private:
    QStackedWidget *stack;

    QWidget *createPage_Start();
    QWidget *createPage_Login();
    QWidget *createPage_Account();
    QWidget *createPage_Dashboard();
    QWidget *createPage_Winch();
    QWidget *createPage_Settings();
    QWidget *createPage_Sensor();
    QWidget *createPage_Solar();
    QWidget *createPage_Operations();
    QWidget *createPage_Camera();
    QWidget *createPage_Winch_Help();
    QWidget *createPage_Find_Winch_Auto();
    QWidget *createPage_Find_Winch_Manual();
    QWidget *createPage_Found_Winch();
    QWidget *createPage_Find_Winch_Help();
    QWidget *createPage_Found_Winch_Help();

    void switchPage(PageType prevPage, PageType nextPage);
    void switchPage(PageType type);

    // Put evey possible scrollable area as a scrollbar (ex. help pages and winches)

    PageType lastPage;

    QPushButton *createButton(const QString &text, const QString &color);
    QPushButton *createHelpButton(PageType type);

    const QString jsonName = "/Users/bwr/Qt/Widgets/s26-36GUI/config.json";

    void getConfig();
    void addEntryToConfig(int number);
    void openWinchPage(int index);

    QPushButton *createWinchButton(winch entry);

    std::vector<winch> winchVector;
    winch *currentWinch = nullptr;

    QVBoxLayout *winchLayout;

    QLabel *winchTitleLabel;
    QLabel *connectionLabel;
    QLabel *idLabel;
    QLabel *statusLabel;
    QLabel *heightLabel;
    QLabel *waterLabel;
    QLabel *scheduleLabel;

    int winchSelected = 0;
    int winchCounter = 0;
};

#endif // PAGES_H
