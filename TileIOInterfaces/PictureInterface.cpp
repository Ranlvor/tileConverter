#include "PictureInterface.h"
#include <qmath.h>
#include <QColor>
#include <QPainter>
PictureInterface::PictureInterface()
{
    outputFormat = "png";
}

void PictureInterface::setOutputFormat(char* newOutputFormat){
    outputFormat = newOutputFormat;
}
void PictureInterface::setSpacing (int newSpacing){
    spacing = newSpacing;
}

void PictureInterface::saveTileList(QList<QImage> tl, QString destination){
    int pictures = tl.length();
    int picturesPerLine = qFloor(qSqrt(pictures)+0.5);
    int numberOfLines = qCeil( ((qreal)pictures) / ((qreal) picturesPerLine) );

    int tileSize = tl.first().width();
    int outputSizeX = (tileSize+spacing)*picturesPerLine-spacing;//every tile gets spacing pixels bigger exept the
    int outputSizeY = (tileSize+spacing)*numberOfLines-spacing;  //ones in the last row and in the last column

    qDebug()<<"saving"<<pictures<<"tiles to"<<destination<<"with a size of"<<outputSizeX<<"x"<<outputSizeY;

    QImage output(outputSizeX, outputSizeY, QImage::Format_ARGB32);
    output.fill(Qt::black);

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

    output.save(destination,outputFormat);
}
