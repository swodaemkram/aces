#include "networksettings.h"
#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include "set_time_screen.h"
#include <QtSql>
#include <QStyle>
#include <QDesktopWidget>

extern QString UserID;

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
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
Lets Load a cool Background
==============================================================================================================
*/
              imageObject = new QImage();               //  _
              imageObject->load(SETTINGSBACKGROUND);    //   |
              image = QPixmap::fromImage(*imageObject); //   |
              scene = new QGraphicsScene(this);         //   |
              scene->addPixmap(image);                  //   |_______All this to display a picture
              scene->setSceneRect(image.rect());        //   |               WOW !
              ui->graphicsView->setScene(scene);        //   |
              imageObject = new QImage();
              //ui->frame_4->hide();
/*
==============================================================================================================
Background is loaded
==============================================================================================================
*/
}

settings::~settings()
{
    delete ui;
}

void settings::on_pushButton_clicked()
{
    close();
}

void settings::on_pushButton_2_clicked()
{
/*
=============================================================================================================
Set Time and Date
=============================================================================================================
*/
//------------------------------------------------------Log Event--------------------------------------------------------
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
         ui->label_2->setText("Connected to database again....");
         QString event_date = QDate::currentDate().toString("yyyyMMdd");
         QString event_time = QTime::currentTime().toString();
         QSqlQuery query4;
         query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "37" + "')");
//-----------------------------------------------------------Log Event-------------------------------------------------------
         set_time_screen set_time_screen;
         set_time_screen.setModal(true);
         set_time_screen.exec();
}
/*
=================================================================================================================
End Of Set time
=================================================================================================================
Setup Network
=================================================================================================================
*/
void settings::on_pushButton_3_clicked()
{
    NetworkSettings NetworkSettings;
    NetworkSettings.setModal(true);
    NetworkSettings.exec();
}
/*
================================================================================================================
End of Setup Network
================================================================================================================
*/
