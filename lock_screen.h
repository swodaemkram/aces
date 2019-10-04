#ifndef LOCK_SCREEN_H
#define LOCK_SCREEN_H

#include <QDialog>
#include <QGraphicsScene> //Need this for Images
#include <QtSerialPort/QtSerialPort>
#include <QChar>

namespace Ui {
class lock_screen;
}

class lock_screen : public QDialog
{
    Q_OBJECT

public:
    explicit lock_screen(QWidget *parent = 0);
    ~lock_screen();
    QSerialPort *lock1_serial;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void open_Lock1_SerialPort();

    void close_Lock1_SerialPort();

    void writeData_lock1(const QByteArray &data);

    QByteArray readData_lock1();

    std::string genkey(const char* challenge);

    char* rot(char b[], char seed);

    void on_pushButton_6_clicked();

    void MyTimerSlot();

private:
    Ui::lock_screen *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;


};

#endif // LOCK_SCREEN_H
