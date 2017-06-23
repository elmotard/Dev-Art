#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include "QtMultimedia/qmediaplayer.h"
#include <QtWidgets>
#include <QProgressBar>

using namespace std;

#include "timewindow.hpp"

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
	QMenu *menuedition;
	uint time[2] = {0,0};
	uint timeMer[2] = {0,0};
	uint timeForet[2] = {0,0};
	uint timeMontagne[2] = {0,0};
	uint timeUrbain[2] = {0,0};
	uint timeGeneral[2] = {0,0};
	TimeWindow *timew;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent* e);

	inline uint getTime(uint index) { return time[index];}
	inline uint getTimeMer(uint index) { return timeMer[index];}
	inline uint getTimeForet(uint index) { return timeForet[index];}
	inline uint getTimeMontagne(uint index) { return timeMontagne[index];}
	inline uint getTimeUrbain(uint index) { return timeUrbain[index];}
	inline uint getTimeGeneral(uint index) { return timeGeneral[index];}

	void setTimeMer (uint heure, uint minute, string signe);
	void setTimeForet (uint heure, uint minute, string signe);
	void setTimeMontagne (uint heure, uint minute, string signe);
	void setTimeUrbain (uint heure, uint minute, string signe);
	void setTimeGeneral (uint heure, uint minute, string signe);

public slots:
	void mer();
	void foret();
	void montagne();
	void urbain();
	void general();
	void vol(int value);
	void editionHeure();

};

#endif // MAINWINDOW_H
