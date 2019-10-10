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
  ui->graphicsView_2->setScene(scene);        //   |
  imageObject = new QImage();


  ui->graphicsView_2->hide();
  ui->graphicsView_3->hide();
  ui->graphicsView_4->hide();
  ui->graphicsView_5->hide();
  ui->graphicsView_6->hide();
  ui->graphicsView_7->hide();

/*
==============================================================================================================
Lets open some comm ports
==============================================================================================================
*/

  lock1_serial = new QSerialPort(this);
  open_Lock1_SerialPort();
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
/*
============================================================================================================
Ok so we conneced to the database, now run querry
============================================================================================================
*/
   QSqlQuery query;
   query.exec("SELECT * FROM user WHERE iduser = " + UserID);
   query.next();
   FirstNameFromDatabase = query.value(1).toString();
   LastNameFromDatabase = query.value(2).toString();
   ui->label_2->setText("User Logged in is " + FirstNameFromDatabase + " " + LastNameFromDatabase);
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
     query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code, event_detail) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "3" + "','" + FirstNameFromDatabase + " " + LastNameFromDatabase + "')");
//---------------------------------------------------Log Event-------------------------------------------------------------
//---------------------------------------------------Close Window----------------------------------------------------------
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
//------------------------------------------------Log Event----------------------------------------------------------

    user_screen user_screen;
    user_screen.setModal(true);
    user_screen.exec();
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
//------------------------------------------------Log Event----------------------------------------------------------
    manage_access_item manage_access_item;
    manage_access_item.setModal(true);
    manage_access_item.exec();
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
      query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code, event_detail) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "17" + "','" + FirstNameFromDatabase + " " + LastNameFromDatabase + "')");
//------------------------------------------------Log Event----------------------------------------------------------
    Access_Group Access_Group;
    Access_Group.setModal(true);
    Access_Group.exec();
}
/*
========================================================================================================================
End of access group screen
========================================================================================================================
*/

void lock_screen::open_Lock1_SerialPort()
{
    lock1_serial->setPortName("/dev/ttyACM0");
    lock1_serial->setBaudRate(QSerialPort::Baud115200);
    lock1_serial->setDataBits(QSerialPort::Data8);
    lock1_serial->setParity(QSerialPort::NoParity);
    lock1_serial->setStopBits(QSerialPort::OneStop);
    lock1_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (lock1_serial->open(QIODevice::ReadWrite)) {

        //ui->label->setText("Connected");//DEBUG MARK MEADOWS

    } else {

        //ui->label->setText("Connection Error");//DEBUG MARK MEADOWS
    }
return;
}

/*
================================================================================================================
Close Lock1 Com port
================================================================================================================
*/
void lock_screen::close_Lock1_SerialPort()
{
    if (lock1_serial->isOpen()) lock1_serial->close();
}
/*
================================================================================================================
end of Close Lock1 Com port
================================================================================================================
Write Data to Lock1
================================================================================================================
*/
void lock_screen::writeData_lock1(const QByteArray &data)
{
    lock1_serial->write(data);
}
/*
================================================================================================================
End of Write Data to Lock1
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
      query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code, event_detail) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "4" + "','" + FirstNameFromDatabase + " " + LastNameFromDatabase + "')");

//------------------------------------------------Log Event----------------------------------------------------------
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
    lock1_serial->write("r;");
    QByteArray data = lock1_serial->readAll();
    QString DoorOpenStatus = data.mid(5,1);
    if(QString::compare(DoorOpenStatus,"1") == 0) ui->graphicsView_2->show();
    else ui->graphicsView_2->hide();

//------------------------------------------End of Lock 1-----------------------------------------------------
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
     query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code, event_detail) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "20" + "','" + FirstNameFromDatabase + " " + LastNameFromDatabase + "')");
}
//------------------------------------------------------Log Event-------------------------------------------------------

/*
==========================================================================================================================
End of Open log Screen
=========================================================================================================================
Open System Screen
==========================================================================================================================
*/
void lock_screen::on_pushButton_3_clicked()
{


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
     query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code, event_detail) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "19" + "','" + FirstNameFromDatabase + " " + LastNameFromDatabase + "')");
//-----------------------------------------------------------Log Event-------------------------------------------------------
     settings settings;
     settings.setModal(true);
     settings.exec();
}
/*
============================================================================================================================
End of Open System Screen
============================================================================================================================
*/
