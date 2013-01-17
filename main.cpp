#include <QCoreApplication>
#include "TileIOInterfaces/FolderInterface.h"
int main(int argc, char *argv[])
{
    FolderInterface fi;
    QList<QImage> tileList = fi.loadTileList("/tmp/testdata/input", 255);
    fi.saveTileList(tileList, "/tmp/testdata/output");
    //QCoreApplication a(argc, argv);
    //return a.exec();
}
