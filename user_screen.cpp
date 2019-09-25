#include "user_screen.h"
#include "ui_user_screen.h"
#include <QStyle>
#include <QDesktopWidget>
//#include <QtWidgets>
#include <QtSql>

    QString iduserFromDB;
    QString NextRecord  ;
    QString PrevRecordString;
    QString RecordModType = "";

    int RecordNumber = 0;

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
  ui->plainTextEdit->setFocus();
  ui->pushButton_5->hide();
  ui->pushButton_49->hide();
  ui->frame_4->hide();
/*
=================================================================================================================
So lets connect to the database
=================================================================================================================
*/
  ui->listWidget->setVisible(false);
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
   query.exec("SELECT * FROM user");

/*
==================================================================================================================
We are connected to the database lets run a select all query
==================================================================================================================
We need to Fill in all the Screen info on the current record
==================================================================================================================
*/
 query.first();

 iduserFromDB = query.value(0).toString();
 ui->label_11->setText(iduserFromDB);

 QString FirstNamefromDB = query.value(1).toString();
 ui->plainTextEdit->setPlainText(FirstNamefromDB);

 QString LastNamefromDB = query.value(2).toString();
 ui->plainTextEdit_2->setPlainText(LastNamefromDB);

 QString PinfromDB = query.value(3).toString();
 ui->plainTextEdit_3->setPlainText(PinfromDB);

 QString  PermissionGroupfromDB =  query.value(4).toString();
 ui->plainTextEdit_4->setPlainText(PermissionGroupfromDB);

 int UserEnabledfromDB = query.value(5).toInt();
 if(UserEnabledfromDB == 1)ui->checkBox->setChecked(true);
 else ui->checkBox->setChecked(false);
/*
================================================================================================================
Screen loaded with First record int the dataqbase
================================================================================================================
*/

}

user_screen::~user_screen()
{
    delete ui;
}

void user_screen::on_pushButton_clicked()
{
    RecordNumber = 0;
    close();
}

void user_screen::on_pushButton_2_clicked()
{
/*
===================================================================================================
Edit User Button
=====================================================================================================
*/
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->show();
    ui->pushButton_49->show();
    ui->frame_4->show();
   ui->listWidget->clear();

//--------------------List all Permissions Groups From Database----------------------------

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
    query.exec("SELECT permission_group_name FROM permission_group");

            while(LastRow == 1)
 {
     LastRow = query.next();
     QString permission_group_name = query.value(0).toString();
     ui->listWidget->insertItem(recordcount,permission_group_name);
     recordcount++;

 }



    ui->listWidget->setVisible(true);
    RecordModType = "edit";
/*
===================================================================================================
End of Edit User Button
=====================================================================================================
*/
}

void user_screen::on_pushButton_51_clicked()
{
/*
==============================================================================================
Move Forward in Database
==============================================================================================
*/

    if(RecordModType != "")return;

    QSqlQuery query;
     qDebug()<< RecordNumber;

     RecordNumber++ ;

     NextRecord = QString::number(RecordNumber);

     query.exec("SELECT * FROM user LIMIT " + NextRecord +",1");

     int nextrecordtrue = query.next();

     if (!nextrecordtrue)
     {
         RecordNumber = RecordNumber - 1;
         return;
      }

     iduserFromDB = query.value(0).toString();
     ui->label_11->setText(iduserFromDB);
     QString FirstNamefromDB = query.value(1).toString();
     ui->plainTextEdit->setPlainText(FirstNamefromDB);
     QString LastNamefromDB = query.value(2).toString();
     ui->plainTextEdit_2->setPlainText(LastNamefromDB);
     QString PinfromDB = query.value(3).toString();
     ui->plainTextEdit_3->setPlainText(PinfromDB);
     QString  PermissionGroupfromDB =  query.value(4).toString();
     ui->plainTextEdit_4->setPlainText(PermissionGroupfromDB);
     int UserEnabledfromDB = query.value(5).toInt();
     if(UserEnabledfromDB == 1)ui->checkBox->setChecked(true);
     else ui->checkBox->setChecked(false);
     ui->label_9->setText(NextRecord);
/*
=============================================================================================
End of Move Forward in database
=============================================================================================
*/
}

