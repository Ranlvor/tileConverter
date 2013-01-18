#include <QCoreApplication>
#include "TileIOInterfaces/FolderInterface.h"
#include "TileIOInterfaces/PictureInterface.h"
#include "TileIOInterfaces/NonchipTilesetV2Interface.h"
int main(int argc, char *argv[])
{
    FolderInterface fi;
    NonchipTilesetV2Interface ni;
    PictureInterface pi;
    pi.setSpacing(0);
    QList<QImage> tileList = pi.loadTileList(argv[1],32);
    //ni.saveTileList(tileList, "/tmp/testdata/output.raw");
    ni.saveTileList(tileList, argv[2]);
    //QCoreApplication a(argc, argv);
    //return a.exec();
}
