/********************************************************************************
** Form generated from reading UI file 'networksettings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKSETTINGS_H
#define UI_NETWORKSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NetworkSettings
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *NetworkSettings)
    {
        if (NetworkSettings->objectName().isEmpty())
            NetworkSettings->setObjectName(QStringLiteral("NetworkSettings"));
        NetworkSettings->resize(1024, 768);
        pushButton = new QPushButton(NetworkSettings);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 590, 89, 25));

        retranslateUi(NetworkSettings);

        QMetaObject::connectSlotsByName(NetworkSettings);
    } // setupUi

    void retranslateUi(QDialog *NetworkSettings)
    {
        NetworkSettings->setWindowTitle(QApplication::translate("NetworkSettings", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NetworkSettings", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NetworkSettings: public Ui_NetworkSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKSETTINGS_H
