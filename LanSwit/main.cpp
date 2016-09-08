#include "widget.h"
#include <QApplication>
#include <QTextCodec>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*加这句可以防止中文出现乱码*/
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    Widget w;
    w.show();

    return a.exec();
}
