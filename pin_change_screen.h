#ifndef PIN_CHANGE_SCREEN_H
#define PIN_CHANGE_SCREEN_H

#include <QDialog>
#include <QGraphicsScene> //Need this for Images
#include <QStyle>

namespace Ui {
class pin_change_screen;
}

class pin_change_screen : public QDialog
{
    Q_OBJECT

public:
    explicit pin_change_screen(QWidget *parent = 0);
    ~pin_change_screen();

private slots:
    void on_pushButton_2_clicked();

    void SaveAndExit();

    void LogEvent(QString EventID);

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

private:
    Ui::pin_change_screen *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;

};

#endif // PIN_CHANGE_SCREEN_H
