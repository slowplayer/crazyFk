#include <QtCore>
#include <stdlib.h>
#include "fkpiece.h"

void FkPiece::setRandomShape()
{
    setShape(FkShape(qrand()%7+1));
}
void FkPiece::setShape(FkShape shape)
{
    static const int coordsTable[8][4][2]={
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },
        { { 0, -1 },  { 1, 0 },   { -1, 0 },  { -1, 1 } },
        { { 0, -1 },  { -1, 0 },   { 1, 0 },   { 1, 1 } },
        { { 0, -2 },  { 0, -1 },   { 0, 1 },   { 0, 2 } },
        { { -1, 0 },  { 0, -1 },   { 1, 0 },   { 0, 1 } },
        { { -1, -1 },   { 1, 1 },   { -1, 1 },   { 1, -1 } },
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { -1, 1 } },
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 1, 1 } }
    };
    for(int i=0;i<4;i++)
        for(int j=0;j<2;j++)
            coords[i][j]=coordsTable[shape][i][j];
    pieceShape=shape;
}
int FkPiece::minX()const
{
    int temp=coords[0][0];
    for(int i=1;i<4;i++)
        temp=qMin(temp,coords[i][0]);
    return temp;
}
int FkPiece::maxX()const
{
    int temp=coords[0][0];
    for(int i=1;i<4;i++)
        temp=qMax(temp,coords[i][0]);
    return temp;
}
int FkPiece::minY()const
{
    int temp=coords[0][1];
    for(int i=1;i<4;i++)
        temp=qMin(temp,coords[i][1]);
    return temp;
}
int FkPiece::maxY()const
{
    int temp=coords[0][1];
    for(int i=1;i<4;i++)
        temp=qMax(temp,coords[i][1]);
    return temp;
}
FkPiece FkPiece::rotatedLeft()const
{
    if(pieceShape==SqureShape)
        return *this;
    FkPiece result;
    result.pieceShape=pieceShape;
    for(int i=0;i<4;i++)
    {
        result.setX(i,y(i));
        result.setY(i,-x(i));
    }
    return result;
}
FkPiece FkPiece::rotatedRight()const
{
    if(pieceShape==SqureShape)
        return *this;
    FkPiece result;
    result.pieceShape=pieceShape;
    for(int i=0;i<4;i++)
    {
        result.setX(i,-y(i));
        result.setY(i,x(i));
    }
    return result;
}
