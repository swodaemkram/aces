#ifndef PIN_CHANGE_SCREEN_H
#define PIN_CHANGE_SCREEN_H

#include <QDialog>

namespace Ui {
class pin_change_screen;
}

class pin_change_screen : public QDialog
{
    Q_OBJECT

public:
    explicit pin_change_screen(QWidget *parent = 0);
    ~pin_change_screen();

private:
    Ui::pin_change_screen *ui;
};

#endif // PIN_CHANGE_SCREEN_H
