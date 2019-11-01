#ifndef REPORTS_H
#define REPORTS_H

#include <QDialog>
#include <QDialog>
#include <QGraphicsScene> //Need this for Images

namespace Ui {
class reports;
}

class reports : public QDialog
{
    Q_OBJECT

public:
    explicit reports(QWidget *parent = 0);
    ~reports();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::reports *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;

};

#endif // REPORTS_H
