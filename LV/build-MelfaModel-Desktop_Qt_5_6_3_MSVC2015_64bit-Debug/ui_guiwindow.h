/********************************************************************************
** Form generated from reading UI file 'guiwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIWINDOW_H
#define UI_GUIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "openglwindow.h"

QT_BEGIN_NAMESPACE

class Ui_GuiWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    OpenGLWindow *widget;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QPushButton *btnInc_6;
    QPushButton *btnInc_5;
    QPushButton *btnInc_3;
    QPushButton *btnDec_5;
    QPushButton *btnInc_2;
    QPushButton *btnDec_1;
    QPushButton *btnInc_1;
    QPushButton *btnDec_3;
    QPushButton *btnDec_2;
    QPushButton *btnDec_6;
    QPushButton *pushButton;

    void setupUi(QMainWindow *GuiWindow)
    {
        if (GuiWindow->objectName().isEmpty())
            GuiWindow->setObjectName(QStringLiteral("GuiWindow"));
        GuiWindow->resize(882, 600);
        centralwidget = new QWidget(GuiWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new OpenGLWindow(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(600, 0));
        widget1 = new QWidget(widget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(0, 10, 862, 191));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnInc_6 = new QPushButton(widget1);
        btnInc_6->setObjectName(QStringLiteral("btnInc_6"));
        btnInc_6->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnInc_6, 4, 1, 1, 1);

        btnInc_5 = new QPushButton(widget1);
        btnInc_5->setObjectName(QStringLiteral("btnInc_5"));
        btnInc_5->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnInc_5, 3, 1, 1, 1);

        btnInc_3 = new QPushButton(widget1);
        btnInc_3->setObjectName(QStringLiteral("btnInc_3"));
        btnInc_3->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnInc_3, 2, 1, 1, 1);

        btnDec_5 = new QPushButton(widget1);
        btnDec_5->setObjectName(QStringLiteral("btnDec_5"));
        btnDec_5->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnDec_5, 3, 0, 1, 1);

        btnInc_2 = new QPushButton(widget1);
        btnInc_2->setObjectName(QStringLiteral("btnInc_2"));
        btnInc_2->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnInc_2, 1, 1, 1, 1);

        btnDec_1 = new QPushButton(widget1);
        btnDec_1->setObjectName(QStringLiteral("btnDec_1"));
        btnDec_1->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnDec_1, 0, 0, 1, 1);

        btnInc_1 = new QPushButton(widget1);
        btnInc_1->setObjectName(QStringLiteral("btnInc_1"));
        btnInc_1->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnInc_1, 0, 1, 1, 1);

        btnDec_3 = new QPushButton(widget1);
        btnDec_3->setObjectName(QStringLiteral("btnDec_3"));
        btnDec_3->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnDec_3, 2, 0, 1, 1);

        btnDec_2 = new QPushButton(widget1);
        btnDec_2->setObjectName(QStringLiteral("btnDec_2"));
        btnDec_2->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnDec_2, 1, 0, 1, 1);

        btnDec_6 = new QPushButton(widget1);
        btnDec_6->setObjectName(QStringLiteral("btnDec_6"));
        btnDec_6->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(btnDec_6, 4, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 200, 748, 23));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(10000, 16777215));
        pushButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(widget);


        horizontalLayout->addLayout(verticalLayout);

        GuiWindow->setCentralWidget(centralwidget);

        retranslateUi(GuiWindow);

        QMetaObject::connectSlotsByName(GuiWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GuiWindow)
    {
        GuiWindow->setWindowTitle(QApplication::translate("GuiWindow", "MainWindow", Q_NULLPTR));
        btnInc_6->setText(QApplication::translate("GuiWindow", "+J6", Q_NULLPTR));
        btnInc_5->setText(QApplication::translate("GuiWindow", "+J5", Q_NULLPTR));
        btnInc_3->setText(QApplication::translate("GuiWindow", "+J3", Q_NULLPTR));
        btnDec_5->setText(QApplication::translate("GuiWindow", "-J5", Q_NULLPTR));
        btnInc_2->setText(QApplication::translate("GuiWindow", "+J2", Q_NULLPTR));
        btnDec_1->setText(QApplication::translate("GuiWindow", "-J1", Q_NULLPTR));
        btnInc_1->setText(QApplication::translate("GuiWindow", "+J1", Q_NULLPTR));
        btnDec_3->setText(QApplication::translate("GuiWindow", "-J3", Q_NULLPTR));
        btnDec_2->setText(QApplication::translate("GuiWindow", "-J2", Q_NULLPTR));
        btnDec_6->setText(QApplication::translate("GuiWindow", "-J6", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GuiWindow", "Home", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiWindow: public Ui_GuiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIWINDOW_H
