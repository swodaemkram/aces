#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lock_screen.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QtSql>
#include <unistd.h>
#include <QNetworkInterface>
#include"override_screen.h"

QString UserID;
QString Pin;
QString Validatae;
QString HideText;

int lock1_serial_open = 0;
int Alarm_Logged = 0;

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
  lock1_serial = new QSerialPort(this);

  imageObject = new QImage();               //  _
  imageObject->load(REDBACKGROUNDIMAGE);       //   |
  image = QPixmap::fromImage(*imageObject); //   |
  scene = new QGraphicsScene(this);         //   |
  scene->addPixmap(image);                  //   |_______All this to display a picture
  scene->setSceneRect(image.rect());        //   |               WOW !
  ui->graphicsView_2->setScene(scene);        //   |
  imageObject = new QImage();
  lock1_serial = new QSerialPort(this);
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
   Log system boot
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

 QString event_date = QDate::currentDate().toString("yyyyMMdd");

 QString event_time = QTime::currentTime().toString();

 QSqlQuery query4;
 query4.exec("INSERT INTO event_log (event_date, event_time, event_code) VALUES ('"+ event_date + "','" + event_time + "','" + "1" +"')");



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
/*
====================================================================================================
  End of Log system Boot
====================================================================================================
*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
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
    QString ct = time.toString("hh:mm:ss    ");
    QDate dedate = QDate::currentDate();
    QString cd = dedate.toString();
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
//-------------------------------------------Door 1------------------------------------------------

    if(lock1_serial_open == 0) Open_Lock1_SerialPort();

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

         QString event_date = QDate::currentDate().toString("yyyyMMdd");

         QString event_time = QTime::currentTime().toString();

         QSqlQuery query4;
         query4.exec("INSERT INTO event_log (event_date, event_time, event_code) VALUES ('"+ event_date + "','" + event_time + "','" + "911" +"')");
         Alarm_Logged = 1;//Set Alarm Flag so we dont log multiple events for a single alarm
        }
//-------------------------------------------------------End of Log Event---------------------------------------------------
        return;
    }
        else
    {
        ui->graphicsView->show();
        ui->graphicsView_2->hide();
        Alarm_Logged = 0;//Reset Alarm Flag to catch next event
    }
//----------------------------------------End of Door 1---------------------------------------------------------------------
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

        if (UserID.length() == 4)
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

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_3_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
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

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_4_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
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

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_6_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
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

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_7_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
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

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_8_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
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

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_10_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
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

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_11_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
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

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_12_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
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

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_15_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
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

    if (Pin.length() ==4) ValidateUser();

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
     query.exec("SELECT * FROM user WHERE iduser = " + UserID );
     query.next();
     QString pin_from_db = query.value(3).toString();
     //ui->label->setText(pin_from_db);
     int user_enabled_from_db = query.value(5).toInt();

//-------------------------------------Here we need to encode the PIN into a MD5 hash so we can compare with the
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

          QString event_date = QDate::currentDate().toString("yyyyMMdd");

          QString event_time = QTime::currentTime().toString();

          QSqlQuery query4;
          query4.exec("INSERT INTO event_log (event_date, event_time, event_code) VALUES ('"+ event_date + "','" + event_time + "','" + "35" +"')");
         return;
     }
/*
================================================================================================================
Is PIN Correct
================================================================================================================
*/

     if(MD5_Hash_from_db == pin_from_db)
     {
        ui->plainTextEdit->setPlainText("");
        ui->plainTextEdit_2->setPlainText("");
        HideText = "";
        //UserID = "";
        Pin = "";
        if (lock1_serial->isOpen()) lock1_serial->close();
        DoorMonitorTimer->stop();
        lock1_serial_open = 0;
        lock_screen lock_screen;
        lock_screen.setModal(true);
        lock_screen.exec();
        ui->label_4->setText("");
        ui->plainTextEdit->setFocus();
        UserID="";
        DoorMonitorTimer->start(500);

        return;
     }
/*
==============================================================================================================
Planed Fall Through
==============================================================================================================
*/

     ui->plainTextEdit->setPlainText("");
     ui->plainTextEdit_2->setPlainText("");
     HideText = "";
     UserID = "";
     Pin = "";
     ui->label_4->setText("Validation Error !!!");
     ui->plainTextEdit->setFocus();
}
/*
==============================================================================================================
End of Validate user
===============================================================================================================
Open Lock 1 Serial Port
===============================================================================================================
*/

void MainWindow::Open_Lock1_SerialPort()
{
    if (lock1_serial_open == 0)
    {


    qDebug() << "open Comm Port";
    lock1_serial->setPortName("/dev/ttyACM0");
    lock1_serial->setBaudRate(QSerialPort::Baud115200);
    lock1_serial->setDataBits(QSerialPort::Data8);
    lock1_serial->setParity(QSerialPort::NoParity);
    lock1_serial->setStopBits(QSerialPort::OneStop);
    lock1_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (lock1_serial->open(QIODevice::ReadWrite))
        {

       // ui->label_4->setText("Door 1 Connected");//DEBUG MARK MEADOWS
          lock1_serial_open = 1;
        } else
        {

        //ui->label_4->setText("Door 1 Connection Error");//DEBUG MARK MEADOWS
           lock1_serial_open = 0;
         }

    }

    return;
}

void MainWindow::on_pushButton_16_clicked()
{
    override_screen override_screen;
    override_screen.setModal(true);
    override_screen.exec();
}
