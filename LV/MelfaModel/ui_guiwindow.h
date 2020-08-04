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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "openglwindow.h"

QT_BEGIN_NAMESPACE

class Ui_GuiWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    OpenGLWindow *openGL;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
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
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_Scan;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Paint;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_Home;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_SetROI;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Camera;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_Japan_Full;
    QPushButton *pushButton_Vietnam_Full;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_StartCamera;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_Error;
    QTextEdit *textEdit_Inform;
    QLabel *label_Warning;
    QTextEdit *textEdit_Waring;
    QTextEdit *textEdit_Position;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GuiWindow)
    {
        if (GuiWindow->objectName().isEmpty())
            GuiWindow->setObjectName(QStringLiteral("GuiWindow"));
        GuiWindow->resize(1197, 648);
        centralwidget = new QWidget(GuiWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        openGL = new OpenGLWindow(tab);
        openGL->setObjectName(QStringLiteral("openGL"));
        openGL->setGeometry(QRect(460, 0, 701, 651));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 441, 161));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 421, 128));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
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


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pushButton_Scan = new QPushButton(layoutWidget);
        pushButton_Scan->setObjectName(QStringLiteral("pushButton_Scan"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Scan->sizePolicy().hasHeightForWidth());
        pushButton_Scan->setSizePolicy(sizePolicy);
        pushButton_Scan->setMinimumSize(QSize(60, 0));
        pushButton_Scan->setMaximumSize(QSize(60, 30));
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

        pushButton_Stop = new QPushButton(layoutWidget);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));
        sizePolicy.setHeightForWidth(pushButton_Stop->sizePolicy().hasHeightForWidth());
        pushButton_Stop->setSizePolicy(sizePolicy);
        pushButton_Stop->setMinimumSize(QSize(60, 0));
        pushButton_Stop->setMaximumSize(QSize(60, 30));
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

        pushButton_Paint = new QPushButton(layoutWidget);
        pushButton_Paint->setObjectName(QStringLiteral("pushButton_Paint"));
        sizePolicy.setHeightForWidth(pushButton_Paint->sizePolicy().hasHeightForWidth());
        pushButton_Paint->setSizePolicy(sizePolicy);
        pushButton_Paint->setMinimumSize(QSize(60, 0));
        pushButton_Paint->setMaximumSize(QSize(60, 30));
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


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        pushButton_Home = new QPushButton(layoutWidget);
        pushButton_Home->setObjectName(QStringLiteral("pushButton_Home"));
        sizePolicy.setHeightForWidth(pushButton_Home->sizePolicy().hasHeightForWidth());
        pushButton_Home->setSizePolicy(sizePolicy);
        pushButton_Home->setMinimumSize(QSize(60, 0));
        pushButton_Home->setMaximumSize(QSize(60, 30));
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

        pushButton_Start = new QPushButton(layoutWidget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        sizePolicy.setHeightForWidth(pushButton_Start->sizePolicy().hasHeightForWidth());
        pushButton_Start->setSizePolicy(sizePolicy);
        pushButton_Start->setMinimumSize(QSize(60, 0));
        pushButton_Start->setMaximumSize(QSize(60, 30));
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

        pushButton_SetROI = new QPushButton(layoutWidget);
        pushButton_SetROI->setObjectName(QStringLiteral("pushButton_SetROI"));
        sizePolicy.setHeightForWidth(pushButton_SetROI->sizePolicy().hasHeightForWidth());
        pushButton_SetROI->setSizePolicy(sizePolicy);
        pushButton_SetROI->setMinimumSize(QSize(60, 0));
        pushButton_SetROI->setMaximumSize(QSize(60, 30));
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


        horizontalLayout->addLayout(verticalLayout_6);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 160, 441, 471));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 421, 381));
        verticalLayout_8 = new QVBoxLayout(layoutWidget1);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_Camera = new QLabel(layoutWidget1);
        label_Camera->setObjectName(QStringLiteral("label_Camera"));
        label_Camera->setMinimumSize(QSize(260, 200));
        label_Camera->setMaximumSize(QSize(260, 200));
        label_Camera->setFrameShape(QFrame::Box);
        label_Camera->setFrameShadow(QFrame::Raised);
        label_Camera->setLineWidth(5);

        horizontalLayout_6->addWidget(label_Camera);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_Japan_Full = new QPushButton(layoutWidget1);
        pushButton_Japan_Full->setObjectName(QStringLiteral("pushButton_Japan_Full"));
        pushButton_Japan_Full->setMaximumSize(QSize(100, 20));

        verticalLayout_5->addWidget(pushButton_Japan_Full);

        pushButton_Vietnam_Full = new QPushButton(layoutWidget1);
        pushButton_Vietnam_Full->setObjectName(QStringLiteral("pushButton_Vietnam_Full"));
        pushButton_Vietnam_Full->setMaximumSize(QSize(100, 20));

        verticalLayout_5->addWidget(pushButton_Vietnam_Full);

        verticalSpacer = new QSpacerItem(10, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_5->addItem(verticalSpacer);

        pushButton_StartCamera = new QPushButton(layoutWidget1);
        pushButton_StartCamera->setObjectName(QStringLiteral("pushButton_StartCamera"));
        pushButton_StartCamera->setMaximumSize(QSize(30, 30));
        pushButton_StartCamera->setStyleSheet(QLatin1String("#pushButton_StartCamera\n"
"{\n"
"border:none;\n"
"}"));

        verticalLayout_5->addWidget(pushButton_StartCamera);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_Error = new QLabel(layoutWidget1);
        label_Error->setObjectName(QStringLiteral("label_Error"));
        sizePolicy.setHeightForWidth(label_Error->sizePolicy().hasHeightForWidth());
        label_Error->setSizePolicy(sizePolicy);
        label_Error->setMaximumSize(QSize(260, 20));
        label_Error->setStyleSheet(QLatin1String("#label_Error\n"
"{\n"
"color: red;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-color:darkblue;\n"
"}"));

        verticalLayout->addWidget(label_Error);

        textEdit_Inform = new QTextEdit(layoutWidget1);
        textEdit_Inform->setObjectName(QStringLiteral("textEdit_Inform"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit_Inform->sizePolicy().hasHeightForWidth());
        textEdit_Inform->setSizePolicy(sizePolicy1);
        textEdit_Inform->setMinimumSize(QSize(260, 50));
        textEdit_Inform->setMaximumSize(QSize(260, 50));

        verticalLayout->addWidget(textEdit_Inform);

        label_Warning = new QLabel(layoutWidget1);
        label_Warning->setObjectName(QStringLiteral("label_Warning"));
        sizePolicy.setHeightForWidth(label_Warning->sizePolicy().hasHeightForWidth());
        label_Warning->setSizePolicy(sizePolicy);
        label_Warning->setMaximumSize(QSize(260, 20));
        label_Warning->setStyleSheet(QLatin1String("#label_Warning\n"
"{\n"
"color:yellow;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-color:darkblue;\n"
"}"));

        verticalLayout->addWidget(label_Warning);

        textEdit_Waring = new QTextEdit(layoutWidget1);
        textEdit_Waring->setObjectName(QStringLiteral("textEdit_Waring"));
        textEdit_Waring->setMaximumSize(QSize(260, 50));

        verticalLayout->addWidget(textEdit_Waring);


        horizontalLayout_5->addLayout(verticalLayout);

        textEdit_Position = new QTextEdit(layoutWidget1);
        textEdit_Position->setObjectName(QStringLiteral("textEdit_Position"));
        textEdit_Position->setMaximumSize(QSize(150, 150));

        horizontalLayout_5->addWidget(textEdit_Position);


        verticalLayout_8->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        GuiWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GuiWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1197, 21));
        GuiWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GuiWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        GuiWindow->setStatusBar(statusbar);

        retranslateUi(GuiWindow);

        tabWidget->setCurrentIndex(0);


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
        pushButton_Scan->setText(QApplication::translate("GuiWindow", "SCAN", Q_NULLPTR));
        pushButton_Stop->setText(QApplication::translate("GuiWindow", "STOP", Q_NULLPTR));
        pushButton_Paint->setText(QApplication::translate("GuiWindow", "Paint", Q_NULLPTR));
        pushButton_Home->setText(QApplication::translate("GuiWindow", "HOME", Q_NULLPTR));
        pushButton_Start->setText(QApplication::translate("GuiWindow", "START", Q_NULLPTR));
        pushButton_SetROI->setText(QApplication::translate("GuiWindow", "ROI", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("GuiWindow", "Camera", Q_NULLPTR));
        label_Camera->setText(QString());
        pushButton_Japan_Full->setText(QApplication::translate("GuiWindow", "JP FULL", Q_NULLPTR));
        pushButton_Vietnam_Full->setText(QApplication::translate("GuiWindow", "VN FULL", Q_NULLPTR));
        pushButton_StartCamera->setText(QString());
        label_Error->setText(QApplication::translate("GuiWindow", "ERROR:", Q_NULLPTR));
        label_Warning->setText(QApplication::translate("GuiWindow", "WARNING:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("GuiWindow", "VISION MODE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("GuiWindow", "JOB MODE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiWindow: public Ui_GuiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIWINDOW_H
