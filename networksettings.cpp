#include "networksettings.h"
#include "ui_networksettings.h"
#include "mainwindow.h"

#include <QStyle>
#include <QDesktopWidget>
#include <QtSql>

extern QString UserID;


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

/*
============================================================================================================================
Log Event
============================================================================================================================
*/

void NetworkSettings::LogEvent(QString EventID)
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

    return;
}
