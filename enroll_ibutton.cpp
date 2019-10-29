#include "enroll_ibutton.h"
#include "ui_enroll_ibutton.h"
#include "mainwindow.h"
#include "user_screen.h"

#include <QtSql>
#include <QStyle>
#include <QDesktopWidget>

int vim_serial_open_enroll = 0;
int is_vim_enabled_enroll = 0;
QString DataFromVIM_enroll = "";

enroll_ibutton::enroll_ibutton(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enroll_ibutton)
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
              imageObject->load("./icons/iButton.jpg"); //   |
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
Open Serial Port
==============================================================================================================
*/

              if(vim_serial_open_enroll == 0)open_commport();

//-------------------------------------------Setup Timer------------------------------------------------------
              get_ibutton_Data_timer = new QTimer;
              connect(get_ibutton_Data_timer, SIGNAL(timeout()), this, SLOT(get_ibutton_Data()));
              get_ibutton_Data_timer->start(500);
//----------------------------------------End of Timer--------------------------------------------------------

}

enroll_ibutton::~enroll_ibutton()
{
    delete ui;
}

void enroll_ibutton::on_pushButton_clicked()
{
    get_ibutton_Data_timer->stop();
    vim_serial->close();
    vim_serial_open_enroll = 0;
    close();
}
/*
=============================================================================================================
Open VIM Comm Port
=============================================================================================================
*/
void enroll_ibutton::open_commport()
{
    if(vim_serial_open_enroll == 0)
    {
    vim_serial = new QSerialPort(this);//----Instanciate VIM Com port
    qDebug() << "open VIM Comm Port";
    vim_serial->setPortName("/dev/ttyACM2");
    vim_serial->setBaudRate(QSerialPort::Baud115200);
    vim_serial->setDataBits(QSerialPort::Data8);
    vim_serial->setParity(QSerialPort::NoParity);
    vim_serial->setStopBits(QSerialPort::OneStop);
    vim_serial->setFlowControl(QSerialPort::NoFlowControl);

    if (vim_serial->open(QIODevice::ReadWrite))
     {

     ui->label_2->setText("VIM Connected");
       vim_serial_open_enroll = 1;
       return;
    }

    else
    {

    ui->label_2->setText("VIM Connection Error");
       vim_serial_open_enroll = 0;
    }

    }
    qDebug() << "VIM Connected = " + vim_serial_open_enroll;
return;
}
/*
=============================================================================================================
End Open VIM Comm Port
=============================================================================================================
Get iButton Data
=============================================================================================================
*/
void enroll_ibutton::get_ibutton_Data()
{
//------------------------------------------------Read Key---------------------------------------------------
    QString data8 = "";
      if(is_vim_enabled_enroll == 0)
    {
        vim_serial->write("E;");//IF the VIM is not enabled, Enable it
        is_vim_enabled_enroll = 1;
        //qDebug() << "VIM is now Enabled";
        while(vim_serial->bytesAvailable()>0||vim_serial->waitForReadyRead(10))
        {
           data8 = vim_serial->readAll();
        }
        //qDebug() << data7;
        return;
    }

     vim_serial->write("I;");//Send Show Me the Key
     while(vim_serial->bytesAvailable()>0||vim_serial->waitForReadyRead(10))
    {
       data8 = vim_serial->readAll();
     }
    //qDebug() << data8;
    vim_serial->write(";");//The VIM WILL NOT WORK WITHOUT THIS !!!
//----------------------------IF THE VIM RESPONSE IS NOT "ffffffffffffffff;" then process the number-------
//------------------------------Or VIM response is not "" or "OK;"-----------------------------------------
    DataFromVIM_enroll = data8;
    if(DataFromVIM_enroll == "OK;" || DataFromVIM_enroll == "" || DataFromVIM_enroll == "ffffffffffffffff;") return;
    qDebug() << DataFromVIM_enroll;
//---------------------------------We now have the new key code--------------------------------------------
    vim_serial->close();
    get_ibutton_Data_timer->stop();
    vim_serial_open_enroll = 0;

    close();
}
/*
===============================================================================================================
End of Get iButton Data
===============================================================================================================
*/
