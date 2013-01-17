#include <QCoreApplication>
#include "TileIOInterfaces/FolderInterface.h"
#include "TileIOInterfaces/PictureInterface.h"
#include "TileIOInterfaces/NonchipTilesetV2Interface.h"
int main(int argc, char *argv[])
{
    FolderInterface fi;
    NonchipTilesetV2Interface pi;
    QList<QImage> tileList = fi.loadTileList("/tmp/testdata/input", 255);
    pi.setSpacing(10);
    pi.saveTileList(tileList, "/tmp/testdata/output.raw");
    //QCoreApplication a(argc, argv);
    //return a.exec();
}
