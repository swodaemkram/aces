#include "user_screen.h"
#include "ui_user_screen.h"
#include <QStyle>
#include <QDesktopWidget>
//#include <QtWidgets>
#include <QtSql>


user_screen::user_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_screen)
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

/*
=================================================================================================================
So lets load the user grid
=================================================================================================================
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
==================================================================================================================
We are connected to the database lets run a select all query
==================================================================================================================
*/
   // QSqlQueryModel *model = new QSqlQueryModel(); //This is for a grid view that wont work well with touch screen
   // QSqlQuery *qry = new QSqlQuery(db);
   // qry->prepare("SELECT * FROM user");
   // qry->exec();
   //  model->setQuery(*qry); //This is for a grid view that wont work well with touch screen
   // ui->tableView->setModel(model); //This is for a grid view that wont work well with touch screen
/*
==================================================================================================================
Query s ran and TableView is loaded
==================================================================================================================
We need to Fill in all the Screen info on the current record
==================================================================================================================
*/

   QSqlQuery query;
   query.exec("SELECT * FROM user");
   query.next();
   QString pin_from_db = query.value(3).toString();





 QString FirstNamefromDB = query.value(1).toString();
 ui->plainTextEdit->setPlainText(FirstNamefromDB);

 QString LastNamefromDB = query.value(2).toString();
 ui->plainTextEdit_2->setPlainText(LastNamefromDB);

 QString PinfromDB = query.value(3).toString();
 ui->plainTextEdit_3->setPlainText(PinfromDB);









}

user_screen::~user_screen()
{
    delete ui;
}

void user_screen::on_pushButton_clicked()
{
    close();
}

void user_screen::on_pushButton_2_clicked()
{

}

void user_screen::on_pushButton_51_clicked()
{

}
