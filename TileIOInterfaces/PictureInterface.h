#ifndef PICTUREINTERFACE_H
#define PICTUREINTERFACE_H
#include "TileIOInterface.h"

class PictureInterface : public TileIOInterface
{
public:
    PictureInterface();
    void setOutputFormat(char* newOutputFormat);
    void setSpacing (int newSpacing);
    void setPicturesPerLine(int newPicturesPerLine);
    void saveTileList(QList<QImage> tl, QString destination);
    QImage createOutputImage(QList<QImage> tl);
    QList<QImage> loadTileList(QString source, int tileSize);
    QList<QImage> parseInputImage(QImage input, int tileSize);

private:
    char * outputFormat;
    int spacing = 0;
    int defaultPicturesPerLine = 0;
};

#endif // PICTUREINTERFACE_H
