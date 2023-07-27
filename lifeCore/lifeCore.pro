QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Cell.cpp \
    GameMap.cpp \
    Ground.cpp \
    LifeCore.cpp \
    MapBuilder.cpp \
    PlayerInterface.cpp

HEADERS += \
    Cell.h \
    GameMap.h \
    Ground.h \
    LifeCore.h \
    MapBuilder.h \
    PlayerInterface.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
