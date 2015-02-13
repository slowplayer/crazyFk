#ifndef FKWINDOW_H
#define FKWINDOW_H

#include <QWidget>
#include <QFrame>

class QLCDNumber;
class QLabel;
class QPushButton;

class FkBoard;

class FkWindow : public QWidget
{
    Q_OBJECT

public:
    FkWindow(QWidget *parent=0);
private:
    QLabel *createLabel(const QString &text);

    FkBoard *board;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
};

#endif // FKWINDOW_H
