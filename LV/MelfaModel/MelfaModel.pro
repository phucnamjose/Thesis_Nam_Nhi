QT += core gui opengl serialport

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MelfaModel
TEMPLATE = app

SOURCES += main.cpp \
    modelloader.cpp \
    openglwindow.cpp \
    link1.cpp \
    link2.cpp \
    link3.cpp \
    link4.cpp \
    link5.cpp \
    link6.cpp \
    guiwindow.cpp\
	box.cpp
HEADERS += \
    modelloader.h \
    openglwindow.h \
    link1.h \
    link2.h \
    link3.h \
    link4.h \
    link5.h \
    link6.h \
    guiwindow.h\
	box.h

RESOURCES += \
    shaders.qrc

LIBS+= -lopengl32

FORMS += \
    guiwindow.ui

# Add thu vien assimp
LIBS += -L$$PWD/../assimp-3.3.1/lib/ -lassimp-vc140-mt


INCLUDEPATH += $$PWD/../assimp-3.3.1/include
DEPENDPATH += $$PWD/../assimp-3.3.1/include
