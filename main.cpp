#include "startscene.h"
#include "mymainwindow.h"
#include <QApplication>
#include "selectscene.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartScene w;
    w.show();

//    SelectScene w;
//    w.show();

    return a.exec();
}
