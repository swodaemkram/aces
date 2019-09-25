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
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_3->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_3->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_3->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "q";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }
}

void user_screen::on_pushButton_7_clicked()
{

if (ui->plainTextEdit->hasFocus())
{
    QString KeyBuff = ui->plainTextEdit->toPlainText();
    KeyBuff = KeyBuff + "w";
    ui->plainTextEdit->setPlainText(KeyBuff);
    return;
}

if (ui->plainTextEdit_2->hasFocus())
{
    QString KeyBuff = ui->plainTextEdit_2->toPlainText();
    KeyBuff = KeyBuff + "w";
    ui->plainTextEdit_2->setPlainText(KeyBuff);
    return;
 }

if (ui->plainTextEdit_3->hasFocus())
{
    QString KeyBuff = ui->plainTextEdit_3->toPlainText();
    KeyBuff = KeyBuff + "w";
    ui->plainTextEdit_3->setPlainText(KeyBuff);
    return;
}

if (ui->plainTextEdit_4->hasFocus())
{
    QString KeyBuff = ui->plainTextEdit_4->toPlainText();
    KeyBuff = KeyBuff + "w";
    ui->plainTextEdit_4->setPlainText(KeyBuff);
    return;
}
}

void user_screen::on_pushButton_8_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "e";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "e";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_3->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_3->toPlainText();
        KeyBuff = KeyBuff + "e";
        ui->plainTextEdit_3->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "e";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }
}

void user_screen::on_pushButton_9_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "r";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "r";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_3->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_3->toPlainText();
        KeyBuff = KeyBuff + "r";
        ui->plainTextEdit_3->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "r";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }
}

void user_screen::on_pushButton_10_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_3->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_3->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_3->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "t";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }
}

void user_screen::on_pushButton_11_clicked()
{
    if (ui->plainTextEdit->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_2->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_2->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_2->setPlainText(KeyBuff);
        return;
     }

    if (ui->plainTextEdit_3->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_3->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_3->setPlainText(KeyBuff);
        return;
    }

    if (ui->plainTextEdit_4->hasFocus())
    {
        QString KeyBuff = ui->plainTextEdit_4->toPlainText();
        KeyBuff = KeyBuff + "y";
        ui->plainTextEdit_4->setPlainText(KeyBuff);
        return;
    }
}
