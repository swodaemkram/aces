#ifndef NETWORKSETTINGS_H
#define NETWORKSETTINGS_H

#include <QDialog>


namespace Ui {
class NetworkSettings;
}

class NetworkSettings : public QDialog
{
    Q_OBJECT

public:
    explicit NetworkSettings(QWidget *parent = 0);
    ~NetworkSettings();

private slots:
    void on_pushButton_clicked();

    void LogEvent(QString EventID);


private:
    Ui::NetworkSettings *ui;

};

#endif // NETWORKSETTINGS_H
