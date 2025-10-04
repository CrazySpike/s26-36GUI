#include "pages.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

Pages::Pages(PageType type, QWidget *parent)
    : QWidget(parent) {
    buildPage(type);
}

void Pages::buildPage(PageType type) {
    auto *layout = new QVBoxLayout(this);

    auto *label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label);

    // ----- Build page contents -----
    switch (type) {
    case Page1: {
        label->setText("This is Page 1");

        auto *btnTo2 = createButton("Go to Page 2", "#4CAF50");
        auto *btnTo3 = createButton("Go to Page 3", "#2196F3");

        connect(btnTo2, &QPushButton::clicked, this, &Pages::goToPage2);
        connect(btnTo3, &QPushButton::clicked, this, &Pages::goToPage3);

        layout->addWidget(btnTo2);
        layout->addWidget(btnTo3);
        break;
    }

    case Page2: {
        label->setText("This is Page 2");

        auto *btnTo1 = createButton("Go to Page 1", "#FF9800");
        auto *btnTo3 = createButton("Go to Page 3", "#9C27B0");

        connect(btnTo1, &QPushButton::clicked, this, &Pages::goToPage1);
        connect(btnTo3, &QPushButton::clicked, this, &Pages::goToPage3);

        layout->addWidget(btnTo1);
        layout->addWidget(btnTo3);
        break;
    }

    case Page3: {
        label->setText("This is Page 3");

        auto *btnTo1 = createButton("Back to Page 1", "#f44336");
        auto *btnTo2 = createButton("Go to Page 2", "#009688");

        connect(btnTo1, &QPushButton::clicked, this, &Pages::goToPage1);
        connect(btnTo2, &QPushButton::clicked, this, &Pages::goToPage2);

        layout->addWidget(btnTo1);
        layout->addWidget(btnTo2);
        break;
    }
    }

    layout->addStretch();
}

QPushButton *Pages::createButton(const QString &text, const QString &color) {
    auto *btn = new QPushButton(text, this);
    btn->setStyleSheet(QString(
                           "QPushButton {"
                           " background-color: %1;"
                           " color: white;"
                           " font-size: 18px;"
                           " padding: 10px;"
                           " border-radius: 8px;"
                           " margin: 5px;"
                           " }").arg(color));
    return btn;
}
