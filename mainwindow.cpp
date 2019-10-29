#include "aboutscreen.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lock_screen.h"
#include "pin_change_screen.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QtSql>
#include <unistd.h>
#include <QNetworkInterface>
#include"override_screen.h"

QString UserID;
QString Pin;
QString Validate;
QString HideText;
QString Alt_ID;
QString DataFromVIM;

//----------------------------------------System Config-------------------------------------------------------
int days_before_pinchange = 0;
int number_of_pin_digits = 0;
int force_pin_change = 0;
int door_alarm_delay = 0;

int door1_enabledmm = 0;
int door2_enabledmm = 0;
int door3_enabledmm = 0;
int door4_enabledmm = 0;
int door5_enabledmm = 0;
int door6_enabledmm = 0;
//-----------------------------------------End of System Config-----------------------------------------------

//-----------------------------------------Flags-------------------------------------------------------------
int lock1_serial_open = 0;
int lock2_serial_open = 0;
int vim_serial_open = 0;
int Alarm_Logged = 0;
int Alarm_Logged2 = 0;
int is_vim_enabled = 0;
//-----------------------------------------Flags-------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
//----------------------------------------------------------------------------------------------------------------
  imageObject = new QImage();               //  _
  imageObject->load(REDBACKGROUNDIMAGE);       //   |
  image = QPixmap::fromImage(*imageObject); //   |
  scene = new QGraphicsScene(this);         //   |
  scene->addPixmap(image);                  //   |_______All this to display a picture
  scene->setSceneRect(image.rect());        //   |               WOW !
  ui->graphicsView_2->setScene(scene);        //   |
  imageObject = new QImage();

 /*
===============================================================================================================
Update Clock Timer and Door Status Timer
===============================================================================================================
*/
//-----------------------------------------------Clock Timer----------------------------------------------------
QTimer *timer;
timer = new QTimer;
connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));
timer->start(500);
//-----------------------------------------------End of clock Timer-----------------------------------------------
//-----------------------------------------------Door Status timer------------------------------------------------
//QTimer *DoorMonitorTimer;
DoorMonitorTimer = new QTimer;
connect(DoorMonitorTimer, SIGNAL(timeout()), this, SLOT(DoorMonitorTimerSlot()));
DoorMonitorTimer->start(500);
//-------------------------------------------End of Door Status Timer----------------------------------------------
/*
====================================================================================================================
End of Update Clock Timer and Door Status Timer
====================================================================================================================
Lets connect to the database
====================================================================================================================
*/

QSqlDatabase db = QSqlDatabase::addDatabase(DATABASEDRIVER);
db.setHostName(DATABASEURL);
db.setDatabaseName(DATABASENAME);
db.setUserName(DATABASEUSER);
db.setPassword(DATABASEPASSWORD);

if (!db.open())
{
     ui->label_4->setText("Unable to connect to database !!!");
    return;
}
 ui->label_4->setText("Connected to database....");
db.close();
 /*
====================================================================================================
   End of connecting to Database
====================================================================================================
   Load System Config
====================================================================================================
*/
db.setHostName(DATABASEURL);
db.setDatabaseName(DATABASENAME);
db.setUserName(DATABASEUSER);
db.setPassword(DATABASEPASSWORD);

if (!db.open())
{
     ui->label_4->setText("Unable to connect to database !!!");
    return;
}
 ui->label_4->setText("Connected to database again....");

 QSqlQuery query;
 query.exec("SELECT * FROM system_config" );
 query.next();
 days_before_pinchange = query.value(2).toInt();
 number_of_pin_digits = query.value(3).toInt();
 force_pin_change = query.value(4).toInt();
 door_alarm_delay = query.value(5).toInt();
//-----------------------------------------------Get door Setup--------------------------------
 query.exec("SELECT * FROM door_setup");
 query.next();
 door1_enabledmm = query.value(4).toInt();
 query.next();
 door2_enabledmm = query.value(4).toInt();
 query.next();
 door3_enabledmm = query.value(4).toInt();
 query.next();
 door4_enabledmm = query.value(4).toInt();
 query.next();
 door5_enabledmm = query.value(4).toInt();
 query.next();
 door6_enabledmm = query.value(4).toInt();
