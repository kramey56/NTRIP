# #####################################################################
# Automatically generated by qmake (2.01a) Fri Dec 31 10:33:45 2010
# #####################################################################
TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += mainwindow.h
FORMS += mainwindow.ui
SOURCES += main.cpp \
    mainwindow.cpp

PRE_TARGETDEPS = ../build/libNTRIP.a

LIBS += -L/home/kramey/work/Platforms/Experimental/kramey/libNTRIP/trunk/build -lNTRIP
LIBS += -L/usr/local/lib -lCommon -lqextserialport
