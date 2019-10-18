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
QString RecordStatus = "";

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
        return;
/*
===============================================================================================================
End of Move Backwards In the Database
===============================================================================================================
*/
}
/*
===================================================================================================================
Add new Access Item
===================================================================================================================
*/
void manage_access_item::on_pushButton_2_clicked()
{

RecordModTypeManageAccess = "addnew";
//------------------------------------First thing clear everything and show save cancel buttons------------------
ui->plainTextEdit->setPlainText("");
ui->plainTextEdit_2->setPlainText("");
ui->plainTextEdit_3->setPlainText("");
ui->plainTextEdit_4->setPlainText("");
ui->checkBox->setChecked(false);
ui->checkBox_2->setChecked(false);
ui->checkBox_3->setChecked(false);
ui->checkBox_4->setChecked(false);
ui->checkBox_5->setChecked(false);
ui->checkBox_6->setChecked(false);
ui->checkBox_7->setChecked(false);
ui->checkBox_8->setChecked(false);
ui->checkBox_9->setChecked(false);
ui->checkBox_10->setChecked(false);
ui->checkBox_11->setChecked(false);
ui->checkBox_12->setChecked(false);
ui->checkBox_13->setChecked(false);
ui->checkBox_14->setChecked(false);
ui->checkBox_15->setChecked(false);
ui->checkBox_16->setChecked(false);
ui->checkBox_17->setChecked(false);
ui->checkBox_18->setChecked(false);
ui->checkBox_19->setChecked(false);
//---------------------------------------------Hide all other buttons--------------------------------------------
ui->pushButton->hide();
ui->pushButton_2->hide();
ui->pushButton_3->hide();
ui->pushButton_4->hide();
ui->pushButton_5->show();
ui->pushButton_6->show();
//---------------------------------------------set focus on first Item----------------------------------------
ui->plainTextEdit_4->setFocus();
ui->plainTextEdit_4->setStyleSheet("background-color: yellow");
//---------------------------------------------Show Keyboard---------------------------------------------------
ui->frame_3->show();

}
/*
================================================================================================================
End of Add new Access Item
================================================================================================================
Cancel Button
================================================================================================================
*/
void manage_access_item::on_pushButton_6_clicked()
{
//--------------------------------------------------Reload Record-----------------------------------------------
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
//-------------------------------------------End of reload record---------------------------------------------------
//----------------------------------------------Hide an show correct buttons----------------------------------------
    ui->pushButton_6->hide();
    ui->pushButton_5->hide();
    ui->pushButton_2->show();
    ui->pushButton_4->show();
    ui->pushButton_3->show();
    ui->pushButton->show();
    RecordModTypeManageAccess = "";
    ui->frame_3->hide();
//-----------------------------------------------Clear all highlighted items---------------------------------------
    ui->checkBox->setStyleSheet("background-color: white");
    ui->checkBox_2->setStyleSheet("background-color: white");
    ui->checkBox_3->setStyleSheet("background-color: white");
    ui->checkBox_4->setStyleSheet("background-color: white");
    ui->checkBox_5->setStyleSheet("background-color: white");
    ui->checkBox_6->setStyleSheet("background-color: white");
    ui->checkBox_7->setStyleSheet("background-color: white");
    ui->checkBox_8->setStyleSheet("background-color: white");
    ui->checkBox_9->setStyleSheet("background-color: white");
    ui->checkBox_10->setStyleSheet("background-color: white");
    ui->checkBox_11->setStyleSheet("background-color: white");
    ui->checkBox_12->setStyleSheet("background-color: white");
    ui->checkBox_13->setStyleSheet("background-color: white");
    ui->checkBox_14->setStyleSheet("background-color: white");
    ui->checkBox_15->setStyleSheet("background-color: white");
    ui->checkBox_16->setStyleSheet("background-color: white");
    ui->checkBox_17->setStyleSheet("background-color: white");
    ui->checkBox_18->setStyleSheet("background-color: white");
    ui->checkBox_19->setStyleSheet("background-color: white");
    ui->plainTextEdit_2->setStyleSheet("background-color: white");
    ui->plainTextEdit_3->setStyleSheet("background-color: white");
    ui->plainTextEdit_4->setStyleSheet("background-color: white");
//---------------------------------------------B End--------------------------------------------------------------

}
/*
===================================================================================================================
End of Cancel Button
===================================================================================================================
Tab Key on Keyboard
===================================================================================================================
*/

