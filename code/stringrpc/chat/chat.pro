HEADERS *= $$PWD/MainMenu.h \
           $$PWD/ChatServer.h \
           $$PWD/ChatClient.h \
           $$PWD/ChatCommon.h \
           $$PWD/ChatMenu.h

SOURCES *= $$PWD/main.cpp \
           $$PWD/MainMenu.cpp \
           $$PWD/ChatServer.cpp \
           $$PWD/ChatClient.cpp \
           $$PWD/ChatMenu.cpp

CONFIG -= qt
CONFIG *= console

target.path = c:/common-cpp-test
INSTALLS *= target

include($$PWD/../../3rdparty/common-cpp/common-cpp.pri)
