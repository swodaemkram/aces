#include "networksettings.h"
#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include "set_time_screen.h"
#include <QtSql>
#include <QStyle>
#include <QDesktopWidget>

extern QString UserID;

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
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
              imageObject->load(SETTINGSBACKGROUND);    //   |
              image = QPixmap::fromImage(*imageObject); //   |
              scene = new QGraphicsScene(this);         //   |
              scene->addPixmap(image);                  //   |_______All this to display a picture
              scene->setSceneRect(image.rect());        //   |               WOW !
              ui->graphicsView->setScene(scene);        //   |
              imageObject = new QImage();
              //ui->frame_4->hide();
/*
==============================================================================================================
Background is loaded
==============================================================================================================
Connect to database
==============================================================================================================
*/

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
=============================================================================================================
Connect to table and pull first query
=============================================================================================================
*/
         QSqlQuery query;
         query.exec("SELECT * FROM system_config");
         query.first();
//--------------------------------------Lets load the system settings first--------------------------------
         ui->plainTextEdit_7->setPlainText(query.value(2).toString());
         if(query.value(4).toString() == "1")
         {
            ui->checkBox->setChecked(true);
         }
         ui->plainTextEdit_9->setPlainText(query.value(3).toString());
         ui->plainTextEdit_8->setPlainText(query.value(5).toString());
//-----------------------------------------Now Lets Load The Door Settings---------------------------------
        QSqlQuery query1;
        query1.exec("SELECT * FROM door_setup");
        query1.first();
        ui->plainTextEdit->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_10->setPlainText(query1.value(3).toString());
        query1.next();
        ui->plainTextEdit_2->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_11->setPlainText(query1.value(3).toString());
        query1.next();
        ui->plainTextEdit_3->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_12->setPlainText(query1.value(3).toString());
        query1.next();
        ui->plainTextEdit_4->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_13->setPlainText(query1.value(3).toString());
        query1.next();
        ui->plainTextEdit_5->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_14->setPlainText(query1.value(3).toString());
        query1.next();
        ui->plainTextEdit_6->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_15->setPlainText(query1.value(3).toString());
        ui->plainTextEdit_7->setFocus();
        ui->plainTextEdit_7->setStyleSheet("background-color: yellow");
//---------------------------------------------End of loading screen--------------------------------------
}

settings::~settings()
{
    delete ui;
}

void settings::on_pushButton_clicked()
{
    close();
}

void settings::on_pushButton_2_clicked()
{
/*
=============================================================================================================
Set Time and Date
=============================================================================================================
*/
//------------------------------------------------------Log Event--------------------------------------------------------
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
         ui->label_2->setText("Connected to database again....");
         QString event_date = QDate::currentDate().toString("yyyyMMdd");
         QString event_time = QTime::currentTime().toString();
         QSqlQuery query4;
         query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + "37" + "')");
