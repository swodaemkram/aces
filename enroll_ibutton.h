#ifndef ENROLL_IBUTTON_H
#define ENROLL_IBUTTON_H

#include <QDialog>
#include <QDialog>
#include <QGraphicsScene> //Need this for Images
#include <QtSerialPort/QtSerialPort>

namespace Ui {
class enroll_ibutton;
}

class enroll_ibutton : public QDialog
{
    Q_OBJECT

public:
    explicit enroll_ibutton(QWidget *parent = 0);
    ~enroll_ibutton();

private slots:
    void on_pushButton_clicked();
    void open_commport();
    void get_ibutton_Data();



private:
    Ui::enroll_ibutton *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
    QSerialPort *vim_serial;
    QTimer *get_ibutton_Data_timer;
};

#endif // ENROLL_IBUTTON_H
