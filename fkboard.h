#ifndef FKBOARD_H
#define FKBOARD_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>

#include "fkpiece.h"
class QLabel;

class FkBoard:public QFrame
{
    Q_OBJECT
public:
    FkBoard(QWidget *parent=0);

    void setNextPieceLabel(QLabel *label);
    QSize sizeHint() const;
    QSize minimumSizeHint()const;
public slots:
    void start();
    void pause();
signals:
    void scoreChanged(int score);
    void levelChanged(int level);
    void linesRemoveChanged(int numLines);
protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void timerEvent(QTimerEvent *e);
private:
    enum{BoardWidth=10,BoardHeight=22};

    FkShape &shapeAt(int x,int y)
    {
        return board[(y*BoardWidth)+x];
    }
    int timeoutTime()
    {
        return 1000/(1+level);
    }
    int squareWidth()
    {
        return contentsRect().width()/BoardWidth;
    }
    int squareHeight()
    {
        return contentsRect().height()/BoardHeight;
    }
    void clearBoard();
    void dropDown();
    void oneLineDown();
    void pieceDropped(int dropHeight);
    void removeFullLines();
    void newPiece();
    void showNextPiece();
    bool tryMove(const FkPiece &newPiece,int newX,int newY);
    void drawSquare(QPainter &painter,int x,int y,FkShape shape);

    QBasicTimer timer;
    QPointer<QLabel> nextPieceLabel;
    bool isStarted;
    bool isPaused;
    bool isWaitingAfterLine;
    FkPiece curPiece;
    FkPiece nextPiece;
    int curX;
    int curY;
    int numLinesRemoved;
    int numPieceDropped;
    int score;
    int level;
    FkShape board[BoardWidth*BoardHeight];

};

#endif // FKBOARD_H
