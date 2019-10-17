/********************************************************************************
** Form generated from reading UI file 'manage_access_item.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGE_ACCESS_ITEM_H
#define UI_MANAGE_ACCESS_ITEM_H

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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manage_access_item
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QFrame *frame_2;
    QGraphicsView *graphicsView_2;
    QPushButton *pushButton_50;
    QPushButton *pushButton_51;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit_3;
    QLabel *label_6;
    QPlainTextEdit *plainTextEdit_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox;
    QCheckBox *checkBox_4;
    QWidget *tab_0;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_13;
    QWidget *tab_2;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_19;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_18;
    QCheckBox *checkBox_17;
    QFrame *frame_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_23;
    QPushButton *pushButton_39;
    QPushButton *pushButton_8;
    QPushButton *pushButton_11;
    QPushButton *pushButton_19;
    QPushButton *pushButton_18;
    QPushButton *pushButton_46;
    QPushButton *pushButton_33;
    QPushButton *pushButton_9;
    QPushButton *pushButton_15;
    QPushButton *pushButton_42;
    QPushButton *pushButton_43;
    QPushButton *pushButton_10;
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
    QPushButton *pushButton_12;
    QPushButton *pushButton_29;
    QPushButton *pushButton_21;
    QPushButton *pushButton_26;
    QPushButton *pushButton_41;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_37;
    QPushButton *pushButton_36;
    QPushButton *pushButton_30;
    QPushButton *pushButton_17;
    QPushButton *pushButton_28;
    QPushButton *pushButton_45;
    QPushButton *pushButton_47;
    QPushButton *pushButton_49;
    QPushButton *pushButton_48;

    void setupUi(QDialog *manage_access_item)
    {
        if (manage_access_item->objectName().isEmpty())
            manage_access_item->setObjectName(QStringLiteral("manage_access_item"));
        manage_access_item->resize(1024, 768);
        manage_access_item->setAutoFillBackground(false);
        graphicsView = new QGraphicsView(manage_access_item);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1024, 768));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(manage_access_item);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 851, 31));
        QPalette palette;
        QBrush brush(QColor(243, 245, 174, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(92, 53, 102, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(32, 74, 135, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label->setPalette(palette);
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Sunken);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(manage_access_item);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 730, 1031, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush4(QColor(164, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        label_2->setPalette(palette1);
        label_2->setFont(font);
        label_2->setAutoFillBackground(true);
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);
        frame = new QFrame(manage_access_item);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 141, 711));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 9, 121, 691));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QPalette palette2;
        QBrush brush5(QColor(243, 243, 243, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_2->setPalette(palette2);
        pushButton_2->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_4->setPalette(palette3);
        pushButton_4->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_3->setPalette(palette4);
        pushButton_3->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_3);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_6->setPalette(palette5);
        pushButton_6->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_5->setPalette(palette6);
        pushButton_5->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_5);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush5);
        QBrush brush7(QColor(255, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton->setPalette(palette7);
        pushButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton);

        frame_2 = new QFrame(manage_access_item);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(160, 40, 851, 331));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        graphicsView_2 = new QGraphicsView(frame_2);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(0, 0, 851, 331));
        graphicsView_2->setAutoFillBackground(true);
        graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton_50 = new QPushButton(frame_2);
        pushButton_50->setObjectName(QStringLiteral("pushButton_50"));
        pushButton_50->setGeometry(QRect(580, 250, 89, 81));
        pushButton_50->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/forward_button_gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_50->setIcon(icon);
        pushButton_50->setIconSize(QSize(80, 80));
        pushButton_50->setFlat(true);
        pushButton_51 = new QPushButton(frame_2);
        pushButton_51->setObjectName(QStringLiteral("pushButton_51"));
        pushButton_51->setGeometry(QRect(160, 260, 89, 71));
        pushButton_51->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/back_button_gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_51->setIcon(icon1);
        pushButton_51->setIconSize(QSize(80, 80));
        pushButton_51->setFlat(true);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 50, 141, 21));
        label_3->setFont(font);
        plainTextEdit = new QPlainTextEdit(frame_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(390, 50, 104, 31));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush7);
        QBrush brush8(QColor(85, 87, 83, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush9(QColor(239, 235, 231, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        plainTextEdit->setPalette(palette8);
        plainTextEdit->setFont(font);
        plainTextEdit->setFocusPolicy(Qt::NoFocus);
        plainTextEdit->setFrameShape(QFrame::WinPanel);
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(350, 20, 111, 17));
        label_4->setFont(font);
        plainTextEdit_2 = new QPlainTextEdit(frame_2);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(470, 10, 121, 31));
        plainTextEdit_2->setFont(font);
        plainTextEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(600, 20, 111, 21));
        label_5->setFont(font);
        plainTextEdit_3 = new QPlainTextEdit(frame_2);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(720, 10, 104, 31));
        plainTextEdit_3->setFont(font);
        plainTextEdit_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 71, 17));
        label_6->setFont(font);
        plainTextEdit_4 = new QPlainTextEdit(frame_2);
        plainTextEdit_4->setObjectName(QStringLiteral("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(80, 10, 261, 31));
        plainTextEdit_4->setFont(font);
        plainTextEdit_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget = new QTabWidget(frame_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 70, 851, 171));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Base, brush7);
        QBrush brush10(QColor(136, 138, 133, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        tabWidget->setPalette(palette9);
        tabWidget->setFont(font);
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        checkBox_3 = new QCheckBox(tab);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(450, 10, 181, 23));
        QFont font1;
        font1.setPointSize(15);
        checkBox_3->setFont(font1);
        checkBox_6 = new QCheckBox(tab);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setGeometry(QRect(210, 40, 151, 23));
        checkBox_6->setFont(font1);
        checkBox_2 = new QCheckBox(tab);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(260, 10, 171, 23));
        checkBox_2->setFont(font1);
        checkBox_8 = new QCheckBox(tab);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));
        checkBox_8->setGeometry(QRect(570, 40, 221, 23));
        checkBox_8->setFont(font1);
        checkBox_5 = new QCheckBox(tab);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(10, 40, 161, 23));
        checkBox_5->setFont(font1);
        checkBox_7 = new QCheckBox(tab);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));
        checkBox_7->setGeometry(QRect(400, 40, 151, 23));
        checkBox_7->setFont(font1);
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(50, 10, 191, 23));
        checkBox->setFont(font1);
        checkBox_4 = new QCheckBox(tab);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(650, 10, 161, 23));
        checkBox_4->setFont(font1);
        tabWidget->addTab(tab, QString());
        tab_0 = new QWidget();
        tab_0->setObjectName(QStringLiteral("tab_0"));
        checkBox_11 = new QCheckBox(tab_0);
        checkBox_11->setObjectName(QStringLiteral("checkBox_11"));
        checkBox_11->setGeometry(QRect(640, 10, 171, 23));
        checkBox_11->setFont(font1);
        checkBox_10 = new QCheckBox(tab_0);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));
        checkBox_10->setGeometry(QRect(330, 10, 161, 23));
        checkBox_10->setFont(font1);
        checkBox_14 = new QCheckBox(tab_0);
        checkBox_14->setObjectName(QStringLiteral("checkBox_14"));
        checkBox_14->setGeometry(QRect(640, 50, 161, 23));
        checkBox_14->setFont(font1);
        checkBox_12 = new QCheckBox(tab_0);
        checkBox_12->setObjectName(QStringLiteral("checkBox_12"));
        checkBox_12->setGeometry(QRect(10, 50, 161, 23));
        checkBox_12->setFont(font1);
        checkBox_9 = new QCheckBox(tab_0);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));
        checkBox_9->setGeometry(QRect(10, 10, 161, 23));
        checkBox_9->setFont(font1);
        checkBox_13 = new QCheckBox(tab_0);
        checkBox_13->setObjectName(QStringLiteral("checkBox_13"));
        checkBox_13->setGeometry(QRect(330, 50, 161, 23));
        checkBox_13->setFont(font1);
        tabWidget->addTab(tab_0, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        checkBox_16 = new QCheckBox(tab_2);
        checkBox_16->setObjectName(QStringLiteral("checkBox_16"));
        checkBox_16->setGeometry(QRect(70, 50, 311, 23));
        checkBox_16->setFont(font1);
        checkBox_19 = new QCheckBox(tab_2);
        checkBox_19->setObjectName(QStringLiteral("checkBox_19"));
        checkBox_19->setGeometry(QRect(620, 10, 211, 23));
        checkBox_19->setFont(font1);
        checkBox_15 = new QCheckBox(tab_2);
        checkBox_15->setObjectName(QStringLiteral("checkBox_15"));
        checkBox_15->setGeometry(QRect(10, 10, 251, 23));
        checkBox_15->setFont(font1);
        checkBox_18 = new QCheckBox(tab_2);
        checkBox_18->setObjectName(QStringLiteral("checkBox_18"));
        checkBox_18->setGeometry(QRect(310, 10, 231, 23));
        checkBox_18->setFont(font1);
        checkBox_17 = new QCheckBox(tab_2);
        checkBox_17->setObjectName(QStringLiteral("checkBox_17"));
        checkBox_17->setGeometry(QRect(490, 50, 281, 23));
        checkBox_17->setFont(font1);
        tabWidget->addTab(tab_2, QString());
        frame_3 = new QFrame(manage_access_item);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(160, 379, 851, 341));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(frame_3);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 850, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(20);
        pushButton_7->setFont(font2);
        pushButton_7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_23 = new QPushButton(gridLayoutWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        sizePolicy.setHeightForWidth(pushButton_23->sizePolicy().hasHeightForWidth());
        pushButton_23->setSizePolicy(sizePolicy);
        pushButton_23->setFont(font2);
        pushButton_23->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_23, 2, 7, 1, 1);

        pushButton_39 = new QPushButton(gridLayoutWidget);
        pushButton_39->setObjectName(QStringLiteral("pushButton_39"));
        sizePolicy.setHeightForWidth(pushButton_39->sizePolicy().hasHeightForWidth());
        pushButton_39->setSizePolicy(sizePolicy);
        pushButton_39->setFont(font2);
        pushButton_39->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_39, 0, 4, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font2);
        pushButton_8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        pushButton_11->setFont(font2);
        pushButton_11->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_11, 1, 5, 1, 1);

        pushButton_19 = new QPushButton(gridLayoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        sizePolicy.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy);
        pushButton_19->setFont(font2);
        pushButton_19->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_19, 2, 3, 1, 1);

        pushButton_18 = new QPushButton(gridLayoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        sizePolicy.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy);
        pushButton_18->setFont(font2);
        pushButton_18->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_18, 2, 2, 1, 1);

        pushButton_46 = new QPushButton(gridLayoutWidget);
        pushButton_46->setObjectName(QStringLiteral("pushButton_46"));
        sizePolicy.setHeightForWidth(pushButton_46->sizePolicy().hasHeightForWidth());
        pushButton_46->setSizePolicy(sizePolicy);
        pushButton_46->setFont(font2);
        pushButton_46->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_46, 3, 8, 1, 1);

        pushButton_33 = new QPushButton(gridLayoutWidget);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        sizePolicy.setHeightForWidth(pushButton_33->sizePolicy().hasHeightForWidth());
        pushButton_33->setSizePolicy(sizePolicy);
        pushButton_33->setFont(font2);
        pushButton_33->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_33, 3, 9, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font2);
        pushButton_9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_9, 1, 2, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);
        pushButton_15->setFont(font2);
        pushButton_15->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_15, 1, 9, 1, 1);

        pushButton_42 = new QPushButton(gridLayoutWidget);
        pushButton_42->setObjectName(QStringLiteral("pushButton_42"));
        sizePolicy.setHeightForWidth(pushButton_42->sizePolicy().hasHeightForWidth());
        pushButton_42->setSizePolicy(sizePolicy);
        pushButton_42->setFont(font2);
        pushButton_42->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_42, 0, 7, 1, 1);

        pushButton_43 = new QPushButton(gridLayoutWidget);
        pushButton_43->setObjectName(QStringLiteral("pushButton_43"));
        sizePolicy.setHeightForWidth(pushButton_43->sizePolicy().hasHeightForWidth());
        pushButton_43->setSizePolicy(sizePolicy);
        pushButton_43->setFont(font2);
        pushButton_43->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_43, 0, 8, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        pushButton_10->setFont(font2);
        pushButton_10->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_10, 1, 3, 1, 1);

        pushButton_22 = new QPushButton(gridLayoutWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        sizePolicy.setHeightForWidth(pushButton_22->sizePolicy().hasHeightForWidth());
        pushButton_22->setSizePolicy(sizePolicy);
        pushButton_22->setFont(font2);
        pushButton_22->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_22, 2, 6, 1, 1);

        pushButton_35 = new QPushButton(gridLayoutWidget);
        pushButton_35->setObjectName(QStringLiteral("pushButton_35"));
        sizePolicy.setHeightForWidth(pushButton_35->sizePolicy().hasHeightForWidth());
        pushButton_35->setSizePolicy(sizePolicy);
        pushButton_35->setFont(font2);
        pushButton_35->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_35, 0, 0, 1, 1);

        pushButton_32 = new QPushButton(gridLayoutWidget);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        sizePolicy.setHeightForWidth(pushButton_32->sizePolicy().hasHeightForWidth());
        pushButton_32->setSizePolicy(sizePolicy);
        pushButton_32->setFont(font2);
        pushButton_32->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_32, 3, 7, 1, 1);

        pushButton_31 = new QPushButton(gridLayoutWidget);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        sizePolicy.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy);
        pushButton_31->setFont(font2);
        pushButton_31->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_31, 3, 6, 1, 1);

        pushButton_38 = new QPushButton(gridLayoutWidget);
        pushButton_38->setObjectName(QStringLiteral("pushButton_38"));
        sizePolicy.setHeightForWidth(pushButton_38->sizePolicy().hasHeightForWidth());
        pushButton_38->setSizePolicy(sizePolicy);
        pushButton_38->setFont(font2);
        pushButton_38->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_38, 0, 3, 1, 1);

        pushButton_20 = new QPushButton(gridLayoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        sizePolicy.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy);
        pushButton_20->setFont(font2);
        pushButton_20->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_20, 2, 4, 1, 1);

        pushButton_40 = new QPushButton(gridLayoutWidget);
        pushButton_40->setObjectName(QStringLiteral("pushButton_40"));
        sizePolicy.setHeightForWidth(pushButton_40->sizePolicy().hasHeightForWidth());
        pushButton_40->setSizePolicy(sizePolicy);
        pushButton_40->setFont(font2);
        pushButton_40->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_40, 0, 5, 1, 1);

        pushButton_27 = new QPushButton(gridLayoutWidget);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        sizePolicy.setHeightForWidth(pushButton_27->sizePolicy().hasHeightForWidth());
        pushButton_27->setSizePolicy(sizePolicy);
        pushButton_27->setFont(font2);
        pushButton_27->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_27, 3, 2, 1, 1);

        pushButton_34 = new QPushButton(gridLayoutWidget);
        pushButton_34->setObjectName(QStringLiteral("pushButton_34"));
        sizePolicy.setHeightForWidth(pushButton_34->sizePolicy().hasHeightForWidth());
        pushButton_34->setSizePolicy(sizePolicy);
        pushButton_34->setFont(font2);
        pushButton_34->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/Help_Circle_Blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_34->setIcon(icon2);
        pushButton_34->setIconSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_34, 3, 0, 1, 1);

        pushButton_44 = new QPushButton(gridLayoutWidget);
        pushButton_44->setObjectName(QStringLiteral("pushButton_44"));
        sizePolicy.setHeightForWidth(pushButton_44->sizePolicy().hasHeightForWidth());
        pushButton_44->setSizePolicy(sizePolicy);
        pushButton_44->setFont(font2);
        pushButton_44->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_44, 0, 9, 1, 1);

        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);
        pushButton_16->setFont(font2);
        pushButton_16->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_16, 2, 0, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);
        pushButton_13->setFont(font2);
        pushButton_13->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_13, 1, 7, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);
        pushButton_14->setFont(font2);
        pushButton_14->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_14, 1, 8, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        pushButton_12->setFont(font2);
        pushButton_12->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_12, 1, 4, 1, 1);

        pushButton_29 = new QPushButton(gridLayoutWidget);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        sizePolicy.setHeightForWidth(pushButton_29->sizePolicy().hasHeightForWidth());
        pushButton_29->setSizePolicy(sizePolicy);
        pushButton_29->setFont(font2);
        pushButton_29->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_29, 3, 4, 1, 1);

        pushButton_21 = new QPushButton(gridLayoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        sizePolicy.setHeightForWidth(pushButton_21->sizePolicy().hasHeightForWidth());
        pushButton_21->setSizePolicy(sizePolicy);
        pushButton_21->setFont(font2);
        pushButton_21->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_21, 2, 5, 1, 1);

        pushButton_26 = new QPushButton(gridLayoutWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        sizePolicy.setHeightForWidth(pushButton_26->sizePolicy().hasHeightForWidth());
        pushButton_26->setSizePolicy(sizePolicy);
        pushButton_26->setFont(font2);
        pushButton_26->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_26, 3, 1, 1, 1);

        pushButton_41 = new QPushButton(gridLayoutWidget);
        pushButton_41->setObjectName(QStringLiteral("pushButton_41"));
        sizePolicy.setHeightForWidth(pushButton_41->sizePolicy().hasHeightForWidth());
        pushButton_41->setSizePolicy(sizePolicy);
        pushButton_41->setFont(font2);
        pushButton_41->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_41, 0, 6, 1, 1);

        pushButton_24 = new QPushButton(gridLayoutWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        sizePolicy.setHeightForWidth(pushButton_24->sizePolicy().hasHeightForWidth());
        pushButton_24->setSizePolicy(sizePolicy);
        pushButton_24->setFont(font2);
        pushButton_24->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_24, 2, 8, 1, 1);

        pushButton_25 = new QPushButton(gridLayoutWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        sizePolicy.setHeightForWidth(pushButton_25->sizePolicy().hasHeightForWidth());
        pushButton_25->setSizePolicy(sizePolicy);
        pushButton_25->setFont(font2);
        pushButton_25->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_25, 2, 9, 1, 1);

        pushButton_37 = new QPushButton(gridLayoutWidget);
        pushButton_37->setObjectName(QStringLiteral("pushButton_37"));
        sizePolicy.setHeightForWidth(pushButton_37->sizePolicy().hasHeightForWidth());
        pushButton_37->setSizePolicy(sizePolicy);
        pushButton_37->setFont(font2);
        pushButton_37->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_37, 0, 2, 1, 1);

        pushButton_36 = new QPushButton(gridLayoutWidget);
        pushButton_36->setObjectName(QStringLiteral("pushButton_36"));
        sizePolicy.setHeightForWidth(pushButton_36->sizePolicy().hasHeightForWidth());
        pushButton_36->setSizePolicy(sizePolicy);
        pushButton_36->setFont(font2);
        pushButton_36->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_36, 0, 1, 1, 1);

        pushButton_30 = new QPushButton(gridLayoutWidget);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        sizePolicy.setHeightForWidth(pushButton_30->sizePolicy().hasHeightForWidth());
        pushButton_30->setSizePolicy(sizePolicy);
        pushButton_30->setFont(font2);
        pushButton_30->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_30, 3, 5, 1, 1);

        pushButton_17 = new QPushButton(gridLayoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        sizePolicy.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy);
        pushButton_17->setFont(font2);
        pushButton_17->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_17, 1, 6, 1, 1);

        pushButton_28 = new QPushButton(gridLayoutWidget);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        sizePolicy.setHeightForWidth(pushButton_28->sizePolicy().hasHeightForWidth());
        pushButton_28->setSizePolicy(sizePolicy);
        pushButton_28->setFont(font2);
        pushButton_28->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_28, 2, 1, 1, 1);

        pushButton_45 = new QPushButton(gridLayoutWidget);
        pushButton_45->setObjectName(QStringLiteral("pushButton_45"));
        sizePolicy.setHeightForWidth(pushButton_45->sizePolicy().hasHeightForWidth());
        pushButton_45->setSizePolicy(sizePolicy);
        pushButton_45->setFont(font2);
        pushButton_45->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_45, 3, 3, 1, 1);

        pushButton_47 = new QPushButton(frame_3);
        pushButton_47->setObjectName(QStringLiteral("pushButton_47"));
        pushButton_47->setGeometry(QRect(100, 290, 641, 41));
        pushButton_47->setFont(font2);
        pushButton_47->setFocusPolicy(Qt::NoFocus);
        pushButton_49 = new QPushButton(frame_3);
        pushButton_49->setObjectName(QStringLiteral("pushButton_49"));
        pushButton_49->setGeometry(QRect(750, 290, 89, 41));
        QFont font3;
        font3.setPointSize(17);
        pushButton_49->setFont(font3);
        pushButton_49->setFocusPolicy(Qt::NoFocus);
        pushButton_48 = new QPushButton(frame_3);
        pushButton_48->setObjectName(QStringLiteral("pushButton_48"));
        pushButton_48->setGeometry(QRect(0, 290, 89, 41));
        pushButton_48->setFont(font2);
        pushButton_48->setFocusPolicy(Qt::NoFocus);

        retranslateUi(manage_access_item);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(manage_access_item);
    } // setupUi

    void retranslateUi(QDialog *manage_access_item)
    {
        manage_access_item->setWindowTitle(QApplication::translate("manage_access_item", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("manage_access_item", "Manage Acess Item", Q_NULLPTR));
        label_2->setText(QApplication::translate("manage_access_item", "TextLabel", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("manage_access_item", "Add", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("manage_access_item", "Edit", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("manage_access_item", "Delete", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("manage_access_item", "Cancel", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("manage_access_item", "Save", Q_NULLPTR));
        pushButton->setText(QApplication::translate("manage_access_item", "Exit", Q_NULLPTR));
        pushButton_50->setText(QString());
        pushButton_51->setText(QString());
        label_3->setText(QApplication::translate("manage_access_item", "Permission # : ", Q_NULLPTR));
        label_4->setText(QApplication::translate("manage_access_item", "Start Time : ", Q_NULLPTR));
        label_5->setText(QApplication::translate("manage_access_item", "Stop Time : ", Q_NULLPTR));
        label_6->setText(QApplication::translate("manage_access_item", "Name : ", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("manage_access_item", "Wednesday", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("manage_access_item", "Saturday", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("manage_access_item", "Tuesday", Q_NULLPTR));
        checkBox_8->setText(QApplication::translate("manage_access_item", "All Days", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("manage_access_item", "Friday", Q_NULLPTR));
        checkBox_7->setText(QApplication::translate("manage_access_item", "Sunday", Q_NULLPTR));
        checkBox->setText(QApplication::translate("manage_access_item", "Monday", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("manage_access_item", "Thursday", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("manage_access_item", "Days", Q_NULLPTR));
        checkBox_11->setText(QApplication::translate("manage_access_item", "Lock 3 Enabled", Q_NULLPTR));
        checkBox_10->setText(QApplication::translate("manage_access_item", "Lock 2 Enabled", Q_NULLPTR));
        checkBox_14->setText(QApplication::translate("manage_access_item", "Lock 6 Enabled", Q_NULLPTR));
        checkBox_12->setText(QApplication::translate("manage_access_item", "Lock 4 Enabled", Q_NULLPTR));
        checkBox_9->setText(QApplication::translate("manage_access_item", "Lock 1 enabled", Q_NULLPTR));
        checkBox_13->setText(QApplication::translate("manage_access_item", "Lock 5 Enabled", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_0), QApplication::translate("manage_access_item", "Locks", Q_NULLPTR));
        checkBox_16->setText(QApplication::translate("manage_access_item", "Can Manage Access Groups", Q_NULLPTR));
        checkBox_19->setText(QApplication::translate("manage_access_item", "Can Modify Users", Q_NULLPTR));
        checkBox_15->setText(QApplication::translate("manage_access_item", "Can Access Log Button", Q_NULLPTR));
        checkBox_18->setText(QApplication::translate("manage_access_item", "Can Modify System", Q_NULLPTR));
        checkBox_17->setText(QApplication::translate("manage_access_item", "Can Manage Access Items", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("manage_access_item", "Options", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("manage_access_item", "Q", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("manage_access_item", "K", Q_NULLPTR));
        pushButton_39->setText(QApplication::translate("manage_access_item", "5", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("manage_access_item", "W", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("manage_access_item", "Y", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("manage_access_item", "F", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("manage_access_item", "D", Q_NULLPTR));
        pushButton_46->setText(QApplication::translate("manage_access_item", ":", Q_NULLPTR));
        pushButton_33->setText(QApplication::translate("manage_access_item", "Clear", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("manage_access_item", "E", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("manage_access_item", "P", Q_NULLPTR));
        pushButton_42->setText(QApplication::translate("manage_access_item", "8", Q_NULLPTR));
        pushButton_43->setText(QApplication::translate("manage_access_item", "9", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("manage_access_item", "R", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("manage_access_item", "J", Q_NULLPTR));
        pushButton_35->setText(QApplication::translate("manage_access_item", "1", Q_NULLPTR));
        pushButton_32->setText(QApplication::translate("manage_access_item", "M", Q_NULLPTR));
        pushButton_31->setText(QApplication::translate("manage_access_item", "N", Q_NULLPTR));
        pushButton_38->setText(QApplication::translate("manage_access_item", "4", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("manage_access_item", "G", Q_NULLPTR));
        pushButton_40->setText(QApplication::translate("manage_access_item", "6", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("manage_access_item", "X", Q_NULLPTR));
        pushButton_34->setText(QString());
        pushButton_44->setText(QApplication::translate("manage_access_item", "0", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("manage_access_item", "A", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("manage_access_item", "I", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("manage_access_item", "O", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("manage_access_item", "T", Q_NULLPTR));
        pushButton_29->setText(QApplication::translate("manage_access_item", "V", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("manage_access_item", "H", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("manage_access_item", "Z", Q_NULLPTR));
        pushButton_41->setText(QApplication::translate("manage_access_item", "7", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("manage_access_item", "L", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("manage_access_item", "Enter", Q_NULLPTR));
        pushButton_37->setText(QApplication::translate("manage_access_item", "3", Q_NULLPTR));
        pushButton_36->setText(QApplication::translate("manage_access_item", "2", Q_NULLPTR));
        pushButton_30->setText(QApplication::translate("manage_access_item", "B", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("manage_access_item", "U", Q_NULLPTR));
        pushButton_28->setText(QApplication::translate("manage_access_item", "S", Q_NULLPTR));
        pushButton_45->setText(QApplication::translate("manage_access_item", "C", Q_NULLPTR));
        pushButton_47->setText(QApplication::translate("manage_access_item", "Space", Q_NULLPTR));
        pushButton_49->setText(QApplication::translate("manage_access_item", "BCKSPC", Q_NULLPTR));
        pushButton_48->setText(QApplication::translate("manage_access_item", "TAB", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class manage_access_item: public Ui_manage_access_item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGE_ACCESS_ITEM_H
