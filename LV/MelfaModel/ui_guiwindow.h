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

QT_BEGIN_NAMESPACE

class Ui_GuiWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
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
    QPushButton *pushButton_Home;
    QPushButton *pushButton_Scan;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_TestMoveJoint;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_StartCamera;
    QPushButton *pushButton_SetROI;
    QTextEdit *textEdit_Position;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_Camera;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_Pick;
    QPushButton *pushButton_Hold;
    QPushButton *pushButton_Place;

    void setupUi(QMainWindow *GuiWindow)
    {
        if (GuiWindow->objectName().isEmpty())
            GuiWindow->setObjectName(QStringLiteral("GuiWindow"));
        GuiWindow->resize(1027, 600);
        centralwidget = new QWidget(GuiWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 100, 30));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 271, 248));
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

        pushButton_Home = new QPushButton(layoutWidget);
        pushButton_Home->setObjectName(QStringLiteral("pushButton_Home"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Home->sizePolicy().hasHeightForWidth());
        pushButton_Home->setSizePolicy(sizePolicy);
        pushButton_Home->setMaximumSize(QSize(10000, 16777215));
        pushButton_Home->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(pushButton_Home);

        pushButton_Scan = new QPushButton(layoutWidget);
        pushButton_Scan->setObjectName(QStringLiteral("pushButton_Scan"));

        verticalLayout_2->addWidget(pushButton_Scan);

        pushButton_Stop = new QPushButton(layoutWidget);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));

        verticalLayout_2->addWidget(pushButton_Stop);

        pushButton_TestMoveJoint = new QPushButton(layoutWidget);
        pushButton_TestMoveJoint->setObjectName(QStringLiteral("pushButton_TestMoveJoint"));

        verticalLayout_2->addWidget(pushButton_TestMoveJoint);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 280, 411, 311));
        pushButton_StartCamera = new QPushButton(groupBox_2);
        pushButton_StartCamera->setObjectName(QStringLiteral("pushButton_StartCamera"));
        pushButton_StartCamera->setGeometry(QRect(270, 190, 30, 30));
        pushButton_StartCamera->setMinimumSize(QSize(30, 30));
        pushButton_StartCamera->setMaximumSize(QSize(30, 30));
        pushButton_StartCamera->setStyleSheet(QLatin1String("#pushButton_StartCamera\n"
"{\n"
" border:none;\n"
"}\n"
""));
        pushButton_SetROI = new QPushButton(groupBox_2);
        pushButton_SetROI->setObjectName(QStringLiteral("pushButton_SetROI"));
        pushButton_SetROI->setGeometry(QRect(280, 70, 75, 23));
        textEdit_Position = new QTextEdit(groupBox_2);
        textEdit_Position->setObjectName(QStringLiteral("textEdit_Position"));
        textEdit_Position->setGeometry(QRect(290, 110, 104, 71));
        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 20, 262, 271));
        verticalLayout_6 = new QVBoxLayout(widget1);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_Camera = new QLabel(widget1);
        label_Camera->setObjectName(QStringLiteral("label_Camera"));
        label_Camera->setMinimumSize(QSize(260, 200));
        label_Camera->setMaximumSize(QSize(260, 200));
        label_Camera->setFrameShape(QFrame::Box);
        label_Camera->setFrameShadow(QFrame::Raised);
        label_Camera->setLineWidth(5);

        verticalLayout_6->addWidget(label_Camera);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_Pick = new QPushButton(widget1);
        pushButton_Pick->setObjectName(QStringLiteral("pushButton_Pick"));

        horizontalLayout_5->addWidget(pushButton_Pick);

        pushButton_Hold = new QPushButton(widget1);
        pushButton_Hold->setObjectName(QStringLiteral("pushButton_Hold"));

        horizontalLayout_5->addWidget(pushButton_Hold);

        pushButton_Place = new QPushButton(widget1);
        pushButton_Place->setObjectName(QStringLiteral("pushButton_Place"));

        horizontalLayout_5->addWidget(pushButton_Place);


        verticalLayout_6->addLayout(horizontalLayout_5);

        pushButton_Place->raise();
        pushButton_Pick->raise();
        pushButton_SetROI->raise();
        pushButton_StartCamera->raise();
        label_Camera->raise();
        label_Camera->raise();
        textEdit_Position->raise();

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
        pushButton_Home->setText(QApplication::translate("GuiWindow", "Home", Q_NULLPTR));
        pushButton_Scan->setText(QApplication::translate("GuiWindow", "Scan", Q_NULLPTR));
        pushButton_Stop->setText(QApplication::translate("GuiWindow", "Stop", Q_NULLPTR));
        pushButton_TestMoveJoint->setText(QApplication::translate("GuiWindow", "Test Move Joint", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("GuiWindow", "Camera", Q_NULLPTR));
        pushButton_StartCamera->setText(QString());
        pushButton_SetROI->setText(QApplication::translate("GuiWindow", "Select  ROI", Q_NULLPTR));
        label_Camera->setText(QString());
        pushButton_Pick->setText(QApplication::translate("GuiWindow", "PICK", Q_NULLPTR));
        pushButton_Hold->setText(QApplication::translate("GuiWindow", "HOLD", Q_NULLPTR));
        pushButton_Place->setText(QApplication::translate("GuiWindow", "PLACE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiWindow: public Ui_GuiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIWINDOW_H
