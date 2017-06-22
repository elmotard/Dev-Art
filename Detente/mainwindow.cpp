#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
	listnomboutton << "Mer/Océan" << "Forêt" << "Montagne" << "Millieu Urbain" << "Général";
    mainlayout = new QVBoxLayout;
    layout1 = new QHBoxLayout;
    layout2 = new QHBoxLayout;
    TPBouton = new QPushButton*[nbBouton];
	QMediaPlayer *son;
	son=new QMediaPlayer();

	son->setMedia(QMediaContent(QUrl::fromLocalFile("1.mp3")));
	son->setVolume(50);
	son->play();

    for(unsigned int i=0; i<=nbBouton; ++i)
    {
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

}

MainWindow::~MainWindow()
{

}

void MainWindow::mer()
{

}

void MainWindow::foret()
{

}

void MainWindow::montagne()
{

}

void MainWindow::urbain()
{

}

void MainWindow::general()
{

}
