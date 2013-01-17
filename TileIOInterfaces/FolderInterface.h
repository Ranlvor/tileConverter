#ifndef FOLDERINTERFACE_H
#define FOLDERINTERFACE_H
#include "TileIOInterface.h"
class FolderInterface : public TileIOInterface
{
public:
    FolderInterface();
    void setOutputFormat(char* newOutputFormat);
    //void saveTileList(QList<QImage> tl, QString destination);
    QList<QImage> loadTileList(QString source, int tileSize);

private:
    char * outputFormat;
};

#endif // FOLDERINTERFACE_H
