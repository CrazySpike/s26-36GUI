#ifndef PAGES_H
#define PAGES_H

#pragma once
#include <QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;

class Pages : public QWidget {
    Q_OBJECT

public:
    enum PageType { Page1, Page2, Page3 };
    explicit Pages(PageType type, QWidget *parent = nullptr);

signals:
    void goToPage1();
    void goToPage2();
    void goToPage3();

private:
    void buildPage(PageType type);
    QPushButton *createButton(const QString &text, const QString &color);
};

#endif // PAGES_H
