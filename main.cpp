#include "fkwindow.h"
#include <QtWidgets>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FkWindow w;
    w.show();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return a.exec();
}
