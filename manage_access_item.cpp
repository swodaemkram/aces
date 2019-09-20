#include "manage_access_item.h"
#include "ui_manage_access_item.h"
#include <QStyle>
#include <QDesktopWidget>
//#include <QtWidgets>
#include <QtSql>


manage_access_item::manage_access_item(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manage_access_item)
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
Background is loaded
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
We are connected to the database lets run a select all query
============================================================================================================
*/
      QSqlQueryModel *model = new QSqlQueryModel();
      QSqlQuery *qry = new QSqlQuery(db);
      qry->prepare("SELECT * FROM permissions");
      qry->exec();
      model->setQuery(*qry);
      ui->tableView->setModel(model);
/*
============================================================================================================
Query s ran and TableView is loaded
============================================================================================================
*/






}

manage_access_item::~manage_access_item()
{
    delete ui;
}

void manage_access_item::on_pushButton_clicked()
{
    close();
}
