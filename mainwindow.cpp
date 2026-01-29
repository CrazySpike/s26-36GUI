#include "mainwindow.h"
#include "pages.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    setWindowTitle("Oyster Farm Operations App");

    // Pages internally manages QStackedWidget
    auto *pages = new Pages(this);
    setCentralWidget(pages);
}
