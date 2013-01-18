#include "PictureInterface.h"
#include <qmath.h>
#include <QColor>
#include <QPainter>
PictureInterface::PictureInterface()
{
    outputFormat = "png";
    spacing=0;
    defaultPicturesPerLine=0;
}

void PictureInterface::setOutputFormat(char* newOutputFormat){
    outputFormat = newOutputFormat;
}
void PictureInterface::setSpacing (int newSpacing){
    spacing = newSpacing;
}
void PictureInterface::setPicturesPerLine (int newPicturesPerLine){
    defaultPicturesPerLine = newPicturesPerLine;
}

void PictureInterface::saveTileList(QList<QImage> tl, QString destination){
    QImage output = createOutputImage(tl);
    qDebug()<<"saving to"<<destination;
    output.save(destination,outputFormat);
}

QImage PictureInterface::createOutputImage(QList<QImage> tl){
    int pictures = tl.length();

    int picturesPerLine = defaultPicturesPerLine;
    if(picturesPerLine == 0)
        picturesPerLine = qFloor(qSqrt(pictures)+0.5);

    int numberOfLines = qCeil( ((qreal)pictures) / ((qreal) picturesPerLine) );

    int tileSize = tl.first().width();
    int outputSizeX = (tileSize+spacing)*picturesPerLine-spacing;//every tile gets spacing pixels bigger exept the
    int outputSizeY = (tileSize+spacing)*numberOfLines-spacing;  //ones in the last row and in the last column

    qDebug()<<"creating a picture with"<<pictures<<"tiles and a size of"<<outputSizeX<<"x"<<outputSizeY;

    QImage output(outputSizeX, outputSizeY, QImage::Format_ARGB32);
    output.fill(Qt::transparent);

    QPainter painter(&output);
    QRect source(0, 0, tileSize,tileSize);
    int row = 0;
    int column = 0;

    for(int i = 0; i < tl.size(); ++i){
        QImage image = tl.at(i);
        QRect target(column*(tileSize+spacing),row*(tileSize+spacing), tileSize,tileSize);
        painter.drawImage(target, image, source);

        column++;
        if(column >= picturesPerLine){
            row++;
            column = 0;
        }
    }
    return output;
}

QList<QImage> PictureInterface::loadTileList(QString source, int tileSize){
    qDebug()<<"loading tileset";
    QImage inputImage;
    inputImage.load(source);
    return parseInputImage(inputImage, tileSize);
}

QList<QImage> PictureInterface::parseInputImage(QImage input, int tileSize){
    QList<QImage> output;
    for(int y = 0; y < input.height(); y += (tileSize+spacing)){
        for(int x = 0; x < input.width(); x += (tileSize+spacing)){
            QImage image = input.copy(x,y,tileSize,tileSize);
            output.append(image);
        }
    }
    return output;
}
