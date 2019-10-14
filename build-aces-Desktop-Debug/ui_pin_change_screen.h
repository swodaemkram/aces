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

QT_BEGIN_NAMESPACE

class Ui_pin_change_screen
{
public:

    void setupUi(QDialog *pin_change_screen)
    {
        if (pin_change_screen->objectName().isEmpty())
            pin_change_screen->setObjectName(QStringLiteral("pin_change_screen"));
        pin_change_screen->resize(1024, 768);

        retranslateUi(pin_change_screen);

        QMetaObject::connectSlotsByName(pin_change_screen);
    } // setupUi

    void retranslateUi(QDialog *pin_change_screen)
    {
        pin_change_screen->setWindowTitle(QApplication::translate("pin_change_screen", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pin_change_screen: public Ui_pin_change_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIN_CHANGE_SCREEN_H