void user_screen::on_pushButton_50_clicked()
{
/*
============================================================================================
Move Backward in database
============================================================================================
*/

    if(RecordModType != "")return;

    QSqlQuery query;

    qDebug()<< RecordNumber;

    if (RecordNumber == 0)
    {

        query.exec("SELECT * FROM user LIMIT " + PrevRecordString +",1");
        query.next();
        iduserFromDB = query.value(0).toString();
        ui->label_11->setText(iduserFromDB);
        QString FirstNamefromDB = query.value(1).toString();
        ui->plainTextEdit->setPlainText(FirstNamefromDB);
        QString LastNamefromDB = query.value(2).toString();
        ui->plainTextEdit_2->setPlainText(LastNamefromDB);
        QString PinfromDB = query.value(3).toString();
        ui->plainTextEdit_3->setPlainText(PinfromDB);
        QString  PermissionGroupfromDB =  query.value(4).toString();
        ui->plainTextEdit_4->setPlainText(PermissionGroupfromDB);
        int UserEnabledfromDB = query.value(5).toInt();
        if(UserEnabledfromDB == 1)ui->checkBox->setChecked(true);
        else ui->checkBox->setChecked(false);
        return;
    }

    RecordNumber-- ;

    PrevRecordString = QString::number(RecordNumber);

    query.exec("SELECT * FROM user LIMIT " + PrevRecordString +",1");
    query.next();

    iduserFromDB = query.value(0).toString();
    ui->label_11->setText(iduserFromDB);
    QString FirstNamefromDB = query.value(1).toString();
    ui->plainTextEdit->setPlainText(FirstNamefromDB);
    QString LastNamefromDB = query.value(2).toString();
    ui->plainTextEdit_2->setPlainText(LastNamefromDB);
    QString PinfromDB = query.value(3).toString();
    ui->plainTextEdit_3->setPlainText(PinfromDB);
    QString  PermissionGroupfromDB =  query.value(4).toString();
    ui->plainTextEdit_4->setPlainText(PermissionGroupfromDB);
    int UserEnabledfromDB = query.value(5).toInt();
    if(UserEnabledfromDB == 1)ui->checkBox->setChecked(true);
    else ui->checkBox->setChecked(false);
    ui->label_9->setText(PrevRecordString);
/*
============================================================================================
Move Backward in database
============================================================================================
*/
}

void user_screen::on_pushButton_4_clicked()
{
/*
=========================================================================================================
Delete the current record
=========================================================================================================
*/
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->show();
    ui->pushButton_49->show();
    RecordModType = "delete";
/*
=======================================================================================================
End of Delete Current Record
=======================================================================================================
 */

}

void user_screen::on_pushButton_3_clicked()
{
/*
=======================================================================================================
Add New User
======================================================================================================
*/
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->show();
    ui->pushButton_49->show();
    RecordModType = "newuser";
/*
=====================================================================================================
End of Add New User
=====================================================================================================
*/

}

void user_screen::on_pushButton_49_clicked()
{
/*
======================================================================================================
Cancel Button
======================================================================================================
*/
    ui->pushButton_5->hide();
    ui->pushButton_49->hide();
    ui->pushButton->show();
    ui->pushButton_3->show();
    ui->pushButton_2->show();
    ui->pushButton_4->show();
    ui->listWidget->setVisible(false);
    ui->frame_4->setVisible(false);
    RecordModType = "";
/*
=====================================================================================================
End of Cancel Button
=====================================================================================================
*/
}

void user_screen::on_pushButton_5_clicked()
{
/*
=====================================================================================================
Save Button
=====================================================================================================
*/

//--------------------------------Delete current record----------------------------------------
    if (RecordModType == "delete")
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
     query.exec("DELETE FROM user WHERE iduser = " + iduserFromDB );
     query.next();
     QString pin_from_db = query.value(3).toString();
     QString FirstNamefromDB = query.value(1).toString();
     ui->plainTextEdit->setPlainText(FirstNamefromDB);
     QString LastNamefromDB = query.value(2).toString();
     ui->plainTextEdit_2->setPlainText(LastNamefromDB);
     QString PinfromDB = query.value(3).toString();
     ui->plainTextEdit_3->setPlainText(PinfromDB);
     QString  PermissionGroupfromDB =  query.value(4).toString();
     ui->plainTextEdit_4->setPlainText(PermissionGroupfromDB);
     int UserEnabledfromDB = query.value(5).toInt();
     if(UserEnabledfromDB == 1)ui->checkBox->setChecked(true);
     else ui->checkBox->setChecked(false);

     QSqlQuery query3;
     query3.exec("SELECT * FROM user");
     query3.first();
     iduserFromDB = query3.value(0).toString();
     ui->label_11->setText(iduserFromDB);
     FirstNamefromDB = query3.value(1).toString();
     ui->plainTextEdit->setPlainText(FirstNamefromDB);
     LastNamefromDB = query3.value(2).toString();
     ui->plainTextEdit_2->setPlainText(LastNamefromDB);
     PinfromDB = query3.value(3).toString();
     ui->plainTextEdit_3->setPlainText(PinfromDB);
     PermissionGroupfromDB =  query3.value(4).toString();
     ui->plainTextEdit_4->setPlainText(PermissionGroupfromDB);
     UserEnabledfromDB = query3.value(5).toInt();
     if(UserEnabledfromDB == 1)ui->checkBox->setChecked(true);
     else ui->checkBox->setChecked(false);

     RecordModType = "";
     ui->pushButton_5->hide();
     ui->pushButton_49->hide();
     ui->pushButton->show();
     ui->pushButton_3->show();
     ui->pushButton_2->show();
     ui->pushButton_4->show();
     ui->label_2->setText("User Deleted !!!");
     ui->frame_4->setVisible(false);
     return;
    }
