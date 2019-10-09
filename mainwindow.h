#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene> //Need this for Images
#include <QtSerialPort/QtSerialPort>

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
#define BACKGROUNDIMAGE "./icons/B4.jpg"
#define SECONDBACKGROUNDIMAGE "./icons/background2.jpg"
#define REDBACKGROUNDIMAGE "./icons/B4RED.jpg"
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

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
    QTimer *DoorMonitorTimer;
};

#endif // MAINWINDOW_H
