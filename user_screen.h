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

private:
    Ui::user_screen *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;


};

#endif // USER_SCREEN_H
