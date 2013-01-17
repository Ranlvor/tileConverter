#include "FolderInterface.h"
#include <QDir>

FolderInterface::FolderInterface()
{
    outputFormat = "png";
}

void FolderInterface::setOutputFormat(char* newOutputFormat){
    outputFormat = newOutputFormat;
}

QList<QImage> FolderInterface::loadTileList(QString source, int tileSize){
    qDebug()<<"loading tiles from "<<source;
    QList<QImage> output;
    QSize outputSize(tileSize, tileSize);
    QDir inputDir(source);
    inputDir.setFilter(QDir::Files|QDir::Readable|QDir::NoDotAndDotDot); //nonchip says . and .. could be files. Sounds strange.
    inputDir.setSorting(QDir::Name);
    QStringList inputFileList = inputDir.entryList();
    if(inputFileList.isEmpty())
        return output;

    for (int i = 0; i < inputFileList.size(); ++i) {
       QString inputFile = inputFileList.at(i);
       QImage inputImage;
       inputImage.load(source+"/"+inputFile);
       QImage outputImage = inputImage.scaled(outputSize);
       output.append(outputImage);
    }

    return output;
}

void FolderInterface::saveTileList(QList<QImage> tl, QString destination){
    QDir destinationFolder(destination);
    if(!destinationFolder.isReadable())
        return;

    for(int i = 0; i < tl.size(); ++i){
        QImage image = tl.at(i);
        image.save(destination+"/"+QVariant(i).toString()+"."+outputFormat, outputFormat);
    }
}
