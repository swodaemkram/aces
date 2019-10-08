#include "manage_access_item.h"
#include "ui_manage_access_item.h"
#include "mainwindow.h"
#include <QStyle>
#include <QDesktopWidget>
//#include <QtWidgets>
#include <QtSql>

QString RecordModTypeManageAccess = "";
int RecordNumberManageAccess = 0;
QString NextRecordNumberManageAccess = "" ;

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
      imageObject->load(BACKGROUNDIMAGE);       //   |
      image = QPixmap::fromImage(*imageObject); //   |
      scene = new QGraphicsScene(this);         //   |
      scene->addPixmap(image);                  //   |_______All this to display a picture
      scene->setSceneRect(image.rect());        //   |               WOW !
      ui->graphicsView->setScene(scene);        //   |
      imageObject = new QImage();

      imageObject = new QImage();               //  _
      imageObject->load(SECONDBACKGROUNDIMAGE);       //   |
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
     ui->pushButton_6->hide();
     ui->pushButton_5->hide();
     ui->frame_3->hide();
     ui->checkBox_8->hide();

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
We are connected to the database lets run a select all query
============================================================================================================
*/
       RecordNumberManageAccess = 0;
       RecordModTypeManageAccess = "";
       NextRecordNumberManageAccess = "" ;

       QSqlQuery query;
       query.exec("SELECT * FROM permissions");
       query.next();

       ui->plainTextEdit_4->setPlainText(query.value(10).toString());
       ui->plainTextEdit_2->setPlainText(query.value(1).toString());
       ui->plainTextEdit_3->setPlainText(query.value(2).toString());
       ui->plainTextEdit->setPlainText(query.value(0).toString());
       if(query.value(3) == 1)ui->checkBox->setChecked(true);
        else ui->checkBox->setChecked(false);
       if(query.value(4) == 1)ui->checkBox_2->setChecked(true);
       else ui->checkBox_2->setChecked(false);
       if(query.value(5) == 1)ui->checkBox_3->setChecked(true);
       else ui->checkBox_3->setChecked(false);
       if(query.value(6) == 1)ui->checkBox_4->setChecked(true);
       else ui->checkBox_4->setChecked(false);
       if(query.value(7) == 1)ui->checkBox_5->setChecked(true);
       else ui->checkBox_5->setChecked(false);
       if(query.value(8) == 1)ui->checkBox_6->setChecked(true);
       else ui->checkBox_6->setChecked(false);
       if(query.value(9) == 1)ui->checkBox_7->setChecked(true);
       else ui->checkBox_7->setChecked(false);
       if(query.value(10) == 1)ui->checkBox_8->setChecked(true);
       else ui->checkBox_8->setChecked(false);
       if(query.value(13) == 1)ui->checkBox_9->setChecked(true);
       else ui->checkBox_9->setChecked(false);
       if(query.value(14) == 1)ui->checkBox_10->setChecked(true);
       else ui->checkBox_10->setChecked(false);
       if(query.value(15) == 1)ui->checkBox_11->setChecked(true);
       else ui->checkBox_11->setChecked(false);
       if(query.value(16) == 1)ui->checkBox_12->setChecked(true);
       else ui->checkBox_12->setChecked(false);
       if(query.value(17) == 1)ui->checkBox_13->setChecked(true);
       else ui->checkBox_13->setChecked(false);
       if(query.value(18) == 1)ui->checkBox_14->setChecked(true);
       else ui->checkBox_14->setChecked(false);
       if(query.value(19) == 1)ui->checkBox_17->setChecked(true);
       else ui->checkBox_17->setChecked(false);
       if(query.value(20) == 1)ui->checkBox_16->setChecked(true);
       else ui->checkBox_16->setChecked(false);
       if(query.value(21) == 1)ui->checkBox_15->setChecked(true);
       else ui->checkBox_15->setChecked(false);
       if(query.value(12) == 1)ui->checkBox_18->setChecked(true);
       else ui->checkBox_18->setChecked(false);
       if(query.value(11) == 1)ui->checkBox_19->setChecked(true);
       else ui->checkBox_19->setChecked(false);
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

