#include "lock_screen.h"
#include "ui_lock_screen.h"
#include "mainwindow.h"
#include "user_screen.h"
#include "access_group.h"
#include "manage_access_item.h"
#include "settings.h"
#include <QtSerialPort/QtSerialPort>
#include <unistd.h> //For sleep function
#include <QStyle>
#include <QDesktopWidget>
//#include <QtWidgets>
#include <QtSql>


extern QString UserID;

/*
===================================================================================================================
Definitions
===================================================================================================================
*/

#define CODE_LENGTH  10
#define KEY "7578649673"

/*
=================================================================================================================
End of Definitions
=================================================================================================================
*/

QString unlock_time="10"; // lock open time in seconds
QString sensor_status = "";

char ochr;

char master[10][10] ={
        {1,2,3,4,5,6,7,8,9,0},
        {3,4,5,6,7,8,9,0,1,2},
        {6,7,8,9,0,1,2,3,4,5},
        {9,0,1,2,3,4,5,6,7,8},
        {4,5,6,7,8,9,0,1,2,3},
        {7,8,9,0,1,2,3,4,5,6},
        {8,9,0,1,2,3,4,5,6,7},
        {0,1,2,3,4,5,6,7,8,9},
        {2,3,4,5,6,7,8,9,0,1},
        {5,6,7,8,9,0,1,2,3,4}
    };
QTimer *timer;

QString FirstNameFromDatabase;
QString LastNameFromDatabase;
//----------------------------------------System Settings--------------------------------------------------

QString door1_name;
QString door2_name;
QString door3_name;
QString door4_name;
QString door5_name;
QString door6_name;

int door1_open_delay = 0;
int door2_open_delay = 0;
int door3_open_delay = 0;
int door4_open_delay = 0;
int door5_open_delay = 0;
int door6_open_delay = 0;

int door1_open_alarm = 0;
int door2_open_alarm = 0;
int door3_open_alarm = 0;
int door4_open_alarm = 0;
int door5_open_alarm = 0;
int door6_open_alarm = 0;

int door1_enabled = 0;
int door2_enabled = 0;
int door3_enabled = 0;
int door4_enabled = 0;
int door5_enabled = 0;
int door6_enabled = 0;

//---------------------------------------End of System Settings-------------------------------------------
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
  imageObject->load(BACKGROUNDIMAGE);       //   |
  image = QPixmap::fromImage(*imageObject); //   |
  scene = new QGraphicsScene(this);         //   |
  scene->addPixmap(image);                  //   |_______All this to display a picture
  scene->setSceneRect(image.rect());        //   |               WOW !
  ui->graphicsView->setScene(scene);        //   |
  imageObject = new QImage();

  imageObject = new QImage();               //  _
  imageObject->load("./icons/black-open-door.png");       //   |
  image = QPixmap::fromImage(*imageObject); //   |
  scene = new QGraphicsScene(this);         //   |
  scene->addPixmap(image);                  //   |_______All this to display a picture
  scene->setSceneRect(image.rect());        //   |               WOW !
  ui->graphicsView_2->setScene(scene);      //   |
  imageObject = new QImage();

  imageObject = new QImage();               //  _
  imageObject->load("./icons/black-open-door.png");       //   |
  image = QPixmap::fromImage(*imageObject); //   |
  scene = new QGraphicsScene(this);         //   |
  scene->addPixmap(image);                  //   |_______All this to display a picture
  scene->setSceneRect(image.rect());        //   |               WOW !
  ui->graphicsView_3->setScene(scene);      //   |
  imageObject = new QImage();

  imageObject = new QImage();               //  _
  imageObject->load("./icons/black-open-door.png");       //   |
  image = QPixmap::fromImage(*imageObject); //   |
  scene = new QGraphicsScene(this);         //   |
  scene->addPixmap(image);                  //   |_______All this to display a picture
  scene->setSceneRect(image.rect());        //   |               WOW !
  ui->graphicsView_4->setScene(scene);      //   |
  imageObject = new QImage();

  imageObject = new QImage();               //  _
  imageObject->load("./icons/black-open-door.png");       //   |
  image = QPixmap::fromImage(*imageObject); //   |
  scene = new QGraphicsScene(this);         //   |
  scene->addPixmap(image);                  //   |_______All this to display a picture
  scene->setSceneRect(image.rect());        //   |               WOW !
  ui->graphicsView_5->setScene(scene);      //   |
  imageObject = new QImage();

  imageObject = new QImage();               //  _
  imageObject->load("./icons/black-open-door.png");       //   |
  image = QPixmap::fromImage(*imageObject); //   |
  scene = new QGraphicsScene(this);         //   |
  scene->addPixmap(image);                  //   |_______All this to display a picture
  scene->setSceneRect(image.rect());        //   |               WOW !
  ui->graphicsView_6->setScene(scene);      //   |
  imageObject = new QImage();

  imageObject = new QImage();               //  _
  imageObject->load("./icons/black-open-door.png");       //   |
  image = QPixmap::fromImage(*imageObject); //   |
  scene = new QGraphicsScene(this);         //   |
  scene->addPixmap(image);                  //   |_______All this to display a picture
  scene->setSceneRect(image.rect());        //   |               WOW !
  ui->graphicsView_7->setScene(scene);      //   |
  imageObject = new QImage();

  ui->graphicsView_2->hide();
  ui->graphicsView_3->hide();
  ui->graphicsView_4->hide();
  ui->graphicsView_5->hide();
  ui->graphicsView_6->hide();
  ui->graphicsView_7->hide();
