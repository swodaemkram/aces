/********************************************************************************
** Form generated from reading UI file 'user_screen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_SCREEN_H
#define UI_USER_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user_screen
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_49;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QFrame *frame_2;
    QFrame *frame_3;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit_3;
    QLabel *label_6;
    QPlainTextEdit *plainTextEdit_4;
    QCheckBox *checkBox;
    QPushButton *pushButton_50;
    QPushButton *pushButton_51;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QListWidget *listWidget;
    QGraphicsView *graphicsView_2;
    QFrame *frame_4;
    QPushButton *pushButton_47;
    QPushButton *pushButton_45;
    QPushButton *pushButton_48;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_6;
    QPushButton *pushButton_23;
    QPushButton *pushButton_39;
    QPushButton *pushButton_7;
    QPushButton *pushButton_11;
    QPushButton *pushButton_19;
    QPushButton *pushButton_18;
    QPushButton *pushButton_46;
    QPushButton *pushButton_33;
    QPushButton *pushButton_8;
    QPushButton *pushButton_15;
    QPushButton *pushButton_42;
    QPushButton *pushButton_43;
    QPushButton *pushButton_9;
    QPushButton *pushButton_22;
    QPushButton *pushButton_35;
    QPushButton *pushButton_32;
    QPushButton *pushButton_31;
    QPushButton *pushButton_38;
    QPushButton *pushButton_20;
    QPushButton *pushButton_40;
    QPushButton *pushButton_27;
    QPushButton *pushButton_34;
    QPushButton *pushButton_44;
    QPushButton *pushButton_16;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_10;
    QPushButton *pushButton_29;
    QPushButton *pushButton_21;
    QPushButton *pushButton_26;
    QPushButton *pushButton_41;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_37;
    QPushButton *pushButton_36;
    QPushButton *pushButton_30;
    QPushButton *pushButton_12;
    QPushButton *pushButton_17;
    QPushButton *pushButton_28;
    QLabel *label_2;

    void setupUi(QDialog *user_screen)
    {
        if (user_screen->objectName().isEmpty())
            user_screen->setObjectName(QStringLiteral("user_screen"));
        user_screen->resize(1024, 768);
        graphicsView = new QGraphicsView(user_screen);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1024, 768));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(user_screen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 851, 31));
        QPalette palette;
        QBrush brush(QColor(243, 245, 174, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(245, 121, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label->setPalette(palette);
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Sunken);
        label->setAlignment(Qt::AlignCenter);
        frame = new QFrame(user_screen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 141, 711));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 121, 691));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush4(QColor(243, 243, 243, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush4);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_3->setPalette(palette1);
        pushButton_3->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_2->setPalette(palette2);
        pushButton_2->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_4->setPalette(palette3);
        pushButton_4->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_4);

        pushButton_49 = new QPushButton(verticalLayoutWidget);
        pushButton_49->setObjectName(QStringLiteral("pushButton_49"));
        sizePolicy.setHeightForWidth(pushButton_49->sizePolicy().hasHeightForWidth());
        pushButton_49->setSizePolicy(sizePolicy);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_49->setPalette(palette4);
        pushButton_49->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_49);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_5->setPalette(palette5);
        pushButton_5->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_5);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton->setPalette(palette6);
        pushButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton);

        frame_2 = new QFrame(user_screen);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(160, 50, 851, 671));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 10, 831, 251));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 121, 17));
        QFont font1;
        font1.setPointSize(14);
        label_3->setFont(font1);
        plainTextEdit = new QPlainTextEdit(frame_3);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(130, 10, 221, 31));
        plainTextEdit->setFont(font1);
        plainTextEdit->setFocusPolicy(Qt::WheelFocus);
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 111, 17));
        label_4->setFont(font1);
        plainTextEdit_2 = new QPlainTextEdit(frame_3);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(130, 50, 221, 31));
        plainTextEdit_2->setFont(font1);
        plainTextEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 100, 41, 17));
        label_5->setFont(font1);
        plainTextEdit_3 = new QPlainTextEdit(frame_3);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(120, 90, 391, 41));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        QBrush brush6(QColor(239, 235, 231, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        plainTextEdit_3->setPalette(palette7);
        plainTextEdit_3->setFont(font1);
        plainTextEdit_3->setAcceptDrops(true);
        plainTextEdit_3->setAutoFillBackground(false);
        plainTextEdit_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(390, 20, 191, 20));
        label_6->setFont(font1);
        plainTextEdit_4 = new QPlainTextEdit(frame_3);
        plainTextEdit_4->setObjectName(QStringLiteral("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(590, 10, 221, 31));
        plainTextEdit_4->setFont(font1);
        plainTextEdit_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        checkBox = new QCheckBox(frame_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(220, 130, 251, 41));
        QFont font2;
        font2.setPointSize(18);
        checkBox->setFont(font2);
        pushButton_50 = new QPushButton(frame_3);
        pushButton_50->setObjectName(QStringLiteral("pushButton_50"));
        pushButton_50->setGeometry(QRect(210, 160, 121, 91));
        QPalette palette8;
        QBrush brush7(QColor(46, 52, 54, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_50->setPalette(palette8);
        pushButton_50->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/back_button_gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_50->setIcon(icon);
        pushButton_50->setIconSize(QSize(80, 80));
        pushButton_50->setFlat(true);
        pushButton_51 = new QPushButton(frame_3);
        pushButton_51->setObjectName(QStringLiteral("pushButton_51"));
        pushButton_51->setGeometry(QRect(500, 160, 121, 91));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_51->setPalette(palette9);
        pushButton_51->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/forward_button_gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_51->setIcon(icon1);
        pushButton_51->setIconSize(QSize(80, 80));
        pushButton_51->setFlat(true);
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 200, 171, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("Ubuntu Condensed"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_7->setFont(font3);
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(620, 200, 151, 17));
        label_8->setFont(font3);
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(310, 190, 201, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("URW Bookman L"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        label_9->setFont(font4);
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 140, 81, 21));
        label_10->setFont(font1);
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(120, 130, 81, 41));
        QPalette palette10;
        QBrush brush8(QColor(186, 189, 182, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        QBrush brush9(QColor(203, 199, 196, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        QBrush brush10(QColor(118, 116, 114, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        label_11->setPalette(palette10);
        QFont font5;
        font5.setFamily(QStringLiteral("URW Bookman L"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        label_11->setFont(font5);
        label_11->setAutoFillBackground(true);
        label_11->setFrameShape(QFrame::WinPanel);
        label_11->setFrameShadow(QFrame::Sunken);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        listWidget = new QListWidget(frame_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(620, 50, 191, 121));
        listWidget->setFont(font1);
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2 = new QGraphicsView(frame_3);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(0, 0, 831, 251));
        graphicsView_2->setAutoFillBackground(true);
        graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2->raise();
        label_3->raise();
        plainTextEdit->raise();
        label_4->raise();
        plainTextEdit_2->raise();
        label_5->raise();
        plainTextEdit_3->raise();
        label_6->raise();
        plainTextEdit_4->raise();
        checkBox->raise();
        pushButton_50->raise();
        pushButton_51->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        listWidget->raise();
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(10, 270, 831, 391));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        pushButton_47 = new QPushButton(frame_4);
        pushButton_47->setObjectName(QStringLiteral("pushButton_47"));
        pushButton_47->setGeometry(QRect(0, 340, 61, 41));
        QFont font6;
        font6.setPointSize(20);
        pushButton_47->setFont(font6);
        pushButton_47->setFocusPolicy(Qt::NoFocus);
        pushButton_45 = new QPushButton(frame_4);
        pushButton_45->setObjectName(QStringLiteral("pushButton_45"));
        pushButton_45->setGeometry(QRect(70, 340, 641, 41));
        pushButton_45->setFont(font6);
        pushButton_45->setFocusPolicy(Qt::NoFocus);
        pushButton_48 = new QPushButton(frame_4);
        pushButton_48->setObjectName(QStringLiteral("pushButton_48"));
        pushButton_48->setGeometry(QRect(720, 340, 111, 41));
        pushButton_48->setFont(font6);
        pushButton_48->setFocusPolicy(Qt::NoFocus);
        gridLayoutWidget = new QWidget(frame_4);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 838, 311));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font6);
        pushButton_6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_23 = new QPushButton(gridLayoutWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        sizePolicy.setHeightForWidth(pushButton_23->sizePolicy().hasHeightForWidth());
        pushButton_23->setSizePolicy(sizePolicy);
        pushButton_23->setFont(font6);
        pushButton_23->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_23, 2, 7, 1, 1);

        pushButton_39 = new QPushButton(gridLayoutWidget);
        pushButton_39->setObjectName(QStringLiteral("pushButton_39"));
        sizePolicy.setHeightForWidth(pushButton_39->sizePolicy().hasHeightForWidth());
        pushButton_39->setSizePolicy(sizePolicy);
        pushButton_39->setFont(font6);
        pushButton_39->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_39, 0, 4, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setFont(font6);
        pushButton_7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        pushButton_11->setFont(font6);
        pushButton_11->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_11, 1, 5, 1, 1);

        pushButton_19 = new QPushButton(gridLayoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        sizePolicy.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy);
        pushButton_19->setFont(font6);
        pushButton_19->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_19, 2, 3, 1, 1);

        pushButton_18 = new QPushButton(gridLayoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        sizePolicy.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy);
        pushButton_18->setFont(font6);
        pushButton_18->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_18, 2, 2, 1, 1);

        pushButton_46 = new QPushButton(gridLayoutWidget);
        pushButton_46->setObjectName(QStringLiteral("pushButton_46"));
        sizePolicy.setHeightForWidth(pushButton_46->sizePolicy().hasHeightForWidth());
        pushButton_46->setSizePolicy(sizePolicy);
        pushButton_46->setFont(font6);
        pushButton_46->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_46, 3, 8, 1, 1);

        pushButton_33 = new QPushButton(gridLayoutWidget);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        sizePolicy.setHeightForWidth(pushButton_33->sizePolicy().hasHeightForWidth());
        pushButton_33->setSizePolicy(sizePolicy);
        pushButton_33->setFont(font6);
        pushButton_33->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_33, 3, 9, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font6);
        pushButton_8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);
        pushButton_15->setFont(font6);
        pushButton_15->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_15, 1, 9, 1, 1);

        pushButton_42 = new QPushButton(gridLayoutWidget);
        pushButton_42->setObjectName(QStringLiteral("pushButton_42"));
        sizePolicy.setHeightForWidth(pushButton_42->sizePolicy().hasHeightForWidth());
        pushButton_42->setSizePolicy(sizePolicy);
        pushButton_42->setFont(font6);
        pushButton_42->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_42, 0, 7, 1, 1);

        pushButton_43 = new QPushButton(gridLayoutWidget);
        pushButton_43->setObjectName(QStringLiteral("pushButton_43"));
        sizePolicy.setHeightForWidth(pushButton_43->sizePolicy().hasHeightForWidth());
        pushButton_43->setSizePolicy(sizePolicy);
        pushButton_43->setFont(font6);
        pushButton_43->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_43, 0, 8, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font6);
        pushButton_9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_9, 1, 3, 1, 1);

        pushButton_22 = new QPushButton(gridLayoutWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        sizePolicy.setHeightForWidth(pushButton_22->sizePolicy().hasHeightForWidth());
        pushButton_22->setSizePolicy(sizePolicy);
        pushButton_22->setFont(font6);
        pushButton_22->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_22, 2, 6, 1, 1);

        pushButton_35 = new QPushButton(gridLayoutWidget);
        pushButton_35->setObjectName(QStringLiteral("pushButton_35"));
        sizePolicy.setHeightForWidth(pushButton_35->sizePolicy().hasHeightForWidth());
        pushButton_35->setSizePolicy(sizePolicy);
        pushButton_35->setFont(font6);
        pushButton_35->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_35, 0, 0, 1, 1);

        pushButton_32 = new QPushButton(gridLayoutWidget);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        sizePolicy.setHeightForWidth(pushButton_32->sizePolicy().hasHeightForWidth());
        pushButton_32->setSizePolicy(sizePolicy);
        pushButton_32->setFont(font6);
        pushButton_32->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_32, 3, 7, 1, 1);

        pushButton_31 = new QPushButton(gridLayoutWidget);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        sizePolicy.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy);
        pushButton_31->setFont(font6);
        pushButton_31->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_31, 3, 6, 1, 1);

        pushButton_38 = new QPushButton(gridLayoutWidget);
        pushButton_38->setObjectName(QStringLiteral("pushButton_38"));
        sizePolicy.setHeightForWidth(pushButton_38->sizePolicy().hasHeightForWidth());
        pushButton_38->setSizePolicy(sizePolicy);
        pushButton_38->setFont(font6);
        pushButton_38->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_38, 0, 3, 1, 1);

        pushButton_20 = new QPushButton(gridLayoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        sizePolicy.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy);
        pushButton_20->setFont(font6);
        pushButton_20->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_20, 2, 4, 1, 1);

        pushButton_40 = new QPushButton(gridLayoutWidget);
        pushButton_40->setObjectName(QStringLiteral("pushButton_40"));
        sizePolicy.setHeightForWidth(pushButton_40->sizePolicy().hasHeightForWidth());
        pushButton_40->setSizePolicy(sizePolicy);
        pushButton_40->setFont(font6);
        pushButton_40->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_40, 0, 5, 1, 1);

        pushButton_27 = new QPushButton(gridLayoutWidget);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        sizePolicy.setHeightForWidth(pushButton_27->sizePolicy().hasHeightForWidth());
        pushButton_27->setSizePolicy(sizePolicy);
        pushButton_27->setFont(font6);
        pushButton_27->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_27, 3, 2, 1, 1);

        pushButton_34 = new QPushButton(gridLayoutWidget);
        pushButton_34->setObjectName(QStringLiteral("pushButton_34"));
        sizePolicy.setHeightForWidth(pushButton_34->sizePolicy().hasHeightForWidth());
        pushButton_34->setSizePolicy(sizePolicy);
        pushButton_34->setFont(font6);
        pushButton_34->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_34, 3, 0, 1, 1);

        pushButton_44 = new QPushButton(gridLayoutWidget);
        pushButton_44->setObjectName(QStringLiteral("pushButton_44"));
        sizePolicy.setHeightForWidth(pushButton_44->sizePolicy().hasHeightForWidth());
        pushButton_44->setSizePolicy(sizePolicy);
        pushButton_44->setFont(font6);
        pushButton_44->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_44, 0, 9, 1, 1);

        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);
        pushButton_16->setFont(font6);
        pushButton_16->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_16, 2, 0, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);
        pushButton_13->setFont(font6);
        pushButton_13->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_13, 1, 7, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);
        pushButton_14->setFont(font6);
        pushButton_14->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_14, 1, 8, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        pushButton_10->setFont(font6);
        pushButton_10->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_10, 1, 4, 1, 1);

        pushButton_29 = new QPushButton(gridLayoutWidget);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        sizePolicy.setHeightForWidth(pushButton_29->sizePolicy().hasHeightForWidth());
        pushButton_29->setSizePolicy(sizePolicy);
        pushButton_29->setFont(font6);
        pushButton_29->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_29, 3, 4, 1, 1);

        pushButton_21 = new QPushButton(gridLayoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        sizePolicy.setHeightForWidth(pushButton_21->sizePolicy().hasHeightForWidth());
        pushButton_21->setSizePolicy(sizePolicy);
        pushButton_21->setFont(font6);
        pushButton_21->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_21, 2, 5, 1, 1);

        pushButton_26 = new QPushButton(gridLayoutWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        sizePolicy.setHeightForWidth(pushButton_26->sizePolicy().hasHeightForWidth());
        pushButton_26->setSizePolicy(sizePolicy);
        pushButton_26->setFont(font6);
        pushButton_26->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_26, 3, 1, 1, 1);

        pushButton_41 = new QPushButton(gridLayoutWidget);
        pushButton_41->setObjectName(QStringLiteral("pushButton_41"));
        sizePolicy.setHeightForWidth(pushButton_41->sizePolicy().hasHeightForWidth());
        pushButton_41->setSizePolicy(sizePolicy);
        pushButton_41->setFont(font6);
        pushButton_41->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_41, 0, 6, 1, 1);

        pushButton_24 = new QPushButton(gridLayoutWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        sizePolicy.setHeightForWidth(pushButton_24->sizePolicy().hasHeightForWidth());
        pushButton_24->setSizePolicy(sizePolicy);
        pushButton_24->setFont(font6);
        pushButton_24->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_24, 2, 8, 1, 1);

        pushButton_25 = new QPushButton(gridLayoutWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        sizePolicy.setHeightForWidth(pushButton_25->sizePolicy().hasHeightForWidth());
        pushButton_25->setSizePolicy(sizePolicy);
        pushButton_25->setFont(font6);
        pushButton_25->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_25, 2, 9, 1, 1);

        pushButton_37 = new QPushButton(gridLayoutWidget);
        pushButton_37->setObjectName(QStringLiteral("pushButton_37"));
        sizePolicy.setHeightForWidth(pushButton_37->sizePolicy().hasHeightForWidth());
        pushButton_37->setSizePolicy(sizePolicy);
        pushButton_37->setFont(font6);
        pushButton_37->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_37, 0, 2, 1, 1);

        pushButton_36 = new QPushButton(gridLayoutWidget);
        pushButton_36->setObjectName(QStringLiteral("pushButton_36"));
        sizePolicy.setHeightForWidth(pushButton_36->sizePolicy().hasHeightForWidth());
        pushButton_36->setSizePolicy(sizePolicy);
        pushButton_36->setFont(font6);
        pushButton_36->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_36, 0, 1, 1, 1);

        pushButton_30 = new QPushButton(gridLayoutWidget);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        sizePolicy.setHeightForWidth(pushButton_30->sizePolicy().hasHeightForWidth());
        pushButton_30->setSizePolicy(sizePolicy);
        pushButton_30->setFont(font6);
        pushButton_30->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_30, 3, 5, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        pushButton_12->setFont(font6);
        pushButton_12->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_12, 1, 6, 1, 1);

        pushButton_17 = new QPushButton(gridLayoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        sizePolicy.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy);
        pushButton_17->setFont(font6);
        pushButton_17->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_17, 2, 1, 1, 1);

        pushButton_28 = new QPushButton(gridLayoutWidget);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        sizePolicy.setHeightForWidth(pushButton_28->sizePolicy().hasHeightForWidth());
        pushButton_28->setSizePolicy(sizePolicy);
        pushButton_28->setFont(font6);
        pushButton_28->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_28, 3, 3, 1, 1);

        pushButton_23->raise();
        pushButton_6->raise();
        pushButton_39->raise();
        pushButton_7->raise();
        pushButton_11->raise();
        pushButton_19->raise();
        pushButton_18->raise();
        pushButton_46->raise();
        pushButton_33->raise();
        pushButton_8->raise();
        pushButton_15->raise();
        pushButton_42->raise();
        pushButton_43->raise();
        pushButton_9->raise();
        pushButton_22->raise();
        pushButton_35->raise();
        pushButton_32->raise();
        pushButton_31->raise();
        pushButton_38->raise();
        pushButton_20->raise();
        pushButton_40->raise();
        pushButton_27->raise();
        pushButton_34->raise();
        pushButton_44->raise();
        pushButton_16->raise();
        pushButton_13->raise();
        pushButton_14->raise();
        pushButton_10->raise();
        pushButton_29->raise();
        pushButton_21->raise();
        pushButton_26->raise();
        pushButton_41->raise();
        pushButton_24->raise();
        pushButton_25->raise();
        pushButton_37->raise();
        pushButton_36->raise();
        pushButton_30->raise();
        pushButton_12->raise();
        pushButton_17->raise();
        pushButton_28->raise();
        label_2 = new QLabel(user_screen);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(6, 730, 1011, 31));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush11(QColor(164, 0, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        label_2->setPalette(palette11);
        label_2->setFont(font1);
        label_2->setAutoFillBackground(true);
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(user_screen);

        QMetaObject::connectSlotsByName(user_screen);
    } // setupUi

    void retranslateUi(QDialog *user_screen)
    {
        user_screen->setWindowTitle(QApplication::translate("user_screen", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("user_screen", "User Administration Screen", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("user_screen", "Add User", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("user_screen", "Edit", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("user_screen", "Delete", Q_NULLPTR));
        pushButton_49->setText(QApplication::translate("user_screen", "Cancel", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("user_screen", "Save", Q_NULLPTR));
        pushButton->setText(QApplication::translate("user_screen", "Exit", Q_NULLPTR));
        label_3->setText(QApplication::translate("user_screen", "First Name :", Q_NULLPTR));
        label_4->setText(QApplication::translate("user_screen", "Last Name :", Q_NULLPTR));
        label_5->setText(QApplication::translate("user_screen", "PIN :", Q_NULLPTR));
        label_6->setText(QApplication::translate("user_screen", "Permission Group :", Q_NULLPTR));
        checkBox->setText(QApplication::translate("user_screen", "User Enabled", Q_NULLPTR));
        pushButton_50->setText(QString());
        pushButton_51->setText(QString());
        label_7->setText(QApplication::translate("user_screen", "Backward In Database", Q_NULLPTR));
        label_8->setText(QApplication::translate("user_screen", "Forward in Database", Q_NULLPTR));
        label_9->setText(QApplication::translate("user_screen", "0", Q_NULLPTR));
        label_10->setText(QApplication::translate("user_screen", "USER ID :", Q_NULLPTR));
        label_11->setText(QString());
        pushButton_47->setText(QApplication::translate("user_screen", "TAB", Q_NULLPTR));
        pushButton_45->setText(QApplication::translate("user_screen", "Space", Q_NULLPTR));
        pushButton_48->setText(QApplication::translate("user_screen", "BCKSPC", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("user_screen", "Q", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("user_screen", "K", Q_NULLPTR));
        pushButton_39->setText(QApplication::translate("user_screen", "5", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("user_screen", "W", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("user_screen", "Y", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("user_screen", "F", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("user_screen", "D", Q_NULLPTR));
        pushButton_46->setText(QApplication::translate("user_screen", "/", Q_NULLPTR));
        pushButton_33->setText(QApplication::translate("user_screen", "CLR", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("user_screen", "E", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("user_screen", "P", Q_NULLPTR));
        pushButton_42->setText(QApplication::translate("user_screen", "8", Q_NULLPTR));
        pushButton_43->setText(QApplication::translate("user_screen", "9", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("user_screen", "R", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("user_screen", "J", Q_NULLPTR));
        pushButton_35->setText(QApplication::translate("user_screen", "1", Q_NULLPTR));
        pushButton_32->setText(QApplication::translate("user_screen", "M", Q_NULLPTR));
        pushButton_31->setText(QApplication::translate("user_screen", "N", Q_NULLPTR));
        pushButton_38->setText(QApplication::translate("user_screen", "4", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("user_screen", "G", Q_NULLPTR));
        pushButton_40->setText(QApplication::translate("user_screen", "6", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("user_screen", "X", Q_NULLPTR));
        pushButton_34->setText(QString());
        pushButton_44->setText(QApplication::translate("user_screen", "0", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("user_screen", "A", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("user_screen", "I", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("user_screen", "O", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("user_screen", "T", Q_NULLPTR));
        pushButton_29->setText(QApplication::translate("user_screen", "V", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("user_screen", "H", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("user_screen", "Z", Q_NULLPTR));
        pushButton_41->setText(QApplication::translate("user_screen", "7", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("user_screen", "L", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("user_screen", "Enter", Q_NULLPTR));
        pushButton_37->setText(QApplication::translate("user_screen", "3", Q_NULLPTR));
        pushButton_36->setText(QApplication::translate("user_screen", "2", Q_NULLPTR));
        pushButton_30->setText(QApplication::translate("user_screen", "B", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("user_screen", "U", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("user_screen", "S", Q_NULLPTR));
        pushButton_28->setText(QApplication::translate("user_screen", "C", Q_NULLPTR));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class user_screen: public Ui_user_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_SCREEN_H
