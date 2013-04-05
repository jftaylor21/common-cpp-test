INCLUDEPATH *= $$PWD/../../3rdparty/common-cpp/include

LIBS *= -L$$PWD/../../3rdparty/common-cpp/lib \
        -lutilities

SOURCES *= $$PWD/main.cpp

CONFIG -= qt
CONFIG *= console

target.path = c:/common-cpp-test
INSTALLS *= target

libs.path = $$target.path
libs.files = $$PWD/../../3rdparty/common-cpp/lib/*.dll
INSTALLS *= libs
