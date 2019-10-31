#include "pin_change_screen.h"
#include "ui_pin_change_screen.h"
#include "mainwindow.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QtSql>

extern int number_of_pin_digits;
extern QString UserID;

QString buffer = "";
QString hidetext = "";


pin_change_screen::pin_change_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pin_change_screen)
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
              imageObject->load("./icons/fire.jpg");    //   |
              image = QPixmap::fromImage(*imageObject); //   |
              scene = new QGraphicsScene(this);         //   |
              scene->addPixmap(image);                  //   |_______All this to display a picture
              scene->setSceneRect(image.rect());        //   |               WOW !
              ui->graphicsView->setScene(scene);        //   |
              imageObject = new QImage();

              buffer = "";   //---Clear Buffers
              hidetext = ""; //--CLear Buffers
/*
==============================================================================================================
Background is loaded
==============================================================================================================
*/

}

pin_change_screen::~pin_change_screen()
{
    delete ui;
}
/*
==============================================================================================================
Keyboard Handler
==============================================================================================================
*/
void pin_change_screen::on_pushButton_2_clicked()
{
    buffer = buffer + "1";
    hidetext = hidetext + "*";
    ui->plainTextEdit->setPlainText(hidetext);
    if (buffer.size() == number_of_pin_digits)
    {
        SaveAndExit();
    }
return;
}

 void pin_change_screen::on_pushButton_3_clicked()
{
    buffer = buffer + "2";
    hidetext = hidetext + "*";
    ui->plainTextEdit->setPlainText(hidetext);
    if (buffer.size() == number_of_pin_digits)
    {
        SaveAndExit();
    }
return;
}

void pin_change_screen::on_pushButton_4_clicked()
{
    buffer = buffer + "3";
    hidetext = hidetext + "*";
    ui->plainTextEdit->setPlainText(hidetext);
    if (buffer.size() == number_of_pin_digits)
    {
        SaveAndExit();
    }
return;
}

void pin_change_screen::on_pushButton_6_clicked()
{
    buffer = buffer + "4";
    hidetext = hidetext + "*";
    ui->plainTextEdit->setPlainText(hidetext);
    if (buffer.size() == number_of_pin_digits)
    {
        SaveAndExit();
    }
return;
}

void pin_change_screen::on_pushButton_7_clicked()
{
    buffer = buffer + "5";
    hidetext = hidetext + "*";
    ui->plainTextEdit->setPlainText(hidetext);
    if (buffer.size() == number_of_pin_digits)
    {
        SaveAndExit();
    }
return;
}

void pin_change_screen::on_pushButton_8_clicked()
{
    buffer = buffer + "6";
    hidetext = hidetext + "*";
    ui->plainTextEdit->setPlainText(hidetext);
    if (buffer.size() == number_of_pin_digits)
    {
        SaveAndExit();
    }
return;
}

void pin_change_screen::on_pushButton_10_clicked()
{
    buffer = buffer + "7";
    hidetext = hidetext + "*";
    ui->plainTextEdit->setPlainText(hidetext);
    if (buffer.size() == number_of_pin_digits)
    {
        SaveAndExit();
    }
return;
}

void pin_change_screen::on_pushButton_11_clicked()
{
    buffer = buffer + "8";
    hidetext = hidetext + "*";
    ui->plainTextEdit->setPlainText(hidetext);
    if (buffer.size() == number_of_pin_digits)
    {
        SaveAndExit();
    }
return;
}

void pin_change_screen::on_pushButton_12_clicked()
{
    buffer = buffer + "9";
    hidetext = hidetext + "*";
    ui->plainTextEdit->setPlainText(hidetext);
    if (buffer.size() == number_of_pin_digits)
    {
        SaveAndExit();
    }
return;
}

void pin_change_screen::on_pushButton_15_clicked()
{
    buffer = buffer + "0";
    hidetext = hidetext + "*";
    ui->plainTextEdit->setPlainText(hidetext);
    if (buffer.size() == number_of_pin_digits)
    {
        SaveAndExit();
    }
return;
}

void pin_change_screen::on_pushButton_14_clicked()
{
    //buffer = ui->plainTextEdit->toPlainText();
    buffer = "";
    hidetext = "";
    ui->plainTextEdit->setPlainText(hidetext);
    return;
}
/*
=============================================================================================================
End of Keyboard Handler
=============================================================================================================
Save and Exit
=============================================================================================================
*/

 void pin_change_screen::SaveAndExit(void)
 {
//--------------------------------------Open Database-------------------------------------------------------
     QSqlDatabase db = QSqlDatabase::addDatabase(DATABASEDRIVER);
     db.setHostName(DATABASEURL);
     db.setDatabaseName(DATABASENAME);
     db.setUserName(DATABASEUSER);
     db.setPassword(DATABASEPASSWORD);

     if (!db.open())
     {
          ui->label->setText("Unable to connect to database !!!");
         return;
     }
      ui->label->setText("Connected to database....");
//---------------------------------------------Hash PIN Code-------------------------------------------------
      QSqlQuery query1;
      query1.exec("SELECT MD5('" + buffer + "')" );
      qDebug() << buffer;
      query1.next();
      QString MD5_Hash_from_db = query1.value(0).toString();
      qDebug() << MD5_Hash_from_db;
      buffer = MD5_Hash_from_db;
      QDate dedate = QDate::currentDate();
//-------------------------------------------Update User------------------------------------------------------
      QSqlQuery query;
      query.exec("UPDATE user SET  pin_number = '" + buffer + "', date_of_last_pin_change = '" + dedate.toString("MM/dd/yyyy") +"' WHERE iduser = '" + UserID + "'" );
      qDebug() << "UPDATE user SET  pin_number = '" + buffer + "', date_of_last_pin_change = '" + dedate.toString("MM/dd/yyyy") +"' WHERE iduser = '" + UserID + "'" ;
      query.next();
      LogEvent("36");//Lets Log This Event
      close();
      return;
 }
/*
============================================================================================================
End of Save and Exit
============================================================================================================
*/

 void pin_change_screen::LogEvent(QString EventID)
 {

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
      query.exec("SELECT * FROM user WHERE iduser = " + UserID + " OR User_id = " + UserID);//<--We need user id or alt-id to validate
      query.next();
//-------------------------------------------Log Event------------------------------------------------------
      db.setHostName(DATABASEURL);
      db.setDatabaseName(DATABASENAME);
      db.setUserName(DATABASEUSER);
      db.setPassword(DATABASEPASSWORD);
      db.open();

       QString event_date = QDate::currentDate().toString("yyyyMMdd");
       QString event_time = QTime::currentTime().toString();

       QSqlQuery query4;
       query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + EventID + "')");

//--------------------------------------------Log Event----------------------------------------------------
/*
============================================================================================================
End of Logging
============================================================================================================
*/
     db.close();
     return;
 }

