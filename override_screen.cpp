#include "override_screen.h"
#include "ui_override_screen.h"
#include "mainwindow.h"
#include "user_screen.h"


#include <QMainWindow>
#include <QGraphicsScene> //Need this for Images
#include <QStyle>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QNetworkInterface>
#include <QtSql>



override_screen::override_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::override_screen)
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
      imageObject->load(BACKGROUNDOVERRIDE);       //   |
      image = QPixmap::fromImage(*imageObject); //   |
      scene = new QGraphicsScene(this);         //   |
      scene->addPixmap(image);                  //   |_______All this to display a picture
      scene->setSceneRect(image.rect());        //   |               WOW !
      ui->graphicsView->setScene(scene);        //   |
      imageObject = new QImage();
/*
==============================================================================================================
End of Load Background
==============================================================================================================
Start Making Unit ID to Make Magic Number with
==============================================================================================================
*/

//-------------------------------First thing we do is get the Mac Address------------------------------------
      QString MAC =  QNetworkInterface::interfaceFromIndex(2).hardwareAddress();
//---------------Then we will take only the last 3 octets and turn them around Least to most------------------
      QString NewMac = MAC.mid(15,2);
      NewMac = NewMac + MAC.mid(12,2);
      NewMac = NewMac + MAC.mid(9,2);
//----------------Then we will get the Day of the week and the hour of the day-------------------------------
//-------------------and add them to the end to create the unit I.D. for this day and hour-------------------
      int theDay;
      QString theDayString;
      theDay = QDate::currentDate().dayOfWeek();
      theDayString.setNum(theDay);
      int theHour;
      theHour = QTime::currentTime().hour();
      QString theHourString;
      theHourString.setNum(theHour);
      ui->label_3->setText(NewMac + theDayString + theHourString);
//--------------------------------End of creating unit I.D.------------------------------------------------

      ui->plainTextEdit->setFocus();
      ui->plainTextEdit->setStyleSheet("background-color: yellow");
}

override_screen::~override_screen()
{
    delete ui;
}

void override_screen::on_pushButton_2_clicked()
{
    close();
}
/*
=====================================================================================================
TAB KEY
=====================================================================================================
*/

void override_screen::on_pushButton_47_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        ui->plainTextEdit_2->setFocus();
        ui->plainTextEdit_2->setStyleSheet("background-color: yellow");
        ui->plainTextEdit->setStyleSheet("background-color: white");
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_3->setFocus();
        ui->plainTextEdit_3->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_2->setStyleSheet("background-color: white");
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        ui->plainTextEdit->setFocus();
        ui->plainTextEdit->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_3->setStyleSheet("background-color: white");
        return;
    }
}
/*
=====================================================================================================
END of TAB KEY
=====================================================================================================
Enter Key
=====================================================================================================
*/
void override_screen::on_pushButton_25_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        ui->plainTextEdit_2->setFocus();
        ui->plainTextEdit_2->setStyleSheet("background-color: yellow");
        ui->plainTextEdit->setStyleSheet("background-color: white");
        return;
    }

    if(ui->plainTextEdit_2->hasFocus())
    {
        ui->plainTextEdit_3->setFocus();
        ui->plainTextEdit_3->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_2->setStyleSheet("background-color: white");
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        ui->plainTextEdit->setFocus();
        ui->plainTextEdit->setStyleSheet("background-color: yellow");
        ui->plainTextEdit_3->setStyleSheet("background-color: white");
        return;
    }
}
/*
=====================================================================================================
End of Enter Key
=====================================================================================================
Clear Key
=====================================================================================================
*/

void override_screen::on_pushButton_33_clicked()
{
    if(ui->plainTextEdit->hasFocus())ui->plainTextEdit->setPlainText("");
    if(ui->plainTextEdit_2->hasFocus())ui->plainTextEdit_2->setPlainText("");
    if(ui->plainTextEdit_3->hasFocus())ui->plainTextEdit_3->setPlainText("");
}
/*
======================================================================================================
End of Clear Key
======================================================================================================
Button 1
======================================================================================================
*/

void override_screen::on_pushButton_35_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit->toPlainText() + "1";
        ui->plainTextEdit->setPlainText(Keybuff);
        return;
    }
    if(ui->plainTextEdit_2->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_2->toPlainText() + "1";
        ui->plainTextEdit_2->setPlainText(Keybuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "1";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }

}

void override_screen::on_pushButton_36_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit->toPlainText() + "2";
        ui->plainTextEdit->setPlainText(Keybuff);
        return;
    }
    if(ui->plainTextEdit_2->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_2->toPlainText() + "2";
        ui->plainTextEdit_2->setPlainText(Keybuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "2";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }

}

void override_screen::on_pushButton_37_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit->toPlainText() + "3";
        ui->plainTextEdit->setPlainText(Keybuff);
        return;
    }
    if(ui->plainTextEdit_2->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_2->toPlainText() + "3";
        ui->plainTextEdit_2->setPlainText(Keybuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "3";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }

}

void override_screen::on_pushButton_38_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit->toPlainText() + "4";
        ui->plainTextEdit->setPlainText(Keybuff);
        return;
    }
    if(ui->plainTextEdit_2->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_2->toPlainText() + "4";
        ui->plainTextEdit_2->setPlainText(Keybuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "4";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }

}

