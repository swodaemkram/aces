#ifndef MANAGE_ACCESS_ITEM_H
#define MANAGE_ACCESS_ITEM_H

#include <QDialog>
#include <QGraphicsScene> //Need this for Images

namespace Ui {
class manage_access_item;
}

class manage_access_item : public QDialog
{
    Q_OBJECT

public:
    explicit manage_access_item(QWidget *parent = 0);
    ~manage_access_item();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_51_clicked();

private:
    Ui::manage_access_item *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;

};

#endif // MANAGE_ACCESS_ITEM_H
