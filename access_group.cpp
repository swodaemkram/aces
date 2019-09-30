#include "access_group.h"
#include "ui_access_group.h"
#include <QStyle>
#include <QDesktopWidget>
//#include <QtWidgets>
#include <QtSql>

QString RecordModTypeaccess = "";
int RecordNumberaccess = 0;
QString NextRecordaccess  ;
QString PrevRecordStringaccess ;

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

          imageObject = new QImage();               //  _
          imageObject->load("./icons/background2.jpg");       //   |
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
           RecordNumberaccess = 0;
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
           ui->listWidget->setVisible(false);
}

Access_Group::~Access_Group()
{
    delete ui;
}

void Access_Group::on_pushButton_clicked()
{
    close();
}

void Access_Group::on_pushButton_4_clicked()
{
/*
=====================================================================================================================
Delete Button Pushed
=====================================================================================================================
*/
    ui->pushButton_49->show();
    ui->pushButton_5->show();
    ui->pushButton_2->setHidden(true);
    ui->pushButton_3->setHidden(true);
    ui->pushButton->setHidden(true);
    ui->pushButton_4->setHidden(true);
    RecordModTypeaccess = "delete";

/*
=====================================================================================================================
End of Delete Button
=====================================================================================================================
*/
}

void Access_Group::on_pushButton_49_clicked()
{
/*
===================================================================================================================
Cancel Button
===================================================================================================================
*/
    ui->plainTextEdit->setReadOnly(false);
    ui->pushButton_49->setHidden(true);
    ui->pushButton_5->setHidden(true);
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton->show();
    ui->pushButton_4->show();
    ui->frame_3->setHidden(true);
    RecordModTypeaccess = "";
    ui->listWidget->setVisible(false);
//-------------------------------------------Clear Highlghted Field----------------------------------------------
    ui->plainTextEdit->setStyleSheet("background-color: white");
    ui->plainTextEdit_2->setStyleSheet("background-color: white");
    ui->plainTextEdit_3->setStyleSheet("background-color: white");
    ui->plainTextEdit_4->setStyleSheet("background-color: white");
    ui->plainTextEdit_5->setStyleSheet("background-color: white");
    ui->plainTextEdit_6->setStyleSheet("background-color: white");
    ui->plainTextEdit_7->setStyleSheet("background-color: white");
    ui->plainTextEdit_8->setStyleSheet("background-color: white");
    ui->plainTextEdit_9->setStyleSheet("background-color: white");
    ui->plainTextEdit_10->setStyleSheet("background-color: white");
    ui->plainTextEdit_11->setStyleSheet("background-color: white");
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------Reload Current Record---------------------------------------------
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
//----------------------------------------------------Current Record Reloaded------------------------------------

/*
=====================================================================================================================
End of cancel Button
=====================================================================================================================
*/
}

void Access_Group::on_pushButton_3_clicked()
{
/*
===================================================================================================================
Edit Button
===================================================================================================================
*/

    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit_2->setFocus();
    ui->plainTextEdit_2->setStyleSheet("background-color: yellow");
    ui->pushButton_49->show();
    ui->pushButton_5->show();
    ui->pushButton_2->setHidden(true);
    ui->pushButton_3->setHidden(true);
    ui->pushButton->setHidden(true);
    ui->pushButton_4->setHidden(true);
    ui->frame_3->show();
    RecordModTypeaccess = "edit";

//--------------------List all Permissions Groups From Database---------------------------------------------------

            ui->listWidget->clear();

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

            int recordcount = 0;
            int LastRow = 1;
            QSqlQuery query ;
            query.exec("SELECT permission_window_name FROM permissions");

                    while(LastRow == 1)
         {
             LastRow = query.next();
             QString permission_window_name = query.value(0).toString();
             ui->listWidget->insertItem(recordcount,permission_window_name);
             recordcount++;

         }

         ui->listWidget->show();
         RecordModTypeaccess = "addnew";
//-------------------------End of loading data into list view-----------------------------------------------------

/*
===================================================================================================================
End of Edit Button
===================================================================================================================
*/
}