void override_screen::on_pushButton_39_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit->toPlainText() + "5";
        ui->plainTextEdit->setPlainText(Keybuff);
        return;
    }
    if(ui->plainTextEdit_2->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_2->toPlainText() + "5";
        ui->plainTextEdit_2->setPlainText(Keybuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "5";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }

}

void override_screen::on_pushButton_40_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit->toPlainText() + "6";
        ui->plainTextEdit->setPlainText(Keybuff);
        return;
    }
    if(ui->plainTextEdit_2->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_2->toPlainText() + "6";
        ui->plainTextEdit_2->setPlainText(Keybuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "6";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }

}

void override_screen::on_pushButton_41_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit->toPlainText() + "7";
        ui->plainTextEdit->setPlainText(Keybuff);
        return;
    }
    if(ui->plainTextEdit_2->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_2->toPlainText() + "7";
        ui->plainTextEdit_2->setPlainText(Keybuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "7";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }

}

void override_screen::on_pushButton_42_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit->toPlainText() + "8";
        ui->plainTextEdit->setPlainText(Keybuff);
        return;
    }
    if(ui->plainTextEdit_2->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_2->toPlainText() + "8";
        ui->plainTextEdit_2->setPlainText(Keybuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "8";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }

}

void override_screen::on_pushButton_43_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit->toPlainText() + "9";
        ui->plainTextEdit->setPlainText(Keybuff);
        return;
    }
    if(ui->plainTextEdit_2->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_2->toPlainText() + "9";
        ui->plainTextEdit_2->setPlainText(Keybuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "9";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }

}

void override_screen::on_pushButton_44_clicked()
{
    if(ui->plainTextEdit->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit->toPlainText() + "0";
        ui->plainTextEdit->setPlainText(Keybuff);
        return;
    }
    if(ui->plainTextEdit_2->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_2->toPlainText() + "0";
        ui->plainTextEdit_2->setPlainText(Keybuff);
        return;
    }

    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "0";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }

}

void override_screen::on_pushButton_16_clicked()
{
    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "a";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }
}

void override_screen::on_pushButton_30_clicked()
{
    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "b";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }
}

void override_screen::on_pushButton_28_clicked()
{
    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "c";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }
}

void override_screen::on_pushButton_18_clicked()
{
    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "d";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }
}

void override_screen::on_pushButton_8_clicked()
{
    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "e";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }
}

void override_screen::on_pushButton_19_clicked()
{
    if(ui->plainTextEdit_3->hasFocus())
    {
        QString Keybuff = ui->plainTextEdit_3->toPlainText() + "f";
        ui->plainTextEdit_3->setPlainText(Keybuff);
        return;
    }
}
/*
=================================================================================================================
End of Keyboard Handeling
=================================================================================================================
*/
void override_screen::on_pushButton_3_clicked()
{
    QString FigureMagicNumber = ui->label_3->text() + ui->plainTextEdit->toPlainText() + ui->plainTextEdit_2->toPlainText();
    //ui->plainTextEdit_3->setPlainText(FigureMagicNumber);

    QSqlDatabase db = QSqlDatabase::addDatabase(DATABASEDRIVER);
    db.setHostName(DATABASEURL);
    db.setDatabaseName(DATABASENAME);
    db.setUserName(DATABASEUSER);
    db.setPassword(DATABASEPASSWORD);
    db.open();

     QSqlQuery query;
     query.exec("SELECT MD5('" + FigureMagicNumber + "')" );
     //qDebug() << pin_number;
     query.next();
     QString MD5_Hash_from_db = query.value(0).toString();
     //ui->plainTextEdit_3->setPlainText(MD5_Hash_from_db);//DEBUG

//-------------------------------------We need one of these for each screen we will----------------------------
//------------------------------------Allow access to with this override---------------------------------------
//--------------------------------------Allow access to User Edit Screen---------------------------------------
     if (ui->plainTextEdit->toPlainText().compare("1") == 0 && MD5_Hash_from_db.compare(ui->plainTextEdit_3->toPlainText()) == 0)
     {
         user_screen user_screen;
         user_screen.setModal(true);
         user_screen.exec();
         close();
     }
//------------------------------------End of User Edit Override-------------------------------------------------
//------------------------------------Allow override to set date and time---------------------------------------
     if (ui->plainTextEdit->toPlainText().compare("2") == 0 && MD5_Hash_from_db.compare(ui->plainTextEdit_3->toPlainText()) == 0)
     {
         user_screen user_screen;
         user_screen.setModal(true);
         user_screen.exec();
         close();
     }
//-------------------------------------End of Time Date override------------------------------------------------

return;

}

/*
============================================================================================================================
Log Event
============================================================================================================================
*/

void override_screen::LogEvent(QString EventID)
{

    QString UserID = ui->plainTextEdit_2->toPlainText();

    QSqlDatabase db = QSqlDatabase::addDatabase(DATABASEDRIVER);
    db.setHostName(DATABASEURL);
    db.setDatabaseName(DATABASENAME);
    db.setUserName(DATABASEUSER);
    db.setPassword(DATABASEPASSWORD);
    db.open();

    QString event_date = QDate::currentDate().toString("yyyyMMdd");
    QString event_time = QTime::currentTime().toString();
    QSqlQuery query4;
    query4.exec("INSERT INTO event_log (event_user_id, event_date, event_time, event_code) VALUES ('"+ UserID + "','" + event_date + "','" + event_time + "','" + EventID + "')");
/*
============================================================================================================
End of Logging
============================================================================================================
*/
    db.close();
    return;
}
