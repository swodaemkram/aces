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

    void on_pushButton_4_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_25_clicked();

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

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::Access_Group *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;

};

#endif // ACCESS_GROUP_H