//-----------------------------------------------------------Log Event-------------------------------------------------------
         set_time_screen set_time_screen;
         set_time_screen.setModal(true);
         set_time_screen.exec();
}
/*
=================================================================================================================
End Of Set time
=================================================================================================================
Setup Network
=================================================================================================================
*/
void settings::on_pushButton_3_clicked()
{
    NetworkSettings NetworkSettings;
    NetworkSettings.setModal(true);
    NetworkSettings.exec();
}
/*
================================================================================================================
End of Setup Network
================================================================================================================
*/
/*
================================================================================================================
Tab Key
================================================================================================================
*/
void settings::on_pushButton_47_clicked()
{
    if(ui->plainTextEdit_7->hasFocus())
    {
        ui->checkBox->setFocus();
        ui->checkBox->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_7->setStyleSheet("background-color: white");
        return;
    }

    if(ui->checkBox->hasFocus())
    {
        ui->plainTextEdit->setFocus();
        ui->checkBox->setStyleSheet("background-color: white");
        ui->plainTextEdit->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit->hasFocus())
    {
        ui->plainTextEdit_10->setFocus();
        ui->plainTextEdit->setStyleSheet("background-color: white");
        ui->plainTextEdit_10->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        ui->plainTextEdit_2->setFocus();
        ui->plainTextEdit_10->setStyleSheet("background-color: white");
        ui->plainTextEdit_2->setStyleSheet("background-color: yellow");
        return;
    }


    if(ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_11->setFocus();
        ui->plainTextEdit_2->setStyleSheet("background-color: white");
        ui->plainTextEdit_11->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        ui->plainTextEdit_3->setFocus();
        ui->plainTextEdit_11->setStyleSheet("background-color: white");
        ui->plainTextEdit_3->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        ui->plainTextEdit_12->setFocus();
        ui->plainTextEdit_3->setStyleSheet("background-color: white");
        ui->plainTextEdit_12->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        ui->plainTextEdit_4->setFocus();
        ui->plainTextEdit_12->setStyleSheet("background-color: white");
        ui->plainTextEdit_4->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        ui->plainTextEdit_13->setFocus();
        ui->plainTextEdit_4->setStyleSheet("background-color: white");
        ui->plainTextEdit_13->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        ui->plainTextEdit_5->setFocus();
        ui->plainTextEdit_13->setStyleSheet("background-color: white");
        ui->plainTextEdit_5->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        ui->plainTextEdit_14->setFocus();
        ui->plainTextEdit_5->setStyleSheet("background-color: white");
        ui->plainTextEdit_14->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        ui->plainTextEdit_6->setFocus();
        ui->plainTextEdit_14->setStyleSheet("background-color: white");
        ui->plainTextEdit_6->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        ui->plainTextEdit_15->setFocus();
        ui->plainTextEdit_6->setStyleSheet("background-color: white");
        ui->plainTextEdit_15->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        ui->plainTextEdit_9->setFocus();
        ui->plainTextEdit_15->setStyleSheet("background-color: white");
        ui->plainTextEdit_9->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        ui->plainTextEdit_8->setFocus();
        ui->plainTextEdit_9->setStyleSheet("background-color: white");
        ui->plainTextEdit_8->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        ui->plainTextEdit_7->setFocus();
        ui->plainTextEdit_8->setStyleSheet("background-color: white");
        ui->plainTextEdit_7->setStyleSheet("background-color: yellow");
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
void settings::on_pushButton_25_clicked()
{
    if(ui->plainTextEdit_7->hasFocus())
    {
        ui->checkBox->setFocus();
        ui->checkBox->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_7->setStyleSheet("background-color: white");
        return;
    }

    if(ui->checkBox->hasFocus())
    {
        ui->plainTextEdit->setFocus();
        ui->checkBox->setStyleSheet("background-color: white");
        ui->plainTextEdit->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit->hasFocus())
    {
        ui->plainTextEdit_10->setFocus();
        ui->plainTextEdit->setStyleSheet("background-color: white");
        ui->plainTextEdit_10->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        ui->plainTextEdit_2->setFocus();
        ui->plainTextEdit_10->setStyleSheet("background-color: white");
        ui->plainTextEdit_2->setStyleSheet("background-color: yellow");
        return;
    }


    if(ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_11->setFocus();
        ui->plainTextEdit_2->setStyleSheet("background-color: white");
        ui->plainTextEdit_11->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        ui->plainTextEdit_3->setFocus();
        ui->plainTextEdit_11->setStyleSheet("background-color: white");
        ui->plainTextEdit_3->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        ui->plainTextEdit_12->setFocus();
        ui->plainTextEdit_3->setStyleSheet("background-color: white");
        ui->plainTextEdit_12->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        ui->plainTextEdit_4->setFocus();
        ui->plainTextEdit_12->setStyleSheet("background-color: white");
        ui->plainTextEdit_4->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        ui->plainTextEdit_13->setFocus();
        ui->plainTextEdit_4->setStyleSheet("background-color: white");
        ui->plainTextEdit_13->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        ui->plainTextEdit_5->setFocus();
        ui->plainTextEdit_13->setStyleSheet("background-color: white");
        ui->plainTextEdit_5->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        ui->plainTextEdit_14->setFocus();
        ui->plainTextEdit_5->setStyleSheet("background-color: white");
        ui->plainTextEdit_14->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        ui->plainTextEdit_6->setFocus();
        ui->plainTextEdit_14->setStyleSheet("background-color: white");
        ui->plainTextEdit_6->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        ui->plainTextEdit_15->setFocus();
        ui->plainTextEdit_6->setStyleSheet("background-color: white");
        ui->plainTextEdit_15->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        ui->plainTextEdit_9->setFocus();
        ui->plainTextEdit_15->setStyleSheet("background-color: white");
        ui->plainTextEdit_9->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        ui->plainTextEdit_8->setFocus();
        ui->plainTextEdit_9->setStyleSheet("background-color: white");
        ui->plainTextEdit_8->setStyleSheet("background-color: yellow");
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        ui->plainTextEdit_7->setFocus();
        ui->plainTextEdit_8->setStyleSheet("background-color: white");
        ui->plainTextEdit_7->setStyleSheet("background-color: yellow");
        return;
    }
}
/*
========================================================================================================================
The End of the Enter Key
=========================================================================================================================
Clear Key
========================================================================================================================
*/
void settings::on_pushButton_33_clicked()
{
    if(ui->plainTextEdit_7->hasFocus())ui->plainTextEdit_7->setPlainText("");
    if(ui->checkBox->hasFocus()) ui->checkBox->setChecked(false);
    if(ui->plainTextEdit->hasFocus())ui->plainTextEdit->setPlainText("");
    if(ui->plainTextEdit_10->hasFocus())ui->plainTextEdit_10->setPlainText("");
    if(ui->plainTextEdit_2->hasFocus())ui->plainTextEdit_2->setPlainText("");
    if(ui->plainTextEdit_11->hasFocus())ui->plainTextEdit_11->setPlainText("");
    if(ui->plainTextEdit_3->hasFocus())ui->plainTextEdit_3->setPlainText("");
    if(ui->plainTextEdit_12->hasFocus())ui->plainTextEdit_12->setPlainText("");
    if(ui->plainTextEdit_4->hasFocus())ui->plainTextEdit_4->setPlainText("");
    if(ui->plainTextEdit_13->hasFocus())ui->plainTextEdit_13->setPlainText("");
    if(ui->plainTextEdit_5->hasFocus())ui->plainTextEdit_5->setPlainText("");
    if(ui->plainTextEdit_14->hasFocus())ui->plainTextEdit_14->setPlainText("");
    if(ui->plainTextEdit_6->hasFocus())ui->plainTextEdit_6->setPlainText("");
    if(ui->plainTextEdit_15->hasFocus())ui->plainTextEdit_15->setPlainText("");
    if(ui->plainTextEdit_9->hasFocus())ui->plainTextEdit_9->setPlainText("");
    if(ui->plainTextEdit_8->hasFocus())ui->plainTextEdit_8->setPlainText("");
}
/*
=======================================================================================================================
End Of Clear Key
=======================================================================================================================
*/
