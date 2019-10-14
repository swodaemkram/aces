/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QFrame *frame_2;
    QLabel *label_9;
    QPlainTextEdit *plainTextEdit_7;
    QLabel *label_10;
    QPlainTextEdit *plainTextEdit_8;
    QFrame *frame_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_6;
    QTextEdit *textEdit;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QPlainTextEdit *plainTextEdit_5;
    QPlainTextEdit *plainTextEdit_6;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
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

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QStringLiteral("settings"));
        settings->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(settings->sizePolicy().hasHeightForWidth());
        settings->setSizePolicy(sizePolicy);
        graphicsView = new QGraphicsView(settings);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1024, 768));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(settings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 0, 851, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(46, 52, 54, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush2(QColor(85, 87, 83, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
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
        label_2 = new QLabel(settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-10, 740, 1041, 31));
        QPalette palette1;
        QBrush brush4(QColor(252, 233, 79, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush5(QColor(243, 245, 174, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        QBrush brush6(QColor(164, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        label_2->setPalette(palette1);
        label_2->setFont(font);
        label_2->setAutoFillBackground(true);
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);
        frame = new QFrame(settings);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 151, 721));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 9, 137, 701));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(20);
        pushButton_3->setFont(font1);
        pushButton_3->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(17);
        pushButton_2->setFont(font2);
        pushButton_2->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(18);
        pushButton->setFont(font3);

        verticalLayout->addWidget(pushButton);

        frame_2 = new QFrame(settings);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(170, 40, 841, 241));
        frame_2->setAutoFillBackground(true);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 10, 231, 31));
        label_9->setFont(font);
        label_9->setAutoFillBackground(true);
        label_9->setFrameShape(QFrame::WinPanel);
        label_9->setFrameShadow(QFrame::Sunken);
        plainTextEdit_7 = new QPlainTextEdit(frame_2);
        plainTextEdit_7->setObjectName(QStringLiteral("plainTextEdit_7"));
        plainTextEdit_7->setGeometry(QRect(250, 10, 201, 31));
        plainTextEdit_7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_7->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(460, 10, 181, 31));
        label_10->setFont(font);
        label_10->setAutoFillBackground(true);
        label_10->setFrameShape(QFrame::WinPanel);
        label_10->setFrameShadow(QFrame::Sunken);
        plainTextEdit_8 = new QPlainTextEdit(frame_2);
        plainTextEdit_8->setObjectName(QStringLiteral("plainTextEdit_8"));
        plainTextEdit_8->setGeometry(QRect(650, 10, 181, 31));
        plainTextEdit_8->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_8->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 50, 821, 181));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 111, 31));
        QFont font4;
        font4.setPointSize(16);
        label_3->setFont(font4);
        label_3->setAutoFillBackground(true);
        label_3->setFrameShape(QFrame::WinPanel);
        label_3->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 50, 111, 31));
        label_4->setFont(font);
        label_4->setAutoFillBackground(true);
        label_4->setFrameShape(QFrame::WinPanel);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 10, 161, 31));
        label_5->setFont(font);
        label_5->setAutoFillBackground(true);
        label_5->setFrameShape(QFrame::WinPanel);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setAlignment(Qt::AlignCenter);
        plainTextEdit = new QPlainTextEdit(frame_3);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(130, 50, 161, 31));
        plainTextEdit->setFont(font);
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 10, 111, 31));
        label_6->setFont(font);
        label_6->setAutoFillBackground(true);
        label_6->setFrameShape(QFrame::WinPanel);
        label_6->setFrameShadow(QFrame::Sunken);
        textEdit = new QTextEdit(frame_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(300, 50, 111, 31));
        textEdit->setFont(font);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 90, 111, 31));
        label_7->setFont(font);
        label_7->setAutoFillBackground(true);
        label_7->setFrameShape(QFrame::WinPanel);
        label_7->setFrameShadow(QFrame::Sunken);
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 130, 111, 31));
        label_8->setFont(font);
        label_8->setAutoFillBackground(true);
        label_8->setFrameShape(QFrame::WinPanel);
        label_8->setFrameShadow(QFrame::Sunken);
        label_8->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(420, 50, 111, 31));
        label_11->setFont(font);
        label_11->setAutoFillBackground(true);
        label_11->setFrameShape(QFrame::WinPanel);
        label_11->setFrameShadow(QFrame::Sunken);
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(420, 90, 111, 31));
        label_12->setFont(font);
        label_12->setAutoFillBackground(true);
        label_12->setFrameShape(QFrame::WinPanel);
        label_12->setFrameShadow(QFrame::Sunken);
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(420, 130, 111, 31));
        label_13->setFont(font);
        label_13->setAutoFillBackground(true);
        label_13->setFrameShape(QFrame::WinPanel);
        label_13->setFrameShadow(QFrame::Sunken);
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(frame_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(420, 10, 111, 31));
        label_14->setFont(font4);
        label_14->setAutoFillBackground(true);
        label_14->setFrameShape(QFrame::WinPanel);
        label_14->setFrameShadow(QFrame::Sunken);
        label_15 = new QLabel(frame_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(540, 10, 151, 31));
        label_15->setFont(font);
        label_15->setAutoFillBackground(true);
        label_15->setFrameShape(QFrame::WinPanel);
        label_15->setFrameShadow(QFrame::Sunken);
        label_15->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(frame_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(700, 10, 111, 31));
        label_16->setFont(font);
        label_16->setAutoFillBackground(true);
        label_16->setFrameShape(QFrame::WinPanel);
        label_16->setFrameShadow(QFrame::Sunken);
        plainTextEdit_2 = new QPlainTextEdit(frame_3);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(130, 90, 161, 31));
        plainTextEdit_2->setFont(font);
        plainTextEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_3 = new QPlainTextEdit(frame_3);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(130, 130, 161, 31));
        plainTextEdit_3->setFont(font);
        plainTextEdit_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_4 = new QPlainTextEdit(frame_3);
        plainTextEdit_4->setObjectName(QStringLiteral("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(540, 50, 151, 31));
        plainTextEdit_4->setFont(font);
        plainTextEdit_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_5 = new QPlainTextEdit(frame_3);
        plainTextEdit_5->setObjectName(QStringLiteral("plainTextEdit_5"));
        plainTextEdit_5->setGeometry(QRect(540, 90, 151, 31));
        plainTextEdit_5->setFont(font);
        plainTextEdit_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_6 = new QPlainTextEdit(frame_3);
        plainTextEdit_6->setObjectName(QStringLiteral("plainTextEdit_6"));
        plainTextEdit_6->setGeometry(QRect(540, 130, 151, 31));
        plainTextEdit_6->setFont(font);
        plainTextEdit_6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_2 = new QTextEdit(frame_3);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(300, 90, 111, 31));
        textEdit_2->setFont(font);
        textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_3 = new QTextEdit(frame_3);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(300, 130, 111, 31));
        textEdit_3->setFont(font);
        textEdit_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_4 = new QTextEdit(frame_3);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(700, 50, 111, 31));
        textEdit_4->setFont(font);
        textEdit_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_5 = new QTextEdit(frame_3);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(700, 90, 111, 31));
        textEdit_5->setFont(font);
        textEdit_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_6 = new QTextEdit(frame_3);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(700, 130, 111, 31));
        textEdit_6->setFont(font);
        textEdit_6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        frame_4 = new QFrame(settings);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(170, 350, 841, 381));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        pushButton_47 = new QPushButton(frame_4);
        pushButton_47->setObjectName(QStringLiteral("pushButton_47"));
        pushButton_47->setGeometry(QRect(0, 340, 61, 41));
        pushButton_47->setFont(font1);
        pushButton_47->setFocusPolicy(Qt::NoFocus);
        pushButton_45 = new QPushButton(frame_4);
        pushButton_45->setObjectName(QStringLiteral("pushButton_45"));
        pushButton_45->setGeometry(QRect(70, 340, 641, 41));
        pushButton_45->setFont(font1);
        pushButton_45->setFocusPolicy(Qt::NoFocus);
        pushButton_48 = new QPushButton(frame_4);
        pushButton_48->setObjectName(QStringLiteral("pushButton_48"));
        pushButton_48->setGeometry(QRect(720, 340, 111, 41));
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
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setFont(font1);
        pushButton_6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_23 = new QPushButton(gridLayoutWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        sizePolicy1.setHeightForWidth(pushButton_23->sizePolicy().hasHeightForWidth());
        pushButton_23->setSizePolicy(sizePolicy1);
        pushButton_23->setFont(font1);
        pushButton_23->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_23, 2, 7, 1, 1);

        pushButton_39 = new QPushButton(gridLayoutWidget);
        pushButton_39->setObjectName(QStringLiteral("pushButton_39"));
        sizePolicy1.setHeightForWidth(pushButton_39->sizePolicy().hasHeightForWidth());
        pushButton_39->setSizePolicy(sizePolicy1);
        pushButton_39->setFont(font1);
        pushButton_39->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_39, 0, 4, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setFont(font1);
        pushButton_7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);
        pushButton_11->setFont(font1);
        pushButton_11->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_11, 1, 5, 1, 1);

        pushButton_19 = new QPushButton(gridLayoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        sizePolicy1.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy1);
        pushButton_19->setFont(font1);
        pushButton_19->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_19, 2, 3, 1, 1);

        pushButton_18 = new QPushButton(gridLayoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        sizePolicy1.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy1);
        pushButton_18->setFont(font1);
        pushButton_18->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_18, 2, 2, 1, 1);

        pushButton_46 = new QPushButton(gridLayoutWidget);
        pushButton_46->setObjectName(QStringLiteral("pushButton_46"));
        sizePolicy1.setHeightForWidth(pushButton_46->sizePolicy().hasHeightForWidth());
        pushButton_46->setSizePolicy(sizePolicy1);
        pushButton_46->setFont(font1);
        pushButton_46->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_46, 3, 8, 1, 1);

        pushButton_33 = new QPushButton(gridLayoutWidget);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        sizePolicy1.setHeightForWidth(pushButton_33->sizePolicy().hasHeightForWidth());
        pushButton_33->setSizePolicy(sizePolicy1);
        pushButton_33->setFont(font1);
        pushButton_33->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_33, 3, 9, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setFont(font1);
        pushButton_8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy1.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy1);
        pushButton_15->setFont(font1);
        pushButton_15->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_15, 1, 9, 1, 1);

        pushButton_42 = new QPushButton(gridLayoutWidget);
        pushButton_42->setObjectName(QStringLiteral("pushButton_42"));
        sizePolicy1.setHeightForWidth(pushButton_42->sizePolicy().hasHeightForWidth());
        pushButton_42->setSizePolicy(sizePolicy1);
        pushButton_42->setFont(font1);
        pushButton_42->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_42, 0, 7, 1, 1);

        pushButton_43 = new QPushButton(gridLayoutWidget);
        pushButton_43->setObjectName(QStringLiteral("pushButton_43"));
        sizePolicy1.setHeightForWidth(pushButton_43->sizePolicy().hasHeightForWidth());
        pushButton_43->setSizePolicy(sizePolicy1);
        pushButton_43->setFont(font1);
        pushButton_43->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_43, 0, 8, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setFont(font1);
        pushButton_9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_9, 1, 3, 1, 1);

        pushButton_22 = new QPushButton(gridLayoutWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        sizePolicy1.setHeightForWidth(pushButton_22->sizePolicy().hasHeightForWidth());
        pushButton_22->setSizePolicy(sizePolicy1);
        pushButton_22->setFont(font1);
        pushButton_22->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_22, 2, 6, 1, 1);

        pushButton_35 = new QPushButton(gridLayoutWidget);
        pushButton_35->setObjectName(QStringLiteral("pushButton_35"));
        sizePolicy1.setHeightForWidth(pushButton_35->sizePolicy().hasHeightForWidth());
        pushButton_35->setSizePolicy(sizePolicy1);
        pushButton_35->setFont(font1);
        pushButton_35->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_35, 0, 0, 1, 1);

        pushButton_32 = new QPushButton(gridLayoutWidget);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        sizePolicy1.setHeightForWidth(pushButton_32->sizePolicy().hasHeightForWidth());
        pushButton_32->setSizePolicy(sizePolicy1);
        pushButton_32->setFont(font1);
        pushButton_32->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_32, 3, 7, 1, 1);

        pushButton_31 = new QPushButton(gridLayoutWidget);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        sizePolicy1.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy1);
        pushButton_31->setFont(font1);
        pushButton_31->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_31, 3, 6, 1, 1);

        pushButton_38 = new QPushButton(gridLayoutWidget);
        pushButton_38->setObjectName(QStringLiteral("pushButton_38"));
        sizePolicy1.setHeightForWidth(pushButton_38->sizePolicy().hasHeightForWidth());
        pushButton_38->setSizePolicy(sizePolicy1);
        pushButton_38->setFont(font1);
        pushButton_38->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_38, 0, 3, 1, 1);

        pushButton_20 = new QPushButton(gridLayoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        sizePolicy1.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy1);
        pushButton_20->setFont(font1);
        pushButton_20->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_20, 2, 4, 1, 1);

        pushButton_40 = new QPushButton(gridLayoutWidget);
        pushButton_40->setObjectName(QStringLiteral("pushButton_40"));
        sizePolicy1.setHeightForWidth(pushButton_40->sizePolicy().hasHeightForWidth());
        pushButton_40->setSizePolicy(sizePolicy1);
        pushButton_40->setFont(font1);
        pushButton_40->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_40, 0, 5, 1, 1);

        pushButton_27 = new QPushButton(gridLayoutWidget);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        sizePolicy1.setHeightForWidth(pushButton_27->sizePolicy().hasHeightForWidth());
        pushButton_27->setSizePolicy(sizePolicy1);
        pushButton_27->setFont(font1);
        pushButton_27->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_27, 3, 2, 1, 1);

        pushButton_34 = new QPushButton(gridLayoutWidget);
        pushButton_34->setObjectName(QStringLiteral("pushButton_34"));
        sizePolicy1.setHeightForWidth(pushButton_34->sizePolicy().hasHeightForWidth());
        pushButton_34->setSizePolicy(sizePolicy1);
        pushButton_34->setFont(font1);
        pushButton_34->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/Help_Circle_Blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_34->setIcon(icon);
        pushButton_34->setIconSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_34, 3, 0, 1, 1);

        pushButton_44 = new QPushButton(gridLayoutWidget);
        pushButton_44->setObjectName(QStringLiteral("pushButton_44"));
        sizePolicy1.setHeightForWidth(pushButton_44->sizePolicy().hasHeightForWidth());
        pushButton_44->setSizePolicy(sizePolicy1);
        pushButton_44->setFont(font1);
        pushButton_44->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_44, 0, 9, 1, 1);

        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        sizePolicy1.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy1);
        pushButton_16->setFont(font1);
        pushButton_16->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_16, 2, 0, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy1.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy1);
        pushButton_13->setFont(font1);
        pushButton_13->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_13, 1, 7, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy1.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy1);
        pushButton_14->setFont(font1);
        pushButton_14->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_14, 1, 8, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);
        pushButton_10->setFont(font1);
        pushButton_10->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_10, 1, 4, 1, 1);

        pushButton_29 = new QPushButton(gridLayoutWidget);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        sizePolicy1.setHeightForWidth(pushButton_29->sizePolicy().hasHeightForWidth());
        pushButton_29->setSizePolicy(sizePolicy1);
        pushButton_29->setFont(font1);
        pushButton_29->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_29, 3, 4, 1, 1);

        pushButton_21 = new QPushButton(gridLayoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        sizePolicy1.setHeightForWidth(pushButton_21->sizePolicy().hasHeightForWidth());
        pushButton_21->setSizePolicy(sizePolicy1);
        pushButton_21->setFont(font1);
        pushButton_21->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_21, 2, 5, 1, 1);

        pushButton_26 = new QPushButton(gridLayoutWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        sizePolicy1.setHeightForWidth(pushButton_26->sizePolicy().hasHeightForWidth());
        pushButton_26->setSizePolicy(sizePolicy1);
        pushButton_26->setFont(font1);
        pushButton_26->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_26, 3, 1, 1, 1);

        pushButton_41 = new QPushButton(gridLayoutWidget);
        pushButton_41->setObjectName(QStringLiteral("pushButton_41"));
        sizePolicy1.setHeightForWidth(pushButton_41->sizePolicy().hasHeightForWidth());
        pushButton_41->setSizePolicy(sizePolicy1);
        pushButton_41->setFont(font1);
        pushButton_41->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_41, 0, 6, 1, 1);

        pushButton_24 = new QPushButton(gridLayoutWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        sizePolicy1.setHeightForWidth(pushButton_24->sizePolicy().hasHeightForWidth());
        pushButton_24->setSizePolicy(sizePolicy1);
        pushButton_24->setFont(font1);
        pushButton_24->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_24, 2, 8, 1, 1);

        pushButton_25 = new QPushButton(gridLayoutWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        sizePolicy1.setHeightForWidth(pushButton_25->sizePolicy().hasHeightForWidth());
        pushButton_25->setSizePolicy(sizePolicy1);
        pushButton_25->setFont(font1);
        pushButton_25->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_25, 2, 9, 1, 1);

        pushButton_37 = new QPushButton(gridLayoutWidget);
        pushButton_37->setObjectName(QStringLiteral("pushButton_37"));
        sizePolicy1.setHeightForWidth(pushButton_37->sizePolicy().hasHeightForWidth());
        pushButton_37->setSizePolicy(sizePolicy1);
        pushButton_37->setFont(font1);
        pushButton_37->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_37, 0, 2, 1, 1);

        pushButton_36 = new QPushButton(gridLayoutWidget);
        pushButton_36->setObjectName(QStringLiteral("pushButton_36"));
        sizePolicy1.setHeightForWidth(pushButton_36->sizePolicy().hasHeightForWidth());
        pushButton_36->setSizePolicy(sizePolicy1);
        pushButton_36->setFont(font1);
        pushButton_36->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_36, 0, 1, 1, 1);

        pushButton_30 = new QPushButton(gridLayoutWidget);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        sizePolicy1.setHeightForWidth(pushButton_30->sizePolicy().hasHeightForWidth());
        pushButton_30->setSizePolicy(sizePolicy1);
        pushButton_30->setFont(font1);
        pushButton_30->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_30, 3, 5, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy1.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy1);
        pushButton_12->setFont(font1);
        pushButton_12->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_12, 1, 6, 1, 1);

        pushButton_17 = new QPushButton(gridLayoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        sizePolicy1.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy1);
        pushButton_17->setFont(font1);
        pushButton_17->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_17, 2, 1, 1, 1);

        pushButton_28 = new QPushButton(gridLayoutWidget);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        sizePolicy1.setHeightForWidth(pushButton_28->sizePolicy().hasHeightForWidth());
        pushButton_28->setSizePolicy(sizePolicy1);
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

        retranslateUi(settings);

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("settings", "System Settings", Q_NULLPTR));
        label_2->setText(QApplication::translate("settings", "DO NOT CHANGE UNLESS YOU KNOW EXACTLY WHAT YOU ARE DOING !!!", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("settings", "Network", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("settings", "Date / Time", Q_NULLPTR));
        pushButton->setText(QApplication::translate("settings", "Exit", Q_NULLPTR));
        label_9->setText(QApplication::translate("settings", "Days Befor PIN Change : ", Q_NULLPTR));
        label_10->setText(QApplication::translate("settings", "Door Alarm Delay : ", Q_NULLPTR));
        label_3->setText(QApplication::translate("settings", "Door/lock", Q_NULLPTR));
        label_4->setText(QApplication::translate("settings", "1", Q_NULLPTR));
        label_5->setText(QApplication::translate("settings", "Name", Q_NULLPTR));
        label_6->setText(QApplication::translate("settings", "dr/opn/dly", Q_NULLPTR));
        label_7->setText(QApplication::translate("settings", "2", Q_NULLPTR));
        label_8->setText(QApplication::translate("settings", "3", Q_NULLPTR));
        label_11->setText(QApplication::translate("settings", "4", Q_NULLPTR));
        label_12->setText(QApplication::translate("settings", "5", Q_NULLPTR));
        label_13->setText(QApplication::translate("settings", "6", Q_NULLPTR));
        label_14->setText(QApplication::translate("settings", "Door/lock", Q_NULLPTR));
        label_15->setText(QApplication::translate("settings", "Name", Q_NULLPTR));
        label_16->setText(QApplication::translate("settings", "dr/opn/dly", Q_NULLPTR));
        pushButton_47->setText(QApplication::translate("settings", "TAB", Q_NULLPTR));
        pushButton_45->setText(QApplication::translate("settings", "Space", Q_NULLPTR));
        pushButton_48->setText(QApplication::translate("settings", "BCKSPC", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("settings", "Q", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("settings", "K", Q_NULLPTR));
        pushButton_39->setText(QApplication::translate("settings", "5", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("settings", "W", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("settings", "Y", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("settings", "F", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("settings", "D", Q_NULLPTR));
        pushButton_46->setText(QApplication::translate("settings", "/", Q_NULLPTR));
        pushButton_33->setText(QApplication::translate("settings", "CLR", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("settings", "E", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("settings", "P", Q_NULLPTR));
        pushButton_42->setText(QApplication::translate("settings", "8", Q_NULLPTR));
        pushButton_43->setText(QApplication::translate("settings", "9", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("settings", "R", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("settings", "J", Q_NULLPTR));
        pushButton_35->setText(QApplication::translate("settings", "1", Q_NULLPTR));
        pushButton_32->setText(QApplication::translate("settings", "M", Q_NULLPTR));
        pushButton_31->setText(QApplication::translate("settings", "N", Q_NULLPTR));
        pushButton_38->setText(QApplication::translate("settings", "4", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("settings", "G", Q_NULLPTR));
        pushButton_40->setText(QApplication::translate("settings", "6", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("settings", "X", Q_NULLPTR));
        pushButton_34->setText(QString());
        pushButton_44->setText(QApplication::translate("settings", "0", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("settings", "A", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("settings", "I", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("settings", "O", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("settings", "T", Q_NULLPTR));
        pushButton_29->setText(QApplication::translate("settings", "V", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("settings", "H", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("settings", "Z", Q_NULLPTR));
        pushButton_41->setText(QApplication::translate("settings", "7", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("settings", "L", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("settings", "Enter", Q_NULLPTR));
        pushButton_37->setText(QApplication::translate("settings", "3", Q_NULLPTR));
        pushButton_36->setText(QApplication::translate("settings", "2", Q_NULLPTR));
        pushButton_30->setText(QApplication::translate("settings", "B", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("settings", "U", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("settings", "S", Q_NULLPTR));
        pushButton_28->setText(QApplication::translate("settings", "C", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
