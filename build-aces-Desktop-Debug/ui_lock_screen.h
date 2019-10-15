/********************************************************************************
** Form generated from reading UI file 'lock_screen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCK_SCREEN_H
#define UI_LOCK_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lock_screen
{
public:
    QGraphicsView *graphicsView;
    QFrame *frame;
    QLabel *label;
    QGraphicsView *graphicsView_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QPushButton *pushButton_8;
    QPushButton *pushButton_11;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView_4;
    QGraphicsView *graphicsView_5;
    QGraphicsView *graphicsView_6;
    QGraphicsView *graphicsView_7;
    QFrame *frame_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_12;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QDialog *lock_screen)
    {
        if (lock_screen->objectName().isEmpty())
            lock_screen->setObjectName(QStringLiteral("lock_screen"));
        lock_screen->resize(1024, 768);
        graphicsView = new QGraphicsView(lock_screen);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1024, 768));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        frame = new QFrame(lock_screen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(180, 10, 831, 711));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 811, 31));
        QPalette palette;
        QBrush brush(QColor(243, 245, 174, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(78, 154, 6, 255));
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
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Sunken);
        label->setAlignment(Qt::AlignCenter);
        graphicsView_2 = new QGraphicsView(frame);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(10, 50, 250, 141));
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 200, 250, 98));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
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
        pushButton_6->setPalette(palette1);
        QIcon icon;
        icon.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/newBlackLock.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon);
        pushButton_6->setIconSize(QSize(50, 50));
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(10, 600, 250, 97));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_9->setPalette(palette2);
        pushButton_9->setIcon(icon);
        pushButton_9->setIconSize(QSize(50, 50));
        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(290, 200, 250, 98));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_7->setPalette(palette3);
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(50, 50));
        pushButton_10 = new QPushButton(frame);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(290, 600, 250, 97));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_10->setPalette(palette4);
        pushButton_10->setIcon(icon);
        pushButton_10->setIconSize(QSize(50, 50));
        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(560, 200, 250, 98));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_8->setPalette(palette5);
        pushButton_8->setIcon(icon);
        pushButton_8->setIconSize(QSize(50, 50));
        pushButton_11 = new QPushButton(frame);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(560, 600, 250, 97));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_11->setPalette(palette6);
        pushButton_11->setIcon(icon);
        pushButton_11->setIconSize(QSize(50, 50));
        graphicsView_3 = new QGraphicsView(frame);
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(290, 50, 251, 141));
        graphicsView_4 = new QGraphicsView(frame);
        graphicsView_4->setObjectName(QStringLiteral("graphicsView_4"));
        graphicsView_4->setGeometry(QRect(560, 50, 251, 141));
        graphicsView_5 = new QGraphicsView(frame);
        graphicsView_5->setObjectName(QStringLiteral("graphicsView_5"));
        graphicsView_5->setGeometry(QRect(10, 450, 251, 141));
        graphicsView_6 = new QGraphicsView(frame);
        graphicsView_6->setObjectName(QStringLiteral("graphicsView_6"));
        graphicsView_6->setGeometry(QRect(290, 450, 251, 141));
        graphicsView_7 = new QGraphicsView(frame);
        graphicsView_7->setObjectName(QStringLiteral("graphicsView_7"));
        graphicsView_7->setGeometry(QRect(560, 450, 251, 141));
        frame_2 = new QFrame(lock_screen);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 161, 711));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 139, 691));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_5->setPalette(palette7);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/black-key.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon1);
        pushButton_5->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_4->setPalette(palette8);
        QIcon icon2;
        icon2.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/Keys-Silhouette.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_2->setPalette(palette9);
        QIcon icon3;
        icon3.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/black_lock.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);
        pushButton_2->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_3->setPalette(palette10);
        QIcon icon4;
        icon4.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/black_gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(pushButton_3);

        pushButton_12 = new QPushButton(verticalLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton_12->setPalette(palette11);
        QIcon icon5;
        icon5.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/black-log.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon5);
        pushButton_12->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(pushButton_12);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        pushButton->setPalette(palette12);
        QIcon icon6;
        icon6.addFile(QStringLiteral("../build-aces-Desktop-Debug/icons/black-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon6);
        pushButton->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(pushButton);

        label_2 = new QLabel(lock_screen);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 730, 1031, 41));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush6(QColor(164, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        label_2->setPalette(palette13);
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        label_2->setAutoFillBackground(true);
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(lock_screen);

        QMetaObject::connectSlotsByName(lock_screen);
    } // setupUi

    void retranslateUi(QDialog *lock_screen)
    {
        lock_screen->setWindowTitle(QApplication::translate("lock_screen", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("lock_screen", "Lock Control Window", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("lock_screen", " Lock 1 Control", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("lock_screen", " Lock 4 Control", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("lock_screen", " Lock 2 Control", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("lock_screen", " Lock 5 Control", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("lock_screen", " Lock 3 Control", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("lock_screen", " Lock 6 Control", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("lock_screen", " Access Item", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("lock_screen", " Access Group", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("lock_screen", " Users", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("lock_screen", " System ", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("lock_screen", "  Logs", Q_NULLPTR));
        pushButton->setText(QApplication::translate("lock_screen", "  Exit", Q_NULLPTR));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class lock_screen: public Ui_lock_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCK_SCREEN_H