/*
==============================================================================================================
Lets Load System Configurations
==============================================================================================================
*/
  QSqlDatabase db = QSqlDatabase::addDatabase(DATABASEDRIVER);
  db.setHostName(DATABASEURL);
  db.setDatabaseName(DATABASENAME);
  db.setUserName(DATABASEUSER);
  db.setPassword(DATABASEPASSWORD);
  QSqlQuery query0;

  if (!db.open())
  {
       ui->label_2->setText("Unable to connect to database !!!");
      return;
  }
   ui->label_2->setText("Connected to database....");
   query0.exec("SELECT * FROM door_setup");
//--------------------------------------------Door1 Setup----------------------------------------------------
   query0.next();
   door1_name = query0.value(1).toString();
   door1_open_delay = query0.value(2).toInt();
   door1_open_alarm = query0.value(3).toInt();
   door1_enabled = query0.value(4).toInt();
   ui->pushButton_6->setText(door1_name);
//------------------------------------------End of Door1 Setup----------------------------------------------
//---------------------------------------------Door2 Setup--------------------------------------------------
   query0.next();
   door2_name = query0.value(1).toString();
   door2_open_delay = query0.value(2).toInt();
   door2_open_alarm = query0.value(3).toInt();
   door2_enabled = query0.value(4).toInt();
   ui->pushButton_7->setText(door2_name);
//------------------------------------------End of Door2 Setup----------------------------------------------
//---------------------------------------------Door3 Setup--------------------------------------------------
   query0.next();
   door3_name = query0.value(1).toString();
   door3_open_delay = query0.value(2).toInt();
   door3_open_alarm = query0.value(3).toInt();
   door3_enabled = query0.value(4).toInt();
   ui->pushButton_8->setText(door3_name);
//------------------------------------------End of Door3 Setup----------------------------------------------
//---------------------------------------------Door4 Setup--------------------------------------------------
   query0.next();
   door4_name = query0.value(1).toString();
   door4_open_delay = query0.value(2).toInt();
   door4_open_alarm = query0.value(3).toInt();
   door4_enabled = query0.value(4).toInt();
   ui->pushButton_9->setText(door4_name);
//------------------------------------------End of Door4 Setup----------------------------------------------
//---------------------------------------------Door5 Setup--------------------------------------------------
   query0.next();
   door5_name = query0.value(1).toString();
   door5_open_delay = query0.value(2).toInt();
   door5_open_alarm = query0.value(3).toInt();
   door5_enabled = query0.value(4).toInt();
   ui->pushButton_10->setText(door5_name);
//------------------------------------------End of Door5 Setup----------------------------------------------
//---------------------------------------------Door6 Setup--------------------------------------------------
   query0.next();
   door6_name = query0.value(1).toString();
   door6_open_delay = query0.value(2).toInt();
   door6_open_alarm = query0.value(3).toInt();
   door6_enabled = query0.value(4).toInt();
   ui->pushButton_11->setText(door6_name);
//------------------------------------------End of Door6 Setup----------------------------------------------

