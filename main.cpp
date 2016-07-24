#include <QApplication>
#include <QtWidgets>
#include "login.h"

#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    Login w;
    w.show();
    
    return a.exec();
}
