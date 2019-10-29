/********************************************************************************
** Form generated from reading UI file 'enroll_ibutton.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENROLL_IBUTTON_H
#define UI_ENROLL_IBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_enroll_ibutton
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *enroll_ibutton)
    {
        if (enroll_ibutton->objectName().isEmpty())
            enroll_ibutton->setObjectName(QStringLiteral("enroll_ibutton"));
        enroll_ibutton->resize(1024, 768);
        graphicsView = new QGraphicsView(enroll_ibutton);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1024, 768));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton = new QPushButton(enroll_ibutton);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 690, 101, 41));
        label = new QLabel(enroll_ibutton);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1031, 51));
        QPalette palette;
        QBrush brush(QColor(138, 226, 52, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        label->setPalette(palette);
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(enroll_ibutton);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 740, 1031, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush2(QColor(164, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label_2->setPalette(palette1);
        label_2->setFont(font);
        label_2->setAutoFillBackground(true);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(enroll_ibutton);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 500, 1021, 71));
        QFont font1;
        font1.setPointSize(18);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(enroll_ibutton);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(6, 570, 1021, 41));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        retranslateUi(enroll_ibutton);

        QMetaObject::connectSlotsByName(enroll_ibutton);
    } // setupUi

    void retranslateUi(QDialog *enroll_ibutton)
    {
        enroll_ibutton->setWindowTitle(QApplication::translate("enroll_ibutton", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("enroll_ibutton", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("enroll_ibutton", "i-Button Enrollment Screen", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("enroll_ibutton", "Please place i-Button key on reader", Q_NULLPTR));
        label_4->setText(QApplication::translate("enroll_ibutton", "after the i-Button has been read this screen will automatically close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class enroll_ibutton: public Ui_enroll_ibutton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENROLL_IBUTTON_H