/*
==============================================================================================================
Lets open some comm ports if enablede
==============================================================================================================
*/
//---------------------------------------------------Door 1--------------------------------------------------
  if (door1_enabled == 1)
  {
  lock1_serial = new QSerialPort(this);
  lock1_serial->setPortName("/dev/ttyACM0");
  lock1_serial->setBaudRate(QSerialPort::Baud115200);
  lock1_serial->setDataBits(QSerialPort::Data8);
  lock1_serial->setParity(QSerialPort::NoParity);
  lock1_serial->setStopBits(QSerialPort::OneStop);
  lock1_serial->setFlowControl(QSerialPort::NoFlowControl);
  lock1_serial->open(QIODevice::ReadWrite);
  }
//---------------------------------------------------Door 2--------------------------------------------------
  if (door2_enabled == 1)
  {
  lock2_serial = new QSerialPort(this);
  lock2_serial->setPortName("/dev/ttyACM1");
  lock2_serial->setBaudRate(QSerialPort::Baud115200);
  lock2_serial->setDataBits(QSerialPort::Data8);
  lock2_serial->setParity(QSerialPort::NoParity);
  lock2_serial->setStopBits(QSerialPort::OneStop);
  lock2_serial->setFlowControl(QSerialPort::NoFlowControl);
  lock2_serial->open(QIODevice::ReadWrite);
  }
//----------------------------------------------------Door 3------------------------------------------------
  if (door3_enabled == 1)
  {
  lock3_serial = new QSerialPort(this);
  lock3_serial->setPortName("/dev/ttyACM2");
  lock3_serial->setBaudRate(QSerialPort::Baud115200);
  lock3_serial->setDataBits(QSerialPort::Data8);
  lock3_serial->setParity(QSerialPort::NoParity);
  lock3_serial->setStopBits(QSerialPort::OneStop);
  lock3_serial->setFlowControl(QSerialPort::NoFlowControl);
  lock3_serial->open(QIODevice::ReadWrite);
  }
//----------------------------------------------------Door 4------------------------------------------------
  if (door4_enabled == 1)
  {
  lock4_serial = new QSerialPort(this);
  lock4_serial->setPortName("/dev/ttyACM3");
  lock4_serial->setBaudRate(QSerialPort::Baud115200);
  lock4_serial->setDataBits(QSerialPort::Data8);
  lock4_serial->setParity(QSerialPort::NoParity);
  lock4_serial->setStopBits(QSerialPort::OneStop);
  lock4_serial->setFlowControl(QSerialPort::NoFlowControl);
  lock4_serial->open(QIODevice::ReadWrite);
  }
//-----------------------------------------------------Door 5-----------------------------------------------
  if (door5_enabled == 1)
  {
  lock5_serial = new QSerialPort(this);
  lock5_serial->setPortName("/dev/ttyACM4");
  lock5_serial->setBaudRate(QSerialPort::Baud115200);
  lock5_serial->setDataBits(QSerialPort::Data8);
  lock5_serial->setParity(QSerialPort::NoParity);
  lock5_serial->setStopBits(QSerialPort::OneStop);
  lock5_serial->setFlowControl(QSerialPort::NoFlowControl);
  lock5_serial->open(QIODevice::ReadWrite);
  }
//------------------------------------------------------Door 6----------------------------------------------
  if (door6_enabled == 1)
  {
  lock6_serial = new QSerialPort(this);
  lock6_serial->setPortName("/dev/ttyACM4");
  lock6_serial->setBaudRate(QSerialPort::Baud115200);
  lock6_serial->setDataBits(QSerialPort::Data8);
  lock6_serial->setParity(QSerialPort::NoParity);
  lock6_serial->setStopBits(QSerialPort::OneStop);
  lock6_serial->setFlowControl(QSerialPort::NoFlowControl);
  lock6_serial->open(QIODevice::ReadWrite);
  }

/*
=============================================================================================================
Locks Comm Ports are Now Open
=============================================================================================================
Lets check lock door status
=============================================================================================================
*/
  timer = new QTimer;
  connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));
  timer->start(500);
