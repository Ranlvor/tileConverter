#include "FolderInterface.h"
#include <QDir>

FolderInterface::FolderInterface()
{
    outputFormat = "PNG";
}

void FolderInterface::setOutputFormat(char* newOutputFormat){
    outputFormat = newOutputFormat;
}

//void saveTileList(QList<QImage> tl, QString destination);
QList<QImage> FolderInterface::loadTileList(QString source, int tileSize){
    qDebug()<<"loading tiles from "<<source;
    QList<QImage> output;
    QSize outputSize(tileSize, tileSize);
    QDir inputDir(source);
    inputDir.setFilter(QDir::Files|QDir::Readable|QDir::NoDotAndDotDot); //nonchip says . and .. could be files. Sounds strange.
    inputDir.setSorting(QDir::Name);
    QStringList inputFileList = inputDir.entryList();
    if(!inputFileList.isEmpty()){
        for (int i = 0; i < inputFileList.size(); ++i) {
            QString inputFile = inputFileList.at(i);
            QImage inputImage;
            inputImage.load(source+"/"+inputFile);
            QImage outputImage = inputImage.scaled(outputSize);
            output.append(outputImage);
        }
    }
    return output;
}
