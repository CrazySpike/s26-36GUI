#include "mainwindow.h"
#include "pages.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), stackedWidget(new QStackedWidget(this)) {

    setWindowTitle("Oyster Farm Operations App");
    setCentralWidget(stackedWidget);

    setupPages();
}

void MainWindow::setupPages() {
    auto *page1 = new Pages(Pages::Page1);
    auto *page2 = new Pages(Pages::Page2);
    auto *page3 = new Pages(Pages::Page3);

    stackedWidget->addWidget(page1); // index 0
    stackedWidget->addWidget(page2); // index 1
    stackedWidget->addWidget(page3); // index 2

    // --- Navigation connections ---
    connect(page1, &Pages::goToPage1, this, [=]() { stackedWidget->setCurrentIndex(0); });
    connect(page1, &Pages::goToPage2, this, [=]() { stackedWidget->setCurrentIndex(1); });
    connect(page1, &Pages::goToPage3, this, [=]() { stackedWidget->setCurrentIndex(2); });

    connect(page2, &Pages::goToPage1, this, [=]() { stackedWidget->setCurrentIndex(0); });
    connect(page2, &Pages::goToPage2, this, [=]() { stackedWidget->setCurrentIndex(1); });
    connect(page2, &Pages::goToPage3, this, [=]() { stackedWidget->setCurrentIndex(2); });

    connect(page3, &Pages::goToPage1, this, [=]() { stackedWidget->setCurrentIndex(0); });
    connect(page3, &Pages::goToPage2, this, [=]() { stackedWidget->setCurrentIndex(1); });
    connect(page3, &Pages::goToPage3, this, [=]() { stackedWidget->setCurrentIndex(2); });
}
