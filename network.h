#ifndef NETWORK_H
#define NETWORK_H

#pragma once

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QUrl>
#include <QObject>

class Network : public QObject
{
    Q_OBJECT

public:
    explicit Network(QObject *parent = nullptr);

    void get(const QString &url);
    void post(const QString &url, const QJsonObject &json);

signals:
    void requestFinished(const QString &endpoint, const QString &response);
    void requestError(const QString &error);

private:
    QNetworkAccessManager *manager;

    void handleReply(QNetworkReply *reply);
};

#endif // NETWORK_H
