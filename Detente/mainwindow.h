#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include "QtMultimedia/qmediaplayer.h"
#include <QtWidgets>
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
	int count[nbBouton];

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

};

#endif // MAINWINDOW_H
