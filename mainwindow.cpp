#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QList>
#include <QtMath>

#include <iostream>
using namespace std;

int wartosc_losowa (int zakres_od, int zakres_do){

    int x=0;

    x=QRandomGenerator::global()->bounded(zakres_od,zakres_do);
    //cout<<"Losowa liczba to: "<<x<<endl;

    return x;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1_clicked()
{

    QList<double> lista_bledow;
    double sum_Pi=0;
    double akumulator=0;

    for (int i=0; i<this->ui->spinBox_2->value(); i++){

        double licznik=0;
        double oszacowana_wartosc_pi=0;

        for (int j=0; j<this->ui->spinBox_1->value(); j++){

            //cout<<"Przebieg i: "<<i<<endl;

            int x = wartosc_losowa(-(this->ui->spinBox_3->value()),this->ui->spinBox_3->value());
            int y = wartosc_losowa(-(this->ui->spinBox_3->value()),this->ui->spinBox_3->value());
            int z = this->ui->spinBox_3->value()*this->ui->spinBox_3->value();


            if (x*x+y*y<=z){
                licznik++;


            }

        }


        oszacowana_wartosc_pi=licznik/this->ui->spinBox_1->value()*4;
        lista_bledow.append(qFabs(oszacowana_wartosc_pi - 3.14159));
        sum_Pi = sum_Pi + oszacowana_wartosc_pi;
        cout<<"Biezace Pi to: "<<oszacowana_wartosc_pi<<"\t"<<oszacowana_wartosc_pi - 3.14159<< " od Pi"<<endl;


    }



    for(int i = 0; i<lista_bledow.size();i++){

        akumulator = akumulator + lista_bledow[i];

    }


    this->ui->lcdNumber_1->display(sum_Pi/this->ui->spinBox_2->value());
    this->ui->lcdNumber_2->display(akumulator/this->ui->spinBox_2->value());

    cout<<"Srednia oszacowana wartosc Pi to : "<<sum_Pi/this->ui->spinBox_2->value()<<endl;
    cout<<"Przecietny blad to: "<<akumulator/this->ui->spinBox_2->value()<<endl;

}

