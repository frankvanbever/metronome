#include "metronome.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Metronome w;
    w.show();

    return a.exec();
}
