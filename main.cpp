#include <QCoreApplication>
#include "TileIOInterfaces/FolderInterface.h"
#include "TileIOInterfaces/PictureInterface.h"
#include "TileIOInterfaces/NonchipTilesetV2Interface.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    if(argc == 2){ //hardcodet to keep kompartible with old scripts
        NonchipTilesetV2Interface ni;
        PictureInterface pi;
        QList<QImage> tileList = pi.loadTileList(argv[1],32);
        ni.saveTileList(tileList, argv[2]);
    } else {
        TileIOInterface * input = 0;
        TileIOInterface * output = 0;
        QString source;
        QString destination;
        int tilesize = 0;

        for(int i = 1; i <= argc; ++i){
            QString parameter = argv[i];
            if((parameter == "--outputBackend") || (parameter == "-b")) {
                ++i;
                parameter = argv[i];
                if(parameter == "nonchip")
                    output = new NonchipTilesetV2Interface();
                else if (parameter == "picture")
                    output = new PictureInterface();
                else if (parameter == "folder")
                    output = new FolderInterface();
            } else if ((parameter == "--inputBackend") || (parameter == "-c")){
                ++i;
                parameter = argv[i];
                if(parameter == "nonchip")
                    input = new NonchipTilesetV2Interface();
                else if (parameter == "picture")
                    input = new PictureInterface();
                else if (parameter == "folder")
                    input = new FolderInterface();
            } else if ((parameter == "--input") || (parameter == "-i")){
                ++i;
                source = argv[i];
            } else if ((parameter == "--output") || (parameter == "-o")){
                ++i;
                destination = argv[i];
            } else if  ((parameter == "--tilesize") || (parameter == "-t")){
                ++i;
                qDebug()<<"trying to set tilesize"<<argv[i];
                tilesize = QVariant(argv[i]).toInt();
                qDebug()<<"tilesize"<<tilesize<<"set";
            }
        }

        if(input == 0){
            qFatal("no input-backend found");
        } else if (output == 0){
            qFatal("no output-backend found");
        } else if (source.isEmpty()){
            qFatal("no input found");
        } else if (destination.isEmpty()){
            qFatal("no output found");
        } else {
            qDebug()<<"calling input-backend with source"<<source<<"and tilesize"<<tilesize;
            QList<QImage> tl = input->loadTileList(source,tilesize);
            output->saveTileList(tl, destination);
        }
    }
}
