#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QMediaPlayer>
#include <QtWidgets>

class MainWindow : public QWidget
{
    Q_OBJECT
	static const unsigned int nbBouton = 4;
	QStringList listnomboutton;
	QPushButton** TPBouton;
	QVBoxLayout* mainlayout;
	QHBoxLayout* layout1;
	QHBoxLayout* layout2;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
	void mer();
	void foret();
	void montagne();
	void urbain();
	void general();

};

#endif // MAINWINDOW_H
