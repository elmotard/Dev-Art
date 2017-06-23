#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include "QtMultimedia/qmediaplayer.h"
#include <QtWidgets>
#include <QProgressBar>
#include <fstream>

using namespace std;

class MainWindow : public QWidget
{
    Q_OBJECT
	static const unsigned int nbBouton = 4;
	QStringList listnomboutton;
	QPushButton** TPBouton;
	QVBoxLayout* mainlayout;
	QHBoxLayout* layout1;
	QHBoxLayout* layout2;
	QMediaPlayer* player;
	int count[nbBouton+1];
	QPixmap pixmap;
	void paintEvent(QPaintEvent *event);
    QProgressBar* son;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent* e);

public slots:
	void mer();
	void foret();
	void montagne();
	void urbain();
	void general();
    void vol(int value);

};

#endif // MAINWINDOW_H
