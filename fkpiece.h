#ifndef FKPIECE_H
#define FKPIECE_H

enum FkShape{NoShape,ZShape,SShape,LineShape,TShape,SqureShape,
            LShape,MirroredLShape};

class FkPiece
{
public:
    FkPiece(){setShape(NoShape);}

    void setRandomShape();
    void setShape(FkShape shape);

    FkShape shape()const{return pieceShape;}
    int x(int index)const
    {
        return coords[index][0];
    }
    int y(int index)const
    {
        return coords[index][1];
    }
    int minX()const;
    int maxX()const;
    int minY()const;
    int maxY()const;
    FkPiece rotatedLeft()const;
    FkPiece rotatedRight()const;
private:
    void setX(int index,int x)
    {
        coords[index][0]=x;
    }
    void setY(int index,int y)
    {
        coords[index][1]=y;
    }
    FkShape pieceShape;
    int coords[4][2];
};

#endif // FKPIECE_H
