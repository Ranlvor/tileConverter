#include "NonchipTilesetV2Interface.h"
#include <QFile>
#include <QColor>

NonchipTilesetV2Interface::NonchipTilesetV2Interface()
{
    setPicturesPerLine(16);
}

void NonchipTilesetV2Interface::saveTileList(QList<QImage> tl, QString destination){
    if(tl.length() <= 256) {
        qDebug()<<"saving a single tileset";
        handleBatch(tl, destination);
        return;
    }
    int count = 0;
    while(tl.length() > 0){
        qDebug()<<"saving tileset"<<count;
        QList<QImage> nextBatch;
        while((nextBatch.length() < 256) && !tl.isEmpty()){
            nextBatch.append(tl.first());
            tl.removeFirst();
        }
        handleBatch(nextBatch,destination+"."+QVariant(count).toString());
        count++;
    }

}

void NonchipTilesetV2Interface::handleBatch(QList<QImage> tl, QString destination){
    QImage outputImage = createOutputImage(tl);
    qDebug()<<"writing output-file with estimated size of"<<(outputImage.width()*outputImage.height()*4)<<"bytes";
    QFile outputFile(destination);
    outputFile.open(QFile::WriteOnly);
    quint8 size = tl.first().width();
    outputFile.write( ( (char*) &size ),1); //1 byte tilesize in pixel
    QRgb pixel;
    quint8 value;
    for (int y = 0; y<outputImage.height(); ++y){
        for (int x = 0; x<outputImage.width(); ++x){
            pixel = outputImage.pixel(x,y);

            value = qRed(pixel);
            outputFile.write( ( (char*) &value ),1); //1 byte red value
            value = qGreen(pixel);
            outputFile.write( ( (char*) &value ),1); //1 byte green value
            value = qBlue(pixel);
            outputFile.write( ( (char*) &value ),1); //1 byte blue value
            value = qAlpha(pixel);
            outputFile.write( ( (char*) &value ),1); //1 byte alpha value
        }
    }
    outputFile.close();
}

QList<QImage> NonchipTilesetV2Interface::loadTileList(QString source, int /*tileSize*/){
    return loadTileList(source);
}

QList<QImage> NonchipTilesetV2Interface::loadTileList(QString source){
    QFile inputFile (source);
    inputFile.open(QFile::ReadOnly);
    quint8 tileSize;
    inputFile.read( ( (char*) &tileSize ),1);
    qDebug()<<"loading tileset with tileSize"<<tileSize;
    int width = tileSize * 16;
    int height = (inputFile.size()-1)/4/width;
    qDebug()<<"calculated size:"<<width<<"x"<<height;

    QImage inputImage(width, height, QImage::Format_ARGB32);
    quint8 value[4];
    for (int y = 0; y<height; ++y){
        for (int x = 0; x<width; ++x){
            inputFile.read( ( (char*) &value ),4);
            inputImage.setPixel(x,y,qRgba(value[0],value[1],value[2],value[3]));
        }
    }
    return parseInputImage(inputImage, tileSize);
}