void Access_Group::on_pushButton_2_clicked()
{
/*
===================================================================================================================
Add New Button
===================================================================================================================
*/

    ui->pushButton_49->show();
    ui->pushButton_5->show();
    ui->pushButton_2->setHidden(true);
    ui->pushButton_3->setHidden(true);
    ui->pushButton->setHidden(true);
    ui->pushButton_4->setHidden(true);
    ui->frame_3->show();
    RecordModTypeaccess = "addnew";
//----------------------------------Load the Access Items into a list and show them-------------------------------
        ui->listWidget->clear();

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

        int recordcount = 0;
        int LastRow = 1;
        QSqlQuery query ;
        query.exec("SELECT permission_window_name FROM permissions");

                while(LastRow == 1)
     {
         LastRow = query.next();
         QString permission_window_name = query.value(0).toString();
         ui->listWidget->insertItem(recordcount,permission_window_name);
         recordcount++;

     }

     ui->listWidget->show();
//-------------------------End of loading data into list view-----------------------------------------------------
//---------------------------Clear Fields for new data set focus on field 1--------------------------------------

     ui->plainTextEdit->setPlainText("");
     ui->plainTextEdit_2->setPlainText("");
     ui->plainTextEdit_3->setPlainText("");
     ui->plainTextEdit_4->setPlainText("");
     ui->plainTextEdit_5->setPlainText("");
     ui->plainTextEdit_6->setPlainText("");
     ui->plainTextEdit_7->setPlainText("");
     ui->plainTextEdit_8->setPlainText("");
     ui->plainTextEdit_9->setPlainText("");
     ui->plainTextEdit_10->setPlainText("");
     ui->plainTextEdit_11->setPlainText("");
     ui->plainTextEdit->setFocus();
     ui->plainTextEdit->setStyleSheet("background-color: yellow");


/*
===================================================================================================================
End of Add New
===================================================================================================================
*/
}

void Access_Group::on_pushButton_50_clicked()
{
/*
==============================================================================================
Move Forward in Database
==============================================================================================
    */
        if(RecordModTypeaccess != "")return;

        QSqlQuery query;
         qDebug()<< RecordNumberaccess;

         RecordNumberaccess++ ;

         NextRecordaccess = QString::number(RecordNumberaccess);

         query.exec("SELECT * FROM permission_group LIMIT " + NextRecordaccess +",1");

         int nextrecordtrue = query.next();

         if (!nextrecordtrue)
         {
             RecordNumberaccess = RecordNumberaccess - 1;
             return;
          }
//------------------------------------------------Display Screen---------------------------------
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
//------------------------------------------------End of display screen---------------------------

/*
=============================================================================================
End of Move Forward in database
=============================================================================================
*/
}

void Access_Group::on_pushButton_51_clicked()
{
/*
===================================================================================================
Move Backwards in database
===================================================================================================
*/
    if(RecordModTypeaccess != "")return;

    QSqlQuery query;

    qDebug()<< RecordNumberaccess;

    if (RecordNumberaccess == 0)
    {

        query.exec("SELECT * FROM permission_group LIMIT " + PrevRecordStringaccess +",1");
        query.next();
//------------------------------------------------Display Screen---------------------------------
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
//------------------------------------------------End of display screen---------------------------
    return;
    }

    RecordNumberaccess-- ;

    PrevRecordStringaccess = QString::number(RecordNumberaccess);

    query.exec("SELECT * FROM permission_group LIMIT " + PrevRecordStringaccess +",1");
    query.next();
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
    return;
/*
===================================================================================================
End of Moveing Backwards in database
===================================================================================================
*/

}

