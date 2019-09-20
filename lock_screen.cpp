#include "lock_screen.h"
#include "ui_lock_screen.h"
#include "mainwindow.h"
#include "user_screen.h"
#include <QStyle>
#include <QDesktopWidget>
//#include <QtWidgets>
#include <QtSql>

extern QString UserID;

lock_screen::lock_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lock_screen)
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
  imageObject->load("./icons/2.jpg");       //   |
  image = QPixmap::fromImage(*imageObject); //   |
  scene = new QGraphicsScene(this);         //   |
  scene->addPixmap(image);                  //   |_______All this to display a picture
  scene->setSceneRect(image.rect());        //   |               WOW !
  ui->graphicsView->setScene(scene);        //   |
  imageObject = new QImage();
/*
==============================================================================================================
Lets Figure out who logqed in and what they can do
==============================================================================================================
*/
  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName("localhost");
  db.setDatabaseName("aces");
  db.setUserName("root");
  db.setPassword("b0whunter");

  if (!db.open())
  {
       ui->label_2->setText("Unable to connect to database !!!");
      return;
  }
   ui->label_2->setText("Connected to database....");
/*
============================================================================================================
Ok so we conneced to the database, now run querry
============================================================================================================
*/
   QSqlQuery query;
   query.exec("SELECT * FROM user WHERE iduser = " + UserID);
   query.next();
   QString FirstNameFromDatabase = query.value(1).toString();
   QString LastNameFromDatabase = query.value(2).toString();
   ui->label_2->setText("User Logged in is " + FirstNameFromDatabase + " " + LastNameFromDatabase);
/*
============================================================================================================
Lets Pull up the permissions for this user at the current time
============================================================================================================
*/
//-----------------------------------Whats the current time------------------------------------------------
    QString time = QTime::currentTime().toString();
    ui->label_2->setText("Logged in as " + FirstNameFromDatabase + " " + LastNameFromDatabase + " " + time );
//------------------------------------Now we have the current time as Variable time-----------------------
//----------------------------------We need to now figure out what day of the week it is------------------
    QString theDayName;
    int theDay;
    theDay = QDate::currentDate().dayOfWeek();
    theDayName = QDate::longDayName(theDay);

    qDebug() <<  theDay;
    qDebug() <<  theDayName;
//---------------------------Now we know what day it is lets figure out what we have access to-------------

    QSqlQuery query1;
    query1.exec("SELECT * FROM user WHERE iduser = " + UserID);
    query1.next();
    QString permission_group = query1.value(4).toString();
    qDebug() << permission_group;
    QSqlQuery query2;
    query2.exec("SELECT * FROM permission_group WHERE permission_group_name = '"+ permission_group + "'" );
    query2.next();
    int pgcount = 1;
    QSqlQuery query3;

    while(pgcount < 10)
     {
        QString permission_group = query2.value(pgcount).toString();

        qDebug() << permission_group;
        query3.exec("SELECT * FROM permissions WHERE permission_window_name = '" + permission_group +
                "' AND start_time <= '" + time +"' AND end_time >= '" + time +"' AND " + theDayName + " = '1'" );
        query3.next();
        int idpermission_group = query3.value(0).toInt();
        if (idpermission_group != 0) break;
        pgcount++;
    }

//------------------------------------------Set up screen for applicable permissions--------------------------
    int can_mod_users = query3.value(11).toInt();
    if(!can_mod_users)ui->pushButton_2->hide();
    int can_mod_system = query3.value(12).toInt();
    if(!can_mod_system)ui->pushButton_3->hide();
    int can_access_door1 = query3.value(13).toInt();
    if(!can_access_door1)ui->pushButton_6->hide();
    int can_access_door2 = query3.value(14).toInt();
    if(!can_access_door2)ui->pushButton_7->hide();
    int can_access_door3 = query3.value(15).toInt();
    if(!can_access_door3)ui->pushButton_8->hide();
    int can_access_door4 = query3.value(16).toInt();
    if(!can_access_door4)ui->pushButton_9->hide();
    int can_access_door5 = query3.value(17).toInt();
    if(!can_access_door5)ui->pushButton_10->hide();
    int can_access_door6 = query3.value(18).toInt();
    if(!can_access_door6)ui->pushButton_11->hide();
    int access_item_button_enabled = query3.value(19).toInt();
    if(!access_item_button_enabled)ui->pushButton_5->hide();
    int access_group_button_enabled = query3.value(20).toInt();
    if(!access_group_button_enabled)ui->pushButton_4->hide();
    int Log_button_enabled = query3.value(21).toInt();
    if(!Log_button_enabled)ui->pushButton_12->hide();
//--------------------------------------------End of Screen Setup---------------------------------------------

    ui->label_2->setText("using permission group " + permission_group );
    db.close(); //Close Database

}

lock_screen::~lock_screen()
{
    delete ui;
}

void lock_screen::on_pushButton_clicked()
{
    close();
}


void lock_screen::on_pushButton_2_clicked()
{
    user_screen user_screen;
    user_screen.setModal(true);
    user_screen.exec();
}
