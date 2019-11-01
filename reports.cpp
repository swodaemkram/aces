#include "reports.h"
#include "ui_reports.h"
#include "mainwindow.h"
#include <QtSql>
#include <QStyle>
#include <QDesktopWidget>
#include <QPainter>
#include <QApplication>
#include <QPrinter>
#include <QPrintDialog>



reports::reports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reports)
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

}

reports::~reports()
{
    delete ui;
}

void reports::on_pushButton_clicked()
{
    close();
}
/*
===========================================================================================================
Run A Daily Log
===========================================================================================================
*/
void reports::on_pushButton_2_clicked()
{
    QDate dedate = QDate::currentDate();
    QString cd = dedate.toString("MM-dd-yyyy");


    QSqlDatabase db = QSqlDatabase::addDatabase(DATABASEDRIVER);
    db.setHostName(DATABASEURL);
    db.setDatabaseName(DATABASENAME);
    db.setUserName(DATABASEUSER);
    db.setPassword(DATABASEPASSWORD);

    if (!db.open())
    {
         ui->label_2->setText("Unable to connect to database !!!");
        return;
    }
     ui->label_2->setText("Connected to database....");

     QSqlQuery query;
     query.exec("SELECT * FROM event_log WERE event_date = '" + cd + "'");
     query.first();






}
/*
==========================================================================================================
End of Daily Log
==========================================================================================================
Print Current Report
==========================================================================================================
*/
void reports::on_pushButton_5_clicked()
{
    QString TestString = "Mark is cool";
    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("print");
    QImage img(REPORTHEADER);

    QPainter painter;
    painter.begin(&printer);
    painter.drawImage(QPoint(0,0),img);
    painter.drawText(50, 50, 250, 250, Qt::AlignLeft|Qt::AlignTop, TestString);
    painter.end();
}
/*
=======================================================================================================
End of Print current Report
=======================================================================================================
*/