void manage_access_item::on_pushButton_48_clicked()
{
    if(ui->plainTextEdit_4->hasFocus())
    {
        ui->plainTextEdit_4->setStyleSheet("background-color: white");
        ui->plainTextEdit_2->setFocus();
        ui->plainTextEdit_2->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_2->setStyleSheet("background-color: white");
        ui->plainTextEdit_3->setFocus();
        ui->plainTextEdit_3->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        ui->plainTextEdit_3->setStyleSheet("background-color: white");
        ui->checkBox->setFocus();
        ui->checkBox->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox->hasFocus())
    {
        ui->checkBox->setStyleSheet("background-color: white");
        ui->checkBox_2->setFocus();
        ui->checkBox_2->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_2->hasFocus())
    {
        ui->checkBox_2->setStyleSheet("background-color: white");
        ui->checkBox_3->setFocus();
        ui->checkBox_3->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_3->hasFocus())
    {
        ui->checkBox_3->setStyleSheet("background-color: white");
        ui->checkBox_4->setFocus();
        ui->checkBox_4->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_4->hasFocus())
    {
        ui->checkBox_4->setStyleSheet("background-color: white");
        ui->checkBox_5->setFocus();
        ui->checkBox_5->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_5->hasFocus())
    {
        ui->checkBox_5->setStyleSheet("background-color: white");
        ui->checkBox_6->setFocus();
        ui->checkBox_6->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_6->hasFocus())
    {
        ui->checkBox_6->setStyleSheet("background-color: white");
        ui->checkBox_7->setFocus();
        ui->checkBox_7->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_7->hasFocus())
    {
        ui->checkBox_7->setStyleSheet("background-color: white");
        ui->checkBox_9->setFocus();
        ui->checkBox_9->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_9->hasFocus())
    {
        ui->checkBox_9->setStyleSheet("background-color: white");
        ui->checkBox_10->setFocus();
        ui->checkBox_10->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_10->hasFocus())
    {
        ui->checkBox_10->setStyleSheet("background-color: white");
        ui->checkBox_11->setFocus();
        ui->checkBox_11->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_11->hasFocus())
    {
        ui->checkBox_11->setStyleSheet("background-color: white");
        ui->checkBox_12->setFocus();
        ui->checkBox_12->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_12->hasFocus())
    {
        ui->checkBox_12->setStyleSheet("background-color: white");
        ui->checkBox_13->setFocus();
        ui->checkBox_13->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_13->hasFocus())
    {
        ui->checkBox_13->setStyleSheet("background-color: white");
        ui->checkBox_14->setFocus();
        ui->checkBox_14->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_14->hasFocus())
    {
        ui->checkBox_14->setStyleSheet("background-color: white");
        ui->checkBox_15->setFocus();
        ui->checkBox_15->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(2);
        return;
    }

    if(ui->checkBox_15->hasFocus())
    {
        ui->checkBox_15->setStyleSheet("background-color: white");
        ui->checkBox_16->setFocus();
        ui->checkBox_16->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(2);
        return;
    }

    if(ui->checkBox_16->hasFocus())
    {
        ui->checkBox_16->setStyleSheet("background-color: white");
        ui->checkBox_17->setFocus();
        ui->checkBox_17->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(2);
        return;
    }

    if(ui->checkBox_17->hasFocus())
    {
        ui->checkBox_17->setStyleSheet("background-color: white");
        ui->checkBox_18->setFocus();
        ui->checkBox_18->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(2);
        return;
    }

    if(ui->checkBox_18->hasFocus())
    {
        ui->checkBox_18->setStyleSheet("background-color: white");
        ui->checkBox_19->setFocus();
        ui->checkBox_19->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(2);
        return;
    }

    if(ui->checkBox_19->hasFocus())
    {
        ui->checkBox_19->setStyleSheet("background-color: white");
        ui->plainTextEdit_4->setFocus();
        ui->plainTextEdit_4->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

}
/*
================================================================================================================
End of Tab Key
================================================================================================================
Enter Key
================================================================================================================
*/
void manage_access_item::on_pushButton_25_clicked()
{
    if(ui->plainTextEdit_4->hasFocus())
    {
        ui->plainTextEdit_4->setStyleSheet("background-color: white");
        ui->plainTextEdit_2->setFocus();
        ui->plainTextEdit_2->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_2->setStyleSheet("background-color: white");
        ui->plainTextEdit_3->setFocus();
        ui->plainTextEdit_3->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        ui->plainTextEdit_3->setStyleSheet("background-color: white");
        ui->checkBox->setFocus();
        ui->checkBox->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox->hasFocus())
    {
        ui->checkBox->setStyleSheet("background-color: white");
        ui->checkBox_2->setFocus();
        ui->checkBox_2->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_2->hasFocus())
    {
        ui->checkBox_2->setStyleSheet("background-color: white");
        ui->checkBox_3->setFocus();
        ui->checkBox_3->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_3->hasFocus())
    {
        ui->checkBox_3->setStyleSheet("background-color: white");
        ui->checkBox_4->setFocus();
        ui->checkBox_4->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_4->hasFocus())
    {
        ui->checkBox_4->setStyleSheet("background-color: white");
        ui->checkBox_5->setFocus();
        ui->checkBox_5->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_5->hasFocus())
    {
        ui->checkBox_5->setStyleSheet("background-color: white");
        ui->checkBox_6->setFocus();
        ui->checkBox_6->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_6->hasFocus())
    {
        ui->checkBox_6->setStyleSheet("background-color: white");
        ui->checkBox_7->setFocus();
        ui->checkBox_7->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    if(ui->checkBox_7->hasFocus())
    {
        ui->checkBox_7->setStyleSheet("background-color: white");
        ui->checkBox_9->setFocus();
        ui->checkBox_9->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_9->hasFocus())
    {
        ui->checkBox_9->setStyleSheet("background-color: white");
        ui->checkBox_10->setFocus();
        ui->checkBox_10->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_10->hasFocus())
    {
        ui->checkBox_10->setStyleSheet("background-color: white");
        ui->checkBox_11->setFocus();
        ui->checkBox_11->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_11->hasFocus())
    {
        ui->checkBox_11->setStyleSheet("background-color: white");
        ui->checkBox_12->setFocus();
        ui->checkBox_12->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_12->hasFocus())
    {
        ui->checkBox_12->setStyleSheet("background-color: white");
        ui->checkBox_13->setFocus();
        ui->checkBox_13->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_13->hasFocus())
    {
        ui->checkBox_13->setStyleSheet("background-color: white");
        ui->checkBox_14->setFocus();
        ui->checkBox_14->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(1);
        return;
    }

    if(ui->checkBox_14->hasFocus())
    {
        ui->checkBox_14->setStyleSheet("background-color: white");
        ui->checkBox_15->setFocus();
        ui->checkBox_15->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(2);
        return;
    }

    if(ui->checkBox_15->hasFocus())
    {
        ui->checkBox_15->setStyleSheet("background-color: white");
        ui->checkBox_16->setFocus();
        ui->checkBox_16->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(2);
        return;
    }

    if(ui->checkBox_16->hasFocus())
    {
        ui->checkBox_16->setStyleSheet("background-color: white");
        ui->checkBox_17->setFocus();
        ui->checkBox_17->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(2);
        return;
    }

    if(ui->checkBox_17->hasFocus())
    {
        ui->checkBox_17->setStyleSheet("background-color: white");
        ui->checkBox_18->setFocus();
        ui->checkBox_18->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(2);
        return;
    }

    if(ui->checkBox_18->hasFocus())
    {
        ui->checkBox_18->setStyleSheet("background-color: white");
        ui->checkBox_19->setFocus();
        ui->checkBox_19->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(2);
        return;
    }

    if(ui->checkBox_19->hasFocus())
    {
        ui->checkBox_19->setStyleSheet("background-color: white");
        ui->plainTextEdit_4->setFocus();
        ui->plainTextEdit_4->setStyleSheet("background-color: yellow");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }
}
/*
======================================================================================================================
End of Enter Key
======================================================================================================================
CLEAR KEY
======================================================================================================================
*/
void manage_access_item::on_pushButton_33_clicked()
{
    if(ui->plainTextEdit_4->hasFocus())
    {
        ui->plainTextEdit_4->setPlainText("");
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_2->setPlainText("");
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        ui->plainTextEdit_3->setPlainText("");
        return;
    }

}
/*
==================================================================================================================
End of Clear Key
==================================================================================================================
Space bar
==================================================================================================================
*/
void manage_access_item::on_pushButton_47_clicked()
{
     if(ui->checkBox->hasFocus())
     {
         if(ui->checkBox->isChecked())
         {
             ui->checkBox->setChecked(false);
             return;
         }
         ui->checkBox->setChecked(true);
         return;
     }

     if(ui->checkBox_2->hasFocus())
     {
         if(ui->checkBox_2->isChecked())
         {
             ui->checkBox_2->setChecked(false);
             return;
         }
         ui->checkBox_2->setChecked(true);
         return;
     }

     if(ui->checkBox_3->hasFocus())
     {
         if(ui->checkBox_3->isChecked())
         {
             ui->checkBox_3->setChecked(false);
             return;
         }
         ui->checkBox_3->setChecked(true);
         return;
     }

     if(ui->checkBox_4->hasFocus())
     {
         if(ui->checkBox_4->isChecked())
         {
             ui->checkBox_4->setChecked(false);
             return;
         }
         ui->checkBox_4->setChecked(true);
         return;
     }


     if(ui->checkBox_5->hasFocus())
     {
         if(ui->checkBox_5->isChecked())
         {
             ui->checkBox_5->setChecked(false);
             return;
         }
         ui->checkBox_5->setChecked(true);
         return;
     }

     if(ui->checkBox_6->hasFocus())
     {
         if(ui->checkBox_6->isChecked())
         {
             ui->checkBox_6->setChecked(false);
             return;
         }
         ui->checkBox_6->setChecked(true);
         return;
     }

     if(ui->checkBox_7->hasFocus())
     {
         if(ui->checkBox_7->isChecked())
         {
             ui->checkBox_7->setChecked(false);
             return;
         }
         ui->checkBox_7->setChecked(true);
         return;
     }

     if(ui->checkBox_8->hasFocus())
     {
         if(ui->checkBox_8->isChecked())
         {
             ui->checkBox_8->setChecked(false);
             return;
         }
         ui->checkBox_8->setChecked(true);
         return;
     }

     if(ui->checkBox_9->hasFocus())
     {
         if(ui->checkBox_9->isChecked())
         {
             ui->checkBox_9->setChecked(false);
             return;
         }
         ui->checkBox_9->setChecked(true);
         return;
     }

     if(ui->checkBox_10->hasFocus())
     {
         if(ui->checkBox_10->isChecked())
         {
             ui->checkBox_10->setChecked(false);
             return;
         }
         ui->checkBox_10->setChecked(true);
         return;
     }

     if(ui->checkBox_11->hasFocus())
     {
         if(ui->checkBox_11->isChecked())
         {
             ui->checkBox_11->setChecked(false);
             return;
         }
         ui->checkBox_11->setChecked(true);
         return;
     }

     if(ui->checkBox_12->hasFocus())
     {
         if(ui->checkBox_12->isChecked())
         {
             ui->checkBox_12->setChecked(false);
             return;
         }
         ui->checkBox_12->setChecked(true);
         return;
     }

     if(ui->checkBox_13->hasFocus())
     {
         if(ui->checkBox_13->isChecked())
         {
             ui->checkBox_13->setChecked(false);
             return;
         }
         ui->checkBox_13->setChecked(true);
         return;
     }

     if(ui->checkBox_14->hasFocus())
     {
         if(ui->checkBox_14->isChecked())
         {
             ui->checkBox_14->setChecked(false);
             return;
         }
         ui->checkBox_14->setChecked(true);
         return;
     }

     if(ui->checkBox_15->hasFocus())
     {
         if(ui->checkBox_15->isChecked())
         {
             ui->checkBox_15->setChecked(false);
             return;
         }
         ui->checkBox_15->setChecked(true);
         return;
     }

     if(ui->checkBox_16->hasFocus())
     {
         if(ui->checkBox_16->isChecked())
         {
             ui->checkBox_16->setChecked(false);
             return;
         }
         ui->checkBox_16->setChecked(true);
         return;
     }

     if(ui->checkBox_17->hasFocus())
     {
         if(ui->checkBox_17->isChecked())
         {
             ui->checkBox_17->setChecked(false);
             return;
         }
         ui->checkBox_17->setChecked(true);
         return;
     }

     if(ui->checkBox_18->hasFocus())
     {
         if(ui->checkBox_18->isChecked())
         {
             ui->checkBox_18->setChecked(false);
             return;
         }
         ui->checkBox_18->setChecked(true);
         return;
     }

     if(ui->checkBox_19->hasFocus())
     {
         if(ui->checkBox_19->isChecked())
         {
             ui->checkBox_19->setChecked(false);
             return;
         }
         ui->checkBox_19->setChecked(true);
         return;
     }

}
/*
=================================================================================================================
End of Space Bar
=================================================================================================================
Main Keyboard Code
=================================================================================================================
*/
//--------------------------------------------------Key 1--------------------------------------------------------
void manage_access_item::on_pushButton_35_clicked()
{
    QString kybdbuff = "";
    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText() + "1";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + "1";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + "1";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

return;

}
//-----------------------------------------------------End of Key 1----------------------------------------------
//------------------------------------------------------Key 2----------------------------------------------------
void manage_access_item::on_pushButton_36_clicked()
{
    QString kybdbuff = "";
    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText() + "2";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + "2";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + "2";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

    return;

}
//-----------------------------------------------------End of Key 2-----------------------------------------------
//-----------------------------------------------------Key 3------------------------------------------------------
void manage_access_item::on_pushButton_37_clicked()
{
    QString kybdbuff = "";
    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText() + "3";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + "3";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + "3";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

   return;

}
//-----------------------------------------------------End of Key 3-------------------------------------------

void manage_access_item::on_pushButton_38_clicked()
{
    QString kybdbuff = "";
    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText() + "4";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + "4";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + "4";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

   return;
}

void manage_access_item::on_pushButton_39_clicked()
{
    QString kybdbuff = "";
    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText() + "5";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + "5";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + "5";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

   return;
}

void manage_access_item::on_pushButton_40_clicked()
{
    QString kybdbuff = "";
    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText() + "6";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + "6";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + "6";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

   return;
}

void manage_access_item::on_pushButton_41_clicked()
{
    QString kybdbuff = "";
    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText() + "7";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + "7";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + "7";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

   return;
}

void manage_access_item::on_pushButton_42_clicked()
{
    QString kybdbuff = "";
    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText() + "8";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + "8";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + "8";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

   return;
}

void manage_access_item::on_pushButton_43_clicked()
{
    QString kybdbuff = "";
    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText() + "9";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + "9";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + "9";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

   return;
}

void manage_access_item::on_pushButton_44_clicked()
{
    QString kybdbuff = "";
    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText() + "0";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + "0";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + "0";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

   return;
}

void manage_access_item::on_pushButton_46_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_3->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_3->toPlainText() + ":";
        ui->plainTextEdit_3->setPlainText(kybdbuff);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_2->toPlainText() + ":";
        ui->plainTextEdit_2->setPlainText(kybdbuff);
        return;
    }

   return;
}

