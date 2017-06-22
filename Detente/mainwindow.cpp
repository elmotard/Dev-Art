#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	QString CurrentDir = QDir::currentPath();
	qDebug() << CurrentDir;
	listnomboutton << "Mer/Océan" << "Forêt" << "Montagne" << "Millieu Urbain" << "Général";
    mainlayout = new QVBoxLayout;
    layout1 = new QHBoxLayout;
    layout2 = new QHBoxLayout;
    TPBouton = new QPushButton*[nbBouton];
	player = new QMediaPlayer;

	player->setVolume(50);

    for(unsigned int i=0; i<=nbBouton; ++i)
    {
		count[0] = 0;
		TPBouton[i]= new QPushButton(listnomboutton[i]);
        if(i <= 1)
            layout1->addWidget(TPBouton[i]);
        if(i>1  && i<=3)
            layout2->addWidget(TPBouton[i]);
    }

	connect(TPBouton[0], &QPushButton::clicked, this, &MainWindow::mer);
	connect(TPBouton[1], &QPushButton::clicked, this, &MainWindow::foret);
	connect(TPBouton[2], &QPushButton::clicked, this, &MainWindow::montagne);
	connect(TPBouton[3], &QPushButton::clicked, this, &MainWindow::urbain);
	connect(TPBouton[4], &QPushButton::clicked, this, &MainWindow::general);

    mainlayout->addLayout(layout1);
    mainlayout->addLayout(layout2);
    mainlayout->addWidget(TPBouton[nbBouton]);

    setLayout(mainlayout);



    //const QIcon icone=QIcon("C:/Users/Flack/Downloads/f7c4d42657fbb19cde75d0df01f0b20d.jpg");
    //TPBouton[3]->setIcon(icone);

    unsigned int heure = QTime::currentTime().hour();
    qDebug() << heure;

    //urbain 7h, foret 10h, mer 14h, montagne 22h
}

MainWindow::~MainWindow()
{

}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
    if(e->key()==Qt::Key_Plus)
        player->setVolume(player->volume()+1);
    if(e->key()==Qt::Key_Minus)
        player->setVolume(player->volume()-1);
}

void MainWindow::mer()
{

	if (count[0] == 0)
	{
		player->setMedia(QUrl("qrc:/audio/release_mer.mp3"));
		qDebug() << "current media: " << player->currentMedia().canonicalUrl().toString();
		player->play();
		count[0] = 1;
	}
	else
	{
		player->pause();
		count[0] = 0;
	}

}

void MainWindow::foret()
{
	if (count[1] == 0)
	{
		player->setMedia(QUrl("release_mer.mp3"));
		player->play();
		count[1] = 1;
	}
	else
	{
		player->pause();
		count[1] = 0;
	}
}

void MainWindow::montagne()
{
	if (count[1] == 0)
	{
		player->setMedia(QUrl::fromLocalFile("release_mer3.mp3"));
		player->play();
		count[1] = 1;
	}
	else
	{
		player->pause();
		count[1] = 0;
	}
}

void MainWindow::urbain()
{
	if (count[1] == 0)
	{
		player->setMedia(QUrl::fromLocalFile("/Sons/Mer/release_mer.mp3"));
		player->play();
		count[1] = 1;
	}
	else
	{
		player->pause();
		count[1] = 0;
	}
}

void MainWindow::general()
{
	if (count[1] == 0)
	{
		player->setMedia(QUrl::fromLocalFile("release_mer.mp3"));
		player->play();
		count[1] = 1;
	}
	else
	{
		player->pause();
		count[1] = 0;
	}
}
