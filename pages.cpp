#include "pages.h"

Pages::Pages(QWidget *parent) : QWidget(parent)
{
    auto *rootLayout = new QVBoxLayout(this);

    stack = new QStackedWidget(this);
    rootLayout->addWidget(stack);

    stack->addWidget(createPage_Start());                   // index 0
    stack->addWidget(createPage_Login());                   // index 1
    stack->addWidget(createPage_Account());                 // index 2
    stack->addWidget(createPage_Dashboard());               // index 3
    stack->addWidget(createPage_Winch());                   // index 4
    stack->addWidget(createPage_Settings());                // index 5
    stack->addWidget(createPage_Sensor());                  // index 6
    stack->addWidget(createPage_Solar());                   // index 7
    stack->addWidget(createPage_Operations());              // index 8
    stack->addWidget(createPage_Camera());                  // index 9
    stack->addWidget(createPage_Winch_Help());              // index 10
    stack->addWidget(createPage_Find_Winch_Auto());         // index 11
    stack->addWidget(createPage_Find_Winch_Manual());       // index 12
    stack->addWidget(createPage_Found_Winch());             // index 13
    stack->addWidget(createPage_Find_Winch_Help());         // index 14
    stack->addWidget(createPage_Found_Winch_Help());        // index 15

    stack->setCurrentIndex(Start);
}

QWidget *Pages::createPage_Start() {
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Oyster Farm Management App");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

    auto *middleBar = new QWidget();
    auto *middleLayout = new QVBoxLayout(middleBar);
    middleLayout->setContentsMargins(10, 10, 10, 10);
    middleLayout->setSpacing(15);

    auto *loginButton = createButton("Login", "#4CAF50");
    auto *addAccountButton = createButton("Add Account", "#2196F3");

    connect(loginButton, &QPushButton::clicked, this, [this]() {
        switchPage(Start, Login);
    });
    connect(addAccountButton, &QPushButton::clicked, this, [this]() {
        switchPage(Start, Account);
    });

    middleLayout->addWidget(loginButton);
    middleLayout->addWidget(addAccountButton);
    middleBar->setLayout(middleLayout);

    layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(middleBar, 0, Qt::AlignHCenter);
    layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));

    return page;
}

QWidget *Pages::createPage_Login() {
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Login");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

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
    connect(submitButton, &QPushButton::clicked, this, [this]() {
        switchPage(Login, Dashboard);
    });

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

    return page;
}

QWidget *Pages::createPage_Account() {
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Add Account");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

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

    // Create password label + entry again
    auto *passwordLabelAgain = new QLabel("Re-enter Password:");
    auto *passwordEditAgain = new QLineEdit();
    passwordEditAgain->setPlaceholderText("Re-enter your password");
    passwordEditAgain->setEchoMode(QLineEdit::Password);

    // Create the add button
    auto *addButton = createButton("Add", "#4CAF50");

    // Connect the add button
    connect(addButton, &QPushButton::clicked, this, [this]() {
        switchPage(Account, Start);
    });

    // Add widgets to the layout in order
    middleLayout->addWidget(usernameLabel);
    middleLayout->addWidget(usernameEdit);
    middleLayout->addWidget(passwordLabel);
    middleLayout->addWidget(passwordEdit);
    middleLayout->addWidget(passwordLabelAgain);
    middleLayout->addWidget(passwordEditAgain);
    middleLayout->addWidget(addButton, 0, Qt::AlignHCenter);
    middleBar->setLayout(middleLayout);

    layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(middleBar, 0, Qt::AlignVCenter);
    layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));

    return page;
}

QWidget *Pages::createPage_Dashboard() {
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Main Dashboard");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

    // --- Scrollable area setup ---
    auto *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // --- Container inside scroll area for Winch buttons ---
    auto *scrollWidget = new QWidget();
    winchLayout = new QVBoxLayout(scrollWidget);
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

    for (const auto &entry : winchVector) {
        auto *newBtn = createWinchButton(entry);
        winchLayout->addWidget(newBtn);
    }

    connect(addButton, &QPushButton::clicked, this, [this]() {
        // winchVector.emplace_back(winchCounter++);
        // auto *newBtn = createWinchButton(winchVector.back());

        // winchLayout->addWidget(newBtn);

        switchPage(Dashboard, Find_Winch_Auto);
    });

    connect(settingsButton, &QPushButton::clicked, this, [this]() {
        switchPage(Dashboard, Settings);
    });

    return page;
}

