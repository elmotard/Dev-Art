#include "mainwindow.h"
#include <QFrame>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    mainlayout = new QVBoxLayout;
    layout1 = new QHBoxLayout;
    layout2 = new QHBoxLayout;
    TPBouton = new QPushButton*[nbBouton];
    for(unsigned int i=0; i<=nbBouton; ++i)
    {
        TPBouton[i]= new QPushButton("Je suis un bouton");
        if(i <= 1)
            layout1->addWidget(TPBouton[i]);
        if(i>1  && i<=3)
            layout2->addWidget(TPBouton[i]);
    }
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
