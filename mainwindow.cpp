#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lock_screen.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QtSql>
#include <unistd.h>

QString UserID;
QString Pin;
QString Validatae;
QString HideText;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
  imageObject = new QImage();

/*
===============================================================================================================
Update Clock Timer
===============================================================================================================
*/
QTimer *timer;
timer = new QTimer;
connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));
timer->start(500);
/*
====================================================================================================================
End of Update Clock Timer
====================================================================================================================
Lets connect to the database
====================================================================================================================
 */

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
db.setHostName("localhost");
db.setDatabaseName("aces");
db.setUserName("root");
db.setPassword("b0whunter");

if (!db.open())
{
     ui->label_4->setText("Unable to connect to database !!!");
    return;
}
 ui->label_4->setText("Connected to database....");
db.close();


 /*
====================================================================================================
   End of connecting to Database
====================================================================================================
*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}

/*
====================================================================================================
Clock Display
====================================================================================================
*/
void MainWindow::MyTimerSlot()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss    ");
    ui->lcdNumber->display(text);
}
/*
===================================================================================================
End of Clock Display
===================================================================================================
Keypad Code
===================================================================================================
*/


void MainWindow::on_pushButton_2_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "1";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "1";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "1";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_3_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "2";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "2";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "2";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_4_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "3";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "3";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "3";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_6_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "4";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "4";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "4";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_7_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "5";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "5";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "5";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_8_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "6";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "6";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "6";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_10_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "7";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "7";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "7";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_11_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "8";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "8";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "8";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_12_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "9";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "9";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "9";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_15_clicked()
{
    if (ui->plainTextEdit->hasFocus() )
    {

        if (UserID.length() == 4)
        {
           ui->plainTextEdit_2->setFocus();
           Pin = Pin + "0";
           HideText = HideText + "*";
           ui->plainTextEdit_2->setPlainText(HideText);
           return;
        }
        UserID = UserID + "0";
        ui->plainTextEdit->setPlainText(UserID);

    }

    if (ui->plainTextEdit_2->hasFocus() )
    {
        Pin = Pin + "0";
        HideText = HideText + "*";
        ui->plainTextEdit_2->setPlainText(HideText);
     }

    if (Pin.length() ==4) ValidateUser();

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->plainTextEdit->setPlainText("");
    ui->plainTextEdit_2->setPlainText("");
    HideText = "";
    UserID = "";
    Pin = "";
    ui->label_4->setText("");
    ui->plainTextEdit->setFocus();
}
/*
====================================================================================================
End of Keypad Code
====================================================================================================
Lets validate user with database
====================================================================================================
*/
void MainWindow::ValidateUser()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("aces");
    db.setUserName("root");
    db.setPassword("b0whunter");

    if (!db.open())
    {
         ui->label_4->setText("Unable to connect to database !!!");
        return;
    }
     ui->label_4->setText("Connected to database again....");


     QSqlQuery query;
     query.exec("SELECT * FROM user WHERE iduser = " + UserID);
     query.next();
     QString pin_from_db = query.value(3).toString();
     //ui->label_4->setText(pin_from_db);
     int user_enabled_from_db = query.value(5).toInt();
     db.close();

/*
=================================================================================================================
Is User Enabled
=================================================================================================================
*/

     if (!user_enabled_from_db)
     {
         ui->plainTextEdit->setPlainText("");
         ui->plainTextEdit_2->setPlainText("");
         HideText = "";
         UserID = "";
         Pin = "";
         ui->label_4->setText("User Not Enabled !!!");
         ui->plainTextEdit->setFocus();
        return;
     }
/*
================================================================================================================
Is PIN Correct
================================================================================================================
*/

     if(Pin == pin_from_db)
     {
        ui->plainTextEdit->setPlainText("");
        ui->plainTextEdit_2->setPlainText("");
        HideText = "";
        //UserID = "";
        Pin = "";
        lock_screen lock_screen;
        lock_screen.setModal(true);
        lock_screen.exec();
        ui->label_4->setText("");
        ui->plainTextEdit->setFocus();
        UserID="";
        return;
     }
/*
==============================================================================================================
Planed Fall Through
==============================================================================================================
*/

     ui->plainTextEdit->setPlainText("");
     ui->plainTextEdit_2->setPlainText("");
     HideText = "";
     UserID = "";
     Pin = "";
     ui->label_4->setText("Validation Error !!!");
     ui->plainTextEdit->setFocus();


}
/*
===================================================================================================
End of Validate user
===================================================================================================
*/