QWidget *Pages::createPage_Winch()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);

    auto *topBar = new QWidget();
    auto *topLayout = new QGridLayout(topBar);

    topLayout->setContentsMargins(0, 0, 0, 0);
    topLayout->setColumnStretch(0, 1);
    topLayout->setColumnStretch(1, 0);
    topLayout->setColumnStretch(2, 1);

    // --- Title ---
    winchTitleLabel = new QLabel("Winch");
    winchTitleLabel->setAlignment(Qt::AlignCenter);
    winchTitleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    topLayout->addWidget(winchTitleLabel, 0, 1);

    // --- Help button ---
    auto *helpButton = createHelpButton(Winch);
    topLayout->addWidget(helpButton, 0, 2, Qt::AlignRight | Qt::AlignVCenter);

    layout->addWidget(topBar, 1);

    // --- ID ---
    idLabel = new QLabel();
    idLabel->setStyleSheet("font-size: 18px;");
    layout->addWidget(idLabel);

    // --- Connection ---
    connectionLabel = new QLabel();
    layout->addWidget(connectionLabel);

    // --- Status ---
    statusLabel = new QLabel();
    statusLabel->setStyleSheet("font-size: 18px;");
    layout->addWidget(statusLabel);

    // --- Height ---
    heightLabel = new QLabel();
    heightLabel->setStyleSheet("font-size: 18px;");
    layout->addWidget(heightLabel);

    // --- Water Level ---
    waterLabel = new QLabel();
    waterLabel->setStyleSheet("font-size: 18px;");
    layout->addWidget(waterLabel);

    // --- Schedule ---
    scheduleLabel = new QLabel(
        "Next Scheduled Action(s):\n"
        "    11:30AM 10/10/25 UP\n"
        "    12:00PM 10/10/25 DOWN\n"
        "    11:30AM 10/11/25 UP\n"
        "    12:00PM 10/11/25 DOWN"
        );
    scheduleLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scheduleLabel->setStyleSheet("font-size: 18px;");
    scheduleLabel->setWordWrap(true);
    layout->addWidget(scheduleLabel);

    // ----- Middle buttons -----
    auto *middleBar = new QWidget();
    auto *middleLayout = new QVBoxLayout(middleBar);

    auto *sensorButton = createButton("Sensor Data", "#FF9800");
    auto *solarButton = createButton("Solar Panel Data", "#FF9800");
    auto *operationButton = createButton("Operation Schedule", "#FF9800");
    auto *cameraButton = createButton("Camera", "#FF9800");

    middleLayout->addWidget(sensorButton);
    middleLayout->addWidget(solarButton);
    middleLayout->addWidget(operationButton);
    middleLayout->addWidget(cameraButton);

    layout->addWidget(middleBar, 1);

    connect(sensorButton, &QPushButton::clicked, this, [this]() {
        switchPage(Winch, Sensor);
    });
    connect(solarButton, &QPushButton::clicked, this, [this]() {
        switchPage(Winch, Solar);
    });
    connect(operationButton, &QPushButton::clicked, this, [this]() {
        switchPage(Winch, Operations);
    });
    connect(cameraButton, &QPushButton::clicked, this, [this]() {
        switchPage(Winch, Camera);
    });

    // --- Bottom bar ---
    auto *bottomBar = new QWidget();
    auto *bottomLayout = new QHBoxLayout(bottomBar);

    auto *backButton = createButton("Back", "#2196F3");
    auto *editButton = createButton("Edit", "#4CAF50");

    bottomLayout->addWidget(backButton);
    bottomLayout->addWidget(editButton);
    layout->addWidget(bottomBar, 0, Qt::AlignBottom);

    connect(backButton, &QPushButton::clicked, this, [this]() {
        switchPage(Winch, Dashboard);
    });

    return page;
}

