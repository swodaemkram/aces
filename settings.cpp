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
        ui->plainTextEdit_10->setPlainText(query1.value(2).toString());
        query1.next();
        ui->plainTextEdit_2->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_11->setPlainText(query1.value(2).toString());
        query1.next();
        ui->plainTextEdit_3->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_12->setPlainText(query1.value(2).toString());
        query1.next();
        ui->plainTextEdit_4->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_13->setPlainText(query1.value(2).toString());
        query1.next();
        ui->plainTextEdit_5->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_14->setPlainText(query1.value(2).toString());
        query1.next();
        ui->plainTextEdit_6->setPlainText(query1.value(1).toString());
        ui->plainTextEdit_15->setPlainText(query1.value(2).toString());
        ui->plainTextEdit_7->setFocus();
        ui->plainTextEdit_7->setStyleSheet("background-color: yellow");
//---------------------------------------------End of loading screen--------------------------------------
}

settings::~settings()
{
    delete ui;
}

/*
==============================================================================================================
Exit Button
==============================================================================================================
*/
void settings::on_pushButton_clicked()
{
//---------------------------------------------Save Current Settings----------------------------------------
//--------------------------------------------Lets save System Data First-----------------------------------
    QSqlQuery query;
    QString force_pin_changed_check_box = "0";
    if (ui->checkBox->isChecked())force_pin_changed_check_box = "1";

    query.exec("UPDATE system_config SET days_before_pin_change = '" + ui->plainTextEdit_7->toPlainText() + "', door_alarm_delay = '"\
               + ui->plainTextEdit_8->toPlainText() + "', number_of_pin_digits = '" + ui->plainTextEdit_9->toPlainText()\
               + "', force_pin_change = '" + force_pin_changed_check_box + "' WHERE idsystem_config = '1'");
    query.next();
//-------------------------------------------End of Save Current Setting-------------------------------------
//----------------------------------------Save Changes to Lock Names and Delays------------------------------
    QSqlQuery query1;
    query1.exec("UPDATE door_setup SET door_name = '" + ui->plainTextEdit->toPlainText() + "', door_open_delay = '" + ui->plainTextEdit_10->toPlainText() +"' WHERE iddoor = '1'" );
    query1.next();
    query1.exec("UPDATE door_setup SET door_name = '" + ui->plainTextEdit_2->toPlainText() + "', door_open_delay = '" + ui->plainTextEdit_11->toPlainText() +"' WHERE iddoor = '2'" );
    query1.next();
    query1.exec("UPDATE door_setup SET door_name = '" + ui->plainTextEdit_3->toPlainText() + "', door_open_delay = '" + ui->plainTextEdit_12->toPlainText() +"' WHERE iddoor = '3'" );
    query1.next();
    query1.exec("UPDATE door_setup SET door_name = '" + ui->plainTextEdit_4->toPlainText() + "', door_open_delay = '" + ui->plainTextEdit_13->toPlainText() +"' WHERE iddoor = '4'" );
    query1.next();
    query1.exec("UPDATE door_setup SET door_name = '" + ui->plainTextEdit_5->toPlainText() + "', door_open_delay = '" + ui->plainTextEdit_14->toPlainText() +"' WHERE iddoor = '5'" );
    query1.next();
    query1.exec("UPDATE door_setup SET door_name = '" + ui->plainTextEdit_6->toPlainText() + "', door_open_delay = '" + ui->plainTextEdit_15->toPlainText() +"' WHERE iddoor = '6'" );
    query1.next();
//------------------------------------------End of saving lock names change----------------------------------
    close();
}
/*
==============================================================================================================
End of Exit Button
==============================================================================================================
*/
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
Keyboard Handler
=======================================================================================================================
*/
void settings::on_pushButton_35_clicked()
{
//----------------------------------------------------1 Key-----------------------------------------------------------
    if(ui->plainTextEdit->hasFocus())
    {
        QString buffer = ui->plainTextEdit->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_7->hasFocus())
    {
        QString buffer = ui->plainTextEdit_7->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_7->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        QString buffer = ui->plainTextEdit_8->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_8->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        QString buffer = ui->plainTextEdit_9->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_9->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        QString buffer = ui->plainTextEdit_10->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_10->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        QString buffer = ui->plainTextEdit_11->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_11->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        QString buffer = ui->plainTextEdit_12->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_12->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        QString buffer = ui->plainTextEdit_13->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_13->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        QString buffer = ui->plainTextEdit_14->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_14->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        QString buffer = ui->plainTextEdit_15->toPlainText();
        buffer = buffer + "1";
        ui->plainTextEdit_15->setPlainText(buffer);
        return;
    }

//----------------------------------------------------End of 1 Key----------------------------------------------------
}