/*
==============================================================================================================
Lets Figure out who logqed in and what they can do
==============================================================================================================
*/
  //QSqlDatabase db = QSqlDatabase::addDatabase(DATABASEDRIVER);
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
/*
============================================================================================================
Ok so we conneced to the database, now run querry
============================================================================================================
*/
   QSqlQuery query;
   query.exec("SELECT * FROM user WHERE iduser = " + UserID + " OR User_id = " + UserID);//<--We need user id or alt-id to validate
   query.next();
//-------------------------------------------Log Event------------------------------------------------------
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
    query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code, event_detail) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "2" + "','" + FirstNameFromDatabase + " " + LastNameFromDatabase + "')");

//--------------------------------------------Log Event----------------------------------------------------
/*
============================================================================================================
End of Logging the login
============================================================================================================
Lets Pull up the permissions for this user at the current time
============================================================================================================
*/
//-----------------------------------Whats the current time------------------------------------------------
    QString time = QTime::currentTime().toString();
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
    query1.exec("SELECT * FROM user WHERE iduser = " + UserID + " OR User_id = " + UserID);//<--We need user id or alt-id to validate
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
     //Close Database

}

lock_screen::~lock_screen()
{
    delete ui;
}

/*
=========================================================================================================================
Exit Button
==========================================================================================================================
*/
void lock_screen::on_pushButton_clicked()
{
//-----------------------------------------------Log Event----------------------------------------------------------------
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
     query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "3" + "')");
     db.close();
//---------------------------------------------------Log Event-------------------------------------------------------------
//---------------------------------------------------Close Window----------------------------------------------------------
     close_Lock1_SerialPort();//Lets Close All Comm ports like a good boy
     close();
}
/*
=========================================================================================================================
End of Exit Button
==========================================================================================================================
Display User Screen
==========================================================================================================================
*/
void lock_screen::on_pushButton_2_clicked()
{

//--------------------------------------------Log Event-------------------------------------------------------------
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
      query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code, event_detail) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "21" + "','" + FirstNameFromDatabase + " " + LastNameFromDatabase + "')");
    db.close();
//------------------------------------------------Log Event----------------------------------------------------------
    timer->stop();
    user_screen user_screen;
    user_screen.setModal(true);
    user_screen.exec();
    timer->start(500);
}
/*
=========================================================================================================================
End of Display User Screen
=========================================================================================================================
Display Access Item Screen
=========================================================================================================================
*/
void lock_screen::on_pushButton_5_clicked()
{
//--------------------------------------------Log Event-------------------------------------------------------------

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
      query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code, event_detail) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "18" + "','" + FirstNameFromDatabase + " " + LastNameFromDatabase + "')");
      db.close();
//------------------------------------------------Log Event----------------------------------------------------------
    timer->stop();
    manage_access_item manage_access_item;
    manage_access_item.setModal(true);
    manage_access_item.exec();
    timer->start(500);
}
/*
=========================================================================================================================
End of Dissplay Access Item Screen
=========================================================================================================================
Display Acces Group Screen
=========================================================================================================================
*/
void lock_screen::on_pushButton_4_clicked()
{
//--------------------------------------------Log Event-------------------------------------------------------------
     LogEvent("17");
//------------------------------------------------Log Event----------------------------------------------------------
    timer->stop();
    Access_Group Access_Group;
    Access_Group.setModal(true);
    Access_Group.exec();
    timer->start(500);
}
/*
========================================================================================================================
End of access group screen
========================================================================================================================
*/


/*
================================================================================================================

================================================================================================================
Close Lock Com ports
================================================================================================================
*/
void lock_screen::close_Lock1_SerialPort()
{
    if (door1_enabled == 1 && lock1_serial->isOpen()) lock1_serial->close();//-|
    if (door2_enabled == 1 && lock2_serial->isOpen()) lock2_serial->close();//-|
    if (door3_enabled == 1 && lock3_serial->isOpen()) lock3_serial->close();//-|
    if (door4_enabled == 1 && lock4_serial->isOpen()) lock4_serial->close();//-|-----Close all enabled comm ports
    if (door5_enabled == 1 && lock5_serial->isOpen()) lock5_serial->close();//-|             Like a good boy
    if (door6_enabled == 1 && lock6_serial->isOpen()) lock6_serial->close();//-|
    return;
}
/*
================================================================================================================
end of Close Lock Com port
================================================================================================================

================================================================================================================
*/