QWidget *Pages::createPage_Settings()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Settings");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

    auto *middleBar = new QWidget();
    auto *middleLayout = new QVBoxLayout(middleBar);
    middleLayout->setContentsMargins(10, 10, 10, 10);
    middleLayout->setSpacing(15);

    auto *operationsButton = createButton("Operation Schedule", "#FF9800");
    auto *userButton = createButton("User Info", "#FF9800");

    QString operations = "Auto/Manual";

    QLabel *operationsLabel = new QLabel(operations, this);
    operationsLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    operationsLabel->setStyleSheet("font-size: 18px;");
    operationsLabel->setWordWrap(true); // ensure long lines wrap

    connect(operationsButton, &QPushButton::clicked, this, [this]() {
        switchPage(Settings, Operations);
    });

    QString user =
        "Audit Info:\n"
        "Who has made what changes and when";

    QLabel *userLabel = new QLabel(user, this);
    userLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    userLabel->setStyleSheet("font-size: 18px;");
    userLabel->setWordWrap(true); // ensure long lines wrap

    middleLayout->addWidget(operationsButton);
    middleLayout->addWidget(operationsLabel);
    middleLayout->addWidget(userButton);
    middleLayout->addWidget(userLabel);

    layout->addWidget(middleBar, 1);

    auto *backButton = createButton("Back", "#2196F3");

    layout->addWidget(backButton, 0, Qt::AlignBottom); // Fixed at bottom

    connect(backButton, &QPushButton::clicked, this, [this]() {
        switchPage(Settings, Dashboard);
    });

    return page;
}

QWidget *Pages::createPage_Sensor()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Sensor Data");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

    // winch currentWinch = NULL;

    // if (!winchVector.empty())
    //     currentWinch = winchVector[winchSelected - 1];

    // int displayNum = currentWinch.displayNumber();
    // label->setText("Winch " + QString::number(displayNum) + ": Sensor Data");

    // --- Chart ---
    auto *chart = new QChart();
    chart->setTitle("Sensor Readings Over Time");
    chart->legend()->setVisible(true);

    auto *tempSeries = new QLineSeries();
    tempSeries->setName("Temperature");

    auto *heightSeries = new QLineSeries();
    heightSeries->setName("Height");

    tempSeries->append(0, 60);
    tempSeries->append(1, 62);
    tempSeries->append(2, 63);
    tempSeries->append(3, 61);

    heightSeries->append(0, 61);
    heightSeries->append(1, 63);
    heightSeries->append(2, 62);
    heightSeries->append(3, 60);

    chart->addSeries(tempSeries);
    chart->addSeries(heightSeries);

    auto *axisX = new QValueAxis();
    axisX->setTitleText("Time");

    auto *axisY = new QValueAxis();
    axisY->setTitleText("Measurement");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    tempSeries->attachAxis(axisX);
    tempSeries->attachAxis(axisY);
    heightSeries->attachAxis(axisX);
    heightSeries->attachAxis(axisY);

    auto *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);

    // --- Toggle Buttons Under Chart ---
    auto *buttonRow = new QWidget();
    auto *buttonLayout = new QHBoxLayout(buttonRow);
    buttonLayout->setContentsMargins(10, 10, 10, 10);
    buttonLayout->setSpacing(20);

    auto *tempButton = new QPushButton("Temperature");
    tempButton->setCheckable(true);
    tempButton->setChecked(true);

    auto *heightButton = new QPushButton("Height");
    heightButton->setCheckable(true);
    heightButton->setChecked(true);

    buttonLayout->addWidget(tempButton);
    buttonLayout->addWidget(heightButton);

    layout->addWidget(buttonRow, 1);

    // --- Toggle Logic ---
    connect(tempButton, &QPushButton::toggled, this,
            [tempSeries](bool checked) { tempSeries->setVisible(checked); });

    connect(heightButton, &QPushButton::toggled, this,
            [heightSeries](bool checked) { heightSeries->setVisible(checked); });

    // --- Bottom fixed control bar (Back + Settings) ---
    auto *bottomBar = new QWidget();
    auto *bottomLayout = new QHBoxLayout(bottomBar);
    bottomLayout->setContentsMargins(10, 10, 10, 10);
    bottomLayout->setSpacing(15);

    auto *backButton = createButton("Back", "#2196F3");
    auto *settingsButton = createButton("Settings", "#4CAF50");

    bottomLayout->addWidget(backButton);
    bottomLayout->addWidget(settingsButton);
    bottomBar->setLayout(bottomLayout);

    layout->addWidget(bottomBar, 0, Qt::AlignBottom); // Fixed at bottom

    connect(backButton, &QPushButton::clicked, this, [this]() {
        switchPage(Sensor, lastPage);
    });

    return page;
}

