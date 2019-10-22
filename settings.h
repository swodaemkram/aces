#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QGraphicsScene> //Need this for Images

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_33_clicked();

private:
    Ui::settings *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;

};

#endif // SETTINGS_H
