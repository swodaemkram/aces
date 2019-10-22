#include "aboutscreen.h"
#include "ui_aboutscreen.h"
#include <QtSql>
#include <QStyle>
#include <QDesktopWidget>

aboutscreen::aboutscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutscreen)
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

              imageObject = new QImage();               //  _
              imageObject->load("./icons/fireking-logo.png");    //   |
              image = QPixmap::fromImage(*imageObject); //   |
              scene = new QGraphicsScene(this);         //   |
              scene->addPixmap(image);                  //   |_______All this to display a picture
              scene->setSceneRect(image.rect());        //   |               WOW !
              ui->graphicsView_2->setScene(scene);        //   |
              imageObject = new QImage();

/*
==============================================================================================================
Background is loaded
==============================================================================================================
*/





}

aboutscreen::~aboutscreen()
{
    delete ui;
}

void aboutscreen::on_pushButton_clicked()
{
    close();
}