QWidget *Pages::createPage_Solar()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Solar Panel Data");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

    // winch currentWinch = NULL;

    // if (!winchVector.empty())
    //     currentWinch = winchVector[winchSelected - 1];

    // int displayNum = currentWinch.displayNumber();

    // // int displayNum = winchVector[winchSelected - 1].displayNumber();
    // label->setText("Winch " + QString::number(displayNum) + ": Solar Data");

    // --- Chart ---
    auto *chart = new QChart();
    chart->setTitle("Sensor Readings Over Time");
    chart->legend()->setVisible(true);

    auto *tempSeries = new QLineSeries();
    tempSeries->setName("CT");

    auto *lVoltSeries = new QLineSeries();
    lVoltSeries->setName("LV");

    auto *sCurrentSeries = new QLineSeries();
    sCurrentSeries->setName("SPC");

    auto *sPowerSeries = new QLineSeries();
    sPowerSeries->setName("SPP");

    auto *sVoltSeries = new QLineSeries();
    sVoltSeries->setName("SPV");

    tempSeries->append(0, 60);
    tempSeries->append(1, 62);
    tempSeries->append(2, 63);
    tempSeries->append(3, 61);

    lVoltSeries->append(0, 61);
    lVoltSeries->append(1, 63);
    lVoltSeries->append(2, 62);
    lVoltSeries->append(3, 60);

    sCurrentSeries->append(0, 60.5);
    sCurrentSeries->append(1, 60.5);
    sCurrentSeries->append(2, 60.5);
    sCurrentSeries->append(3, 60.5);

    sPowerSeries->append(0, 61.5);
    sPowerSeries->append(1, 61.5);
    sPowerSeries->append(2, 61.5);
    sPowerSeries->append(3, 61.5);

    sVoltSeries->append(0, 62.5);
    sVoltSeries->append(1, 62.5);
    sVoltSeries->append(2, 62.5);
    sVoltSeries->append(3, 62.5);

    chart->addSeries(tempSeries);
    chart->addSeries(lVoltSeries);
    chart->addSeries(sCurrentSeries);
    chart->addSeries(sPowerSeries);
    chart->addSeries(sVoltSeries);

    auto *axisX = new QValueAxis();
    axisX->setTitleText("Time");

    auto *axisY = new QValueAxis();
    axisY->setTitleText("Measurement");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    tempSeries->attachAxis(axisX);
    tempSeries->attachAxis(axisY);
    lVoltSeries->attachAxis(axisX);
    lVoltSeries->attachAxis(axisY);
    sCurrentSeries->attachAxis(axisX);
    sCurrentSeries->attachAxis(axisY);
    sPowerSeries->attachAxis(axisX);
    sPowerSeries->attachAxis(axisY);
    sVoltSeries->attachAxis(axisX);
    sVoltSeries->attachAxis(axisY);

    auto *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);

    // --- Toggle Buttons Under Chart ---
    auto *buttonRow = new QWidget();
    auto *buttonLayout = new QVBoxLayout(buttonRow);
    buttonLayout->setContentsMargins(10, 10, 10, 10);
    buttonLayout->setSpacing(20);

    auto *tempButton = new QPushButton("Controller Temperature");
    tempButton->setCheckable(true);
    tempButton->setChecked(true);

    auto *lVoltButton = new QPushButton("Load Voltage");
    lVoltButton->setCheckable(true);
    lVoltButton->setChecked(true);

    auto *sCurrentButton = new QPushButton("Solar Panel Current");
    sCurrentButton->setCheckable(true);
    sCurrentButton->setChecked(true);

    auto *sPowerButton = new QPushButton("Solar Panel Power");
    sPowerButton->setCheckable(true);
    sPowerButton->setChecked(true);

    auto *sVoltButton = new QPushButton("Solar Panel Voltage");
    sVoltButton->setCheckable(true);
    sVoltButton->setChecked(true);

    buttonLayout->addWidget(tempButton);
    buttonLayout->addWidget(lVoltButton);
    buttonLayout->addWidget(sCurrentButton);
    buttonLayout->addWidget(sPowerButton);
    buttonLayout->addWidget(sVoltButton);

    layout->addWidget(buttonRow, 1);

    // --- Toggle Logic ---
    connect(tempButton, &QPushButton::toggled, this,
            [tempSeries](bool checked) { tempSeries->setVisible(checked); });

    connect(lVoltButton, &QPushButton::toggled, this,
            [lVoltSeries](bool checked) { lVoltSeries->setVisible(checked); });

    connect(sCurrentButton, &QPushButton::toggled, this,
            [sCurrentSeries](bool checked) { sCurrentSeries->setVisible(checked); });

    connect(sPowerButton, &QPushButton::toggled, this,
            [sPowerSeries](bool checked) { sPowerSeries->setVisible(checked); });

    connect(sVoltButton, &QPushButton::toggled, this,
            [sVoltSeries](bool checked) { sVoltSeries->setVisible(checked); });

    // --- Bottom fixed control bar (Back + Settings) ---
    auto *bottomBar = new QWidget();
    auto *bottomLayout = new QHBoxLayout(bottomBar);
    bottomLayout->setContentsMargins(10, 10, 10, 10);
    bottomLayout->setSpacing(15);

    auto *backButton = createButton("Back", "#2196F3");
    auto *settingsButton = createButton("Settings", "#4CAF50");

    bottomLayout->addWidget(backButton);
    bottomLayout->addWidget(settingsButton);
    bottomBar->setLayout(bottomLayout);

    layout->addWidget(bottomBar, 0, Qt::AlignBottom); // Fixed at bottom

    connect(backButton, &QPushButton::clicked, this, [this]() {
        switchPage(Solar, lastPage);
    });

    return page;
}

