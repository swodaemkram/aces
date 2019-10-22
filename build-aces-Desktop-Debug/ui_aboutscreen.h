/********************************************************************************
** Form generated from reading UI file 'aboutscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTSCREEN_H
#define UI_ABOUTSCREEN_H

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

class Ui_aboutscreen
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QGraphicsView *graphicsView_2;
    QLabel *label;

    void setupUi(QDialog *aboutscreen)
    {
        if (aboutscreen->objectName().isEmpty())
            aboutscreen->setObjectName(QStringLiteral("aboutscreen"));
        aboutscreen->resize(1024, 768);
        graphicsView = new QGraphicsView(aboutscreen);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1024, 768));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton = new QPushButton(aboutscreen);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(460, 710, 121, 51));
        graphicsView_2 = new QGraphicsView(aboutscreen);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(5, 11, 1011, 181));
        graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(aboutscreen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 200, 1001, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        label->setPalette(palette);
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(aboutscreen);

        QMetaObject::connectSlotsByName(aboutscreen);
    } // setupUi

    void retranslateUi(QDialog *aboutscreen)
    {
        aboutscreen->setWindowTitle(QApplication::translate("aboutscreen", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("aboutscreen", "Exit", Q_NULLPTR));
        label->setText(QApplication::translate("aboutscreen", "A.C.E.S.  By Fireking Security Group", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aboutscreen: public Ui_aboutscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTSCREEN_H