void manage_access_item::on_pushButton_7_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "Q";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "q";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_8_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "W";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "w";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

    return;
}

void manage_access_item::on_pushButton_9_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "E";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "e";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_10_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "R";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "r";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_12_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "T";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "t";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_11_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "Y";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "y";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_17_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "U";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "u";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_13_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "I";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "i";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_14_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "O";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "o";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_15_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "P";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "p";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_16_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "A";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "a";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_28_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "S";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "s";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_18_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "D";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "d";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_19_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "F";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "f";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_20_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "G";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "g";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_21_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "H";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "h";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_22_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "J";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "j";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_23_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "K";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "k";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_24_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "L";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "l";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_26_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "Z";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "z";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_27_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "X";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "x";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_45_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "C";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "c";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_29_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "V";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "v";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_30_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "B";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "b";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_31_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "N";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "n";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}

void manage_access_item::on_pushButton_32_clicked()
{
    QString kybdbuff = "";

    if(ui->plainTextEdit_4->hasFocus())
    {
        kybdbuff = ui->plainTextEdit_4->toPlainText();

        if(kybdbuff.size() < 1)
        {
            kybdbuff = ui->plainTextEdit_4->toPlainText() + "M";
            ui->plainTextEdit_4->setPlainText(kybdbuff);
            return;
        }

        kybdbuff = ui->plainTextEdit_4->toPlainText() + "m";
        ui->plainTextEdit_4->setPlainText(kybdbuff);
        return;
    }

return;
}
/*
======================================================================================================================
End of Keyboard Handeling
======================================================================================================================
Save Button
======================================================================================================================
*/
void manage_access_item::on_pushButton_5_clicked()
{

//------------------------------------------If we are saving a new record------------------------------------------

    if(RecordModTypeManageAccess == "addnew")
    {
//-------------------------------------------We must have a name filled out---------------------------------------
        if(ui->plainTextEdit_4->toPlainText().size()<1)
        {
            ui->plainTextEdit_4->setFocus();
            ui->plainTextEdit_4->setStyleSheet("background-color: red");
            ui->label_2->setText("Must have a name !!!");
            return;
        }
//----------------------------------------------End of Check Name--------------------------------------------------
//----------------------------------------------Check Start Time---------------------------------------------------
       if(ui->plainTextEdit_2->toPlainText().size() < 4)
       {
         ui->plainTextEdit_2->setFocus();
         ui->plainTextEdit_2->setStyleSheet("background-color: red");
         ui->label_2->setText("Must have a valid start time !!!");
         return;
       }
//------------------------------------------------End of Start Time Check----------------------------------------
//------------------------------------------------End Time Check-------------------------------------------------
       if(ui->plainTextEdit_3->toPlainText().size() < 4)
       {
         ui->plainTextEdit_3->setFocus();
         ui->plainTextEdit_3->setStyleSheet("background-color: red");
         ui->label_2->setText("Must have a valid End time !!!");
         return;
       }
//------------------------------------------------End of End Time Check------------------------------------------
//-----------------------------------------Start Time Must Be Less then End Time---------------------------------
            QTime StartTime = QTime::fromString(ui->plainTextEdit_2->toPlainText()) ;
            QTime EndTime = QTime::fromString(ui->plainTextEdit_3->toPlainText()) ;

            if (StartTime > EndTime)
            {
            ui->plainTextEdit_2->setFocus();
            ui->plainTextEdit_2->setStyleSheet("background-color: red");
            ui->label_2->setText("Start Time must be less then End Time !!!!");
            return;
            }
//------------------------------------------------End of Sanity Checks-------------------------------------------
//------------------------------------------------Lets Save Record-----------------------------------------------
//----------------------------------------------------Open Database----------------------------------------------
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
//-----------------------------------------------------Database Opened-----------------------------------------
//------------------------------------------------Lets Get all Variables Set-----------------------------------
             QString start_time = ui->plainTextEdit_2->toPlainText();
             QString end_time = ui->plainTextEdit_3->toPlainText();
             QString Monday = "0";
             QString Tuesday = "0";
             QString Wednesday = "0";
             QString Thursday = "0";
             QString Friday = "0";
             QString Saturday = "0";
             QString sunday = "0";
             QString permission_window_name = ui->plainTextEdit_4->toPlainText();
             QString can_mod_users = "0";
             QString can_mod_system = "0";
             QString can_access_door1 = "0";
             QString can_access_door2 = "0";
             QString can_access_door3 = "0";
             QString can_access_door4 = "0";
             QString can_access_door5 = "0";
             QString can_access_door6 = "0";
             QString access_item_button_enabled = "0";
             QString access_group_button_enabled = "0";
             QString Loggs_button_enabled = "0";
//------------------------------------------Variables are set at defaults now-----------------------------------
//-------------------------------------------Lets set current status--------------------------------------------
             if (ui->checkBox->isChecked()) Monday = "1";
             if (ui->checkBox_2->isChecked()) Tuesday = "1";
             if (ui->checkBox_3->isChecked()) Wednesday = "1";
             if (ui->checkBox_4->isChecked()) Thursday = "1";
             if (ui->checkBox_5->isChecked()) Friday = "1";
             if (ui->checkBox_6->isChecked()) Saturday = "1";
             if (ui->checkBox_7->isChecked()) sunday = "1";
             if (ui->checkBox_9->isChecked()) can_access_door1 = "1";
             if (ui->checkBox_10->isChecked()) can_access_door2 = "1";
             if (ui->checkBox_11->isChecked()) can_access_door3 = "1";
             if (ui->checkBox_12->isChecked()) can_access_door4 = "1";
             if (ui->checkBox_13->isChecked()) can_access_door5 = "1";
             if (ui->checkBox_14->isChecked()) can_access_door6 = "1";
             if (ui->checkBox_15->isChecked()) Loggs_button_enabled = "1";
             if (ui->checkBox_16->isChecked()) access_group_button_enabled = "1";
             if (ui->checkBox_17->isChecked()) access_item_button_enabled = "1";
             if (ui->checkBox_18->isChecked()) can_mod_system = "1";
             if (ui->checkBox_19->isChecked()) can_mod_users = "1";

             QSqlQuery query;

             query.exec("INSERT INTO permissions(start_time,end_time,Monday,Tuesday,Wednesday,\
                        Thursday,Friday,Saturday,sunday,permission_window_name,can_mod_users,\
                        can_mod_system,can_access_door1,can_access_door2,can_access_door3,\
                        can_access_door4,can_access_door5,can_access_door6,access_item_button_enabled,\
                        access_group_button_enabled,Loggs_button_enabled) VALUES ('" + start_time + "','" +
                        end_time + "','" + Monday + "','" + Tuesday + "','" + Wednesday + "','" \
                        + Thursday + "','" + Friday + "','" + Saturday + "','" + sunday + "','" \
                        + permission_window_name + "','"+ can_mod_users + "','" + can_mod_system + "','" \
                        + can_access_door1 + "','" + can_access_door2 + "','" + can_access_door3 + "','"\
                        + can_access_door4 + "','" + can_access_door5 + "','" + can_access_door6 + "','"\
                        + access_item_button_enabled + "','" +  access_group_button_enabled + "','"\
                        +  Loggs_button_enabled + "')");

             query.next();

        ui->label_2->setText("Record Saved......");

//-----------------------------------------------Clear all highlighted items---------------------------------------
      ui->checkBox->setStyleSheet("background-color: white");
      ui->checkBox_2->setStyleSheet("background-color: white");
      ui->checkBox_3->setStyleSheet("background-color: white");
      ui->checkBox_4->setStyleSheet("background-color: white");
      ui->checkBox_5->setStyleSheet("background-color: white");
      ui->checkBox_6->setStyleSheet("background-color: white");
      ui->checkBox_7->setStyleSheet("background-color: white");
      ui->checkBox_8->setStyleSheet("background-color: white");
      ui->checkBox_9->setStyleSheet("background-color: white");
      ui->checkBox_10->setStyleSheet("background-color: white");
      ui->checkBox_11->setStyleSheet("background-color: white");
      ui->checkBox_12->setStyleSheet("background-color: white");
      ui->checkBox_13->setStyleSheet("background-color: white");
      ui->checkBox_14->setStyleSheet("background-color: white");
      ui->checkBox_15->setStyleSheet("background-color: white");
      ui->checkBox_16->setStyleSheet("background-color: white");
      ui->checkBox_17->setStyleSheet("background-color: white");
      ui->checkBox_18->setStyleSheet("background-color: white");
      ui->checkBox_19->setStyleSheet("background-color: white");
      ui->plainTextEdit_2->setStyleSheet("background-color: white");
      ui->plainTextEdit_3->setStyleSheet("background-color: white");
      ui->plainTextEdit_4->setStyleSheet("background-color: white");

//-----------------------------------------Hide and show all the correct buttons-----------------------------------
        ui->pushButton_2->show();
        ui->pushButton_3->show();
        ui->pushButton_4->show();
        ui->pushButton->show();
        ui->pushButton_6->hide();
        ui->pushButton_5->hide();
        RecordModTypeManageAccess = "";
        return;
    }
//-------------------------------------------End of Save New Record------------------------------------------------
//-------------------------------------------Delete Current Record-------------------------------------------------
     if(RecordModTypeManageAccess == "delete")
     {
//----------------------------------------------Open Database------------------------------------------------------
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
//----------------------------------------------Setup SQL Query and Execute--------------------------------------------
          QSqlQuery query;
          query.exec("DELETE FROM permissions WHERE idpermission_window = " + ui->plainTextEdit->toPlainText());
          query.next();
//-----------------------------------------------Reload Modified Database---------------------------------------------
//---------------------------------------------------Reload Control Buttons-------------------------------------------
           ui->pushButton->show();
           ui->pushButton_2->show();
           ui->pushButton_3->show();
           ui->pushButton_4->show();
           ui->pushButton_6->hide();
           ui->pushButton_5->hide();
           RecordModTypeManageAccess = "";
           on_pushButton_51_clicked();
           return;
     }
//-----------------------------------------End of Delete Current Record---------------------------------------------
//---------------------------------------------------Save Edited Record---------------------------------------------
     if(RecordModTypeManageAccess == "edit")
     {
//-------------------------------------------We must have a name filled out---------------------------------------
       if(ui->plainTextEdit_4->toPlainText().size()<1)
       {
           ui->plainTextEdit_4->setFocus();
           ui->plainTextEdit_4->setStyleSheet("background-color: red");
           ui->label_2->setText("Must have a name !!!");
           return;
        }
//----------------------------------------------End of Check Name--------------------------------------------------
//----------------------------------------------Check Start Time---------------------------------------------------
       if(ui->plainTextEdit_2->toPlainText().size() < 4)
       {
         ui->plainTextEdit_2->setFocus();
         ui->plainTextEdit_2->setStyleSheet("background-color: red");
         ui->label_2->setText("Must have a valid start time !!!");
         return;
       }
//------------------------------------------------End of Start Time Check----------------------------------------
//------------------------------------------------End Time Check-------------------------------------------------
       if(ui->plainTextEdit_3->toPlainText().size() < 4)
       {
         ui->plainTextEdit_3->setFocus();
         ui->plainTextEdit_3->setStyleSheet("background-color: red");
         ui->label_2->setText("Must have a valid End time !!!");
         return;
       }
//------------------------------------------------End of End Time Check------------------------------------------
//-----------------------------------------Start Time Must Be Less then End Time---------------------------------
        QTime StartTime = QTime::fromString(ui->plainTextEdit_2->toPlainText()) ;
        QTime EndTime = QTime::fromString(ui->plainTextEdit_3->toPlainText()) ;

        if (StartTime > EndTime)
        {
          ui->plainTextEdit_2->setFocus();
          ui->plainTextEdit_2->setStyleSheet("background-color: red");
          ui->label_2->setText("Start Time must be less then End Time !!!!");
          return;
         }
//------------------------------------------------End of Sanity Checks-------------------------------------------
//------------------------------------------------Lets Save Record-----------------------------------------------
//----------------------------------------------------Open Database----------------------------------------------
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
//-----------------------------------------------------Database Opened-----------------------------------------
//------------------------------------------------Lets Get all Variables Set-----------------------------------
             QString start_time = ui->plainTextEdit_2->toPlainText();
             QString end_time = ui->plainTextEdit_3->toPlainText();
             QString Monday = "0";
             QString Tuesday = "0";
             QString Wednesday = "0";
             QString Thursday = "0";
             QString Friday = "0";
             QString Saturday = "0";
             QString sunday = "0";
             QString permission_window_name = ui->plainTextEdit_4->toPlainText();
             QString can_mod_users = "0";
             QString can_mod_system = "0";
             QString can_access_door1 = "0";
             QString can_access_door2 = "0";
             QString can_access_door3 = "0";
             QString can_access_door4 = "0";
             QString can_access_door5 = "0";
             QString can_access_door6 = "0";
             QString access_item_button_enabled = "0";
             QString access_group_button_enabled = "0";
             QString Loggs_button_enabled = "0";
//------------------------------------------Variables are set at defaults now-----------------------------------
//-------------------------------------------Lets set current status--------------------------------------------
             if (ui->checkBox->isChecked()) Monday = "1";
             if (ui->checkBox_2->isChecked()) Tuesday = "1";
             if (ui->checkBox_3->isChecked()) Wednesday = "1";
             if (ui->checkBox_4->isChecked()) Thursday = "1";
             if (ui->checkBox_5->isChecked()) Friday = "1";
             if (ui->checkBox_6->isChecked()) Saturday = "1";
             if (ui->checkBox_7->isChecked()) sunday = "1";
             if (ui->checkBox_9->isChecked()) can_access_door1 = "1";
             if (ui->checkBox_10->isChecked()) can_access_door2 = "1";
             if (ui->checkBox_11->isChecked()) can_access_door3 = "1";
             if (ui->checkBox_12->isChecked()) can_access_door4 = "1";
             if (ui->checkBox_13->isChecked()) can_access_door5 = "1";
             if (ui->checkBox_14->isChecked()) can_access_door6 = "1";
             if (ui->checkBox_15->isChecked()) Loggs_button_enabled = "1";
             if (ui->checkBox_16->isChecked()) access_group_button_enabled = "1";
             if (ui->checkBox_17->isChecked()) access_item_button_enabled = "1";
             if (ui->checkBox_18->isChecked()) can_mod_system = "1";
             if (ui->checkBox_19->isChecked()) can_mod_users = "1";

             QSqlQuery query;

             query.exec("UPDATE permissions SET start_time = '" + start_time + "', end_time = '" + end_time \
                        + "', Monday = '"+ Monday +"', Tuesday = '" + Tuesday + "', Wednesday = '"+ Wednesday \
                        + "', Thursday = '" + Thursday + "', Friday = '"+ Friday + "', Saturday = '" + Saturday \
                        + "', sunday = '" + sunday + "', permission_window_name = '" + permission_window_name \
                        + "', can_mod_users = '" + can_mod_users + "', can_mod_system = '" + can_mod_system \
                        + "', can_access_door1 = '" + can_access_door1 + "', can_access_door2 = '" + can_access_door2 \
                        + "', can_access_door3 = '" + can_access_door3 + "', can_access_door4 = '" + can_access_door4 \
                        + "', can_access_door5 = '" + can_access_door5 + "', can_access_door6 = '" + can_access_door6 \
                        + "', access_item_button_enabled = '" + access_item_button_enabled + "', access_group_button_enabled = '" + \
                        access_group_button_enabled + "', Loggs_button_enabled = '" + Loggs_button_enabled + "' WHERE idpermission_window = '" + ui->plainTextEdit->toPlainText() + "'");

             query.next();
             ui->label_2->setText("Record Saved......");

//-----------------------------------------------Clear all highlighted items---------------------------------------
      ui->checkBox->setStyleSheet("background-color: white");
      ui->checkBox_2->setStyleSheet("background-color: white");
      ui->checkBox_3->setStyleSheet("background-color: white");
      ui->checkBox_4->setStyleSheet("background-color: white");
      ui->checkBox_5->setStyleSheet("background-color: white");
      ui->checkBox_6->setStyleSheet("background-color: white");
      ui->checkBox_7->setStyleSheet("background-color: white");
      ui->checkBox_8->setStyleSheet("background-color: white");
      ui->checkBox_9->setStyleSheet("background-color: white");
      ui->checkBox_10->setStyleSheet("background-color: white");
      ui->checkBox_11->setStyleSheet("background-color: white");
      ui->checkBox_12->setStyleSheet("background-color: white");
      ui->checkBox_13->setStyleSheet("background-color: white");
      ui->checkBox_14->setStyleSheet("background-color: white");
      ui->checkBox_15->setStyleSheet("background-color: white");
      ui->checkBox_16->setStyleSheet("background-color: white");
      ui->checkBox_17->setStyleSheet("background-color: white");
      ui->checkBox_18->setStyleSheet("background-color: white");
      ui->checkBox_19->setStyleSheet("background-color: white");
      ui->plainTextEdit_2->setStyleSheet("background-color: white");
      ui->plainTextEdit_3->setStyleSheet("background-color: white");
      ui->plainTextEdit_4->setStyleSheet("background-color: white");

//-----------------------------------------Hide and show all the correct buttons-----------------------------------
       ui->pushButton_2->show();
       ui->pushButton_3->show();
       ui->pushButton_4->show();
       ui->pushButton->show();
       ui->pushButton_6->hide();
       ui->pushButton_5->hide();
       ui->frame_3->hide();
       RecordModTypeManageAccess = "";

             return;
         }

}
/*
=====================================================================================================================
End of Save Button
=====================================================================================================================
Edit Current Record Button
=====================================================================================================================
*/
void manage_access_item::on_pushButton_4_clicked()
{
//-------------------------------------------Setup Control Buttons--------------------------------------------------
             ui->pushButton->hide();
             ui->pushButton_2->hide();
             ui->pushButton_3->hide();
             ui->pushButton_4->hide();
             ui->pushButton_6->show();
             ui->pushButton_5->show();
             RecordModTypeManageAccess = "edit";
             ui->plainTextEdit_4->setFocus();
             ui->plainTextEdit_4->setStyleSheet("background-color: yellow");
             ui->frame_3->show();
}
/*
===================================================================================================================
End of Edit Current Record Button
===================================================================================================================
Delete Button
===================================================================================================================
*/
void manage_access_item::on_pushButton_3_clicked()
{
//----------------------------------------------Hide and Show Correct Buttons------------------------------------
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->show();
    ui->pushButton_5->show();
//--------------------------------------------End of Hide Show Buttons------------------------------------------
    RecordModTypeManageAccess = "delete";
}
/*
==============================================================================================================
End of Delete Button
==============================================================================================================
*/