QWidget *Pages::createPage_Operations()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Operation Schedule");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

    auto *middleBar = new QWidget();
    auto *middleLayout = new QVBoxLayout(middleBar);
    middleLayout->setContentsMargins(10, 10, 10, 10);
    middleLayout->setSpacing(15);

    QString info =
        "Appears as a calendar with options to\n"
        "show day, week, month\n\n"
        "Should show every past action\n"
        "Should show every future planned action\n"
        "with option to set to auto or manually adjust\n\n"
        "Options for displaying any number of farms at once";

    QLabel *infoLabel = new QLabel(info, this);
    infoLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    infoLabel->setStyleSheet("font-size: 18px;");
    infoLabel->setWordWrap(true); // ensure long lines wrap

    middleLayout->addWidget(infoLabel);

    layout->addWidget(middleBar, 1);

    auto *backButton = createButton("Back", "#2196F3");

    layout->addWidget(backButton, 0, Qt::AlignBottom); // Fixed at bottom

    connect(backButton, &QPushButton::clicked, this, [this]() {
        switchPage(Operations, lastPage);
    });

    return page;
}

QWidget *Pages::createPage_Camera()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Camera");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

    auto *middleBar = new QWidget();
    auto *middleLayout = new QVBoxLayout(middleBar);
    middleLayout->setContentsMargins(10, 10, 10, 10);
    middleLayout->setSpacing(15);

    QString info =
        "List of recent photos";

    QLabel *infoLabel = new QLabel(info, this);
    infoLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    infoLabel->setStyleSheet("font-size: 18px;");
    infoLabel->setWordWrap(true); // ensure long lines wrap

    middleLayout->addWidget(infoLabel);

    layout->addWidget(middleBar, 1);

    // --- Bottom fixed control bar (Back + Take Picture) ---
    auto *bottomBar = new QWidget();
    auto *bottomLayout = new QHBoxLayout(bottomBar);
    bottomLayout->setContentsMargins(10, 10, 10, 10);
    bottomLayout->setSpacing(15);

    auto *backButton = createButton("Back", "#2196F3");
    auto *pictureButton = createButton("Take Picture", "#4CAF50");

    bottomLayout->addWidget(backButton);
    bottomLayout->addWidget(pictureButton);
    bottomBar->setLayout(bottomLayout);

    layout->addWidget(bottomBar, 0, Qt::AlignBottom); // Fixed at bottom

    connect(backButton, &QPushButton::clicked, this, [this]() {
        switchPage(Camera, lastPage);
    });

    return page;
}