/*
================================================================================================================

================================================================================================================
 Read Data from Lock1 Com port
================================================================================================================
*/
QByteArray lock_screen::readData_lock1()
{
   QByteArray data = lock1_serial->readAll();
   qDebug() << data;
   return(data);
}
/*
================================================================================================================
end of Read Data from Lock1 Com port
================================================================================================================
Open Lock1
================================================================================================================
*/
void lock_screen::on_pushButton_6_clicked()
{
     timer->stop();
     QByteArray data;

     lock1_serial->write("k;");
     //data = lock1_serial->readAll();

     while(lock1_serial->bytesAvailable()>0||lock1_serial->waitForReadyRead(10))
     {
        data = lock1_serial->readAll();
     }

     data = data.mid(3,10);
     //ui->label->setText("Challenge Code = " + data);
     std::string challenge = data.toStdString();
     const char* newchallenge = challenge.c_str();

     std::string response = genkey(newchallenge);
     printf("Response Key = %s\n",response.c_str());

     QString newResponse = QString::fromStdString(response);
     QString TheResponse = "E 10 " + newResponse + ";";
     std::string TheStringResponse = TheResponse.toStdString();
     qDebug() << TheResponse;
     QByteArray NewResponse = QByteArray::fromStdString(TheStringResponse);
     lock1_serial->write(NewResponse);

     while(lock1_serial->bytesAvailable()>0||lock1_serial->waitForReadyRead(10))
     {
        data = lock1_serial->readAll();
     }

     //ui->label->setText(data);

//--------------------------------------------Log Event-------------------------------------------------------------
     LogEvent("4");
     timer->start(500);
}
/*
===============================================================================================================
End of open Lock1
===============================================================================================================
Timer to get lock and door status
==============================================================================================================
*/
void lock_screen::MyTimerSlot()

{
//---------------------------------------------Lock 1------------------------------------------------------------
     if (door1_enabled == 1)
    {
      lock1_serial->write("r;");
      QByteArray data = lock1_serial->readAll();
      QString DoorOpenStatus = data.mid(5,1);
      if(QString::compare(DoorOpenStatus,"1") == 0) ui->graphicsView_2->show();
      else ui->graphicsView_2->hide();
    }
//------------------------------------------End of Lock 1-------------------------------------------------------
//---------------------------------------------Lock 2-----------------------------------------------------------
    if (door2_enabled == 1)
    {
      lock2_serial->write("r;");
      QByteArray data2 = lock2_serial->readAll();
      QString DoorOpenStatus2 = data2.mid(5,1);
      if(QString::compare(DoorOpenStatus2,"1") == 0) ui->graphicsView_3->show();
      else ui->graphicsView_3->hide();
    }
//------------------------------------------End of Lock 2--------------------------------------------------------
//---------------------------------------------Lock 3-----------------------------------------------------------
    if (door3_enabled == 1)
    {
      lock3_serial->write("r;");
      QByteArray data3 = lock3_serial->readAll();
      QString DoorOpenStatus3 = data3.mid(5,1);
      if(QString::compare(DoorOpenStatus3,"1") == 0) ui->graphicsView_4->show();
      else ui->graphicsView_4->hide();
    }
//------------------------------------------End of Lock 3--------------------------------------------------------
//---------------------------------------------Lock 4-----------------------------------------------------------
    if (door4_enabled == 1)
    {
      lock4_serial->write("r;");
      QByteArray data4 = lock4_serial->readAll();
      QString DoorOpenStatus4 = data4.mid(5,1);
      if(QString::compare(DoorOpenStatus4,"1") == 0) ui->graphicsView_5->show();
      else ui->graphicsView_5->hide();
    }
//------------------------------------------End of Lock 4--------------------------------------------------------
//---------------------------------------------Lock 5-----------------------------------------------------------
    if (door5_enabled == 1)
    {
      lock5_serial->write("r;");
      QByteArray data5 = lock5_serial->readAll();
      QString DoorOpenStatus5 = data5.mid(5,1);
      if(QString::compare(DoorOpenStatus5,"1") == 0) ui->graphicsView_6->show();
      else ui->graphicsView_6->hide();
    }
//------------------------------------------End of Lock 5--------------------------------------------------------
//---------------------------------------------Lock 6-----------------------------------------------------------
    if (door6_enabled == 1)
    {
      lock6_serial->write("r;");
      QByteArray data6 = lock6_serial->readAll();
      QString DoorOpenStatus6 = data6.mid(5,1);
      if(QString::compare(DoorOpenStatus6,"1") == 0) ui->graphicsView_7->show();
      else ui->graphicsView_7->hide();
    }
//------------------------------------------End of Lock 6--------------------------------------------------------
    return;
}
/*
==================================================================================================================
End of door status timer
==================================================================================================================
Lock Decryption Key Gen
==================================================================================================================
*/