void Access_Group::on_pushButton_47_clicked()
{
/*
===========================================================================================================
Handels Tab key
===========================================================================================================
*/


    if (ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_3->setFocus();
        ui->plainTextEdit_3->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_2->setStyleSheet("background-color: white");
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_3->setFocus();
        ui->plainTextEdit_3->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_2->setStyleSheet("background-color: white");
        return;
    }

    if (ui->plainTextEdit_3->hasFocus())
    {
        ui->plainTextEdit_4->setFocus();
        ui->plainTextEdit_4->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_3->setStyleSheet("background-color: white");
        return;
    }

    if (ui->plainTextEdit_4->hasFocus())
    {
        ui->plainTextEdit_5->setFocus();
        ui->plainTextEdit_5->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_4->setStyleSheet("background-color: white");
        return;
    }

    if (ui->plainTextEdit_5->hasFocus())
    {
        ui->plainTextEdit_6->setFocus();
        ui->plainTextEdit_6->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_5->setStyleSheet("background-color: white");
        return;
    }

    if (ui->plainTextEdit_6->hasFocus())
    {
        ui->plainTextEdit_7->setFocus();
        ui->plainTextEdit_7->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_6->setStyleSheet("background-color: white");
        return;
    }

    if (ui->plainTextEdit_7->hasFocus())
    {
        ui->plainTextEdit_8->setFocus();
        ui->plainTextEdit_8->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_7->setStyleSheet("background-color: white");
        return;
    }

    if (ui->plainTextEdit_8->hasFocus())
    {
        ui->plainTextEdit_9->setFocus();
        ui->plainTextEdit_9->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_8->setStyleSheet("background-color: white");
        return;
    }

    if (ui->plainTextEdit_9->hasFocus())
    {
        ui->plainTextEdit_10->setFocus();
        ui->plainTextEdit_10->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_9->setStyleSheet("background-color: white");
        return;
    }

    if (ui->plainTextEdit_10->hasFocus())
    {
        ui->plainTextEdit_11->setFocus();
        ui->plainTextEdit_11->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_10->setStyleSheet("background-color: white");
        return;
    }

    if (ui->plainTextEdit_11->hasFocus())
    {
        ui->plainTextEdit_2->setFocus();
        ui->plainTextEdit_2->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_11->setStyleSheet("background-color: white");
        return;
    }

/*
===========================================================================================================
Handels Tab key
===========================================================================================================
*/
}

void Access_Group::on_pushButton_25_clicked()
{
/*
===========================================================================================================
Handels Enter key
===========================================================================================================
*/

        if (ui->plainTextEdit_2->hasFocus())
        {
            ui->plainTextEdit_3->setFocus();
            ui->plainTextEdit_3->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_2->setStyleSheet("background-color: white");
            return;
        }

        if (ui->plainTextEdit_2->hasFocus())
        {
            ui->plainTextEdit_3->setFocus();
            ui->plainTextEdit_3->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_2->setStyleSheet("background-color: white");
            return;
        }

        if (ui->plainTextEdit_3->hasFocus())
        {
            ui->plainTextEdit_4->setFocus();
            ui->plainTextEdit_4->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_3->setStyleSheet("background-color: white");
            return;
        }

        if (ui->plainTextEdit_4->hasFocus())
        {
            ui->plainTextEdit_5->setFocus();
            ui->plainTextEdit_5->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_4->setStyleSheet("background-color: white");
            return;
        }

        if (ui->plainTextEdit_5->hasFocus())
        {
            ui->plainTextEdit_6->setFocus();
            ui->plainTextEdit_6->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_5->setStyleSheet("background-color: white");
            return;
        }

        if (ui->plainTextEdit_6->hasFocus())
        {
            ui->plainTextEdit_7->setFocus();
            ui->plainTextEdit_7->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_6->setStyleSheet("background-color: white");
            return;
        }

        if (ui->plainTextEdit_7->hasFocus())
        {
            ui->plainTextEdit_8->setFocus();
            ui->plainTextEdit_8->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_7->setStyleSheet("background-color: white");
            return;
        }

        if (ui->plainTextEdit_8->hasFocus())
        {
            ui->plainTextEdit_9->setFocus();
            ui->plainTextEdit_9->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_8->setStyleSheet("background-color: white");
            return;
        }

        if (ui->plainTextEdit_9->hasFocus())
        {
            ui->plainTextEdit_10->setFocus();
            ui->plainTextEdit_10->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_9->setStyleSheet("background-color: white");
            return;
        }

        if (ui->plainTextEdit_10->hasFocus())
        {
            ui->plainTextEdit_11->setFocus();
            ui->plainTextEdit_11->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_10->setStyleSheet("background-color: white");
            return;
        }

        if (ui->plainTextEdit_11->hasFocus())
        {
            ui->plainTextEdit_2->setFocus();
            ui->plainTextEdit_2->setStyleSheet("background-color: yellow");
            ui->plainTextEdit_11->setStyleSheet("background-color: white");
            return;
        }

/*
===========================================================================================================
Handels Enter key
===========================================================================================================
*/
}

