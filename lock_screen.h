#ifndef LOCK_SCREEN_H
#define LOCK_SCREEN_H

#include <QDialog>
#include <QGraphicsScene> //Need this for Images

namespace Ui {
class lock_screen;
}

class lock_screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit lock_screen(QWidget *parent = 0);
    ~lock_screen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::lock_screen *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;





};

#endif // LOCK_SCREEN_H
