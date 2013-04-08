HEADERS *= $$PWD/MainMenu.h \
           $$PWD/ChatServer.h \
           $$PWD/ChatClient.h \
           $$PWD/ChatCommon.h

SOURCES *= $$PWD/main.cpp \
           $$PWD/MainMenu.cpp \
           $$PWD/ChatServer.cpp \
           $$PWD/ChatClient.cpp

CONFIG -= qt
CONFIG *= console

target.path = c:/common-cpp-test
INSTALLS *= target

include($$PWD/../../3rdparty/common-cpp/common-cpp.pri)
