#ifndef TILEIOINTERFACE_H
#define TILEIOINTERFACE_H
#include <QList>
#include <QImage>
#include <QDebug>
class TileIOInterface
{
    public:
        virtual void saveTileList(QList<QImage> /*tl*/, QString /*destination*/){
            qDebug()<<"this method is not implemented";
        }
        virtual QList<QImage> loadTileList(QString /*source*/, int /*tileSize*/){
            qDebug()<<"this method is not implemented";
            return QList<QImage>();
        }
};
#endif // TILEIOINTERFACE_H
