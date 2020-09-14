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
    QGroupBox *groupBox_Information;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_Joint_var;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_Theta1;
    QTextEdit *textEdit_Theta1;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_Theta2;
    QTextEdit *textEdit_Theta2;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_D3;
    QTextEdit *textEdit_D3;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_Theta4;
    QTextEdit *textEdit_Theta4;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_slider;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label;
    QLabel *label_var0_min;
    QSlider *horizontalSlider_var0;
    QLabel *label_var0_max;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_2;
    QLabel *label_var1_min;
    QSlider *horizontalSlider_var1;
    QLabel *label_var1_max;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_3;
    QLabel *label_var2_min;
    QSlider *horizontalSlider_var2;
    QLabel *label_var2_max;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_4;
    QLabel *label_var3_min;
    QSlider *horizontalSlider_var3;
    QLabel *label_var3_max;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_XYZ_target_2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_X_2;
    QTextEdit *textEdit_X;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_Y_2;
    QTextEdit *textEdit_Y;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_Z_2;
    QTextEdit *textEdit_Z;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_Roll_2;
    QTextEdit *textEdit_Roll;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_XYZ_target_4;
    QVBoxLayout *verticalLayout_26;
    QLabel *label_X_4;
    QTextEdit *textEdit_X_Object;
    QVBoxLayout *verticalLayout_27;
    QLabel *label_Y_4;
    QTextEdit *textEdit_Y_Object;
    QVBoxLayout *verticalLayout_30;
    QLabel *label_Roll_5;
    QTextEdit *textEdit_Class;
    QVBoxLayout *verticalLayout_29;
    QLabel *label_Roll_4;
    QTextEdit *textEdit_Roll_Object;
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
    QPushButton *pushButton_Log;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_Home;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_SetROI;
    QGroupBox *groupBox_2;
    QLabel *label_Camera;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_Japan;
    QLabel *label_Vietnam;
    QHBoxLayout *horizontalLayout_9;
    QTextEdit *textEdit_Japan_Num;
    QTextEdit *textEdit_Vietnam_Num;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_Japan_Full;
    QPushButton *pushButton_Vietnam_Full;
    QPushButton *pushButton_StartCamera;
    QTextEdit *textEdit_Waring;
    QTextEdit *textEdit_Inform;
    QWidget *tab_3;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_Change;
    QTextEdit *textEdit_Group1;
    QLabel *label_10;
    QTextEdit *textEdit_Line2_up;
    QLabel *label_9;
    QLabel *label_11;
    QTextEdit *textEdit_Line1;
    QLabel *label_12;
    QTextEdit *textEdit_Line2_low;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GuiWindow)
    {
        if (GuiWindow->objectName().isEmpty())
            GuiWindow->setObjectName(QStringLiteral("GuiWindow"));
        GuiWindow->resize(1197, 676);
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
        openGL->setGeometry(QRect(470, 10, 701, 651));
        groupBox_Information = new QGroupBox(openGL);
        groupBox_Information->setObjectName(QStringLiteral("groupBox_Information"));
        groupBox_Information->setEnabled(true);
        groupBox_Information->setGeometry(QRect(10, 10, 671, 141));
        layoutWidget_3 = new QWidget(groupBox_Information);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 20, 308, 56));
        horizontalLayout_Joint_var = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_Joint_var->setObjectName(QStringLiteral("horizontalLayout_Joint_var"));
        horizontalLayout_Joint_var->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_Joint_var->setContentsMargins(0, 0, 0, 0);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_Theta1 = new QLabel(layoutWidget_3);
        label_Theta1->setObjectName(QStringLiteral("label_Theta1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_Theta1->sizePolicy().hasHeightForWidth());
        label_Theta1->setSizePolicy(sizePolicy);
        label_Theta1->setMaximumSize(QSize(70, 20));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_Theta1->setFont(font);

        verticalLayout_13->addWidget(label_Theta1);

        textEdit_Theta1 = new QTextEdit(layoutWidget_3);
        textEdit_Theta1->setObjectName(QStringLiteral("textEdit_Theta1"));
        sizePolicy.setHeightForWidth(textEdit_Theta1->sizePolicy().hasHeightForWidth());
        textEdit_Theta1->setSizePolicy(sizePolicy);
        textEdit_Theta1->setMaximumSize(QSize(70, 32));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        textEdit_Theta1->setFont(font1);

        verticalLayout_13->addWidget(textEdit_Theta1);


        horizontalLayout_Joint_var->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_Theta2 = new QLabel(layoutWidget_3);
        label_Theta2->setObjectName(QStringLiteral("label_Theta2"));
        sizePolicy.setHeightForWidth(label_Theta2->sizePolicy().hasHeightForWidth());
        label_Theta2->setSizePolicy(sizePolicy);
        label_Theta2->setMaximumSize(QSize(70, 20));
        label_Theta2->setFont(font);

        verticalLayout_14->addWidget(label_Theta2);

        textEdit_Theta2 = new QTextEdit(layoutWidget_3);
        textEdit_Theta2->setObjectName(QStringLiteral("textEdit_Theta2"));
        sizePolicy.setHeightForWidth(textEdit_Theta2->sizePolicy().hasHeightForWidth());
        textEdit_Theta2->setSizePolicy(sizePolicy);
        textEdit_Theta2->setMaximumSize(QSize(70, 32));
        textEdit_Theta2->setFont(font1);

        verticalLayout_14->addWidget(textEdit_Theta2);


        horizontalLayout_Joint_var->addLayout(verticalLayout_14);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_D3 = new QLabel(layoutWidget_3);
        label_D3->setObjectName(QStringLiteral("label_D3"));
        sizePolicy.setHeightForWidth(label_D3->sizePolicy().hasHeightForWidth());
        label_D3->setSizePolicy(sizePolicy);
        label_D3->setMaximumSize(QSize(70, 20));
        label_D3->setFont(font);

        verticalLayout_17->addWidget(label_D3);

        textEdit_D3 = new QTextEdit(layoutWidget_3);
        textEdit_D3->setObjectName(QStringLiteral("textEdit_D3"));
        sizePolicy.setHeightForWidth(textEdit_D3->sizePolicy().hasHeightForWidth());
        textEdit_D3->setSizePolicy(sizePolicy);
        textEdit_D3->setMaximumSize(QSize(70, 32));
        textEdit_D3->setFont(font1);

        verticalLayout_17->addWidget(textEdit_D3);


        horizontalLayout_Joint_var->addLayout(verticalLayout_17);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_Theta4 = new QLabel(layoutWidget_3);
        label_Theta4->setObjectName(QStringLiteral("label_Theta4"));
        sizePolicy.setHeightForWidth(label_Theta4->sizePolicy().hasHeightForWidth());
        label_Theta4->setSizePolicy(sizePolicy);
        label_Theta4->setMaximumSize(QSize(70, 20));
        label_Theta4->setFont(font);

        verticalLayout_15->addWidget(label_Theta4);

        textEdit_Theta4 = new QTextEdit(layoutWidget_3);
        textEdit_Theta4->setObjectName(QStringLiteral("textEdit_Theta4"));
        sizePolicy.setHeightForWidth(textEdit_Theta4->sizePolicy().hasHeightForWidth());
        textEdit_Theta4->setSizePolicy(sizePolicy);
        textEdit_Theta4->setMaximumSize(QSize(70, 32));
        textEdit_Theta4->setFont(font1);

        verticalLayout_15->addWidget(textEdit_Theta4);


        horizontalLayout_Joint_var->addLayout(verticalLayout_15);

        layoutWidget_5 = new QWidget(groupBox_Information);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(350, 20, 311, 116));
        verticalLayout_slider = new QVBoxLayout(layoutWidget_5);
        verticalLayout_slider->setObjectName(QStringLiteral("verticalLayout_slider"));
        verticalLayout_slider->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label = new QLabel(layoutWidget_5);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(45, 0));

        horizontalLayout_11->addWidget(label);

        label_var0_min = new QLabel(layoutWidget_5);
        label_var0_min->setObjectName(QStringLiteral("label_var0_min"));
        label_var0_min->setMinimumSize(QSize(30, 0));
        label_var0_min->setFont(font1);
        label_var0_min->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_var0_min);

        horizontalSlider_var0 = new QSlider(layoutWidget_5);
        horizontalSlider_var0->setObjectName(QStringLiteral("horizontalSlider_var0"));
        horizontalSlider_var0->setMaximum(999);
        horizontalSlider_var0->setSliderPosition(0);
        horizontalSlider_var0->setTracking(false);
        horizontalSlider_var0->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(horizontalSlider_var0);

        label_var0_max = new QLabel(layoutWidget_5);
        label_var0_max->setObjectName(QStringLiteral("label_var0_max"));
        label_var0_max->setMinimumSize(QSize(30, 0));
        label_var0_max->setFont(font1);
        label_var0_max->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_var0_max);


        verticalLayout_slider->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_2 = new QLabel(layoutWidget_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(45, 0));

        horizontalLayout_12->addWidget(label_2);

        label_var1_min = new QLabel(layoutWidget_5);
        label_var1_min->setObjectName(QStringLiteral("label_var1_min"));
        label_var1_min->setMinimumSize(QSize(30, 0));
        label_var1_min->setFont(font1);
        label_var1_min->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_var1_min);

        horizontalSlider_var1 = new QSlider(layoutWidget_5);
        horizontalSlider_var1->setObjectName(QStringLiteral("horizontalSlider_var1"));
        horizontalSlider_var1->setMaximum(999);
        horizontalSlider_var1->setTracking(false);
        horizontalSlider_var1->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(horizontalSlider_var1);

        label_var1_max = new QLabel(layoutWidget_5);
        label_var1_max->setObjectName(QStringLiteral("label_var1_max"));
        label_var1_max->setMinimumSize(QSize(30, 0));
        label_var1_max->setFont(font1);
        label_var1_max->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_var1_max);


        verticalLayout_slider->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_3 = new QLabel(layoutWidget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(45, 0));

        horizontalLayout_13->addWidget(label_3);

        label_var2_min = new QLabel(layoutWidget_5);
        label_var2_min->setObjectName(QStringLiteral("label_var2_min"));
        label_var2_min->setMinimumSize(QSize(30, 0));
        label_var2_min->setFont(font1);
        label_var2_min->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_var2_min);

        horizontalSlider_var2 = new QSlider(layoutWidget_5);
        horizontalSlider_var2->setObjectName(QStringLiteral("horizontalSlider_var2"));
        horizontalSlider_var2->setMaximum(999);
        horizontalSlider_var2->setTracking(false);
        horizontalSlider_var2->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(horizontalSlider_var2);

        label_var2_max = new QLabel(layoutWidget_5);
        label_var2_max->setObjectName(QStringLiteral("label_var2_max"));
        label_var2_max->setMinimumSize(QSize(30, 0));
        label_var2_max->setFont(font1);
        label_var2_max->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_var2_max);


        verticalLayout_slider->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_4 = new QLabel(layoutWidget_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(45, 0));

        horizontalLayout_14->addWidget(label_4);

        label_var3_min = new QLabel(layoutWidget_5);
        label_var3_min->setObjectName(QStringLiteral("label_var3_min"));
        label_var3_min->setMinimumSize(QSize(30, 0));
        label_var3_min->setFont(font1);
        label_var3_min->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_var3_min);

        horizontalSlider_var3 = new QSlider(layoutWidget_5);
        horizontalSlider_var3->setObjectName(QStringLiteral("horizontalSlider_var3"));
        horizontalSlider_var3->setMaximum(999);
        horizontalSlider_var3->setPageStep(100);
        horizontalSlider_var3->setTracking(false);
        horizontalSlider_var3->setOrientation(Qt::Horizontal);

        horizontalLayout_14->addWidget(horizontalSlider_var3);

        label_var3_max = new QLabel(layoutWidget_5);
        label_var3_max->setObjectName(QStringLiteral("label_var3_max"));
        label_var3_max->setMinimumSize(QSize(30, 0));
        label_var3_max->setFont(font1);
        label_var3_max->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_var3_max);


        verticalLayout_slider->addLayout(horizontalLayout_14);

        layoutWidget_2 = new QWidget(groupBox_Information);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 80, 308, 56));
        horizontalLayout_XYZ_target_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_XYZ_target_2->setObjectName(QStringLiteral("horizontalLayout_XYZ_target_2"));
        horizontalLayout_XYZ_target_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_XYZ_target_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_X_2 = new QLabel(layoutWidget_2);
        label_X_2->setObjectName(QStringLiteral("label_X_2"));
        sizePolicy.setHeightForWidth(label_X_2->sizePolicy().hasHeightForWidth());
        label_X_2->setSizePolicy(sizePolicy);
        label_X_2->setMaximumSize(QSize(70, 20));
        label_X_2->setFont(font);

        verticalLayout_10->addWidget(label_X_2);

        textEdit_X = new QTextEdit(layoutWidget_2);
        textEdit_X->setObjectName(QStringLiteral("textEdit_X"));
        sizePolicy.setHeightForWidth(textEdit_X->sizePolicy().hasHeightForWidth());
        textEdit_X->setSizePolicy(sizePolicy);
        textEdit_X->setMaximumSize(QSize(70, 32));
        textEdit_X->setFont(font1);

        verticalLayout_10->addWidget(textEdit_X);


        horizontalLayout_XYZ_target_2->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_Y_2 = new QLabel(layoutWidget_2);
        label_Y_2->setObjectName(QStringLiteral("label_Y_2"));
        sizePolicy.setHeightForWidth(label_Y_2->sizePolicy().hasHeightForWidth());
        label_Y_2->setSizePolicy(sizePolicy);
        label_Y_2->setMaximumSize(QSize(70, 20));
        label_Y_2->setFont(font);

        verticalLayout_11->addWidget(label_Y_2);

        textEdit_Y = new QTextEdit(layoutWidget_2);
        textEdit_Y->setObjectName(QStringLiteral("textEdit_Y"));
        sizePolicy.setHeightForWidth(textEdit_Y->sizePolicy().hasHeightForWidth());
        textEdit_Y->setSizePolicy(sizePolicy);
        textEdit_Y->setMaximumSize(QSize(70, 32));
        textEdit_Y->setFont(font1);

        verticalLayout_11->addWidget(textEdit_Y);


        horizontalLayout_XYZ_target_2->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_Z_2 = new QLabel(layoutWidget_2);
        label_Z_2->setObjectName(QStringLiteral("label_Z_2"));
        sizePolicy.setHeightForWidth(label_Z_2->sizePolicy().hasHeightForWidth());
        label_Z_2->setSizePolicy(sizePolicy);
        label_Z_2->setMaximumSize(QSize(70, 20));
        label_Z_2->setFont(font);

        verticalLayout_12->addWidget(label_Z_2);

        textEdit_Z = new QTextEdit(layoutWidget_2);
        textEdit_Z->setObjectName(QStringLiteral("textEdit_Z"));
        sizePolicy.setHeightForWidth(textEdit_Z->sizePolicy().hasHeightForWidth());
        textEdit_Z->setSizePolicy(sizePolicy);
        textEdit_Z->setMaximumSize(QSize(70, 32));
        textEdit_Z->setFont(font1);

        verticalLayout_12->addWidget(textEdit_Z);


        horizontalLayout_XYZ_target_2->addLayout(verticalLayout_12);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        label_Roll_2 = new QLabel(layoutWidget_2);
        label_Roll_2->setObjectName(QStringLiteral("label_Roll_2"));
        sizePolicy.setHeightForWidth(label_Roll_2->sizePolicy().hasHeightForWidth());
        label_Roll_2->setSizePolicy(sizePolicy);
        label_Roll_2->setMaximumSize(QSize(70, 20));
        label_Roll_2->setFont(font);

        verticalLayout_22->addWidget(label_Roll_2);

        textEdit_Roll = new QTextEdit(layoutWidget_2);
        textEdit_Roll->setObjectName(QStringLiteral("textEdit_Roll"));
        sizePolicy.setHeightForWidth(textEdit_Roll->sizePolicy().hasHeightForWidth());
        textEdit_Roll->setSizePolicy(sizePolicy);
        textEdit_Roll->setMaximumSize(QSize(70, 32));
        textEdit_Roll->setFont(font1);

        verticalLayout_22->addWidget(textEdit_Roll);


        horizontalLayout_XYZ_target_2->addLayout(verticalLayout_22);

        groupBox_4 = new QGroupBox(openGL);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 160, 341, 91));
        layoutWidget_8 = new QWidget(groupBox_4);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(20, 20, 308, 61));
        horizontalLayout_XYZ_target_4 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_XYZ_target_4->setObjectName(QStringLiteral("horizontalLayout_XYZ_target_4"));
        horizontalLayout_XYZ_target_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_XYZ_target_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        label_X_4 = new QLabel(layoutWidget_8);
        label_X_4->setObjectName(QStringLiteral("label_X_4"));
        sizePolicy.setHeightForWidth(label_X_4->sizePolicy().hasHeightForWidth());
        label_X_4->setSizePolicy(sizePolicy);
        label_X_4->setMaximumSize(QSize(70, 20));
        label_X_4->setFont(font);

        verticalLayout_26->addWidget(label_X_4);

        textEdit_X_Object = new QTextEdit(layoutWidget_8);
        textEdit_X_Object->setObjectName(QStringLiteral("textEdit_X_Object"));
        sizePolicy.setHeightForWidth(textEdit_X_Object->sizePolicy().hasHeightForWidth());
        textEdit_X_Object->setSizePolicy(sizePolicy);
        textEdit_X_Object->setMaximumSize(QSize(70, 32));
        textEdit_X_Object->setFont(font1);

        verticalLayout_26->addWidget(textEdit_X_Object);


        horizontalLayout_XYZ_target_4->addLayout(verticalLayout_26);

        verticalLayout_27 = new QVBoxLayout();
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        label_Y_4 = new QLabel(layoutWidget_8);
        label_Y_4->setObjectName(QStringLiteral("label_Y_4"));
        sizePolicy.setHeightForWidth(label_Y_4->sizePolicy().hasHeightForWidth());
        label_Y_4->setSizePolicy(sizePolicy);
        label_Y_4->setMaximumSize(QSize(70, 20));
        label_Y_4->setFont(font);

        verticalLayout_27->addWidget(label_Y_4);

        textEdit_Y_Object = new QTextEdit(layoutWidget_8);
        textEdit_Y_Object->setObjectName(QStringLiteral("textEdit_Y_Object"));
        sizePolicy.setHeightForWidth(textEdit_Y_Object->sizePolicy().hasHeightForWidth());
        textEdit_Y_Object->setSizePolicy(sizePolicy);
        textEdit_Y_Object->setMaximumSize(QSize(70, 32));
        textEdit_Y_Object->setFont(font1);

        verticalLayout_27->addWidget(textEdit_Y_Object);


        horizontalLayout_XYZ_target_4->addLayout(verticalLayout_27);

        verticalLayout_30 = new QVBoxLayout();
        verticalLayout_30->setObjectName(QStringLiteral("verticalLayout_30"));
        label_Roll_5 = new QLabel(layoutWidget_8);
        label_Roll_5->setObjectName(QStringLiteral("label_Roll_5"));
        sizePolicy.setHeightForWidth(label_Roll_5->sizePolicy().hasHeightForWidth());
        label_Roll_5->setSizePolicy(sizePolicy);
        label_Roll_5->setMaximumSize(QSize(70, 20));
        label_Roll_5->setFont(font);

        verticalLayout_30->addWidget(label_Roll_5);

        textEdit_Class = new QTextEdit(layoutWidget_8);
        textEdit_Class->setObjectName(QStringLiteral("textEdit_Class"));
        sizePolicy.setHeightForWidth(textEdit_Class->sizePolicy().hasHeightForWidth());
        textEdit_Class->setSizePolicy(sizePolicy);
        textEdit_Class->setMaximumSize(QSize(70, 32));
        textEdit_Class->setFont(font1);

        verticalLayout_30->addWidget(textEdit_Class);


        horizontalLayout_XYZ_target_4->addLayout(verticalLayout_30);

        verticalLayout_29 = new QVBoxLayout();
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        label_Roll_4 = new QLabel(layoutWidget_8);
        label_Roll_4->setObjectName(QStringLiteral("label_Roll_4"));
        sizePolicy.setHeightForWidth(label_Roll_4->sizePolicy().hasHeightForWidth());
        label_Roll_4->setSizePolicy(sizePolicy);
        label_Roll_4->setMaximumSize(QSize(70, 20));
        label_Roll_4->setFont(font);

        verticalLayout_29->addWidget(label_Roll_4);

        textEdit_Roll_Object = new QTextEdit(layoutWidget_8);
        textEdit_Roll_Object->setObjectName(QStringLiteral("textEdit_Roll_Object"));
        sizePolicy.setHeightForWidth(textEdit_Roll_Object->sizePolicy().hasHeightForWidth());
        textEdit_Roll_Object->setSizePolicy(sizePolicy);
        textEdit_Roll_Object->setMaximumSize(QSize(70, 32));
        textEdit_Roll_Object->setFont(font1);

        verticalLayout_29->addWidget(textEdit_Roll_Object);


        horizontalLayout_XYZ_target_4->addLayout(verticalLayout_29);

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
        sizePolicy.setHeightForWidth(label_Comport->sizePolicy().hasHeightForWidth());
        label_Comport->setSizePolicy(sizePolicy);
        label_Comport->setMaximumSize(QSize(80, 20));

        horizontalLayout_2->addWidget(label_Comport);

        comboBox_Comport = new QComboBox(layoutWidget);
        comboBox_Comport->setObjectName(QStringLiteral("comboBox_Comport"));
        sizePolicy.setHeightForWidth(comboBox_Comport->sizePolicy().hasHeightForWidth());
        comboBox_Comport->setSizePolicy(sizePolicy);
        comboBox_Comport->setMaximumSize(QSize(100, 20));

        horizontalLayout_2->addWidget(comboBox_Comport);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Baudrate = new QLabel(layoutWidget);
        label_Baudrate->setObjectName(QStringLiteral("label_Baudrate"));
        sizePolicy.setHeightForWidth(label_Baudrate->sizePolicy().hasHeightForWidth());
        label_Baudrate->setSizePolicy(sizePolicy);
        label_Baudrate->setMinimumSize(QSize(80, 20));

        horizontalLayout_3->addWidget(label_Baudrate);

        comboBox_Baudrate = new QComboBox(layoutWidget);
        comboBox_Baudrate->setObjectName(QStringLiteral("comboBox_Baudrate"));
        sizePolicy.setHeightForWidth(comboBox_Baudrate->sizePolicy().hasHeightForWidth());
        comboBox_Baudrate->setSizePolicy(sizePolicy);
        comboBox_Baudrate->setMaximumSize(QSize(100, 20));

        horizontalLayout_3->addWidget(comboBox_Baudrate);


        verticalLayout_2->addLayout(horizontalLayout_3);

        pushButton_Connect = new QPushButton(layoutWidget);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_Connect->sizePolicy().hasHeightForWidth());
        pushButton_Connect->setSizePolicy(sizePolicy1);
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
        sizePolicy.setHeightForWidth(label_Velocity->sizePolicy().hasHeightForWidth());
        label_Velocity->setSizePolicy(sizePolicy);
        label_Velocity->setMinimumSize(QSize(110, 0));

        verticalLayout_3->addWidget(label_Velocity);

        sliderVelocity = new QSlider(layoutWidget);
        sliderVelocity->setObjectName(QStringLiteral("sliderVelocity"));
        sizePolicy.setHeightForWidth(sliderVelocity->sizePolicy().hasHeightForWidth());
        sliderVelocity->setSizePolicy(sizePolicy);
        sliderVelocity->setMinimumSize(QSize(110, 0));
        sliderVelocity->setMinimum(1);
        sliderVelocity->setMaximum(100);
        sliderVelocity->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(sliderVelocity);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_Accelerate = new QLabel(layoutWidget);
        label_Accelerate->setObjectName(QStringLiteral("label_Accelerate"));
        sizePolicy.setHeightForWidth(label_Accelerate->sizePolicy().hasHeightForWidth());
        label_Accelerate->setSizePolicy(sizePolicy);
        label_Accelerate->setMinimumSize(QSize(110, 0));

        verticalLayout_4->addWidget(label_Accelerate);

        sliderAccerlerate = new QSlider(layoutWidget);
        sliderAccerlerate->setObjectName(QStringLiteral("sliderAccerlerate"));
        sizePolicy.setHeightForWidth(sliderAccerlerate->sizePolicy().hasHeightForWidth());
        sliderAccerlerate->setSizePolicy(sizePolicy);
        sliderAccerlerate->setMinimumSize(QSize(110, 0));
        sliderAccerlerate->setMinimum(1);
        sliderAccerlerate->setMaximum(100);
        sliderAccerlerate->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(sliderAccerlerate);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pushButton_Scan = new QPushButton(layoutWidget);
        pushButton_Scan->setObjectName(QStringLiteral("pushButton_Scan"));
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

        pushButton_Log = new QPushButton(layoutWidget);
        pushButton_Log->setObjectName(QStringLiteral("pushButton_Log"));
        sizePolicy.setHeightForWidth(pushButton_Log->sizePolicy().hasHeightForWidth());
        pushButton_Log->setSizePolicy(sizePolicy);
        pushButton_Log->setMinimumSize(QSize(60, 0));
        pushButton_Log->setMaximumSize(QSize(60, 30));
        pushButton_Log->setStyleSheet(QLatin1String("color: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-radius:10px;\n"
"background-color:gray;"));

        verticalLayout_7->addWidget(pushButton_Log);


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
        label_Camera = new QLabel(groupBox_2);
        label_Camera->setObjectName(QStringLiteral("label_Camera"));
        label_Camera->setGeometry(QRect(10, 20, 260, 200));
        label_Camera->setMinimumSize(QSize(260, 200));
        label_Camera->setMaximumSize(QSize(260, 200));
        label_Camera->setFrameShape(QFrame::Box);
        label_Camera->setFrameShadow(QFrame::Raised);
        label_Camera->setLineWidth(5);
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(280, 30, 160, 160));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_Japan = new QLabel(layoutWidget1);
        label_Japan->setObjectName(QStringLiteral("label_Japan"));
        sizePolicy.setHeightForWidth(label_Japan->sizePolicy().hasHeightForWidth());
        label_Japan->setSizePolicy(sizePolicy);
        label_Japan->setMinimumSize(QSize(50, 50));
        label_Japan->setMaximumSize(QSize(50, 50));

        horizontalLayout_8->addWidget(label_Japan);

        label_Vietnam = new QLabel(layoutWidget1);
        label_Vietnam->setObjectName(QStringLiteral("label_Vietnam"));
        sizePolicy.setHeightForWidth(label_Vietnam->sizePolicy().hasHeightForWidth());
        label_Vietnam->setSizePolicy(sizePolicy);
        label_Vietnam->setMinimumSize(QSize(50, 50));
        label_Vietnam->setMaximumSize(QSize(50, 50));

        horizontalLayout_8->addWidget(label_Vietnam);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        textEdit_Japan_Num = new QTextEdit(layoutWidget1);
        textEdit_Japan_Num->setObjectName(QStringLiteral("textEdit_Japan_Num"));
        sizePolicy.setHeightForWidth(textEdit_Japan_Num->sizePolicy().hasHeightForWidth());
        textEdit_Japan_Num->setSizePolicy(sizePolicy);
        textEdit_Japan_Num->setMaximumSize(QSize(50, 40));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        textEdit_Japan_Num->setFont(font2);

        horizontalLayout_9->addWidget(textEdit_Japan_Num);

        textEdit_Vietnam_Num = new QTextEdit(layoutWidget1);
        textEdit_Vietnam_Num->setObjectName(QStringLiteral("textEdit_Vietnam_Num"));
        sizePolicy.setHeightForWidth(textEdit_Vietnam_Num->sizePolicy().hasHeightForWidth());
        textEdit_Vietnam_Num->setSizePolicy(sizePolicy);
        textEdit_Vietnam_Num->setMaximumSize(QSize(50, 40));
        textEdit_Vietnam_Num->setFont(font2);

        horizontalLayout_9->addWidget(textEdit_Vietnam_Num);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_Japan_Full = new QPushButton(layoutWidget1);
        pushButton_Japan_Full->setObjectName(QStringLiteral("pushButton_Japan_Full"));
        pushButton_Japan_Full->setMinimumSize(QSize(0, 30));
        pushButton_Japan_Full->setMaximumSize(QSize(100, 20));
        pushButton_Japan_Full->setStyleSheet(QLatin1String("color: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-radius:10px;\n"
"background-color:gray;"));

        horizontalLayout_7->addWidget(pushButton_Japan_Full);

        pushButton_Vietnam_Full = new QPushButton(layoutWidget1);
        pushButton_Vietnam_Full->setObjectName(QStringLiteral("pushButton_Vietnam_Full"));
        pushButton_Vietnam_Full->setMinimumSize(QSize(0, 30));
        pushButton_Vietnam_Full->setMaximumSize(QSize(100, 20));
        pushButton_Vietnam_Full->setStyleSheet(QLatin1String("color: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color:black;\n"
"border-radius:10px;\n"
"background-color:gray;"));

        horizontalLayout_7->addWidget(pushButton_Vietnam_Full);


        verticalLayout_5->addLayout(horizontalLayout_7);

        pushButton_StartCamera = new QPushButton(groupBox_2);
        pushButton_StartCamera->setObjectName(QStringLiteral("pushButton_StartCamera"));
        pushButton_StartCamera->setGeometry(QRect(280, 200, 20, 20));
        sizePolicy.setHeightForWidth(pushButton_StartCamera->sizePolicy().hasHeightForWidth());
        pushButton_StartCamera->setSizePolicy(sizePolicy);
        pushButton_StartCamera->setMaximumSize(QSize(20, 20));
        textEdit_Waring = new QTextEdit(groupBox_2);
        textEdit_Waring->setObjectName(QStringLiteral("textEdit_Waring"));
        textEdit_Waring->setGeometry(QRect(10, 230, 261, 191));
        textEdit_Inform = new QTextEdit(tab);
        textEdit_Inform->setObjectName(QStringLiteral("textEdit_Inform"));
        textEdit_Inform->setGeometry(QRect(280, 390, 150, 190));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEdit_Inform->sizePolicy().hasHeightForWidth());
        textEdit_Inform->setSizePolicy(sizePolicy2);
        textEdit_Inform->setMinimumSize(QSize(150, 190));
        textEdit_Inform->setMaximumSize(QSize(150, 190));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 20, 120, 261));
        pushButton_Change = new QPushButton(groupBox_3);
        pushButton_Change->setObjectName(QStringLiteral("pushButton_Change"));
        pushButton_Change->setGeometry(QRect(10, 230, 75, 23));
        textEdit_Group1 = new QTextEdit(groupBox_3);
        textEdit_Group1->setObjectName(QStringLiteral("textEdit_Group1"));
        textEdit_Group1->setGeometry(QRect(10, 190, 104, 31));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 60, 51, 16));
        textEdit_Line2_up = new QTextEdit(groupBox_3);
        textEdit_Line2_up->setObjectName(QStringLiteral("textEdit_Line2_up"));
        textEdit_Line2_up->setGeometry(QRect(10, 130, 104, 31));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 10, 47, 13));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 110, 61, 16));
        textEdit_Line1 = new QTextEdit(groupBox_3);
        textEdit_Line1->setObjectName(QStringLiteral("textEdit_Line1"));
        textEdit_Line1->setGeometry(QRect(10, 30, 104, 31));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 170, 47, 13));
        textEdit_Line2_low = new QTextEdit(groupBox_3);
        textEdit_Line2_low->setObjectName(QStringLiteral("textEdit_Line2_low"));
        textEdit_Line2_low->setGeometry(QRect(10, 80, 104, 31));
        tabWidget->addTab(tab_3, QString());

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
        groupBox_Information->setTitle(QApplication::translate("GuiWindow", "Robot Position", Q_NULLPTR));
        label_Theta1->setText(QApplication::translate("GuiWindow", "Theta1", Q_NULLPTR));
        label_Theta2->setText(QApplication::translate("GuiWindow", "Theta2", Q_NULLPTR));
        label_D3->setText(QApplication::translate("GuiWindow", "D3(mm)", Q_NULLPTR));
        label_Theta4->setText(QApplication::translate("GuiWindow", "Theta4", Q_NULLPTR));
        label->setText(QApplication::translate("GuiWindow", "<html><head/><body><p><span style=\" font-weight:600;\">THETA1</span></p></body></html>", Q_NULLPTR));
        label_var0_min->setText(QApplication::translate("GuiWindow", "-85", Q_NULLPTR));
        label_var0_max->setText(QApplication::translate("GuiWindow", "85", Q_NULLPTR));
        label_2->setText(QApplication::translate("GuiWindow", "<html><head/><body><p><span style=\" font-weight:600;\">THETA1</span></p></body></html>", Q_NULLPTR));
        label_var1_min->setText(QApplication::translate("GuiWindow", "-135", Q_NULLPTR));
        label_var1_max->setText(QApplication::translate("GuiWindow", "135", Q_NULLPTR));
        label_3->setText(QApplication::translate("GuiWindow", "<html><head/><body><p><span style=\" font-weight:600;\">D3</span></p></body></html>", Q_NULLPTR));
        label_var2_min->setText(QApplication::translate("GuiWindow", "0", Q_NULLPTR));
        label_var2_max->setText(QApplication::translate("GuiWindow", "100", Q_NULLPTR));
        label_4->setText(QApplication::translate("GuiWindow", "<html><head/><body><p><span style=\" font-weight:600;\">THETA4</span></p></body></html>", Q_NULLPTR));
        label_var3_min->setText(QApplication::translate("GuiWindow", "-170", Q_NULLPTR));
        label_var3_max->setText(QApplication::translate("GuiWindow", "170", Q_NULLPTR));
        label_X_2->setText(QApplication::translate("GuiWindow", "X(mm)", Q_NULLPTR));
        label_Y_2->setText(QApplication::translate("GuiWindow", "Y(mm)", Q_NULLPTR));
        label_Z_2->setText(QApplication::translate("GuiWindow", "Z(mm)", Q_NULLPTR));
        label_Roll_2->setText(QApplication::translate("GuiWindow", "ROLL(deg)", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("GuiWindow", "Object Position", Q_NULLPTR));
        label_X_4->setText(QApplication::translate("GuiWindow", "X(mm)", Q_NULLPTR));
        label_Y_4->setText(QApplication::translate("GuiWindow", "Y(mm)", Q_NULLPTR));
        label_Roll_5->setText(QApplication::translate("GuiWindow", "CLASS", Q_NULLPTR));
        label_Roll_4->setText(QApplication::translate("GuiWindow", "ROLL(deg)", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("GuiWindow", "Robot", Q_NULLPTR));
        label_Comport->setText(QApplication::translate("GuiWindow", "COM PORT", Q_NULLPTR));
        label_Baudrate->setText(QApplication::translate("GuiWindow", "BAUD RATE", Q_NULLPTR));
        pushButton_Connect->setText(QApplication::translate("GuiWindow", "Connect", Q_NULLPTR));
        label_Velocity->setText(QApplication::translate("GuiWindow", "VELOCITY", Q_NULLPTR));
        label_Accelerate->setText(QApplication::translate("GuiWindow", "ACCERLERATE", Q_NULLPTR));
        pushButton_Scan->setText(QApplication::translate("GuiWindow", "SCAN", Q_NULLPTR));
        pushButton_Stop->setText(QApplication::translate("GuiWindow", "STOP", Q_NULLPTR));
        pushButton_Log->setText(QApplication::translate("GuiWindow", "LOG", Q_NULLPTR));
        pushButton_Home->setText(QApplication::translate("GuiWindow", "HOME", Q_NULLPTR));
        pushButton_Start->setText(QApplication::translate("GuiWindow", "START", Q_NULLPTR));
        pushButton_SetROI->setText(QApplication::translate("GuiWindow", "ROI", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("GuiWindow", "Camera", Q_NULLPTR));
        label_Camera->setText(QString());
        label_Japan->setText(QApplication::translate("GuiWindow", "Japan", Q_NULLPTR));
        label_Vietnam->setText(QApplication::translate("GuiWindow", "Vietnam", Q_NULLPTR));
        pushButton_Japan_Full->setText(QApplication::translate("GuiWindow", "JP FULL", Q_NULLPTR));
        pushButton_Vietnam_Full->setText(QApplication::translate("GuiWindow", "VN FULL", Q_NULLPTR));
        pushButton_StartCamera->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("GuiWindow", "VISION MODE", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("GuiWindow", "Deal", Q_NULLPTR));
        pushButton_Change->setText(QApplication::translate("GuiWindow", "Change", Q_NULLPTR));
        textEdit_Group1->setHtml(QApplication::translate("GuiWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.5</p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("GuiWindow", "line2 lower", Q_NULLPTR));
        textEdit_Line2_up->setHtml(QApplication::translate("GuiWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">40</p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("GuiWindow", "line 1", Q_NULLPTR));
        label_11->setText(QApplication::translate("GuiWindow", "line 2 upper", Q_NULLPTR));
        textEdit_Line1->setHtml(QApplication::translate("GuiWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.5</p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("GuiWindow", "group 1", Q_NULLPTR));
        textEdit_Line2_low->setHtml(QApplication::translate("GuiWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">33</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("GuiWindow", "SETTING", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiWindow: public Ui_GuiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIWINDOW_H
