#ifndef OVERRIDE_SCREEN_H
#define OVERRIDE_SCREEN_H

#include <QDialog>
#include <QGraphicsScene> //Need this for Images

namespace Ui {
class override_screen;
}

class override_screen : public QDialog
{
    Q_OBJECT

public:
    explicit override_screen(QWidget *parent = 0);
    ~override_screen();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_33_clicked();

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

    void on_pushButton_16_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::override_screen *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;



};

#endif // OVERRIDE_SCREEN_H
