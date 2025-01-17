#include "set_time_screen.h"
#include "ui_set_time_screen.h"
#include "mainwindow.h"
#include "settings.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QtSql>

extern QString UserID;


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

/*
============================================================================================================================
End of Open Lock 2
============================================================================================================================
Log Event
============================================================================================================================
*/

void set_time_screen::LogEvent(QString EventID)
{

    QSqlDatabase db = QSqlDatabase::addDatabase(DATABASEDRIVER);
    db.setHostName(DATABASEURL);
    db.setDatabaseName(DATABASENAME);
    db.setUserName(DATABASEUSER);
    db.setPassword(DATABASEPASSWORD);
    db.open();

    QString event_date = QDate::currentDate().toString("yyyyMMdd");
    QString event_time = QTime::currentTime().toString();
    QSqlQuery query4;
    query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + EventID + "')");
/*
============================================================================================================
End of Logging
============================================================================================================
*/
    db.close();
    return;
}