//------------------------------------End of Delete Current Record-------------------------------
//--------------------------------Add New User record----------------------------------------
 if (RecordModType == "new")
 {
     ui->pushButton_5->hide();
     ui->pushButton_49->hide();
     ui->pushButton->show();
     ui->pushButton_3->show();
     ui->pushButton_2->show();
     ui->pushButton_4->show();
     return;
 }
//--------------------------------Add New User record----------------------------------------
//--------------------------------Edit current User record----------------------------------------

 if (RecordModType == "edit")
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
      QString first_name = ui->plainTextEdit->toPlainText();
      QString last_name = ui->plainTextEdit_2->toPlainText();
      QString pin_number = ui->plainTextEdit_3->toPlainText();
      QString permission_group = ui->plainTextEdit_4->toPlainText();
      QString user_enabled = "";

      if(!ui->checkBox->isChecked())
      {
           user_enabled = "0";
      }
          else  user_enabled ="1";

//------------------------------Record Sanity Check------------------------------------------

    if (pin_number.size() < 4)
    {
        QPalette pal = palette();
        ui->plainTextEdit_3->setFocus();
        ui->label_2->setText("PIN CODE MUST BE 4 DIGITS !!!");
        return;
    }

//---------------------------Do we need to Hash a new PIN number------------------------------
      if (pin_number.size() == 4)
      {
          QSqlQuery query1;
          query1.exec("SELECT MD5('" + pin_number + "')" );
          //qDebug() << pin_number;
          query1.next();
          QString MD5_Hash_from_db = query1.value(0).toString();
          //qDebug() << MD5_Hash_from_db;
          pin_number = MD5_Hash_from_db;
      }
//----------------------------New PIN Hashed and ready for Database-----------------------------


      query.exec("UPDATE user SET first_name = '" + first_name +"', last_name = '" + last_name + "', pin_number = '" +
                 pin_number + "', permission_group = '" + permission_group + "', user_enabled = '" + user_enabled +
                 "' WHERE iduser = '" + iduserFromDB + "'" );

     query.next();

//-----------------------------------Lets Reload Changes to Database------------------------------
     QSqlQuery query2;
     query2.exec("SELECT * FROM user");
     query2.first();

     iduserFromDB = query2.value(0).toString();
     ui->label_11->setText(iduserFromDB);

     QString FirstNamefromDB = query2.value(1).toString();
     ui->plainTextEdit->setPlainText(FirstNamefromDB);

     QString LastNamefromDB = query2.value(2).toString();
     ui->plainTextEdit_2->setPlainText(LastNamefromDB);

     QString PinfromDB = query2.value(3).toString();
     ui->plainTextEdit_3->setPlainText(PinfromDB);

     QString  PermissionGroupfromDB =  query2.value(4).toString();
     ui->plainTextEdit_4->setPlainText(PermissionGroupfromDB);

     int UserEnabledfromDB = query2.value(5).toInt();
     if(UserEnabledfromDB == 1)ui->checkBox->setChecked(true);
     else ui->checkBox->setChecked(false);

     RecordModType = "";
     RecordNumber = 0;
     ui->pushButton_5->hide();
     ui->pushButton_49->hide();
     ui->pushButton->show();
     ui->pushButton_3->show();
     ui->pushButton_2->show();
     ui->pushButton_4->show();
     ui->listWidget->setVisible(false);
     ui->label_2->setText("Edit Save ...");
     ui->frame_4->setVisible(false);
     return;
 }
//--------------------------------Edit current User record----------------------------------------


/*
==================================================================================================
End of Save Button
==================================================================================================
*/
}
/*
===================================================================================================
Keyboard Processing
===================================================================================================
*/
void user_screen::on_pushButton_35_clicked()
{
//-----------------------------------------Button 1------------------------------------------------
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


//----------------------------------------End Button 1---------------------------------------------
}

void user_screen::on_pushButton_36_clicked()
{
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
}

void user_screen::on_pushButton_37_clicked()
{
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
}

void user_screen::on_pushButton_38_clicked()
{
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
}

void user_screen::on_pushButton_39_clicked()
{
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
}