//--------------------------------------------End of Door Setup---------------------------------------
db.close();
//--------------------------------------------Log System Boot-----------------------------------------
LogEvent("1");
/*
=====================================================How We play Audio============================================
*/
//player = new QMediaPlayer;
//player->setMedia(QUrl::fromLocalFile("/home/mark/qt_projects/build-aces-Desktop-Debug/01.mp3"));
//player->setVolume(90);
//player->play();
/*
=======================================================How We Play Audio==========================================
*/
return;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    lock1_serial->close();
    lock2_serial->close();
    vim_serial->close();
    exit(0);
}

/*
====================================================================================================
Clock Display
====================================================================================================
*/
void MainWindow::MyTimerSlot()
{
    QTime time = QTime::currentTime();
    QString ct = time.toString("hh:mm:ss.zzz ");
    QDate dedate = QDate::currentDate();
    QString cd = dedate.toString("MM-dd-yyyy");
    QString DateAndTime = cd + " " + ct;
    ui->lcdNumber->display(DateAndTime);
}
/*
===================================================================================================
End of Clock Display
===================================================================================================
Door Status Monitor Code
====================================================================================================
*/
void MainWindow::DoorMonitorTimerSlot()
{

//------------------------------------------Door 1--------------------------------------------------------------------------
    lock1_comm();
//----------------------------------------End of Door 1---------------------------------------------------------------------
//-------------------------------------------Door 2-------------------------------------------------------------------------
    lock2_comm();
//----------------------------------------End of Door 2---------------------------------------------------------------------
//----------------------------------------Check VIM for Data----------------------------------------------------------------
    vim_comm();
//-----------------------------------------END of VIM Code------------------------------------------------------------------
    return;
}
/*
============================================================================================================================
End of door monitoring code
============================================================================================================================
Keypad Code
============================================================================================================================
*/
void MainWindow::on_pushButton_2_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == number_of_pin_digits)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "1";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "1";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "1";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() == number_of_pin_digits) ValidateUser();

}

void MainWindow::on_pushButton_3_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == number_of_pin_digits)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "2";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "2";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "2";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() == number_of_pin_digits) ValidateUser();

}

void MainWindow::on_pushButton_4_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == number_of_pin_digits)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "3";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "3";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "3";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() == number_of_pin_digits) ValidateUser();

}

void MainWindow::on_pushButton_6_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == number_of_pin_digits)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "4";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "4";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "4";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() == number_of_pin_digits) ValidateUser();

}

void MainWindow::on_pushButton_7_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == number_of_pin_digits)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "5";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "5";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "5";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() == number_of_pin_digits) ValidateUser();

}

void MainWindow::on_pushButton_8_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == number_of_pin_digits)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "6";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "6";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "6";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() == number_of_pin_digits) ValidateUser();

}

void MainWindow::on_pushButton_10_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == number_of_pin_digits)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "7";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "7";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "7";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() == number_of_pin_digits) ValidateUser();

}

void MainWindow::on_pushButton_11_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == number_of_pin_digits)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "8";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "8";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "8";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() == number_of_pin_digits) ValidateUser();

}

void MainWindow::on_pushButton_12_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == number_of_pin_digits)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "9";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "9";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "9";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() == number_of_pin_digits) ValidateUser();

}

