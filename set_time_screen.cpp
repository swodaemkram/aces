#include "set_time_screen.h"
#include "ui_set_time_screen.h"
#include "mainwindow.h"
#include "settings.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QDateTime>
#include <QDate>
#include <QTime>

set_time_screen::set_time_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::set_time_screen)
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
qDebug() << QDateTime::currentDateTime();
ui->dateTimeEdit->setDateTime( QDateTime::currentDateTime() );

}

set_time_screen::~set_time_screen()
{
    delete ui;
}

void set_time_screen::on_pushButton_clicked()
{
    QString SetDateTime = ui->dateTimeEdit->dateTime().toString("yyyy-M-dd +HH:mm");
    qDebug() << SetDateTime;
    QProcess::execute("date -s " + SetDateTime);
    close();
}
