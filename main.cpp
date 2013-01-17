#include <QCoreApplication>
#include "TileIOInterfaces/FolderInterface.h"
#include "TileIOInterfaces/PictureInterface.h"
int main(int argc, char *argv[])
{
    FolderInterface fi;
    PictureInterface pi;
    QList<QImage> tileList = fi.loadTileList("/tmp/testdata/input", 255);
    pi.setSpacing(10);
    pi.saveTileList(tileList, "/tmp/testdata/output.png");
    //QCoreApplication a(argc, argv);
    //return a.exec();
}
