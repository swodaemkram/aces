/********************************************************************************
** Form generated from reading UI file 'pin_change_screen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIN_CHANGE_SCREEN_H
#define UI_PIN_CHANGE_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pin_change_screen
{
public:
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QPushButton *pushButton_4;
    QPushButton *pushButton_16;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_12;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QPushButton *pushButton_8;
    QPushButton *pushButton_11;
    QLabel *label;

    void setupUi(QDialog *pin_change_screen)
    {
        if (pin_change_screen->objectName().isEmpty())
            pin_change_screen->setObjectName(QStringLiteral("pin_change_screen"));
        pin_change_screen->resize(1024, 768);
        pushButton_7 = new QPushButton(pin_change_screen);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(410, 428, 193, 96));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(243, 243, 243, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(190, 190, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_7->setPalette(palette);
        QFont font;
        font.setPointSize(18);
        pushButton_7->setFont(font);
        pushButton_7->setFocusPolicy(Qt::NoFocus);
        pushButton_10 = new QPushButton(pin_change_screen);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(212, 530, 192, 95));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush3(QColor(238, 238, 236, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_10->setPalette(palette1);
        pushButton_10->setFont(font);
        pushButton_10->setFocusPolicy(Qt::NoFocus);
        pushButton_4 = new QPushButton(pin_change_screen);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(609, 327, 192, 95));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_4->setPalette(palette2);
        pushButton_4->setFont(font);
        pushButton_4->setFocusPolicy(Qt::NoFocus);
        pushButton_16 = new QPushButton(pin_change_screen);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(609, 631, 192, 95));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_16->setPalette(palette3);
        pushButton_16->setFont(font);
        pushButton_16->setFocusPolicy(Qt::NoFocus);
        pushButton_3 = new QPushButton(pin_change_screen);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 327, 193, 95));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_3->setPalette(palette4);
        pushButton_3->setFont(font);
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_6 = new QPushButton(pin_change_screen);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(212, 428, 192, 96));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_6->setPalette(palette5);
        pushButton_6->setFont(font);
        pushButton_6->setFocusPolicy(Qt::NoFocus);
        pushButton_2 = new QPushButton(pin_change_screen);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(212, 327, 192, 95));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_2->setPalette(palette6);
        pushButton_2->setFont(font);
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_12 = new QPushButton(pin_change_screen);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(609, 530, 192, 95));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_12->setPalette(palette7);
        pushButton_12->setFont(font);
        pushButton_12->setFocusPolicy(Qt::NoFocus);
        pushButton_15 = new QPushButton(pin_change_screen);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(410, 631, 193, 95));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_15->setPalette(palette8);
        pushButton_15->setFont(font);
        pushButton_15->setFocusPolicy(Qt::NoFocus);
        pushButton_14 = new QPushButton(pin_change_screen);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(212, 631, 192, 95));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_14->setPalette(palette9);
        pushButton_14->setFont(font);
        pushButton_14->setFocusPolicy(Qt::NoFocus);
        pushButton_8 = new QPushButton(pin_change_screen);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(609, 428, 192, 96));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_8->setPalette(palette10);
        pushButton_8->setFont(font);
        pushButton_8->setFocusPolicy(Qt::NoFocus);
        pushButton_11 = new QPushButton(pin_change_screen);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(410, 530, 193, 95));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_11->setPalette(palette11);
        pushButton_11->setFont(font);
        pushButton_11->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(pin_change_screen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 736, 1031, 31));
        QPalette palette12;
        QBrush brush4(QColor(243, 245, 174, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        QBrush brush5(QColor(164, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        label->setPalette(palette12);
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(pin_change_screen);

        QMetaObject::connectSlotsByName(pin_change_screen);
    } // setupUi

    void retranslateUi(QDialog *pin_change_screen)
    {
        pin_change_screen->setWindowTitle(QApplication::translate("pin_change_screen", "Dialog", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("pin_change_screen", "5", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("pin_change_screen", "7", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("pin_change_screen", "3", Q_NULLPTR));
        pushButton_16->setText(QString());
        pushButton_3->setText(QApplication::translate("pin_change_screen", "2", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("pin_change_screen", "4", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("pin_change_screen", "1", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("pin_change_screen", "9", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("pin_change_screen", "0", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("pin_change_screen", "Clear", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("pin_change_screen", "6", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("pin_change_screen", "8", Q_NULLPTR));
        label->setText(QApplication::translate("pin_change_screen", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pin_change_screen: public Ui_pin_change_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIN_CHANGE_SCREEN_H