void Access_Group::on_pushButton_5_clicked()
{
/*
===========================================================================================================
Save Button
===========================================================================================================
*/
//---------------------------------------Delete Function---------------------------------------------------
if (RecordModTypeaccess == "delete")
{
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
     QSqlQuery query;
     qDebug()<< ui->plainTextEdit->toPlainText();
     query.exec("DELETE FROM permission_group WHERE permission_group_name = '" + ui->plainTextEdit->toPlainText() + "'");
     query.next();

     ui->plainTextEdit->setReadOnly(false);
     ui->pushButton_49->setHidden(true);
     ui->pushButton_5->setHidden(true);
     ui->pushButton_2->show();
     ui->pushButton_3->show();
     ui->pushButton->show();
     ui->pushButton_4->show();
     ui->frame_3->setHidden(true);
     RecordModTypeaccess = "";
     ui->listWidget->setVisible(false);
 //-------------------------------------------Clear Highlghted Field----------------------------------------------
     ui->plainTextEdit->setStyleSheet("background-color: white");
     ui->plainTextEdit_2->setStyleSheet("background-color: white");
     ui->plainTextEdit_3->setStyleSheet("background-color: white");
     ui->plainTextEdit_4->setStyleSheet("background-color: white");
     ui->plainTextEdit_5->setStyleSheet("background-color: white");
     ui->plainTextEdit_6->setStyleSheet("background-color: white");
     ui->plainTextEdit_7->setStyleSheet("background-color: white");
     ui->plainTextEdit_8->setStyleSheet("background-color: white");
     ui->plainTextEdit_9->setStyleSheet("background-color: white");
     ui->plainTextEdit_10->setStyleSheet("background-color: white");
     ui->plainTextEdit_11->setStyleSheet("background-color: white");
 //---------------------------------------------------------------------------------------------------------------
 //---------------------------------------------Reload Current Record---------------------------------------------

     if (!db.open())
     {
          ui->label_2->setText("Unable to connect to database !!!");
         return;
     }
      ui->label_2->setText("Connected to database....");

      QSqlQuery query2;
      query2.exec("SELECT * FROM permission_group");
      query2.first();

      QString permissionGroupNamefromDB = query2.value(11).toString();
      ui->plainTextEdit->setPlainText(permissionGroupNamefromDB);
      QString item1DB = query2.value(1).toString();
      ui->plainTextEdit_2->setPlainText(item1DB);
      QString item2DB = query2.value(2).toString();
      ui->plainTextEdit_3->setPlainText(item2DB);
      QString item3DB = query2.value(3).toString();
      ui->plainTextEdit_4->setPlainText(item3DB);
      QString item4DB = query2.value(4).toString();
      ui->plainTextEdit_5->setPlainText(item4DB);
      QString item5DB = query2.value(5).toString();
      ui->plainTextEdit_6->setPlainText(item5DB);
      QString item6DB = query2.value(6).toString();
      ui->plainTextEdit_7->setPlainText(item6DB);
      QString item7DB = query2.value(7).toString();
      ui->plainTextEdit_8->setPlainText(item7DB);
      QString item8DB = query2.value(8).toString();
      ui->plainTextEdit_9->setPlainText(item8DB);
      QString item9DB = query2.value(9).toString();
      ui->plainTextEdit_10->setPlainText(item9DB);
      QString item10DB = query2.value(10).toString();
      ui->plainTextEdit_11->setPlainText(item10DB);
 //----------------------------------------------------Current Record Reloaded------------------------------------
     RecordModTypeaccess = "";
     RecordNumberaccess = 0;
      return;
}
//------------------------------------End of Delete Function-----------------------------------------------
//---------------------------------------Add New Function--------------------------------------------------
     if (RecordModTypeaccess == "addnew")
     {
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
          QSqlQuery query;

          query.exec("INSERT INTO permission_group (permission_group1, permission_group2, permission_group3, permission_group4, permission_group5, permission_group6, permission_group7, permission_group8, permission_group9, permission_group10, permission_group_name)"
                     " VALUES ('" + ui->plainTextEdit_2->toPlainText() + "','" +  ui->plainTextEdit_3->toPlainText() + "','" + ui->plainTextEdit_4->toPlainText() + "','" + ui->plainTextEdit_5->toPlainText() + "','"
                     + ui->plainTextEdit_6->toPlainText() + "','" + ui->plainTextEdit_7->toPlainText() + "','" + ui->plainTextEdit_8->toPlainText() + "','" + ui->plainTextEdit_9->toPlainText()+ "','" + ui->plainTextEdit_10->toPlainText() + "','" + ui->plainTextEdit_11->toPlainText() + "','" + ui->plainTextEdit->toPlainText() +"')");

          query.next();
          ui->plainTextEdit->setReadOnly(false);
          ui->pushButton_49->setHidden(true);
          ui->pushButton_5->setHidden(true);
          ui->pushButton_2->show();
          ui->pushButton_3->show();
          ui->pushButton->show();
          ui->pushButton_4->show();
          ui->frame_3->setHidden(true);
          RecordModTypeaccess = "";
          ui->listWidget->setVisible(false);
//-------------------------------------------Clear Highlghted Field----------------------------------------------
          ui->plainTextEdit->setStyleSheet("background-color: white");
          ui->plainTextEdit_2->setStyleSheet("background-color: white");
          ui->plainTextEdit_3->setStyleSheet("background-color: white");
          ui->plainTextEdit_4->setStyleSheet("background-color: white");
          ui->plainTextEdit_5->setStyleSheet("background-color: white");
          ui->plainTextEdit_6->setStyleSheet("background-color: white");
          ui->plainTextEdit_7->setStyleSheet("background-color: white");
          ui->plainTextEdit_8->setStyleSheet("background-color: white");
          ui->plainTextEdit_9->setStyleSheet("background-color: white");
          ui->plainTextEdit_10->setStyleSheet("background-color: white");
          ui->plainTextEdit_11->setStyleSheet("background-color: white");
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------Reload Current Record---------------------------------------------

          if (!db.open())
          {
               ui->label_2->setText("Unable to connect to database !!!");
              return;
          }
           ui->label_2->setText("Connected to database....");

           QSqlQuery query2;
           query2.exec("SELECT * FROM permission_group");
           query2.first();

           QString permissionGroupNamefromDB = query2.value(11).toString();
           ui->plainTextEdit->setPlainText(permissionGroupNamefromDB);
           QString item1DB = query2.value(1).toString();
           ui->plainTextEdit_2->setPlainText(item1DB);
           QString item2DB = query2.value(2).toString();
           ui->plainTextEdit_3->setPlainText(item2DB);
           QString item3DB = query2.value(3).toString();
           ui->plainTextEdit_4->setPlainText(item3DB);
           QString item4DB = query2.value(4).toString();
           ui->plainTextEdit_5->setPlainText(item4DB);
           QString item5DB = query2.value(5).toString();
           ui->plainTextEdit_6->setPlainText(item5DB);
           QString item6DB = query2.value(6).toString();
           ui->plainTextEdit_7->setPlainText(item6DB);
           QString item7DB = query2.value(7).toString();
           ui->plainTextEdit_8->setPlainText(item7DB);
           QString item8DB = query2.value(8).toString();
           ui->plainTextEdit_9->setPlainText(item8DB);
           QString item9DB = query2.value(9).toString();
           ui->plainTextEdit_10->setPlainText(item9DB);
           QString item10DB = query2.value(10).toString();
           ui->plainTextEdit_11->setPlainText(item10DB);
//----------------------------------------------------Current Record Reloaded------------------------------------
          RecordModTypeaccess = "";
          RecordNumberaccess = 0;
           return;
     }
//------------------------------------End of Add New Function----------------------------------------------
//----------------------------------------Edit Function----------------------------------------------------


//------------------------------------End of Edit Function-------------------------------------------------
/*
===========================================================================================================
End of Save Button
===========================================================================================================
*/
}
/*
===========================================================================================================
Keyboard Processing
===========================================================================================================
*/
void Access_Group::on_pushButton_35_clicked()
{
//---------------------------------------------Keyboard Button 1-------------------------------------------------
    if (ui->plainTextEdit->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_3->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_3->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit_3->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_5->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_5->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit_5->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_6->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_6->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit_6->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_7->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_7->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit_7->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_8->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_8->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit_8->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_9->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_9->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit_9->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_10->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_10->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit_10->setPlainText(KeyBuff);
        return;
    }
    if (ui->plainTextEdit_11->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_11->toPlainText();
        KeyBuff = KeyBuff + "1";
        ui->plainTextEdit_11->setPlainText(KeyBuff);
        return;
    }

//---------------------------------------------End of Button 1---------------------------------------------------
}