QWidget *Pages::createPage_Winch_Help()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Help Page - Winches");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

    // --- Scrollable area setup ---
    auto *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QString info =
        "Cage Status: UP/DOWN\n"
        "Cage Height: measured in feet\n"
        "Water Level: measured in feet\n\n"
        "Next Scheduled Action(s):\n"
        "    TIME DATE ACTION\n"
        "    TIME DATE ACTION\n\n"
        "Sensor Data: See a graph of past temperature"
        "and cage height measurements\n\n"
        "Solar Panel Data: See a graph of past voltage,"
        "current, and power measurements from the solar panel\n\n"
        "Operation Schedule: See/edit the current scheduled"
        "lifts, or lift/lower a cage manually\n\n"
        "Camera: See a list of past photos and"
        "option to take a photo now\n\n"
        "Edit: Change information such as the winch name or ID";

    QLabel *infoLabel = new QLabel(info, this);
    infoLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    infoLabel->setStyleSheet("font-size: 18px;");
    infoLabel->setWordWrap(true); // ensure long lines wrap

    auto *scrollWidget = new QWidget();
    auto *helpLayout = new QVBoxLayout(scrollWidget);
    helpLayout->setContentsMargins(10, 10, 10, 10);
    helpLayout->setSpacing(15);
    helpLayout->addWidget(infoLabel);
    scrollWidget->setLayout(helpLayout);
    scrollArea->setWidget(scrollWidget);

    layout->addWidget(scrollArea, 1);

    auto *exitButton = createButton("Exit Help Page", "#2196F3");

    layout->addWidget(exitButton, 0, Qt::AlignBottom); // Fixed at bottom

    connect(exitButton, &QPushButton::clicked, this, [this]() {
        switchPage(Winch_Help, lastPage);
    });

    return page;
}

QWidget *Pages::createPage_Find_Winch_Auto()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);

    auto *topBar = new QWidget();
    auto *topLayout = new QGridLayout(topBar);

    topLayout->setContentsMargins(0, 0, 0, 0);
    topLayout->setColumnStretch(0, 1);
    topLayout->setColumnStretch(1, 0);
    topLayout->setColumnStretch(2, 1);

    // --- Title ---
    auto *titleLabel = new QLabel("Find Nearby Winches");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    topLayout->addWidget(titleLabel, 0, 1);

    // --- Help button ---
    auto *helpButton = createHelpButton(Find_Winch_Auto);
    topLayout->addWidget(helpButton, 0, 2, Qt::AlignRight | Qt::AlignVCenter);

    layout->addWidget(topBar, 0, Qt::AlignTop);

    // --- Scrollable area setup ---
    auto *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // --- Container inside scroll area for Winch buttons ---
    auto *scrollWidget = new QWidget();
    auto *searchLayout = new QVBoxLayout(scrollWidget);
    searchLayout->setAlignment(Qt::AlignTop);
    scrollWidget->setLayout(searchLayout);
    scrollArea->setWidget(scrollWidget);

    layout->addWidget(scrollArea, 1);

    auto *newBtn = new QPushButton("Test");

    searchLayout->addWidget(newBtn);

    connect(newBtn, &QPushButton::clicked, this, [this]() {
        switchPage(Find_Winch_Auto, Found_Winch);
    });

    // --- Bottom bar ---
    auto *bottomBar = new QWidget();
    auto *bottomLayout = new QHBoxLayout(bottomBar);

    auto *backButton = createButton("Back", "#2196F3");
    auto *manualButton = createButton("Manual Search", "#4CAF50");

    bottomLayout->addWidget(backButton);
    bottomLayout->addWidget(manualButton);
    layout->addWidget(bottomBar, 0, Qt::AlignBottom);

    connect(backButton, &QPushButton::clicked, this, [this]() {
        switchPage(Find_Winch_Auto, Dashboard);
    });

    connect(manualButton, &QPushButton::clicked, this, [this]() {
        switchPage(Find_Winch_Auto, Find_Winch_Manual);
    });

    return page;
}

