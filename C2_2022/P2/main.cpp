#include "reactiontime.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReactionTime w;
    w.show();
    return a.exec();
}
