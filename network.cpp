#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

void Network::get(const QString &url)
{
    QNetworkRequest request((QUrl(url)));

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        handleReply(reply);
    });
}

void Network::post(const QString &url, const QJsonObject &json)
{
    QNetworkRequest request((QUrl(url)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray data = QJsonDocument(json).toJson();

    QNetworkReply *reply = manager->post(request, data);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        handleReply(reply);
    });
}

void Network::handleReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QString path = reply->url().path();
        emit requestFinished(path, reply->readAll());
    }
    else
    {
        emit requestError(reply->errorString());
    }

    reply->deleteLater();
}
