#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	a.setStyle(QStyleFactory::create("Fusion"));
	MainWindow w;
	w.setMinimumSize(500,300);
	w.show();
    return a.exec();
}
