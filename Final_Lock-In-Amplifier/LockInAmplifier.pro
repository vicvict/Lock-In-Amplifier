#-------------------------------------------------
#
# Project created by QtCreator 2019-12-19T16:06:13
#
#-------------------------------------------------

QT += core gui testlib serialport
CONFIG += warn_on c++1z

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LockInAmplifaer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++1z

SOURCES += \
        LIA_Models/LockInAmplifier/SRS/SRS.cpp \
        LIA_Models/LockInAmplifier/SRS/SerialPortCommunication/Convertion/QtSTLConvertion.cpp \
        LIA_Models/LockInAmplifier/SRS/SerialPortCommunication/SerialPortCommunication.cpp \
        LIA_Models/LockInAmplifier/SRS/SerialPortCommunication/SerialPortCommunicationQt/SerialPortCommunicationQt.cpp \
        LIA_Models/LockInAmplifier/SRS/SerialPortCommunication/Timer/Timer.cpp \
        LIA_Models/LockInAmplifier/lockinamplifier.cpp \
        LIA_Models/SR830/sr830.cpp \
        LIA_Models/SR844/sr844.cpp \
        LIA_Models/SR865/sr865.cpp \
        finallockinamplifier.cpp \
        main.cpp \
        mainwindow.cpp \

HEADERS += \
        LIA_Models/LockInAmplifier/SRS/SRS.h \
        LIA_Models/LockInAmplifier/SRS/SerialPortCommunication/Convertion/QtSTLConvertion.h \
        LIA_Models/LockInAmplifier/SRS/SerialPortCommunication/SerialPortCommunication.h \
        LIA_Models/LockInAmplifier/SRS/SerialPortCommunication/SerialPortCommunicationQt/SerialPortCommunicationQt.h \
        LIA_Models/LockInAmplifier/SRS/SerialPortCommunication/Timer/Timer.h \
        LIA_Models/LockInAmplifier/lockinamplifier.h \
        LIA_Models/SR830/sr830.h \
        LIA_Models/SR844/sr844.h \
        LIA_Models/SR865/sr865.h \
        finallockinamplifier.h \
        mainwindow.h

FORMS += \
        mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
