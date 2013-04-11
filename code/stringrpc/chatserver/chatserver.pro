INCLUDEPATH *= $$PWD/../chat

HEADERS *= $$PWD/../chat/ChatServer.h

SOURCES *= $$PWD/main.cpp \
           $$PWD/../chat/ChatServer.cpp

CONFIG -= qt
CONFIG *= console

target.path = c:/common-cpp-test
INSTALLS *= target

include($$PWD/../../3rdparty/common-cpp/common-cpp.pri)