void MainWindow::on_pushButton_15_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == number_of_pin_digits)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "0";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "0";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "0";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() == number_of_pin_digits) ValidateUser();

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->plainTextEdit->setPlainText("");
    ui->plainTextEdit_2->setPlainText("");
    HideText = "";
    UserID = "";
    Pin = "";
    ui->label_4->setText("");
    ui->plainTextEdit->setFocus();
}
/*
====================================================================================================
End of Keypad Code
====================================================================================================
Lets validate user with database
====================================================================================================
*/
void MainWindow::ValidateUser()
{
    QSqlDatabase db = QSqlDatabase::addDatabase(DATABASEDRIVER);
    db.setHostName(DATABASEURL);
    db.setDatabaseName(DATABASENAME);
    db.setUserName(DATABASEUSER);
    db.setPassword(DATABASEPASSWORD);

    if (!db.open())
    {
         ui->label_4->setText("Unable to connect to database !!!");
        return;
    }
     ui->label_4->setText("Connected to database again....");


     QSqlQuery query;
//--We need user id or alt-id to validate or the override_key_number----------------------------------------------

     query.exec("SELECT * FROM user WHERE iduser = " + UserID + " OR User_id = " + UserID);
     query.next();
     QString pin_from_db = query.value(3).toString();
     //ui->label->setText(pin_from_db);
     qDebug() << "pin from db = " +pin_from_db;
     QString IButtonCodeFromDB = query.value(6).toString();//Get IButtonData
     int user_enabled_from_db = query.value(5).toInt();

//---------------Here we need to encode the PIN into a MD5 hash so we can compare with the----------------------
//-------------------------------------Given password-----------------------------------------------------------
     QSqlQuery query1;
     query1.exec("SELECT MD5('" + Pin + "')" );
     query1.next();
     QString MD5_Hash_from_db = query1.value(0).toString();
     db.close();
/*
=================================================================================================================
Is User Enabled
=================================================================================================================
*/
     if (!user_enabled_from_db)
     {
         ui->plainTextEdit->setPlainText("");
         ui->plainTextEdit_2->setPlainText("");
         HideText = "";
         UserID = "";
         Pin = "";
         ui->label_4->setText("User Not Enabled !!!");
         ui->plainTextEdit->setFocus();

         LogEvent("35");
         return;
     }
/*
================================================================================================================
Is PIN Correct
================================================================================================================
*/
     if(MD5_Hash_from_db == pin_from_db || IButtonCodeFromDB == DataFromVIM)
     {
        ui->plainTextEdit->setPlainText("");
        ui->plainTextEdit_2->setPlainText("");
        HideText = "";
        //UserID = "";
        Pin = "";
        if (lock1_serial->isOpen()) lock1_serial->close();//Close Comm Ports before leaving Screen
        if (lock2_serial->isOpen()) lock2_serial->close();//Close Comm Ports before leaving screen
        if(vim_serial->isOpen()) vim_serial->close();//Close Vim serial port
        lock1_serial_open = 0;
        lock2_serial_open = 0;
        vim_serial_open = 0;
        DoorMonitorTimer->stop();
//-----------------------------------------------Do we need to change PIN ?-------------------------------------
        //qDebug() << "Last PIN Change was " +  query.value(7).toString();
        QString DateFromDatabase = query.value(7).toString();

        QDate lastPINDate = QDate::fromString(DateFromDatabase,"MM/dd/yyyy");

        qDebug() << lastPINDate;
        qDebug() << days_before_pinchange;

        QDate PINExpiers = lastPINDate.addDays(days_before_pinchange);

        qDebug() <<  PINExpiers ;
        QDate dedate = QDate::currentDate();
        //qDebug() <<  dedate;
        if(dedate > PINExpiers)
        {
            pin_change_screen pin_change_screen;
            pin_change_screen.setModal(true);
            pin_change_screen.exec();
        }

//-----------------------------------------End of do we need to change PIN-------------------------------------
        lock_screen lock_screen;
        lock_screen.setModal(true);
        lock_screen.exec();

        ui->label_4->setText("");
        ui->plainTextEdit->setFocus();
        UserID="";

        Open_Lock1_SerialPort();//---------Open Comm Ports
        Open_Lock2_SerialPort();
        open_vim_serial();
        DoorMonitorTimer->start(500);
        return;
     }
/*
==============================================================================================================
Planed Fall Through Failed Authentication
==============================================================================================================
*/
     ui->plainTextEdit->setPlainText("");
     ui->plainTextEdit_2->setPlainText("");
     HideText = "";
     UserID = "";
     Pin = "";
     ui->label_4->setText("Validation Error !!!");
     ui->plainTextEdit->setFocus();
     return;
}
/*
==============================================================================================================
End of Validate user
===============================================================================================================
Open Serial Ports
===============================================================================================================
*/

