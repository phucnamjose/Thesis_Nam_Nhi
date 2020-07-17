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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
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
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Comport;
    QComboBox *comboBox_Comport;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Baudrate;
    QComboBox *comboBox_Baudrate;
    QPushButton *pushButton_Connect;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Velocity;
    QSlider *sliderVelocity;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_Accelerate;
    QSlider *sliderAccerlerate;
    QGroupBox *groupBox_2;
    QLabel *label_Camera;
    QPushButton *pushButton_StartCamera;
    QTextEdit *textEdit_Position;
    QTextEdit *textEdit_Inform;
    QTextEdit *textEdit_Waring;
    QLabel *label_Error;
    QLabel *label_Warning;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_Home;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_SetROI;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_Scan;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Paint;
    OpenGLWindow *widget;

    void setupUi(QMainWindow *GuiWindow)
    {
        if (GuiWindow->objectName().isEmpty())
            GuiWindow->setObjectName(QStringLiteral("GuiWindow"));
        GuiWindow->resize(1218, 597);
        centralwidget = new QWidget(GuiWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 181, 126));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Comport = new QLabel(layoutWidget);
        label_Comport->setObjectName(QStringLiteral("label_Comport"));

        horizontalLayout_2->addWidget(label_Comport);

        comboBox_Comport = new QComboBox(layoutWidget);
        comboBox_Comport->setObjectName(QStringLiteral("comboBox_Comport"));

        horizontalLayout_2->addWidget(comboBox_Comport);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Baudrate = new QLabel(layoutWidget);
        label_Baudrate->setObjectName(QStringLiteral("label_Baudrate"));

        horizontalLayout_3->addWidget(label_Baudrate);

        comboBox_Baudrate = new QComboBox(layoutWidget);
        comboBox_Baudrate->setObjectName(QStringLiteral("comboBox_Baudrate"));

        horizontalLayout_3->addWidget(comboBox_Baudrate);


        verticalLayout_2->addLayout(horizontalLayout_3);

        pushButton_Connect = new QPushButton(layoutWidget);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        pushButton_Connect->setStyleSheet(QLatin1String("#pushButton_Connect\n"
"{\n"
"color: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-radius:10px;\n"
"background-color:gray;\n"
"}"));

        verticalLayout_2->addWidget(pushButton_Connect);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_Velocity = new QLabel(layoutWidget);
        label_Velocity->setObjectName(QStringLiteral("label_Velocity"));

        verticalLayout_3->addWidget(label_Velocity);

        sliderVelocity = new QSlider(layoutWidget);
        sliderVelocity->setObjectName(QStringLiteral("sliderVelocity"));
        sliderVelocity->setMinimum(1);
        sliderVelocity->setMaximum(100);
        sliderVelocity->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(sliderVelocity);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_Accelerate = new QLabel(layoutWidget);
        label_Accelerate->setObjectName(QStringLiteral("label_Accelerate"));

        verticalLayout_4->addWidget(label_Accelerate);

        sliderAccerlerate = new QSlider(layoutWidget);
        sliderAccerlerate->setObjectName(QStringLiteral("sliderAccerlerate"));
        sliderAccerlerate->setMinimum(1);
        sliderAccerlerate->setMaximum(100);
        sliderAccerlerate->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(sliderAccerlerate);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 150, 411, 411));
        label_Camera = new QLabel(groupBox_2);
        label_Camera->setObjectName(QStringLiteral("label_Camera"));
        label_Camera->setGeometry(QRect(0, 20, 260, 200));
        label_Camera->setMinimumSize(QSize(260, 200));
        label_Camera->setMaximumSize(QSize(260, 200));
        label_Camera->setFrameShape(QFrame::Box);
        label_Camera->setFrameShadow(QFrame::Raised);
        label_Camera->setLineWidth(5);
        pushButton_StartCamera = new QPushButton(groupBox_2);
        pushButton_StartCamera->setObjectName(QStringLiteral("pushButton_StartCamera"));
        pushButton_StartCamera->setGeometry(QRect(260, 200, 31, 31));
        pushButton_StartCamera->setStyleSheet(QLatin1String("#pushButton_StartCamera\n"
"{\n"
"border:none;\n"
"}"));
        textEdit_Position = new QTextEdit(groupBox_2);
        textEdit_Position->setObjectName(QStringLiteral("textEdit_Position"));
        textEdit_Position->setGeometry(QRect(270, 250, 131, 151));
        textEdit_Inform = new QTextEdit(groupBox_2);
        textEdit_Inform->setObjectName(QStringLiteral("textEdit_Inform"));
        textEdit_Inform->setGeometry(QRect(0, 250, 261, 91));
        textEdit_Waring = new QTextEdit(groupBox_2);
        textEdit_Waring->setObjectName(QStringLiteral("textEdit_Waring"));
        textEdit_Waring->setGeometry(QRect(0, 360, 261, 61));
        label_Error = new QLabel(groupBox_2);
        label_Error->setObjectName(QStringLiteral("label_Error"));
        label_Error->setGeometry(QRect(10, 230, 47, 13));
        label_Error->setStyleSheet(QLatin1String("#label_Error\n"
"{\n"
"color: red;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-color:darkblue;\n"
"}"));
        label_Warning = new QLabel(groupBox_2);
        label_Warning->setObjectName(QStringLiteral("label_Warning"));
        label_Warning->setGeometry(QRect(10, 340, 61, 16));
        label_Warning->setStyleSheet(QLatin1String("#label_Warning\n"
"{\n"
"color:yellow;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-color:darkblue;\n"
"}"));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(200, 20, 101, 121));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_Home = new QPushButton(layoutWidget1);
        pushButton_Home->setObjectName(QStringLiteral("pushButton_Home"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Home->sizePolicy().hasHeightForWidth());
        pushButton_Home->setSizePolicy(sizePolicy);
        pushButton_Home->setMaximumSize(QSize(10000, 16777215));
        pushButton_Home->setLayoutDirection(Qt::LeftToRight);
        pushButton_Home->setStyleSheet(QLatin1String("#pushButton_Home\n"
"{\n"
"color: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-radius:10px;\n"
"background-color:gray;\n"
"}"));

        verticalLayout_6->addWidget(pushButton_Home);

        pushButton_Start = new QPushButton(layoutWidget1);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setStyleSheet(QLatin1String("#pushButton_Start\n"
"{\n"
"color: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-radius:10px;\n"
"background-color:gray;\n"
"}"));

        verticalLayout_6->addWidget(pushButton_Start);

        pushButton_SetROI = new QPushButton(layoutWidget1);
        pushButton_SetROI->setObjectName(QStringLiteral("pushButton_SetROI"));
        pushButton_SetROI->setStyleSheet(QLatin1String("#pushButton_SetROI\n"
"{\n"
"color: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-radius:10px;\n"
"background-color:gray;\n"
"}\n"
"#pushButton_SetROI:pressed\n"
"{\n"
" 	border-color:black;\n"
"   background-color:green;\n"
"}"));

        verticalLayout_6->addWidget(pushButton_SetROI);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(310, 20, 101, 121));
        verticalLayout_7 = new QVBoxLayout(layoutWidget2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        pushButton_Scan = new QPushButton(layoutWidget2);
        pushButton_Scan->setObjectName(QStringLiteral("pushButton_Scan"));
        pushButton_Scan->setStyleSheet(QLatin1String("#pushButton_Scan\n"
"{\n"
"color: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-radius:10px;\n"
"background-color:gray;\n"
"}"));

        verticalLayout_7->addWidget(pushButton_Scan);

        pushButton_Stop = new QPushButton(layoutWidget2);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));
        pushButton_Stop->setStyleSheet(QLatin1String("#pushButton_Stop\n"
"{\n"
"color: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-radius:10px;\n"
"background-color:gray;\n"
"}"));

        verticalLayout_7->addWidget(pushButton_Stop);

        pushButton_Paint = new QPushButton(layoutWidget2);
        pushButton_Paint->setObjectName(QStringLiteral("pushButton_Paint"));
        pushButton_Paint->setStyleSheet(QLatin1String("#pushButton_Paint\n"
"{\n"
"color: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-radius:10px;\n"
"background-color:gray;\n"
"}"));

        verticalLayout_7->addWidget(pushButton_Paint);

        widget = new OpenGLWindow(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(430, 20, 721, 521));

        verticalLayout->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout);

        GuiWindow->setCentralWidget(centralwidget);

        retranslateUi(GuiWindow);

        QMetaObject::connectSlotsByName(GuiWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GuiWindow)
    {
        GuiWindow->setWindowTitle(QApplication::translate("GuiWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("GuiWindow", "Robot", Q_NULLPTR));
        label_Comport->setText(QApplication::translate("GuiWindow", "COM PORT", Q_NULLPTR));
        label_Baudrate->setText(QApplication::translate("GuiWindow", "BAUD RATE", Q_NULLPTR));
        pushButton_Connect->setText(QApplication::translate("GuiWindow", "Connect", Q_NULLPTR));
        label_Velocity->setText(QApplication::translate("GuiWindow", "VELOCITY", Q_NULLPTR));
        label_Accelerate->setText(QApplication::translate("GuiWindow", "ACCERLERATE", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("GuiWindow", "Camera", Q_NULLPTR));
        label_Camera->setText(QString());
        pushButton_StartCamera->setText(QString());
        label_Error->setText(QApplication::translate("GuiWindow", "ERROR:", Q_NULLPTR));
        label_Warning->setText(QApplication::translate("GuiWindow", "WARNING:", Q_NULLPTR));
        pushButton_Home->setText(QApplication::translate("GuiWindow", "HOME", Q_NULLPTR));
        pushButton_Start->setText(QApplication::translate("GuiWindow", "START", Q_NULLPTR));
        pushButton_SetROI->setText(QApplication::translate("GuiWindow", "ROI", Q_NULLPTR));
        pushButton_Scan->setText(QApplication::translate("GuiWindow", "SCAN", Q_NULLPTR));
        pushButton_Stop->setText(QApplication::translate("GuiWindow", "STOP", Q_NULLPTR));
        pushButton_Paint->setText(QApplication::translate("GuiWindow", "Paint", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiWindow: public Ui_GuiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIWINDOW_H
