#include "pin_change_screen.h"
#include "ui_pin_change_screen.h"

pin_change_screen::pin_change_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pin_change_screen)
{
    ui->setupUi(this);
}

pin_change_screen::~pin_change_screen()
{
    delete ui;
}