void MainWindow::Open_Lock1_SerialPort()
{
//-------------------------------------------Lock 1---------------------------------------------------------------

    if(door1_enabledmm == 0)return;

    if (lock1_serial_open == 0)
    {
    lock1_serial = new QSerialPort(this);//----Instanciate Comm port 1
    qDebug() << "open Comm Port1";
    lock1_serial->setPortName("/dev/ttyACM0");
    lock1_serial->setBaudRate(QSerialPort::Baud115200);
    lock1_serial->setDataBits(QSerialPort::Data8);
    lock1_serial->setParity(QSerialPort::NoParity);
    lock1_serial->setStopBits(QSerialPort::OneStop);
    lock1_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (lock1_serial->open(QIODevice::ReadWrite))
        {

       // ui->label_4->setText("Door 1 Connected");
          lock1_serial_open = 1;
        } else
        {

        //ui->label_4->setText("Door 1 Connection Error");
           lock1_serial_open = 0;
         }

    }
//------------------------------------------End of Lock 1-------------------------------------------------------

return;
}

void MainWindow::Open_Lock2_SerialPort()
{
//--------------------------------------------Lock 2------------------------------------------------------------------

    if (door2_enabledmm == 0)return;

    if (lock2_serial_open == 0)
    {
     lock2_serial = new QSerialPort(this);//----Instanciate Comm port 2
     qDebug() << "open Comm Port2";
     lock2_serial->setPortName("/dev/ttyACM1");
     lock2_serial->setBaudRate(QSerialPort::Baud115200);
     lock2_serial->setDataBits(QSerialPort::Data8);
     lock2_serial->setParity(QSerialPort::NoParity);
     lock2_serial->setStopBits(QSerialPort::OneStop);
     lock2_serial->setFlowControl(QSerialPort::NoFlowControl);

     if (lock2_serial->open(QIODevice::ReadWrite))
      {

      //ui->label_4->setText("Door 1 Connected");
        lock2_serial_open = 1;
        } else
        {

     //ui->label_4->setText("Door 1 Connection Error");
        lock2_serial_open = 0;
        }

        }
//-------------------------------------------End of Lock 2------------------------------------------------------
return;
}
//-------------------------------------Open Comm Port for VIM module--------------------------------------------
void MainWindow::open_vim_serial(void)
{

    if(vim_serial_open == 0)
    {
    vim_serial = new QSerialPort(this);//----Instanciate VIM Com port
    qDebug() << "open VIM Comm Port";
    vim_serial->setPortName("/dev/ttyACM2");
    vim_serial->setBaudRate(QSerialPort::Baud115200);
    vim_serial->setDataBits(QSerialPort::Data8);
    vim_serial->setParity(QSerialPort::NoParity);
    vim_serial->setStopBits(QSerialPort::OneStop);
    vim_serial->setFlowControl(QSerialPort::NoFlowControl);

    if (vim_serial->open(QIODevice::ReadWrite))
     {

     //ui->label_4->setText("VIM Connected");
       vim_serial_open = 1;
       return;
    }

    else
    {

    //ui->label_4->setText("VIM Connection Error");
       vim_serial_open = 0;
    }

    }
return;
}
//--------------------------------------End of VIM Module-------------------------------------------------------
/*
================================================================================================================
Over-ride Button
================================================================================================================
*/
void MainWindow::on_pushButton_16_clicked()
{
    override_screen override_screen;
    override_screen.setModal(true);
    override_screen.exec();
}
/*
================================================================================================================
end of Over-ride Button
================================================================================================================
*/

void MainWindow::on_pushButton_5_clicked()
{
    aboutscreen aboutscreen;
    aboutscreen.setModal(true);
    aboutscreen.exec();
}

/*
============================================================================================================================
Log Event
============================================================================================================================
*/

void MainWindow::LogEvent(QString EventID)
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
/*
============================================================================================================
VIM Board Communications
============================================================================================================
*/

