#ifndef TIMEWINDOW_HPP
#define TIMEWINDOW_HPP

#include <QtWidgets>

class TimeWindow : public QWidget
{
		Q_OBJECT
		QVBoxLayout *leftLayout;
		QVBoxLayout *rightLayout;
		QHBoxLayout *mainLayout;

		QRadioButton *radioBoutonMer;
		QRadioButton *radioBoutonForet;
		QRadioButton *radioBoutonMontagne;
		QRadioButton *radioBoutonUrbain;
		QRadioButton *radioBoutonGeneral;

		QCheckBox *active;

		QPushButton *heureUp;
		QPushButton *heureDown;

		QLabel *labelheure;
		QLCDNumber *lcd;
		QTimer *m_timer;

	public:
		explicit TimeWindow(QWidget *parent = nullptr);
		~TimeWindow();

	signals:

	public slots:
		void timeup();
		void timedown();
	private slots:
		void tick();
};

#endif // TIMEWINDOW_HPP
