#include "lock_screen.h"
#include "ui_lock_screen.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QtSql>

extern QString UserID;

lock_screen::lock_screen(QWidget *parent) :
    QMainWindow(parent),
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
   QString user_enabled = query.value(5).toString();

   ui->label_2->setText("User Logged in is " + FirstNameFromDatabase+ " " +LastNameFromDatabase + " " + user_enabled);

/*
===========================================================================================================
Check to see if the user is enabled if not ditch out and back to login screen
===========================================================================================================
*/
   int UserStatus = user_enabled.toInt();
   qDebug() << UserStatus;
   if(!UserStatus)
   {
       qDebug("This is the end");
       close();
   }
/*
==========================================================================================================
End of user verificaton
==========================================================================================================
*/

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
