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
    QString cd = dedate.toString("yyyy-MM-dd");


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
     query.exec("SELECT * FROM event_log WHERE event_date = '" + cd + "'");
     query.next();

     int lastrow = 1;
//-----------------------------Lets setup the printer------------------------------------------------------------------

     QString TestString = "Mark is cool";
     QPrinter printer;
     QPrintDialog *dialog = new QPrintDialog(&printer);
     dialog->setWindowTitle("print");
     QImage img(REPORTHEADER);
     QPainter painter;
     painter.begin(&printer);
     painter.drawImage(QPoint(0,0),img);
     QFont font=painter.font();
     font.setPointSize ( 20 ); /// BIG
     painter.setFont(font);
     int lineNumber = 500;
     painter.drawText(250,lineNumber,"Daily Activity Log");
     lineNumber = lineNumber + 40;
     painter.drawText(1, lineNumber,"==========================================================================================");
     lineNumber = lineNumber + 40;
//--------------------------------Lets Rip through the data and populate the text box--------------------------------------
     while(lastrow == 1)
     {
         QString TheLineOfText = query.value(0).toString() + " " + query.value(1).toString() + " " + query.value(2).toString()
         + " " + query.value(3).toString() + " " + query.value(4).toString() + "\n";
         ui->textEdit->append(TheLineOfText);
         painter.drawText(50, lineNumber,  TheLineOfText);
         lineNumber = lineNumber + 40;
         lastrow = query.next();
     }
//------------------------------------------Done Ripping-------------------------------------------------------------------
painter.end();
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
