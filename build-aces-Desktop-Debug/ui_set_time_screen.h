/********************************************************************************
** Form generated from reading UI file 'set_time_screen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_TIME_SCREEN_H
#define UI_SET_TIME_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_set_time_screen
{
public:
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *set_time_screen)
    {
        if (set_time_screen->objectName().isEmpty())
            set_time_screen->setObjectName(QStringLiteral("set_time_screen"));
        set_time_screen->resize(1024, 768);
        dateTimeEdit = new QDateTimeEdit(set_time_screen);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(110, 110, 791, 131));
        QPalette palette;
        QBrush brush(QColor(138, 226, 52, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(5, 27, 105, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush2(QColor(14, 15, 125, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush4(QColor(145, 141, 126, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        dateTimeEdit->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("URW Bookman L"));
        font.setPointSize(49);
        font.setBold(true);
        font.setWeight(75);
        dateTimeEdit->setFont(font);
        dateTimeEdit->setAutoFillBackground(false);
        dateTimeEdit->setFrame(false);
        dateTimeEdit->setAlignment(Qt::AlignCenter);
        dateTimeEdit->setProperty("showGroupSeparator", QVariant(false));
        dateTimeEdit->setCalendarPopup(false);
        pushButton = new QPushButton(set_time_screen);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 290, 531, 91));
        QFont font1;
        font1.setPointSize(20);
        pushButton->setFont(font1);

        retranslateUi(set_time_screen);

        QMetaObject::connectSlotsByName(set_time_screen);
    } // setupUi

    void retranslateUi(QDialog *set_time_screen)
    {
        set_time_screen->setWindowTitle(QApplication::translate("set_time_screen", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("set_time_screen", "Set and Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class set_time_screen: public Ui_set_time_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_TIME_SCREEN_H
