/********************************************************************************
** Form generated from reading UI file 'access_group.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCESS_GROUP_H
#define UI_ACCESS_GROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Access_Group
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QTableView *tableView;
    QFrame *frame_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_49;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
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
    QPushButton *pushButton_6;
    QPushButton *pushButton_47;
    QPushButton *pushButton_48;

    void setupUi(QDialog *Access_Group)
    {
        if (Access_Group->objectName().isEmpty())
            Access_Group->setObjectName(QStringLiteral("Access_Group"));
        Access_Group->resize(1024, 768);
        graphicsView = new QGraphicsView(Access_Group);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1024, 768));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(Access_Group);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 851, 31));
        QPalette palette;
        QBrush brush(QColor(243, 245, 174, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(52, 101, 164, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(190, 190, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label->setPalette(palette);
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Sunken);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Access_Group);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 730, 1001, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(164, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        label_2->setPalette(palette1);
        label_2->setAutoFillBackground(true);
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);
        frame = new QFrame(Access_Group);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(160, 50, 851, 121));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tableView = new QTableView(frame);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 831, 101));
        QFont font1;
        font1.setPointSize(8);
        tableView->setFont(font1);
        frame_2 = new QFrame(Access_Group);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 141, 711));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 121, 691));
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
        QBrush brush5(QColor(46, 52, 54, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_2->setPalette(palette2);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_3->setPalette(palette3);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_4->setPalette(palette4);

        verticalLayout->addWidget(pushButton_4);

        pushButton_49 = new QPushButton(verticalLayoutWidget);
        pushButton_49->setObjectName(QStringLiteral("pushButton_49"));
        sizePolicy.setHeightForWidth(pushButton_49->sizePolicy().hasHeightForWidth());
        pushButton_49->setSizePolicy(sizePolicy);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_49->setPalette(palette5);

        verticalLayout->addWidget(pushButton_49);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton_5->setPalette(palette6);

        verticalLayout->addWidget(pushButton_5);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QPalette palette7;
        QBrush brush6(QColor(136, 138, 133, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pushButton->setPalette(palette7);

        verticalLayout->addWidget(pushButton);

        gridLayoutWidget = new QWidget(Access_Group);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(157, 420, 851, 261));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_23 = new QPushButton(gridLayoutWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        sizePolicy.setHeightForWidth(pushButton_23->sizePolicy().hasHeightForWidth());
        pushButton_23->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_23, 2, 7, 1, 1);

        pushButton_39 = new QPushButton(gridLayoutWidget);
        pushButton_39->setObjectName(QStringLiteral("pushButton_39"));
        sizePolicy.setHeightForWidth(pushButton_39->sizePolicy().hasHeightForWidth());
        pushButton_39->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_39, 0, 4, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_11, 1, 5, 1, 1);

        pushButton_19 = new QPushButton(gridLayoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        sizePolicy.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_19, 2, 3, 1, 1);

        pushButton_18 = new QPushButton(gridLayoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        sizePolicy.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_18, 2, 2, 1, 1);

        pushButton_46 = new QPushButton(gridLayoutWidget);
        pushButton_46->setObjectName(QStringLiteral("pushButton_46"));
        sizePolicy.setHeightForWidth(pushButton_46->sizePolicy().hasHeightForWidth());
        pushButton_46->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_46, 3, 8, 1, 1);

        pushButton_33 = new QPushButton(gridLayoutWidget);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        sizePolicy.setHeightForWidth(pushButton_33->sizePolicy().hasHeightForWidth());
        pushButton_33->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_33, 3, 9, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_9, 1, 2, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_15, 1, 9, 1, 1);

        pushButton_42 = new QPushButton(gridLayoutWidget);
        pushButton_42->setObjectName(QStringLiteral("pushButton_42"));
        sizePolicy.setHeightForWidth(pushButton_42->sizePolicy().hasHeightForWidth());
        pushButton_42->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_42, 0, 7, 1, 1);

        pushButton_43 = new QPushButton(gridLayoutWidget);
        pushButton_43->setObjectName(QStringLiteral("pushButton_43"));
        sizePolicy.setHeightForWidth(pushButton_43->sizePolicy().hasHeightForWidth());
        pushButton_43->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_43, 0, 8, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_10, 1, 3, 1, 1);

        pushButton_22 = new QPushButton(gridLayoutWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        sizePolicy.setHeightForWidth(pushButton_22->sizePolicy().hasHeightForWidth());
        pushButton_22->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_22, 2, 6, 1, 1);

        pushButton_35 = new QPushButton(gridLayoutWidget);
        pushButton_35->setObjectName(QStringLiteral("pushButton_35"));
        sizePolicy.setHeightForWidth(pushButton_35->sizePolicy().hasHeightForWidth());
        pushButton_35->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_35, 0, 0, 1, 1);

        pushButton_32 = new QPushButton(gridLayoutWidget);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        sizePolicy.setHeightForWidth(pushButton_32->sizePolicy().hasHeightForWidth());
        pushButton_32->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_32, 3, 7, 1, 1);

        pushButton_31 = new QPushButton(gridLayoutWidget);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        sizePolicy.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_31, 3, 6, 1, 1);

        pushButton_38 = new QPushButton(gridLayoutWidget);
        pushButton_38->setObjectName(QStringLiteral("pushButton_38"));
        sizePolicy.setHeightForWidth(pushButton_38->sizePolicy().hasHeightForWidth());
        pushButton_38->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_38, 0, 3, 1, 1);

        pushButton_20 = new QPushButton(gridLayoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        sizePolicy.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_20, 2, 4, 1, 1);

        pushButton_40 = new QPushButton(gridLayoutWidget);
        pushButton_40->setObjectName(QStringLiteral("pushButton_40"));
        sizePolicy.setHeightForWidth(pushButton_40->sizePolicy().hasHeightForWidth());
        pushButton_40->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_40, 0, 5, 1, 1);

        pushButton_27 = new QPushButton(gridLayoutWidget);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        sizePolicy.setHeightForWidth(pushButton_27->sizePolicy().hasHeightForWidth());
        pushButton_27->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_27, 3, 2, 1, 1);

        pushButton_34 = new QPushButton(gridLayoutWidget);
        pushButton_34->setObjectName(QStringLiteral("pushButton_34"));
        sizePolicy.setHeightForWidth(pushButton_34->sizePolicy().hasHeightForWidth());
        pushButton_34->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_34, 3, 0, 1, 1);

        pushButton_44 = new QPushButton(gridLayoutWidget);
        pushButton_44->setObjectName(QStringLiteral("pushButton_44"));
        sizePolicy.setHeightForWidth(pushButton_44->sizePolicy().hasHeightForWidth());
        pushButton_44->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_44, 0, 9, 1, 1);

        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_16, 2, 0, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_13, 1, 7, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_14, 1, 8, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_12, 1, 4, 1, 1);

        pushButton_29 = new QPushButton(gridLayoutWidget);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        sizePolicy.setHeightForWidth(pushButton_29->sizePolicy().hasHeightForWidth());
        pushButton_29->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_29, 3, 4, 1, 1);

        pushButton_21 = new QPushButton(gridLayoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        sizePolicy.setHeightForWidth(pushButton_21->sizePolicy().hasHeightForWidth());
        pushButton_21->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_21, 2, 5, 1, 1);

        pushButton_26 = new QPushButton(gridLayoutWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        sizePolicy.setHeightForWidth(pushButton_26->sizePolicy().hasHeightForWidth());
        pushButton_26->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_26, 3, 1, 1, 1);

        pushButton_41 = new QPushButton(gridLayoutWidget);
        pushButton_41->setObjectName(QStringLiteral("pushButton_41"));
        sizePolicy.setHeightForWidth(pushButton_41->sizePolicy().hasHeightForWidth());
        pushButton_41->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_41, 0, 6, 1, 1);

        pushButton_24 = new QPushButton(gridLayoutWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        sizePolicy.setHeightForWidth(pushButton_24->sizePolicy().hasHeightForWidth());
        pushButton_24->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_24, 2, 8, 1, 1);

        pushButton_25 = new QPushButton(gridLayoutWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        sizePolicy.setHeightForWidth(pushButton_25->sizePolicy().hasHeightForWidth());
        pushButton_25->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_25, 2, 9, 1, 1);

        pushButton_37 = new QPushButton(gridLayoutWidget);
        pushButton_37->setObjectName(QStringLiteral("pushButton_37"));
        sizePolicy.setHeightForWidth(pushButton_37->sizePolicy().hasHeightForWidth());
        pushButton_37->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_37, 0, 2, 1, 1);

        pushButton_36 = new QPushButton(gridLayoutWidget);
        pushButton_36->setObjectName(QStringLiteral("pushButton_36"));
        sizePolicy.setHeightForWidth(pushButton_36->sizePolicy().hasHeightForWidth());
        pushButton_36->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_36, 0, 1, 1, 1);

        pushButton_30 = new QPushButton(gridLayoutWidget);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        sizePolicy.setHeightForWidth(pushButton_30->sizePolicy().hasHeightForWidth());
        pushButton_30->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_30, 3, 5, 1, 1);

        pushButton_17 = new QPushButton(gridLayoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        sizePolicy.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_17, 1, 6, 1, 1);

        pushButton_28 = new QPushButton(gridLayoutWidget);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        sizePolicy.setHeightForWidth(pushButton_28->sizePolicy().hasHeightForWidth());
        pushButton_28->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_28, 2, 1, 1, 1);

        pushButton_45 = new QPushButton(gridLayoutWidget);
        pushButton_45->setObjectName(QStringLiteral("pushButton_45"));
        sizePolicy.setHeightForWidth(pushButton_45->sizePolicy().hasHeightForWidth());
        pushButton_45->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_45, 3, 3, 1, 1);

        pushButton_6 = new QPushButton(Access_Group);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(300, 684, 571, 41));
        pushButton_47 = new QPushButton(Access_Group);
        pushButton_47->setObjectName(QStringLiteral("pushButton_47"));
        pushButton_47->setGeometry(QRect(160, 690, 131, 31));
        pushButton_48 = new QPushButton(Access_Group);
        pushButton_48->setObjectName(QStringLiteral("pushButton_48"));
        pushButton_48->setGeometry(QRect(880, 690, 121, 31));

        retranslateUi(Access_Group);

        QMetaObject::connectSlotsByName(Access_Group);
    } // setupUi

    void retranslateUi(QDialog *Access_Group)
    {
        Access_Group->setWindowTitle(QApplication::translate("Access_Group", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Access_Group", "Manage Access Group Screen", Q_NULLPTR));
        label_2->setText(QString());
        pushButton_2->setText(QApplication::translate("Access_Group", "Add", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Access_Group", "Edit", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Access_Group", "Delete", Q_NULLPTR));
        pushButton_49->setText(QApplication::translate("Access_Group", "Cancel", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Access_Group", "Save", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Access_Group", "Exit", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Access_Group", "Q", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("Access_Group", "K", Q_NULLPTR));
        pushButton_39->setText(QApplication::translate("Access_Group", "5", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Access_Group", "W", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("Access_Group", "Y", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("Access_Group", "F", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("Access_Group", "D", Q_NULLPTR));
        pushButton_46->setText(QApplication::translate("Access_Group", "/", Q_NULLPTR));
        pushButton_33->setText(QApplication::translate("Access_Group", "Shift", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Access_Group", "E", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("Access_Group", "P", Q_NULLPTR));
        pushButton_42->setText(QApplication::translate("Access_Group", "8", Q_NULLPTR));
        pushButton_43->setText(QApplication::translate("Access_Group", "9", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("Access_Group", "R", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("Access_Group", "J", Q_NULLPTR));
        pushButton_35->setText(QApplication::translate("Access_Group", "1", Q_NULLPTR));
        pushButton_32->setText(QApplication::translate("Access_Group", "M", Q_NULLPTR));
        pushButton_31->setText(QApplication::translate("Access_Group", "N", Q_NULLPTR));
        pushButton_38->setText(QApplication::translate("Access_Group", "4", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("Access_Group", "G", Q_NULLPTR));
        pushButton_40->setText(QApplication::translate("Access_Group", "6", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("Access_Group", "X", Q_NULLPTR));
        pushButton_34->setText(QApplication::translate("Access_Group", "Shift", Q_NULLPTR));
        pushButton_44->setText(QApplication::translate("Access_Group", "0", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("Access_Group", "A", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("Access_Group", "I", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("Access_Group", "O", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("Access_Group", "T", Q_NULLPTR));
        pushButton_29->setText(QApplication::translate("Access_Group", "V", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("Access_Group", "H", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("Access_Group", "Z", Q_NULLPTR));
        pushButton_41->setText(QApplication::translate("Access_Group", "7", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("Access_Group", "L", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("Access_Group", "Enter", Q_NULLPTR));
        pushButton_37->setText(QApplication::translate("Access_Group", "3", Q_NULLPTR));
        pushButton_36->setText(QApplication::translate("Access_Group", "2", Q_NULLPTR));
        pushButton_30->setText(QApplication::translate("Access_Group", "B", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("Access_Group", "U", Q_NULLPTR));
        pushButton_28->setText(QApplication::translate("Access_Group", "S", Q_NULLPTR));
        pushButton_45->setText(QApplication::translate("Access_Group", "C", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Access_Group", "Space", Q_NULLPTR));
        pushButton_47->setText(QApplication::translate("Access_Group", "TAB", Q_NULLPTR));
        pushButton_48->setText(QApplication::translate("Access_Group", "BCKSPC", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Access_Group: public Ui_Access_Group {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCESS_GROUP_H