std::string lock_screen::genkey(const char* newchallenge)
{

            qDebug() << newchallenge;
            unsigned char r = 0;

            //char master[] = KEY;    // "7578649673";

            char master[] = "7578649673";
            char ctmp[10];                              // = new byte[10];
            char code[10];
            //bzero(ctmp,10);
            //bzero(code,10);

            memset(ctmp,0,10);
            memset(code,0,10);

            char salt[12];
            bzero(salt,12);

            for(int i = 0; i < 10; i++)
                salt[i] = newchallenge[i] - 0x30;

            for(int i = 0; i < 10; i++)
                master[i] = master[i] - 0x30;

            for(int i = 0; i < 10; i++)
                ctmp[i] = (char) ((salt[i] + master[i]) % 10);

            for(int i = 0; i < 5; i++)
            {
                char *x = rot(ctmp, r);
                for (int i=0; i < 10; i++)
                    ctmp[i] = x[i];
                r = ctmp[9];
            }

            for(int i = 0; i < 10; i++)
            {
                code[i] = (unsigned char) ('0' + ctmp[i]);
            }

            std::string str;
            for (int i=0; i < 10; i++)
                str += code[i];

            return str;

}

char* lock_screen::rot(char b[], char seed)
{
    char a[10];
        for (int i=0; i < 10; i++)
        a[i]=b[i];
        b[0] = master[seed][a[0]];

        for(int i = 1; i < 10; i++) {
        b[i] = master[b[i-1]][a[i]];
    }
    return &b[0];
}
/*
=================================================================================================================
End of Lock Decryption
=================================================================================================================
Open Log Screen
=================================================================================================================
*/
void lock_screen::on_pushButton_12_clicked()
{

//--------------------------------------------------Log Event------------------------------------------------------
    LogEvent("20");
//--------------------------------------------------Log Event-------------------------------------------------------
}


/*
==========================================================================================================================
End of Open log Screen
=========================================================================================================================
Open System Screen
==========================================================================================================================
*/
void lock_screen::on_pushButton_3_clicked()
{
    timer->stop();
//------------------------------------------------------Log Event--------------------------------------------------------
    LogEvent("19");
//------------------------------------------------------Log Event--------------------------------------------------------
     settings settings;
     settings.setModal(true);
     settings.exec();
     timer->start(500);
}
/*
============================================================================================================================
End of Open System Screen
============================================================================================================================
Open Lock 2
=============================================================================================================================
*/

void lock_screen::on_pushButton_7_clicked()
{
    timer->stop();
    QByteArray data;

    lock2_serial->write("k;");
    //data = lock2_serial->readAll();

    while(lock2_serial->bytesAvailable()>0||lock2_serial->waitForReadyRead(10))
    {
       data = lock2_serial->readAll();
    }

    data = data.mid(3,10);
    //ui->label->setText("Challenge Code = " + data);
    std::string challenge = data.toStdString();
    const char* newchallenge = challenge.c_str();

    std::string response = genkey(newchallenge);
    printf("Response Key = %s\n",response.c_str());

    QString newResponse = QString::fromStdString(response);
    QString TheResponse = "E 10 " + newResponse + ";";
    std::string TheStringResponse = TheResponse.toStdString();
    qDebug() << TheResponse;
    QByteArray NewResponse = QByteArray::fromStdString(TheStringResponse);
    lock2_serial->write(NewResponse);

    while(lock2_serial->bytesAvailable()>0||lock2_serial->waitForReadyRead(10))
    {
       data = lock2_serial->readAll();
    }

//--------------------------------------------Log Event-------------------------------------------------------------
    LogEvent("5");
//------------------------------------------------Log Event----------------------------------------------------------
    timer->start(500);
}
/*
============================================================================================================================
End of Open Lock 2
============================================================================================================================
Log Event
============================================================================================================================
*/

void lock_screen::LogEvent(QString EventID)
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
