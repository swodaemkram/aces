#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene> //Need this for Images
#include <QtSerialPort/QtSerialPort>
#include <QtMultimedia/QMediaPlayer> //sound
/*
==============================================================================================================
Definitions
==============================================================================================================
*/
#define DATABASEDRIVER "QMYSQL"
#define DATABASEURL "localhost"
#define DATABASEUSER "root"
#define DATABASEPASSWORD "b0whunter"
#define DATABASENAME "aces"
#define BACKGROUNDIMAGE "./icons/fire.jpg"
//#define BACKGROUNDIMAGE "./icons/B4.jpg"
#define SECONDBACKGROUNDIMAGE "./icons/background2.jpg"
#define REDBACKGROUNDIMAGE "./icons/B4RED.jpg"
#define SETTINGSBACKGROUND "./icons/settingsbackground.jpg"
#define BACKGROUNDOVERRIDE "./icons/B0.jpg"
#define HELPICON "./icons/Help_Circle_Blue.png"
#define REPORTHEADER "./icons/yum.jpg"

/*
==============================================================================================================
End Definitions
==============================================================================================================
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QSerialPort *lock1_serial;
    QSerialPort *lock2_serial;
    QSerialPort *vim_serial;

private slots:
    void on_pushButton_clicked();

    void MyTimerSlot();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void ValidateUser();

    void DoorMonitorTimerSlot();

    void Open_Lock1_SerialPort();

    void Open_Lock2_SerialPort();

    void on_pushButton_16_clicked();

    void on_pushButton_5_clicked();

    void LogEvent(QString EventID);

    void open_vim_serial();

    void vim_comm();

    void lock2_comm();

    void lock1_comm();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
    QTimer *DoorMonitorTimer;
    QMediaPlayer *player;

};

#endif // MAINWINDOW_H
