#ifndef ACCESS_GROUP_H
#define ACCESS_GROUP_H

#include <QDialog>
#include <QGraphicsScene> //Need this for Images

namespace Ui {
class Access_Group;
}

class Access_Group : public QDialog
{
    Q_OBJECT

public:
    explicit Access_Group(QWidget *parent = 0);
    ~Access_Group();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Access_Group *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;

};

#endif // ACCESS_GROUP_H
