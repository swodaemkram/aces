#include "networksettings.h"
#include "ui_networksettings.h"
#include "mainwindow.h"

#include <QStyle>
#include <QDesktopWidget>




NetworkSettings::NetworkSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetworkSettings)
{
    ui->setupUi(this);
/*
===============================================================================================================
Center Window on Screen and remove minimize, maximize and exit buttons
===============================================================================================================
*/
       //this->setWindowFlags(Qt::Dialog); //Removes Minimize and Maximize Buttons
         this->setWindowFlags(Qt::FramelessWindowHint);//Gets Rid of all Window Buttons Minimize,Maxinize and Exit
         this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));//Centers This window on any screen

/*
==============================================================================================================
Setup Done
==============================================================================================================
*/




}

NetworkSettings::~NetworkSettings()
{
    delete ui;
}

void NetworkSettings::on_pushButton_clicked()
{
    close();
}
