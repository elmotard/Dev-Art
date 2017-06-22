#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static const unsigned int nbBouton = 4;
    QPushButton** TPBouton;
    QVBoxLayout* mainlayout;
    QHBoxLayout* layout1;
    QHBoxLayout* layout2;

};

#endif // MAINWINDOW_H
