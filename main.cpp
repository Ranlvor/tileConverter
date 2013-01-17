#include <QCoreApplication>
#include "TileIOInterfaces/FolderInterface.h"
#include "TileIOInterfaces/PictureInterface.h"
#include "TileIOInterfaces/NonchipTilesetV2Interface.h"
int main(int argc, char *argv[])
{
    FolderInterface fi;
    NonchipTilesetV2Interface ni;
    PictureInterface pi;
    pi.setSpacing(100);
    QList<QImage> tileList = ni.loadTileList("/tmp/testdata/output.raw.0", 255);
    //ni.saveTileList(tileList, "/tmp/testdata/output.raw");
    fi.saveTileList(tileList, "/tmp/testdata/output");
    //QCoreApplication a(argc, argv);
    //return a.exec();
}
