#ifndef PICTUREINTERFACE_H
#define PICTUREINTERFACE_H
#include "TileIOInterface.h"

class PictureInterface : public TileIOInterface
{
public:
    PictureInterface();
    void setOutputFormat(char* newOutputFormat);
    void setSpacing (int newSpacing);
    void saveTileList(QList<QImage> tl, QString destination);
    //QList<QImage> loadTileList(QString source, int tileSize);

private:
    char * outputFormat;
    int spacing = 0;
};

#endif // PICTUREINTERFACE_H
