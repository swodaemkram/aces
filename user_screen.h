#ifndef USER_SCREEN_H
#define USER_SCREEN_H

#include <QDialog>
#include <QGraphicsScene> //Need this for Images

namespace Ui {
class user_screen;
}

class user_screen : public QDialog
{
    Q_OBJECT

public:
    explicit user_screen(QWidget *parent = 0);
    ~user_screen();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::user_screen *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;


};

#endif // USER_SCREEN_H