void Access_Group::on_pushButton_36_clicked()
{
    //---------------------------------------------Keyboard Button 2-------------------------------------------------
        if (ui->plainTextEdit->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_2->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_2->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        if (ui->plainTextEdit_3->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_3->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_4->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_4->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_5->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_5->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_6->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_6->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_7->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_7->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_8->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_8->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_9->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_9->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_10->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_10->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
        }
        if (ui->plainTextEdit_11->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_11->toPlainText();
            KeyBuff = KeyBuff + "2";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
        }

    //---------------------------------------------End of Button 2---------------------------------------------------
}

void Access_Group::on_pushButton_37_clicked()
{
    //---------------------------------------------Keyboard Button 3-------------------------------------------------
        if (ui->plainTextEdit->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_2->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_2->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        if (ui->plainTextEdit_3->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_3->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_4->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_4->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_5->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_5->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_6->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_6->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_7->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_7->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_8->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_8->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_9->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_9->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_10->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_10->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
        }
        if (ui->plainTextEdit_11->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_11->toPlainText();
            KeyBuff = KeyBuff + "3";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
        }

    //---------------------------------------------End of Button 3---------------------------------------------------
}

void Access_Group::on_pushButton_38_clicked()
{
    //---------------------------------------------Keyboard Button 4-------------------------------------------------
        if (ui->plainTextEdit->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_2->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_2->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        if (ui->plainTextEdit_3->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_3->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_4->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_4->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_5->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_5->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_6->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_6->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_7->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_7->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_8->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_8->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_9->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_9->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_10->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_10->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
        }
        if (ui->plainTextEdit_11->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_11->toPlainText();
            KeyBuff = KeyBuff + "4";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
        }

    //---------------------------------------------End of Button 4---------------------------------------------------
}

void Access_Group::on_pushButton_39_clicked()
{
    //---------------------------------------------Keyboard Button 5-------------------------------------------------
        if (ui->plainTextEdit->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_2->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_2->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        if (ui->plainTextEdit_3->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_3->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_4->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_4->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_5->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_5->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_6->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_6->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_7->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_7->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_8->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_8->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_9->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_9->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_10->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_10->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
        }
        if (ui->plainTextEdit_11->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_11->toPlainText();
            KeyBuff = KeyBuff + "5";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
        }

    //---------------------------------------------End of Button 5---------------------------------------------------
}

void Access_Group::on_pushButton_40_clicked()
{
    //---------------------------------------------Keyboard Button 6-------------------------------------------------
        if (ui->plainTextEdit->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_2->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_2->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        if (ui->plainTextEdit_3->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_3->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_4->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_4->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_5->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_5->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_6->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_6->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_7->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_7->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_8->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_8->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_9->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_9->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_10->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_10->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
        }
        if (ui->plainTextEdit_11->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_11->toPlainText();
            KeyBuff = KeyBuff + "6";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
        }

    //---------------------------------------------End of Button 6---------------------------------------------------
}

void Access_Group::on_pushButton_41_clicked()
{
    //---------------------------------------------Keyboard Button 7-------------------------------------------------
        if (ui->plainTextEdit->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_2->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_2->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        if (ui->plainTextEdit_3->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_3->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_4->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_4->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_5->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_5->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_6->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_6->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_7->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_7->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_8->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_8->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_9->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_9->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_10->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_10->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
        }
        if (ui->plainTextEdit_11->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_11->toPlainText();
            KeyBuff = KeyBuff + "7";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
        }

    //---------------------------------------------End of Button 7---------------------------------------------------
}

void Access_Group::on_pushButton_42_clicked()
{
    //---------------------------------------------Keyboard Button 8-------------------------------------------------
        if (ui->plainTextEdit->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_2->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_2->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        if (ui->plainTextEdit_3->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_3->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_4->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_4->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_5->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_5->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_6->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_6->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_7->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_7->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_8->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_8->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_9->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_9->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_10->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_10->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
        }
        if (ui->plainTextEdit_11->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_11->toPlainText();
            KeyBuff = KeyBuff + "8";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
        }

    //---------------------------------------------End of Button 8---------------------------------------------------
}

void Access_Group::on_pushButton_43_clicked()
{
    //---------------------------------------------Keyboard Button 9-------------------------------------------------
        if (ui->plainTextEdit->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_2->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_2->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        if (ui->plainTextEdit_3->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_3->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_4->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_4->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_5->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_5->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_6->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_6->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_7->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_7->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_8->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_8->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_9->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_9->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_10->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_10->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
        }
        if (ui->plainTextEdit_11->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_11->toPlainText();
            KeyBuff = KeyBuff + "9";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
        }

    //---------------------------------------------End of Button 9---------------------------------------------------
}

void Access_Group::on_pushButton_44_clicked()
{
    //---------------------------------------------Keyboard Button 0-------------------------------------------------
        if (ui->plainTextEdit->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_2->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_2->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        if (ui->plainTextEdit_3->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_3->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_4->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_4->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_5->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_5->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_6->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_6->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_7->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_7->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_8->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_8->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_9->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_9->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
        }

        if (ui->plainTextEdit_10->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_10->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
        }
        if (ui->plainTextEdit_11->hasFocus())
        {
            QString KeyBuff = ui->plainTextEdit_11->toPlainText();
            KeyBuff = KeyBuff + "0";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
        }

//---------------------------------------------End of Button 0---------------------------------------------------
}

void Access_Group::on_pushButton_7_clicked()
{
 //--------------------------------------------- Button q------------------------------------------------------------

    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
    }


    if (ui->plainTextEdit_3->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_3->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_3->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_3->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_5->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_5->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_5->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_5->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_6->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_6->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_6->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_6->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_7->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_7->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_7->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_7->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_8->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_8->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_8->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_8->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_9->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_9->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_9->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_9->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_10->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_10->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_10->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_10->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_11->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_11->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Q";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_11->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_11->setPlainText(KeyBuff);
        return;
    }

    return;
}

void Access_Group::on_pushButton_8_clicked()
{
//--------------------------------------------- Button W------------------------------------------------------------

       if (ui->plainTextEdit->hasFocus())
       {

           QString KeyBuff = ui->plainTextEdit->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit->setPlainText(KeyBuff);
           return;
       }

       if (ui->plainTextEdit_2->hasFocus())
       {
           QString KeyBuff = ui->plainTextEdit_2->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit_2->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit_2->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit_2->setPlainText(KeyBuff);
           return;
       }


       if (ui->plainTextEdit_3->hasFocus())
       {
           QString KeyBuff = ui->plainTextEdit_3->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit_3->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit_3->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit_3->setPlainText(KeyBuff);
           return;
       }

       if (ui->plainTextEdit_4->hasFocus())
       {
           QString KeyBuff = ui->plainTextEdit_4->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit_4->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit_4->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit_4->setPlainText(KeyBuff);
           return;
       }

       if (ui->plainTextEdit_5->hasFocus())
       {
           QString KeyBuff = ui->plainTextEdit_5->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit_5->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit_5->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit_5->setPlainText(KeyBuff);
           return;
       }

       if (ui->plainTextEdit_6->hasFocus())
       {
           QString KeyBuff = ui->plainTextEdit_6->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit_6->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit_6->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit_6->setPlainText(KeyBuff);
           return;
       }

       if (ui->plainTextEdit_7->hasFocus())
       {
           QString KeyBuff = ui->plainTextEdit_7->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit_7->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit_7->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit_7->setPlainText(KeyBuff);
           return;
       }

       if (ui->plainTextEdit_8->hasFocus())
       {
           QString KeyBuff = ui->plainTextEdit_8->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit_8->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit_8->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit_8->setPlainText(KeyBuff);
           return;
       }

       if (ui->plainTextEdit_9->hasFocus())
       {
           QString KeyBuff = ui->plainTextEdit_9->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit_9->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit_9->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit_9->setPlainText(KeyBuff);
           return;
       }

       if (ui->plainTextEdit_10->hasFocus())
       {
           QString KeyBuff = ui->plainTextEdit_10->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit_10->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit_10->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit_10->setPlainText(KeyBuff);
           return;
       }

       if (ui->plainTextEdit_11->hasFocus())
       {
           QString KeyBuff = ui->plainTextEdit_11->toPlainText();
           if(KeyBuff.size() == 0)
           {
               QString KeyBuff = "W";
               ui->plainTextEdit_11->setPlainText(KeyBuff);
               return;
            }

           KeyBuff = ui->plainTextEdit_11->toPlainText();
           KeyBuff = KeyBuff + "w";
           ui->plainTextEdit_11->setPlainText(KeyBuff);
           return;
       }

       return;
//-----------------------------------------------------End of the W key-------------------------------------------------------
}

void Access_Group::on_pushButton_9_clicked()
{
    //--------------------------------------------- Button E------------------------------------------------------------

           if (ui->plainTextEdit->hasFocus())
           {

               QString KeyBuff = ui->plainTextEdit->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_2->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_2->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit_2->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_2->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit_2->setPlainText(KeyBuff);
               return;
           }


           if (ui->plainTextEdit_3->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_3->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit_3->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_3->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit_3->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_4->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_4->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit_4->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_4->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit_4->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_5->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_5->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit_5->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_5->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit_5->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_6->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_6->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit_6->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_6->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit_6->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_7->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_7->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit_7->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_7->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit_7->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_8->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_8->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit_8->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_8->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit_8->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_9->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_9->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit_9->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_9->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit_9->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_10->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_10->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit_10->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_10->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit_10->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_11->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_11->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "E";
                   ui->plainTextEdit_11->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_11->toPlainText();
               KeyBuff = KeyBuff + "e";
               ui->plainTextEdit_11->setPlainText(KeyBuff);
               return;
           }

           return;
    //-----------------------------------------------------End of the E key-------------------------------------------------------
}

void Access_Group::on_pushButton_10_clicked()
{
    //--------------------------------------------- Button R------------------------------------------------------------

           if (ui->plainTextEdit->hasFocus())
           {

               QString KeyBuff = ui->plainTextEdit->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_2->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_2->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit_2->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_2->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit_2->setPlainText(KeyBuff);
               return;
           }


           if (ui->plainTextEdit_3->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_3->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit_3->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_3->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit_3->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_4->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_4->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit_4->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_4->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit_4->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_5->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_5->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit_5->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_5->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit_5->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_6->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_6->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit_6->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_6->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit_6->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_7->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_7->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit_7->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_7->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit_7->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_8->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_8->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit_8->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_8->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit_8->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_9->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_9->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit_9->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_9->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit_9->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_10->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_10->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit_10->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_10->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit_10->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_11->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_11->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "R";
                   ui->plainTextEdit_11->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_11->toPlainText();
               KeyBuff = KeyBuff + "r";
               ui->plainTextEdit_11->setPlainText(KeyBuff);
               return;
           }

           return;
    //-----------------------------------------------------End of the R key-------------------------------------------------------
}

void Access_Group::on_pushButton_12_clicked()
{//--------------------------------------------- Button W------------------------------------------------------------

    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
    }


    if (ui->plainTextEdit_3->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_3->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_3->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_3->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_5->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_5->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_5->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_5->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_6->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_6->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_6->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_6->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_7->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_7->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_7->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_7->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_8->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_8->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_8->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_8->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_9->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_9->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_9->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_9->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_10->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_10->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_10->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_10->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_11->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_11->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "T";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_11->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_11->setPlainText(KeyBuff);
        return;
    }

    return;
//-----------------------------------------------------End of the T key-------------------------------------------------------

}

void Access_Group::on_pushButton_11_clicked()
{//--------------------------------------------- Button Y------------------------------------------------------------

    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
    }


    if (ui->plainTextEdit_3->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_3->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit_3->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_3->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_3->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_5->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_5->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit_5->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_5->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_5->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_6->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_6->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit_6->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_6->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_6->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_7->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_7->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit_7->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_7->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_7->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_8->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_8->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit_8->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_8->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_8->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_9->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_9->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit_9->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_9->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_9->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_10->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_10->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit_10->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_10->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_10->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_11->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_11->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Y";
            ui->plainTextEdit_11->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_11->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_11->setPlainText(KeyBuff);
        return;
    }

    return;
//-----------------------------------------------------End of the Y key-------------------------------------------------------

}

void Access_Group::on_pushButton_17_clicked()
{
    //--------------------------------------------- Button U------------------------------------------------------------

           if (ui->plainTextEdit->hasFocus())
           {

               QString KeyBuff = ui->plainTextEdit->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_2->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_2->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit_2->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_2->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit_2->setPlainText(KeyBuff);
               return;
           }


           if (ui->plainTextEdit_3->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_3->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit_3->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_3->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit_3->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_4->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_4->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit_4->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_4->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit_4->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_5->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_5->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit_5->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_5->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit_5->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_6->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_6->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit_6->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_6->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit_6->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_7->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_7->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit_7->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_7->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit_7->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_8->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_8->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit_8->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_8->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit_8->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_9->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_9->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit_9->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_9->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit_9->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_10->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_10->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit_10->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_10->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit_10->setPlainText(KeyBuff);
               return;
           }

           if (ui->plainTextEdit_11->hasFocus())
           {
               QString KeyBuff = ui->plainTextEdit_11->toPlainText();
               if(KeyBuff.size() == 0)
               {
                   QString KeyBuff = "U";
                   ui->plainTextEdit_11->setPlainText(KeyBuff);
                   return;
                }

               KeyBuff = ui->plainTextEdit_11->toPlainText();
               KeyBuff = KeyBuff + "u";
               ui->plainTextEdit_11->setPlainText(KeyBuff);
               return;
           }

           return;
    //-----------------------------------------------------End of the U key-------------------------------------------------------
}
