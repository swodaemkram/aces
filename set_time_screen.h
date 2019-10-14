#ifndef SET_TIME_SCREEN_H
#define SET_TIME_SCREEN_H

#include <QDialog>

namespace Ui {
class set_time_screen;
}

class set_time_screen : public QDialog
{
    Q_OBJECT

public:
    explicit set_time_screen(QWidget *parent = 0);
    ~set_time_screen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::set_time_screen *ui;


};

#endif // SET_TIME_SCREEN_H
