#ifndef NONCHIPTILESETV2INTERFACE_H
#define NONCHIPTILESETV2INTERFACE_H
#include "PictureInterface.h"

class NonchipTilesetV2Interface : public PictureInterface
{
public:
    NonchipTilesetV2Interface();
    void saveTileList(QList<QImage> tl, QString destination);
    void handleBatch(QList<QImage> tl, QString destination);
    QList<QImage> loadTileList(QString source, int tileSize); //only for the interface
    QList<QImage> loadTileList(QString source); //does the work
};

#endif // NONCHIPTILESETV2INTERFACE_H
