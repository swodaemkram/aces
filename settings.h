#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QGraphicsScene> //Need this for Images

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();

private slots:
    void on_pushButton_clicked();

private:
    Ui::settings *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;

};

#endif // SETTINGS_H