void manage_access_item::on_pushButton_50_clicked()
{
/*
===============================================================================================================
Move Forward In the Database
===============================================================================================================
*/

    if(RecordModTypeManageAccess != "")return;

    QSqlQuery query;
     qDebug()<< RecordNumberManageAccess;

     RecordNumberManageAccess++ ;

     NextRecordNumberManageAccess = QString::number(RecordNumberManageAccess);

     query.exec("SELECT * FROM permissions LIMIT " + NextRecordNumberManageAccess +",1");

     int nextrecordtrue = query.next();

     if (!nextrecordtrue)
     {
         RecordNumberManageAccess = RecordNumberManageAccess - 1;
         return;
      }

    ui->plainTextEdit_4->setPlainText(query.value(10).toString());
    ui->plainTextEdit_2->setPlainText(query.value(1).toString());
    ui->plainTextEdit_3->setPlainText(query.value(2).toString());
    ui->plainTextEdit->setPlainText(query.value(0).toString());
    if(query.value(3) == 1)ui->checkBox->setChecked(true);
     else ui->checkBox->setChecked(false);
    if(query.value(4) == 1)ui->checkBox_2->setChecked(true);
    else ui->checkBox_2->setChecked(false);
    if(query.value(5) == 1)ui->checkBox_3->setChecked(true);
    else ui->checkBox_3->setChecked(false);
    if(query.value(6) == 1)ui->checkBox_4->setChecked(true);
    else ui->checkBox_4->setChecked(false);
    if(query.value(7) == 1)ui->checkBox_5->setChecked(true);
    else ui->checkBox_5->setChecked(false);
    if(query.value(8) == 1)ui->checkBox_6->setChecked(true);
    else ui->checkBox_6->setChecked(false);
    if(query.value(9) == 1)ui->checkBox_7->setChecked(true);
    else ui->checkBox_7->setChecked(false);
    if(query.value(10) == 1)ui->checkBox_8->setChecked(true);
    else ui->checkBox_8->setChecked(false);
    if(query.value(13) == 1)ui->checkBox_9->setChecked(true);
    else ui->checkBox_9->setChecked(false);
    if(query.value(14) == 1)ui->checkBox_10->setChecked(true);
    else ui->checkBox_10->setChecked(false);
    if(query.value(15) == 1)ui->checkBox_11->setChecked(true);
    else ui->checkBox_11->setChecked(false);
    if(query.value(16) == 1)ui->checkBox_12->setChecked(true);
    else ui->checkBox_12->setChecked(false);
    if(query.value(17) == 1)ui->checkBox_13->setChecked(true);
    else ui->checkBox_13->setChecked(false);
    if(query.value(18) == 1)ui->checkBox_14->setChecked(true);
    else ui->checkBox_14->setChecked(false);
    if(query.value(19) == 1)ui->checkBox_17->setChecked(true);
    else ui->checkBox_17->setChecked(false);
    if(query.value(20) == 1)ui->checkBox_16->setChecked(true);
    else ui->checkBox_16->setChecked(false);
    if(query.value(21) == 1)ui->checkBox_15->setChecked(true);
    else ui->checkBox_15->setChecked(false);
    if(query.value(12) == 1)ui->checkBox_18->setChecked(true);
    else ui->checkBox_18->setChecked(false);
    if(query.value(11) == 1)ui->checkBox_19->setChecked(true);
    else ui->checkBox_19->setChecked(false);
/*
===============================================================================================================
Ens of Move Forward In the Database
===============================================================================================================
*/
}

void manage_access_item::on_pushButton_51_clicked()
{
    /*
    ===============================================================================================================
    Move Backwards In the Database
    ===============================================================================================================
    */

        if(RecordModTypeManageAccess != "")return;

        QSqlQuery query;
         qDebug()<< RecordNumberManageAccess;

         RecordNumberManageAccess-- ;

         NextRecordNumberManageAccess = QString::number(RecordNumberManageAccess);

         query.exec("SELECT * FROM permissions LIMIT " + NextRecordNumberManageAccess +",1");

         int nextrecordtrue = query.next();

         if (!nextrecordtrue)
         {
             RecordNumberManageAccess = RecordNumberManageAccess + 1;
             return;
          }

        ui->plainTextEdit_4->setPlainText(query.value(10).toString());
        ui->plainTextEdit_2->setPlainText(query.value(1).toString());
        ui->plainTextEdit_3->setPlainText(query.value(2).toString());
        ui->plainTextEdit->setPlainText(query.value(0).toString());
        if(query.value(3) == 1)ui->checkBox->setChecked(true);
         else ui->checkBox->setChecked(false);
        if(query.value(4) == 1)ui->checkBox_2->setChecked(true);
        else ui->checkBox_2->setChecked(false);
        if(query.value(5) == 1)ui->checkBox_3->setChecked(true);
        else ui->checkBox_3->setChecked(false);
        if(query.value(6) == 1)ui->checkBox_4->setChecked(true);
        else ui->checkBox_4->setChecked(false);
        if(query.value(7) == 1)ui->checkBox_5->setChecked(true);
        else ui->checkBox_5->setChecked(false);
        if(query.value(8) == 1)ui->checkBox_6->setChecked(true);
        else ui->checkBox_6->setChecked(false);
        if(query.value(9) == 1)ui->checkBox_7->setChecked(true);
        else ui->checkBox_7->setChecked(false);
        if(query.value(10) == 1)ui->checkBox_8->setChecked(true);
        else ui->checkBox_8->setChecked(false);
        if(query.value(13) == 1)ui->checkBox_9->setChecked(true);
        else ui->checkBox_9->setChecked(false);
        if(query.value(14) == 1)ui->checkBox_10->setChecked(true);
        else ui->checkBox_10->setChecked(false);
        if(query.value(15) == 1)ui->checkBox_11->setChecked(true);
        else ui->checkBox_11->setChecked(false);
        if(query.value(16) == 1)ui->checkBox_12->setChecked(true);
        else ui->checkBox_12->setChecked(false);
        if(query.value(17) == 1)ui->checkBox_13->setChecked(true);
        else ui->checkBox_13->setChecked(false);
        if(query.value(18) == 1)ui->checkBox_14->setChecked(true);
        else ui->checkBox_14->setChecked(false);
        if(query.value(19) == 1)ui->checkBox_17->setChecked(true);
        else ui->checkBox_17->setChecked(false);
        if(query.value(20) == 1)ui->checkBox_16->setChecked(true);
        else ui->checkBox_16->setChecked(false);
        if(query.value(21) == 1)ui->checkBox_15->setChecked(true);
        else ui->checkBox_15->setChecked(false);
        if(query.value(12) == 1)ui->checkBox_18->setChecked(true);
        else ui->checkBox_18->setChecked(false);
        if(query.value(11) == 1)ui->checkBox_19->setChecked(true);
        else ui->checkBox_19->setChecked(false);
    /*
    ===============================================================================================================
    End of Move Backwards In the Database
    ===============================================================================================================
    */
}