void MainWindow::vim_comm()
{

    QString data7 = "";
    if (vim_serial_open == 0) open_vim_serial();
    if (vim_serial_open == 0) return;

    if(is_vim_enabled == 0)
    {
        vim_serial->write("E;");//IF the VIM is no enabled Enable it
        is_vim_enabled = 1;
        //qDebug() << "VIM is now Enabled";
        while(vim_serial->bytesAvailable()>0||vim_serial->waitForReadyRead(10))
        {
           data7 = vim_serial->readAll();
        }
        //qDebug() << data7;
        return;
    }

     vim_serial->write("I;");//Send Show Me the Key
     while(vim_serial->bytesAvailable()>0||vim_serial->waitForReadyRead(10))
    {
       data7 = vim_serial->readAll();
     }
    //qDebug() << data7;
    vim_serial->write(";");//The VIM WILL NOT WORK WITHOUT THIS !!!
//----------------------------IF THE VIM RESPONSE IS NOT "ffffffffffffffff;" then process the number-------
//------------------------------Or VIM response is not "" or "OK;"-----------------------------------------

    DataFromVIM = data7;
    if(DataFromVIM == "OK;" || DataFromVIM == "" || DataFromVIM == "ffffffffffffffff;")return;
    qDebug() << DataFromVIM;
//---------------------------------Now we need to validate the number against the database----------------

    ValidateUser();
    return;
}
/*
============================================================================================================
End of VIM Board Communications
============================================================================================================
Lock 2 Comm
============================================================================================================
*/
void MainWindow::lock2_comm()
{
    if (door2_enabledmm == 0) return;
    if(lock2_serial_open == 0) Open_Lock2_SerialPort();
    if(lock2_serial_open == 0)return;

    lock2_serial->write("r;");
    QString data2 = "";

    while(lock2_serial->bytesAvailable()>0||lock2_serial->waitForReadyRead(10))
    {
       data2 = lock2_serial->readAll();
    }

    QString DoorOpenStatus2 = data2.mid(5,1);
    if(QString::compare(DoorOpenStatus2,"1") == 0)
    {
        ui->graphicsView->hide();
        ui->graphicsView_2->show();

//-------------------------------------------------------Log Event--------------------------------------------------
        if(Alarm_Logged2 == 0)
        {
          LogEvent("911");
          Alarm_Logged2 = 1;//Set Alarm Flag so we dont log multiple events for a single alarm
          return;
        }
//-------------------------------------------------------End of Log Event---------------------------------------------------
    }
        else
    {
        ui->graphicsView->show();
        ui->graphicsView_2->hide();
        Alarm_Logged2 = 0;//Reset Alarm Flag to catch next event
    }

    return;
}
/*
============================================================================================================
End of Lock 2 Comm
============================================================================================================
Lock 1 Comm
============================================================================================================
*/
void MainWindow::lock1_comm()
{
//-------------------------------------------Door 1------------------------------------------------
        if (door1_enabledmm == 0)return;
        if(lock1_serial_open == 0) Open_Lock1_SerialPort();
        if(lock1_serial_open == 0)return;

        lock1_serial->write("r;");
        QString data = "";

        while(lock1_serial->bytesAvailable()>0||lock1_serial->waitForReadyRead(10))
        {
           data = lock1_serial->readAll();
        }

        QString DoorOpenStatus = data.mid(5,1);
        if(QString::compare(DoorOpenStatus,"1") == 0)
        {
            ui->graphicsView->hide();
            ui->graphicsView_2->show();
//-------------------------------------------------------Log Event--------------------------------------------------
            if(Alarm_Logged == 0)
            {
              LogEvent("911");
              Alarm_Logged = 1;//Set Alarm Flag so we dont log multiple events for a single alarm
              return;
            }
//-------------------------------------------------------End of Log Event---------------------------------------------------
        else
        {
            ui->graphicsView->show();
            ui->graphicsView_2->hide();
            Alarm_Logged = 0;//Reset Alarm Flag to catch next event
        }

 return;
}
}
/*
==============================================================================================================
End of Lock 1 comm
===============================================================================================================
*/

