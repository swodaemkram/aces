#ifndef ABOUTSCREEN_H
#define ABOUTSCREEN_H

#include <QDialog>
#include <QGraphicsScene> //Need this for Images

namespace Ui {
class aboutscreen;
}

class aboutscreen : public QDialog
{
    Q_OBJECT

public:
    explicit aboutscreen(QWidget *parent = 0);
    ~aboutscreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::aboutscreen *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
};

#endif // ABOUTSCREEN_H