void settings::on_pushButton_36_clicked()
{
//-----------------------------------------------------Key 2----------------------------------------------------------
    if(ui->plainTextEdit->hasFocus())
    {
        QString buffer = ui->plainTextEdit->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_7->hasFocus())
    {
        QString buffer = ui->plainTextEdit_7->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_7->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        QString buffer = ui->plainTextEdit_8->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_8->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        QString buffer = ui->plainTextEdit_9->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_9->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        QString buffer = ui->plainTextEdit_10->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_10->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        QString buffer = ui->plainTextEdit_11->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_11->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        QString buffer = ui->plainTextEdit_12->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_12->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        QString buffer = ui->plainTextEdit_13->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_13->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        QString buffer = ui->plainTextEdit_14->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_14->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        QString buffer = ui->plainTextEdit_15->toPlainText();
        buffer = buffer + "2";
        ui->plainTextEdit_15->setPlainText(buffer);
        return;
    }
//----------------------------------------------------End of Key 2----------------------------------------------------
}

void settings::on_pushButton_37_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString buffer = ui->plainTextEdit->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_7->hasFocus())
    {
        QString buffer = ui->plainTextEdit_7->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_7->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        QString buffer = ui->plainTextEdit_8->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_8->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        QString buffer = ui->plainTextEdit_9->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_9->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        QString buffer = ui->plainTextEdit_10->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_10->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        QString buffer = ui->plainTextEdit_11->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_11->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        QString buffer = ui->plainTextEdit_12->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_12->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        QString buffer = ui->plainTextEdit_13->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_13->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        QString buffer = ui->plainTextEdit_14->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_14->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        QString buffer = ui->plainTextEdit_15->toPlainText();
        buffer = buffer + "3";
        ui->plainTextEdit_15->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_38_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString buffer = ui->plainTextEdit->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_7->hasFocus())
    {
        QString buffer = ui->plainTextEdit_7->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_7->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        QString buffer = ui->plainTextEdit_8->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_8->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        QString buffer = ui->plainTextEdit_9->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_9->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        QString buffer = ui->plainTextEdit_10->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_10->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        QString buffer = ui->plainTextEdit_11->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_11->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        QString buffer = ui->plainTextEdit_12->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_12->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        QString buffer = ui->plainTextEdit_13->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_13->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        QString buffer = ui->plainTextEdit_14->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_14->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        QString buffer = ui->plainTextEdit_15->toPlainText();
        buffer = buffer + "4";
        ui->plainTextEdit_15->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_39_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString buffer = ui->plainTextEdit->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_7->hasFocus())
    {
        QString buffer = ui->plainTextEdit_7->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_7->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        QString buffer = ui->plainTextEdit_8->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_8->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        QString buffer = ui->plainTextEdit_9->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_9->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        QString buffer = ui->plainTextEdit_10->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_10->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        QString buffer = ui->plainTextEdit_11->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_11->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        QString buffer = ui->plainTextEdit_12->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_12->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        QString buffer = ui->plainTextEdit_13->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_13->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        QString buffer = ui->plainTextEdit_14->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_14->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        QString buffer = ui->plainTextEdit_15->toPlainText();
        buffer = buffer + "5";
        ui->plainTextEdit_15->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_40_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString buffer = ui->plainTextEdit->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_7->hasFocus())
    {
        QString buffer = ui->plainTextEdit_7->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_7->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        QString buffer = ui->plainTextEdit_8->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_8->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        QString buffer = ui->plainTextEdit_9->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_9->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        QString buffer = ui->plainTextEdit_10->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_10->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        QString buffer = ui->plainTextEdit_11->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_11->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        QString buffer = ui->plainTextEdit_12->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_12->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        QString buffer = ui->plainTextEdit_13->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_13->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        QString buffer = ui->plainTextEdit_14->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_14->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        QString buffer = ui->plainTextEdit_15->toPlainText();
        buffer = buffer + "6";
        ui->plainTextEdit_15->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_41_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString buffer = ui->plainTextEdit->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_7->hasFocus())
    {
        QString buffer = ui->plainTextEdit_7->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_7->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        QString buffer = ui->plainTextEdit_8->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_8->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        QString buffer = ui->plainTextEdit_9->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_9->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        QString buffer = ui->plainTextEdit_10->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_10->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        QString buffer = ui->plainTextEdit_11->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_11->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        QString buffer = ui->plainTextEdit_12->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_12->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        QString buffer = ui->plainTextEdit_13->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_13->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        QString buffer = ui->plainTextEdit_14->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_14->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        QString buffer = ui->plainTextEdit_15->toPlainText();
        buffer = buffer + "7";
        ui->plainTextEdit_15->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_42_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString buffer = ui->plainTextEdit->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_7->hasFocus())
    {
        QString buffer = ui->plainTextEdit_7->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_7->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        QString buffer = ui->plainTextEdit_8->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_8->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        QString buffer = ui->plainTextEdit_9->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_9->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        QString buffer = ui->plainTextEdit_10->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_10->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        QString buffer = ui->plainTextEdit_11->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_11->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        QString buffer = ui->plainTextEdit_12->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_12->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        QString buffer = ui->plainTextEdit_13->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_13->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        QString buffer = ui->plainTextEdit_14->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_14->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        QString buffer = ui->plainTextEdit_15->toPlainText();
        buffer = buffer + "8";
        ui->plainTextEdit_15->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_43_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString buffer = ui->plainTextEdit->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_7->hasFocus())
    {
        QString buffer = ui->plainTextEdit_7->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_7->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        QString buffer = ui->plainTextEdit_8->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_8->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        QString buffer = ui->plainTextEdit_9->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_9->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        QString buffer = ui->plainTextEdit_10->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_10->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        QString buffer = ui->plainTextEdit_11->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_11->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        QString buffer = ui->plainTextEdit_12->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_12->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        QString buffer = ui->plainTextEdit_13->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_13->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        QString buffer = ui->plainTextEdit_14->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_14->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        QString buffer = ui->plainTextEdit_15->toPlainText();
        buffer = buffer + "9";
        ui->plainTextEdit_15->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_44_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString buffer = ui->plainTextEdit->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_7->hasFocus())
    {
        QString buffer = ui->plainTextEdit_7->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_7->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_8->hasFocus())
    {
        QString buffer = ui->plainTextEdit_8->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_8->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_9->hasFocus())
    {
        QString buffer = ui->plainTextEdit_9->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_9->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_10->hasFocus())
    {
        QString buffer = ui->plainTextEdit_10->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_10->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_11->hasFocus())
    {
        QString buffer = ui->plainTextEdit_11->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_11->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_12->hasFocus())
    {
        QString buffer = ui->plainTextEdit_12->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_12->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_13->hasFocus())
    {
        QString buffer = ui->plainTextEdit_13->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_13->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_14->hasFocus())
    {
        QString buffer = ui->plainTextEdit_14->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_14->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_15->hasFocus())
    {
        QString buffer = ui->plainTextEdit_15->toPlainText();
        buffer = buffer + "0";
        ui->plainTextEdit_15->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_6_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Q";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "q";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Q";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "q";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Q";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "q";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Q";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "q";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Q";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "q";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Q";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "q";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_7_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "W";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "w";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "W";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "w";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "W";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "w";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "W";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "w";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "W";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "w";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "W";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "w";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_8_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "E";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "e";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "E";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "e";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "E";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "e";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "E";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "e";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "E";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "e";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "E";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "e";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_9_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "R";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "r";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "R";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "r";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "R";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "r";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "R";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "r";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "R";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "r";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "R";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "r";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_10_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "T";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "t";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "T";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "t";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "T";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "t";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "T";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "t";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "T";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "t";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "T";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "t";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_11_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Y";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "y";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Y";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "y";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Y";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "y";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Y";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "y";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Y";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "y";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Y";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "y";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_12_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "U";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "u";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "U";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "u";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "U";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "u";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "U";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "u";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "U";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "u";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "U";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "u";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_13_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "I";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "i";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "I";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "i";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "I";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "i";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "I";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "i";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "I";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "i";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "I";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "i";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_14_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "O";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "o";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "O";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "o";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "O";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "o";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "O";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "o";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "O";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "o";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "O";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "o";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_15_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "P";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "p";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "P";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "p";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "P";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "p";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "P";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "p";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "P";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "p";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "P";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "p";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_16_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "A";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "a";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "A";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "a";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "A";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "a";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "A";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "a";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "A";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "a";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "A";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "a";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_17_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "S";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "s";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "S";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "s";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "S";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "s";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "S";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "s";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "S";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "s";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "S";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "s";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_18_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "D";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "d";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "D";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "d";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "D";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "d";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "D";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "d";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "D";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "d";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "D";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "d";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_19_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "F";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "f";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "F";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "f";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "F";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "f";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "F";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "f";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "F";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "f";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "F";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "f";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_20_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "G";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "g";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "G";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "g";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "G";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "g";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "G";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "g";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "G";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "g";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "G";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "g";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_21_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "H";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "h";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "H";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "h";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "H";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "h";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "H";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "h";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "H";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "h";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "H";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "h";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_22_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "J";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "j";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "J";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "j";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "J";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "j";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "J";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "j";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "J";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "j";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "J";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "j";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_23_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "K";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "k";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "K";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "k";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "K";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "k";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "K";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "k";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "K";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "k";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "K";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "k";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_24_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "L";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "l";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "L";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "l";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "L";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "l";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "L";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "l";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "L";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "l";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "L";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "l";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_26_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Z";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "z";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Z";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "z";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Z";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "z";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Z";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "z";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Z";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "z";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "Z";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "z";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_27_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "X";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "x";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "X";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "x";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "X";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "x";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "X";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "x";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "X";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "x";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "X";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "x";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_28_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "C";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "c";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "C";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "c";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "C";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "c";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "C";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "c";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "C";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "c";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "C";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "c";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_29_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "V";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "v";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "V";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "v";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "V";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "v";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "V";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "v";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "V";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "v";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "V";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "v";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_30_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "B";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "b";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "B";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "b";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "B";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "b";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "B";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "b";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "B";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "b";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "B";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "b";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_31_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "N";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "n";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "N";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "n";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "N";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "n";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "N";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "n";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "N";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "n";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "N";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "n";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_32_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "M";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + "m";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "M";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + "m";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "M";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + "m";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "M";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + "m";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "M";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + "m";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + "M";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + "m";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}

void settings::on_pushButton_45_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {

        QString buffer = ui->plainTextEdit->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + " ";
            ui->plainTextEdit->setPlainText(buffer);
            return;
        }
        buffer = buffer + " ";
        ui->plainTextEdit->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        QString buffer = ui->plainTextEdit_2->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + " ";
            ui->plainTextEdit_2->setPlainText(buffer);
            return;
        }
        buffer = buffer + " ";
        ui->plainTextEdit_2->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString buffer = ui->plainTextEdit_3->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + " ";
            ui->plainTextEdit_3->setPlainText(buffer);
            return;
        }
        buffer = buffer + " ";
        ui->plainTextEdit_3->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_4->hasFocus())
    {
        QString buffer = ui->plainTextEdit_4->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + " ";
            ui->plainTextEdit_4->setPlainText(buffer);
            return;
        }
        buffer = buffer + " ";
        ui->plainTextEdit_4->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_5->hasFocus())
    {
        QString buffer = ui->plainTextEdit_5->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + " ";
            ui->plainTextEdit_5->setPlainText(buffer);
            return;
        }
        buffer = buffer + " ";
        ui->plainTextEdit_5->setPlainText(buffer);
        return;
    }

    if(ui->plainTextEdit_6->hasFocus())
    {
        QString buffer = ui->plainTextEdit_6->toPlainText();
        if(buffer.size() == 0)
        {
            buffer = buffer + " ";
            ui->plainTextEdit_6->setPlainText(buffer);
            return;
        }
        buffer = buffer + " ";
        ui->plainTextEdit_6->setPlainText(buffer);
        return;
    }
}
