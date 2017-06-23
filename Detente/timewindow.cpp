#include "timewindow.hpp"
#include "mainwindow.h"

TimeWindow::TimeWindow(QWidget *parent) : QWidget(parent)
{
	MainWindow w;

	leftLayout = new QVBoxLayout;
	rightLayout = new QVBoxLayout;
	mainLayout = new QHBoxLayout;

	radioBoutonMer = new QRadioButton("Mer");
	radioBoutonForet = new QRadioButton("Foret");
	radioBoutonMontagne = new QRadioButton("Montagne");
	radioBoutonUrbain = new QRadioButton("Urbain");
	radioBoutonGeneral = new QRadioButton("General");

	active = new QCheckBox("Active");

	lcd = new QLCDNumber(5);
	lcd->setSegmentStyle(QLCDNumber::Flat);
	lcd->display("12:00");
	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this, &TimeWindow::tick);

	heureUp = new QPushButton;
	heureDown = new QPushButton;

	QPixmap pixmapMontant(":/images/Images/fleche_montante.png");
	QIcon ButtonIconMontant(pixmapMontant);
	heureUp->setIcon(ButtonIconMontant);
	heureUp->setIconSize(pixmapMontant.rect().size());

	QPixmap pixmapDescendant(":/images/Images/fleche_descendente.png");
	QIcon ButtonIconDescendant(pixmapDescendant);
	heureDown->setIcon(ButtonIconDescendant);
	heureDown->setIconSize(pixmapDescendant.rect().size());

	connect(heureUp, &QPushButton::clicked, this, &TimeWindow::timeup);
	connect(heureDown, &QPushButton::clicked, this, &TimeWindow::timedown);

	leftLayout->addWidget(radioBoutonMer);
	leftLayout->addWidget(radioBoutonForet);
	leftLayout->addWidget(radioBoutonMontagne);
	leftLayout->addWidget(radioBoutonUrbain);
	leftLayout->addWidget(radioBoutonGeneral);
	leftLayout->addSpacing(20);
	leftLayout->addWidget(active);

	rightLayout->addWidget(heureUp);
	//rightLayout->addWidget(labelheure);
	rightLayout->addWidget(lcd);
	rightLayout->addWidget(heureDown);

	mainLayout->addLayout(leftLayout);
	mainLayout->addSpacing(20);
	mainLayout->addLayout(rightLayout);

	setLayout(mainLayout);
}

TimeWindow::~TimeWindow()
{

}

void TimeWindow::tick()
{
	MainWindow w;
	if (radioBoutonMer->isChecked())
		lcd->display(QString::number(w.getTimeMer(0)) + ":" + QString::number(w.getTimeMer(1)));
	if(radioBoutonForet->isChecked())
		lcd->display(QString::number(w.getTimeForet(0)) + ":" + QString::number(w.getTimeForet(1)));
	if(radioBoutonMontagne->isChecked())
		lcd->display(QString::number(w.getTimeMontagne(0)) + ":" + QString::number(w.getTimeMontagne(1)));
	if(radioBoutonUrbain->isChecked())
		lcd->display(QString::number(w.getTimeUrbain(0)) + ":" + QString::number(w.getTimeUrbain(1)));
	if(radioBoutonGeneral->isChecked())
		lcd->display(QString::number(w.getTimeGeneral(0)) + ":" + QString::number(w.getTimeGeneral(1)));
	else
		lcd->display(QString::number(w.getTime(0)) + ":" + QString::number(w.getTime(1)));
}

void TimeWindow::timeup()
{

	MainWindow w;
	if (radioBoutonMer->isChecked())
	{
		w.setTimeMer(w.getTimeMer(0), w.getTimeMer(1) + 5, "+");
		qDebug() << w.getTimeMer(0) << " " << w.getTimeMer(1);
	}
	if(radioBoutonForet->isChecked())
		w.setTimeForet(w.getTimeForet(0), w.getTimeForet(1) + 5, "+");
	if(radioBoutonMontagne->isChecked())
		w.setTimeMontagne(w.getTimeMontagne(0), w.getTimeMontagne(1) + 5, "+");
	if(radioBoutonUrbain->isChecked())
		w.setTimeUrbain(w.getTimeUrbain(0), w.getTimeUrbain(1) + 5, "+");
	if(radioBoutonGeneral->isChecked())
		w.setTimeGeneral(w.getTimeGeneral(0), w.getTimeGeneral(1) + 5, "+");
}

void TimeWindow::timedown()
{
	MainWindow w;
	if (radioBoutonMer->isChecked())
		w.setTimeMer(w.getTimeMer(0), w.getTimeMer(1) - 5, "-");
	if(radioBoutonForet->isChecked())
		w.setTimeForet(w.getTimeForet(0), w.getTimeForet(1) - 5, "-");
	if(radioBoutonMontagne->isChecked())
		w.setTimeMontagne(w.getTimeMontagne(0), w.getTimeMontagne(1) - 5, "-");
	if(radioBoutonUrbain->isChecked())
		w.setTimeUrbain(w.getTimeUrbain(0), w.getTimeUrbain(1) - 5, "-");
	if(radioBoutonGeneral->isChecked())
		w.setTimeGeneral(w.getTimeGeneral(0), w.getTimeGeneral(1) - 5, "-");
}
