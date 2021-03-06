#include "musickgdiscoverlistthread.h"
#include "musicdownloadkginterface.h"
#///QJson import
#include "qjson/parser.h"

MusicKGDiscoverListThread::MusicKGDiscoverListThread(QObject *parent)
    : MusicDownLoadDiscoverListThread(parent)
{

}

QString MusicKGDiscoverListThread::getClassName()
{
    return staticMetaObject.className();
}

void MusicKGDiscoverListThread::startToSearch()
{
    if(!m_manager)
    {
        return;
    }

    M_LOGGER_INFO(QString("%1 startToSearch").arg(getClassName()));
    m_toplistInfo.clear();
    QUrl musicUrl = MusicUtils::Algorithm::mdII(KG_SONG_TOPLIST_URL, false).arg(6666);
    deleteAll();
    m_interrupt = true;

    QNetworkRequest request;
    request.setUrl(musicUrl);
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", MusicUtils::Algorithm::mdII(KG_UA_URL_1, ALG_UA_KEY, false).toUtf8());
    setSslConfiguration(&request);

    m_reply = m_manager->get(request);
    connect(m_reply, SIGNAL(finished()), SLOT(downLoadFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(replyError(QNetworkReply::NetworkError)));
}

void MusicKGDiscoverListThread::downLoadFinished()
{
    if(m_reply == nullptr)
    {
        deleteAll();
        return;
    }

    M_LOGGER_INFO(QString("%1 downLoadFinished").arg(getClassName()));
    m_interrupt = false;

    if(m_reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = m_reply->readAll();

        QJson::Parser parser;
        bool ok;
        QVariant data = parser.parse(bytes, &ok);
        if(ok)
        {
            QVariantMap value = data.toMap();
            if(value.contains("songs"))
            {
                value = value["songs"].toMap();
                QVariantList datas = value["list"].toList();
                int where = datas.count();
                where = (where > 0) ? qrand()%where : 0;

                int counter = 0;
                foreach(const QVariant &var, datas)
                {
                    if(m_interrupt) return;

                    if((where != counter++) || var.isNull())
                    {
                        continue;
                    }

                    QVariantMap value = var.toMap();
                    m_toplistInfo = value["filename"].toString();
                    break;
                }
            }
        }
    }

    emit downLoadDataChanged(m_toplistInfo);
    deleteAll();
    M_LOGGER_INFO(QString("%1 downLoadFinished deleteAll").arg(getClassName()));
}