QWidget *Pages::createPage_Find_Winch_Manual()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);

    auto *topBar = new QWidget();
    auto *topLayout = new QGridLayout(topBar);

    topLayout->setContentsMargins(0, 0, 0, 0);
    topLayout->setColumnStretch(0, 1);
    topLayout->setColumnStretch(1, 0);
    topLayout->setColumnStretch(2, 1);

    // --- Title ---
    auto *titleLabel = new QLabel("Find Nearby Winches");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    topLayout->addWidget(titleLabel, 0, 1);

    // --- Help button ---
    auto *helpButton = createHelpButton(Find_Winch_Manual);
    topLayout->addWidget(helpButton, 0, 2, Qt::AlignRight | Qt::AlignVCenter);

    layout->addWidget(topBar, 0, Qt::AlignTop);

    // --- Scrollable area setup ---
    auto *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // --- Container inside scroll area for Winch buttons ---
    auto *scrollWidget = new QWidget();
    auto *searchLayout = new QVBoxLayout(scrollWidget);
    searchLayout->setAlignment(Qt::AlignTop);
    scrollWidget->setLayout(searchLayout);
    scrollArea->setWidget(scrollWidget);

    layout->addWidget(scrollArea, 1);

    auto *newBtn = new QPushButton("Test");

    searchLayout->addWidget(newBtn);

    connect(newBtn, &QPushButton::clicked, this, [this]() {
        switchPage(Find_Winch_Manual, Found_Winch);
    });

    // --- Bottom bar ---
    auto *bottomBar = new QWidget();
    auto *bottomLayout = new QHBoxLayout(bottomBar);

    auto *backButton = createButton("Back", "#2196F3");

    bottomLayout->addWidget(backButton);
    layout->addWidget(bottomBar, 0, Qt::AlignBottom);

    connect(backButton, &QPushButton::clicked, this, [this]() {
        switchPage(Find_Winch_Manual, Find_Winch_Auto);
    });

    return page;
}

QWidget *Pages::createPage_Found_Winch()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);

    auto *topBar = new QWidget();
    auto *topLayout = new QGridLayout(topBar);

    topLayout->setContentsMargins(0, 0, 0, 0);
    topLayout->setColumnStretch(0, 1);
    topLayout->setColumnStretch(1, 0);
    topLayout->setColumnStretch(2, 1);

    // --- Title ---
    auto *titleLabel = new QLabel("Found Winch");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    topLayout->addWidget(titleLabel, 0, 1);

    // --- Help button ---
    auto *helpButton = createHelpButton(Found_Winch);
    topLayout->addWidget(helpButton, 0, 2, Qt::AlignRight | Qt::AlignVCenter);

    layout->addWidget(topBar, 0, Qt::AlignTop);

    // --- Bottom bar ---
    auto *bottomBar = new QWidget();
    auto *bottomLayout = new QHBoxLayout(bottomBar);

    auto *backButton = createButton("Back", "#2196F3");
    auto *addButton = createButton("Add Winch", "#4CAF50");

    bottomLayout->addWidget(backButton);
    bottomLayout->addWidget(addButton);
    layout->addWidget(bottomBar, 0, Qt::AlignBottom);

    connect(backButton, &QPushButton::clicked, this, [this]() {
        switchPage(Found_Winch, lastPage);
    });

    connect(addButton, &QPushButton::clicked, this, [this]() {
        winchVector.emplace_back(winchCounter++);

        auto *newBtn = createWinchButton(winchVector.back());

        winchLayout->addWidget(newBtn);

        switchPage(Found_Winch, Dashboard);
    });

    return page;
}

QWidget *Pages::createPage_Find_Winch_Help()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Help Page - Find Winch");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

    auto *middleBar = new QWidget();
    auto *middleLayout = new QVBoxLayout(middleBar);
    middleLayout->setContentsMargins(10, 10, 10, 10);
    middleLayout->setSpacing(15);

    QString info =
        "This page allows the user to see all winches that"
        "are available to add nearby. The user can use the"
        "“Manual Search” button to add a winch that"
        "isn’t found/listed.";

    QLabel *infoLabel = new QLabel(info, this);
    infoLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    infoLabel->setStyleSheet("font-size: 18px;");
    infoLabel->setWordWrap(true); // ensure long lines wrap

    middleLayout->addWidget(infoLabel);

    layout->addWidget(middleBar, 1);

    auto *exitButton = createButton("Exit Help Page", "#2196F3");

    layout->addWidget(exitButton, 0, Qt::AlignBottom); // Fixed at bottom

    connect(exitButton, &QPushButton::clicked, this, [this]() {
        switchPage(Winch_Help, lastPage);
    });

    return page;
}

