#ifndef INAPPMESSAGE_H
#define INAPPMESSAGE_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class InAppMessage : public QFrame
{
public:
    explicit InAppMessage(QWidget *parent = nullptr, QLabel *label = new QLabel())
        : QFrame(parent)
    {
        setStyleSheet(R"(
            QFrame {
                background: black;
                border-radius: 12px;
            }
        )");

        setFixedSize(300, 300);

        auto *layout = new QVBoxLayout(this);

        // QLabel *label = new QLabel("Event saved successfully", this);
        label->setWordWrap(true);

        QPushButton *ok = new QPushButton("OK", this);

        layout->addWidget(label);
        layout->addStretch();
        layout->addWidget(ok);

        connect(ok, &QPushButton::clicked, this, &QWidget::hide);
    }
};

#endif // INAPPMESSAGE_H
