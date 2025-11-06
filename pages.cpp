#include "pages.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>

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

    // --- Build page contents ---
    switch (type) {
        case Page1: {
            label->setText("Oyster Farm Management App");

            auto *middleBar = new QWidget();
            auto *middleLayout = new QVBoxLayout(middleBar);
            middleLayout->setContentsMargins(10, 10, 10, 10);
            middleLayout->setSpacing(15);

            auto *loginButton = createButton("Login", "#4CAF50");
            auto *addAccountButton = createButton("Add Account", "#2196F3");

            connect(loginButton, &QPushButton::clicked, this, &Pages::goToPage2);
            // connect(addAccountButton, &QPushButton::clicked, this, &Pages::goToPage3);

            middleLayout->addWidget(loginButton);
            middleLayout->addWidget(addAccountButton);
            middleBar->setLayout(middleLayout);

            layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
            layout->addWidget(middleBar, 0, Qt::AlignHCenter);
            layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
            break;
        }

        case Page2: {
            label->setText("Login");

            auto *middleBar = new QWidget();
            auto *middleLayout = new QVBoxLayout(middleBar);
            middleLayout->setContentsMargins(10, 10, 10, 10);
            middleLayout->setSpacing(15);

            // Create username label + entry
            auto *usernameLabel = new QLabel("Username:");
            auto *usernameEdit = new QLineEdit();
            usernameEdit->setPlaceholderText("Enter your username");

            // Create password label + entry
            auto *passwordLabel = new QLabel("Password:");
            auto *passwordEdit = new QLineEdit();
            passwordEdit->setPlaceholderText("Enter your password");
            passwordEdit->setEchoMode(QLineEdit::Password);

            // Create the submit button
            auto *submitButton = createButton("Submit", "#4CAF50");

            // Connect the submit button
            connect(submitButton, &QPushButton::clicked, this, &Pages::goToPage3);

            // Add widgets to the layout in order
            middleLayout->addWidget(usernameLabel);
            middleLayout->addWidget(usernameEdit);
            middleLayout->addWidget(passwordLabel);
            middleLayout->addWidget(passwordEdit);
            middleLayout->addWidget(submitButton, 0, Qt::AlignHCenter);
            middleBar->setLayout(middleLayout);

            layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
            layout->addWidget(middleBar, 0, Qt::AlignVCenter);
            layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
            break;
        }

        case Page3: {
            label->setText("Main Dashboard");

            // --- Scrollable area setup ---
            auto *scrollArea = new QScrollArea();
            scrollArea->setWidgetResizable(true);
            scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

            // --- Container inside scroll area for Winch buttons ---
            auto *scrollWidget = new QWidget();
            auto *winchLayout = new QVBoxLayout(scrollWidget);
            winchLayout->setAlignment(Qt::AlignTop);
            scrollWidget->setLayout(winchLayout);
            scrollArea->setWidget(scrollWidget);

            layout->addWidget(scrollArea, 1); // Takes available vertical space

            // --- Bottom fixed control bar (Settings + Add Widget) ---
            auto *bottomBar = new QWidget();
            auto *bottomLayout = new QHBoxLayout(bottomBar);
            bottomLayout->setContentsMargins(10, 10, 10, 10);
            bottomLayout->setSpacing(15);

            auto *settingsButton = createButton("Settings", "#2196F3");
            auto *addButton = createButton("Add Winch", "#4CAF50");

            bottomLayout->addWidget(settingsButton);
            bottomLayout->addWidget(addButton);
            bottomBar->setLayout(bottomLayout);

            layout->addWidget(bottomBar, 0, Qt::AlignBottom); // Fixed at bottom

            // --- Dynamic Winch button logic ---
            static int winchCounter = 0;

            connect(addButton, &QPushButton::clicked, this, [this, winchLayout]() mutable {
                ++winchCounter;
                int thisWinch = winchCounter;

                auto *newWinchButton = new QPushButton(QString("Winch %1").arg(thisWinch));
                newWinchButton->setStyleSheet(
                    "background-color: #FF9800; color: white; font-weight: bold; "
                    "padding: 10px; border-radius: 8px;"
                    );
                newWinchButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

                winchLayout->addWidget(newWinchButton);

                // Each Winch button opens its page
                connect(newWinchButton, &QPushButton::clicked, this, [this, thisWinch]() {
                    // goToWinchPage(thisWinch);
                    qDebug() << "Winch" << thisWinch;
                });
            });

            connect(settingsButton, &QPushButton::clicked, this, []() {
                qDebug() << "Settings clicked!";
            });
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