QWidget *Pages::createPage_Found_Winch_Help()
{
    auto *page = new QWidget();
    auto *layout = new QVBoxLayout(page);
    auto *label = new QLabel("Help Page - Found Winch");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(label, 0, Qt::AlignTop);

    auto *middleBar = new QWidget();
    auto *middleLayout = new QVBoxLayout(middleBar);
    middleLayout->setContentsMargins(10, 10, 10, 10);
    middleLayout->setSpacing(15);

    QString info =
        "This page gives the user information about the"
        "winch that they would like to add\n\n"
        "ADD WINCH - adds the winch to the main dashboard";

    QLabel *infoLabel = new QLabel(info, this);
    infoLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    infoLabel->setStyleSheet("font-size: 18px;");
    infoLabel->setWordWrap(true); // ensure long lines wrap

    middleLayout->addWidget(infoLabel);

    layout->addWidget(middleBar, 1);

    auto *exitButton = createButton("Exit Help Page", "#2196F3");

    layout->addWidget(exitButton, 0, Qt::AlignBottom); // Fixed at bottom

    connect(exitButton, &QPushButton::clicked, this, [this]() {
        switchPage(Found_Winch);
    });

    return page;
}

void Pages::switchPage(PageType prevPage, PageType nextPage)
{
    lastPage = prevPage;

    stack->setCurrentIndex(nextPage);
}

void Pages::switchPage(PageType type)
{
    stack->setCurrentIndex(type);
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

QPushButton *Pages::createHelpButton(PageType type)
{
    constexpr int DIAMETER = 30;

    auto *btn = new QPushButton("?");
    btn->setFixedSize(DIAMETER, DIAMETER);

    btn->setStyleSheet(QString(
                           "QPushButton {"
                           " background-color: #808080;"
                           " color: black;"
                           " font-weight: bold;"
                           " font-size: 24px;"
                           " border: 3px solid black;"
                           " border-radius: %1px;"
                           " padding: 0px;"
                           "}"
                           ).arg(DIAMETER / 2));

    switch(type) {
        case Winch:
        {
            connect(btn, &QPushButton::clicked, this, [this]() {
                switchPage(Winch, Winch_Help);
            });

            break;
        }
        case Find_Winch_Auto:
        {
            connect(btn, &QPushButton::clicked, this, [this]() {
                switchPage(Find_Winch_Auto, Find_Winch_Help);
            });

            break;
        }
        case Find_Winch_Manual:
        {
            connect(btn, &QPushButton::clicked, this, [this]() {
                switchPage(Find_Winch_Manual, Find_Winch_Help);
            });

            break;
        }
        case Found_Winch:
        {
            connect(btn, &QPushButton::clicked, this, [this]() {
                switchPage(Found_Winch_Help);
            });

            break;
        }
        default: break;
    }

    return btn;
}

void Pages::openWinchPage(int index)
{
    if (index < 0 || index >= winchVector.size())
        return;

    winchSelected = index;
    currentWinch = &winchVector[index];

    winchTitleLabel->setText(
        "Winch " + QString::number(currentWinch->displayNumber())
        );

    idLabel->setText(
        "ID: " + QString::number(currentWinch->displayID())
        );

    if (currentWinch->isConnected()) {
        connectionLabel->setText("Connected");
        connectionLabel->setStyleSheet("font-size: 18px; color: green;");
    } else {
        connectionLabel->setText("Disconnected");
        connectionLabel->setStyleSheet("font-size: 18px; color: red;");
    }

    statusLabel->setText(
        currentWinch->isDown()
            ? "Cage Status: DOWN"
            : "Cage Status: UP"
        );

    heightLabel->setText(
        "Cage Height: " +
        QString::number(currentWinch->displayCageHeight()) + " ft"
        );

    waterLabel->setText(
        "Water Level: " +
        QString::number(currentWinch->displayWaterLevel()) + " ft"
        );

    switchPage(Dashboard, Winch);
}

QPushButton* Pages::createWinchButton(winch entry)
{
    int index = entry.displayNumber() - 1;

    auto *btn = new QPushButton(QString("Winch %1").arg(entry.displayNumber()));
    btn->setStyleSheet(
        "background-color: #FF9800;"
        "color: white;"
        "font-weight: bold;"
        "padding: 10px;"
        "border-radius: 8px;"
        );
    btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    connect(btn, &QPushButton::clicked, this, [this, index]() {
        openWinchPage(index);
    });

    return btn;
}
