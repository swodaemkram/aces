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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkSettings
{
public:
    QFrame *frame;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_4;
    QLabel *label_9;
    QCheckBox *checkBox_2;
    QPlainTextEdit *plainTextEdit;
    QWidget *tab_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QTimeEdit *timeEdit;
    QPushButton *pushButton_2;
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
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *NetworkSettings)
    {
        if (NetworkSettings->objectName().isEmpty())
            NetworkSettings->setObjectName(QStringLiteral("NetworkSettings"));
        NetworkSettings->resize(1024, 768);
        frame = new QFrame(NetworkSettings);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 40, 1001, 691));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 981, 281));
        QFont font;
        font.setPointSize(14);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 981, 31));
        QPalette palette;
        QBrush brush(QColor(252, 175, 62, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        label_4->setPalette(palette);
        label_4->setAutoFillBackground(true);
        label_4->setFrameShape(QFrame::WinPanel);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 70, 161, 41));
        checkBox_2 = new QCheckBox(tab);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 40, 221, 23));
        plainTextEdit = new QPlainTextEdit(tab);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(170, 70, 791, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 981, 31));
        QPalette palette1;
        QBrush brush1(QColor(233, 185, 110, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_3->setPalette(palette1);
        label_3->setAutoFillBackground(true);
        label_3->setFrameShape(QFrame::WinPanel);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setAlignment(Qt::AlignCenter);
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 60, 151, 23));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 60, 121, 17));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 100, 171, 17));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 160, 151, 17));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 200, 191, 17));
        plainTextEdit_2 = new QPlainTextEdit(tab_2);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(300, 40, 661, 41));
        plainTextEdit_3 = new QPlainTextEdit(tab_2);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(180, 90, 371, 41));
        plainTextEdit_4 = new QPlainTextEdit(tab_2);
        plainTextEdit_4->setObjectName(QStringLiteral("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(180, 140, 371, 41));
        timeEdit = new QTimeEdit(tab_2);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(210, 185, 201, 41));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 90, 401, 91));
        tabWidget->addTab(tab_2, QString());
        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(130, 290, 861, 381));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        pushButton_47 = new QPushButton(frame_4);
        pushButton_47->setObjectName(QStringLiteral("pushButton_47"));
        pushButton_47->setGeometry(QRect(0, 330, 71, 51));
        QFont font1;
        font1.setPointSize(20);
        pushButton_47->setFont(font1);
        pushButton_47->setFocusPolicy(Qt::NoFocus);
        pushButton_45 = new QPushButton(frame_4);
        pushButton_45->setObjectName(QStringLiteral("pushButton_45"));
        pushButton_45->setGeometry(QRect(80, 340, 641, 41));
        pushButton_45->setFont(font1);
        pushButton_45->setFocusPolicy(Qt::NoFocus);
        pushButton_48 = new QPushButton(frame_4);
        pushButton_48->setObjectName(QStringLiteral("pushButton_48"));
        pushButton_48->setGeometry(QRect(740, 330, 111, 51));
        pushButton_48->setFont(font1);
        pushButton_48->setFocusPolicy(Qt::NoFocus);
        gridLayoutWidget = new QWidget(frame_4);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(7, 20, 838, 311));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font1);
        pushButton_6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_23 = new QPushButton(gridLayoutWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        sizePolicy.setHeightForWidth(pushButton_23->sizePolicy().hasHeightForWidth());
        pushButton_23->setSizePolicy(sizePolicy);
        pushButton_23->setFont(font1);
        pushButton_23->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_23, 2, 7, 1, 1);

        pushButton_39 = new QPushButton(gridLayoutWidget);
        pushButton_39->setObjectName(QStringLiteral("pushButton_39"));
        sizePolicy.setHeightForWidth(pushButton_39->sizePolicy().hasHeightForWidth());
        pushButton_39->setSizePolicy(sizePolicy);
        pushButton_39->setFont(font1);
        pushButton_39->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_39, 0, 4, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setFont(font1);
        pushButton_7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        pushButton_11->setFont(font1);
        pushButton_11->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_11, 1, 5, 1, 1);

        pushButton_19 = new QPushButton(gridLayoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        sizePolicy.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy);
        pushButton_19->setFont(font1);
        pushButton_19->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_19, 2, 3, 1, 1);

        pushButton_18 = new QPushButton(gridLayoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        sizePolicy.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy);
        pushButton_18->setFont(font1);
        pushButton_18->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_18, 2, 2, 1, 1);

        pushButton_46 = new QPushButton(gridLayoutWidget);
        pushButton_46->setObjectName(QStringLiteral("pushButton_46"));
        sizePolicy.setHeightForWidth(pushButton_46->sizePolicy().hasHeightForWidth());
        pushButton_46->setSizePolicy(sizePolicy);
        pushButton_46->setFont(font1);
        pushButton_46->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_46, 3, 8, 1, 1);

        pushButton_33 = new QPushButton(gridLayoutWidget);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        sizePolicy.setHeightForWidth(pushButton_33->sizePolicy().hasHeightForWidth());
        pushButton_33->setSizePolicy(sizePolicy);
        pushButton_33->setFont(font1);
        pushButton_33->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_33, 3, 9, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font1);
        pushButton_8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);
        pushButton_15->setFont(font1);
        pushButton_15->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_15, 1, 9, 1, 1);

        pushButton_42 = new QPushButton(gridLayoutWidget);
        pushButton_42->setObjectName(QStringLiteral("pushButton_42"));
        sizePolicy.setHeightForWidth(pushButton_42->sizePolicy().hasHeightForWidth());
        pushButton_42->setSizePolicy(sizePolicy);
        pushButton_42->setFont(font1);
        pushButton_42->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_42, 0, 7, 1, 1);

        pushButton_43 = new QPushButton(gridLayoutWidget);
        pushButton_43->setObjectName(QStringLiteral("pushButton_43"));
        sizePolicy.setHeightForWidth(pushButton_43->sizePolicy().hasHeightForWidth());
        pushButton_43->setSizePolicy(sizePolicy);
        pushButton_43->setFont(font1);
        pushButton_43->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_43, 0, 8, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font1);
        pushButton_9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_9, 1, 3, 1, 1);

        pushButton_22 = new QPushButton(gridLayoutWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        sizePolicy.setHeightForWidth(pushButton_22->sizePolicy().hasHeightForWidth());
        pushButton_22->setSizePolicy(sizePolicy);
        pushButton_22->setFont(font1);
        pushButton_22->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_22, 2, 6, 1, 1);

        pushButton_35 = new QPushButton(gridLayoutWidget);
        pushButton_35->setObjectName(QStringLiteral("pushButton_35"));
        sizePolicy.setHeightForWidth(pushButton_35->sizePolicy().hasHeightForWidth());
        pushButton_35->setSizePolicy(sizePolicy);
        pushButton_35->setFont(font1);
        pushButton_35->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_35, 0, 0, 1, 1);

        pushButton_32 = new QPushButton(gridLayoutWidget);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        sizePolicy.setHeightForWidth(pushButton_32->sizePolicy().hasHeightForWidth());
        pushButton_32->setSizePolicy(sizePolicy);
        pushButton_32->setFont(font1);
        pushButton_32->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_32, 3, 7, 1, 1);

        pushButton_31 = new QPushButton(gridLayoutWidget);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        sizePolicy.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy);
        pushButton_31->setFont(font1);
        pushButton_31->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_31, 3, 6, 1, 1);

        pushButton_38 = new QPushButton(gridLayoutWidget);
        pushButton_38->setObjectName(QStringLiteral("pushButton_38"));
        sizePolicy.setHeightForWidth(pushButton_38->sizePolicy().hasHeightForWidth());
        pushButton_38->setSizePolicy(sizePolicy);
        pushButton_38->setFont(font1);
        pushButton_38->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_38, 0, 3, 1, 1);

        pushButton_20 = new QPushButton(gridLayoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        sizePolicy.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy);
        pushButton_20->setFont(font1);
        pushButton_20->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_20, 2, 4, 1, 1);

        pushButton_40 = new QPushButton(gridLayoutWidget);
        pushButton_40->setObjectName(QStringLiteral("pushButton_40"));
        sizePolicy.setHeightForWidth(pushButton_40->sizePolicy().hasHeightForWidth());
        pushButton_40->setSizePolicy(sizePolicy);
        pushButton_40->setFont(font1);
        pushButton_40->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_40, 0, 5, 1, 1);

        pushButton_27 = new QPushButton(gridLayoutWidget);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        sizePolicy.setHeightForWidth(pushButton_27->sizePolicy().hasHeightForWidth());
        pushButton_27->setSizePolicy(sizePolicy);
        pushButton_27->setFont(font1);
        pushButton_27->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_27, 3, 2, 1, 1);

        pushButton_34 = new QPushButton(gridLayoutWidget);
        pushButton_34->setObjectName(QStringLiteral("pushButton_34"));
        sizePolicy.setHeightForWidth(pushButton_34->sizePolicy().hasHeightForWidth());
        pushButton_34->setSizePolicy(sizePolicy);
        pushButton_34->setFont(font1);
        pushButton_34->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/Help_Circle_Blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_34->setIcon(icon);
        pushButton_34->setIconSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_34, 3, 0, 1, 1);

        pushButton_44 = new QPushButton(gridLayoutWidget);
        pushButton_44->setObjectName(QStringLiteral("pushButton_44"));
        sizePolicy.setHeightForWidth(pushButton_44->sizePolicy().hasHeightForWidth());
        pushButton_44->setSizePolicy(sizePolicy);
        pushButton_44->setFont(font1);
        pushButton_44->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_44, 0, 9, 1, 1);

        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);
        pushButton_16->setFont(font1);
        pushButton_16->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_16, 2, 0, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);
        pushButton_13->setFont(font1);
        pushButton_13->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_13, 1, 7, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);
        pushButton_14->setFont(font1);
        pushButton_14->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_14, 1, 8, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        pushButton_10->setFont(font1);
        pushButton_10->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_10, 1, 4, 1, 1);

        pushButton_29 = new QPushButton(gridLayoutWidget);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        sizePolicy.setHeightForWidth(pushButton_29->sizePolicy().hasHeightForWidth());
        pushButton_29->setSizePolicy(sizePolicy);
        pushButton_29->setFont(font1);
        pushButton_29->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_29, 3, 4, 1, 1);

        pushButton_21 = new QPushButton(gridLayoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        sizePolicy.setHeightForWidth(pushButton_21->sizePolicy().hasHeightForWidth());
        pushButton_21->setSizePolicy(sizePolicy);
        pushButton_21->setFont(font1);
        pushButton_21->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_21, 2, 5, 1, 1);

        pushButton_26 = new QPushButton(gridLayoutWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        sizePolicy.setHeightForWidth(pushButton_26->sizePolicy().hasHeightForWidth());
        pushButton_26->setSizePolicy(sizePolicy);
        pushButton_26->setFont(font1);
        pushButton_26->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_26, 3, 1, 1, 1);

        pushButton_41 = new QPushButton(gridLayoutWidget);
        pushButton_41->setObjectName(QStringLiteral("pushButton_41"));
        sizePolicy.setHeightForWidth(pushButton_41->sizePolicy().hasHeightForWidth());
        pushButton_41->setSizePolicy(sizePolicy);
        pushButton_41->setFont(font1);
        pushButton_41->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_41, 0, 6, 1, 1);

        pushButton_24 = new QPushButton(gridLayoutWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        sizePolicy.setHeightForWidth(pushButton_24->sizePolicy().hasHeightForWidth());
        pushButton_24->setSizePolicy(sizePolicy);
        pushButton_24->setFont(font1);
        pushButton_24->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_24, 2, 8, 1, 1);

        pushButton_25 = new QPushButton(gridLayoutWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        sizePolicy.setHeightForWidth(pushButton_25->sizePolicy().hasHeightForWidth());
        pushButton_25->setSizePolicy(sizePolicy);
        pushButton_25->setFont(font1);
        pushButton_25->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_25, 2, 9, 1, 1);

        pushButton_37 = new QPushButton(gridLayoutWidget);
        pushButton_37->setObjectName(QStringLiteral("pushButton_37"));
        sizePolicy.setHeightForWidth(pushButton_37->sizePolicy().hasHeightForWidth());
        pushButton_37->setSizePolicy(sizePolicy);
        pushButton_37->setFont(font1);
        pushButton_37->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_37, 0, 2, 1, 1);

        pushButton_36 = new QPushButton(gridLayoutWidget);
        pushButton_36->setObjectName(QStringLiteral("pushButton_36"));
        sizePolicy.setHeightForWidth(pushButton_36->sizePolicy().hasHeightForWidth());
        pushButton_36->setSizePolicy(sizePolicy);
        pushButton_36->setFont(font1);
        pushButton_36->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_36, 0, 1, 1, 1);

        pushButton_30 = new QPushButton(gridLayoutWidget);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        sizePolicy.setHeightForWidth(pushButton_30->sizePolicy().hasHeightForWidth());
        pushButton_30->setSizePolicy(sizePolicy);
        pushButton_30->setFont(font1);
        pushButton_30->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_30, 3, 5, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        pushButton_12->setFont(font1);
        pushButton_12->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_12, 1, 6, 1, 1);

        pushButton_17 = new QPushButton(gridLayoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        sizePolicy.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy);
        pushButton_17->setFont(font1);
        pushButton_17->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_17, 2, 1, 1, 1);

        pushButton_28 = new QPushButton(gridLayoutWidget);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        sizePolicy.setHeightForWidth(pushButton_28->sizePolicy().hasHeightForWidth());
        pushButton_28->setSizePolicy(sizePolicy);
        pushButton_28->setFont(font1);
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
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 290, 121, 391));
        pushButton->setFont(font);
        label = new QLabel(NetworkSettings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1031, 31));
        QPalette palette2;
        QBrush brush2(QColor(138, 226, 52, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label->setPalette(palette2);
        label->setFont(font);
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Sunken);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(NetworkSettings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 730, 1031, 41));
        QPalette palette3;
        QBrush brush3(QColor(243, 245, 174, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        QBrush brush4(QColor(164, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush5(QColor(190, 190, 190, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        label_2->setPalette(palette3);
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu Condensed"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setAutoFillBackground(true);
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(NetworkSettings);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NetworkSettings);
    } // setupUi

    void retranslateUi(QDialog *NetworkSettings)
    {
        NetworkSettings->setWindowTitle(QApplication::translate("NetworkSettings", "Dialog", Q_NULLPTR));
        label_4->setText(QApplication::translate("NetworkSettings", "Cloud Server Settings", Q_NULLPTR));
        label_9->setText(QApplication::translate("NetworkSettings", "Cloud Server URL : ", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("NetworkSettings", "Cloud Server Enabled : ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("NetworkSettings", "Cloud Server Settings", Q_NULLPTR));
        label_3->setText(QApplication::translate("NetworkSettings", "Email Server Settings", Q_NULLPTR));
        checkBox->setText(QApplication::translate("NetworkSettings", "Enable E-Mail :", Q_NULLPTR));
        label_5->setText(QApplication::translate("NetworkSettings", "SMTP Server :", Q_NULLPTR));
        label_6->setText(QApplication::translate("NetworkSettings", "SMTP User Name : ", Q_NULLPTR));
        label_7->setText(QApplication::translate("NetworkSettings", "SMTP Password : ", Q_NULLPTR));
        label_8->setText(QApplication::translate("NetworkSettings", "Time to Send E-Mail : ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("NetworkSettings", "Send Test Email", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("NetworkSettings", "E-Mail Server Settings", Q_NULLPTR));
        pushButton_47->setText(QApplication::translate("NetworkSettings", "TAB", Q_NULLPTR));
        pushButton_45->setText(QApplication::translate("NetworkSettings", "Space", Q_NULLPTR));
        pushButton_48->setText(QApplication::translate("NetworkSettings", "BCKSPC", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("NetworkSettings", "Q", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("NetworkSettings", "K", Q_NULLPTR));
        pushButton_39->setText(QApplication::translate("NetworkSettings", "5", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("NetworkSettings", "W", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("NetworkSettings", "Y", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("NetworkSettings", "F", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("NetworkSettings", "D", Q_NULLPTR));
        pushButton_46->setText(QApplication::translate("NetworkSettings", "/", Q_NULLPTR));
        pushButton_33->setText(QApplication::translate("NetworkSettings", "CLR", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("NetworkSettings", "E", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("NetworkSettings", "P", Q_NULLPTR));
        pushButton_42->setText(QApplication::translate("NetworkSettings", "8", Q_NULLPTR));
        pushButton_43->setText(QApplication::translate("NetworkSettings", "9", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("NetworkSettings", "R", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("NetworkSettings", "J", Q_NULLPTR));
        pushButton_35->setText(QApplication::translate("NetworkSettings", "1", Q_NULLPTR));
        pushButton_32->setText(QApplication::translate("NetworkSettings", "M", Q_NULLPTR));
        pushButton_31->setText(QApplication::translate("NetworkSettings", "N", Q_NULLPTR));
        pushButton_38->setText(QApplication::translate("NetworkSettings", "4", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("NetworkSettings", "G", Q_NULLPTR));
        pushButton_40->setText(QApplication::translate("NetworkSettings", "6", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("NetworkSettings", "X", Q_NULLPTR));
        pushButton_34->setText(QString());
        pushButton_44->setText(QApplication::translate("NetworkSettings", "0", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("NetworkSettings", "A", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("NetworkSettings", "I", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("NetworkSettings", "O", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("NetworkSettings", "T", Q_NULLPTR));
        pushButton_29->setText(QApplication::translate("NetworkSettings", "V", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("NetworkSettings", "H", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("NetworkSettings", "Z", Q_NULLPTR));
        pushButton_41->setText(QApplication::translate("NetworkSettings", "7", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("NetworkSettings", "L", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("NetworkSettings", ":", Q_NULLPTR));
        pushButton_37->setText(QApplication::translate("NetworkSettings", "3", Q_NULLPTR));
        pushButton_36->setText(QApplication::translate("NetworkSettings", "2", Q_NULLPTR));
        pushButton_30->setText(QApplication::translate("NetworkSettings", "B", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("NetworkSettings", "U", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("NetworkSettings", "S", Q_NULLPTR));
        pushButton_28->setText(QApplication::translate("NetworkSettings", "C", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NetworkSettings", "Exit/Save", Q_NULLPTR));
        label->setText(QApplication::translate("NetworkSettings", "Network Settings", Q_NULLPTR));
        label_2->setText(QApplication::translate("NetworkSettings", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NetworkSettings: public Ui_NetworkSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKSETTINGS_H