void user_screen::on_pushButton_40_clicked()
{
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
}

void user_screen::on_pushButton_41_clicked()
{
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
}

void user_screen::on_pushButton_42_clicked()
{
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
}

void user_screen::on_pushButton_43_clicked()
{
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
}

void user_screen::on_pushButton_44_clicked()
{
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
}

void user_screen::on_pushButton_6_clicked()
{
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

return;
}

void user_screen::on_pushButton_7_clicked()
{

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

return;
}

void user_screen::on_pushButton_8_clicked()
{
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

return;
}

void user_screen::on_pushButton_9_clicked()
{
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
        KeyBuff = KeyBuff + "rq";
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

return;
}

void user_screen::on_pushButton_10_clicked()
{
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

return;
}

void user_screen::on_pushButton_11_clicked()
{
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

return;
}

void user_screen::on_pushButton_12_clicked()
{
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

return;
}

void user_screen::on_pushButton_13_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "I";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "i";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "I";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "i";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "I";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "i";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_14_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "O";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "o";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "O";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "o";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "O";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "o";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_15_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "P";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "p";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "P";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "p";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "P";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "p";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_16_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "A";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "a";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "A";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "a";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "A";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "a";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_17_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "S";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "s";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "S";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "s";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "S";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "s";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_18_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "D";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "d";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "D";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "d";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "D";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "d";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_19_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "F";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "f";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "F";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "f";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "F";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "f";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_20_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "G";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "g";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "G";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "g";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "G";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "g";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_21_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "H";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "h";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "H";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "h";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "H";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "h";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_22_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "J";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "j";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "J";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "j";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "J";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "j";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_23_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "K";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "k";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "K";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "k";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "K";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "k";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_24_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "L";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "l";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "L";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "l";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "L";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "l";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_26_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Z";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "z";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Z";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "z";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "Z";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "z";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_27_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "X";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "x";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "X";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "x";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "X";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "x";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_28_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "C";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "c";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "C";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "c";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "C";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "c";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_29_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "V";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "v";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "V";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "v";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "V";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "v";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_30_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "B";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "b";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "B";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "b";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "B";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "b";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_31_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "N";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "n";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "N";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "n";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "N";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "n";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_32_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {

        QString KeyBuff = ui->plainTextEdit->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "M";
            ui->plainTextEdit->setPlainText(KeyBuff);
            return;
         }

         KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "m";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "M";
            ui->plainTextEdit_2->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "m";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        if(KeyBuff.size() == 0)
        {
            QString KeyBuff = "M";
            ui->plainTextEdit_4->setPlainText(KeyBuff);
            return;
         }

        KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "m";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }

return;
}

void user_screen::on_pushButton_33_clicked()
{
//--------------------------Handels the clear button--------------------------------------------------
    if (ui->plainTextEdit->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = "";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = "";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_3->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_3->toPlainText();
        KeyBuff = "";
        ui->plainTextEdit_3->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = "";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }
return;
}
//--------------------------End of the Clear Button------------------------------------------------------
void user_screen::on_pushButton_45_clicked()
{
//-------------------------Handels The Space Bar-------------------------------------------------
    if (ui->plainTextEdit->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + " ";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + " ";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + " ";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }
return;
}
//----------------------------End of Space Bar-----------------------------------------------------
void user_screen::on_pushButton_47_clicked()
{
//---------------------------Handels Tab Key-----------------------------------------------------

    if (ui->plainTextEdit->hasFocus())
    {
        ui->plainTextEdit_2->setFocus();
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_3->setFocus();
        return;
     }

    if (ui->plainTextEdit_3->hasFocus())
    {
        ui->plainTextEdit_4->setFocus();
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        ui->checkBox->setFocus();
        return;
    }

    if (ui->checkBox->hasFocus())
    {
        ui->plainTextEdit->setFocus();
        return;
    }

    return;
//-------------------------------End of Tab Key---------------------------------------------------
}

void user_screen::on_pushButton_25_clicked()
{
//------------------------------Handels Enter Key--------------------------------------------------
    if (ui->plainTextEdit->hasFocus())
    {
        ui->plainTextEdit_2->setFocus();
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_3->setFocus();
        return;
     }

    if (ui->plainTextEdit_3->hasFocus())
    {
        ui->plainTextEdit_4->setFocus();
        return;
     }

    if (ui->plainTextEdit_4->hasFocus())
    {
        ui->checkBox->setFocus();
        return;
    }

    if (ui->checkBox->hasFocus())
    {
        ui->plainTextEdit->setFocus();
        return;
    }
//--------------------------------------End of Enter Key--------------------------------------------
}
/*
=================================================================================================================
End of Keyboard Handeling
=================================================================================================================
 */
