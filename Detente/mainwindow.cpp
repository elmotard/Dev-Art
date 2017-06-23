#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	//Initialisation
	listnomboutton << "Mer/Océan" << "Forêt" << "Montagne" << "Millieu Urbain" << "Général";
    mainlayout = new QVBoxLayout;
    layout1 = new QHBoxLayout;
    layout2 = new QHBoxLayout;
    TPBouton = new QPushButton*[nbBouton];
	player = new QMediaPlayer;
    son = new QProgressBar;
    son->setRange(0, 100);
	player->setVolume(50); //Mise du volume à 50%
	son->setValue(player->volume()); //Mise de la barre à 50%

	//Placement et création des bouttons dans les layouts
    for(unsigned int i=0; i<=nbBouton; ++i)
    {
		count[i] = 0;
		TPBouton[i]= new QPushButton(listnomboutton[i]);
        if(i <= 1)
            layout1->addWidget(TPBouton[i]);
        if(i>1  && i<=3)
            layout2->addWidget(TPBouton[i]);
    }
	count[4]=0;

	//Connecter tous les boutons aux fonctions
	connect(TPBouton[0], &QPushButton::clicked, this, &MainWindow::mer);
	connect(TPBouton[1], &QPushButton::clicked, this, &MainWindow::foret);
	connect(TPBouton[2], &QPushButton::clicked, this, &MainWindow::montagne);
	connect(TPBouton[3], &QPushButton::clicked, this, &MainWindow::urbain);
	connect(TPBouton[4], &QPushButton::clicked, this, &MainWindow::general);

	connect(TPBouton[0], SIGNAL(clicked(bool)), this, SLOT(update()));
	connect(TPBouton[1], SIGNAL(clicked(bool)), this, SLOT(update()));
	connect(TPBouton[2], SIGNAL(clicked(bool)), this, SLOT(update()));
	connect(TPBouton[3], SIGNAL(clicked(bool)), this, SLOT(update()));
	connect(TPBouton[4], SIGNAL(clicked(bool)), this, SLOT(update()));

	//Mise des layouts dans un layout principal
    mainlayout->addLayout(layout1);
    mainlayout->addLayout(layout2);
    mainlayout->addWidget(TPBouton[nbBouton]);

	//Ajout du titre
	setWindowTitle(tr("Détente"));

    connect(player, SIGNAL(volumeChanged(int)), this, SLOT(vol(int)));

	//Ajout de la progressBar dans la fenêtre
    mainlayout->addWidget(son);

	//Mise du layout principale dans la fenetre
    setLayout(mainlayout);

    unsigned int heure = QTime::currentTime().hour();
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

void MainWindow::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);
	QPainter painter(this);
	if (count[0] == 0)
	{
		qDebug() << "Hi";
		painter.opacity();
	}
	else if (count[0] == 1)
	{
		pixmap.load(":/images/Images/fond_ecran_mer.jpg");
		painter.drawPixmap(0,0,pixmap);
	}
	if (count[1] == 0)
	{
		painter.opacity();
	}
	else if (count[1] == 1)
	{
		qDebug() << "Bonjour";
		pixmap.load(":/images/Images/fond_ecran_foret.jpg");
		painter.drawPixmap(0,0,pixmap);
	}
	if (count[2] == 0)
	{
		painter.opacity();
	}
	else if (count[2] == 1)
	{
		pixmap.load(":/images/Images/fond_ecran_montagne.jpg");
		painter.drawPixmap(0,0,pixmap);

	}
	if (count[3] == 0)
	{
		painter.opacity();
	}
	else if (count[3] == 1)
	{
		pixmap.load(":/images/Images/fond_ecran_urbain.jpg");
		painter.drawPixmap(0,0,pixmap);

	}
	else if (count[4] == 0)
	{
		painter.opacity();
	}
	else if (count[4] == 1)
	{
		pixmap.load(":/images/Images/fond_ecran_general.jpg");
		painter.drawPixmap(0,0,pixmap);

	}
}

void MainWindow::mer()
{

	if (count[0] == 0)
	{
		player->setMedia(QUrl("qrc:/audio/Sons/Mer/release_mer.mp3"));
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
		qDebug() << "Hello";
		player->setMedia(QUrl("qrc:/audio/Sons/Foret/release_foret.mp3"));
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
	if (count[2] == 0)
	{
		player->setMedia(QUrl("qrc:/audio/Sons/Montagne/release_montagne.mp3"));
		player->play();
		count[2] = 1;
	}
	else
	{
		player->pause();
		count[2] = 0;
	}
}

void MainWindow::urbain()
{
	if (count[3] == 0)
	{
		player->setMedia(QUrl("qrc:/audio/Sons/Urbain/release_urbain.mp3"));
		player->play();
		count[3] = 1;
	}
	else
	{
		player->pause();
		count[3] = 0;
	}
}

void MainWindow::general()
{
	if (count[4] == 0)
	{
		player->setMedia(QUrl("qrc:/audio/Sons/Général/release_général.mp3"));
		player->play();
		count[4] = 1;
	}
	else
	{
		player->pause();
		count[4] = 0;
	}
}

void MainWindow::vol(int value)
{
    son->setValue(value);
}
