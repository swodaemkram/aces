#include "access_group.h"
#include "ui_access_group.h"
#include <QStyle>
#include <QDesktopWidget>
//#include <QtWidgets>
#include <QtSql>

Access_Group::Access_Group(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Access_Group)
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
          imageObject->load("./icons/B4.jpg");       //   |
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
          ui->frame_3->hide();
          ui->pushButton_5->hide();
          ui->pushButton_49->hide();
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
          //QSqlQueryModel *model = new QSqlQueryModel();
          //QSqlQuery *qry = new QSqlQuery(db);
          //qry->prepare("SELECT * FROM permission_group");
          //qry->exec();
          //model->setQuery(*qry);
          //ui->tableView->setModel(model);
/*
============================================================================================================
Query s ran and TableView is loaded
============================================================================================================
*/
           QSqlQuery query;
           query.exec("SELECT * FROM permission_group");
           query.first();

           QString permissionGroupNamefromDB = query.value(11).toString();
           ui->plainTextEdit->setPlainText(permissionGroupNamefromDB);
           QString item1DB = query.value(1).toString();
           ui->plainTextEdit_2->setPlainText(item1DB);
           QString item2DB = query.value(2).toString();
           ui->plainTextEdit_3->setPlainText(item2DB);
           QString item3DB = query.value(3).toString();
           ui->plainTextEdit_4->setPlainText(item3DB);
           QString item4DB = query.value(4).toString();
           ui->plainTextEdit_5->setPlainText(item4DB);
           QString item5DB = query.value(5).toString();
           ui->plainTextEdit_6->setPlainText(item5DB);
           QString item6DB = query.value(6).toString();
           ui->plainTextEdit_7->setPlainText(item6DB);
           QString item7DB = query.value(7).toString();
           ui->plainTextEdit_8->setPlainText(item7DB);
           QString item8DB = query.value(8).toString();
           ui->plainTextEdit_9->setPlainText(item8DB);
           QString item9DB = query.value(9).toString();
           ui->plainTextEdit_10->setPlainText(item9DB);
           QString item10DB = query.value(10).toString();
           ui->plainTextEdit_11->setPlainText(item10DB);














}

Access_Group::~Access_Group()
{
    delete ui;
}

void Access_Group::on_pushButton_clicked()
{
    close();
}
