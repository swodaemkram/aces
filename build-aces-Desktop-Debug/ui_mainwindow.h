/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_12;
    QPushButton *pushButton_15;
    QPushButton *pushButton_11;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_16;
    QPushButton *pushButton_10;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_14;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLCDNumber *lcdNumber;
    QLabel *label_4;
    QGraphicsView *graphicsView_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1024, 768));
        graphicsView->setFocusPolicy(Qt::NoFocus);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 61, 31));
        pushButton->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 1001, 51));
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
        font.setFamily(QStringLiteral("URW Bookman L"));
        font.setPointSize(50);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(210, 280, 591, 401));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush2(QColor(243, 243, 243, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_2->setPalette(palette1);
        QFont font1;
        font1.setPointSize(18);
        pushButton_2->setFont(font1);
        pushButton_2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_12->setPalette(palette2);
        pushButton_12->setFont(font1);
        pushButton_12->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_12, 2, 2, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_15->setPalette(palette3);
        pushButton_15->setFont(font1);
        pushButton_15->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_15, 3, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_11->setPalette(palette4);
        pushButton_11->setFont(font1);
        pushButton_11->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_11, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_3->setPalette(palette5);
        pushButton_3->setFont(font1);
        pushButton_3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_8->setPalette(palette6);
        pushButton_8->setFont(font1);
        pushButton_8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_16->setPalette(palette7);
        pushButton_16->setFont(font1);
        pushButton_16->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_16, 3, 2, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        QPalette palette8;
        QBrush brush4(QColor(238, 238, 236, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_10->setPalette(palette8);
        pushButton_10->setFont(font1);
        pushButton_10->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_10, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_7->setPalette(palette9);
        pushButton_7->setFont(font1);
        pushButton_7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_6->setPalette(palette10);
        pushButton_6->setFont(font1);
        pushButton_6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_4->setPalette(palette11);
        pushButton_4->setFont(font1);
        pushButton_4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_4, 0, 2, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_14->setPalette(palette12);
        pushButton_14->setFont(font1);
        pushButton_14->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_14, 3, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(320, 140, 451, 51));
        plainTextEdit->setFont(font1);
        plainTextEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhMultiLine);
        plainTextEdit->setTabChangesFocus(true);
        plainTextEdit_2 = new QPlainTextEdit(centralWidget);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(320, 210, 451, 51));
        plainTextEdit_2->setFont(font1);
        plainTextEdit_2->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly|Qt::ImhHiddenText|Qt::ImhPreferNumbers|Qt::ImhSensitiveData);
        plainTextEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_2->setTabChangesFocus(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 140, 91, 41));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        label_2->setPalette(palette13);
        label_2->setFont(font1);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 220, 61, 31));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        label_3->setPalette(palette14);
        label_3->setFont(font1);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(80, 72, 871, 51));
        QPalette palette15;
        QBrush brush5(QColor(114, 159, 207, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        QBrush brush6(QColor(14, 15, 125, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        QBrush brush7(QColor(32, 74, 135, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        lcdNumber->setPalette(palette15);
        lcdNumber->setAutoFillBackground(true);
        lcdNumber->setFrameShape(QFrame::WinPanel);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(24);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(16, 720, 991, 41));
        QPalette palette16;
        QBrush brush8(QColor(243, 245, 174, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush9(QColor(204, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        label_4->setPalette(palette16);
        QFont font2;
        font2.setPointSize(14);
        label_4->setFont(font2);
        label_4->setAutoFillBackground(true);
        label_4->setFrameShape(QFrame::WinPanel);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setAlignment(Qt::AlignCenter);
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(0, 0, 1021, 771));
        graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MainWindow->setCentralWidget(centralWidget);
        graphicsView_2->raise();
        graphicsView->raise();
        label->raise();
        gridLayoutWidget->raise();
        plainTextEdit->raise();
        plainTextEdit_2->raise();
        label_2->raise();
        label_3->raise();
        lcdNumber->raise();
        pushButton->raise();
        label_4->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "A.C.E.S.", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        pushButton_16->setText(QString());
        pushButton_10->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "User ID :", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "PIN :", Q_NULLPTR));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
